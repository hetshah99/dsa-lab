#include<stdio.h>
#define QUEUE_SIZE 3
#define NO_OF_PRIORITY 1000
struct Priority_Q
{
  int iQueue[(NO_OF_PRIORITY*2)+1][QUEUE_SIZE];
  int iaFront[(NO_OF_PRIORITY*2)+1];
  int iaRear[(NO_OF_PRIORITY*2)+1];
};


void insert (struct Priority_Q *queue,int iElement,int iPriority)
  {
    if(iPriority==0)
    {
      iPriority = NO_OF_PRIORITY;
    }
    else if(iPriority>0)
    {
      iPriority = NO_OF_PRIORITY+iPriority;
    }
    else
    {
      iPriority = NO_OF_PRIORITY +iPriority;
    }
    if(queue->iaRear[iPriority]==(QUEUE_SIZE-1))
      {
        printf("overflow");
        exit(0);

      }
      else
      {
          queue->iaRear[iPriority]++;
          queue->iQueue[iPriority][queue->iaRear[iPriority]] = iElement;
      }
  }

  void delete(struct Priority_Q *queue )
      {
          int iIterator2=0;
          int iFlag=1;
          while(iIterator2<(NO_OF_PRIORITY*2)+1)
            {
              if(queue->iaRear[iIterator2]!=queue->iaFront[iIterator2]-1)
                {
                  printf("the deleted element is %d ",queue->iQueue[iIterator2][queue->iaFront[iIterator2]]);
                  queue->iaFront[iIterator2]++;
                  iFlag=0;
                  break;
                }
                iIterator2++;
            }
          if(iFlag==1)
            {
              printf("all queues are empty \n");

          }
      }

    void display(struct Priority_Q *queue)
    {
        int iIterator1=0,iIterator2=0;

        for(iIterator1=0;iIterator1<((NO_OF_PRIORITY*2)+1);iIterator1++)
        {
            if(queue->iaRear[iIterator1]==queue->iaFront[iIterator1]-1)
            {

            }
            else
            {
              for(iIterator2=queue->iaFront[iIterator1];iIterator2<=queue->iaRear[iIterator1];iIterator2++)
              printf("%d ",  queue->iQueue[iIterator1][iIterator2]);

              printf("\n");
            }
        }
    }
int  main()
{
  struct Priority_Q queue;
  int iIterator1 = 0;

    for(iIterator1=0;iIterator1<((NO_OF_PRIORITY*2)+1);iIterator1++)
      {
        queue.iaFront[iIterator1]=0;
        queue.iaRear[iIterator1]=-1;
      }
      int iPriority;
      int iElement;
      int iSelect = 0;
      do
      {
          printf("enter 1 for insert ,2 for delete,3 to exit  ");
          scanf("%d",&iSelect);

          switch (iSelect) {
            case 1:
              printf("enter the element and its priority (priority should be a whole number)",NO_OF_PRIORITY);
              scanf("%d%d",&iElement,&iPriority);
                  insert(&queue,iElement,iPriority);
                  display(&queue);
                  break;

              case 2:
                  delete(&queue);
                  display(&queue);
                  break;

          }

      }while(iSelect!=3);
}
