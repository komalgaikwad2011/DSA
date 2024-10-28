#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front,*rear;
void init()
{
	front=NULL;
}
int isempty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}
void add(int num)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	if(front==NULL)
	{
	front=rear=newnode;
	}
	else
	{
	rear->next=newnode;
	rear=newnode;
	}
}
int delq()
{
	int num;
	struct node *temp;
	if(isempty())
	{
	printf("que is empty:");
	}
	else
	{
	temp=front;
	num=temp->data;
	front=front->next;
	free(temp);
	  return num;
	}
}
int peek()
{
	return front->data;
}
void disp()
{
	struct node *temp=front;
	for(temp=front;temp!=NULL;temp=temp->next)
	{
	printf("%d\t",temp->data);
	}
}
void main()
{
	int ch;
	do
	{
	printf("\nenter choice:1-add\n2-delq\n3-peek\n4-disp:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:int num;
	       printf("enter data:");
	       scanf("%d",&num);
	       add(num);
	       printf("add element is:%d",num);
	       break;
	 case 2:num=delq();
	       printf("remove is:%d",num);
	        break;
	 case 3:num=peek();
	        printf("\npeek is:%d",num);
	        break;
	 case 4:disp();
	        break;
	}
	}while(ch<4);
}
