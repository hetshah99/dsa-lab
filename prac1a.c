#include <stdio.h>
#define COLSIZE 2
#define ROWSIZE 2

int main()
{
      //declaring the array
    int iaElements[COLSIZE][ROWSIZE];
    //decalribng the pointer and the counter
    int *ipElement = NULL,iCount=0;

    //pointing the pointer to first element of the array
    ipElement=&iaElements[0][0];

    //declaring the iterator
    int iIterator=0;

    //making a menu drive program
    printf("enter 1 to insert \nenter 2 to update \n3 to delete \n4 to exit\n");

      //taking choice from user
    int iSelection;
    scanf("%d",&iSelection);

      //doing all the operations until the user says so
    while(iSelection!=4)
    {
          if(iSelection==1)
          {


                //scanning the element to the inseted and also incrementing the value of the pointer and counter
              if(iCount!=(COLSIZE+ROWSIZE))
              {
                printf("enter the element to be inserted\t\n" );
                ipElement++;
              scanf("%d",ipElement );
              iCount++;}
              else
              {
                printf("operation not valid please enter a valid operation \n" );

              }
              printf("enter the next operation \t" );
              scanf("%d",&iSelection );
          }
          else if(iSelection==2)
          {
              printf("enter the new value for the element\n");

                //scanning the new value and then assigning its pointer to its current position
              scanf("%d",ipElement );
              printf("enter the next operation \n" );
              scanf("%d",&iSelection );
          }
          else
          {
                  //checking if the pointer doesnt point to the first element
                if(iCount!=0)
                  {
                        // decrement both the value of pointer and counter so it will point to the element before it
                        iCount--;
                        ipElement--;

                        printf("enter the next operation \t" );
                        scanf("%d",&iSelection );
                  }
                  else
                  {
                    printf("operation not valid please enter a valid operation" );
                    printf("enter the next operation \t" );
                    scanf("%d",&iSelection );
                  }
          }
    }

      //reassigning the pointer the the first element of the array
    ipElement = &iaElements[0][0];

      // outputing all the changes
    for(int iIterator=0;iIterator<iCount;iIterator++)
    {
      printf("%d ",*ipElement);
      ipElement++;
    }
}
