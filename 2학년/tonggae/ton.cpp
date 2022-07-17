#include <stdio.h>
#include <iostream.h>


void main()
{
	FILE *T_file=NULL;

	if((T_file=fopen( "data.txt", "r" )) == NULL )
      printf( "The file 'data.txt' was not opened\n" );
    else
      printf( "The file 'data.txt' was opened\n" );
	
	int *Array = new (int)(T_file->_bufsiz);

	for(int i=0 ; i<T_file->_bufsiz ; i++)
	{
		if((int)(T_file->_file) != 20)
			Array[i]=T_file->_file;
		else



//	delete Array;
//	delete T_file;

}