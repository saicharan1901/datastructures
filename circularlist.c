#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE *last;
}CSLL;

void initList(CSLL *pl)
{
	pl->last=NULL;
}
void insertFront(CSLL *pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->last==NULL) //List empty case
	{
		newNode->next=newNode;
		pl->last=newNode;
	}
	else
	{
		newNode->next=pl->last->next;
		pl->last->next=newNode;
	}
}
void insertLast(CSLL *pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->last==NULL) //List empty case
	{
		newNode->next=newNode;
		pl->last=newNode;
	}
	else
	{
		newNode->next=pl->last->next;
		pl->last->next=newNode;
		pl->last=newNode;
	}
}
void display(CSLL *pl)
{	
	if(pl->last==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		NODE *p=pl->last->next;
		while(p!=pl->last)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("%d\n",p->info);
	}
}
int deleteFront(CSLL *pl,int *pele)
{
	if(pl->last==NULL)		//List empty
		return 0;
	else if(pl->last==pl->last->next) //Single node
	{
		*pele=pl->last->info;
		free(pl->last);
		pl->last=NULL;
	}							//Multiple nodes
	else
	{
		NODE *p=pl->last->next;
		*pele=p->info;
		pl->last->next=p->next;
		free(p);
		return 1;
	}
}
void destroyList(CSLL *pl)
{
	if(pl->last==NULL)
		return;
	else
	{
		NODE *p=pl->last->next;
		
		while(p!=pl->last)
		{
			pl->last->next=p->next;
			free(p);
			p=pl->last;
		}
		free(p);
		pl->last=NULL;
	}
}
int deleteLast(CSLL *pl,int *pele)
{
	if(pl->last==NULL)		//List empty
		return 0;
	else if(pl->last==pl->last->next) //Single node
	{
		*pele=pl->last->info;
		free(pl->last);
		pl->last=NULL;
		return 1;
	}							//Multiple nodes
	else
	{
		NODE *p=pl->last->next;
		
		while(p->next != pl->last)
			p=p->next;
		
		p->next=pl->last->next;
		*pele=pl->last->info;
		free(pl->last);
		pl->last=p;
		return 1;
	}
}
int countNodes(CSLL *pl)
{
	int count=0;
	if(pl->last==NULL)
		return count;
	else
	{
		NODE *p=pl->last->next;
		while(p!=pl->last)
		{
			count++;
			p=p->next;
		}
		
		return count+1;
	}
}
int insertAtPos(CSLL *pl,int ele,int pos)
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
		NODE *p=pl->last->next;
		for(int i=1;i<pos;i++)
			p=p->next;
		
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=ele;
		newNode->next=p->next;
		p->next=newNode;
		return 1;
	}
}
int deleteAtPos(CSLL *pl,int *pele,int pos)
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
		NODE *p=pl->last->next;
		NODE *q=pl->last;
		
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		
		*pele=p->info;
		q->next=p->next;
		free(p);
		return 1;
	}
}


int main()
{
	CSLL lobj;
	
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