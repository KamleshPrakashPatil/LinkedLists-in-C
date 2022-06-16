#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head,int no)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		newn->next=*head;
		*head=newn;
	}
}

void InsertLast(PPNODE head,int no)
{
	PNODE newn=NULL;
	PNODE temp=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if(*head==NULL)
	{
		*head=newn;
	}
	else
	{
		temp=*head;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}

void DeleteFirst(PPNODE head)
{
	PNODE temp=NULL;

	if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		temp=*head;
		*head=(*head)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp=NULL;

	if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		temp=*head;

		while(temp->next->next!=NULL)
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
		printf("| %d |",head->data);
		head=head->next;
	}
	printf("| NULL |\n");
}

int Count(PNODE head)
{
	int iCount=0;
	while(head!=NULL)
	{
		iCount++;
		head=head->next;
	}
	return iCount;
}

void InsertAtPos(PPNODE head,int no,int pos)
{
	int size=0,iCnt=0;
	size=Count(*head);
	PNODE newn=NULL;
	PNODE temp=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	newn->data=no;
	newn->next=NULL;

	if(pos<1||pos>(size+1))
	{
		printf("Invalid Position....\n");
		return;
	}

	if(pos==1)
	{
		InsertFirst(head,no);
	}
	else if(pos==(size+1))
	{
		InsertLast(head,no);
	}
	else
	{
		temp=*head;
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=no;
		newn->next=NULL;

		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}

		newn->next=temp->next;
		temp->next=newn;
	}
}

void DeleteAtPos(PPNODE head,int pos)
{
	int size=0,iCnt=0;
	size=Count(*head);
	PNODE temp=NULL;
	PNODE tempdelete=NULL;

	if(pos<1||pos>(size+1))
	{
		printf("Invalid Position....\n");
		return;
	}

	if(pos==1)
	{
		DeleteFirst(head);
	}
	else if(pos==(size+1))
	{
		DeleteLast(head);
	}
	else
	{
		temp=*head;

		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}

		tempdelete=temp->next;
		temp->next=temp->next->next;
		free(tempdelete);

	}
}

int main()
{
	int ret=0;
	PNODE first=NULL;

	InsertFirst(&first,11);
	InsertFirst(&first,21);	
	InsertFirst(&first,51);
	
	Display(first);
	
	ret=Count(first);
	printf("Number of nodes are: %d\n",ret);

	InsertLast(&first,101);
	InsertLast(&first,111);
	
	DeleteFirst(&first);
	Display(first);
	
	DeleteLast(&first);
	InsertFirst(&first,611);
	Display(first);
	
	DeleteFirst(&first);
	Display(first);

	InsertAtPos(&first,75,3);
	Display(first);

	DeleteAtPos(&first,3);
	Display(first);


	ret=Count(first);
	printf("Number of nodes are: %d\n",ret);
	return 0;
}