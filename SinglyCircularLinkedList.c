#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE Head,PNODE Tail)
{
	PNODE temp=NULL;

	if(Head==NULL)
	{
		printf("LinkedList is empty\n");
	}

	else
	{
		temp=Head;
		do
		{
			printf("| %d |",temp->data);
			temp=temp->next;
		}while(temp!=Head);
		printf("| NULL |\n");
	}
}

int Count(PNODE Head,PNODE Tail)
{
	PNODE temp=NULL;
	int iCnt=0;

	if(Head==NULL)
	{
		printf("LinkedList is empty\n");
	}

	else
	{
		temp=Head;
		do
		{
			iCnt++;
			temp=temp->next;
		}while(temp!=Head);

		return iCnt;
	}
}

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}

	else
	{
		newn->next=*Head;
		*Head=newn;

	}
	(*Tail)->next=*Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}

	else
	{
		(*Tail)->next=newn;
		*Tail=newn;
	}
	(*Tail)->next=*Head;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL)||(*Tail==NULL))
	{
		return;
	}

	if(*Head==*Tail)
	{
		free(*Head);
	}

	else
	{
		*Head=((*Head)->next);
		free((*Tail)->next);
	}
	(*Tail)->next=*Head;
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE Temp=NULL;

	if((*Head==NULL)||(*Tail==NULL))
	{
		return;
	}

	if(*Head==*Tail)
	{
		free(*Head);
	}

	else
	{
		Temp=*Head;
		while(Temp->next->next!=*Head)
		{
			Temp=Temp->next;
			*Tail=Temp;
		}
	}
	(*Tail)->next=*Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int pos)
{
	PNODE Temp=NULL;
	PNODE newn=NULL;
	int iSize=0,iCnt=0;

	iSize=Count(*Head,*Tail);


	if((pos<1)||(pos>(iSize+1)))
	{
		printf("Invalid Position\n");
	}

	if(pos==1)
	{
		InsertFirst(Head,Tail,no);
	}

	if(pos==(iSize+1))
	{
		InsertLast(Head,Tail,no);
	}

	else
	{
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=no;
		newn->next=NULL;

		Temp=*Head;

		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			Temp=Temp->next;
		}
		newn->next=Temp->next;
		Temp->next=newn;
	}

}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
	int iSize=0,iCnt=0;
	PNODE Temp=NULL,TempDelete=NULL;

	iSize=Count(*Head,*Tail);

	if((pos<1)||(pos>(iSize+1)))
	{
		printf("Invalid Position\n");
	}

	if(pos==1)
	{
		DeleteFirst(Head,Tail);
	}

	if(pos==iSize)
	{
		DeleteLast(Head,Tail);
	}

	else
	{
		Temp=*Head;

		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			Temp=Temp->next;
		}
		TempDelete=Temp->next;
		Temp->next=Temp->next->next;
		free(TempDelete);
		TempDelete=NULL;
	}
}

int main()
{
	PNODE Head=NULL;
	PNODE Tail=NULL;
	int iRet=0;

	Display(Head,Tail);

	InsertFirst(&Head,&Tail,51);
	
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertFirst(&Head,&Tail,21);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertFirst(&Head,&Tail,11);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertLast(&Head,&Tail,101);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertLast(&Head,&Tail,111);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertFirst(&Head,&Tail,5);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertLast(&Head,&Tail,201);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	DeleteFirst(&Head,&Tail);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	DeleteLast(&Head,&Tail);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	InsertAtPos(&Head,&Tail,75,4);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	DeleteAtPos(&Head,&Tail,4);
	Display(Head,Tail);
	iRet=Count(Head,Tail);
	printf("Total Nodes Present in LinkedList: %d\n",iRet);

	return 0;
}