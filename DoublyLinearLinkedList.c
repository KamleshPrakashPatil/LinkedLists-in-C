#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iNo;
	newn->prev=NULL;
	newn->next=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=(*head);
		(*head)->prev=newn;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int iNo)
{
	PNODE newn=NULL;
	PNODE Temp=NULL;
	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=iNo;
	newn->prev=NULL;
	newn->next=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		Temp=*head;
		while(Temp->next!=NULL)
		{
			Temp=Temp->next;
		}
		Temp->next=newn;
		newn->prev=Temp;
	}
}

void DeleteFirst(PPNODE head)
{
	if(*head==NULL)
	{
		return;
	}

	if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		*head=(*head)->next;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp=*head;
	if(*head==NULL)
	{
		return;
	}

	if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		while((temp->next->next)!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}	
}

void Display(PNODE head)
{
	while(head!=NULL)
	{
		printf("| %d |<=>",(head->data));
		head=head->next;
	}
	printf("| NULL |\n");
}

int Count(PNODE head)
{
	int iCnt=0;
	while(head!=NULL)
	{
		iCnt++;
		head=head->next;
	}
	return iCnt;
}

void InsterAtPos(PPNODE head,int iNo,int pos)
{
	int iSize=0,iCnt=0;
	iSize=Count(*head);
	PNODE newn=NULL;
	PNODE Temp=NULL;
	
	if((pos<1)||(pos>iSize+1))
	{
		printf("Invalid Poition\n");
		return;
	}

	if(pos==1)
	{
		InsertFirst(head,iNo);
	}
	else if(pos==iSize+1)
	{
		InsertLast(head,iNo);
	}
	else
	{
		Temp=*head;
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=iNo;
		newn->prev=NULL;
		newn->next=NULL;

		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			Temp=Temp->next;
		}
		newn->next=Temp->next;
		Temp->next->prev=newn;
		Temp->next=newn;
		newn->prev=Temp;
	}
}

void DeleteAtPos(PPNODE head,int pos)
{
	int iSize=0,iCnt=0;
	PNODE Temp=NULL;
	PNODE TempDelete=NULL;
	iSize=Count(*head);
	
	if((pos<1)||(pos>iSize+1))
	{
		printf("Invalid Poition\n");
		return;
	}

	if(pos==1)
	{
		DeleteFirst(head);
	}
	else if(pos==iSize+1)
	{
		DeleteLast(head);
	}
	else
	{
		Temp=*head;
		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			Temp=Temp->next;
		}
		TempDelete=Temp->next;

		Temp->next=Temp->next->next;
		Temp->next->prev=Temp;

	}
}

int main()
{
	PNODE first=NULL;
	int iRet=0;

	InsertFirst(&first,40);
	InsertFirst(&first,30);
	InsertFirst(&first,15);
	InsertFirst(&first,10);

	InsertLast(&first,50);

	Display(first);
	iRet=Count(first);
	printf("@ %d @\n",iRet);

	DeleteFirst(&first);
	Display(first);
	iRet=Count(first);
	printf("@ %d @\n",iRet);

	DeleteLast(&first);
	Display(first);
	iRet=Count(first);
	printf("@ %d @\n",iRet);

	InsterAtPos(&first,45,3);
	Display(first);
	iRet=Count(first);
	printf("@ %d @\n",iRet);

	DeleteAtPos(&first,3);
	Display(first);
	iRet=Count(first);
	printf("@ %d @\n",iRet);

	return 0;
}
