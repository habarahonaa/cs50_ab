//Caesar is a program that encrypts plaintext messages by shifting the characters by some numbers of places (key) the user inputs at the command line

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Checks that the user inputs a "key" value and that is only a number
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            //If the user inputs something thats not a number, the program will return a warning.
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //Using atoi function, convert the string the user prompted at the command-line to an integer to use it as the key for the cipher

        int key = atoi(argv[1]);

        //Get the plaintext the user wants to cipher using the get_string function

        string plaintext = get_string("plaintext: ");

        //Create alphabetical index, each char on the created string has an index that can be accesed by the program (A will be 0 and Z on the other end is 25, the same for lowercase var.)

        string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        string lowercase = "abcdefghijklmnopqrstuvwxyz";

        //Count the length of the plaintext and create an array to store it for later printing

        int plaintext_length = strlen(plaintext);

        char ciphertext[plaintext_length];

        for (int x = 0; x < plaintext_length; x++)
        {
            int ascii_to_int = 0;

            if (isupper(plaintext[x]))
            {
                ascii_to_int = ((int) plaintext[x] - 65 + key) % 26;
                ciphertext[x] = uppercase[ascii_to_int];
            }

            else if (islower(plaintext[x]))
            {
                ascii_to_int = ((int) plaintext[x] - 97 + key) % 26;
                ciphertext[x] = lowercase[ascii_to_int];
            }

            else
            {
                ciphertext[x] = plaintext[x];
            }
        }

        //Output the cipher text

        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }

    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
