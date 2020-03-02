/* 

assingment3Application.cpp - Application file for a program named assingment3
============================================================================

This program is for Assignment No. 3, Course 04-630 Data Structures and Algorithms for Engineers. 


Pseudocode
----------
declare and initiliaze all the neccessary variables
open the files both input.txt and output.txt
when doing so check see if it is not End of file
read the number of test cases using a for loo pthen from the input.txt and inside the for loop:
read keys and their values from the input.txt and store them in initialised variables for such keys
while doing so do a string compare inside a for loop to check the actual values will be stored in order and in the correct variables
once done initialize new variables where most of the values in the key value pairs is converted to miliseconds

inside the test cases for loop create a simulaation for loop
this should run less than the runtime to prevent overflow 
inside the simulation loop:
call the posion function and pass in lambda and save the output to count
where lambda is the arrival_rate multiplied by thr increment;
use count from the poison function and create another for loop using it as the perimeter and inside the loop:
add cars into the list by calling the enqueue function 
each time a car is added increase the length of the queue to keep track
then close the inner loop
just outside the loop do the light sequencing to allow for duqueue
to do this use if statements to ensure the stated conditions are med before the light sequence changes color
then check to see if a car can leave if the light sequence is on green and departure_timer is greater the departure period
but before doing so check to see if the list is empty
dequeue a car and reduce the length of the queue
calculate the total waiting time using the waiting time
from the waiitng time check condition if the waiting time is greater than maximum waiiting time if so chang the maximum waiitng time to that
close these if conditions 
just after check queue size if its bigger than maximum queue size then change the value of maximum queue size
close the simulation loop

just outisde the simuluation check if there is still anything in the queue if so 
dequeue the cars
then calculate the required statics using the value gathered as follows 
average_queue_length total_queue_length / total number of cars in the queue 
to calculate median I need to sort the array therefor use my previous bubble sort and pass the array with with queue length
check to see if they are even or odd numbers as this changes the way median is calculated
to do this put if conditions that checks if even the divide the list take the the elemnts in the middle + that index minus 1
add the elements together and divide by 2

then calculate average wating time
as average_waiting_time  as total_waiting_time divided by total_cars


then 

print my andrew id to the output file
print the results to the output file in the specified order for example
when printing the output the values should be converted back to seconds from milliseconds

Time complexity
worse case time complexity is n^3 as I have a for inside a for loop  inside a for loop, starting from the for loop checking the number of test cases,
then checking keys tehn the for loop for enqueue
this time complexity can also be added by the other for loops inside the main simulation loop
most of the conditions are if statements which are checked once and thereby giving a complexity of 1 thereby not affecting the overal worst 
Inside the code I also call my bubble sort which has a complexity of n^2 which also adds to the time complexity of my code 
case time complexity




Author
------

Lynet T Svotwa, Carnegie Mellon University Africa
01/02/2020
revision date 16/02/2020
version 3 revision date 28/02/2020

acknowledgements
David Vernon Lab 6, Posion code and linked listed code 
TA's for guidance



testing
---------
test to see if it prints as expected by the asingmnt 
test to see if the order is hapzard the program can string perform well
test to see if parameters are changed the program will still perform
test to see if there are many test cases will the program still perform well
test to see if one of the values is abnormally different to others what will happen
test to see if some of the values are 0 will my program crush
test to see if one of the values is 0  especially for the light sequence will my program crush
test to see if all of them are 0 will my program crush
      program did not print anything to output file therefore removed the test case
test to see if I print the same test case will it give me approximate values

sample input is 
1
Arrival 10
Departure 5
Runtime 5
Increment 10
Green 10
Amber 1
Red 30

sample output is
lsvotwa
 Arrival rate:   10 cars per minute
 Departure rate: 5 s per car
 Runtime:        5 min
 Time increment: 10 ms
 Light sequence: Green 10; Amber 1; Red 30 
 Average length: 27 cars
 Median length:  26 cars
 Maximum length: 45 cars
 Average wait:   139 s
 Maximum wait:   277 s

*/
// main program for where the program is first executed

