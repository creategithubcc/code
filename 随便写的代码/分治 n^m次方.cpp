#include<stdio.h>
#include<iostream>
using namespace std; 

void RandomBigNumFun(int low,int high)                 //���ݲ���Ϊ������ָ��
{
	unsigned int temp[1024] = {0};                     //��ʼ��һ�����飬�������10000���Ƶ�����
	temp [0] = low;                                    //��ʼ����һ��Ԫ��Ϊ��Ҫ��ֵ��
	int flag = -1;                                     //��Ǳ���������ָʾ�Ƿ���Ҫ����һλ��λ��ͬ�±��������
	unsigned int m_count = 1;                          //�������������������б�ռ���˶��ٸ�Ԫ��
	int _index,index;                                  //����ѭ������
	for(_index = 0;_index <high-1; ++_index)           //ѭ��high-1�� ��Ϊ����temp[0]= low��
	{
		for(index = 0; index < m_count ; ++index)      //ѭ��m_count�Σ���ʵԭ�����԰���������ѭ����
		{                                              //ֻ������ʱ�ˣ���Ϊʵ����ֵ�ĵط�ֻ��m_count��
			temp[ index ] *= low;                      
			if(flag != -1)                             //�����һλ�Ƿ��������Ҫ���Լ���λ 
			{
				temp[index] += flag;
				flag = -1;                             //��λ֮������ǰѱ��������Ϊ-1
			}
			if(temp[index] > 9999)                     //�ж��Ƿ���Ҫ����һλ��λ
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
			printf("���ݹ���������С�������ô������Ĵ�С");
			exit(0);
		}
	}
	for(index = m_count-1;index >=0;--index)        //����ֵ��˵���������λ����1����Ҫ���0001����Ϊ��һ�����
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
