#include <iostream.h>
#include <time.h>

int main()
{
   int n, p, DivSum, Divisor, r;
   long start, stop;
   long totaltime;
   cout << "* Enter the number of n : ";
   cin >> n;
   time(&start);                         
   for(p=1; p<=n; p++){               
     DivSum = 1;                         
     Divisor = 2;                        
     while( Divisor <= p-1 ){            
        r = p-((int)(p/Divisor))*Divisor;
        if(r==0)                         
           DivSum +=Divisor;             
        Divisor++;
     }
     if(DivSum==p)
        cout << p << " is a perfect number" << endl;
   }
   time(&stop);
   totaltime = stop - start;
   cout << "total time is " << totaltime << endl;
   return 0;
}
