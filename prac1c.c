#include<stdio.h>
int  main()
{
      //declaring all the matrix
    int iaMatrix1[3][3],iaMatrix2[3][3],iaMatrix3[3][3],iaMatrixTemp1[3][3],iaMatrixTemp2[3][3];

      //declaring all the iterators
    int iIterator1,iIterator2,iIterator3,iSelection;

      //taking the input from user in the form the user wants
    printf("enter two matrices either in row form or column form \n");

      //inputting matrix one
    printf("enter 1 to enter first matrix in row form or enter 2 to enter first matrix in columnn form\n");
    scanf("%d",&iSelection);

    if(iSelection==1)

      {
        printf("Enter values of matrix 1: \n");

                    for (iIterator1=0;iIterator1<3;iIterator1++)
                        for(iIterator2=0;iIterator2<3;iIterator2++)
                            scanf("%d", &iaMatrix1[iIterator1][iIterator2]);

                    //taking transpose
                  for (iIterator1=0;iIterator1<3;iIterator1++)
                      for(iIterator2=0;iIterator2<3;iIterator2++)
                        iaMatrixTemp1[iIterator2][iIterator1] = iaMatrix1[iIterator1][iIterator2];

      }
      else
      {
          printf("Enter values of matrix 1: \n");

              for (iIterator2=0;iIterator2<3;iIterator2++)
                for(iIterator1=0;iIterator1<3;iIterator1++)
                    scanf("%d", &iaMatrixTemp1[iIterator1][iIterator2]);

      }

        // inputting the secoond matrix from user
      printf("enter 1 to enter second matrix in row form or enter 2 to enter second matrix in columnn form\n");
      scanf("%d",&iSelection);

      if(iSelection==1)

        {
          printf("Enter values of matrix 1: \n");

                      for (iIterator1=0;iIterator1<3;iIterator1++)
                          for(iIterator2=0;iIterator2<3;iIterator2++)
                              scanf("%d", &iaMatrixTemp2[iIterator1][iIterator2]);

        }
        else
        {
            printf("Enter values of matrix 1: \n");

                for (iIterator2=0;iIterator2<3;iIterator2++)
                  for(iIterator1=0;iIterator1<3;iIterator1++)
                      scanf("%d", &iaMatrix2[iIterator1][iIterator2]);

                      //taking transpose
              for (iIterator1=0;iIterator1<3;iIterator1++)
                for(iIterator2=0;iIterator2<3;iIterator2++)
                    iaMatrixTemp2[iIterator2][iIterator1] = iaMatrix2[iIterator1][iIterator2];


        }



          //performing matrix multiplication and storing it in matrix 3
        for(iIterator1=0;iIterator1<3;iIterator1++)
    	{
    		  for(iIterator2=0;iIterator2<3;iIterator2++)
    		    {
    			        iaMatrix3[iIterator1][iIterator2]=0;
    			           for(iIterator3=0;iIterator3<3;iIterator3++)
    			              {
    				                  iaMatrix3[iIterator1][iIterator2] +=  iaMatrixTemp1[iIterator1][iIterator3]* iaMatrixTemp2[iIterator3][iIterator2];
    			              }

    		     }

    	}

      // displaying the result of multiplication matrix 1 and matrix 2
    printf("value of matrix multiplication: \n");
    for(iIterator1=0;iIterator1<3;iIterator1++)
        {
            for(iIterator2=0;iIterator2<3;iIterator2++)
              {
                  printf("%d ", iaMatrix3[iIterator1][iIterator2]);
              }
              printf("\n");
        }

return 0;
}
