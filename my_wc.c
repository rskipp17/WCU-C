//Ryan Skipp
//CSC331 S20
//Assignment 2

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

//Declare variables
int ccount;
int wcount;
int lcount;

//Increase character and line counts if needed
#define COUNT(c)       \
      ccount++;        \
      if ((c) == '\n') \
        lcount++;

// Return true if word
static int isword (unsigned char c)
{
  return isalpha(c);
}

//Get next word from file input
int getword(FILE *fp)
{
   int c;
   int word = 0;

   if (feof(fp))
      return 0;

   while ((c = getc(fp)) != EOF)
   {
      if (isword(c))
      {
         wcount++;
         break;
      }
      COUNT(c);
   }

   for (; c != EOF; c = getc(fp))
   {
      COUNT(c);
      if (!isword(c))
         break;
   }

   return c != EOF;
}

//Parse file
void counter(char *file)
{
   FILE *fp = fopen(file, "r");

   if (!fp)
   {
      printf("my_wc: cannot open file\n");
      exit(1);
   }

   ccount = wcount = lcount = 0;
   while (getword(fp))
      ;
   fclose(fp);

   printf ("%d %d %d %s\n", lcount, wcount, ccount, file);
}

int main(int argc, char **argv)
{
   if (argc < 2)
   {
      printf("my_wc: [option ...] [file ...]\n");
      exit(1);
   }

   for (int i = 1; i < argc; i++)
      counter(argv[i]);

   return 0;
}