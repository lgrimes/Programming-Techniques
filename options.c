/******************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2012 Assignment #1
* Full Name        : Lauren Grimes
* Student Number   : s3228871
* Yallara Username : s3228871
* Course Code      : COSC1284
* Program Code     : BP162
******************************************************************************/

#include "assignment1.h"
#include <string.h>
#include <ctype.h>
/****************************************************************************
* This source file contains important functions to be developed and
* used by various menu options, as indicated. Note that every
* function has as its first parameter the optionsStats array, which
* will be appropriately updated for later reporting of menu option 7.
* You may ignore this parameter and its relevance to each function
* until you develop the sessionSummary() function.
****************************************************************************/


/****************************************************************************
* This function prompts the user for a positive integer. It reports
* whether or not this number is a perfect square. Additionally, it
* prints the perfect squares immediately before and after this
* number. See requirement #2 in the assignment specification
****************************************************************************/
void perfectSquares(int *optionStats)
{
   int userNum;
   char *p;
   char buffer[7 + EXTRA_SPACES];
   int divNum;
   int closestSquare;
   char* prompt = "Please enter a positive integer ( 1 - 1000000): ";
   
   printf("Perfect Squares \n ----------------- \n\n");
   getString(buffer, MAX_INT_LENGTH, prompt);
   if ( buffer[0] == '\0' )
   {
      printf("Exiting to Main Menu... \n \n");
      return;
   }
   userNum = strtol(buffer, &p, 10);
      if ((buffer[0] != '\n') && (*p == '\n' || *p == '\0'))
      {
        /* VALIDATION: Range validation*/
         if ( (userNum < 1000000) && (userNum > 0) )
         {   
         for (divNum=1; divNum <= userNum; divNum++)
         {
            if (divNum == (userNum / divNum))
            {  
               if ((divNum*divNum) == userNum)
               {
               printf("'%d' is a perfect square: %d * %d \n \n", userNum, divNum, divNum);
               return;
               }
            }  
            else if ((userNum-1) == divNum)
            {
               printf("'%d' is not a perfect Square.\n", userNum);
               /*retreieve closest square roots */
               /* issues occuring when using 27 as a square root. FIX!!!!!!! */
               divNum = 1;
               closestSquare = divNum * divNum;
               while (closestSquare <( (userNum - divNum)-1))
               {
               if ((divNum * divNum) > userNum)
                  break;
               divNum++;
               closestSquare = divNum * divNum;
               }
            printf("'%d' is the perfect square before. %d * %d \n", closestSquare, divNum, divNum);
            divNum++;
            printf("'%d' is the perfect square root after. %d * %d \n \n",divNum * divNum, divNum, divNum);
            (optionStats[0])++;
            return;
            }
        } 
        }
        else
        {
         printf("Invalid range \n");
        }
      }
      else
      {
        printf("Invalid Number \n");
        return;
      /*need to change to reprompt for input*/
      }
}

/****************************************************************************
ASCII TO BINARY TRANSLATOR
****************************************************************************/
void asciiToBinary(int *optionStats)
{
   /*TRANSLATE THE ASCII CHARACTERS TO DECIMAL NOTATION THEN TO BINARY AND DISPLAY EACH ONE INDIVIDUALLY SEPERATED BY A SPACE.
      READ IN EACH CHARACTER FORM THE STRING AND THEN DO THE TRANSLATION THEN SAVE TO NEW BUFFER AND PRINT OUT. 
   */
   char buffer[5 + EXTRA_SPACES];
   char *prompt = "Please Enter upto 5 ASCII characters: ";
   int i;
   
   printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n ASCII TO BINARY CONVERSION\n\n");
   getString( buffer, 5 + EXTRA_SPACES, prompt);
   if (buffer[0] == '\0')
   {
      printf("Exiting to Main Menu....");
      return;
   }

   for (i = 0; buffer[i] != '\0';  i++)
   {
      int ascii = buffer[i];
      char binaryNotation [8];
      int j;

      do
      {
         /* j = number of bits for binary number*/
         /* % 2 to find if bit is 1 or 0
         Divide ascii num by 2*/
         for (j = 0; j < 8; j++)
         {
         binaryNotation[j] = ascii % 2;
         ascii = ascii/2;
         }
      } while ((ascii %2) != 0);
      /*print back from array */
      for (j = 7; j>=0; j--)
      {
      printf("%d", binaryNotation[j]);
      }
      printf(" ");
   }  
 printf("\n\n");
 (optionStats[1])++;
 return;
}

