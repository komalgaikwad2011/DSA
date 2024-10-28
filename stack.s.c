#include<stdio.h>
#define MAX 10
struct stack
{
	int a[MAX];
	int top;
}s;
void init()
{
	s.top=-1;
}
int isfull()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}
int peek()
{
	return s.a[s.top];
}
void push(int num)
{
	if(isfull())
	printf("stack is full:");
	else
	{
	s.top++;
	s.a[s.top]=num;
	}
}
int pop()
{
	int num;
	if(isempty())
	printf("stack is empty:");
	else
	{
	num=s.a[s.top];
	s.top--;
	return num;
	}
}
void disp()
{
	int i;
	for(i=s.top;i>0;i--)
	{
	printf("%d\t",s.a[i]);
	}
}
int main()
{
	int ch;
	do
	{
	printf("\nenter choice:1-push\n2-pop\n3-peek\n4-disp:\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:int num;
	       printf("enter num:");
	       scanf("%d",&num);
	       push(num);
	       break;
	 case 2:num=pop();
	        printf("pop num is:%d",num);
	        break;
	 case 3:num=peek();
	       printf("peek element is:%d",num);
	        break;
	 case 4:disp();
	        break;
	}
	}while(ch<4);
}