#include "assingment3.h" // to ensure that I make use of the signatures in the header file.
#include "linkedList.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main() {

	printf("lsvotwa\n");
	int counting = 0;
	int debug = TRUE;
	char message[MAX_MESSAGE_LENGTH];
	typedef char keyword[KEY_LENGTH];
	char input_string[STRING_LENGTH]; // a line read from the input file
	int number_of_runs       = 0;  // number of simulations
	int arrival_rate_input   = 0;  // cars per minute
	int departure_time_input = 0;  // second per car
	int runtime_input        = 0;  // minutes
	int increment_input      = 0;  // milliseconds
	int red_duration_input   = 0;  // seconds
	int green_duration_input = 0;  // seconds
	int amber_duration_input = 0;  // seconds
	keyword key;

	//str_light_sequence = "GREEN";
	//printf("%d",strcmp(str_light_sequence,"GREEN"));

	keyword keylist[NUMBER_OF_KEYS] = {
		"arrival",
		"departure",
		"runtime",
		"increment",
		"red",
		"amber",
		"green"
	};



	FILE *fp_in, *fp_out;

	if ((fp_in = fopen("../data/input.txt","r")) == 0) {  //precaution when opening file such that if it fails program does not crash
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt","w")) == 0) {
		printf("Error can't open output output.txt\n");      //precaution when writing to file such that if it fails program does not crash
		prompt_and_exit(1);
	}

	fprintf(fp_out," lsvotwa\n");
	//  printf("lsvotwa\n");




	//declaring variables to be used in my loops
	int number_of_test_cases = 0;
	int j,value;
	//float t, x, y;

	/* read the number of test cases from a file */
	fgets(input_string, STRING_LENGTH, fp_in);
	sscanf(input_string, "%d", &number_of_test_cases); 

	// printf("Test case: %d\n", number_of_test_cases);
	int i;


	//for loop for number of test cases
	for(i=1; i<=number_of_test_cases; i++)
	{
		for (j=0; j < NUMBER_OF_KEYS; j++) {
			//if (strcmp(key,keylist[j]) == 0) {

			fgets(input_string, STRING_LENGTH, fp_in); // read a line from the input file
			//printf("Input string: %s",input_string); // write it out to the terminal to check

			/* extract the key */
			sscanf(input_string, " %s %d", key, &value); // extracts the key and the value from the string
			//printf("key-value: %s %d\n", key, value); // write it out to the terminal to check

			/* convert the key to lower case to be safe */
			int k;
			for (k=0; k < (int) strlen(key); k++)
				key[k] = tolower(key[k]);
			printf("key-value: %s %d\n",key, value); // write it out to the terminal to check

			/* now compare it  for increment*/
			if (strcmp(key, "increment") == 0) { // strcmp() return 0 when there is a match
				increment_input = value;   // milliseconds
			}
			/* now compare it  for arrival*/
			if (strcmp(key, "arrival") == 0) { // strcmp() return 0 when there is a match
				arrival_rate_input = value;   // milliseconds
			}
			/* now compare it for departure*/
			if (strcmp(key, "departure") == 0) { // strcmp() return 0 when there is a match
				departure_time_input = value;   // milliseconds
			}
			/* now compare it for runtime */
			if (strcmp(key, "runtime") == 0) { // strcmp() return 0 when there is a match
				runtime_input = value;   // milliseconds
			}
			/* now compare it for red */
			if (strcmp(key, "red") == 0) { // strcmp() return 0 when there is a match
				red_duration_input = value;   // milliseconds
			}
			/* now compare it for amber */
			if (strcmp(key, "amber") == 0) { // strcmp() return 0 when there is a match
				amber_duration_input = value;   // milliseconds
			}
			/* now compare it for green */
			if (strcmp(key, "green") == 0) { // strcmp() return 0 when there is a match
				green_duration_input = value;   // milliseconds
			}



			//printf('%s', count);
		}
		int total_cars = 0;
		int queue_length = 0;
		int long departure_timer = 0;
		int long total_waiting_time = 0;
		int long waiting_time = 0;
		int long maximum_waiting_time = 0;
		int maximum_queue_length = 0;
		int total_queue_length = 0;
		int array_for_queue_length[60000]; //10*60*1000/10
		int long light_timer = 0;
		char* str_light_sequence = "RED";
		int average_queue_length = 0;
		int median_queue_length = 0;
		int average_waiting_time = 0;

		WINDOW_TYPE w;
		ELEMENT_TYPE e;
		LIST_TYPE list;
		initialize_list(&list); //initialising the list

		empty(&list);
		print(&list);
		int l = 0;
		//from the read items now initialize variables to make them usable
		double arrival_rate      = 0;  // cars per millisecond
		double departure_time    = 0;  // milliseconds per car
		long int runtime         = 0;  // milliseconds
		long int increment       = increment_input;  // milliseconds
		long int red_duration    = red_duration_input*1000;  // millisecond
		long int green_duration  = green_duration_input*1000;  // milliseconds
		long int amber_duration  = red_duration_input*1000;  // milliseconds
		// Total waiting time/total number of cars = avg waiting time

		int  count;               // the number of cars that arrive in any given
		// simulation interval (i.e time increment)

		double lambda;            // the mean number of cars that arrive in any one
		// similation interval (i.e. time increment)

		/*  arrival_rate_input is in cars per minute so convert to cars per millisecond   */
		arrival_rate = ((float)arrival_rate_input) / (60*1000); //converting to milliseconds

		runtime = (runtime_input)*60*1000; //converting runtime to milliseconds

		/* the Poisson distribution mean, lambda, is the arrival rate of cars during   */
		/* the simulation interval, i.e. arrival rate per millisecond multiplied by    */
		/* the number of milliseconds in each simulation interval                      */

		lambda = arrival_rate*increment;
		departure_time = (departure_time_input)*1000; //converting departure time to milli seconds
		int z;
		/* Compute the number of cars that have arrived in the current simulation interval */
		//printf("%d %d", increment_input, runtime_input);
		for(z=0; z<runtime; z=z+increment)
		{
			count = samplePoisson(lambda); //calling the samplePoison function and saving it in the count variable



			int n; //declaring variable to use in the next for loop
			//for loop for enqueueing
			for(n=0;n<count; n++){
				assign_element_values(&e,n, z); 
				enqueue(e,&list); // adding an element to the queue
				//printf(" %d %d \n", k, z);
				queue_length = queue_length+1;  //incrementing the queue length

			}


			//robot sequence
			//if condition to chance the sequence in favor of green
			if((strcmp(str_light_sequence,"RED")==0) && (light_timer > red_duration))
			{
				str_light_sequence =  "GREEN"; //changing the color to green
				light_timer = 0;    //re-initialising the light timer
				departure_timer = 0; //resetting departure timer

			}
			//if condition to chance the sequence in favor of amber
			else if((strcmp(str_light_sequence,"GREEN")==0) && (light_timer>green_duration)){
				str_light_sequence = "AMBER"; //changing the color to Amber
				light_timer = 0;  //re-initialising the light timer
			}
			//if condition to chance the sequence in favor of green
			else if((strcmp(str_light_sequence,"AMBER")==0) && (light_timer>amber_duration)){
				str_light_sequence = "RED";  //changing the color to Red
				light_timer = 0;//re-initialising the light timer
			}

			total_cars = total_cars+count; // total cars 
			//printf("Tot cars %d\n", total_cars);
			departure_timer = departure_timer+increment; //incrementing departure timer
			light_timer = light_timer+increment; //incremenitn the light timer

			if((departure_timer>departure_time) && (strcmp(str_light_sequence,"GREEN")==0))
			{   
				//cheching to see if the list is empty 
				if(!is_empty(&list))
				{
					//printf("nothing in list \n");
					e = dequeue(&list);
					queue_length = queue_length-1; //decreasing the queue length uponeach dequeue
					departure_timer = 0; //initialising departure timer
					//printf("%d ", e.mytime);
					waiting_time = z-e.mytime; //calculating waiting time then saving it to the varibale waiting time
					//printf("wait tym %d \n", waiting_time);
					total_waiting_time = total_waiting_time+waiting_time; //incrementing total waiting time
					//printf("Tot Wait Time %d\n", total_waiting_time);
					//if condition to check if waiting time is now bigger is so enter the if conditon 
					if(waiting_time > maximum_waiting_time)
					{
						maximum_waiting_time = waiting_time; //make the waiting time to be the maximum waiting time as it is the bigger value
						//print(&list);
					}
				}
				//if condition to check if queue_length is greater than maximum_queue_length
				if(queue_length>maximum_queue_length)  
				{
					maximum_queue_length = queue_length; //adding new queue length if condition above is met
					//printf("Max: %d",maximum_queue_length);

				}


			}

			total_queue_length = total_queue_length+queue_length; //incrementing total queue length
			array_for_queue_length[l] = queue_length; //storing the queue length in the array
			l++; //incrementing the index to my array

		}
		int m; //declaring my variable m which I am going to use for my for loop
		//for loop that check at the end if there are any remaining cars that needs to be dequeued 
		for(m=0; m<queue_length; m++)
		{    //condition to check if the list is empty
			if(!is_empty(&list))
			{
				e = dequeue(&list); //dequeue item from list

				departure_timer = 0; //initialising the departure timer 
				//printf("%d", e.mytime);
				waiting_time = z-e.mytime; // getting my waiitng time by subtrating the time the car left versus the time it went in the queue
				total_waiting_time = total_waiting_time+waiting_time; //incrememnting the total waiting time for future use

				//if statement checks if the new waiting time is greater than the maximum waiting time
				//if so that value is then made to be the new maximum time
				if(waiting_time > maximum_waiting_time)
				{
					maximum_waiting_time = waiting_time; // making the bigger waiting time into the new maximum time

				}

			}
		}
		int x =0; //initialising x for use when calculating median
		//calcualting average queue length
		//printf("the thing %d %d", total_queue_length, l);
		//fprintf(fp_out,"%d",total_queue_length);

		average_queue_length = total_queue_length / l; //calculating the average queue length
		//printf("average queue length %d", average_queue_length);

		//sorting my array_for_queue_length so that the figures are in order
		//I reused my bubble sort from last assingment which I modified to suit this need
		bubble_sort(array_for_queue_length,l);  // calling the bubble sort function on the array

		//the condition check to see if l is even, if yes then it enters the if statement
		if(l%2==0)
		{   
			x =l/2; //dividing to get the item in the center
			//to calculate the median we the 2 items in the middle for even numbers 
			//therefore when I divide I get the item in the middle to ge the other value I need to subtrate the index by 1
			median_queue_length = (array_for_queue_length[x] + array_for_queue_length[x-1])/2;  // calculating the median of the queue

		}

		//if it is not even then we need the middle value
		if(l%2==1){
			// we divide the list the middle item is the value we seek
			x =l/2;//dividing to get th middle element
			median_queue_length =array_for_queue_length[x]; //placing that element as the median.
		}


		//calculating average wating time
		average_waiting_time = total_waiting_time/total_cars;

		//printing to the file
		fprintf(fp_out," Arrival rate:   %d cars per minute\n", arrival_rate_input); //printing arrival rate to output file
		fprintf(fp_out," Departure rate: %d s per car\n", departure_time_input); //printing departure rate to output file
		fprintf(fp_out," Runtime:        %d min\n", runtime_input); //printing runtime to output file
		fprintf(fp_out," Time increment: %d ms\n", increment_input); //printing increment to output file
		fprintf(fp_out," Light sequence: Green %d; Amber %d; Red %d \n", green_duration_input, amber_duration_input, red_duration_input); //printing the light 
		//sequence to output file
		fprintf(fp_out," Average length: %d cars\n", average_queue_length); //printing average length to output file
		fprintf(fp_out," Median length:  %d cars\n", median_queue_length); //printing median length to output file
		fprintf(fp_out," Maximum length: %d cars\n", maximum_queue_length); //printing maximum length to output file
		fprintf(fp_out," Average wait:   %d s\n", average_waiting_time/1000); //printing average wait to output file which i have to convert back to seconds from
		//milliseconds by dividing by 1000
		fprintf(fp_out," Maximum wait:   %d s\n ", maximum_waiting_time/1000); //printing maximum wait to output file which I have to convert back to seconds from
		//milliseconds by dividing by 1000
		fprintf(fp_out," \n"); //for visibility  need a new line





	}

	//closing the files
	fclose(fp_in);
	fclose(fp_out);
	// since asked for no prompt I commneted the last 2 lines for that out
	/*_getch();		
	prompt_and_exit(0);*/
	//}
}