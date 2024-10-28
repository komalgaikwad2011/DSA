#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top;
void init()
{
	top=NULL;
}
void isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
void push(int num)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=top;
	top=newnode;
}
int pop()
{
	int num;
	struct node *temp=top;
	num=temp->data;
	top=top->next;
	free(temp);
	return num;
}
int peek()
{
	return top->data;
}
void disp()
{
	struct node *temp=top;
	for(temp=top;temp!=NULL;temp=temp->next)
	{
	printf("%d\t",temp->data);
	}
}
void main()
{
	int ch;
	do
	{
	printf("\nenter choice:1-push\n2-pop\n3-peek\n4-disp:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:int num;
	       printf("enter data:");
	       scanf("%d",&num);
	       push(num);
	       printf("push element is:%d",num);
	       break;
	 case 2:num=pop();
	        printf("pop is:%d",num);
	        break;
	 case 3:num=peek();
	        printf("\npeek is:%d",num);
	        break;
	 case 4:disp();
	        break;
	}
	}while(ch<4);
}
