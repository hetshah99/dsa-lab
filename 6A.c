#include<stdio.h>
#include<stdlib.h>
void swap(int *iNum1, int *iNum2)
{
    int iTemp = *iNum1;
    *iNum1 = *iNum2;
    *iNum2 = iTemp;
}

void quicksort(int *iaArray, int iSize)
{
    int iIndex, iLast=0;
    if(iSize <= 1)
        return;

    for(iIndex=1 ; iIndex<iSize ; iIndex++)
    {
        if(iaArray[iIndex] <= iaArray[0] )
            swap(iaArray+(++iLast),iaArray+iIndex);

    }
    swap(iaArray,iaArray+iLast);
    printf("\n\nPartion1:");
    if(iLast == 0)
    	printf("- ");
    for(iIndex=0;iIndex<iLast;iIndex++)
    {
    	printf("%d ",iaArray[iIndex]);
	}
	printf("Pivot:%d Partion2:",iaArray[iLast]);
	for(iIndex=iLast+1;iIndex<iSize;iIndex++)
    {
    	printf("%d ",iaArray[iIndex]);
	}
    quicksort(iaArray,iLast);
    quicksort(iaArray+iLast+1,iSize-iLast-1);
}
void main()
{
    int iSize, iIndex, *iaArray,iChoice;
    printf("Enter the size of the array:");
    scanf("%d",&iSize);
    iaArray = (int *) malloc(sizeof(int)*iSize);

	printf("Enter the elements of the array:");
    for(iIndex=0 ; iIndex<iSize; iIndex++)
        scanf("%d",iaArray+iIndex);

	printf("\nThe original array is :");
    for(iIndex=0 ; iIndex<iSize; iIndex++)
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

            quicksort(iaArray, iSize);

        	printf("\n\nThe sorted array is: ");
            for(iIndex=0 ; iIndex<iSize; iIndex++)
                printf("%d ",iaArray[iIndex]);
      }

}
