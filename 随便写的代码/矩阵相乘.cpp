#include<stdio.h>
int main()
{
	int matrix1[100][100], matrix2[100][100],matrix3[100][100];
	int i,j,k,a_line,a_list,b_line,b_list;
	printf("请输入第一个矩阵的行列:"); 
	scanf("%d %d",&a_line,&a_list);
	for(i=0;i<a_line;i++)
	{
		for(j=0;j<a_list;j++)
		{
			printf("请输入从左到右从上到下的矩阵数字："); 
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("请输入第二个矩阵的行列:"); 
	scanf("%d %d",&b_line,&b_list);
	for(i=0;i<b_line;i++)
	{
		for(j=0;j<b_list;j++)
		{
			printf("请输入从左到右从上到下的矩阵数字："); 
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
