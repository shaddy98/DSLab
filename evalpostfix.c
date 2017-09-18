#include<stdio.h>
#include<ctype.h>	//for isdigit() function

typedef struct  conversion
{
	int a[30];
	int top;
}stack;

void push(stack*,int);

int pop(stack*);

int evalpostfix(char[]);

int operation(int,int,char);

int main()
{
	char postfix[30];
	printf("\nENTER POSTFIX EXPRESSION\n");
	scanf("%s",postfix);
	printf("\n\nEvaluated VALUE OF POSTFIX EXPRESSION IS\n%d",evalpostfix(postfix));
	return 0;
}

int evalpostfix(char in[])
{
	int i,num1,num2,res;
	stack s;
	s.top=-1;
	for(i=0;in[i]!='\0';i++)
	{
			if(isdigit(in[i]))
				push(&s,in[i]-'0');
			if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/')
			{
				num1=pop(&s);
				num2=pop(&s);
				res=operation(num1,num2,in[i]);
				push(&s,res);
			}
	}
	return s.a[s.top];
}

int operation(int n1,int n2,char opr)
{
	switch(opr)
	{
		case '+':
			return n1+n2;
		case '-':
			return n1-n2;
		case '*':
			return n1*n2;
		case '/':
			return n1/n2;
	}
	return 0;
}	

void push(stack *s, int opr)
{
	s->top++;
	s->a[s->top]=opr;
}

int pop(stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty\n");
		return 0;
	}
	else
	{
		int data=s->a[s->top--];
		return data;
	}
}
	
			
