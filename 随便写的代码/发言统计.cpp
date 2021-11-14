#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,sum=0,ret,j,chang,b=0;
	char s[10000][25],a[10000][25];
	
	scanf("%d",&n);//输入次数 
	
	for(i=0;i<n;i++)
	{
	scanf("%s",&s[i]);//输入二维数组记录每一串字符串 
	}
	for(i=0;i<n;i++)
	{
	chang=strlen(s[i]);//测试长度 
	if((chang<=10))//如果小于零则是不营养发言 
		{
			sum+=1;//不营养加一 
		}
	}
	for(i=0;i<n;i++)
	{
	chang=strlen(s[i]);
	for(j=i+1;j<n;j++)
	{
	ret=strcmp(s[i],s[j]);//比较字符串 
	if((ret==0)&&(i!=j)&&(chang>10))//如果字符串一样的话 
	{
		b=1;
	}
	}
		if(b==1)
	{
		sum+=b; 
		b=0;
	}	
	}		
	printf("%d\n",n-sum);//有营养的发言 
}
