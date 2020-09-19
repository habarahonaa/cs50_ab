//Credit is a program that implements Luhn's algorithm for checking if a Credit's card number is valid (WIP)

#include <cs50.h>
#include <stdio.h>

bool check_validity(long number);
int find_length(long n);
bool checksum(long credit_card_number);
void print_cc_issuer(long credit_card_number);


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

	if (check_validity(number) == true)
		print_cc_issuer(number);
	else
	    printf("INVALID\n");
}

//Function to check if input number is valid

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

//Luhn's Algorithm

bool checksum(long credit_card_number)
{
    int sum = 0;
    for(int i = 0; credit_card_number != 0; i++, credit_card_number /= 10)
    {
        if (i % 2 == 0)
            sum += credit_card_number % 10;
        else
        {
            int digit = 2 * (credit_card_number % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 10;
}

//Function for checking Credit Card Network and printing it

void print_cc_issuer(long credit_card_number)
{
    if ( (credit_card_number >= 34e13 && credit_card_number < 35e13) || (credit_card_number >= 37e13 && credit_card_number < 38e13))
    printf("AMEX\n");

    else if (credit_card_number >= 51e14 && credit_card_number < 56e14)
    printf("MASTERCARD\n");

    else if ( (credit_card_number >= 4e12 && credit_card_number < 5e12) || (credit_card_number >= 4e14 && credit_card_number < 5e14))
    printf("VISA\n");

    else
    printf ("INVALID\n");
}
