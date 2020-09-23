//Credit is a program that implements Luhn's algorithm for checking if a Credit's card number is valid (WIP)

//Headers
#include <cs50.h>
#include <stdio.h>

//Prototypes
bool check_validity(long number);
int find_length(long n);
bool checksum(long card_number);
void print_issuer(long number);


int main(void)
{
	//Prompt user for credit card number
	long number;
	do
	{
		number = get_long("Number: ");
	}
	while (number < 0);

	//Prints the Credit Card Network or INVALID if number is not valid
	if (checksum(number) == true)
		print_issuer(number);
	else
	    printf("INVALID\n");
}

//Check if input number is valid 
bool check_validity(long number)
{
    int length = find_length(number);
    return (length == 13 || length == 14 || length == 15) && checksum(number);
}

//Find length of credit card
int find_length(long n)
{
    int length;
    for (length = 0; n != 0; n /= 10, length++);
	return length;
}

//Luhn's Algorithm Implementation
bool checksum(long number)
{
    int sum = 0;
    for(int i = 0; number != 0; i++, number /= 10)
    {
        if (i % 2 == 0)
            sum += number % 10;
        else 
        {
            int digit = 2 * (number % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 10;
}

//Function for checking Credit Card Network and printing it
void print_issuer(long number)
{
    if ( (number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13))
    printf("AMEX\n");

    else if (number >= 51e14 && number < 56e14)
    printf("MASTERCARD\n");

    else if ( (number >= 4e12 && number < 5e12) || (number >= 4e14 && number < 5e14))
    printf("VISA\n");

    else
    printf ("INVALID\n");
}