/****************************************************************************
* See requirement #4 "Matching Brackets"
****************************************************************************/
void matchingBrackets(int *optionStats)
{
   char *prompt = "Please enter a string (1 - 20 Characters): ";
   char buffer [20 + EXTRA_SPACES];
   int i=0;
   char brackets[20 + EXTRA_SPACES];
   int j = 0;
   int MATCHING = TRUE;
   
   printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\nMATCHING BRACKETS\n\n");
   getString(buffer, 20 + EXTRA_SPACES, prompt);
   if (buffer[0] == '\0')
   {
      printf("Exiting to Main Menu....\n");
      return;
   }
   do
   {
      if (((buffer[i] == '(') || (buffer[i] == '[') || (buffer[i] == '{')) || ((buffer[i] == ')') || (buffer[i] == ']') || (buffer[i] == '}')))
      {
         brackets[j] = buffer[i];
         j++;
      }
      i++;
  } while (buffer[i] != '\0');
  
  /*reinitalise counters*/
  i=0;
  j=j-1;
  
  /*For Nested brackets only */
  for(i=0; (MATCHING== TRUE) && (i< j); i++, j--)
  {
      if ((brackets[i] == '(') && (brackets[j] != ')'))
      {
         printf("Brackets do not match\n");
         MATCHING = FALSE;
         (optionStats[2])++;
         return;
      }
      else if ((brackets[i] == '{') && (brackets[j] != '}'))
      {
         printf("Brackets do not match\n");
         MATCHING = FALSE;
         (optionStats[2])++;
         return;
      }
      else if ((brackets[i] == '[') && (brackets[j] != ']'))
      {
         printf("Brackets do not match\n");
         MATCHING = FALSE;
         (optionStats[2])++;
         return;
      }
      else
      {
         i++;
         j--;
      }
  }
   if (MATCHING == TRUE)
   {
      printf("Brackets Match \n");
      (optionStats[2])++;
   }
}

/****************************************************************************
* See requirement #5 "Tic Tac Toe Game"
****************************************************************************/
void drawBoard(char boardTurns[][NUM_COLS])
{
   printf("+---+---+---+\n");
   printf("| %c | %c | %c |\n", boardTurns[0][0], boardTurns[0][1], boardTurns[0][2]);
   printf("+---+---+---+\n");
   printf("| %c | %c | %c |\n", boardTurns[1][0], boardTurns[1][1], boardTurns[1][2]);
   printf("+---+---+---+\n");
   printf("| %c | %c | %c |\n", boardTurns[2][0], boardTurns[2][1], boardTurns[2][2]);
   printf("+---+---+---+\n");
}

/* char validateSelection 
******************************
* Will check if the selection inputted by the user is a numeri number or if the turn has already been taken
******************************/


