//Ryan Skipp
//CSC331 Spring 2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{    
    //Declare variables
    char *filename;
    int *array, size;
    FILE *fp;

    //Assign variables
    filename = argv[1];
    size = 0;
    
    fp = fopen(filename, "r");

    //count number of lines in file
    int numLines; 
    for (char c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n')
            numLines += 1;

    //allocate enough array space for number of lines
    array = malloc(numLines * 80 * __SIZEOF_INT__); 
    
    //store each integer in array
    int tempNumber;
    rewind(fp);
    while (fscanf(fp, "%d", &tempNumber) != EOF)
    {
        array[size] = tempNumber;
        size++;
    }
    
    fclose(fp);

    //Sort array in ascending order
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i]   = array[j];
                array[j]   = temp;
            }
        }
    }

    //Output sorted array contents
    for (int i=0; i < size-1; i++)
        printf("%d ", array[i]);
    printf("%d", array[size-1]);
    
    //End program
    return(0);
}