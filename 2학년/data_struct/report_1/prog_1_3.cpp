#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
//#include <iostream.h>

#define MAX_SIZE 30000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void sort(int [], int);
int compare(int, int);
int binsearch(int [], int, int, int);

void main(void)
{
	int i, n;
	long start, stop, totaltime;
	int list[MAX_SIZE]; 

	printf("Enter the number of numbers to generate: "); 
	scanf("%d", &n);
	
	if (n<1 || n>MAX_SIZE){
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}
	
	time(&start);

	for (i=0 ; i<n ; i++){
		list[i] = rand()%30000;
		printf(" %d", list[i]);
	} 

	sort(list, n); 

	time(&stop);
	totaltime=stop-start;

	printf("\n Sorted array:\n");

	for(i=0 ; i<n ; i++)
		printf(" %d", list[i]); 
	printf("\n");

	printf("Time is %d \n", totaltime);

/*
	printf("\n * Enter a number to search : "); 
    scanf(" %d", &i); 
    while(i){
		int ind;
    	ind = binsearch(list, i, 0, n); 
		printf("\n * index of %d is %d", i, ind);
		printf("  - Enter a number to search : ");	
        scanf("%d", &i);
    }
*/
}

void sort(int list[], int n)

{
	int i, j, min, temp;
	for (i=0 ; i<n-1 ; i++){ 
		min=i; 
		for (j=i+1 ; j<n ; j++) 
			if (list[j] < list[min]) 
				min=j; 
	SWAP(list[i], list[min], temp);  
	}
}

int compare(int x, int y)
{
	if (x<y) return -1; 
	else if (x==y) return 0; 
		else return 1;
}

int binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while (left <= right) {
		middle = (left+right)/2; 
		switch (compare(list[middle], searchnum)) { 
		case -1 : return
					  binsearch(list, searchnum, middle+1, right);
			         
		case 0 : return middle;
			         
		case 1 : return
					 binsearch(list, searchnum, left, middle-1);
			         
		}
	}
	return -1;
}

			     