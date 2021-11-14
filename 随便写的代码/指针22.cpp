#include<stdio.h>
int main()
{
	int pp[]={10,100,200};
	int i,*p;
	p=pp;
	i=0;
	while(p<=&pp[3-1])
	{
		printf("%d=%x\n",i,pp);
		printf("%d=%d\n",i,*pp);
		p++;
		i++;
	}
	return 0;
 } 
