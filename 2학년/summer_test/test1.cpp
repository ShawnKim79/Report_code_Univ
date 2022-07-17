#include <stdio.h>
#include <iostream.h>

void main()
{	
	int i, j, count;

	for (i=1; i<=20 ; i++){
		count=0;
		for (j=1; j<=i ; j++)
		{
			if (!(i%j)) count=count+1;
		}
		if(count==2) printf("%d \n", i);
	}

}

j