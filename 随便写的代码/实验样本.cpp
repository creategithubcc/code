#include<stdio.h>
int fun(int r)
{
	int i;
	if(r%2==0)
	{
	r=r/2;
	}
	else if(r%2!=0)
	{
	r=r*3+1;
	}
	return r;
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;;i++)
	{
		printf("%d\n",n);
		n=fun(n);
		if(n==1)
		break;}
		printf("1\n%d\n",i+1);
		return 0;
	}

