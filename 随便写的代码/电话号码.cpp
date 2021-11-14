#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int zimu[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,9};
int num[1000086],sum[2000],flag=1,x=0,ans,ans2,ans3,m=0,d;
/*bool q=true;*/

int fun(const void*a,const void*b)
{
    return*(int*)a-*(int*)b;
}
int main()
{
    int n=0,i,j,k,p;
    char tel[2000];
    printf("Error:\n");
	while(scanf("%s",&tel)!=EOF)
	{
		n++;
		p=strlen(tel);
			
	    if(tel[0]!='3'&&tel[0]!='6'&&tel[0]!='D'&&tel[0]!='E'&&tel[0]!='F'&&tel[0]!='M'&&tel[0]!='N'&&tel[0]!='O')
	   	{
			printf("%s\n",tel);
			 x++;
			 continue;	
		}
				
		
            for(j=0;j<p;j++)//开始检查是否有“-”有的话就去掉，没有的话则把字符转换成数字并存入num数组 
            {
            	if(tel[j]=='-')
				{
				for(k=j;k<p;k++)
				{
					tel[k]=tel[k+1];
				}
				j--;
				p--;
				continue;	
				}
	            else
				{
					if(tel[j]>='0'&&tel[j]<='9')
					{
					 sum[j]=tel[j]-'0';
					}
				    else if(tel[j]>='A'&&tel[j]<='Z') 
				    {
				   	 sum[j]=zimu[tel[j]-'A'];
					}
				} 
			}
			ans=0;//将数组sum里面的数组转换成函数并存入num 
			for(i=0;i<p;i++)
			{
				ans+=sum[i]*pow(10,p-1-i);	
			}
		m++;
		num[m-1]=ans;	
	}
		qsort(&num,n-x,sizeof(int),fun);//*一直到这一步没有错 
		if(x==0)
		{
			printf("Not found.\n");
		}
		n=n-x;
		x=0;
		printf("\nDuplication:\n");
		for(i=0;i<n;i++)
		{
			flag=1;
	        while((num[i]==num[i+1])&&(i+1<n))//判断是否有重复的 
	        {
	        	//q=0;
	           	flag+=1;
	           	i++;
			}
			if(flag>=2)
			{
				ans2=num[i]/10000;
				ans3=num[i]%10000;
				printf("%03d-%04d %d\n",ans2,ans3,flag);
				x++;
			} 	
		}
		if(x==0)
		{
			printf("Not found.\n");
		}
}

