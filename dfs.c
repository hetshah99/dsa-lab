#include<stdio.h>
#include<stdlib.h>
struct Graph
{
	int isgValue, isgVisited;
	struct Graph *psgAdjacentLink, *psgLink;
};
struct Queue
{
	struct Graph *psgLink;
	struct Queue *psqLink;
};
void build(struct Graph **ppsgRoot, struct Graph *psgNew)
{
	struct Graph *psgTemp = *ppsgRoot, *psgNew2, *psgAdjacent, *psgAdjacent2;
	int iChoice;
	if(*ppsgRoot == NULL)
	{
		*ppsgRoot = psgNew;

			psgNew2 = (struct Graph *) malloc(sizeof(struct Graph));
			psgNew2->isgValue = psgNew->isgValue; psgNew2->isgVisited=0; psgNew2->psgLink=NULL; psgNew2->psgAdjacentLink=NULL;
			(*ppsgRoot)->psgAdjacentLink = psgNew2;

		printf("The tree was empty. So the node was inserted directly.");
		return;
	}
	while(psgTemp->psgLink != NULL)
		psgTemp = psgTemp->psgLink;
	psgTemp->psgLink = psgNew;

	psgAdjacent = psgNew;
	printf("Enter the adjacency of the node.\n");
	for(psgTemp=*ppsgRoot ; psgTemp!=NULL ; psgTemp=psgTemp->psgLink)
	{
		if(psgNew->isgValue!=psgTemp->isgValue)
		{
		printf("Is %d connected to %d? (1-Yes, 2-No):",psgNew->isgValue,psgTemp->isgValue);
		scanf("%d",&iChoice);
		if(iChoice == 2)
			continue;

		psgNew2 = (struct Graph *) malloc(sizeof(struct Graph));
		psgNew2->isgValue = psgTemp->isgValue; psgNew2->isgVisited=0; psgNew2->psgLink=NULL; psgNew2->psgAdjacentLink=NULL;
		psgAdjacent->psgAdjacentLink  = psgNew2;
		psgAdjacent = psgAdjacent->psgAdjacentLink;

		psgNew2 = (struct Graph *) malloc(sizeof(struct Graph));
		psgNew2->isgValue = psgNew->isgValue; psgNew2->isgVisited=0; psgNew2->psgLink=NULL; psgNew2->psgAdjacentLink=NULL;
		for(psgAdjacent2=psgTemp ; psgAdjacent2->psgAdjacentLink!=NULL ; psgAdjacent2=psgAdjacent2->psgAdjacentLink);
		psgAdjacent2->psgAdjacentLink = psgNew2;
	}
	}

}
int find(struct Graph *psgRoot,int iNum)
{
	struct Graph *psgTemp = psgRoot;
	int flag = 0;
	while(flag!=1 && psgTemp!=NULL)
	{
		if(psgTemp->isgValue == iNum)
			flag = 1;
		psgTemp = psgTemp->psgLink;
	}
	return flag;
}

