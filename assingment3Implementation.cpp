/* 

assingment3Implementation.cpp - implementation file for a program named assingment3
============================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 


Pseudocode
----------
put the input.txt file in the data folder
read the file 
while reading the file using a for loop to read the number of test cases and the while loop to read the values
where there is a negative value on t replace with ------------------
create a structure of array to store values
once stored sort the values per each test case using the bubble sort {
whenit sorts it puts the value to be sorted in a temp location then replaces it with the other value then put that value to the new location
once done print to output file
after testing remove the prompt 


add the poisondistribution function and reuse code
adjust it to suit my needs for this assingment 
add the signature to the header file

%complexity of bubble sort
the order of complexity is big O of n^2 and this is because we have a for loop inside a for loop which makes it n by n making it n^2
this is because the if statement is only checked once therefor giving the time complaxity of 1 and therefor not affecting

Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
01/02/2020


testing
---------
to test if the bubble sort was working and how it was working I put a for loop just before the terminating brace 
when sing size-1 in the implementation file it was omiting the last values therefor I decided to remove the -1 part 
and implement it in the application file when calling the bubble sort


*/

#include "assingment3.h"
#include "linkedList.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

//function to be called when prompting users to close termiaal
void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n"); // printing to the screen
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[]) 
{ 
	fprintf(fp,"The message is: %s\n", message);
}


/* removed id and left the store_location function with the required variables for this assingment 
the unnecessary code was commented out since I no longer want it to store by unique ids
*/
int store_location(struct location_type location[],float t, int x, int y, int counting){

	//int i;

	//for loop which checks condition that the there is no repetetion
	//for(i = 0; i<=counting; i++){
	// condition for checking if new data read is not the same as that that has been already saved
	//if(location[i].x == x && location[i].y == y){
	//return -1; // if they are the same instead of saving return -1 
	//}
	//}

	//incrementing counter to ensure the same id is not given
	//return (counting + 1);
	return 0; // neccessary since i declared the function as int
}

//function for bubble sort
int bubble_sort( int numbers[], int size) {
	int i,j, temp,  tempy; // initialising all variables to be used

	for (i=0; i < size; i++) {

		for (j=i; j >= 0; j--) {
			//sorting by number of elements in the array
			if (numbers[j] > numbers[j+1]) {
				temp = numbers[j+1]; 
				numbers[j+1] = numbers[j];
				numbers[j] = temp;

			}
		}
	}
	//testing my bubble sort to see how it works
	/*int k;
	for (k = 0; k < size; k++){

	printf("%1.3f %d %d \n",location[k].t,location[k].x,location[k].y);
	}*/

	return 0;
}


// poision function 
//acknowledgement for David Vernon documentation
int samplePoisson(double lambda) {
	/* Generate a random sample from a Poisson distribution with a given mean, lambda */
	/* Use the function rand to generate a random number                              */
	static bool first_call = true;
	int count;double product;
	double zero_probability;
	/* Seed the random-number generator with current time so */
	/* that the numbers will be different every time we run  */
	if (first_call) {
		srand( (unsigned)time( NULL ));first_call = false;
	}
	count = 0;
	product = (double) rand() / (double) RAND_MAX;
	zero_probability = exp(-lambda);
	while (product > zero_probability) {
		count++;
		product = product * ((double) rand() / (double) RAND_MAX);
	}
	return(count);
}



