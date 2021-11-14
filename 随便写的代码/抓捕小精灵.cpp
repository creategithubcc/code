#include <iostream>
#include <algorithm>
int num[1001];
int wei[1001];
int dp[1001][1001];  //精力球个数，体力 => 最大捕捉量

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
	{
        cin>>num[i]>>wei[i];
    }
    for(int i=1;i<=k;i++)//这里定义的是野生精灵的数量，也就是在当前情况下你最多能抓多少只 
	{
        for(int j=n;j>=0;j--)//这一块是剩余精灵球和下面皮卡丘体力组成联动on2，使得所有数值有n*m个 
		{
            for(int x=m;x>=0;x--)//当当前dp值还可以继续抓捕精灵时 ，就判断这一步会不会比之前的最优解更好，会的话就替换 
			{
                if(j-num[i]>=0&&x-wei[i]>=0)//因为你之前有最优解了，这次你再抓精灵说不定就不是最优解的那条路了 
                    dp[j][x] = max(dp[j][x],dp[j-num[i]][x-wei[i]]+1);
            }
        }
    }
    cout<<dp[n][m]<<" ";
	for(int i=0;i<=m;i++)
	{
		if(dp[n][i]==dp[n][m])
		{
			cout<<m-i<<endl;
			return 0;
		}
	} 

    /*for(int j=0;j<=n;j++)
	{
		for(int i=0;i<=m;i++)
		{
			cout<<"dp["<<j<<"]["<<i<<"]"<<"="<<dp[j][i]<<endl;
		} 
	}*/ 
    return 0;
}
