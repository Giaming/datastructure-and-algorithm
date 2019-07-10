

// 顺序查找法
int Search(int a[], int n, int k)
{
    for(int i=1;i<n;i++)
        if(a[i]==k)
            return (i+1);
    return 0;
}


// 折半查找法
int BSearch(int R[], int low, int high, int k)
{
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(R[mid]==k)
            return mid;      
        else if(R[mid]>k)
            high = mid-1;
        else    
            low = mid+1;
    }
    return 0;
}