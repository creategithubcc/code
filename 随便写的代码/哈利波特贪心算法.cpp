#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,a[100],b[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(i=0;i<n;i++)
    {
    	cin>>b[i];
	}
    sort(a,a+n);//÷∏’Î
    sort(b,b+n);
    for(i=0;i<n;i++)
	{
		
		if(a[i]>b[i])
		{
			cout<<"NE"<<endl;
			return 0;
		}
	}
	cout<<"DA"<<endl;
}
