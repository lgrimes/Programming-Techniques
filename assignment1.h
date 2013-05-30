/*******************************:***********************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2011 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Yallara Username : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Christopher Hoobin and Xiaodong Li
******************************************************************************/

/* Header files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants. */
#define NUM_OPTION_STATS 7

/* This is used to compensate for the extra character spaces taken up by
   the '\n' and '\0' when user is asked for input through fgets(). */
#define EXTRA_SPACES 2

/* Specifies the maximum input length a user can enter for the options
   menu. */
#define MAX_OPTION_INPUT 1

/* Used for input validation. */
#define TRUE 1
#define FALSE 0

/* More constants. */
#define GRID_SIZE 3

/*max length for the perfectnum */
#define MAX_INT_LENGTH 7

/* Menu options */
#define PERFECT_SQUARES_OPTION 1
#define ASCII_TO_BINARY_OPTION 2
#define MATCHING_BRACKETS_OPTION 3
#define TIC_TAC_OPTION 4
#define FORMAT_OPTION 5
#define SUMMARY_OPTION 6
#define EXIT_OPTION 7

/* TIC TAC TOE GAME */
#define NUM_ROWS 3
#define NUM_COLS 3
#define MAX_TURNS 9

/* Function prototypes. */
void perfectSquares(int*);
void asciiToBinary(int*);
void matchingBrackets(int*);
void ticTacToeGame(int*);
void formattingText(int*);
void sessionSummary(int *);
void printMenu();
void drawBoard(char boardTurns[][NUM_COLS]);
char checkWin(char matrixGrid[][NUM_COLS]);
/* My defined utility function prototypes. */
void readRestOfLine();
int getString();
int validateNumericInput(int, char*, unsigned, char);
