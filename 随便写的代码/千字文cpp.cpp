#include <stdio.h>
struct hanzi
{
	int val;
	unsigned char s[5];
}
f[65536];
 
int main()
{
	unsigned char c,d,e,ff;
	int unic,i,aa=0;
	for (i=1;i<=65535;i++)
	{
		f[i].val=0;
	}
	freopen("use1.txt","r",stdin);
	freopen("result1.txt","w",stdout);
	while (scanf("%c",&c)!=EOF)
	{
		if ((c>> 4)<8)
		{
			continue;
		}
		else if((c>>4)==15)
		{
			d=getchar();
			e=getchar();
			ff=getchar();
			unic=((c&7)<<18)+((d&63)<<12)+((e&63)<<6)+(ff&63);
			f[unic].val++;
			f[unic].s[0]=c;
			f[unic].s[1]=d;
			f[unic].s[2]=e;
			f[unic].s[3]=ff;
			f[unic].s[4]='\0';
		}
		else if((c>>4)==14)
		{
			d=getchar();
			e=getchar();
			unic=((c&15)<<12)+((d&63)<<6)+(e&63);
			f[unic].val++;
			f[unic].s[0]=c;
			f[unic].s[1]=d;
			f[unic].s[2]=e;
			f[unic].s[3]='\0';
		}
		else if((c>>4)>=12)
		{
			d=getchar();
			unic=((c&31)<<6)+(d&63);
			f[unic].val++;
			f[unic].s[0]=c;
			f[unic].s[1]=d;
			f[unic].s[2]='\0';
		}
	}
	for(i=1;i<=65535;i++)
	{
		if(f[i].val >1)
		{
			printf("%s 0x%04x %d\n", f[i].s,i,f[i].val);
			aa=1;
		}
	}
	if(aa==0)
	{	
		printf("No repeat!\n");
	} 
		fclose(stdin);
		fclose(stdout);	
}

