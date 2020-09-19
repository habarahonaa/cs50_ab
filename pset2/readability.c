//Readability is a program that computes the approximate grade level required to read and understand a piece of text the user inputs.

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //Prompt the user for text (using get_string function declared in cs50.h).

    string text = get_string("Text: ");

    //Calculate the number of letters, words & sentences (using isalpha && isblank functions declared in ctype.h).

    float letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else

            if (isblank(text[i]))
            {
                words++;
            }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //Average the number of letters and sentences per 100 words of text.

    float l = letters / words * 100;
    float s = sentences / words * 100;

    //Coleman-Liau index, where l is the average number of letters per 100 words in the text, and s is the average number of sentences per 100 words in the text

    float index = (0.0588 * l) - (0.296 * s) - 15.8;

    int grade = round(index);

    //Print the computed reading grade

    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
}
