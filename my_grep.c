//Ryan Skipp
//CSC331 S20
//Assignment 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Parse file
void counter(char *text, char *file)
{
    FILE *fp = fopen(file, "r");
    char line[2048];

    if (!fp)
    {
        printf("my_grep: cannot open file\n");
        exit(1);
    }

    //search each line for matching text, and print it if it matches
    while (fgets(line, sizeof(line), fp))
        if (strstr(line, text) != NULL){
            printf("Found: %s", line);
        }
            

    fclose(fp);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("my_grep: searchterm [file ...]");
        exit(1);
    }

    for (int i = 2; i < argc; i++)
        counter(argv[1], argv[i]);

    return 0;
}