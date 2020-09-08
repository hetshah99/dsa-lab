#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct BSTree{
	int isbValue;
	struct BSTree *psbLeft, *psbRight;
};
void build(struct BSTree **ppsbNode, struct BSTree *psbNew)
{
	if(*ppsbNode == NULL)
	{
		*ppsbNode = psbNew;
		return;
	}
	if((*ppsbNode)->isbValue > psbNew->isbValue)
	{
		if((*ppsbNode)->psbLeft == NULL)
			(*ppsbNode)->psbLeft = psbNew;
		else
			build(&(*ppsbNode)->psbLeft,psbNew);
	}
	else
	{
		if((*ppsbNode)->psbRight == NULL)
			(*ppsbNode)->psbRight = psbNew;
		else
			build(&(*ppsbNode)->psbRight,psbNew);
	}
}
void pre_order(struct BSTree *psbNode)
{
	if(psbNode == NULL)
		return;
	printf("%d ",psbNode->isbValue);
	if(psbNode->psbLeft != NULL)
		pre_order(psbNode->psbLeft);
	if(psbNode->psbRight != NULL)
		pre_order(psbNode->psbRight);
}
void post_order(struct BSTree *psbNode)
{
	if(psbNode == NULL)
		return;
	if(psbNode->psbLeft != NULL)
		post_order(psbNode->psbLeft);
	if(psbNode->psbRight != NULL)
		post_order(psbNode->psbRight);
	printf("%d ",psbNode->isbValue);
}
void in_order(struct BSTree *psbNode)
{
	if(psbNode == NULL)
		return;
	if(psbNode->psbLeft != NULL)
		in_order(psbNode->psbLeft);
	printf("%d ",psbNode->isbValue);
	if(psbNode->psbRight != NULL)
		in_order(psbNode->psbRight);
}
void traverse(struct BSTree *psbNode)
{
	if(psbNode == NULL)
	{
		printf("The Tree is empty.");
		return;
	}
	int iChoice;
	printf("1.Pre-order 2.Post-order 3.In-order\nYour choice:");
	label:
	scanf("%d",&iChoice);
	switch(iChoice)
	{
		case 1: pre_order(psbNode);
				break;
		case 2: post_order(psbNode);
				break;
		case 3: in_order(psbNode);
				break;
		default : printf("Please enter proper choice:");
				goto  label;
	}
}
void del(struct BSTree **ppsbRoot,int iNum)
{
	int iFound; char cSide;
	struct BSTree *psbParent, *psbCurrent, *psbPred, *psbSuc, *psbQ;
	if(*ppsbRoot != NULL)
	{
		psbCurrent=(*ppsbRoot);
		psbParent=NULL;
		cSide='L';
	}
	else
	{
		printf("The tree is empty. Can't delete any number");
		return;
	}
	iFound = FALSE;
	while(iFound==FALSE && psbCurrent!=NULL)
	{
		if(psbCurrent->isbValue == iNum)
			iFound = TRUE;
		else
		{
			if(iNum < psbCurrent->isbValue)
			{
				psbParent = psbCurrent;
				psbCurrent = psbCurrent->psbLeft;
				cSide = 'L';
			}
			else
			{
				psbParent = psbCurrent;
				psbCurrent = psbCurrent->psbRight;
				cSide = 'R';
			}
		}
	}
	if(iFound == FALSE)
	{
		printf("The node is not found.");
		return;
	}
	printf("The node %d is deleted",psbCurrent->isbValue);
	if(psbCurrent->psbLeft==NULL)
		psbQ = psbCurrent->psbRight;
	else
	{
		if(psbCurrent->psbRight==NULL)
			psbQ = psbCurrent->psbLeft;
		else
		{
			psbSuc=psbCurrent->psbRight;
			if(psbSuc->psbLeft == NULL)
			{
				psbSuc->psbLeft = psbCurrent->psbLeft;
				psbQ=psbSuc;
			}
			else
			{
				psbPred = psbSuc;
				psbSuc = psbSuc->psbLeft;
				while(psbSuc->psbLeft != NULL)
				{
					psbPred = psbSuc;
					psbSuc = psbSuc->psbLeft;
				}
				psbPred->psbLeft = psbSuc->psbRight;
				psbSuc->psbLeft = psbCurrent->psbLeft;
				psbSuc->psbRight = psbCurrent->psbRight;
				psbQ = psbSuc;
			}
		}
	}
	if(psbParent == NULL)
	{
		*ppsbRoot = psbQ;
		return;
	}
	if(cSide == 'L')
		psbParent->psbLeft = psbQ;
	else
		psbParent->psbRight = psbQ;
}
int height(struct BSTree *psbNode)
{
	if(psbNode == NULL)
		return -1;
	int heightR, heightL;
	heightL = height(psbNode->psbLeft);
	heightR = height(psbNode->psbRight);
	if(heightL > heightR)
		return heightL+1;
	else
		return heightR+1;
}
int find(struct BSTree *psbNode,int iNum)
{
	struct BSTree *psbCurrent = psbNode;
	while(psbCurrent!=NULL && psbCurrent->isbValue!=iNum)
	{
		if(psbCurrent->isbValue > iNum)
			psbCurrent = psbCurrent->psbLeft;
		else
			psbCurrent = psbCurrent->psbRight;
	}
	if(psbCurrent == NULL)
		return 0;
	else if(psbCurrent->isbValue == iNum)
		return 1;
}
void main()
{
	struct BSTree *psbRoot=NULL, *psbNew;
	int iChoice,iNum;
	while(1)
	{
		printf("1.Add a number 2.Traverse tree 3.Delete a node 4.Height of the tree 5.Exit\nYour choice:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: psbNew = (struct BSTree *) malloc(sizeof(struct BSTree));
					printf("Enter your number:");
					scanf("%d",&psbNew->isbValue);
					psbNew->psbLeft=NULL; psbNew->psbRight=NULL;
					if(psbRoot!=NULL && find(psbRoot,psbNew->isbValue))
					{
						printf("Node %d is already present in the tree.",psbNew->isbValue);
						break;
					}
					build(&psbRoot,psbNew);
					break;
			case 2: traverse(psbRoot);
					break;
			case 3: if(psbRoot == NULL)
						printf("The tree is empty.");
					else
					{
						printf("Enter the number to be deleted:");
						scanf("%d",&iNum);
						del(&psbRoot,iNum);
					}
					break;
			case 4: if(height(psbRoot) != -1)
						printf("The height of the tree is:%d",height(psbRoot));
					else
						printf("The tree is empty.");
					break;
			case 5: exit(0);
		}
		printf("\n");
	}
}
