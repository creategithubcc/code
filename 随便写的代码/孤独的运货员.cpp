#include <stdio.h>
#include <string.h> 
#define N 70 
int matrix[N][N], truck[N], usedTime, sum; 
void UnLoad(int no, int storeCapacity)
{ 
for (int i = truck[0]; truck[0] && i > 0; i--) //��truck����ĩβ��ʼȡ������� 
{ 
	usedTime++; truck[0]--;//�����л���������1 
	if (no == truck[i]) //��ǰ�Ļ��������վ�����ͬ������Aƽ̨ 
	sum--; //�ܻ���������1 
	else if(matrix[no][0] < storeCapacity) //��ǰ���������վ��Ų�ͬ�Ҳֿ�δ����Ӧ�÷���Bƽ̨ 
	matrix[no][++matrix[no][0]] = truck[i];//�ѻ�������i����վ�Ķ�β 
	else //�Ȳ���װ��Aƽ̨Ҳ����װ��Bƽ̨ 
	{ usedTime--; truck[0]++; break; } 
} 
} 
void Load(int no, int carCapacity) 
{ 
int j = matrix[no][0], i;
for (i = 1; i <= j && truck[0] < carCapacity; i++)//�Ӳֿ����ͷ��ȡ��������뵽����β�� 
{ 
	usedTime++; 
	truck[++truck[0]] = matrix[no][i]; 
	matrix[no][0]--; 
} 
if (matrix[no][0]) 
for (int k = i; k <= j; k++) //�ƶ�����Ԫ�أ��ѿ�λ��ȥ 
matrix[no][k - i + 1] = matrix[no][k]; 
} 
void Transport(int stations, int carCapacity, int storeCapacity) 
{ 
	int i = 1, j, k; 
	while (1) //��վ��Ŵ�1��ʼ 
	{ 
		if (truck[0] > 0 && matrix[i][0] <= storeCapacity) //�ж��Ƿ����ж����matrix[i][0]�д�ŵ��ǵ�i����վ�л��������,truck[0]��ŵ��ǻ����л�������� 
		UnLoad(i, storeCapacity); 
		if (!sum) 
		return;//���������Ϊ0��ֱ�ӷ��� 
		if (truck[0] < carCapacity && matrix[i][0] > 0) //�ж��Ƿ����װ�� 
		Load(i, carCapacity); 
		usedTime += 2; 
		i = (i + 1) % (stations + 1) == 0 ? 1 : (i + 1) % (stations + 1); 
	} 
} 
int main() 
{ 
freopen("in.txt", "r", stdin); 
int n,stations,carCapacity,storeCapacity,testNumbers,i = 0,j,k; 
scanf("%d", &testNumbers); 
while(testNumbers--) 
{ 
	sum = 0, usedTime = 0, i = 1; 
	scanf("%d %d %d", &stations, &carCapacity, &storeCapacity); 
	while (i <= stations) 
	{ 
		scanf("%d", &matrix[i][0]); 
		sum += matrix[i][0]; //���������ܼ��� 
		for (j = 1; j <= matrix[i][0]; j++) 
		scanf("%d", &matrix[i][j]);
		i++; 
	} 
	Transport(stations, carCapacity, storeCapacity); 
	printf("%d\n", usedTime); 
} 
return 0; 
} 
