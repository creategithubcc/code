#include<stdio.h>
#include<stdlib.h>
int fun(const void*a,const void*b)
{
    return*(int*)a-*(int*)b;
}

int main ()
{ 
	long long int x[100086]={},y[100086]={},i,j,k,n,x1,y1,sum=0;
	while(scanf("%d",&n)!=EOF)//while(1)的情况下乐学上最后输出肯定会变成无数个零...上一道题血痛的教训... 
	{  	
		sum=0;
		x[0]=0;y[0]=0;
	    for(i=1;i<=n;i++)//从1号士兵开始 
	    {
	   		scanf("%lld %lld",&x[i],&y[i]);
		}
		qsort(&x[1],n,sizeof(long long int),fun);//从一开始快速排序x坐标y坐标 /////首地址（从哪开始） 总共有几个 要占用的字节（通常int）调用子函数 
		qsort(&y[1],n,sizeof(long long int),fun);//c语言不能用sort而是要用qsort...... 
	    for(i=1;i<=n;i++)
	    {
	    	x[i]=x[i]-i;//让x坐标从1开始，因为要排成一列，所以y轴可以不动但x轴要-1，-2，-3......-n,然后重新排序x 
		}
		y1=y[(1+n)/2];
		qsort(&x[1],n,sizeof(long long int),fun);
	    x1=x[(1+n)/2];
	    for(i=1;i<=n;i++)
	    {
	    	sum+=abs(y[i]-y1);//最后就是|x-x1|+|x-x2|+...... 
	        sum+=abs(x[i]-x1);//绝对值相加得出要移动的横坐标，纵坐标的数值 
	    }
	    printf("%lld\n",sum);
	}
}

