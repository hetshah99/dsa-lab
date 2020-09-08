#include<stdio.h>
#include<stdlib.h>
void swap(int *iNum1, int *iNum2)
{
	int iTemp = *iNum1;
	*iNum1 = *iNum2;
	*iNum2 = iTemp;
}
void heapify(int *iaArray, int iIndex, int iSize)
{
	int iLargest = iIndex, iLeft = 2*iIndex + 1, iRight = 2*iIndex + 2;
	if(iLeft<iSize && iaArray[iLargest]<iaArray[iLeft])
		iLargest = iLeft;
	if(iRight<iSize && iaArray[iLargest]<iaArray[iRight])
		iLargest = iRight;
	if(iLargest != iIndex)
	{
		swap(iaArray+iIndex,iaArray+iLargest);
		heapify(iaArray,iLargest,iSize);
	}
}
void heapsort(int *iaArray, int iSize)
{
	int iIndex,iIndex2;
	for(iIndex=iSize/2-1;iIndex>=0;iIndex--)
		heapify(iaArray,iIndex,iSize);
	for(iIndex=iSize-1;iIndex>=0;iIndex--)
	{
		swap(iaArray,iaArray+iIndex);
		heapify(iaArray,0,iIndex);
		printf("\nThe number deleted out of tree:%d and the max-heap is:",iaArray[iIndex]);
		if(iIndex==0)
		{
			printf("NULL");
			continue;
		}
		for(iIndex2=0;iIndex2<iIndex;iIndex2++)
			printf("%d ",iaArray[iIndex2]);
	}
}
void main()
{
	int iSize, *iaArray, iIndex;
	printf("Enter the size:");
	scanf("%d",&iSize);
  if(iSize<0)
  {
    printf("array size not defined");
    return;
  }
	iaArray = (int *) malloc(sizeof(int) * iSize);
	printf("Enter the elements:");
	for(iIndex=0 ; iIndex<iSize ; iIndex++)
		scanf("%d",iaArray+iIndex);
	printf("Original Array:");
	for(iIndex=0 ; iIndex<iSize ; iIndex++)
		printf("%d ",iaArray[iIndex]);

		int iFlag=0;

		for(iIndex=1;iIndex<iSize;iIndex++)
		{
			if(iaArray[iIndex]<=iaArray[iIndex-1])
				iFlag=1;
		}

		if(iFlag==0)
			printf("Array is already sorted");
		else
		{
			heapsort(iaArray, iSize);

			printf("\nSorted Array:");
			for(iIndex=0 ; iIndex<iSize ; iIndex++)
				printf("%d ",iaArray[iIndex]);
		}

}
