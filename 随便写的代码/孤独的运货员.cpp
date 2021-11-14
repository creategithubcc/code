#include <stdio.h>
#include <string.h> 
#define N 70 
int matrix[N][N], truck[N], usedTime, sum; 
void UnLoad(int no, int storeCapacity)
{ 
for (int i = truck[0]; truck[0] && i > 0; i--) //从truck数组末尾开始取出“货物” 
{ 
	usedTime++; truck[0]--;//货车中货的数量减1 
	if (no == truck[i]) //当前的货物编号与货站编号相同，放入A平台 
	sum--; //总货物数量减1 
	else if(matrix[no][0] < storeCapacity) //当前货物编号与货站编号不同且仓库未满，应该放入B平台 
	matrix[no][++matrix[no][0]] = truck[i];//把货物加入第i个货站的队尾 
	else //既不能装入A平台也不能装入B平台 
	{ usedTime--; truck[0]++; break; } 
} 
} 
void Load(int no, int carCapacity) 
{ 
int j = matrix[no][0], i;
for (i = 1; i <= j && truck[0] < carCapacity; i++)//从仓库队列头部取出货物加入到货车尾部 
{ 
	usedTime++; 
	truck[++truck[0]] = matrix[no][i]; 
	matrix[no][0]--; 
} 
if (matrix[no][0]) 
for (int k = i; k <= j; k++) //移动数组元素，把空位消去 
matrix[no][k - i + 1] = matrix[no][k]; 
} 
void Transport(int stations, int carCapacity, int storeCapacity) 
{ 
	int i = 1, j, k; 
	while (1) //货站编号从1开始 
	{ 
		if (truck[0] > 0 && matrix[i][0] <= storeCapacity) //判断是否可以卸货，matrix[i][0]中存放的是第i个货站中货物的数量,truck[0]存放的是货车中货物的数量 
		UnLoad(i, storeCapacity); 
		if (!sum) 
		return;//如果货物数为0则直接返回 
		if (truck[0] < carCapacity && matrix[i][0] > 0) //判断是否可以装货 
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
		sum += matrix[i][0]; //计算货物的总件数 
		for (j = 1; j <= matrix[i][0]; j++) 
		scanf("%d", &matrix[i][j]);
		i++; 
	} 
	Transport(stations, carCapacity, storeCapacity); 
	printf("%d\n", usedTime); 
} 
return 0; 
} 
