#include <iostream>  
#include <queue> 
#include <stdio.h>  
#include <string.h> 
#include <stack> 
using namespace std; 
int cmp(const void*a,const void*b)    
{    
return*(long long*)a>*(long long*)b;    
}     
int fun(const void*a1,const void*b1) 
{ 
return*(int*)a1-*(int*)b1; 
} 
int main() 
{ 
long long p; 
stack<int> zhan; 
int i,j,k,n,m,flag=0,ans,ans2,max=0;   
while(cin>>n) 
{ 
flag=0;  
max=0;
while(zhan.empty()==0) //リセット 
{ 
zhan.pop(); 
} 
for(i=0;i<n;i++) 
{ 
cin>>p; 
if(max<p)
{
max=p;
} 
ans=p%2; 
if(zhan.empty()==0)// Zhanがもし�召世辰燭蕕佞蕕阿廚蕕垢い繊■修世辰燭蕕世后■爾世辰燭蕕い譴� 
{ 
if(p>zhan.top()) 
{ 
flag=1; 
} 
else if(p==zhan.top()) 
{ 
zhan.pop(); 
} 
else if(p<zhan.top()) 
{ 
zhan.push(p); 
} 
} 
else if(zhan.empty()!=0)
{ 
zhan.push(p); 
} 
}  
if(flag==1) //////////////ここちゅうい!!!!
{ 
if(!zhan.empty()&&zhan.top()==max)
{
cout<<"YES"<<endl;
}
else
{
cout<<"NO"<<endl;
}
} 
else if(flag!=1)
{ 
while(zhan.empty()==0) 
{ 
if(zhan.empty()==1) 
{ 
cout<<"YES"<<endl; 
} 
else if(zhan.empty()!=1)
{ 
flag=0; 
while(zhan.empty()==0) 
{ 
flag++; 
zhan.pop(); 
} 
if(flag==1) 
{ 
if(!zhan.empty()&&zhan.top()==max) 
{
cout<<"YES"<<endl;
}
else
{
cout<<"NO"<<endl;
}
} 
else 
{ 
cout<<"NO"<<endl; 
} 
} 
} 
} 
}    
}
