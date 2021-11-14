#include<iostream>  
#include<queue>  
#include<stack>  
using namespace std; 
struct sjk{  
long long int code,c1;  
struct sjk* d1;  
long long int e1;  
long int f1;  
int g1;  
}bb[100086];   
queue <sjk> que;   
int fun(const void*a1,const void*b1)
{
return*(int*)a1-*(int*)b1;
}
template<class suiji>  
void make_heap(suiji f,suiji l);  //
int main() 
{  
long long int i,j,k,n,m,p,num,t,ans,ans2,ans3,ans4,sum;  
queue<long long>que;  
stack<long long>stk;  
priority_queue<long long>a;  
priority_queue<long long,vector<long long>,greater<long long> >c;  
long long aaa[100086]={0};  //
while(cin>>n)
{  
ans=ans2=ans3=ans4=1;//  
for(i=0;i<n;i++)
{  
cin>>sum>>num;  
if(sum!=1)
{  
if(!que.empty())
{  
sum=que.front();  
if(sum!=num)
{
ans=0;
que.pop();  
} 
else if(sum==num)
{
	que.pop();  
}
}  
else
{  
ans=0;  
}  
if(!stk.empty())
{  
sum=stk.top();   
if(sum!=num)
{  
ans2=0;  
stk.pop();  
} 
else if(sum==num)
{
stk.pop();	
}  
}  
else
{
ans2=0;
}   

if(!a.empty())
{  
t=a.top();  
if(t==num)
{
a.pop();  
}
else if(t!=num)
{  
a.pop();  
ans3=0;  
}   
}  
else 
{
ans3=0;
} 

if(!c.empty())
{  
t=c.top();  
if(t==num)
{
c.pop();  
} 
else if(t!=num)
{  
c.pop();  
ans4=0;  
}  
}  
else
{
ans4=0;
}   
} 
else if(sum==1)
{  
que.push(num);  
a.push(num);
c.push(num);  

stk.push(num);
}   
}  
p=ans+ans2+ans3+ans4;  
if(p==0)
{  
cout<<"pool zls\n";  
while(!que.empty())
{  
que.pop();  
}  
while(!stk.empty())
{  
stk.pop();  
}  
while(!a.empty())
{  
a.pop();  
}  
while(!c.empty())
{  
c.pop();  
}  
}  
else if(p==1)
{  
if(ans==1)
{  
cout<<"queue\n";  
}  
else if(ans2==1)
{  
cout<<"stack\n";  
}  
else if(ans3==1)
{  
cout<<"big priority queue\n";  
}  
else if(ans4==1)//
{  
cout<<"small priority queue\n";  
}  
while(!que.empty())
{  
que.pop();  
}  
while(!stk.empty())
{  
stk.pop();  
}  
while(!a.empty())
{  
a.pop();  
}  
while(!c.empty())
{  
c.pop();  
}  
}  
else
{  
cout<<"not sure\n";  
while(!que.empty())
{  
que.pop();  
}  
while(!stk.empty())
{  
stk.pop();  
}  
while(!a.empty())
{  
a.pop();  
}  
while(!c.empty())
{  
c.pop();  
}  
}   
}  
}  
