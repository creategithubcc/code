#include <iostream>  
#include <algorithm>  
#include <queue>  
using namespace std;  
long int aa[100086];  
struct sjk{  
long long int code,c;  
struct sjk* d;  
long long int e;  
long int f;  
int g;  
}bb[100086];   
queue <sjk> que;  
bool cmp(const sjk &a, const sjk &b)            //const必须加，不然会错，目前不懂为啥。当return的是ture时，a先输出，所以示例中是升序  
{  
return a.c<b.c;  
}  
int fun(const void*a1,const void*b1)
{
return*(int*)a1-*(int*)b1;
}
int main()
{  
long long int i,j,k,p,q,n,m,t,sum,x;  
cin>>n;  
for(i=0;i<n;i++)
{  
cin>>bb[i].c;
bb[i].code=i+1;
bb[i].f=1; 
bb[i].e=bb[i].g=0;
} 
x=0;
for(i=0;i<n;i++)
{
if(bb[i].c>bb[i+1].c)
{
x++;
}
} 
/*cout<<x<<endl;*/
sort(bb,bb+n,cmp);  
sum=n; 
j=n-1; 
for(i=n-1;i>=0;i--)
{  
if(bb[j].c>=2*bb[i].c)
{  
bb[i].e=j;
q=bb[j].f;
bb[i].f+=q;
sum-=1;
j-=1;  
}  
}  
cout<<sum<<endl;  
for(i=0;i<n;i++)
{  
if(bb[i].g==1)
{  
continue;  
}  
else if(bb[i].g!=1)//
{  
cout<<bb[i].f<<" "<<bb[i].code<<" ";  
t=bb[i].f-1;
p=bb[i].e;
bb[i].g=1;
for(;t>0;t--)
{  
cout<<bb[p].code<<" ";  
bb[p].g=1;  
p=bb[p].e;
}  
cout<<endl;  
}  
}  

return 0;  
}  
