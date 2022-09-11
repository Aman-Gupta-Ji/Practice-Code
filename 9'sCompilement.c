#include<stdio.h>
#include<math.h>
int main(void) {
    long n;
    scanf("%ld",&n);
    long sum=0;
    int r;
    long pow=1;
    while(n!=0) {
        r=n%10;
        n/=10;
        sum+=(9-r)*pow;
        pow*=10;
    }
    printf("%ld",sum);
}