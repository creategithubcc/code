#include<stdio.h>
#include<stdlib.h>
struct sjk
{ int x,y;
  int value;
};
 
struct sjk2
{ 
   struct sjk mat[100];
   int m,n,number;
};
struct sjk3
{ 
   struct sjk mat[100];
   int m,n,number;
};
int main()
{  struct sjk2 *t;
   struct sjk3 *p;
   int i,j,k,number[100],copt[100],cpot[100];
    t=(struct sjk2*)malloc(sizeof(struct sjk2));  
   scanf("%d %d %d",&t->m,&t->n,&t->number);
        
        for (i=1;i<=t->number;i++)
        {
                scanf("%d %d %d",&t->mat[i].x,&t->mat[i].y,&t->mat[i].value);
        }
   p=(struct sjk3*)malloc(sizeof(struct sjk3));  
     
   p->m=t->n;
   p->n=t->m;
   p->number=t->number;
for(i=1;i<=t->n;i++)
    number[i]=0;
for(i=1;i<=t->number;i++)
  number[t->mat[i].y]++;
cpot[1]=copt[1]=1;
 
for(i=2;i<=t->number;i++)
   cpot[i]=copt[i]=copt[i-1]+number[i-1];
for(i=1;i<=t->number;i++)
   {       j=copt[t->mat[i].y];
                p->mat[j].x=t->mat[i].y;
                p->mat[j].y=t->mat[i].x;
                p->mat[j].value=t->mat[i].value;
                copt[t->mat[i].y]++;
}
printf("num:");
for(i=1;i<=p->m;i++)
{  if(i!=p->m)
       printf("%d,",number[i]);
    else
       printf("%d,\n",number[i]);
}
printf("cpot:");
printf("1,");
  for(i=1;i<p->m;i++)
  { 
   if(i!=p->m-1)
       printf("%d,",copt[i]);
    else
       printf("%d,\n",copt[i]);
}
     for (i=1;i<=p->number;i++)
        {
                printf("%d,%d,%d\n",p->mat[i].x,p->mat[i].y,p->mat[i].value);
        }
}
