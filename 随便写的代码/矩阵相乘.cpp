#include<stdio.h>
int main()
{
	int matrix1[100][100], matrix2[100][100],matrix3[100][100];
	int i,j,k,a_line,a_list,b_line,b_list;
	printf("�������һ�����������:"); 
	scanf("%d %d",&a_line,&a_list);
	for(i=0;i<a_line;i++)
	{
		for(j=0;j<a_list;j++)
		{
			printf("����������Ҵ��ϵ��µľ������֣�"); 
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("������ڶ������������:"); 
	scanf("%d %d",&b_line,&b_list);
	for(i=0;i<b_line;i++)
	{
		for(j=0;j<b_list;j++)
		{
			printf("����������Ҵ��ϵ��µľ������֣�"); 
			scanf("%d",&matrix2[i][j]);
		}
	}
	for(i=0;i<a_line;i++)
	{
		for(j=0;j<b_list;j++)
		{
			matrix3[i][j]=0;
			for(k=0;k<a_list;k++)
			{
				matrix3[i][j]=matrix3[i][j]+matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	for(i=0;i<a_line;i++)
	{
		for(j=0;j<b_list;j++)
		{
			printf("%d ",matrix3[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
