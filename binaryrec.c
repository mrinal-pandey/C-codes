/* @author: mrinal-pandey
 * Program to print binary of a given decimal number using recursion
 * Input is a single number whose binary representation is to be obtained
 * */

#include<stdio.h>
#include<stdlib.h>

void printbinary(int);

int main()
{
	int N;
	scanf("%d",&N);
	printbinary(N);
	printf("\n");
	return 0;
}

void printbinary(int N)
{
	if(N==1)
	{
		printf("1");
	}
	else
	{
		printbinary(N/2);
		printf("%d",N%2);
	}
}
