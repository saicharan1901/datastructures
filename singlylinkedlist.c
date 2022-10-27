#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}
void insertFront(LLIST *pl,int ele)
{
	NODE* newNode=createNode(ele);
	
	newNode->next=pl->head;
	pl->head=newNode;
}

void insertLast(LLIST *pl,int ele)
{
	NODE* newNode=createNode(ele);
	
	NODE* p=pl->head;
	
	if(pl->head==NULL)	//List is empty
	{
		pl->head=newNode;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}
void display(LLIST *pl)
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
/*
Precondition: List is already created and not empty
*/
int deleteFront1(LLIST *pl)
{
	NODE *p=pl->head;
	int ele;
	
	ele=p->info;				//ele=pl->head->info;
	pl->head=pl->head->next;	//pl->head=p->next;
	free(p);
	return ele;
}

/*List is created and may be empty or may have nodes*/
//Return value: indicates success or failure status
int deleteFront2(LLIST *pl,int *pele)
{
	NODE *p=pl->head;
	
	if(pl->head==NULL)
		return 0;
	else
	{
		*pele=p->info;		//*pele=pl->head->info
		pl->head=pl->head->next;
		free(p);
		return 1;
	}
	
}
/* 
int deleteFront2(LLIST *pl,int *pele)
{
	NODE *p=pl->head;
	int retValue;
	if(pl->head==NULL)
		retValue=0;
	else
	{
		*pele=p->info;		//*pele=pl->head->info
		pl->head=pl->head->next;
		free(p);
		retValue=1;
	}
	return retValue;
} */

void destroyList(LLIST *pl)
{
	NODE *p;
	
	while(pl->head!=NULL)
	{
		p=pl->head;
		pl->head=pl->head->next;	//pl->head=p->next;
		printf("%d freed\n",p->info);
		free(p);
	}
}

//Precondition: List is already created and not empty
int deleteLast(LLIST *pl)
{
	NODE *p=pl->head;
	int ele;
	if(p->next==NULL)//if(pl->head->next==NULL)//single node case
	{
		ele=p->info;
		free(p);
		pl->head=NULL;
	}
	else
	{
		while(p->next->next!=NULL)
			p=p->next;
		
		ele=p->next->info;
		free(p->next);
		p->next=NULL;
	}
	return ele;
}

int countNodes(LLIST *pl)
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

int insertAtPos(LLIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	NODE *p,*newNode;
	if(pos<0 || pos>n)
		return 0;
	else if(pos==0)
	{
		insertFront(pl,ele);
		return 1;
	}
	else
	{
		p=pl->head;
		newNode=createNode(ele);
		
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		p->next=newNode;
		return 1;
	}
}
int deleteAtPos(LLIST *pl,int *pele,int pos)
{
	int n=countNodes(pl);
	
	NODE *q=NULL,*p=pl->head;
	
	if(pos<0 || pos>=n)
		return 0;
	else if(pos==0)
	{
		return deleteFront2(pl,pele);
	}
	else
	{
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
	LLIST lobj;
	
	initList(&lobj);
	int choice;
	int ele;
	int status;
	int pos;
	do
	{
		printf("1.Insert Front 2.Insert Last 3.Display");
		printf("4. Delete Front 5.Delete Front 6.Delete Last ");
		printf("7.Insert At Pos 8. Delete at pos\n");
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
			case 4:if(lobj.head==NULL)		
						printf("List is already empty\n");
					else
					{
						ele=deleteFront1(&lobj);
						printf("Del ele is %d\n",ele);
					}
					break;
			case 5: status=deleteFront2(&lobj,&ele);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty\n");
					break;
					
			case 6:if(lobj.head==NULL)		
						printf("List is already empty\n");
					else
					{
						ele=deleteLast(&lobj);
						printf("Del ele is %d\n",ele);
					}
					break;
					
			case 7:printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter the pos\n");
					scanf("%d",&pos);
					status=insertAtPos(&lobj,ele,pos);
					if(status==0)
						printf("Invalid position\n");
					break;
			case 8: printf("Enter the pos\n");
					scanf("%d",&pos);
					status=deleteAtPos(&lobj,&ele,pos);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty or invalid pos\n");
					break;
		}
	}while(choice<9);
	destroyList(&lobj);
}