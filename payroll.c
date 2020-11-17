//Ryan Skipp
//CSC331 Spring 2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{    
    //Declare variables
    char *firstName, *lastName;
    int hoursWorked;
    double hourlyRate, totalPayment;
    
    //Assign variables
    firstName = argv[1];
    lastName = argv[2];
    hoursWorked = atoi(argv[3]);
    hourlyRate = atof(argv[4]);
    
    //Calculate payment, display output
    totalPayment = hoursWorked * hourlyRate;
    printf("%s, %s: %.2f\n", lastName, firstName, totalPayment);

    //End program
    return(0);
}