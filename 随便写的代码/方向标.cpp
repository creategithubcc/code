#include <iostream> 
#include <cstring> 
using namespace std; 
int main() 
{ 
int i,j,n,l=-1,r=-1; 
long long aa[2086],bb[4086]; 
cin>>n; 
memset(aa,0,sizeof aa); 
for(i=0;i<=n;i++)
{ 
cin>>aa[i]; 
} 
memset(bb,0,sizeof bb); 
bb[0]=bb[1]=1; 
for(i=1;i<=n;i++)
{ 
for(j=i;j>=0;j--)
{ 
if(aa[i]>aa[j])
{ 
l=j; 
break; 
} 
} 
for(j=i;j>0;j--)
{ 
if(aa[j]>aa[i])
{ 
r=j; 
break; 
} 
} 
if(r==-1||l==-1)
{ 
r=l=-1;
bb[i]=bb[i-1]; 
} 
else if(r!=-1&&l!=-1)
{ 
bb[i]=bb[l]%2147483647+bb[r]%2147483647; 
bb[i]=bb[i]%2147483647; 
l=r=-1; 
} 
} 
cout<<bb[n]<<endl;  
}  
