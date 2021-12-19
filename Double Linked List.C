#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node *head = NULL, *tail = NULL, *cur, *temp, *temp1;

struct node* create(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the value to be entered into the data of the node:\n ");
    for(int i = 0; i < n; i++){
        cur = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &cur->data);
        cur->prev = NULL;
        cur->next = NULL;
        if(head == NULL){
            head = cur;
            tail = cur;
        }
        else{
            temp = head;
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
    }
    return head;
}

struct node* insert_begin(int ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    cur->prev = NULL;
    cur->next = head;
    head->prev = cur;
    head = cur;
    return head;
}

struct node* insert_end(int ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    cur->next = NULL;
    cur->prev = tail;
    tail->next = cur;
    tail = cur;
    return head;
}

struct node* insert_pos(int pos, int ele){
    int c = 0;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    temp = head;
    while(c < pos){
        temp1 = temp;
        temp = temp->next;
        c++;
    }
    temp1->next = cur;
    cur->prev = temp1;
    cur->next = temp;
    temp->prev = cur;

}

struct node* delete_begin(struct node* head){
    temp = head;
    head = head->next;
    printf("Deleted element %d\n", temp->data);
    head->prev = NULL;
    free(temp);
    return head;
}

struct node* delete_end(struct node* tail){
    temp = tail;
    tail = tail->prev;
    printf("Deleted element %d\n", temp->data);
    tail->next = NULL;
    free(temp);
    return head;
}

struct node* delete_pos(struct node* head, int pos){
    int c = 1;
    temp = head;
    while(c < pos){
        temp1 = temp;
        temp = temp->next;
        c++;
    }
    temp1->next = temp->next;
    temp->next->prev = temp;
    printf("Deleted element %d \n", temp->data);
    free(temp);
    return head;
}

void display(struct node* head){
    temp = head;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void reverse_display(struct node* tail){
    temp = tail;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->prev;
    }
}


int main(){
    int ch, ele, pos, key;
    while(1){
        printf("Enter your choice\n");
        printf("1: create\n2: insert_begin\n3: insert_end\n4: insert_pos\n5: delete_begin\n6: delete_end\n7: delete_pos\n8: display\n9: reverse_display\n10: exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:head = create();
                break;
            case 2:printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert_begin(ele);
                break;
            case 3:printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert_end(ele);
                break;
            case 4:printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_pos(pos , ele);
                break;
            case 5:head = delete_begin(head);
                break;
            case 6:head = delete_end(head);
                break;
            case 7:printf("Enter the position\n");
                scanf("%d", &pos);
                head = delete_pos(head, pos);
                break;
            case 8:display(head);
                break;
            case 9:reverse_display(tail);
                break;
            case 10:exit(0);
        }
    }
}
