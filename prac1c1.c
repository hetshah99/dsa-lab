#include<stdio.h>
void main()
{
    int iArr1[2][2],iArr2[2][2],iArr3[2][2];
    int iiter1,iiter2,iiter3,ichoice;
    printf("do you want to enter the matrix \n1. row wise \n2.column wise \nenter choice");
    scanf("%d",&ichoice);
    switch(ichoice)
    {
        case 1 :  printf("Enter values of matrix 1: \n");
                    for (iiter1=0;iiter1<2;iiter1++)
                        for(iiter2=0;iiter2<2;iiter2++)
                            scanf("%d", &iArr1[iiter1][iiter2]);
                            break;
        case 2 :  printf("Enter values of matrix 1: \n");
                        for (iiter2=0;iiter2<2;iiter2++)
                            for(iiter1=0;iiter1<2;iiter1++)
                                scanf("%d", &iArr1[iiter1][iiter2]);
    }
    printf("do you want to enter the matrix \n1. row wise \n2.column wise \nenter choice");
    scanf("%d",&ichoice);
    switch(ichoice)
    {
        case 1 :  printf("Enter values of matrix 2: \n");
                    for (iiter1=0;iiter1<2;iiter1++)
                        for(iiter2=0;iiter2<2;iiter2++)
                            scanf("%d", &iArr2[iiter1][iiter2]);
                        break;
        case 2 :  printf("Enter values of matrix 2: \n");
                        for (iiter2=0;iiter2<2;iiter2++)
                            for(iiter1=0;iiter1<2;iiter1++)
                                scanf("%d", &iArr2[iiter1][iiter2]);
    }
        printf("value of matrix 1: \n");
        for(iiter1=0;iiter1<2;iiter1++)
        {
            for(iiter2=0;iiter2<2;iiter2++)
                printf("%d ", iArr1[iiter1][iiter2]);
            printf("\n");
        }

    printf("value of matrix 2: \n");
    for(iiter1=0;iiter1<2;iiter1++)
        {
            for(iiter2=0;iiter2<2;iiter2++)
                printf("%d ", iArr2[iiter1][iiter2]);
            printf("\n");
        }
    for(iiter1=0; iiter1<2; ++iiter1)
        for(iiter2=0; iiter2<2; ++iiter2)
            for(iiter3=0; iiter3<2; ++iiter3)
            {
                iArr3[iiter1][iiter2]+=iArr1[iiter1][iiter3]*iArr2[iiter3][iiter2];
            }
    printf("value of matrix multiplication: \n");
    for(iiter1=0;iiter1<2;iiter1++)
        {
            for(iiter2=0;iiter2<2;iiter2++)
                printf("%d ", iArr3[iiter1][iiter2]);
            printf("\n");
        }
}
