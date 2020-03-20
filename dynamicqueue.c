/* @author: mrinal-pandey
 * Program to implement a dynamic circular queue
 * */

#include<stdio.h>
#include<stdlib.h>

void insert(int[],int*,int*,int,int*);
int delete(int[],int*,int*,int*);
void display(int[],int*,int*,int,int*);
int* queueFull(int*,int*,int*,int*);
void queueEmpty();

int main()
{
	int *queue,front=0,rear=0,count=0,MAX=5;
	int choice,deletedValue,value;
	char proceed;

	queue=(int*)malloc(MAX*sizeof(int));

	do{
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Display status\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if((rear+1)%MAX==front)
				{
					queue=queueFull(queue,&front,&rear,&MAX);
					printf("\nEnter the value to insert:\n");
					scanf("%d",&value);
					insert(queue,&front,&rear,value,&MAX);
					count++;
					display(queue,&front,&rear,count,&MAX);
				}
				else
				{
					printf("\nEnter the value to insert:\n");
					scanf("%d",&value);
					insert(queue,&front,&rear,value,&MAX);
					count++;
					display(queue,&front,&rear,count,&MAX);
				}
				break;
			case 2:
				if(front==rear)
				{
					queueEmpty();
				}
				else
				{
					deletedValue=delete(queue,&front,&rear,&MAX);
					printf("\nThe value you deleted is:%d",deletedValue);
					count--;
					display(queue,&front,&rear,count,&MAX);
				}
				break;
			case 3:
				if(front==rear)
				{
					queueEmpty();
				}
				else
				{
					display(queue,&front,&rear,count,&MAX);
				}
				break;
			case 4:
				printf("\nThe elements currently in Queue are %d\n",count);
				printf("The value of Front is %d\n",front);
				printf("The value of Rear is %d\n",rear);
				printf("Queue can still accomodate %d elements\n",MAX-count-1);
				break;
			case 5:
				printf("Exiting...");
				return 0;
				break;
			default: 
				printf("Please enter a valid input!");
		}

		printf("\nDo you want to continue?(Y/N):");
		scanf(" %c",&proceed);

	}while(proceed=='Y'||proceed=='y');

	return 0;
}

void insert(int queue[],int* front,int* rear,int value,int* MAX)
{
	*rear=(*rear+1)%*MAX;
	queue[*rear]=value;
}

int delete(int queue[],int* front,int* rear,int* MAX)
{
	*front=(*front+1)%*MAX;
	return queue[*front];
}

void display(int queue[],int* front,int* rear,int count,int* MAX)
{
	int f=*front,i;
	
	printf("\n");

	for(i=1;i<=count;i++)
	{
		printf("%d ",queue[(f+1)%*MAX]);
		f++;
	}

	printf("\n");
}

int* queueFull(int *queue,int* front,int* rear,int* MAX)
{
	int *newQ,i,f;
	f=*front;
	newQ=(int*)malloc((*MAX+1)*sizeof(int));

	for(i=0;i<*MAX-1;i++)
	{
		newQ[i]=queue[(f+1)%*MAX];
		f++;
	}

	free(queue);
	
	*front=*MAX;
	*rear=*MAX-2;
	*MAX=*MAX+1;

	return newQ;

}

void queueEmpty()
{
	printf("\nQueue Empty!\n");
}
