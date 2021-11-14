#include<stdio.h>

struct kanji
{
	int val;
	unsigned char a[5];
}
	aa[65535];//先把结构体做好 



int main()
{
	int i,j=0,u;
	unsigned char ii,jj,bb,cc;//ii是输入字符 
	//freopen("use1.txt","r",stdin);
//	freopen("result1.txt","w",stdout);
	for(i=1;i<65536;i++)
	{
		aa[i].val=0;
	}

	while(scanf("%c",&ii)!=EOF)
	{
		if((ii>>4)==15)//当二进制数是十五位的情况 需要三个字节，十四时则是需要两个字节，十二需要一个 
		{
			jj=getchar();//代表一个字节 
			bb=getchar();
			cc=getchar();
			u=((ii&7)<<18)+((jj&63)<<12)+((bb&63)<<6)+(cc&63);//unicode转换utf8是根据字节的数量再加上Unicode本身的码来编码的 
			aa[u].val++;                                 // 从最后一个二进制位开始，依次从后向前填入格式中的x，剩下用零补全 
			aa[u].a[0]=ii;                                //三个字节的话就是1110xxxx 10xxxxxx 10xxxxxx，在x里面填入unicode码 
			aa[u].a[1]=jj;                                // 由此得知从utf8转换到Unicode的方法，就是将1110，10，10去掉并将剩下的1和0移位相加 
			aa[u].a[2]=bb;                               // utf8编码是六个字节 
			aa[u].a[3]=cc;
			aa[u].a[4]='\0';
		}
		
		
		else if((ii>>4)==14)//当二进制数是十四位的情况
		{
			jj=getchar();
			bb=getchar();
			u=((ii&15)<<12)+((jj&63)<<6)+(bb&63);          //2^4-1=15,2^6-1=63,从这里开始向左移6*n位
			aa[u].val++;
			aa[u].a[0]=ii;
			aa[u].a[1]=jj;
			aa[u].a[2]=bb;
			aa[u].a[3]='\0';
		}
		
		
		else if(((ii>>4)>=12)&&((ii>>4)<14))//当二进制数是十二位的情况
		{
			jj=getchar();
			u=((ii&31)<<6)+(jj&63);
			aa[u].val++;
			aa[u].a[0]=ii;
			aa[u].a[1]=jj;
			aa[u].a[2]='\0';
		}
		
		
		else if(((ii>>4)>8)&&((ii>>4)<12))//UTF-8//当二进制数是八位的情况
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
