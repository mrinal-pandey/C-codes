/* @author: mrinal-pandey
 * Program to sort given numbers using Insertion sort
 * */

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int main()
{
	int a[MAX],i,j,k,key;
	
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=1;i<MAX;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}

		a[j+1]=key;
	}
	
	printf("\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}
