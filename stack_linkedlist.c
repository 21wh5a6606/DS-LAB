#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL,*cur,*temp;
void push(int ele)
{
    cur = (struct node*)malloc(sizeof(struct node));
    cur -> data =ele;
    if(top == NULL)
        cur -> link = NULL;
    else
        cur -> link = top;
    top = cur;
}
int pop()
{
    temp = top;
    if(top == NULL)
        printf("stack underflow");
    else
        top = top -> link;
    return temp -> data;
    free(temp);
}
int peek()
{
    if(top == NULL)
    printf("stack underflow");
    else
    printf("top most element is %d",peek());
}
void display()
{
    temp = top;
    while(temp != NULL)
    {
        printf("%d\n" ,temp -> data);
        temp = temp -> link;
    }
}

int main()
{
    int ch,ele;
    while(1)
    {
        printf("1:push\n 2:pop\n 3:peek\n 4:display\n 5:exit");
        scanf("%d",&ch);
    switch (ch)
    {
    case 1: printf("enter element to be inserted");
            scanf("%d",&ele);
            push(ele);
            break;
    case 2: printf("deleted element is %d",pop());
            break;
    case 3: printf("top most element is %d",peek());
            break;
    case 4: if(top == NULL)
            printf("stack underflow");
            else
            display();
            break;
    case 5: exit(0);
    }
    }
    }
#OUTPUT
1:push
 2:pop
 3:peek
 4:display
 5:exit1
enter element to be inserted2
1:push
 2:pop
 3:peek
 4:display
 5:exit1
enter element to be inserted3
1:push
 2:pop
 3:peek
 4:display
 5:exit1
enter element to be inserted5
1:push
 2:pop
 3:peek
 4:display
 5:exit4
5
3
2
1:push
 2:pop
 3:peek
 4:display
 5:exit2
deleted element is 51:push
 2:pop
 3:peek
 4:display
 5:exit4
3
2
1:push
 2:pop
 3:peek
 4:display
 5:exit3
top most element is 31:push
 2:pop
 3:peek
 4:display
 5:exit4
3
2
1:push
 2:pop
 3:peek
 4:display
 5:exit
 
 #UNDERFLOW 
 1:push
 2:pop
 3:peek
 4:display
 5:exit1
enter element to be inserted2
1:push
 2:pop
 3:peek
 4:display
 5:exit2
deleted element is 21:push
 2:pop
 3:peek
 4:display
 5:exit2
stack underflow

