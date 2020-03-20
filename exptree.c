/* @author: mrinal-pandey
 * Program to create an expression tree of a given postfix expression
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct tree
{
	struct tree* left;
	struct tree* right;
	char data;
}treeNode;

treeNode* stack[50];
int TOP=-1;

void push(treeNode* temp)
{
	stack[++TOP]=temp;
}

treeNode* pop()
{
	return stack[TOP--];
}

treeNode* createNode(char cs)
{
	treeNode* temp=(treeNode*)malloc(sizeof(treeNode));
	temp->right=temp->left=NULL;
	temp->data=cs;
	return temp;
}

treeNode* create(char postfix[])
{
	int i=0;
	char cs;
	treeNode* temp;
	treeNode* root;
	treeNode* popA;
	treeNode* popB;

	while(i<strlen(postfix))
	{
		cs=postfix[i];
		if(isdigit(cs))
		{
			temp=createNode(cs);
			push(temp);
		}
		else
		{
			popA=pop();
			popB=pop();
			root=createNode(cs);
			root->right=popA;
			root->left=popB;
			push(root);
		}
		i++;
	}

	return root;
}

void inorder(treeNode* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

int eval(treeNode* root)
{
	if(isdigit(root->data))
	{
		return root->data-'0';
	}
	else
	{
		switch(root->data)
		{
			case '+':
				return (eval(root->left)+eval(root->right));
				break;

			case '-':
				return (eval(root->left)-eval(root->right));
				break;

			case '*':
				return (eval(root->left)*eval(root->right));
				break;

			case '/':
				return (eval(root->left)/eval(root->right));
				break;
		}
	}
}

int main()
{
	int choice;
	treeNode* root;
	char postfix[50];
	
	while(1)
	{
		printf("1.Create\n2.Eval\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				scanf("%s",postfix);
				root=create(postfix);
				inorder(root);
				printf("\n");
				break;
			case 2:
				printf("\n%d\n",eval(root));
				break;
		}
	}

	return 0;
}
