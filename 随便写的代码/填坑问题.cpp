#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
int a[100005];
int l[100005]; 
int r[100005];
int main()
{
    int T,n;
    scanf("%d",&T);
    int i,j,k,t;
    long long int total; // in case of spill
    for(t = 0;t<T;t++){
        total = 0;
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        scanf("%d", &n);
        for(i = 0;i < n;i++){
            scanf("%d", a + i);
        }
        // l[i] = max(a[0], a[1], ...a[i])
        l[0] = a[0];
        for(i = 1;i < n;i++)
            l[i] = max(l[i-1], a[i]);
        // r[i] = max(a[i], a[i+1],...a[n-1])
        r[n-1] = a[n-1];
        for(i = n - 2;i >= 0;i--)
            r[i] = max(r[i + 1], a[i]);
        for(i = 0;i < n;i++){
            total += min(l[i], r[i]) - a[i];
        }
        printf("%lld\n", total);
    }
}
