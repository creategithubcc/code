#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char str[1005];
int tail,head=0;
void headout()
{
	printf("destroy tail\n");
	printf("free list node\n");
	printf("generic list: ");
}
void GetHead()
{
	headout();
	int sendu=-1,i;
	for(i=head;str[i]!='\0';i++)
	{
		if(str[i]=='(')
		{
			sendu+=1;
			if(sendu==0)
				head=i+1;
			continue;	 
		}
		if(str[i]==')')
		{
			sendu-=1;
			if(sendu==0)
			{
				tail = i;
				break;
			} 
			continue;
		}
		if (str[i] == ','&&sendu == 0)
        {
            tail = i - 1;
            break;
        }
	}
	for(i=head;i<=tail;i++)
	{
		printf("%c",str[i]);
	}printf("\n");
	
}
void tailout()
{
	printf("free head node\n");
	printf("free list node\n");
	printf("generic list: ");	
}
void GetTail()
{
	tailout();
	int sendu=-1,i;
	for(i=head;str[i]!='\0';i++)
	{
		if(i == tail)
		{
			printf("()\n");
			goto x;
		}
	    if (str[i] == '(')
            sendu++;
        if (str[i] == ')')
            sendu--;
        if (str[i] == ','&&sendu == 0)
        {
            str[i] = '(';
            head = i;
            break;
        }
	}
	for(i=head;i<=tail;i++)
	{
		printf("%c",str[i]);
	}printf("\n");
	x:;
}
void input()
{
	scanf("%s",&str);
	printf("generic list: %s\n",str);	
}
int main()
{
	int t;
	input();
	tail=strlen(str)-1;
	while(scanf("%d",&t)!=EOF)
	{
		if(t==1)
		{
			GetHead();
		}
		else if(t==2)
		{
			GetTail();
		}
	}
return 0;	
}
