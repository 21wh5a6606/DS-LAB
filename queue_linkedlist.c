#include<stdio.h>
#include<stdlib.h> 
struct node
{
	int data;
	struct node*link;
};
struct node *front = NULL,*rear = NULL,*cur;
void enqueue()
{
	cur = (struct node*)malloc(sizeof(struct node));
		printf("enter current data");
		scanf("%d",&cur -> data);
		cur -> link = NULL;
	if(front == NULL)
		front = rear = cur;
	else
		rear -> link = cur;
		rear = cur;
}
void dequeue()
{
	if(front == NULL)
		printf("queue empty");
	else if(front == rear)
	{
		printf("deleted element is %d",front -> data);
		front = rear = NULL;
	}
	else
		printf("deleted element is %d",front -> data);
		front = front-> link;
}
void display()
{
	if(front == NULL)
		printf("queue is empty");
	else
		cur = front;
		while(cur != NULL)
		{
			printf("%d",cur -> data);
			cur = cur -> link;
		}
}
int main()
{
	int ch,element;
	while(1)
	{
		printf("1-enqueue\n 2-dequeue\n 3-display\n 4-exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
				   break;
			case 2:dequeue();
				   break;
			case 3:display();
				   break;
			case 4:exit(0);
		}
	}
}

#OUTPUT
1-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice1
enter current data2
1-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice1
enter current data3
1-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice3
231-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice2
deleted element is 21-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice3
31-enqueue
 2-dequeue
 3-display
 4-exit
enter your choice2
deleted element is 3
	
