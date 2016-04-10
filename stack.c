#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push(int);
int pop();
void display();

int main()
{
	int choice, num;
	while(1)
	{
		printf("\n Enter your choice: ");
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			  printf("\nEnter the number to be insterted: ");
			  scanf("%d",&num);
			  push(num);
			  break;
			case 2:
			  num = pop();
			  break;
			case 3:
			  display();
			  break;
			case 4:
			  exit(1);
			default:
			  printf("\nInvalid choice!");
		}
	
	}
return 0;
}

void push(int element)
{
	if(top == MAX-1)
	{
		printf("\nStack is already full!");
		return;
	}
	top = top+1;
	stack[top] = element;
}

int pop()
{
	int element;
	if (top == -1)
	{
		printf("\nStack is empty!");
		return;
	}
	element = stack[top];
	top = top-1;
	printf("\n%d has been deleted",element);
	return element;
}

void display()
{
	int i;
	if (top == -1)
        {
                printf("\nStack is empty!");
                return;
        }
	printf("\n\n");
	for (i = top; i>=0; i--)
		printf("%d\n",stack[i]);
}
