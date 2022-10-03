#include<stdio.h>
int count=0;
void move(int,char,char);
void disk1(char,char);
void disk2(char,char,char);
void disk3(char,char,char);
void disk4(char,char,char);
void disk5(char,char,char);
void disk6(char,char,char);
void disk7(char,char,char);
void disk8(char,char,char);
void disk9(char,char,char);
void disk10(char,char,char);
int main(void)
{
	int n;
	printf("\n-----------------------------------------------------------\n");
	printf("\n\t\tWELCOME TO TOWER OF HANOI\n");
	printf("\n-----------------------------------------------------------\n");
	printf("\n\tA\t\tB\t\tC\n");
	printf("\nEnter The Number of Disks : ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			disk1('A','C');
			break;
		case 2:
			disk2('A','B','C');
			break;
		case 3:
			disk3('A','B','C');
			break;
		case 4:
			disk4('A','B','C');
			break;
		case 5:
			disk5('A','B','C');
			break;
		case 6:
			disk6('A','B','C');
			break;
		case 7:
			disk7('A','B','C');
			break;
		case 8:
			disk8('A','B','C');
			break;
		case 9:
			disk9('A','B','C');
			break;
		case 10:
			disk10('A','B','C');
			break;
		default :
			printf("\n\tINVALID INPUT\nThe Number of Disks between 1 to 10 ");
	}
	printf("\n\n-----------------------------------------------------------\n");
	printf("\n\t\tTOTAL NO. OF STEPS : %d\n",count);
	printf("\n-----------------------------------------------------------\n");
	printf("\n\t\t------   THANK YOU   -----\n");
	printf("\n\t\t\t\t\tBY :- AMAN GUPTA\n");
	printf("\n-----------------------------------------------------------\n");
	return 0;
}
void disk1(char S,char E)
{
	move(1,S,E);
	return;
}
void disk2(char S,char M,char E)
{
	disk1(S,M);
	move(2,S,E);
	disk1(M,E);
	return;	
}
void disk3(char S,char M,char E)
{
	disk2(S,E,M);
	move(3,S,E);
	disk2(M,S,E);
	return;
}
void disk4(char S,char M,char E)
{
	disk3(S,E,M);
	move(4,S,E);
	disk3(M,S,E);
	return;
}
void disk5(char S,char M,char E)
{
	disk4(S,E,M);
	move(5,S,E);
	disk4(M,S,E);
	return;
}
void disk6(char S,char M,char E)
{
	disk5(S,E,M);
	move(6,S,E);
	disk5(M,S,E);
	return;
}
void disk7(char S,char M,char E)
{
	disk6(S,E,M);
	move(7,S,E);
	disk6(M,S,E);
	return;
}
void disk8(char S,char M,char E)
{
	disk7(S,E,M);
	move(8,S,E);
	disk7(M,S,E);
	return;
}
void disk9(char S,char M,char E)
{
	disk8(S,E,M);
	move(9,S,E);
	disk8(M,S,E);
	return;
}
void disk10(char S,char M,char E)
{
	disk9(S,E,M);
	move(10,S,E);
	disk9(M,S,E);
	return;
}
void move(int N,char S,char E)
{
	printf("\nmove  %d  from  %c  to  %c",N,S,E);
	count++;
	return;
}

