#include <iostream>
#include <algorithm>
int num[1001];
int wei[1001];
int dp[1001][1001];  //��������������� => ���׽��

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
	{
        cin>>num[i]>>wei[i];
    }
    for(int i=1;i<=k;i++)//���ﶨ�����Ұ�������������Ҳ�����ڵ�ǰ������������ץ����ֻ 
	{
        for(int j=n;j>=0;j--)//��һ����ʣ�ྫ���������Ƥ���������������on2��ʹ��������ֵ��n*m�� 
		{
            for(int x=m;x>=0;x--)//����ǰdpֵ�����Լ���ץ������ʱ �����ж���һ���᲻���֮ǰ�����Ž���ã���Ļ����滻 
			{
                if(j-num[i]>=0&&x-wei[i]>=0)//��Ϊ��֮ǰ�����Ž��ˣ��������ץ����˵�����Ͳ������Ž������·�� 
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
