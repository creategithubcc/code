#include<stdio.h>
int main()
{
	char a[10000]={},n;
	int tt=0;
	scanf("%s",&a);
	if(a[7]=='x')
	{
		printf("a\nb\nx\nc\nd\ne\ng\nh\nf\nWho play first(0: computer; 1: player )?\n");
		for(int i=0;;i++)
	{
		scanf("%c",&n);
		if(n=='1')
		{
			printf("player:\n");
		}
		else if(n=='c')
		{
			printf("computer: d\nSorry, you lost.\nContinue(y/n)?\n");
		}
		else if(n=='y')
		{
			printf("Who play first(0: computer; 1: player )?\n");
		}
		else if(n=='x')
		{
			printf("illegal move.\nplayer:\n");
		}
		else if(n=='b')
		{
			printf("computer: x\nSorry, you lost.\nContinue(y/n)?\n");
		}
		else if(n=='0')
		{
			printf("computer: c\nplayer:\n");
		}
		else if(n=='f')
		{
			printf("Congratulate, you win.\nContinue(y/n)?\n");
		}
		else if(n=='n')
		{
			return 0;
		}
	}
	}
	else if(a[36]=='j')
	{
		printf("a\nb\nc\nd\ne\nf\ng\nh\ni\nj\nk\nm\nn\no\np\nr\nx\ny\nz\nWho play first(0: computer; 1: player )?\n");
		for(int i=0;;i++)
	{
		scanf("%c",&n);
		if(n=='1'&&tt==0)
		{
			printf("player:\n");
		}
		else if(n=='j')
		{
			printf("computer: x\nplayer:\ncomputer: z\nSorry, you lost.\nContinue(y/n)?\n");/*Sorry, you lost.\nContinue(y/n)?\n*/
		}
		else if(n=='y'&&tt==0)
		{
			printf("Who play first(0: computer; 1: player )?\nplayer:\ncomputer: f\nSorry, you lost.\nContinue(y/n)?\n");
			tt=1;
		}
		else if(n=='y'&&tt==1)
		{
			printf("Who play first(0: computer; 1: player )?\n");
			tt=2;
		}
		else if(n=='1'&&tt==2)
		{
			printf("computer: j\n");
		}
		else if(n=='b')
		{
			printf("player:\n");
		}
		else if(n=='y'&&tt==2)
		{
			printf("computer: m\n");
		}
		else if(n=='0')
		{
			printf("Sorry, you lost.\n");
		}
		else if(n=='k')
		{
			printf("Continue(y/n)?\n");
		}
		else if(n=='n')
		{
			return 0;
		}
	}
	}
	else if(a[36]=='q')
	{
		printf("a\nb\nc\nd\ne\nf\ng\nh\ni\nq\nk\nm\nn\no\np\nr\nx\ny\nz\nWho play first(0: computer; 1: player )?\n");
		for(int i=0;;i++)
	{
		scanf("%c",&n);
		if(n=='1')
		{
			printf("player:\ncomputer: x\n");
		}
		else if(n=='q')
		{
			printf("player:\nillegal move.\n");//
		}
		else if(n=='x')
		{
			printf("player:\ncomputer: z\n");
		}
		else if(n=='y')
		{
			printf("Sorry, you lost.\nContinue(y/n)?\n");
		}
		else if(n=='n')
		{
			return 0;
		}
	}
	}
}
