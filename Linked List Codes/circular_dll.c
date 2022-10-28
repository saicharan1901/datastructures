#include<stdio.h> 
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}NODE;

NODE* createnode()
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    if(temp!=NULL)
        return temp;
}

void insertfront(NODE *head, int ele)
{
    NODE *temp=createnode();
    temp->data=ele;
    NODE *first=head->next;
    head->next=temp;
    temp->next=first;
    temp->prev=head;
    first->prev=temp;
}

void insertrear(NODE *ptr, int ele)
{
    NODE *last=ptr->prev;
    NODE *temp=createnode();
    temp->data=ele;
    temp->prev=last;
    last->next=temp;
    temp->next=ptr;
    ptr->prev=temp;
}

void display(NODE *ptr)
{
    NODE *cur=ptr->next;
    while(cur!=ptr)
    {
        printf("%d\t", cur->data);
        cur=cur->next;
    }
    printf("\n");
}

int deletefront(NODE *ptr)
{
    if(ptr->next==ptr)
        return 9999;
    NODE *first=ptr->next;
    ptr->next=first->next;
    first->next->prev=ptr;
    int x=first->data;
    free(first);
    return x;
}

int deleterear(NODE *ptr)
{
    if(ptr->next==ptr)
        return 9999;
    NODE *last=ptr->prev;
    ptr->prev=last->prev;
    last->prev->next=ptr;
    int x=last->data;
    free(last);
    return x;
}

int main()
{
    NODE *head=createnode();
    head->next=head;
    head->prev=head;
    int choice, ele, x, flag=1;
    while(flag==1)
    {
        printf(" 1.Insert at front\n 2. Insert at rear\n 3. Delete at front\n 4. Delete at rear\n 5. Display\n 6. Exit\n\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter element\n");
            scanf("%d",&ele);
            insertfront(head,ele);
            break;
            case 2: printf("enter element\n");
            scanf("%d",&ele);
            insertrear(head,ele);
            break;
            case 3: x = deletefront(head);
            if(x==9999)
                printf("No element to delete \n");
            else
                printf("The deleted element is %d\n", x);
            break;
            case 4: x = deleterear(head);
            if(x==9999)
                printf("No element to delete \n");
            else
                printf("The deleted element is %d\n", x);
            break;
            case 5: display(head);
            break;
            case 6: flag++;
            break;
        }
    }
    return 0;
}