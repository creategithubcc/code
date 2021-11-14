#include<stack>
#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio>
using namespace std;
struct matrix
{
	int hang,lie,geshu;
	struct
	{
		int i ,j, e;//	 row–– col¡– 
	}ys[1005];
	int temp[1005];
};
int cpot[1000];
int num[1000];
matrix ma, mb, ans;
void cheng()
{
	int i,mahang,tag,p,mbhang,t,q,anslie;
	if (ma.geshu*mb.geshu != 0)
	{
		for (mahang = 1; mahang <= ma.hang; mahang++){
			memset(cpot, 0, sizeof(cpot));
			ans.temp[mahang] = ans.geshu + 1;
			if (mahang < ma.hang)
				tag = ma.temp[mahang + 1];
			else
			{
				tag = ma.geshu + 1;
			}
			for (p = ma.temp[mahang]; p < tag; p++){
				mbhang = ma.ys[p].j;
				if (mbhang < mb.hang)
					t = mb.temp[mbhang + 1];
				else
				{
					t = mb.geshu + 1;
				}
				for (q = mb.temp[mbhang]; q < t; q++){
					anslie = mb.ys[q].j;
					cpot[anslie] += ma.ys[p].e*mb.ys[q].e;
				}
			}
			for (anslie = 1; anslie <= ans.lie;anslie++)
			if (cpot[anslie]){
				ans.geshu++;
				ans.ys[ans.geshu].i = mahang;
				ans.ys[ans.geshu].j = anslie;
				ans.ys[ans.geshu].e = cpot[anslie];
			}
		}
	}
}
void output()
{
	int i;
	printf("%d\n", ans.hang);
	printf("%d\n", ans.lie);
	printf("%d\n", ans.geshu);
	for (i = 1; i <= ans.geshu; i++)
		printf("%d,%d,%d\n", ans.ys[i].i, ans.ys[i].j, ans.ys[i].e);
	return ;
}
int very[1005];
void fun()
{
	int i;
	for(i=1;i<ma.geshu;i++)
	{
		very[i]=ma.ys[i].e;	
	}	
} 
void input()
{
	int i;
	scanf("%d%d%d", &ma.hang, &ma.lie, &ma.geshu);
	for (i = 1; i <= ma.geshu; i++)
	{
		scanf("%d%d%d", &ma.ys[i].i, &ma.ys[i].j, &ma.ys[i].e);
	}
	scanf("%d%d%d", &mb.hang, &mb.lie, &mb.geshu);
	for (i = 1; i <= mb.geshu; i++)
	{
		scanf("%d%d%d", &mb.ys[i].i, &mb.ys[i].j, &mb.ys[i].e);
	}	 
}
int main()
{
	int i;
	input();
	fun();
	for (i = 1; i <= ma.hang; i++)
		num[i] = 0;
	for (i = 1; i <= ma.geshu; i++)
		num[ma.ys[i].i]++;
	ma.temp[1] = 1;
	for (i = 2; i <= ma.hang; i++)
		ma.temp[i] = ma.temp[i - 1] + num[i - 1];
	for (i = 1; i <= mb.hang; i++)
		num[i] = 0;
	for (i = 1; i <= mb.geshu; i++)
		num[mb.ys[i].i]++;
	mb.temp[1] = 1;
	for (i = 2; i <= mb.hang; i++)
		mb.temp[i] = mb.temp[i - 1] + num[i - 1];
	ans.hang = ma.hang;
	ans.lie = mb.lie;
	ans.geshu = 0;
	cheng();
	output();
}

