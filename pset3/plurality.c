//Distribution code as provided by Harvard's CS50 staff
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        //Compares the names on the ballots to the candidate's names using strcmp (RETURNS TRUE IF FOUND, OTHERWISE FALSE)
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Declares integer that will hold the max_votes
    int max_votes = 0;

    //Iterates over candidates
    for (int x = 0; x < candidate_count; x++)
    {
        //If the number of votes of a candidate is more than max_votes, updates it every iteration
        if (candidates[x].votes > max_votes)
        {
            max_votes = candidates[x].votes;
        }
    }
    
    //Iterates once again over candidates, this time to check if it matches the max_votes value
    for (int y = 0; y < candidate_count; y++)
    {
        //If it matches max_votes, prints the name of the candidate
        if (candidates[y].votes == max_votes)
        {
            printf("%s\n", candidates[y].name);
        }
    }
   
    return;
}
