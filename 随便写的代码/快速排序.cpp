#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int cutoff = 5;
int numbers[1000], mid=0, midnumbers[100];
void InsertSort(int num[],int left,int right)
{
    int temp, j;
    for(int i=left + 1; i<=right; i++){
        temp = num[i];
        for(j = i - 1;j >= 0 && num[j] > temp;j--)
        {
            num[j+1] = num[j];
        }
        if (j != i - 1)
            num[j+1] = temp;
    }
}
 
int  MidCheck(int numbers[], int left, int right)
{
    int mid = (left + right) / 2;
    int temp[3];
    temp[2] = numbers[right];
    temp[1] = numbers[mid];
    temp[0] = numbers[left];
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
            if(temp[i]>temp[j])
			{
                int a = temp[i];
                temp[i]=temp[j];
                temp[j]=a;
            }
    numbers[left] = temp[0];
    numbers[right] = temp[1];
    numbers[mid] = temp[2];
    
    return temp[1];
}
 
void Sort(int numbers[], int left, int right)
{
    if (right - left < cutoff)
    {
        InsertSort(numbers, left, right);
    }
    else
    {
        midnumbers[mid++] = MidCheck(numbers, left, right);
    
        int pivot = numbers[right];
        int i = left ,j = right-1;
        while(1)
        {
            while (i < j && numbers[i] < pivot)i++;
            while (i < j && pivot < numbers[j])j--;
            if (i < j)
            {
                int c = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = c;
                i++,j--;
            }
            else break;
        }
        if (numbers[i] >= pivot)
        {
            numbers[right] = numbers[i];
            numbers[i] = pivot;
        }
        Sort(numbers, left, i-1);
        Sort(numbers, i+1, right);
    }
}
int main() 
{
    int count = 0;
    char x[20];
    while(1){
        scanf("%s",x);
        if(strcmp(x,"#")==0)
            break;
        numbers[count++] = atoi(x);
    }
 
    Sort(numbers,0,count-1);
    
    printf("After Sorting:\n");
    for(int i=0;i<count;i++)
	{
        printf("%d ",numbers[i]);
    }
    printf("\nMedian3 Value:\n");
    if(mid > 0)
	{
        for(int i=0;i<mid;i++)
            printf("%d ",midnumbers[i]);
        printf("\n");
    }
    else 
	{
        printf("none\n");
    }
    return 1;
}