char checkWin(char matrixGrid[][NUM_COLS])
{
   int i=0;
   /*check the rows*/
   for ( i=0; i< NUM_ROWS; i++)
   {
      if ( (matrixGrid[i][0]== matrixGrid[i][1]) && (matrixGrid[i][1]==matrixGrid[i][2]) && (matrixGrid[i][2]==matrixGrid[i][0]))
      {
         return matrixGrid[i][0];
      }
   }
   /*Check the columns*/
   for ( i=0; i< NUM_COLS; i++)
   {
      if ( (matrixGrid[0][i]==matrixGrid[1][i]) && (matrixGrid[1][i]==matrixGrid[2][i]) && (matrixGrid[2][i]==matrixGrid[0][i]))
      {
         return matrixGrid[0][i];
      }
   }
   /*check diagonals */
   if ((matrixGrid[0][0]==matrixGrid[1][1]) && (matrixGrid[1][1]==matrixGrid[2][2]) && (matrixGrid[2][2]==matrixGrid[0][0]))
   {
      return matrixGrid[0][0];
   }

   if ((matrixGrid[0][2]==matrixGrid[1][1]) && (matrixGrid[1][1]==matrixGrid[2][0]) && (matrixGrid[2][0]==matrixGrid[0][2]))
   {
      return matrixGrid[0][2];
   }

   return NULL;
}

void ticTacToeGame( int * optionStats )
{
   char matrix[NUM_ROWS][NUM_COLS]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
   char buffer[1 + EXTRA_SPACES];
   int playerNum = 1;
   int turnCount=0;
   int selection=0;
   /*drawGrid(*boardTurns)*/
   for (turnCount=0; turnCount <= MAX_TURNS; turnCount++)
   {
      if ( playerNum == 1 )
      {
         int x =0;
         int y =0;
         char check=NULL;
         char* prompt = "Player #1 select a square: ";
         char *p;
/*implement for player two aswell */
         drawBoard(matrix);
         getString(buffer, 1 + EXTRA_SPACES, prompt);
         selection= strtol(buffer, &p, 10);
         /*validateNumericInput(selection, buffer, 1 + EXTRA_SPACES, prompt);*/
         /*check if input is non-numeric*/
         if ((selection < 0) || (selection > 9))
         {
            printf("invalid selection. please try again");
         }
         
         if (buffer[0] == '\0')
         {
            printf("Exiting to Main Menu.... \n \n");
            return;
         }
         if ((buffer[0] != '\n') && (*p == '\n' || *p == '\0'))
         {
            if (selection <= 9 && selection > 0 )
            {
               for (x=0; x < NUM_ROWS; x++)
               {
                  for (y=0; y < NUM_COLS; y++)
                  {
                  /*better way of finding char value of user input - although vlidation already performed so input should be ok to straight convert*/
                  if ( matrix[x][y] == (char)buffer[0] )
                  {
                     matrix[x][y]='X';
                  }
                  }
               }
            }
            else
               /*need to loop and reprompt for inpt */
               printf("Invalid option.");
         }
         /*assign selection to board[][]*/
         check=checkWin(matrix);
         if (check != NULL)
         {
            printf("\n Player %c WON!\n", check);
            drawBoard(matrix);
            printf("Returning to menu");
            (optionStats[3])++;
            return;
         }
         playerNum=2;
      }
      if ( playerNum == 2 )
      {
         int x=0;
         int y=0;
         char check=NULL;
         char *prompt = "Player #2 select a square: "; 
         char *p;

         drawBoard(matrix);
         getString(buffer, 1 + EXTRA_SPACES, prompt);
         selection=strtol(buffer, &p, 10);
         
         if ((selection < 0) || (selection >9))
         {
            printf("invalid selection. please try again \n");
         }
         if (buffer[0] == '\0')
         {
            printf("Exiting to Main Menu.... \n \n");
            return;
         }
         else if ((buffer[0] != '\n') && ( *p == '\n' || *p == '\0'))
           { 
            /*check for non numeric characters - also semi done in selection check */
            if  (selection <= 9 && selection > 0)
            {
               for (x=0; x < NUM_ROWS; x++)
               {
                  for (y=0; y < NUM_COLS; y++)
                  {  
                     if ( matrix[x][y] == (char)buffer[0])
                     {
                        matrix[x][y]='O';
                     }  
                  }
               }
            }
            else
               printf("invalid Range");
          }
         
         check=checkWin(matrix);
         if (check != NULL)
         {
            printf("\nPlayer %c WON!\n", check);
            drawBoard(matrix);
            printf("Returning to Menu\n");
            (optionStats[3])++;
            return;
         }
         playerNum=1;
      }
   }
}


