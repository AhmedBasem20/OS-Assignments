/*
Q2. Write a multithreaded program that makes Multiplication for two matrices.
 Allow user to enter the size and values of two matrices and multiply them
using multiple threads that each work on one matrix row. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h
#include <pthread.h>

#define MAX_SIZE 100
#define MAX_NO 1000
 
int x[MAX_SIZE][MAX_SIZE];
int y[MAX_SIZE][MAX_SIZE];
int z[MAX_SIZE][MAX_SIZE];
int count = 0;
int matSize=0;
void* multiplicationFunc(void* arg)
{
    int i = count++; //i denotes row number of resultant z
   
    for (int j = 0; j < matSize; j++)
      for (int k = 0; k < matSize; k++)
        z[i][j] += x[i][k] * y[k][j];
}

int main()
{
   
    printf("size of matrix: ");
    scanf("%d",&matSize);
 
    printf("\n First Matrix \n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++)
        {

             printf("%d ", x[i][j]);  
        }
        printf("\n");
    }
 
    printf("\n Second Matrix \n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++)
        {
       printf("%d ", y[i][j] );      
        }
        printf("\n");
    }
 
         pthread_t threads[MAX_NO];

    for (int i = 0; i < MAX_NO; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multiplicationFunc, (void*)(p));
    }
 
    for (int i = 0; i < MAX_NO; i++)
    {

        pthread_join(threads[i], NULL);
    }

    printf("\n Result \n");
    for (int i = 0; i < matSize; i++) {
        
        for (int j = 0; j < matSize; j++) {

               printf("%d ", z[i][j]);             
        }
        printf("\n");
    }
    return 0;
}