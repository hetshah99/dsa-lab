#include<stdio.h>
#include<string.h>
#define STACK_SIZE 100
int iFlag=0;
int iFlag1=0;

struct stack
{
    char caStack[STACK_SIZE];
    int iTop;
};

int getIn(char cInput)
{
    int iAns;
    if( (cInput>=65 && cInput<=90) || (cInput>=97 && cInput<=122) )
        iAns=11;
    else
    {
        switch(cInput)
        {
            case '+': case '-':iAns=1; break;
            case '*': case '/':iAns=3; break;
            case '^': iAns=6; break;
            case ':': case '$':iAns=7; break;
            case '@': case '#':iAns=9; break;
            case '(': iAns=13; break;
            case ')': iAns=0; break;
            default : iFlag=1;
        }
    }
    return iAns;
}

int getOut(char cOutput)
{
    int iAns;
    if( (cOutput>=65 && cOutput<=90) || (cOutput>=97 && cOutput<=122) )
        iAns=12;
    else
    {
        switch(cOutput)
        {
            case '+': case '-':iAns=2; break;
            case '*': case '/':iAns=4; break;
            case '^': iAns=5; break;
            case ':': case '$':iAns=8; break;
            case '@': case '#':iAns=10; break;
            case '(': iAns=0; break;
            case ')': iAns=-1; break;
            default : iFlag=1;
        }
    }
    return iAns;
}

void push(struct stack *charStack, char cInput)
{
  if(iFlag==0)
  {
    if(charStack->iTop>=STACK_SIZE)
      {
        printf(" overflow");
        iFlag=1;
         return;
      }

    charStack->caStack[++charStack->iTop]=cInput;

  }
}

char pop(struct stack *charStack)
{
  if(iFlag==0)
  {
    if(charStack->iTop<=-1)
      {
        printf("underflow");
        iFlag==1;
        return;
      }
    char cAns=charStack->caStack[charStack->iTop];
    charStack->iTop--;
    return cAns;
  }
  else
    return;
}

void main()
{
    struct stack charStack; charStack.iTop=0; charStack.caStack[charStack.iTop]='(';
    char caInfix[1000], caTemp[1000], caPostfix[1000]="", caCat[]=")",temp;
    int iIndex=0, iCount=0;
    printf("Enter an infix expression:");
    scanf("%s",caInfix);

    for(iIndex=0 ; iIndex<strlen(caInfix) ; iIndex++)
    {

        	caTemp[iCount++] = caInfix[iIndex];
	  }

    strcat(caTemp,caCat);
    for(iIndex=0;iIndex<strlen(caTemp);iIndex++)
    {
        while((getIn(caTemp[iIndex]) < getOut(charStack.caStack[charStack.iTop])) && iFlag1==0)
        {

            caCat[0]=pop(&charStack);
            if(iFlag1==1)
            {
              printf("invalid operation");
              return;
            }
            caCat[1]='\0';
            printf("%c ",temp);
            strcat(caPostfix,caCat);

        }
        if(iFlag1==1)
        {
          printf("invalid operation");
          return;
        }
          if(getIn(caTemp[iIndex]) != getOut(charStack.caStack[charStack.iTop]))
              push(&charStack,caTemp[iIndex]);
          else if(getIn(caTemp[iIndex]) == getOut(charStack.caStack[charStack.iTop]))
          {
            charStack.iTop--;
            continue;
          }
          
    }


    if(iFlag==0 && iFlag1==0)
    {
      printf("\nPostfix expression:");
      for(iIndex=0 ; iIndex<strlen(caPostfix) ; iIndex++)
    	 printf("%c ",caPostfix[iIndex]);
	  }
    else
    {
      printf("   invalid operation");
    }

}
