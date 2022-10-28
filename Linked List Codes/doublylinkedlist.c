#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE* head;
}DLIST;


void initList(DLIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(int ele)
{
	NODE* newNode=malloc(sizeof(NODE));
	newNode->prev=NULL;
	newNode->next=NULL;
	newNode->info=ele;
	
	return newNode;
}

void insertFront(DLIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)
		pl->head=newNode;
	else
	{
		newNode->next=pl->head;
		pl->head->prev=newNode;
		
		pl->head=newNode;
	}
}

void insertLast(DLIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	NODE*p=pl->head;
	
	if(pl->head==NULL)
		pl->head=newNode;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		newNode->prev=p;
		p->next=newNode;
	}
}
void display(DLIST *pl)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)
		printf("List is empty\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d\n",p->info);
			p=p->next;
		}
	}
}

int deleteFront(DLIST *pl,int *pele)
{
	if(pl->head==NULL)	//List empty
		return 0;
	else if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}		//Multiple node case
	else
	{
		*pele=pl->head->info;
		pl->head=pl->head->next;
		free(pl->head->prev);
		pl->head->prev=NULL;
		return 1;
	}
}
void destroyList(DLIST *pl)
{
	if(pl->head==NULL)
		return;
	else
	{
		while(pl->head->next!=NULL)
		{
			printf("%d freed\n",pl->head->info);
			pl->head=pl->head->next;
			free(pl->head->prev);
		}
		printf("%d freed\n",pl->head->info);
		free(pl->head);
		pl->head=NULL;
	}
}
int deleteLast(DLIST *pl,int *pele)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)	//List empty
		return 0;
	else if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}		//Multiple node case
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		*pele=p->info;
		p->prev->next=NULL;
		free(p);
		return 1;
	}
}

int countNodes(DLIST *pl)
{
	NODE *p=pl->head;
	int count=0;
	
	if(pl->head==NULL)
		return count;
	else
	{
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		return count;
	}
}

int insertAtPos(DLIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>n)
		return 0;
	else if(pos==0)
	{
		insertFront(pl,ele);
		return 1;
	}
	else if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
	}
	else
	{
		NODE *p=pl->head;
		
		NODE *newNode=createNode(ele);
		
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		newNode->prev=p;
		p->next->prev=newNode;
		p->next=newNode;
	}
}
int deleteAtPos(DLIST *pl,int *pele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>=n)
		return 0;
	else if(pos==0)
		return deleteFront(pl,pele);
	else if(pos==n-1)
		return deleteLast(pl,pele);
	else
	{
		NODE *p=pl->head;
		for(int i=0;i<pos;i++)
			p=p->next;
		
		*pele=p->info;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		return 1;
	}
}


int main()
{
	DLIST lobj;
	
	initList(&lobj);
	int choice;
	int ele;
	int status;
	int pos;
	do
	{
		printf("1.Insert Front 2.Insert Last 3.Display");
		printf("4. Delete Front 5.Delete Last ");
		printf("6.Insert At Pos 7. Delete at pos\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertFront(&lobj,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertLast(&lobj,ele);
					break;
			case 3: display(&lobj);
					break;

			case 4: status=deleteFront(&lobj,&ele);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty\n");
					break;
					
			case 5: status=deleteLast(&lobj,&ele);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty\n");
					break;
					
			case 6:printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter the pos\n");
					scanf("%d",&pos);
					status=insertAtPos(&lobj,ele,pos);
					if(status==0)
						printf("Invalid position\n");
					break;
			case 7: printf("Enter the pos\n");
					scanf("%d",&pos);
					status=deleteAtPos(&lobj,&ele,pos);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty or invalid pos\n");
					break;
		}
	}while(choice<8);
	destroyList(&lobj);
}