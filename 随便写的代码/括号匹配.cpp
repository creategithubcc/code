#include<stdio.h>      
#include<string.h>
int main()
{
	char a[100086]={};
	int i,j,k,z,p,q,sum=0,left=0,right=0;
	int b[100086]={},flag=0,num=0,ans,ans2;////////////////////
	scanf("%d",&z);
	for(i=0;i<z;i++)
	{
		scanf("%s",&a);
		left=0;right=0;
		p=strlen(a);
		for(j=0;j<p;j++)
		{
			if(a[j]=='(')
			{
				left++;	
			}
			else if(a[j]==')')
			{
				right++;
				if(left>=1)
				{
					left--;
					right--;
				}
			}
		 } 
		if((left!=0)&&(right!=0))
		{
			i--;z--;
			continue;
		}
		else if((left==0)&&(right!=0))
		{
			b[right]+=1;
			if(right>flag)
			{
				flag=right;
			}
		}
		else if((right==0)&&(left!=0))
		{
			b[-left]+=1;
			if(left>flag)
			{
				flag=left;
			}
		}
		else if((left==0)&&(right==0))
		{
			num++;
		}
	}
	for(i=0;i<=flag;i++)
		{
			 if(b[i]>=b[-i])
				{
					ans=b[i]-b[-i];
					ans2=b[i]-ans;
					sum+=ans2;
				}
			else if(b[i]<b[-i])
			{
				sum+=b[i];
			}
		}
		printf("%d\n",sum+(num/2));
}
