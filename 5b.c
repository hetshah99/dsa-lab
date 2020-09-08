#include<stdio.h>
#include<stdlib.h>
struct polynomial
{
	int ispCoefficient, ispXPower, ispYPower, ispZPower;
	struct polynomial *pspNext;
};
void construct(struct polynomial **ppspPolynomial)
{
	struct polynomial *pspNew;
	int iChoice;
	while(1)
	{
		pspNew = (struct polynomial*) malloc(sizeof(struct polynomial));
		printf("Enter power of X:");
		scanf("%d",&pspNew->ispXPower);
		printf("Enter power of Y:");
		scanf("%d",&pspNew->ispYPower);
		printf("Enter power of Z:");
		scanf("%d",&pspNew->ispZPower);
		if(pspNew->ispXPower<0 || pspNew->ispYPower<0 || pspNew->ispZPower<0)
		{
			printf("The degree of the polynomial should be non-negative. Please enter valid values!\n");
			continue;
		}
		printf("Enter coefficient of the term:");
		scanf("%d",&pspNew->ispCoefficient);
		pspNew->pspNext = *ppspPolynomial;
		*ppspPolynomial = pspNew;
		label:
		printf("Want to continue? (Yes:1, No:2):");
		scanf("%d",&iChoice);
		if(iChoice == 2)
			break;
		else if(iChoice != 1)
		{
			printf("Enter proper choice.\n");
			goto label;
		}
	}
}
void check(struct polynomial **ppspPolynomial)
{
	struct polynomial *pspCurrent1 = *ppspPolynomial, *pspCurrent2;
	while(pspCurrent1 != NULL)
	{
		pspCurrent2 = pspCurrent1;
		while(pspCurrent2->pspNext != NULL)
		{
			if((pspCurrent2->pspNext)->ispXPower == pspCurrent1->ispXPower && (pspCurrent2->pspNext)->ispYPower == pspCurrent1->ispYPower && (pspCurrent2->pspNext)->ispZPower == pspCurrent1->ispZPower)
			{
				pspCurrent1->ispCoefficient += (pspCurrent2->pspNext)->ispCoefficient;
				pspCurrent2->pspNext = (pspCurrent2->pspNext)->pspNext;
			}
			pspCurrent2  = pspCurrent2->pspNext;
			if(pspCurrent2 == NULL)
				break;
		}
		pspCurrent1 = pspCurrent1->pspNext;
	}
}
void display(struct polynomial *pspPolynomial)
{
	struct polynomial *pspCurrent = pspPolynomial;
	if(pspPolynomial == NULL)
	{
		printf("Polynomial does not exist.");
		return;
	}
	int iFlag1=0;
	while(pspCurrent != NULL)
	{
		if(pspCurrent->ispCoefficient!=0)
		{
		 iFlag1=1;
		 printf("%d(x^%d)(y^%d)(z^%d)",pspCurrent->ispCoefficient,pspCurrent->ispXPower,pspCurrent->ispYPower,pspCurrent->ispZPower);

		}
		pspCurrent = pspCurrent->pspNext;
		if(pspCurrent != NULL)
		 printf(" + ");
	}
	if(iFlag1==0)
	printf("0");
}
void add(struct polynomial **ppspPolynomial1, struct polynomial *pspPolynomial2)
{
	struct polynomial *pspCurrent1=*ppspPolynomial1, *pspCurrent2=pspPolynomial2, *pspNew;
	int iFlag;
	while(pspCurrent2 != NULL)
	{
		iFlag = 0;
		pspCurrent1 = *ppspPolynomial1;
		while(pspCurrent1 != NULL)
		{
			if(pspCurrent1->ispXPower==pspCurrent2->ispXPower && pspCurrent1->ispYPower==pspCurrent2->ispYPower && pspCurrent1->ispZPower==pspCurrent2->ispZPower)
			{
				pspCurrent1->ispCoefficient += pspCurrent2->ispCoefficient;
				iFlag = 1;
				break;
			}
			pspCurrent1 = pspCurrent1->pspNext;
		}
		if(iFlag == 0)
		{
			pspNew = (struct polynomial*) malloc(sizeof(struct polynomial));
			pspNew->ispCoefficient = pspCurrent2->ispCoefficient;
			pspNew->ispXPower = pspCurrent2->ispXPower;
			pspNew->ispYPower = pspCurrent2->ispYPower;
			pspNew->ispZPower = pspCurrent2->ispZPower;
			pspNew->pspNext = *ppspPolynomial1;
			(*ppspPolynomial1) = pspNew;
		}
		pspCurrent2 = pspCurrent2->pspNext;
	}
}
void swap(struct polynomial *pspTerm1,struct polynomial *pspTerm2)
{
	int iTemp;

	iTemp = pspTerm1->ispCoefficient;
	pspTerm1->ispCoefficient = pspTerm2->ispCoefficient;
	pspTerm2->ispCoefficient = iTemp;

	iTemp = pspTerm1->ispXPower;
	pspTerm1->ispXPower = pspTerm2->ispXPower;
	pspTerm2->ispXPower = iTemp;

	iTemp = pspTerm1->ispYPower;
	pspTerm1->ispYPower = pspTerm2->ispYPower;
	pspTerm2->ispYPower = iTemp;

	iTemp = pspTerm1->ispZPower;
	pspTerm1->ispZPower = pspTerm2->ispZPower;
	pspTerm2->ispZPower = iTemp;
}
void sort(struct polynomial **ppspPolynomial)
{
	struct polynomial *pspCurrent1,*pspCurrent2;
	for(pspCurrent1=*ppspPolynomial ; pspCurrent1!=NULL ; pspCurrent1=pspCurrent1->pspNext)
	{
		for(pspCurrent2=pspCurrent1->pspNext ; pspCurrent2!=NULL ; pspCurrent2=pspCurrent2->pspNext)
		{
			if(pspCurrent2->ispXPower > pspCurrent1->ispXPower)
				swap(pspCurrent1,pspCurrent2);
			else if(pspCurrent2->ispXPower == pspCurrent1->ispXPower)
			{
				if(pspCurrent2->ispYPower > pspCurrent1->ispYPower)
					swap(pspCurrent1,pspCurrent2);
				else if(pspCurrent2->ispYPower == pspCurrent1->ispYPower)
				{
					if(pspCurrent2->ispZPower > pspCurrent1->ispZPower)
						swap(pspCurrent1,pspCurrent2);
				}
			}
		}
	}
}
void main()
{
	struct polynomial *pspPolynomial1=NULL, *pspPolynomial2=NULL;

	printf("For Polynomial 1:\n");
	construct(&pspPolynomial1);
	check(&pspPolynomial1);
	sort(&pspPolynomial1);

	printf("For Polynomial 2:\n");
	construct(&pspPolynomial2);
	check(&pspPolynomial2);
	sort(&pspPolynomial2);

	printf("\nPolynomial 1:");
	display(pspPolynomial1);

	printf("\nPolynomial 2:");
	display(pspPolynomial2);

	add(&pspPolynomial1,pspPolynomial2);
	sort(&pspPolynomial1);
	printf("\nAddition of both Polynomials:");
	display(pspPolynomial1);
}
