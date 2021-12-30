
//  Q1. Write a program that runs 5 threads, each thread randomizes a number between 1 and 10.
//   The main thread waits for all the others to finish, calculates the sum of the numbers
//    which were randomized and prints that sum. 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<time.h>

int x = 0;
int sum;
int y[5];

void *child(void *p){
srand(time(0));
    y[x]=rand()%10;
	pthread_exit(0);
};
int main( )
{
pthread_t thread[5];
for(int i = 0; i<5; i++)
{
pthread_create( &thread[i], 0,child,0 );

pthread_join(thread[i], NULL);
x++;
}	
for(int i = 0; i<5; i++){

	sum+=y[i];
}
printf( "sum= %d\n",sum);
return 0;
}
