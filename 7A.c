#include<stdio.h>
#include<stdlib.h>
void swap(int *iaArray,int iIndex,int iIndex2)
{
	int iTemp = iaArray[iIndex2];
	iaArray[iIndex2] = iaArray[iIndex];
	iaArray[iIndex] = iTemp;
}
void sort(int *iaArray,int iSize)
{
	int iLast=0,iIndex;
	if(iSize <= 1)
		return;
	for(iIndex=1;iIndex<iSize;iIndex++)
	{
		if(iaArray[iIndex] <= iaArray[0])
			swap(iaArray,iIndex,++iLast);
	}
	swap(iaArray,0,iLast);
	sort(iaArray,iLast);
	sort(iaArray+iLast+1,iSize-iLast-1);
}
int binarysearch(int *iaArray,int iStartIndex,int iSize, int iElement,int *iCount)
{
	int iMiddle, iResult;
	if(iSize <= 1)
	{
		if(iaArray[0] == iElement)
			return iStartIndex;
		return -1;
	}
	(*iCount)++;
	iMiddle = (iSize+1)/2 - 1;
	if(iElement == iaArray[iMiddle])
		iResult = iMiddle;
	else if(iElement < iaArray[iMiddle])
		iResult = binarysearch(iaArray,iStartIndex,iMiddle,iElement,iCount);
	else if(iElement > iaArray[iMiddle])
		iResult = binarysearch(iaArray+iMiddle+1,iStartIndex+iMiddle+1,iSize-iMiddle-1,iElement,iCount);
	return iResult;
}
void main()
{
	int iSize,iElement,*iaArray,iIndex,iResult,iCount=0;
	printf("Enter the size of the array:");
	scanf("%d",&iSize);
	iaArray = (int *) malloc(sizeof(int)*iSize);
	printf("Enter the elements:");
	for(iIndex=0;iIndex<iSize;iIndex++)
		scanf("%d",iaArray+iIndex);
	sort(iaArray,iSize);
	printf("Enter the element to be searched:");
	scanf("%d",&iElement);
	iResult = binarysearch(iaArray,0,iSize,iElement,&iCount);
	if(iResult == -1)
		printf("%d is not present in the array.",iElement);
	else
		printf("The index of the element %d in the array is %d with no of iterations:%d",iElement,iResult,iCount);
}
