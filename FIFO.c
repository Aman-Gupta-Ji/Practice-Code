#include<stdio.h>
typedef struct frame
{
    int page, time;
}frame;
int main(void) {
    int nf,n,i,np,j;
    scanf("%d",&n);
    int req[n];
    for(i=0;i<n;i++) {
        scanf("%d",&req[i]);
    }
    int pf=0;
    int temp, min, count=0;
    scanf("%d",&nf);
    frame f[nf];
    for(i=0;i<nf;i++) {
        f[i].page=-1;
    }
    for(i=0;i<n;i++) {
        temp=req[i];
        for(j=0;j<nf;j++) {
            if(f[j].page!=-1&&f[j].page==temp)
                break;
        }
        if(j<nf)
            continue;
        pf++;
        if(count<nf) {
            f[count].page=temp;
            f[count].time=i;
            count++;
            continue;
        }
        min=0;
        for(j=1;j<nf;j++) {
            if(f[min].time>f[j].time) {
                min=j;
            }
        }
        f[min].page=temp;
        f[min].time=i;
    }
    double miss=(double)pf/n, hit=1.0-miss;
    printf("\nNo. of page fault : %d\nHit ratio : %.3lf\nMiss ratio : %.3lf\n",pf,hit,miss);
}