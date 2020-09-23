//Distribution code as provided by Harvard's CS50 staff
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //Iterates through the array of candidates, while is smaller than the full count of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //Compares the names on the ballots to the candidate's names using strcmp (RETURNS TRUE IF FOUND, OTHERWISE FALSE)
        if (strcmp(name, candidates[i].name) == 0)
        {
            //Updates the preferences for each voter (if the above condition is fulfilled)
            preferences[voter][rank] = i;
            return true;
        }
    }
    //Else, return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //Iterate through voter count
    for (int i = 0; i < voter_count; i++)
    {
        //Initialize variable to 0 (0 is the highest preference rank, followed by 1 and 2 (2 and 3 respectively))
        int j = 0;
        //Iterates through each vote to see if the voter's highest preference is eliminated, moves to the next highest preference
        while (candidates[preferences[i][j]].eliminated == true)
        {
            j++;
        }
        //Updates vote count
        candidates[preferences[i][j]].votes++;
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //Calculates majority and stores the value
    int majority = voter_count / 2 + 0.5;
    //Iterates through the candidates to check number of votes
    for (int l = 0; l < candidate_count; l++)
    {
        //If one candidate has majority, declare the winner, and return true
        if (candidates[l].votes > majority)
        {
            printf("%s\n", candidates[l].name);
            return true;
        }
    }
    //Else
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //Defines a variable to store the lowest vote count
    int minvotes = candidates[0].votes;
    //Iterates through the candidates list
    for (int m = 0; m < candidate_count; m++)
    {
        //Checks if the candidate is not eliminated and the vote count is less than the stored vote count & updates it
        if (candidates[m].eliminated == false && minvotes < candidates[m].votes)
        {
            minvotes = candidates[m].votes;
        }
    }
    //Returns the integer lowest_vote
    return minvotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int minvotes)
{
    for (int n = 0; n < candidate_count; n++)
    {
        //Check if candidate is not eliminated and has the minimum votes (if a candidate has the minimum votes means there is no tie)
        if (candidates[n].eliminated == false && candidates[n].votes != minvotes)
        {
            return false;
        }
    }
    //Else
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int minvotes)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated != true && candidates[i].votes == minvotes)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
