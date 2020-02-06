/**********************
 * 排序算法：
 * 1. 插入类排序
 *     直接插入排序
 *     折半插入排序
 *     希尔排序
 * 2. 交换类排序
 *     冒泡排序
 *     快速排序
 * 3. 选择类排序
 *     简单选择排序
 *     堆排序
 * 4. 归并排序
 *     二路归并排序
 *     多路归并排序
 * 5. 基数排序
 *     最高位优先
 *     最低位优先
 * 
 */


// 直接插入排序
#include<stdlib.h>

void InsertSort(int R[], int n)      //待排序关键字存储在R[]中，默认为整型，个数为n
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)    //默认第一个元素是有序的
    {
        temp = R[i];     //将待插入关键字暂存在temp中
        j=i-1;     //从后往前比较
        while(R[j]>temp&&j>=0)
        {
            R[j+1] = R[j];      //移动元素
            j--;
        }
        R[j+1] = temp;   //找到插入位置，将temp中暂存的待排序关键字插入
    }
}



// 折半插入排序
void BinInsertSort(int R[], int n)
{
    int i,j;
    int low,high,mid;
    int temp;
    for(i=1;i<n;i++)
    {
        temp = R[i];
        low = 0;high=i-1;
        // 下面是折半查找
        while(low<=high)
        {
            mid = (low+high)/2;
            if(temp<R[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        // 集中进行元素右移
        for(j=i-1;j>mid;j--)
            R[j+1] = R[j];
        R[mid+1] = temp;
    }
}



//  希尔排序
void Shellsort(int R[], int n)
{
    int i,j,increamnet;
    int temp;
    for(increamnet = n/2; increamnet>0;increamnet/=2)
    {
        for(i=increamnet;i<n;i++)
        {
            temp = R[i];
            for(j=i;j>=increamnet;j-=increamnet)     // 对间隔increamnet个元素进行插入排序
            {
                if(temp<R[j-increamnet])
                    R[j] = R[j-increamnet];
                else    break;
            }
            R[j] = temp;
        }
    } 
}

void Shellsort1(int R[],int n)
{
    int i,j,increamnet;
    int temp;
    increamnet = n/2;   // 增量置初值
    while(increamnet>0)
    {
        for(i=increamnet;i<n;i++)
        {
            temp = R[i];       // 对相隔increament个位置采用直接插入排序
            j = i-increamnet;
            while(j>=0 && temp < R[j])
            {
                R[j+increamnet] = R[j];
                j = j-increamnet;
            }
            R[j+increamnet] = temp;
        }
        increamnet /= 2;   // 增量减小二分之一 
    }
}



// 冒泡排序
void BubbleSort(int R[], int n)  //将R中元素按从小到大排序
{
    int i,j,flag;
    int temp;
    for(i=n-1;i>=1;--i)
    {
        flag = 0;   //变量flag用来标记本趟排序是否发生了交换
        for(j=1;j<=i;++j)
        {
            if(R[j-1]>R[j])
            {
                temp = R[j];
                R[j] = R[j-1];
                R[j-1] = temp;
                flag = 1;       //如果没发生交换，则flag为0；如果发生交换，则flag=1
            }
        }
        if(flag==0)
            return;
    }
}

// 快速排序
void QuickSort(int R[], int low, int high)
{
    int pivot;
    int i=low,j=high;
    // 下面是partition操作
    if(low<high)
    {
        pivot = R[low];   // 取第一个元素作为pivot
        // 下面这个循环完成了一趟排序，即将数组中小于pivot的关键字放在左边，将大于pivot的关键字放在右边
        while(i<j)
        {
            while(j>i && R[j]>pivot) --j;    // 从右往左扫描，找到一个小于pivot的关键字
            if(i<j)
            {
                R[i] = R[j];
                ++i;
            }
            while(j>i && R[i]<pivot) ++i;
            if(i<j)
            {
                R[j] = R[i];
                --j;
            }
        }
        R[i] = pivot;   // 每一次排序总会使pivot放在最终位置
        // 递归调用
        QuickSort(R,low,i-1);
        QuickSort(R,i+1,high);
    }
}


// 选择排序
void SelectSort(int R[], int n)
{
    int i,j,k;
    int temp;
    for(i=0;i<n;i++)
    {
        k = i;   // k用来找最小值的下标
        for(j=i+1;j<n;j++)
            if(R[k]>R[j])
                k = j;
        // 交换
        temp = R[i];
        R[i] = R[k];
        R[k] = temp;
    }
}


// 堆排序算法
void Sift(int R[],int low, int high)      // 关键字的存储设定从数组下标为1开始
{
    int i=low, j=2*i;   // j为i的左孩子结点
    int temp = R[i];   
    while(j<=high)
    {
        if(j<high&&R[j]<R[i+1])    // 让左孩子跟右孩子进行比较，将j赋值给数值较大的那个孩子的下标
            ++j;
        if(temp<R[j])
        {
            R[i] = R[j];    // 将R[j]调整到双亲的位置上
            i=j;
            j=2*i;     // 修改i个j的值
        }
        else    break;
    }
    R[i] = temp;
}

// 堆排序算法
void HeapSort(int R[], int n)
{
    int i;
    int temp;
    // 建立初始堆
    for(i=n/2;i>=1;--i)
        Sift(R, i, n);
    for(i=n;i>=2;--i)    // 进行n-1次循环，完成堆排序
    {
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        Sift(R,1,i-1);
    }
}


// 归并排序
void Merge(int R[],int low,int mid,int high)
{
    int *R1;
    int i=low,j=mid+1,k=0;
    R1 = (int *)malloc(high-low+1)*sizeof(int);

}
