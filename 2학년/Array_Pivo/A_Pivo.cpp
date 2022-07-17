#include <iostream.h>

void main()
{
	int Array[4];
	int first, second, third, fourth;
	int a_first, a_second, a_third, a_fourth;

	for(a_first=1 ; a_first<5 ; a_first++)
	{
		first = a_first;
		Array[0]=first;
		for(a_second=1 ; a_second<5 ; a_second++)
		{
			second = a_second;
			if(second == Array[0])
			{
				second++;
				Array[1]=second;
			}
			else
			{
				Array[1]=second;
			}

			for(a_third=1 ; a_third<5 ; a_third++)
			{
				third=a_third;
				if(third == Array[0] && third == Array[1])
				{
					third++;
					Array[2]=third;
				}
				else
				{
					Array[2]=third;
				}

				for(a_fourth=1 ; a_fourth<5 ; a_fourth++)
				{
					fourth = a_fourth;
					if(fourth == Array[0] && fourth == Array[1] && fourth == Array[2])
					{
						fourth++;
						Array[3]=fourth;
					}
					else
					{
						if(fourth > 4)
							fourth--;
					
						Array[3]=fourth;
					}

					cout << Array[0] << Array[1] << Array[2] << Array[3] << endl;
				}
			}
		}
	}


}