/****************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2012 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Yallara Username : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "assignment1.h"
#include "utility.h"

/* Function readRestOfLine() is used for buffer clearing.
 * Please refer to "test_fgets.c" on Blackboard:
 * "Course Documents"->"Function Examples"->"Input Validation Examples" */
void readRestOfLine()
{
   int c;

   /* Read until the end of the line or end-of-file. */
   while ((c = fgetc(stdin)) != '\n' && c != EOF)
      ;

   /* Clear the error and end-of-file flags. */
   clearerr(stdin);
}

/*int validateNumericInput(int number, char* string, unsigned length, char prompt)
{
   int finished = FALSE;

   if ( isdigit(number) == FALSE)
   {
     do
     {
      if ( (number >= 9) || (number < 0))
      {
         printf("Invalid option entered. \n");
         getString(string, length, prompt);
      }
      else
      {
         finished = TRUE;
      }
     } while (finished == FALSE);
   }
   else
   {
      printf("valid number");
      return TRUE;
   }
}*/
/*************************************************************************
* Reused Code: getString function
* Author: Steven Burrows
* sdb@cs.rmit.edu.au
* created June 2006
*************************************************************************/
/* START REUSED CODE */
int getString(char* string, unsigned length, char* prompt)
{
   int finished = FALSE;
   char tempString[ 200  + EXTRA_SPACES];

   /*Continue to interact with the user until the input is validated */
   do
   {
      /*customized prompt */
      printf("%s", prompt);

      /*Accept input */
      fgets(tempString, length + 2, stdin);

      /*A String without a '/n' is too long */
      if (tempString[strlen(tempString) -1 ] != '\n')
      {
         printf("Input was too long.\n");
         readRestOfLine();
      }
      else
      {
         finished = TRUE;
      }
   } while (finished == FALSE);

   /* Overwrite the newline character with '\0' */
   tempString[strlen(tempString) - 1] = '\0';
   /*copy tempstring to string */
   strcpy(string, tempString);
   return TRUE;
}

/* END RESUSED CODE */

