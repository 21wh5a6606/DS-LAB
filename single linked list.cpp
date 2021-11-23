#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data; 
	struct node*link;
};
	struct node*head = NULL,*cur,*temp,*temp1;
struct node* create()
{
	int n;
	printf("enter number of nodes");
	scanf("%d",&n);
	for(int i = 0; i< n; i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&(cur->data));
		cur -> link = NULL;
		if (head == NULL)
		{
			head = cur;
		}
		else
		{
			temp = head;
			while(temp->link != NULL)
				temp = temp->link;
				temp -> link = cur;
		}
	} 
		return head;
}

struct node* insert_begin(int ele)
{
	cur = (struct node*)malloc(sizeof(struct node));
	cur-> data = ele;
	cur -> link = head;
	head = cur;
	return head;
}

struct node* insert_end(int ele)
{
	cur = (struct node*)malloc(sizeof(struct node));
	cur -> data = ele;
	cur -> link = NULL;
	temp = head;
	while(temp->link!=NULL)
	{
		temp = temp->link;
	}
	temp -> link = cur;
    return head;
}  

struct node* insert_pos(int pos,int ele)
{
	int c = 1;
	cur = (struct node*)malloc(sizeof(struct node));
	cur -> data = ele;
	temp = head;
	while (c < pos-1)
	{
		temp = temp -> link;
		c++;
		cur -> link = temp -> link;
	}
	temp -> link = cur;
	return head;
}

struct node* delete_begin(struct node * head)
{
	temp = head;
	head = temp -> link;
	printf("delete at begin %d",temp -> data);
	free(temp);
	return head;
}

struct node* delete_end(struct node * head)
{
	temp = head;
	while(temp -> link!= NULL)
	{
		//printf("element %d\n", temp-> data);
		temp1 = temp;
		temp = temp -> link;
	}
	temp1 -> link = NULL;
	printf("deleted element %d\n", temp-> data);
	free(temp);
	return head;
}

struct node* delete_pos(struct node*head, int pos)
{
	temp = head;
	int c = 1;
	while(c < pos)
	{
		temp1 = temp;
		temp = temp -> link;
		c++;
	}
		temp1 -> link = temp -> link;
		printf("deleted element at pos %d",temp -> data);
		free(temp);
	return head;
}

int search(struct node *head,int key)
{
	int c=1;
	temp = head;
	while (temp != NULL)
	{
		if(key == temp -> data)
		{
		return c;
	}
		temp = temp -> link;
	c++;
} 
	return -1;
}

struct node *sorting(struct node*head)
{
	int x,i,s;
	temp = head;
	temp1 = NULL;
	while(s)
	{
		s = 0;
		temp = head;
		while (temp -> link != temp1)
		{
			if((temp -> data) > (temp -> link -> data))
			{
				x = temp -> data;
				temp -> data = temp -> link -> data;
				temp -> link ->data = x;
				s=1;
			}
			temp = temp -> link;
		}
		temp1 = temp;
		}
		return head;
	}
	
void reverse_display(struct node*head)
{
	if(head!=NULL)
	{
		reverse_display(head -> link);
		printf("%d",head -> data);
	}
}
 
void display(struct node*head)
{
	temp = head;
	while(temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp -> link;
	}
	
}
int main()
{
	int ch,ele,pos,key;
	while(1)
	{
		printf("1-create\n 2-insert_begin\n 3-insert_end\n 4-insert_pos\n 5-delete_begin\n 6-delete_end\n 7-delete_pos\n 8-search\n 9-sorting\n 10-display\n 11-reverse_dispaly 12-exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1: head = create();
			break;
	case 2: scanf("%d",&ele);
	        head = insert_begin(ele);
	        break;
	case 3: scanf("%d",&ele);
			head = insert_end(ele);
			break;
	case 4: printf("enter pos");
			scanf("%d",&pos);
			printf("enter ele");
			scanf("%d",&ele);
			head = insert_pos(pos,ele);
	case 5: printf("enter ele");
	        scanf("%d",&ele);
	        head = delete_begin(head);
			break;
	case 6: head = delete_end(head);
			break;
	case 7: printf("enter pos");
			scanf("%d",&pos);
			head = delete_pos(head,pos);
			break;
	case 8: printf("enter key value\n");
	        scanf("%d",&key);
			pos = search(head,key);
			if(pos == -1)
				printf("element not found");
			else 
				printf("element found at %d",pos);
			break;
	case 9: head = sorting(head);
			break;
	case 10: reverse_display(head);
			 break;
	case 11: display(head);
	        break;
	case 12: exit(0);
    } 
	}
}
