#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct AVLTree{
	int isaValue, isaBalanceFactor;
	struct AVLTree *psaLeft, *psaRight;
};
int height(struct AVLTree *psaNode)
{
	if(psaNode == NULL)
		return -1;
	int heightR, heightL;
	heightL = height(psaNode->psaLeft);
	heightR = height(psaNode->psaRight);
	if(heightL > heightR)
		return heightL+1;
	else
		return heightR+1;
}
void rotate_left(struct AVLTree **ppsaNode,struct AVLTree **ppsaParent, char cSide)
{
	struct AVLTree *psaTemp;
	psaTemp = (*ppsaNode)->psaRight;
	(*ppsaNode)->psaRight = psaTemp->psaLeft;
	psaTemp->psaLeft = *ppsaNode;

	if(*ppsaParent != *ppsaNode)
	{
		if(cSide == 'L')
			(*ppsaParent)->psaLeft = psaTemp;
		else
			(*ppsaParent)->psaRight = psaTemp;
	}
	else
		(*ppsaParent) = psaTemp;
}
void rotate_right(struct AVLTree **ppsaNode,struct AVLTree **ppsaParent, char cSide)
{
	struct AVLTree *psaTemp;
	psaTemp = (*ppsaNode)->psaLeft;
	(*ppsaNode)->psaLeft = psaTemp->psaRight;
	psaTemp->psaRight = (*ppsaNode);

	if(*ppsaParent != *ppsaNode)
	{
		if(cSide == 'L')
			(*ppsaParent)->psaLeft = psaTemp;
		else
			(*ppsaParent)->psaRight = psaTemp;
	}
	else
		(*ppsaParent) = psaTemp;
}
void check(struct AVLTree **ppsaNode, struct AVLTree **ppsaParent, char cSide)
{
	if(*ppsaNode == NULL)
		return;
	int iHeightL1,iHeightR1,iHeightR2,iHeightL2;
	iHeightL1 = height((*ppsaNode)->psaLeft)+1;
	iHeightR1 = height((*ppsaNode)->psaRight)+1;
	if(iHeightL1 - iHeightR1 > 1)
	{
		iHeightL2 = height((*ppsaNode)->psaLeft->psaLeft)+1;
		iHeightR2 = height((*ppsaNode)->psaLeft->psaRight)+1;

		if(iHeightL2 > iHeightR2)			//Left-Left
			rotate_right(ppsaNode,ppsaParent,cSide);
		else								//Left-Right
		{
			rotate_left(&(*ppsaNode)->psaLeft,ppsaNode,'L');
			rotate_right(ppsaNode,ppsaParent,cSide);
		}
	}
	else if(iHeightR1 - iHeightL1 > 1)
	{
		iHeightL2 = height((*ppsaNode)->psaRight->psaLeft)+1;
		iHeightR2 = height((*ppsaNode)->psaRight->psaRight)+1;

		if(iHeightL2 > iHeightR2)			//Right-Left
		{
			rotate_right(&(*ppsaNode)->psaRight,ppsaNode,'R');
			rotate_left(ppsaNode,ppsaParent,cSide);
		}
		else								//Right-Right
			rotate_left(ppsaNode,ppsaParent,cSide);
	}
	check(&(*ppsaNode)->psaLeft,ppsaNode,'L');
	check(&(*ppsaNode)->psaRight,ppsaNode,'R');
}
void calcBal(struct AVLTree **ppsaNode)
{
	if(*ppsaNode == NULL)
		return;
	(*ppsaNode)->isaBalanceFactor = height((*ppsaNode)->psaLeft) - height((*ppsaNode)->psaRight);
	calcBal(&(*ppsaNode)->psaLeft);
	calcBal(&(*ppsaNode)->psaRight);
}
void build(struct AVLTree **ppsaNode, struct AVLTree *psaNew)
{
	if(*ppsaNode == NULL)
	{
		*ppsaNode = psaNew;
		return;
	}
	if((*ppsaNode)->isaValue > psaNew->isaValue)
	{
		if((*ppsaNode)->psaLeft == NULL)
			(*ppsaNode)->psaLeft = psaNew;
		else
			build(&(*ppsaNode)->psaLeft,psaNew);
	}
	else
	{
		if((*ppsaNode)->psaRight == NULL)
			(*ppsaNode)->psaRight = psaNew;
		else
			build(&(*ppsaNode)->psaRight,psaNew);
	}
}
void pre_order(struct AVLTree *psaNode)
{
	if(psaNode == NULL)
		return;
	printf("%d[%d] ",psaNode->isaValue,psaNode->isaBalanceFactor);
	if(psaNode->psaLeft != NULL)
		pre_order(psaNode->psaLeft);
	if(psaNode->psaRight != NULL)
		pre_order(psaNode->psaRight);
}
void post_order(struct AVLTree *psaNode)
{
	if(psaNode == NULL)
		return;
	if(psaNode->psaLeft != NULL)
		post_order(psaNode->psaLeft);
	if(psaNode->psaRight != NULL)
		post_order(psaNode->psaRight);
	printf("%d[%d] ",psaNode->isaValue,psaNode->isaBalanceFactor);
}
void in_order(struct AVLTree *psaNode)
{
	if(psaNode == NULL)
		return;
	if(psaNode->psaLeft != NULL)
		in_order(psaNode->psaLeft);
	printf("%d[%d] ",psaNode->isaValue,psaNode->isaBalanceFactor);
	if(psaNode->psaRight != NULL)
		in_order(psaNode->psaRight);
}
void traverse(struct AVLTree *psaNode)
{
	if(psaNode == NULL)
	{
		printf("The Tree is empty.");
		return;
	}
	int iChoice;
	printf("1.Pre-order 2.Post-order 3.In-order\nYour choice:");
	label:
	scanf("%d",&iChoice);
	printf("The tree (node[balance-factor]):");
	switch(iChoice)
	{
		case 1: pre_order(psaNode);
				break;
		case 2: post_order(psaNode);
				break;
		case 3: in_order(psaNode);
				break;
		default : printf("Please enter proper choice:");
				goto  label;
	}
}
void del(struct AVLTree **ppsaRoot,int iNum)
{
	int iFound; char cSide;
	struct AVLTree *psaParent, *psaCurrent, *psaPred, *psaSuc, *psaQ;
	if(*ppsaRoot != NULL)
	{
		psaCurrent=(*ppsaRoot);
		psaParent=NULL;
		cSide='L';
	}
	else
	{
		printf("The tree is empty. Can't delete any number");
		return;
	}
	iFound = FALSE;
	while(iFound==FALSE && psaCurrent!=NULL)
	{
		if(psaCurrent->isaValue == iNum)
			iFound = TRUE;
		else
		{
			if(iNum < psaCurrent->isaValue)
			{
				psaParent = psaCurrent;
				psaCurrent = psaCurrent->psaLeft;
				cSide = 'L';
			}
			else
			{
				psaParent = psaCurrent;
				psaCurrent = psaCurrent->psaRight;
				cSide = 'R';
			}
		}
	}
	if(iFound == FALSE)
	{
		printf("The node is not found.");
		return;
	}
	printf("The node %d is deleted",psaCurrent->isaValue);
	if(psaCurrent->psaLeft==NULL)
		psaQ = psaCurrent->psaRight;
	else
	{
		if(psaCurrent->psaRight==NULL)
			psaQ = psaCurrent->psaLeft;
		else
		{
			psaSuc=psaCurrent->psaRight;
			if(psaSuc->psaLeft == NULL)
			{
				psaSuc->psaLeft = psaCurrent->psaLeft;
				psaQ=psaSuc;
			}
			else
			{
				psaPred = psaSuc;
				psaSuc = psaSuc->psaLeft;
				while(psaSuc->psaLeft != NULL)
				{
					psaPred = psaSuc;
					psaSuc = psaSuc->psaLeft;
				}
				psaPred->psaLeft = psaSuc->psaRight;
				psaSuc->psaLeft = psaCurrent->psaLeft;
				psaSuc->psaRight = psaCurrent->psaRight;
				psaQ = psaSuc;
			}
		}
	}
	if(psaParent == NULL)
	{
		*ppsaRoot = psaQ;
		return;
	}
	if(cSide == 'L')
		psaParent->psaLeft = psaQ;
	else
		psaParent->psaRight = psaQ;
}
void split(struct AVLTree **ppsaT1,struct AVLTree **ppsaT2,struct AVLTree *psaNode,int iNum)
{
	if(psaNode == NULL)
		return;
	if(psaNode->psaLeft != NULL)
		split(ppsaT1,ppsaT2,psaNode->psaLeft,iNum);
	struct AVLTree *psaNew = (struct AVLTree *) malloc(sizeof(struct AVLTree));
	psaNew->psaLeft = NULL; psaNew->psaRight =NULL;
	psaNew->isaValue = psaNode->isaValue;
	if(psaNew->isaValue <= iNum)
	{
		build(ppsaT1,psaNew);
		check(ppsaT1,ppsaT1,'L');
	}
	else
	{
		build(ppsaT2,psaNew);
		check(ppsaT2,ppsaT2,'L');
	}
	if(psaNode->psaRight != NULL)
		split(ppsaT1,ppsaT2,psaNode->psaRight,iNum);
}
int find(struct AVLTree *psaRoot, int iNum)
{
	struct AVLTree *psaCurrent = psaRoot;
	while(psaCurrent!=NULL && psaCurrent->isaValue!=iNum)
	{
		if(psaCurrent->isaValue > iNum)
			psaCurrent = psaCurrent->psaLeft;
		else
			psaCurrent = psaCurrent->psaRight;
	}
	if(psaCurrent == NULL)
		return 0;
	else if(psaCurrent->isaValue == iNum)
		return 1;
}
void main()
{
	struct AVLTree *psaRoot=NULL, *psaNew, *psaT1 = NULL, *psaT2 = NULL;
	int iChoice,iNum;
	while(1)
	{
		printf("1.Add a number 2.Traverse tree 3.Delete a node 4.Height of the tree 5.Split 6.Exit\nYour choice:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: psaNew = (struct AVLTree *) malloc(sizeof(struct AVLTree));
					printf("Enter your number:");
					scanf("%d",&psaNew->isaValue);
					psaNew->psaLeft=NULL; psaNew->psaRight=NULL;
					if(psaRoot!=NULL && find(psaRoot,psaNew->isaValue))
					{
						printf("The node %d is already present in the tree. Cannot enter it again",psaNew->isaValue);
						break;
					}
					build(&psaRoot,psaNew);
					check(&psaRoot,&psaRoot,'L');
					calcBal(&psaRoot);
					break;
			case 2: traverse(psaRoot);
					break;
			case 3: if(psaRoot == NULL)
						printf("The tree is empty.");
					else
					{
						printf("Enter the number to be deleted:");
						scanf("%d",&iNum);
						del(&psaRoot,iNum);
					}
					check(&psaRoot,&psaRoot,'L');
					calcBal(&psaRoot);
					break;
			case 4: if(height(psaRoot) != -1)
						printf("The height of the tree is:%d",height(psaRoot));
					else
						printf("The tree is empty.");
					break;
			case 5: printf("Enter the value of the node:");
					scanf("%d",&iNum);
					if(psaRoot == NULL)
					{
						printf("The tree is empty.");
						break;
					}
					if(!find(psaRoot,iNum))
					{
						printf("The node %d is not found\n",iNum);
						break;
					}
					split(&psaT1,&psaT2,psaRoot,iNum);
					check(&psaT1,&psaT1,'L');
					calcBal(&psaT1);
					check(&psaT2,&psaT2,'L');
					calcBal(&psaT2);
					printf("Preorder traversal of the tree T1 (node[balance-factor]):");
					pre_order(psaT1);
					printf("\n");
					printf("Postorder traversal of the tree T1 (node[balance-factor]):");
					post_order(psaT1);
					printf("\n");
					printf("Inorder traversal of the tree T1 (node[balance-factor]):");
					in_order(psaT1);
					printf("\n");
					printf("Preorder traversal of the tree T2 (node[balance-factor]):");
					pre_order(psaT2);
					printf("\n");
					printf("Postorder traversal of the tree T2 (node[balance-factor]):");
					post_order(psaT2);
					printf("\n");
					printf("Inorder traversal of the tree T2 (node[balance-factor]):");
					in_order(psaT2);
					break;
			case 6: exit(0);
		}
		printf("\n\n");
	}
}
