#include<stdio.h>
#define MAX 10
struct que
{
	int a[MAX];
	int front,rear;
}q;
void init()
{
	q.front=-1;
}
int isfull()
{
	if(q.rear==MAX-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(q.front==-1)
	return 1;
	else
	return 0;
}
int peek()
{
	return q.a[q.rear];
}
void enq(int num)
{
	if(isfull())
	printf("que is full:");
	else
	{
	q.rear++;
	q.a[q.rear]=num;
	}
}
int delq()
{
	int num;
	if(isempty())
	printf("que is empty:");
	else
	{
	q.front++;
	num=q.a[q.front];
	return num;
	}
}
void reverse()
{
	int i;
	for(i=q.rear;i>0;i--)
	{
	printf("%d\t",q.a[i]);
	}
}
void disp()
{
	int i;
	for(i=q.front+1;i<=q.rear;i++)
	{
	printf("%d\t",q.a[i]);
	}
}
int main()
{
	int ch;
	do
	{
	printf("\nenter choice:1-enq\n2-delq\n3-peek\n4-reverse\n5-disp:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:int num;
	       printf("enter num:");
	       scanf("%d",&num);
	       enq(num);
	       break;
	 case 2:num=delq();
	        printf("delq num is:%d",num);
	        break;
	 case 3:num=peek();
	       printf("peek element is:%d",num);
	        break;
	 case 4:reverse();
	        break;
              case 5:disp();
	        break;
	}
	}while(ch<5);
}
