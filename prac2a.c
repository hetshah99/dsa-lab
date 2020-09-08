#include<stdio.h>
#define STACK_SIZE 10
struct stack
{
	int iStack[STACK_SIZE];
	int top;
};
void push(struct stack*,int);
void pop(struct stack*);
void change(struct stack*,int,int);
int peep(struct stack*,int);
void main()
{
	int iNum,iChoice,iPeepIndex,iChangeIndex,iter,iAmount;
	char cCh;
	struct stack Stack;
	Stack.top=-1;
	if(STACK_SIZE<=0)
	{
		printf("stack size not valid");
		return;
	}
	do
	{
		printf("1.Push\t2.Pop\t3.Peep\t4.Change\nYour choice (5 to discontinue):");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:

				        printf("Enter the number to be pushed:\t");
								
			          scanf("%d",&iNum );
					      push(&Stack,iNum);
				      break;
			case 2:
                pop(&Stack);
			          break;
			case 3:
                printf("Enter the index of the stack to be peeped at:");
				        scanf("%d",&iPeepIndex);
				        iNum=peep(&Stack,iPeepIndex);
	              break;
			case 4:
          printf("Enter the index of the stack at which the number is to be changed:");
				  scanf("%d",&iChangeIndex);
				  printf("Enter the number to be changed with:");
				  scanf("%d",&iNum);
				  change(&Stack,iChangeIndex,iNum);
				      break;

		}

	}while(iChoice!=5);
	printf("the stack is \n");

  for(int i=0;i<=Stack.top;i++)
  {
    printf("%d ",Stack.iStack[i]);
  }
}
void push(struct stack *Stack,int num)
{
	if(Stack->top<STACK_SIZE-1)
	{
		Stack->top++;
		Stack->iStack[Stack->top]=num;
	}
	else
	{
		printf("Stack Overflow.\n");
	}
}
void pop(struct stack *Stack)
{
	if(Stack->top<0)
	{
		printf("Stack Underflow.\n");
	}
	else
	{
		Stack->top--;
 	printf("popped element : %d\n",Stack->iStack[(Stack->top)+1]);
	}
}
void change(struct stack *Stack,int index,int num)
{
	if((Stack->top-index)<0)
	{
		printf("not valid\n");
	}
	else
	{
		Stack->iStack[Stack->top-index]=num;
	}
}
int peep(struct stack *Stack,int index)
{
	if((Stack->top-index)<0 || index<0)
	{
		printf("not valid\n ");
		return 0;
	}
	else
	{
		printf( "The value at index %d with respect to the top of stack is %d.\n",index,Stack->iStack[Stack->top-index] );
	}
}
