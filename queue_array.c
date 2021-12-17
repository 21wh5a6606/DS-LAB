#include<stdio.h>
#include<stdlib.h>
#define size 5
int front = -1,rear = -1,a[size];
void enqueue(int ele)
{
a[++rear] = ele;
if(front == -1)
    front = 0;
}
int dequeue()
{
    if(front == rear)
     	front = rear = -1;
    else
    	return a[front];
        front ++;
    return a[front];
}
void display()
{
    for(int i = front;i <= rear; i++)
    printf("%d\n",a[i]);
}
int main()
{
    int ch,element;
    while(1)
    {
        printf("1-enqueue\n 2-dequeue\n 3-display\n 4-exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
    switch(ch)
    {
    case 1:if(rear == size-1)
               printf("queue overflow");
           else
                printf("enter element to be inserted");
                scanf("%d",&element);
                enqueue(element);
                break;
                break;
    case 2:if(front == -1)
		 printf("queue underflow");
            else
                printf("deleted element is %d",dequeue());
                break;
    case 3:if(front == -1)
                printf("queue empty");
           else
                display();
                break;
    case 4:exit(0);
}
}
}
