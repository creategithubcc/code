#include <iostream> 
#include <queue>
#include <stdio.h> 
#include <string.h>
#include <stack>
using namespace std;
int fun(const void*a1,const void*b1)
{
return*(int*)a1-*(int*)b1;
}
int main()
{
	long long p;
	stack<int> zhan;
	int i,j,k,n,m,flag=0,ans,ans2;  
	while(cin>>n)
	{
		while(zhan.empty()==0)
		{
			zhan.pop();
		}
		for(i=0;i<n;i++)
		{
			cin>>p;
			ans=p%2;
			if(zhan.empty()==0)
			{
				ans2=(zhan.top())%2;
				if(ans==ans2)
				{
					zhan.pop();
				}
				else
				{
					zhan.push(p);
				}
			}
			else
			{
				zhan.push(p);
			}
		 } 
		 if(zhan.empty()==1)
		 {
		 	cout<<"YES"<<endl;
		 }
		 else
		 {
		 	while(zhan.empty()==0)
		 	{
		 		if(zhan.empty()==1)
		 		{
		 			cout<<"YES"<<endl;
				 }
				 else
				 {
				 	flag=0;
				 	while(zhan.empty()==0)
				 	{
				 		flag++;
				 		zhan.pop();
					 }
					 if(flag==1)
					 {
					 	cout<<"YES"<<endl;
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
