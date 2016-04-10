#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}NODE;

NODE* createNode();
void displayList(NODE *head);
void insertAt(NODE* head, int value, int position);
void deleteAt(NODE *head, int position);

int main(int argc, char *argv[])
{
	NODE *head = createNode();
	int i;	
	head->next = NULL;
	NODE *temp = head;
	for(i=1; i<argc; i++)
	{
		head->data = atoi(argv[i]);
		head->next = createNode();
		head = head->next;
	}
	printf("\t List status: ");
	head = temp;
	displayList(head);
	//insert and delete options
	while(1)
	{
		int opt;
	        printf("Choose one of the options: \n 1. insert \n 2. delete \n 3. exit \n : ");
        	scanf("%d",&opt);
		int value, position;
	        switch (opt)
        	{
			case 1:
	                 printf("\nEnter the value to be inserted: ");
        	         scanf("%d", &value);
                	 printf("Enter the posiotion number for it: ");
	                 scanf("%d",&position);
			 head = temp;
                	 insertAt(head,value,position);
			 break;
       			case 2:
	                 printf("\nEnter the position number to be deleted: ");
        	         scanf("%d",&position);
			 head = temp;
			 deleteAt(head,position);
			 break;
			case 3:
			 exit(1);
			default:
			 printf("\nInvalid choice!\n");
		}
		printf("\t List status: ");
		head = temp;
		displayList(head);
	}
	
return 0;
}

void displayList(NODE *head)
{
	while(head->next != NULL)
	{
		printf("\t%d -> ",head->data);
		head = head->next;
	}
	printf("null\n\n");
}

void insertAt(NODE* head, int value, int position)
{
int count = 0;
while (head != NULL)
	{
	count++;
	if (count == (position - 1) )
		break;
	head = head->next;
	}
NODE* nextone = head->next;
head->next = createNode();
head->next->data = value;
head->next->next = nextone;
}

void deleteAt(NODE *head, int position)
{
int count = 0;
while (head != NULL)
	{
	count++;
	if (count == (position - 1) )
		break;
	head = head->next;
	}
NODE* nextone = head->next;
head->next = head->next->next;
free(nextone);
} 

NODE* createNode()
{
        return ( (NODE *) malloc( sizeof(NODE)  ) );
}
