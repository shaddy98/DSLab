#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;

//returns true if stack is full else false
int isFull()
{
	return top==MAX_SIZE-1;
}
//returns true if stack is empty else false
int isEmpty()
{
	return top==-1;
}
//returns element at the top of the stack
int peek()
{
	if(!isEmpty())
		return stack[top];
	else
	{
		printf("\nStack is Empty. Returning -1");
		return -1;
	}
}
void push(int e)
{
	if(!isFull())
	{
		stack[++top]=e;
		printf("\nElement is successfully inserted");
	}
	else
	{
		printf("\nStackOverflow. Element cannot be inserted");
	}
}
int pop()
{
	int d;
	if(!isEmpty())
	{
		d=stack[top--];
		return d;
	}
	else
	{
		printf("\nStackUnderflow. No Element to Delete. Returning -1");
		return -1;
	}
}
int main()
{
	int choice,e;
	do
	{
		printf("\nPlease Enter Your Choice");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n\nPlease Enter the Element to be Inserted: ");
				scanf("%d",&e);
				push(e);
				break;
			case 2:
				e=pop();
				printf("\nThe Element Deleted is :%d",e);
				break;
			case 3:
				e=peek();
				printf("\nThe Element at the Top of the Stack  is :%d",e);
				break;
			case 4:
				return 0;
				break;
			default:
				printf("\nInvalid Choide");
				break;
		}
	}while(1);
	return 0;
}
