#include "AnyNode.h"
#include "Function.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

void quickSort(int a[],int l, int r)
{
	if (l>r)	return ;
	int li=l;
	int ri=r;
	int mid=l;
	int v=a[mid];
	while (li<ri)
	{
		while (a[ri]>v&&li<ri)
		{
			ri--;
		}
		if(li<ri)   
        {  
            a[li] = a[ri];   
            li++;  
        }  

		while(a[li]<v&&li<ri)
		{
			li++;
		}
		if(li<ri)   
        {  
            a[ri] = a[li]; 
            ri--;  
        }  
	}
	a[li]=v;
	quickSort(a,l,li-1);
	quickSort(a,li+1,r);
}

int charToInt(char c)
{
	if (c=='A')			return 1;
	else if (c=='B')	return 2;
	else if (c=='C')	return 3;
	else if (c=='D')	return 4;
	else if (c=='E')	return 5;
	else if (c=='F')	return 6;
	else if (c=='G')	return 7;
	else if (c=='H')	return 8;
	else if (c=='I')	return 9;
	else if (c=='J')	return 10;
	else if (c=='K')	return 11;
	else if (c=='L')	return 12;
	else if (c=='M')	return 13;
	else if (c=='N')	return 14;
	else if (c=='O')	return 15;
	else if (c=='P')	return 16;
	else if (c=='Q')	return 17;
	else if (c=='R')	return 18;
	else if (c=='S')	return 19;
	else if (c=='T')	return 20;
	else if (c=='U')	return 21;
	else if (c=='V')	return 22;
	else if (c=='W')	return 23;
	else if (c=='X')	return 24;
	else if (c=='Y')	return 25;
	else if (c=='Z')	return 26;
	
	return -1;
}


int main()
{
		return 1;
}
