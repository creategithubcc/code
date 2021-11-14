#include <iostream>  
#include <cstring> 
using namespace std;  
long long int aa[2086],a,b,m,bb[2086];  
int main()
{  
int n,i,j;                                                     //問題のポイントは 
cin>>n>>m;  												// //外ループiが1からnまで
long long int cc[2086];  									// 遍歴しているのは，i番目のを選択したときのプラン数である
memset(cc,0,sizeof cc);  									// 内ループは0からｍ―1であり，それぞれ剰余が0と剰余がｍ―1で
memset(bb,0,sizeof bb);  									// あるとき，剰余はｍで到達不可能であるので，ｍ―1で十分である.
for(i=0;i<n;i++)
{  
cin>>aa[i];  
} 
for(j=0;j<n;j++)
{
b=m;
} 
for(j=0;j<n;j++)                                         
{  
for(i=0;i<m;i++)
{  
bb[(i+aa[j])%m]=cc[(i+aa[j])%m]%10000000+cc[i]%10000000;  
bb[(i+aa[j])%m]=bb[(i+aa[j])%m]%10000000;  
} 
for(i=0;i<m;i++)
{
for(b=0;b<m;b++)
{
cc[i]=bb[i]; 
} 
}  
cc[aa[j]%m]++;  
}  
cout<<cc[0]<<endl;  
}  
