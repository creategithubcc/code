#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void*a,const void*b)
{
 return *(int*)a-*(int*)b; 
}
main()
{
 int n,flag=0,i,j,k;
 int d[5];
 char a[15][10], b[3][10]={"he","jin","min"},c[3][10]={"ma","ze","hang"};
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 scanf("%s",a[i]);
 }
 memset(d,0,sizeof(d));
 if(flag==0)
 {
 for(i=1;i<=n;i++)
 {
 if(strcmp(a[i],b[0])==0)
 {
 d[0]=i;
 for(j=1;j<=n;j++)
 {
 if(strcmp(a[j],b[1])==0)
 {
 d[1]=j;
 for(k=1;k<=n;k++)
 {
 if(strcmp(a[k],b[2])==0)
 {
 d[2]=k;
 qsort(d,3,sizeof(d[0]),comp);
 printf("3\n");
 printf("%d %d %d",d[0],d[1],d[2]);
 flag++;
 
 }
 }
 }
 }
  
 } 
 } 
    } 
    memset(d,0,sizeof(d));
    if(flag==0)
 {
 for(i=1;i<=n;i++)
 {
 if(strcmp(a[i],c[0])==0)
 {
 d[0]=i;
 for(j=1;j<=n;j++)
 {
 if(strcmp(a[j],c[1])==0)
 {
 d[1]=j;
 for(k=1;k<=n;k++)
 {
 if(strcmp(a[k],c[2])==0)
 {
 d[2]=k;
 qsort(d,3,sizeof(d[0]),comp);
 printf("3\n");
 printf("%d %d %d",d[0],d[1],d[2]);
 flag++;
 
 }
 }
 }
 }
  
 } 
 }
    }
 if(flag==0)
 printf("-1\n"); 
}
