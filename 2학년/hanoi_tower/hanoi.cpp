#include <iostream.h>
#include <stdio.h>

struct tower{
	int* array;
	int top;
};

void main()
{
	tower a;
	tower b;
	tower c;
	int count;
	int j;
	int height;

	int* x;
	int* y;
	int* z;

	cout << "ž�� ����? : ";
	cin >> height;
	j = 1;

	x = new int[height];
	y = new int[height];
	z = new int[height];
	
	a.array = x;
	b.array = y;
	c.array = z;
	
	for (count=height ; count>0 ; count--)
	{
		//cin >> a.array[count%height] = height%(count+1);
		a.array[count-1] = j;
		cout << "ž" << count-1 << "���� ���� ���� : " << j << endl;
		j++;
	}
	for (count=0 ; count<=height ; count++)
	{
		b.array[count] = 0;
		c.array[count] = 0;
	}
	
	a.top=(height-1);
	b.top=-1;
	c.top=-1;
	
	int i=3;
	while(b.top != height-1)
	{
		/////////////////////////////////////////////////////////////////////
		// 1�� �̵�
		if((i%2))
		{
			if(a.array[a.top] == 1) // 1�� a�� �����Ҷ�.
			{
				b.top++;
				b.array[b.top]=a.array[a.top];
				a.array[a.top]=0;
				a.top--;
				
			} else if(b.array[b.top] == 1) // 1�� b�� �����Ҷ�.
			{
				c.top++;
				c.array[c.top]=b.array[b.top];
				b.array[b.top]=0;
				b.top--;
				
			} else // 1�� c�� ������ �� 
			{
				a.top++;
				a.array[a.top]=c.array[c.top];
				c.array[c.top]=0;
				c.top--;
				
			}
		}

		//////////////////////////////////////////////////////////////////////////		
		// �������� �̵�
		// 1�� a�� ����.
		if(!(i%2))
		{
			if(a.array[a.top] == 1 && a.top>-1)
			{
				if((b.top>-1) && (c.top>-1))
				{
					if(b.array[b.top]>c.array[c.top]) // b�� c���� Ŭ �� -> c�� b�� �̵�
					{
						b.top++;
						b.array[b.top] = c.array[c.top];
						c.array[c.top]=0;
						c.top--;
					} else if(b.array[b.top]<c.array[c.top])// c�� b���� Ŭ �� -> c�� b�� �̵�
					{
						c.top++;
						c.array[c.top] = b.array[b.top];
						b.array[b.top]=0;
						b.top--;
					}
				}else if(b.top<0)
				{
					b.top++;
					b.array[b.top] = c.array[c.top];
					c.array[c.top]=0;
					c.top--;
				}else if(c.top<0)
				{
					c.top++;
					c.array[c.top] = b.array[b.top];
					b.array[b.top]=0;
					b.top--;
				}

			}
			
			
			// 1�� b�� ����.
			if(b.array[b.top] == 1 && b.top>-1)
			{
				if((c.top>-1) && (a.top>-1))
				{
					if(c.array[c.top]>a.array[a.top]) // c�� a���� Ŭ �� -> a�� c�� �̵�
					{
						a.top++;
						a.array[a.top] = c.array[c.top];
						c.array[c.top]=0;
						c.top--;
						
					} else if(c.array[c.top]<a.array[a.top])// a�� c���� Ŭ �� -> c�� a�� �̵�
					{
						c.top++;
						c.array[c.top] = a.array[a.top];
						a.array[a.top]=0;
						a.top--;
					}
				}else if(c.top<0)
				{
					c.top++;
					c.array[c.top]=a.array[a.top];
					a.array[a.top]=0;
					a.top--;
				}else if(a.top<0)
				{
					a.top++;
					a.array[a.top]=c.array[c.top];
					c.array[c.top]=0;
					c.top--;
				}
			}
			
			
			// 1�� c�� ����.
			if(c.array[c.top] == 1 && c.top>-1)
			{
				if((a.top>-1) && (b.top>-1))
				{
					if(b.array[b.top]>a.array[a.top]) // b�� a���� Ŭ �� -> a�� b�� �̵�
					{
						a.top++;
						a.array[a.top] = b.array[b.top];
						b.array[a.top]=0;
						b.top--;
					
					} else if(b.array[b.top]<a.array[a.top])// a�� b���� Ŭ �� -> b�� a�� �̵�
					{
						b.top++;
						b.array[b.top] = a.array[a.top];
						a.array[a.top]=0;
						a.top--;
					}
				}else if(a.top<0)
				{
					a.top++;
					a.array[a.top] = b.array[b.top];
					b.array[b.top]=0;
					b.top--;
				}else if(b.top<0)
				{
					b.top++;
					b.array[b.top] = a.array[a.top];
					a.array[a.top] = 0;
					a.top--;
				}
			}
		}
		/*		if(a.top<0) a.array[a.top]=0;
		if(b.top<0) b.array[b.top]=0;
		if(b.top<0) b.array[b.top]=0;
		*/
		for(count=height ; count>0 ; count--)
		{
			cout << "|" << a.array[count-1] << "|";
			cout << b.array[count-1] << "|" << c.array[count-1] << "|" << endl;
		}
		cout << "==================================" << endl;
		i++;		
		
	}
	
	
}