/****************************************************************************
* This function prompts the user for a integer N and several lines of
* text (sentences between 150-200 characters. The text will be printed
* N characters per line, by adding extra spaces as evenly as possible
* so there are no broken words. See requirement #6 in the assignment
* specification.
****************************************************************************/
void formattingText(int *optionStats)
{
   char *prompt1= "Enter a max number of characters per line: ";
   char *prompt2= "Enter a sentence (between 150-200) characters: ";
   char buffer [200 + EXTRA_SPACES];
   char linefeeder [200 + EXTRA_SPACES];
   char number [3+ EXTRA_SPACES];
   int MAX_CHARS_LINE;
   char *p;
   int i;
   char SPACE = ' ';
   int pointer;
   int spacecounter;
   int insertcounter;

   getString(number, 3 + EXTRA_SPACES, prompt1);
   MAX_CHARS_LINE = strtol(number,&p,10);
   if(number[0] == '\0')
   {
      printf("Exiting to Main Menu.... \n");
      return;
   }

   getString(buffer, 200 + EXTRA_SPACES, prompt2);
   if(buffer[0] == '\0')
   {
      printf("Exiting to Main Menu.... \n");
      return;
   }
   
   printf("%d - max number \n", MAX_CHARS_LINE);
   printf("%s \n", buffer);
   /*initialise the pointer for the string*/
   pointer = (MAX_CHARS_LINE-1);
   /*all in a while loop */
   while (buffer[pointer] != '\0')
   {
      /*is char is a space*/
      /*clear out linefeeder before using again*/
      if (buffer[pointer] == SPACE)
      {
         printf("space detected");
         spacecounter=0;
         /*copy upto MAX_CHARS into linefeeder and print out*/
         for(i=0;i <= (MAX_CHARS_LINE-1); i++)
         {
            if (buffer[i] == SPACE)
            {
             spacecounter++;
            }  
            linefeeder[i] = buffer[i];
         }
         linefeeder[MAX_CHARS_LINE] = '\n';
         pointer=pointer+ MAX_CHARS_LINE;
         printf("%s ...spaces: %d\n",linefeeder, spacecounter);
      }
      /*if char is not a space*/
      if (buffer[pointer] != SPACE)
      {
         printf("Character detected");
         /*initiliase the counters of characters iterated and spaces already in array*/
         spacecounter=0;
         insertcounter=0;
         while (buffer[pointer] != SPACE)
         {
            pointer--;
            insertcounter++;
         }
         for (i=pointer; i <=( (MAX_CHARS_LINE-1) + pointer); i++)
         {
            if (buffer[i] == SPACE)
            {
               spacecounter++;
            }
         }

         printf(" %d spaces should be inserted. Currently %d spaces.", insertcounter, spacecounter);
         if (buffer[pointer] == SPACE)
         {
            /*write to line feeder adding in extra spaces evenly*/
         }
      }
   } 
}


/*************************************************************************
* This function will report a Session Summary of the running of your
* program. This summary needs to output the number of times each option
* has been processed (not including the Exit option). See requirement #7
* in the assignment specification.
*************************************************************************/
void sessionSummary(int *optionStats)
{
   printf("--------------------------------\n\nSESSION SUMMARY\n\n");
   printf("Perfect Sqaures: %d \n", optionStats[0]);
   printf("ASCII to Binary: %d \n", optionStats[1]);
   printf("Matching Brackets: %d \n", optionStats[2]);
   printf("Tic Tac Toe Game: %d \n", optionStats[3]);
   printf("Formatting Text: %d \n", optionStats[4]);
}
