//Prints a recreation of Mario's World 1-1 pyramid using hashes

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompts the user for height of pyramid that must be a positive number between 1 and 8
   int n;
   do
   {
       n = get_int("Height:");
   }
   while (n < 1 || n > 8);
   
  //Prints the pyramid of hashes; i is the number of rows
  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          //If the sum of Rows (i) + Cells (j) is less than Height - 1 prints a space, else it prints a hash
          if (i + j < n - 1)
            printf (" ");
          
          else
            printf("#");
      }
      printf("\n");
  }
}
