#include <iostream> 
#include <cstring> 
using namespace std;  
long long aa[500086],bb[4][500086],max1,flag=1; 
const int wx=0x3f3f3f3f; //無限コード 
int main() 
{ 
int n,i,j,k;
long long int max2; 
cin>>n; 
memset(bb,0,sizeof bb); 
for(i=1;i<n+1;i++)
{ 
cin>>aa[i]; 
} 
k=1; 
for(i=1;i<4;i++,k^=1)//ここでとりあえず必ず一人の女の子を貯蔵して
{ 
bb[k][i-1]=-wx;           // そして加入前の和は(本隊の前の)と(上隊の前の)中の最大値を取ります
for(j=1;j<n+1;j++)
{
max2=-wx;
}   
for(j=i;j<n-2+i;j++)  
{ 
max2=max(max2,bb[k^1][j-1]);   
bb[k][j]=max(bb[k][j-1],max2)+aa[j];  
} 
} 
for(i=1;i<n+1;i++)
{
max1=-wx;
} 
for(i=3;i<n+1;i++)
{ 
if(bb[3&1][i]>max1)
{ 
max1=bb[3&1][i]; 
} 
} 
cout<<max1<<endl;
}  
