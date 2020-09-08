#include<stdio.h>
#include<stdlib.h>
struct list
{
    int iInfo;
    struct list *Link;
};

void insert(int iNum, struct list **Last)
{
    struct list *New = malloc(sizeof(struct list));
    struct list *Cur = *Last, *Save = NULL;

    int iChoice, iPosition, iCount;
    New->iInfo = iNum;
    if( (*Last) == NULL )
    {
        printf("The list was empty, so the element is added at the start.");
        *Last = New;
        (*Last)->Link = (*Last);
        return;
    }
    printf("1.At the beginning\n2.At the end\n3.After element no.\n4.Before element no.\nYour choice:");
    scanf("%d",&iChoice);
    switch(iChoice)
    {
        case 1: New->Link = (*Last)->Link;
                (*Last)->Link = New;
                break;
        case 2: New->Link = (*Last)->Link;
                (*Last)->Link = New;
                *Last = (*Last)->Link;
                break;
        case 3: printf("Enter the position of the number after which insertion will occur:");
                scanf("%d",&iPosition);
                iCount = 1;
                while(iCount <= iPosition)
                {
                    iCount++;
                    Cur = Cur->Link;
                }
                New->Link = Cur->Link;
                Cur->Link = New;
                if(Cur == *Last)
                    *Last = (*Last)->Link;
                break;
        case 4: printf("Enter the position of the number before which insertion will occur:");
                scanf("%d",&iPosition);
                iCount = 1;
                while(iCount < iPosition)
                {
                    iCount++;
                    Cur = Cur->Link;
                }
                New->Link = Cur->Link;
                Cur->Link = New;
                if(Cur == *Last)
                    *Last = (*Last)->Link;
                break;
    }

}
int rem(struct list **Last)
{
    int iNum, iChoice, iPosition, iCount;
    struct list *Cur = *Last;
    if(*Last == NULL)
    {
        printf("The list is empty. No elements can be removed.");
        return 0;
    }
    if(*Last == (*Last)->Link)
    {
    	iNum = (*Last)->iInfo;
    	*Last = NULL;
    	printf("The list had only one element. ");
    	return iNum;
	}
    printf("1.At the beginning 2.At the end 3.After element no. 4.Before element no.\nYour choice:");
    scanf("%d",&iChoice);
    switch(iChoice)
    {
        case 1: iNum = (*Last)->Link->iInfo;
        		(*Last)->Link = (*Last)->Link->Link;
                break;
        case 2: iNum = (*Last)->iInfo;
            	while(Cur->Link != *Last)
                    Cur = Cur->Link;
                Cur->Link = (*Last)->Link;
                *Last = Cur;
                break;
        case 3: printf("Enter the position of the number after which deletion will occur:");
                scanf("%d",&iPosition);
                iCount = 1;
                while(iCount <= iPosition)
                {
                    iCount++;
                    Cur = Cur->Link;
                }
				iNum = Cur->Link->iInfo;
				if(Cur->Link == *Last)
					*Last = Cur;
				Cur->Link = Cur->Link->Link;
                break;
        case 4: printf("Enter the position of the number before which insertion will occur:");
                scanf("%d",&iPosition);
                iCount = 1;
                while(iCount < iPosition-1)
                {
                    iCount++;
                    Cur = Cur->Link;
                }
                iNum = Cur->Link->iInfo;
                if(Cur->Link == *Last)
                    *Last = Cur;
                Cur->Link = Cur->Link->Link;
                break;
    }
    return iNum;
}
void traverse(struct list *Last)
{

    if(Last == NULL)
    {
        printf("No element present.");
          exit(0);
    }
    struct list *Cur = Last->Link;
    printf("The numbers are:");
   while(Cur != Last)
    {
      printf("%d ",Cur->iInfo);
    Cur = Cur->Link;
  }
  printf("%d ",Cur->iInfo);
}
void main()
{
    int iChoice, iNum;
    struct list *Last = NULL;
    while(1)
    {
        printf("\n1.Add 2.Delete 3.Traverse 4.Exit\nYour choice:");
        scanf("%d",&iChoice);
        switch(iChoice)
        {
            case 1: printf("Enter the number to be inserted:");
                    scanf("%d",&iNum);
                    insert(iNum,&Last);
                    break;
            case 2: iNum = rem(&Last);
                    if(iNum == NULL)
                        continue;
                    printf("The removed element is:%d",iNum);
                    break;
            case 3: traverse(Last);
                    break;
            case 4: exit(0);
        }
    }
}
