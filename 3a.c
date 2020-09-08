#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 1
struct queue
{
	int iaQueue[QUEUE_SIZE],iFront,iRear;
};
void enqueue(struct queue *Queue,int iNum)
{
	if(Queue->iFront-Queue->iRear==1 || Queue->iFront==0&&Queue->iRear==QUEUE_SIZE-1)       //overflow
	{
		printf("The queue is full. Cannot insert any element.\n");
		exit(0);
	}
	if(Queue->iFront==-1 && Queue->iRear==-1)                                       //at the start
	{
		Queue->iFront=0; Queue->iRear=0;
	}
	else if(Queue->iRear==QUEUE_SIZE-1)                                         //for circular queuing
	{
		Queue->iRear=0;
	}
	else                                                                        //at anytime
	{
		Queue->iRear++;
	}
	Queue->iaQueue[Queue->iRear]=iNum;
}
int dequeue(struct queue *Queue)
{
	int iNum;
	if(Queue->iFront==-1)
	{
		printf("The queue is empty. Cannot delete any element.");
		exit(0);
	}
	if(Queue->iFront==QUEUE_SIZE)
	{
		Queue->iFront=0;
	}
	iNum=Queue->iaQueue[Queue->iFront];
	Queue->iFront++;
	if(Queue->iFront - Queue->iRear == 1)
	{
		Queue->iFront=-1; Queue->iRear=-1;
	}
	return iNum;
}
void display(struct queue *Queue)
{
	int iIndex,iTempIndex;
	printf("The elements in the queue are :");
	if(Queue->iRear==-1 && Queue->iFront==-1)
    {
        printf("Front=%d Rear=%d\nThe queue is empty.",Queue->iFront,Queue->iRear);
        return;
    }
	if(Queue->iRear >= Queue->iFront)
	{
		for(iIndex=Queue->iFront; iIndex<=Queue->iRear ; iIndex++)
			printf("%d ",Queue->iaQueue[iIndex]);
        printf("\nFront=%d Rear=%d",Queue->iFront,Queue->iRear);
		return;
	}
	for(iIndex=Queue->iFront ; iTempIndex!=Queue->iRear ; iIndex=iIndex+1)
	{
	    iTempIndex = iIndex % QUEUE_SIZE;
		printf("%d ",Queue->iaQueue[iTempIndex]);
	}
	printf("\nFront=%d Rear=%d",Queue->iFront,Queue->iRear);
}
void main()
{
	struct queue Queue; Queue.iFront=-1; Queue.iRear=-1;
	int iChoice,iNum;
	//menu driven program for user to perform the operation on queue
	while(1)
	{
		printf("\n\n1.Insert 2.Delete 3.Exit\nYour Choice:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the number to inserted:");
				scanf("%d",&iNum);
				enqueue(&Queue,iNum);
				display(&Queue);
				break;
			case 2:iNum=dequeue(&Queue);
				printf("\nThe number deleted is:%d",iNum);
					display(&Queue);
				break;

			case 3:
			display(&Queue);
			exit(0);
			break;
		}
	}
}
