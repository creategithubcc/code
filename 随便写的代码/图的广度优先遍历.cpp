#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct tu{
	char name;//节点
	int next[500];
	int biao=0;
	int num=0;
}map[500];	
queue <tu> M;
void creat_list()
{
	int right,left;
	while(1)
	{
		scanf("%d,%d",&left,&right);//建表 
		if(left==-1&&right==-1)
			break;
		map[left].next[map[left].num] = right;
		map[left].num++;
		map[right].next[map[right].num] = left;
		map[right].num++;	
	}
}
void bfs(int n)
{
	printf("the Breadth-First-Seacrh list:");
	for(int i=0;i<n;i++)
	{
		if(map[i].biao==0)
		{
			M.push(map[i]);
			map[i].biao = 1;
			struct tu temp;
			while(!M.empty())
			{
				temp=M.front();	
				printf("%c",temp.name); 
				for(int j=temp.num-1;j>=0;j--)
				{
					if(map[temp.next[j]].biao==0)
					{
						map[temp.next[j]].biao=1;
						M.push(map[temp.next[j]]);
					}
				}
				M.pop();
			}
		}
	}
	printf("\n");
}
void out(int n)
{
	printf("the ALGraph is\n");	
	for(int i=0;i<n;i++)
	{
		printf("%c",map[i].name);
		for(int j=map[i].num-1;j>=0;j--)
		{
			printf(" %d",map[i].next[j]);
		}
		printf("\n");
	}
}
int main()
{
	int i=0,j;
	while(1)
	{
		char s[10];
		scanf("%s",s);
		if(s[0]=='*')
			break;
		map[i].name = s[0];
		i++;	
	}
	int jiedian_num = i; 
	creat_list();
	out(jiedian_num);
	bfs(jiedian_num);
return 0;	
}
