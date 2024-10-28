#include<stdio.h>
#include<math.h>
#define MAX 100
struct stack
{
	int a[MAX];
	int top;
}s;
int init()
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
void push(int n)
{
	if(isfull())
	printf("stack is full");
	else
	{
	s.top++;
	s.a[s.top]=n;
	}
}
int pop()
{
	int n;
	if(isempty())
	printf("stack is empty");
	else
	{
	n=s.a[s.top];
	s.top--;
	return n;
	}
}
int main()
{
	char exp[20],*e;
	int a,b,c,d,n1,n2,n3,n,i;
	printf("enter exp:");
	scanf("%s",&exp);
	printf("enter value of a,b,c and d:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=exp;
	while(*e!='\0')
	{
	if(*e=='a')
	{ push(a);}
	else if(*e=='b')
	{ push(b);}
	else if(*e=='c')
	{ push(c);}
	else if(*e=='d')
	{ push(d);}
	else
	{
	n1=pop();
	n2=pop();
	switch(*e)
	{
	case '+':{ n3=n1+n2;break;}
	case '-':{ n3=n2-n1;break;}
	case '*':{ n3=n1*n2;break;}
	case '/':{ n3=n1/n2;break;}
	}
	e++;
	}
	printf("result of %s is:%d",exp,pop());
	return 0;
	}
}











