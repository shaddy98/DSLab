#include<stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],front=-1,rear=-1;

//returns true if queue is full else false
int isFull()
{
	return (front==0&&rear==MAX_SIZE-1)||(front==rear+1);
}
//returns true if queue is empty else false
int isEmpty()
{
	return front&&rear==-1;
}
//returns element at the top of the stack
void display()
{
	if(!isEmpty())
	{
	int i;
		for(i=front;i!=rear;i=(i+1)%MAX_SIZE)
		{
			printf("%d\t",queue[i]);
		}
		printf("%d\t",queue[i]);
	}
	else
	{
		printf("Queue empty");
	}
}
void insert(int e)
{
	if(!isFull())
	{
		if(isEmpty())
		{
			front=0;
		}
		
		rear=(rear+1)%MAX_SIZE;
		queue[rear]=e;
		printf("\nElement is successfully inserted");
	}
	else
	{
		printf("\n Element cannot be inserted");
	}
}
int delete()
{
	int d;
	if(!isEmpty())
	{
		
		d=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
			front=(front+1)%MAX_SIZE;
		return d;
	}
	else
	{
		printf("\n No Element to Delete. Returning -1");
		return -1;
	}
}
int main()
{
	int choice,e;
	do
	{
		printf("\nPlease Enter Your Choice");
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n\nPlease Enter the Element to be Inserted: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				e=delete();
				printf("\nThe Element Deleted is :%d",e);
				break;
			case 3:
				display();
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
