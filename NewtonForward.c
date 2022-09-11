#include<stdio.h>
void NewtonForward()
{
	int n, i, j;
	scanf("%d",&n);
	float x[n], y[n][n], f;
	for(i=0;i<n;i++)
		scanf("%f",&x[i]);
	for(i=0;i<n;i++)
		scanf("%f",&y[i][0]);
	double u, u1 , h, a;
	scanf("%f",&f);
	h=x[1]-x[0];
	u=(f-x[0])/h;
	u1=u;
	a=y[0][0];
	long fact=1;
	for(j=1;j<n;j++)
	{
		for(i=0;i<=(n-j);i++)
			y[i][j]=y[i+1][j-1]-y[i][j-1];
	}
	for(j=1;j<n;j++)
	{
		a=a+(u1*y[0][j])/fact;
		u1*=(u-j);
		fact*=j+1;
	}
	printf("%lf \n",a);
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        NewtonForward();
    }
    return 0;
}