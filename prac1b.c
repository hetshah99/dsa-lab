#include <stdio.h>
#define SIZE 2

int main() {

  // declaring student structure
  struct student {
    int iId;
    float fPercentage;
  };

  // student structure variable
  struct student saStudent[SIZE];

  // student structure pointer variable
  struct student *spPointer = NULL;

  // counter variable declaration
  int iCounter=0;

  //declaring the iterator
  int iIterator=0;

  // assign pointer  to structure array
  spPointer = saStudent;
  //making a menu drive program
  printf("enter 1 to insert \nenter 2 to update \nenter 3 to delete \nenter 4 to exit\n");

  //taking choice from user
  int iSelection;
  scanf("%d",&iSelection);

  //doing all the operations until the user says so
  while(iSelection!=4)
  {
    if(iSelection==1)
      {
          if(iCounter<SIZE)
        {
          printf("Enter ID: ");
          scanf("%d", &spPointer->iId);

          printf("Enter Percentage: ");
          scanf("%f",&spPointer->fPercentage);

          // update pointer to point at next element of the array std
          spPointer++;
          iCounter++;

          printf("enter the next operation \t" );
          scanf("%d",&iSelection );
        }
        else
        {
          printf("not valid \n");
          printf("enter the next operation \t" );
          scanf("%d",&iSelection );
        }
      }
      else if(iSelection==2)
      {
          //taking new values from the user for the current Structure element
          printf("updating the current element");
          printf("Enter ID: ");
          scanf("%d", &spPointer->iId);

          printf("Enter Percentage: ");
          scanf("%f",&spPointer->fPercentage);

          //asking for the next operation from user
          printf("enter the next operation \t\n" );
          scanf("%d",&iSelection );

      }
      else
      {
          //decresing the pointer and counter value so that it will point to previous element
          if(iCounter!=0)
          {
            printf("deleting the current element");
            spPointer--;
            iCounter--;

            printf("enter the next operation \t" );
            scanf("%d",&iSelection );
        }
        else
        {
          printf("cannot delete select another operation\n");

          printf("enter the next operation \t" );
          scanf("%d",&iSelection );
        }
      }
  }

  // reset pointer back to the starting
  spPointer = saStudent;

  //displating all the elements of the structure
  if(iCounter!=0)
  {
    for (iIterator = 0; iIterator < iCounter; iIterator++)
        {
          printf("Student No %d\n ",iIterator+1);
          printf("ID: %d\n", spPointer->iId);
          printf("Points: %f\n",spPointer->fPercentage);

          // update pointer to point at next element
          spPointer++;
        }
      }
  else
    {
        printf("database empty");
      }
  return 0;
}
