//Anupta Islam
//1007108
//anupta@uoguelph.ca

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

//int NITER = 1000000;
int NITER;

int cnt = 0;

sem_t mutex;  //declaring sem variable

void * Count(void * a)
{

    int i, tmp;
    sem_wait(&mutex); //sem mutex is waiting
    for(i = 0; i < NITER; i++)
    {
        tmp = cnt;      /* copy the global cnt locally */
        tmp = tmp+1;    /* increment the local copy */
        cnt = tmp;      /* store the local value into the global cnt */
    }

    sem_post(&mutex);
}

int main(int argc, char * argv[])
{
	pthread_t tid1, tid2;
  sem_init(&mutex, 0, 1); //initializing sem

  //int newNitter;
if(argc == 2){  //if correct number of arguments are passed
  NITER = atoi(argv[1]); // pass argument into NITER variable
}

if(argc == 1 || argc > 2 || atoi(argv[1]) < 0 ){
  printf("usage: %s NoofTimesEachThreadIncrements \n", argv[0]); //if incorrect or a negative value is passed exit program
  exit(EXIT_FAILURE);
}




	// validate arguments
	// implementation
	// Parsing the arguments passed to your C program
	// Including the number of times that each thread increments
	// the shared count cnt
	// For example, NITER = 20000;


	// Display the number of times (entered by the user) that each thread
	// increments the shared count cnt
// PLEASE DO NOT remove or modify the following code
//	printf("2*NITER is [%d]\n", 2*NITER);
  	printf("2*NITER is [%d]\n", 2*NITER);
// End of code section

	// creating Thread 1
	if(pthread_create(&tid1, NULL, Count, NULL))
	{
		printf("\n ERROR creating thread 1");
		exit(1);
	}

	// creating Thread 2
	if(pthread_create(&tid2, NULL, Count, NULL))
	{
		printf("\n ERROR creating thread 2");
		exit(1);
	}

	if(pthread_join(tid1, NULL))	/* wait for the thread 1 to finish */
	{
		printf("\n ERROR joining thread");
		exit(1);
	}

	if(pthread_join(tid2, NULL))        /* wait for the thread 2 to finish */
	{
		printf("\n ERROR joining thread");
		exit(1);
	}

        // Display the value of count cnt
// PLEASE DO NOT remove or modify the following code
	printf("\nCounter is [%d]\n", cnt);
	if (cnt == 2 * NITER)
		printf("\nPASS\n");
	else
		printf("\nFAIL\n");
// End of code section
  sem_destroy(&mutex); //destory the sem variable
	pthread_exit(NULL);
}
