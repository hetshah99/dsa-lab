//Implement Traversal, Insertion and Deletion operations on doubly linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int iInfo;
	struct node *previous, *next;
};

void insert(struct node **First, int iNum)
{
	struct node *New = (struct node *) malloc(sizeof(struct node)), *Cur = *First;
	int iChoice, iCount; float iPosition;
	New->iInfo = iNum;
	if(*First == NULL)
	{
		New->previous = NULL;
		New->next = NULL;
		*First = New;
		printf("The list was empty. So, the element is inserted directly.");
		return;
	}
	printf("1.At the beginning 2.At the end 3.After element no.\nYour choice:");
	label5:
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1: label1:
				New->previous = NULL;
				New->next = *First;
				(*First)->previous = New;
				*First = New;
				break;
		case 2: label2:
				while(Cur->next != NULL)
					Cur = Cur->next;
				New->next = NULL;
				New->previous = Cur;
				Cur->next = New;
				break;
		case 3: label:
				printf("Enter the position:");
				scanf("%f",&iPosition);
				iPosition = (int) iPosition;
				if(iPosition == 0)
					goto label1;
				else if(iPosition < 0)
				{
					printf("The position entered is invalid.\n");
					goto label;
				}
				iCount = 1;
				while(iCount < iPosition && Cur!=NULL)
				{
					iCount++;
					Cur = Cur->next;
				}
				if(Cur == NULL)
				{
					printf("The position entered is more than no of elements present in the list.\n");
					goto label;
				}
				else if(Cur->next == NULL)
					goto label2;
				New->next = Cur->next;
				New->previous = Cur;
				Cur->next->previous = New;
				Cur->next = New;
				break;
			default : printf("Enter proper choice:");
						goto label5;
	}
}

void del(struct node **First)
{
	int iNum, iChoice, iCount; float iPosition;
	struct node *Cur = *First;
	if(*First == NULL)
	{
		printf("No element present in the list.");
		return;
	}
	if( (*First)->next == (*First)->previous )
	{
		iNum = (*First)->iInfo;
		*First = NULL;
		printf("Only one element was present in the list. The deleted element is %d",iNum);
		return;
	}
	printf("1.At the beginning 2.At the end 3.Element no.\nYour choice:");
	label7:
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1: label3:
				iNum = (*First)->iInfo;
				*First = (*First)->next;
				(*First)->previous = NULL;
				printf("\nThe deleted element is %d",iNum);
				break;
		case 2: label4:
				while(Cur->next != NULL)
					Cur = Cur->next;
				iNum = Cur->iInfo;
				Cur->previous->next = NULL;
				printf("\nThe deleted element is %d",iNum);
				break;
		case 3: label6:
				printf("Enter the position:");
				scanf("%f",&iPosition);
				iPosition = (int) iPosition;
				if(iPosition == 1)
					goto label3;
				else if(iPosition <= 0)
				{
					printf("The entered position is invalid.\n");
					goto label6;
				}
				iCount = 1;
				while(iCount < iPosition-1 && Cur->next!=NULL)
				{
					iCount++;
					Cur = Cur->next;
				}
				if(Cur->next == NULL)
				{
					printf("The positon of the number to be deleted is more than the no of elements present in the list.\n");
					goto label6;
				}
				else if(Cur->next->next == NULL)
					goto label4;
				iNum = Cur->next->iInfo;
				Cur->next = Cur->next->next;
				Cur->next->previous = Cur;
				printf("\nThe deleted element is %d",iNum);
				break;
			default: printf("Enter proper choice:");
					goto label7;
	}
}

void traverse(struct node *First)
{
	struct node *Cur = First;
	if(First == NULL)
	{
		printf("No elements present in the list. The list is empty.");
		return;
	}
	printf("The elements are:\n");
	while(Cur != NULL)
	{
		printf("Prev=%10u Num=%d Next=%10u\n",Cur->previous,Cur->iInfo,Cur->next);
		Cur = Cur->next;
	}
}

void main()
{
	struct node *First = NULL;
	int iNum, iChoice;
	while(1)
	{
		printf("\n1.Insert 2.Delete 3.Traverse 4.Exit\nYour choice:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("Enter the number:");
					scanf("%d",&iNum);
					insert(&First,iNum);
					break;
			case 2: del(&First);
					break;
			case 3: traverse(First);
					break;
			case 4: exit(0);
			default: printf("Enter proper choice.");
		}
	}
}
