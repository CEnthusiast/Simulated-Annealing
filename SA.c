#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10

int main(){
	
	int initial[N],final[N], i,k, T, Tmax, Tmin, DE, random;
	float probability;
	
	time_t t;

  	/* Intializes random number generator */
   	srand((unsigned) time(&t));
   	
   	/* Create random values for the initial array and then copy it in the final array(in the latter the values will be changed in each repeat) */
   	for(i=0; i<N; i++){
   		initial[i] = rand();
   		final[i] = initial[i];
	}

	/* Intialize Tmax and Tmin */
	Tmax = 10000;
	Tmin = 1;
	
	/* SA */
	for(T=Tmax; T>Tmin; T--){
		
		/* Pick a random array's position */
		k = rand()%N;
		
		random = rand();
		
		/* Generate a random number in [0,1] */
		probability = (double)(rand()%101) / 100;
		
		//printf("Probability = %f \n",probability);
		
		DE = random - final[k];
		
		if(DE > 0)
			final[k] = random;
		else if(exp(DE/T) > probability)
			final[k] = random;	
		
	}
	
	/* Print initial and final arrays */
	printf("Initial - Final Array Comparison\n");
	for(i=0; i<N; i++){
		printf("%d --> %d \n",initial[i],final[i]);		
	}

	return 0;
}