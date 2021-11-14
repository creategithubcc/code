#include<stdio.h>
#include<string.h>
int main()
{   char a[100086],c[10]={'f','a','t','t','y','h','a','p','p','y'},b[10086]={};
    int i=0,j,m,k,flag,p,ch=0,z;
    scanf("%d",&z);
    while(ch<z)
	{
    	memset(a,0,sizeof(a));//清除掉数组内的数据 
        scanf("%s",&a);
        p=strlen(a);
        if(p<10)
        {
        	printf("-1\n");
        	goto loop;
		}
        for(i=0;i<=p-9;i++)//i从0开始到 p-10+1 ，表示有这么多次的历遍 
        {
			memset(b,0,sizeof(b));//清除b数组 
			flag=0;
			for(j=i;j<10+i;j++)//从i开始后十位字符串开始比较 j从0开始 
		  	{
			   	b[j-i]=a[j];//把每次历遍的字符串全部放到b[] 
				if(b[j-i]!=c[j-i])//如果遍历的某一组串不刚好等于c【】的话 
				  {
					  	flag++;
					  	m=j-i;
			    	} 
		  	}
	 		if(flag==1)
	 		{
	 			for(j=0;j<i;j++)//j小于i，i+10后面开始一直到p结束 
	 			{
	 				if(a[j]==c[m])
	 				{
	 					printf("%d %d\n",j+1,m+i+1);//从一开始的序号排列 
	 					flag=0;
	 					goto loop;
					 }
				 }
				 for(j=i+10;j<p;j++)
				 {
				 	if(a[j]==c[m])
	 				{
	 					printf("%d %d\n",m+i+1,j+1);//从10+1开始的序号排列 
	 					flag=0;
	 					goto loop;
					 }
				 }
				 if(flag!=0)
					{
					 	printf("-1\n");
					 	flag=0;
					 	goto loop;
					}
			 }
			else if(flag==2)
			{
				for(j=0;j<10;j++)
				{
					if(b[j]!=c[j])
					{
						m=c[j];
						break;
					}
				}
				for(k=j+1;k<10;k++)
				{
					if(b[k]!=c[k])
					{
						if(m==b[k])
						{
							if(b[j]==c[k])
							{
								printf("%d %d\n",j+1+i,k+1+i);
								flag=0;
								goto loop;
							}
						}
					}
				}
				if(flag!=0)
				{
				 	continue;
				}
			}
			else if(flag>=3)
			{
				if(i==p-9)
				{
					printf("-1\n");
				}
				continue;
			}
			else if(flag==0)
		  	{
		  		printf("%d %d\n",i+3,i+4);
		  		goto loop;
			  }
       	}loop:if(ch<z)
		   {
		   	ch++;
		   }

    }
}
