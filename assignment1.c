
/*COSC1283/1284 - Programming Techniques
 * Semester 1 2012 Assignment #1
 * Full Name        : Lauren Grimes
 * Student Number   : s3228871
 * Yallara Username : s3228871
 * Course Code      : COSC1284
 * Program Code     : Programming Techniques
 * 
 ******************************************************************************/ 
#include "assignment1.h"

/*-----MAIN------*/
int main (void)
{ 
   int optionStats[NUM_OPTION_STATS];
   int optionChoice = 0;
   char sel[ 1 + EXTRA_SPACES ];
   char* prompt = "Please enter a selection: ";
   char *p;

   while (optionChoice != EXIT_OPTION )
   {
      /*prints the main menu */
      printMenu();
      
      /*gets user input as a string */
      getString(sel, 1 + EXTRA_SPACES, prompt);
      optionChoice = strtol(sel, &p, 10);

      switch (optionChoice)
      {     
       case PERFECT_SQUARES_OPTION : printf("option 1 selected \n");
                 perfectSquares(optionStats); 
                  break;
      case ASCII_TO_BINARY_OPTION : printf("option 2 selected \n");
                  asciiToBinary(optionStats);
                  break;
      case MATCHING_BRACKETS_OPTION : printf("option 3 selected \n");
                  matchingBrackets(optionStats);
                  break;
      case TIC_TAC_OPTION : printf("option 4 selected \n");
                  ticTacToeGame(optionStats);
                  break;
      case FORMAT_OPTION : printf("Option 5 selected \n");
                  formattingText(optionStats);
                  break;
      case SUMMARY_OPTION : printf("Option 6 selected \n");
                  sessionSummary(optionStats);
                  break;
      }
   }
   return EXIT_SUCCESS;
}

void printMenu( )
{

   printf("Main Menu: \n");
   printf("1) Perfect Squares \n");
   printf("2) Ascii To Binary Calculator \n");
   printf("3) Matching Brackets \n");
   printf("4) Tic Tac Toe Game \n");
   printf("5) Formatting Text \n");
   printf("6) Session Summary \n");
   printf("7) Exit \n \n");
   
}


