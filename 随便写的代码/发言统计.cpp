#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,sum=0,ret,j,chang,b=0;
	char s[10000][25],a[10000][25];
	
	scanf("%d",&n);//������� 
	
	for(i=0;i<n;i++)
	{
	scanf("%s",&s[i]);//�����ά�����¼ÿһ���ַ��� 
	}
	for(i=0;i<n;i++)
	{
	chang=strlen(s[i]);//���Գ��� 
	if((chang<=10))//���С�������ǲ�Ӫ������ 
		{
			sum+=1;//��Ӫ����һ 
		}
	}
	for(i=0;i<n;i++)
	{
	chang=strlen(s[i]);
	for(j=i+1;j<n;j++)
	{
	ret=strcmp(s[i],s[j]);//�Ƚ��ַ��� 
	if((ret==0)&&(i!=j)&&(chang>10))//����ַ���һ���Ļ� 
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
	printf("%d\n",n-sum);//��Ӫ���ķ��� 
}
