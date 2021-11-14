#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int fun(const void*a1,const void*b1)
{
    return*(int*)a1-*(int*)b1;
}
vector<int> ss[200086];
long long int aa[200086],bb[200086],cc[200086],qs=1,os=0;
bool sjk(int n)
{
for(int i=0;i<ss[n].size();i++)
{
if(aa[ss[n][i]]!=0)
{
continue;
}  
else if(aa[ss[n][i]]==0)
{
for(int j=0;j<ss[n].size();j++)
{
aa[ss[n][i]]=1;	
}
bb[ss[n][i]]=bb[n]+1;
if(bb[ss[n][i]]%2==1)
{
os+=1;
}
else if(bb[ss[n][i]]%2==0)
{
qs+=1;
}
sjk(ss[n][i]);
cc[n]=cc[n]+cc[ss[n][i]];
}  
}
}
int main()
{
int i,j,k,m,n;
long long int sum=0,ans=0;
cin>>n;
for(i=1;i<n;i++)
{
cin>>k>>m;
ss[m].push_back(k);
ss[k].push_back(m);
}
for(i=0;i<=200086;i++)
{
cc[i]=1;
}
memset(aa,0,sizeof(aa));
for(i=0;i<=n;i++)
{
bb[1]=0;
aa[1]=1;	
}
sjk(1);
for(i=1;i<=n;i++)
{
sum=sum+cc[i]*(n-cc[i]);
}
ans=(sum+os*qs)/2;
cout<<ans<<endl;
}
