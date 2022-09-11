#include<stdio.h>
int count=0;
void move(int,char,char);
void disk(int,char,char,char);
int main(void)
{
	int n;
	printf("\n-----------------------------------------------------------\n");
	printf("\n\t\tWELCOME TO TOWER OF HANOI\n");
	printf("\n-----------------------------------------------------------\n");
	printf("\n\tS\t\tA\t\tD\n");
	printf("\nEnter The Number of Disks : ");
	scanf("%d",&n);
	if(n>0)
		disk(n,'S','A','D');
	else
	{
		printf("\n\tINVALID INPUT\nThe Number of Disks ");
		return 1;
	}
	printf("\n\n-----------------------------------------------------------\n");
	printf("\n\t\tTOTAL NO. OF STEPS : %d\n",count);	// 2^n - 1
	printf("\n-----------------------------------------------------------\n");
	printf("\n\t\t------   THANK YOU   -----\n");
	printf("\n\t\t\t\t\tBY :- AMAN GUPTA\n");
	printf("\n-----------------------------------------------------------\n");
	return 0;
}
void disk(int n,char S,char M,char E)	// T.C. = O(2^n)	S.C. = O(n)
{
	if(n==1)
	{
		move(1,S,E);
		return;
	}
	disk(n-1,S,E,M);
	move(n,S,E);
	disk(n-1,M,S,E);
	return;
}
void move(int N,char S,char E)
{
	printf("\nmove  %d  from  %c  to  %c",N,S,E);
	count++;
	return;
}