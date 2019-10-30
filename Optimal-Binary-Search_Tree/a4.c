#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// A utility function to get sum of array elements
// freq[i] to freq[j]

size_t string_parser( const char *input, char ***word_array)
{
    size_t n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( isspace( ( unsigned char )*p ) ) ++p;
        n += *p != '\0';
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
    }

    if ( n )
    {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) );

        p = input;

        while ( *p )
        {
            while ( isspace( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !isspace( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }
    }

    return n;
}


int sum(int freq[], int i, int j);

// A recursive function to calculate cost of optimal
// binary search tree
int optCost(int freq[], int i, int j)
{
   // Base cases
   if (j < i)      // no elements in this subarray
     return 0;
   if (j == i)     // one element in this subarray
     return freq[i];

   // Get sum of freq[i], freq[i+1], ... freq[j]
   int fsum = sum(freq, i, j);

   // Initialize minimum value
   int min = INT_MAX;

   // One by one consider all elements as root and
   // recursively find cost of the BST, compare the
   // cost with min and update min if needed
   for (int r = i; r <= j; ++r)
   {
       int cost = optCost(freq, i, r-1) +
                  optCost(freq, r+1, j);
       if (cost < min)
          min = cost;
   }

   // Return minimum value
   return min + fsum;
}

// The main function that calculates minimum cost of
// a Binary Search Tree. It mainly uses optCost() to
// find the optimal cost.
int optimalSearchTree(int keys[], int freq[], int n)
{
     // Here array keys[] is assumed to be sorted in
     // increasing order. If keys[] is not sorted, then
     // add code to sort keys, and rearrange freq[]
     // accordingly.
     return optCost(freq, 0, n-1);
}

// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

// Driver program to test above functions
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int i = 0;
    char ** word_array = NULL;
    char *s;
    int n = sizeof(keys)/sizeof(keys[0]);

    int menuNum = 0;

  //  char *buffer;
    FILE *fp;
    char ch;
	  int count=0;
    long length;
    char key[1500];
    int checker = 0;



    do{
      printf("What would you like to do?\n");
      scanf("%d", &menuNum);

      switch(menuNum){

        case 1:
        printf("Initialize Tree\n");
        fp = fopen("data_7.txt", "r");

        //code to count the content of the file


        printf("\nContents of the File is:");
	       while((ch=fgetc(fp))!=EOF) {
		         count++;
		        // printf("%c", ch);
	          }

        printf("Total characters is: %d\n", count);

        fseek (fp, 0, SEEK_END);
        length = ftell (fp);
         s = malloc (length);
        fseek (fp, 0, SEEK_SET);

        if (s)
        {
          fread (s, 1, length, fp);
        }
        size_t n = string_parser( s, &word_array );

        printf("test : %s \n", word_array[1]);


        fclose(fp);

        break;

        case 2:
        printf("enter key\n");
        break;

        case 3:
        printf("Exit program.\n");
        return 0;
        break;
      }

    }while(menuNum < 4);



    printf("Cost of Optimal BST is %d ",
               optimalSearchTree(keys, freq, n));
    return 0;
}
