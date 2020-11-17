//Ryan Skipp
//CSC331 Spring 2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{    
    //Declare variables
    char *filename;
    int array[10], sum, size;
    FILE *fp;

    //Assign variables
    filename = argv[1];
    sum = 0;
    size = 0;
    
    //Open file, read into array char array, close file
    fp = fopen(filename, "r");

    int tempNumber;
    while (fscanf(fp, "%d", &tempNumber) != EOF)
    {
        array[size] = tempNumber;
        size++;
    }
    
    fclose(fp);

    //Calculate sum of integers in array and output sum
    for (int i=0; i < size; i++)
        sum = sum + array[i];
    printf("%d\n", sum);
    
    //End program
    return(0);
}