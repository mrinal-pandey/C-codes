/* @author: mrinal-pandey
 * Demo of how a double dimensional array is used in C
 * */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,r,c,i,j;
	scanf("%d%d",&r,&c);
	a=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		*(a+i)=(int*)malloc(c*sizeof(int));
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",(*(a+i)+j));
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
	free(a);
	return 0;
}
