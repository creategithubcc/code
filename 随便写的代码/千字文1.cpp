#include<stdio.h>

struct kanji
{
	int val;
	unsigned char a[5];
}
	aa[65535];//�Ȱѽṹ������ 



int main()
{
	int i,j=0,u;
	unsigned char ii,jj,bb,cc;//ii�������ַ� 
	//freopen("use1.txt","r",stdin);
//	freopen("result1.txt","w",stdout);
	for(i=1;i<65536;i++)
	{
		aa[i].val=0;
	}

	while(scanf("%c",&ii)!=EOF)
	{
		if((ii>>4)==15)//������������ʮ��λ����� ��Ҫ�����ֽڣ�ʮ��ʱ������Ҫ�����ֽڣ�ʮ����Ҫһ�� 
		{
			jj=getchar();//����һ���ֽ� 
			bb=getchar();
			cc=getchar();
			u=((ii&7)<<18)+((jj&63)<<12)+((bb&63)<<6)+(cc&63);//unicodeת��utf8�Ǹ����ֽڵ������ټ���Unicode�������������� 
			aa[u].val++;                                 // �����һ��������λ��ʼ�����δӺ���ǰ�����ʽ�е�x��ʣ�����㲹ȫ 
			aa[u].a[0]=ii;                                //�����ֽڵĻ�����1110xxxx 10xxxxxx 10xxxxxx����x��������unicode�� 
			aa[u].a[1]=jj;                                // �ɴ˵�֪��utf8ת����Unicode�ķ��������ǽ�1110��10��10ȥ������ʣ�µ�1��0��λ��� 
			aa[u].a[2]=bb;                               // utf8�����������ֽ� 
			aa[u].a[3]=cc;
			aa[u].a[4]='\0';
		}
		
		
		else if((ii>>4)==14)//������������ʮ��λ�����
		{
			jj=getchar();
			bb=getchar();
			u=((ii&15)<<12)+((jj&63)<<6)+(bb&63);          //2^4-1=15,2^6-1=63,�����￪ʼ������6*nλ
			aa[u].val++;
			aa[u].a[0]=ii;
			aa[u].a[1]=jj;
			aa[u].a[2]=bb;
			aa[u].a[3]='\0';
		}
		
		
		else if(((ii>>4)>=12)&&((ii>>4)<14))//������������ʮ��λ�����
		{
			jj=getchar();
			u=((ii&31)<<6)+(jj&63);
			aa[u].val++;
			aa[u].a[0]=ii;
			aa[u].a[1]=jj;
			aa[u].a[2]='\0';
		}
		
		
		else if(((ii>>4)>8)&&((ii>>4)<12))//UTF-8//�����������ǰ�λ�����
		{
			continue;
		 } 


	}

	for(i=0;i<65536;i++) 
	{
		if(aa[i].val>1)
		{
			printf("%s 0x%04x %d\n",aa[i].a,i,aa[i].val);
			j++;
		}
	}
	
	if(j==0)
	{
		printf("No repeat!\n");
	}
//	fclose(stdin);
//	fclose(stdout);
}
