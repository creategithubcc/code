#include<stdio.h>
#include<string.h>
int main()
{   char a[100086],c[10]={'f','a','t','t','y','h','a','p','p','y'},b[10086]={};
    int i=0,j,m,k,flag,p,ch=0,z;
    scanf("%d",&z);
    while(ch<z)
	{
    	memset(a,0,sizeof(a));//����������ڵ����� 
        scanf("%s",&a);
        p=strlen(a);
        if(p<10)
        {
        	printf("-1\n");
        	goto loop;
		}
        for(i=0;i<=p-9;i++)//i��0��ʼ�� p-10+1 ����ʾ����ô��ε����� 
        {
			memset(b,0,sizeof(b));//���b���� 
			flag=0;
			for(j=i;j<10+i;j++)//��i��ʼ��ʮλ�ַ�����ʼ�Ƚ� j��0��ʼ 
		  	{
			   	b[j-i]=a[j];//��ÿ��������ַ���ȫ���ŵ�b[] 
				if(b[j-i]!=c[j-i])//���������ĳһ�鴮���պõ���c�����Ļ� 
				  {
					  	flag++;
					  	m=j-i;
			    	} 
		  	}
	 		if(flag==1)
	 		{
	 			for(j=0;j<i;j++)//jС��i��i+10���濪ʼһֱ��p���� 
	 			{
	 				if(a[j]==c[m])
	 				{
	 					printf("%d %d\n",j+1,m+i+1);//��һ��ʼ��������� 
	 					flag=0;
	 					goto loop;
					 }
				 }
				 for(j=i+10;j<p;j++)
				 {
				 	if(a[j]==c[m])
	 				{
	 					printf("%d %d\n",m+i+1,j+1);//��10+1��ʼ��������� 
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
