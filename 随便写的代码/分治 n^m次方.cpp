#include<stdio.h>
#include<iostream>
using namespace std; 

void RandomBigNumFun(int low,int high)                 //传递参数为底数和指数
{
	unsigned int temp[1024] = {0};                     //初始化一个数组，用来存放10000进制的数据
	temp [0] = low;                                    //初始化第一个元素为需要的值！
	int flag = -1;                                     //标记变量，用来指示是否需要往上一位进位，同事保存进多少
	unsigned int m_count = 1;                          //技术变量，计算数组中被占用了多少个元素
	int _index,index;                                  //两个循环变量
	for(_index = 0;_index <high-1; ++_index)           //循环high-1次 因为本身temp[0]= low，
	{
		for(index = 0; index < m_count ; ++index)      //循环m_count次，其实原本可以把整个数组循环完
		{                                              //只不过耗时了，因为实际有值的地方只有m_count个
			temp[ index ] *= low;                      
			if(flag != -1)                             //检测下一位是否溢出，需要向自己进位 
			{
				temp[index] += flag;
				flag = -1;                             //进位之后别忘记把标记在设置为-1
			}
			if(temp[index] > 9999)                     //判断是否需要向上一位进位
			{
				flag = temp[index]/10000 ;
				temp[index] %= 10000;
			}
		}
		if(flag != -1)                                 
		{
			temp[index] += flag;
			++m_count;
			flag = -1;
		}
		if(m_count > 1023)
		{
			printf("数据过大而数组过小，请重置存放数组的大小");
			exit(0);
		}
	}
	for(index = m_count-1;index >=0;--index)        //这里值得说明，如果该位上是1，则要输出0001，因为是一万进制
	{
		if(temp[index] < 10)
			cout<<"000"<<temp[index];
		else if(temp[index] < 100)
			cout<<"00"<<temp[index];
		else if(temp[index] < 1000)
			cout<<"0"<<temp[index];
		else
			cout<<temp[index];
	}
} 
int main()
{
	int n,m;
	cin>>n>>m;
	RandomBigNumFun(n,m);
}
