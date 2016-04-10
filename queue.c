#include <stdio.h>
#include <stdlib.h>

#define MAX 30

void insert(int);
int delete();
void display();
int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
	int choice, num;
	while(1)
	{
		printf("\n Enter your choice: ");
                printf("\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                          printf("\nEnter the number to be insterted: ");
                          scanf("%d",&num);
                          insert(num);
                          break;
                        case 2:
                          num = delete();
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
}

void insert(int element)
{
	if ( (rear - front) >= 4 )
	{
		printf("\nQueue is full!");
		return;
	}
	if (front == -1)
		front = front+1;
	rear = rear + 1;
	queue[rear] = element;
}

int delete()
{
	int element;
	if (front==-1 || front == rear + 1)
	{
		printf("\nQueue is empty!");
		return;
	}
	element = queue[front];
	front = front +1;
	printf("\n%d has been deleted",element);
}

void display()
{
	if (front==-1 || front == rear + 1)
	{
		printf("\nQueue is empty!");
		return;
	}
	int i;
	for (i=front; i<=rear; i++)
		printf("%d ",queue[i]);
}

