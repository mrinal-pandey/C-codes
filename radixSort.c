/* @author: mrinal-pandey
 * Program to sort given numbers using Radix sort
 * */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 5

typedef struct linkedList
{
	int value;
	struct linkedList *next;
}List;

int numberOfPasses(int a[])
{
	int i, maxNumber=0, count=0;

	for(i=0; i<MAX; i++)
	{
		if(a[i]>maxNumber)
		{
			maxNumber=a[i];
		}
	}

	while(maxNumber!=0)
	{
		maxNumber/=10;
		count++;
	}

	return count;
}

List* createNode()
{
	List* temp=(List*)malloc(sizeof(List));
	temp->next=NULL;
	return temp;
}

void insertEnd(List* temp, int number)
{
	List* newNode=createNode();
	newNode->value=number;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=newNode;
}

int main()
{
	int a[MAX],i,j=1,k,NOP,digit,tempNum;
	List* list[10];
	List* temp;

	for(i=0; i<MAX; i++)
	{
		scanf("%d", &a[i]);
	}

	NOP=numberOfPasses(a);

	while(NOP--)
	{

		for(i=0; i<10; i++)
		{
			list[i]=NULL;
		}

		for(i=0; i<MAX; i++)
		{
			tempNum=a[i];
			tempNum/=(int)pow(10,j-1);
			digit=tempNum%10;
			
			if(list[digit]==NULL)
			{
				list[digit]=createNode();
				list[digit]->value=a[i];
			}
			else
			{
				insertEnd(list[digit], a[i]);
			}
		}

		i=0;
		k=0;

		while(i<10)
		{
			if(list[i]!=NULL)
			{
				temp=list[i];
				while(temp!=NULL)
				{
					a[k]=temp->value;
					temp=temp->next;
					k++;
				}
			}

			i++;
		}

		j++;

		free(temp);
	}

	printf("\nSorted:\n");
	for(i=0; i<MAX; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
