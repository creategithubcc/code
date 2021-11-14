#include<iostream>
#include<cstring>
#include<queue> 
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000];
void HeapAdjust(int i,int n)
{
    int child = 2 * i;
    int temp = arr[i];
    while (child <= n)
    {
        if (child > n)
            break;
        if (arr[child] < arr[child + 1]&&child < n)
            child++;
        if (temp < arr[child])
        {
            arr[i] = arr[child];
            i = child;
            child = 2 * i;
        }
        else
            break;
    }
    arr[i] = temp;
}
void HeapSort(int n)
{
	int i;
	for(i=n/2;i>0;i--)
	{
		HeapAdjust(i,n);
	}
}
void output(int n)
{
	for(int j=1;j<=n;j++)
	{
		printf("%d ",arr[j]);
	}printf("\n");
	arr[1]=arr[n];
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=3;i++)
	{
		HeapSort(n);
		output(n);
		n--;
	}
return 0;	
}
