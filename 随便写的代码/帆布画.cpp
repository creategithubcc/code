#include<stdio.h>
#include<stdlib.h>  
#include<string.h> 
long long aa[100086],bb[100086];  
int cmp(const void*a,const void*b)  
{  
	return*(long long*)a>*(long long*)b;  
}   
int fun(const void*c,const void*d)
{
    return*(int*)c-*(int*)d;
}
int main() 
{  
long long int i,j,k,n,m,p=0,q=0,sum=0,ans=0,ans2=0,ans3=0,x=0;  
scanf("%lld",&n); 
for(i=0;i<n;i++)
{
scanf("%lld",&m);
sum=0;  
for(j=0;j<m;j++)
{
scanf("%lld",&aa[j]);
x+=1;
}
qsort(aa,m,sizeof(long long),cmp);
if(m==1)
{  
printf("0\n");aa[0]=0;
goto loop;
}  
else if(m!=1)
{  
ans=ans2=ans3=0; 
for(j=0;j<m-1;j++)
{
if(ans2==ans3||(aa[ans]<bb[ans2]&&ans!=m))
{  
sum+=aa[ans];  
bb[ans3]+=aa[ans];  
ans+=1;  
} 
else 
{  
bb[ans3]+=bb[ans2];  
sum+=bb[ans2];  
ans2+=1;  
}  
if(ans2==ans3||(aa[ans]<bb[ans2]&&ans!=m))
{ 
sum+=aa[ans];  //
bb[ans3]+=aa[ans];  
ans++;  
} 
else 
{  
bb[ans3]+=bb[ans2];  
sum+=bb[ans2];  
ans2++;  
}
ans3+=1;  
} 
}
memset(aa,0,sizeof aa);  
memset(bb,0,sizeof bb);
printf("%lld\n",sum); 
loop:;
/*cout<<x<<endl;*/
}return 0;
} 
