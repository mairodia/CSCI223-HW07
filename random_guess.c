// ================================================================================================
// File: random_guess.c
// ================================================================================================
// Programmer: Jennifer King
// Date: 2/26/2018
// Project: Random Guess
// Professor: Scott Edwards
// Class: CSCI223F | TR 4:30PM
// Description:
//              This program creates an array of numbers from 0 to a max amount specified by the user.
//              The user inputs how many times they think a certain number will occur, and the program
//              checks to see if they are correct.
// ================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LEN = 1000000;

//prototypes
void FillRandArray(int max, int array[]);
int FindNumMatches(int target, int array[]);

int main(void)
{
    auto int max;
    auto int target;
    auto int numMatch;
    auto int array[LEN];

    printf("What is the maximum random value? ");
    scanf("%d", &max);

    if(max < 0)
    {
        printf("Sorry, negative numbers don't work here...\n");
        exit(1);
    }

    printf("What is the target value? ");
    scanf("%d", &target);

    if(target > max)
    {
        printf("Sorry, the target value can't be greater than the maximum value...\n");
        exit(1);
    }

    printf("How many matches do you think there will be? ");
    scanf("%d", &numMatch);

    FillRandArray(max, array);

    if(numMatch == FindNumMatches(target, array))
    {
        printf("Unbelievable!! You were exactly right!\n");
    }
    else
    {
        printf("There were %d matches,", FindNumMatches(target, array));
        printf(" meaning you were off by %d...\n", (LEN - FindNumMatches(target, array)));
    }
    return 0;
} // end of main

// == FillRandArray ===============================================================================
// This function fills the array with random numbers.
//
// IN:
//              max -- int representing the maximum value of the randomized number
//              array -- the randomized array
//
// OUT:
//              nothing; void function
// ================================================================================================
void FillRandArray(int max, int array[])
{
    srand(time(NULL));

    for(int index = 0; index < LEN; index ++)
    {
        if(max == 0)
        {
            array[index] = 0;
        }
        else
        {
            array[index] = rand() % (max+1);
        }
    }
} // end of FillRandArray

// == FindNumMatches ==============================================================================
// This function checks how many times the target occurs in the array.
//
// IN:
//              target -- int representing the value the user is looking for
//              array -- the randomized array
//
// OUT:
//              match -- the number of times the target value was equal to a member of the array.
// ================================================================================================
int FindNumMatches(int target, int array[])
{
    auto int match = 0;

    for(int index = 0; index < LEN; index ++)
    {
        if(array[index] == target)
        {
            match ++;
        }

        else
        {
        }
    }
	return match;
} // end of FindNumMatches