void enqueue(struct Queue **ppsqFront, struct Queue **ppsqRear, struct Graph *psgLink)
{
	struct Queue *psqNew = (struct Queue *) malloc(sizeof(struct Queue));
	psqNew->psgLink = psgLink; psqNew->psqLink=NULL;
	if(*ppsqFront == NULL)
	{
		*ppsqFront = psqNew;
		*ppsqRear = psqNew;
		return;
	}
	(*ppsqRear)->psqLink = psqNew;
	*ppsqRear = psqNew;
}
struct Graph *dequeue(struct Queue **ppsqFront, struct Queue **ppsqRear)
{
	struct Graph *psgAns=(*ppsqFront)->psgLink;
	*ppsqFront = (*ppsqFront)->psqLink;
	if(*ppsqFront == NULL)
		*ppsqRear = NULL;
	return psgAns;
}
int findQueue(struct Queue *psqFront, struct Graph *psgNode)
{
	struct Queue *psqTemp;
	int flag = 0;
	for(psqTemp=psqFront ; psqTemp!=NULL ; psqTemp=psqTemp->psqLink)
	{
		if(psqTemp->psgLink->isgValue == psgNode->isgValue)
			flag = 1;
	}
	return flag;
}
void bfs(struct Graph **ppsgRoot,int iStartNum)
{
	struct Queue *psqFront=NULL, *psqRear=NULL;
	struct Graph *psgLink,*psgTemp,*psgTemp2,*psgAdjacent;
	int iNum,iCost=-1;
	if(*ppsgRoot == NULL)
	{
		printf("The graph is empty");
		return;
	}
	for(psgTemp=*ppsgRoot ; psgTemp->isgValue!=iStartNum ; psgTemp=psgTemp->psgLink);
	enqueue(&psqFront,&psqRear,psgTemp);
	int x =psgTemp->isgValue;
	printf("The BFS spanning tree starting from %d:",psgTemp->isgValue);
	while(psqFront != NULL)
	{
		psgLink = dequeue(&psqFront,&psqRear);
		iNum = psgLink->isgValue;
		label:
		for(psgTemp=*ppsgRoot ; psgTemp!=NULL ; psgTemp=psgTemp->psgLink)
		{
			if(psgTemp->isgValue == iNum && psgTemp->isgVisited==0)
			{
				iCost++;
				//printf("%d",psgTemp->isgValue);
				for(psgAdjacent=psgTemp->psgAdjacentLink ; psgAdjacent!=NULL ; psgAdjacent=psgAdjacent->psgAdjacentLink)
				{
					for(psgTemp2=*ppsgRoot ; psgTemp2->isgValue!=psgAdjacent->isgValue ; psgTemp2=psgTemp2->psgLink);
					if(psgTemp2->isgVisited == 0 && !findQueue(psqFront,psgTemp2) && psgTemp->isgValue!=psgAdjacent->isgValue)
						printf("%d,",psgAdjacent->isgValue);
					enqueue(&psqFront,&psqRear,psgAdjacent);
				}
				printf("%d",x);
				psgTemp->isgVisited = 1;

				break;
			}
		}
	}
	for(psgTemp=*ppsgRoot ; psgTemp!=NULL ; psgTemp=psgTemp->psgLink)
	{
		if(psgTemp->isgVisited == 0)
		{
			iNum = psgTemp->isgValue;
			iCost--;
			goto label;
		}
	}
	printf("\nThe cost of tree is %d.",iCost);
}
void dfs(struct Graph **ppsgRoot, struct Graph *psgNode, int *iCost)
{
	struct Graph *psgTemp, *psgAdjacent;
	if(psgNode == NULL)
		return;
	printf("%d ",psgNode->isgValue);
	for(psgAdjacent=psgNode->psgAdjacentLink ; psgAdjacent!=NULL ; psgAdjacent=psgAdjacent->psgAdjacentLink)
	{
		for(psgTemp=*ppsgRoot ; psgTemp->isgValue!=psgAdjacent->isgValue ; psgTemp=psgTemp->psgLink);
		if(psgTemp->isgVisited == 0)
		{
			psgTemp->isgVisited = 1;
			(*iCost)++;
			dfs(ppsgRoot,psgTemp,iCost);
		}
	}
}
void unvisit(struct Graph **ppsgRoot)
{
	struct Graph *psgTemp;
	for(psgTemp=*ppsgRoot ; psgTemp!=NULL ; psgTemp=psgTemp->psgLink)
		psgTemp->isgVisited = 0;
}
void main()
{
	int iChoice,iNum, iCost=0;
	struct Graph *psgNew, *psgRoot = NULL, *psgNode;
	struct SpanTree *pssRoot = NULL;
	while(1)
	{
		printf("1.Enter a node 2.Span a tree-BFS 3.Span a tree-DFS 4.Exit\nYour choice:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: psgNew = (struct Graph *) malloc(sizeof(struct Graph));
					printf("Enter the node value:");
					scanf("%d",&psgNew->isgValue);
					psgNew->psgAdjacentLink = NULL; psgNew->psgLink = NULL; psgNew->isgVisited=0;
					build(&psgRoot,psgNew);
					break;

			case 2: printf("Enter the starting node:");
					label:
					scanf("%d",&iNum);
					if(!find(psgRoot,iNum))
					{
						printf("Enter proper node value:");
						goto label;
					}
					bfs(&psgRoot,iNum);
					unvisit(&psgRoot);
					break;
			case 3: if(psgRoot == NULL)
					{
						printf("The graph is empty.");
						break;
					}
					printf("Enter the starting node:");
					label2:
					scanf("%d",&iNum);
					if(!find(psgRoot,iNum))
					{
						printf("%d node not present in the graph. Enter proper node value:",iNum);
						goto label2;
					}
					for(psgNode=psgRoot ; psgNode->isgValue!=iNum ; psgNode=psgNode->psgLink);
					printf("The DFS spanning tree starting from %d:",psgNode->isgValue);
					label3:
					psgNode->isgVisited = 1;
					dfs(&psgRoot,psgNode,&iCost);
					for(psgNode=psgRoot ; psgNode!=NULL ; psgNode=psgNode->psgLink)
					{
						if(psgNode->isgVisited == 0)
							goto label3;
					}
					unvisit(&psgRoot);
					printf("\nThe cost of the tree is: %d",iCost);
					break;
			case 4: exit(0);
			default: printf("Enter proper choice:");
		}
		printf("\n\n");
	}
}
