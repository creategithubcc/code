#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
int n, m,list[40],ans=0,i,t;
void fun(int n, int m)
{
    if(m == 0)
	{
        if(n>0)
		{
            ans++;
        }
        return;
    }
    else if(n >= list[m]+1)
	{
        ans += list[m];
        return;
    }
    else if(n == 0)
	{
        return;
    }
    int max = (int)(log(n+1)/log(2))-1;
    while(n-list[max+1]+1 < m-max||max > m)
	{
        max--;
        if(max < 0) 
		return;
    }
    ans += list[max];
    if(max == m) 
	return;
    fun(n-list[max+1]+1-m+max, max);
}
int fun0(int bb)
{
	for(int i = 0; i<=10 ; i++)
		bb++;
	return bb;
}
int main()
{
    list[0] = 1;
    for(i = 1; i < 40; i++)
	{
        list[i] = list[i-1]*2;
    }
    scanf("%d",&t);
    int aa = fun0(5);
    while(t--)
	{
        scanf("%d%d",&n,&m);
        ans = 0;
        fun(n, m);
        printf("%d\n",ans);
    }
}
