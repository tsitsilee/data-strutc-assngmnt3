/* 

assingment3.h - interface file for a program named assignment3
======================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 

Please refer to the application file - assingment2pplication.cpp - for details of the functionality of this program


File organization
-----------------

assingment3.h  :interface file:      
contains the declarations required to use the functions that implement the solution to this problem
typically, these will include the definitions of the abstract data types used in the implementation

assingment3Implementation.cpp  implementation file: 
contains the definitions of the functions that implement the algorithm used in the implementation

assingment3Application.cpp     application file:    
contains the code that instantiates the abstract data types and calls the associated functions
in order to effect the required functionality for this application

Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
03/02/2019


Acknowledgements
David Vernon Lab 4;
TAs;

version 2.0 this code is an update from assignment1

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81
#define MAX_NUMBER_OF_POINTS 27000 // limit given was 27000 
#define KEY_LENGTH 10
#define STRING_LENGTH 50
#define NUMBER_OF_KEYS 7


/* function prototypes go here */

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);

//declaration of the struct I am going to use including the variable types
struct location_type {
	float t;
	int x;
	int y;
};
int store_location(struct location_type location[],float t, int x, int y, int counting); /*declaration of the store_location function where 
																						 I am going to store the data i read*/
int bubble_sort( int numbers[], int size); //declaration for the bubble sort function which I choose to use
int samplePoisson(double lambda); //samplePoisionsignature 




