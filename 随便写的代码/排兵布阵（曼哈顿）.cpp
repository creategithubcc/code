#include<stdio.h>
#include<stdlib.h>
int fun(const void*a,const void*b)
{
    return*(int*)a-*(int*)b;
}

int main ()
{ 
	long long int x[100086]={},y[100086]={},i,j,k,n,x1,y1,sum=0;
	while(scanf("%d",&n)!=EOF)//while(1)���������ѧ���������϶�������������...��һ����Ѫʹ�Ľ�ѵ... 
	{  	
		sum=0;
		x[0]=0;y[0]=0;
	    for(i=1;i<=n;i++)//��1��ʿ����ʼ 
	    {
	   		scanf("%lld %lld",&x[i],&y[i]);
		}
		qsort(&x[1],n,sizeof(long long int),fun);//��һ��ʼ��������x����y���� /////�׵�ַ�����Ŀ�ʼ�� �ܹ��м��� Ҫռ�õ��ֽڣ�ͨ��int�������Ӻ��� 
		qsort(&y[1],n,sizeof(long long int),fun);//c���Բ�����sort����Ҫ��qsort...... 
	    for(i=1;i<=n;i++)
	    {
	    	x[i]=x[i]-i;//��x�����1��ʼ����ΪҪ�ų�һ�У�����y����Բ�����x��Ҫ-1��-2��-3......-n,Ȼ����������x 
		}
		y1=y[(1+n)/2];
		qsort(&x[1],n,sizeof(long long int),fun);
	    x1=x[(1+n)/2];
	    for(i=1;i<=n;i++)
	    {
	    	sum+=abs(y[i]-y1);//������|x-x1|+|x-x2|+...... 
	        sum+=abs(x[i]-x1);//����ֵ��ӵó�Ҫ�ƶ��ĺ����꣬���������ֵ 
	    }
	    printf("%lld\n",sum);
	}
}

