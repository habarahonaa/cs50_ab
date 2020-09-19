//Prints a recreation of Mario's World 1-1 adjacent pyramids using hashes

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompts the user for height of pyramid that must be a positive number between 1 and 8 
    
   int n;
   
   //Using a do-while loop ask the user for the desired height of pyramid (will repeat if the while condition is not fulfilled)
   do
   {
       n = get_int("Height:");
   }
   while (n < 1 || n > 8);
   
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n + 2; j++)
        {
            if (j == n || j == n + 1 || i+j < n - 1 || j > i + n + 2)
                printf (" ");
                
            else
            printf ("#");
        }   
          printf ("\n");  
    }
}
