//Ryan Skipp
//CSC331 S20
//Assignment 2

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    FILE *fp;
    char c;

    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");
        
        if (fp == NULL)
        {
            printf("my_cat: cannot open file");
            exit(1);
        }

        printf("\n------------File: %d----------------\n", i);
        // Reading file and showing it as output
        for (char c = getc(fp); c != EOF; c = getc(fp))
            printf("%c", c);
        printf("\n------------End of File %d----------------\n", i);
        fclose(fp);
    }

    return 0;
}