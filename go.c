#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------
// 比较函数，用于 qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);       //升序排列
}
int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    //nums = [4,5,2,1], queries = [3,10,21]
    qsort(nums, numsSize, sizeof(int), cmp);
    //此时nums = [1,2,4,5]，queries = [3,10,21]
    for(int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];
    //此时nums = [1,3,7,12]，queries = [3,10,21]
    for(int i = 0; i < queriesSize; i++){       //执行queries长度次，每次都queries[i]与nums进行比较，找到第一个num小于等于queries[i]
        int left = 0, right = numsSize - 1;//3
        while(left <= right){
            int mid = left + (right - left) / 2;//中间位置  在 C 语言中，整数除法会自动向下取整，因此 mid = left + (right - left) / 2 的结果是一个整数
            if(nums[mid] <= queries[i])
                left = mid + 1; //1+1    2+1    3+1
            else               //这里调整left，right是为了下一次的二分查找(mid = left + (right - left) / 2)
                right = mid - 1;
        }
        queries[i] = left; 
    }
    *returnSize = queriesSize;

    return queries;//[2,3,4]
}

//----------------------------------------------------
//2180

int getDigitSum(int num) {      //获取数字的各位数之和。
    int sum = 0;
    while (num > 0) {
        sum += num % 10;        //获取 num 的最后一位数字。
        num /= 10;      //然后 num 除以 10 去掉最后一位数字,c语言中 / 会自动向下取整
        // 循环继续，直到 num 为 0 为止
    }
    return sum;
}

int countEven(int num) {
    int even = 0;
    for (int i = 1; i <= num; i++) {
        if (getDigitSum(i) % 2 == 0) {
            even++;         //符合条件，even++
        }
    }
    return even;
} 

//----------------------------------------------------
//2215

// 函数功能：找到两个整数数组之间的差异。它接受两个整数数组 nums1 和 nums2，以及它们的大小 nums1Size 和 nums2Size。
// 返回值：返回一个二维整数指针，第一维表示在 nums1 中存在但不在 nums2 中的数字，第二维表示在 nums2 中存在但不在 nums1 中的数字。
// 参数：返回值的大小由 returnSize 指针指向的整数表示，返回的列大小（即每个子数组的大小）由 returnColumnSizes 指针指向的整数指针数组表示。
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int hash1[2001] = { 0 };
    int hash2[2001] = { 0 };
    int** ans = (int**)malloc(sizeof(int*)*2);
    ans[0] = (int*)malloc(sizeof(int)*nums1Size);   //二维数组0行的列数，用于储存nums1中不同于num2的数字
    ans[1] = (int*)malloc(sizeof(int)*nums2Size);   //二维数组1行的列数，用于储存nums2中不同于num1的数字

    int diff1 = 0;      //初始化diff1和diff2为0
    int diff2 = 0;
    //nums1 = [1,2,3], nums2 = [2,4,6]
    int i = 0;
    for (i = 0; i < nums2Size; i++)
    {
        //填充 hash1,遍历 nums2，将每个元素的值映射到 hash1 中,如：hash1[1000-2] = 1
        hash1[1000-nums2[i]] += 1;
    }

    for (i = 0; i < nums1Size; i++)
    {
        //填充 hash2,遍历 nums1，将每个元素的值映射到 hash2 中,如：hash2[1000-1] = 1
        hash2[1000-nums1[i]] += 1;
    }
    //
    for (i = 0; i < nums1Size; i++)       //遍历 nums1
    {
        if (hash1[1000-nums1[i]] == 0)  //如果hash1[1000-nums1[i]] == 0,说明nums1[i]不在nums2中 
        {
            ans[0][diff1++] = nums1[i];     //将nums1[i]加入ans[0][diff1++]中
            hash1[1000-nums1[i]] += 1;      //将nums1[i]加入hash1中,防止重复添加
        }
    }

    for (i = 0; i < nums2Size; i++)
    {
        if (hash2[1000-nums2[i]] == 0)      //如果hash2[1000-nums2[i]] == 0,说明nums2[i]不在nums1中
        {
            ans[1][diff2++] = nums2[i];     //将nums2[i]加入ans[1][diff2++]中
            hash2[1000-nums2[i]] += 1;      //将nums2[i]加入hash2中,防止重复添加
        }
    }    

    *returnColumnSizes = (int*)malloc(sizeof(int)*2);       

    (*returnColumnSizes)[0] = diff1;
    (*returnColumnSizes)[1] = diff2;
    
    *returnSize = 2;
    return ans;         //返回ans
}

//----------------------------------------------------
//1971
// #include <stdbool.h>
// int setFind(int *set,int u){
//     if(u==set[u])return u;
//     else return set[u]=setFind(set,set[u]); //再次寻找其根节点
// }
// bool isSameSet(int *set,int u, int v){
//     u=setFind(set,u);
//     v=setFind(set,v);
//     return u==v;
// }
// void setJoin(int *set, int u, int v){   //如传入参数set[0]=0,u=0,v=1,则set[0]=1
//     u=setFind(set,u);
//     v=setFind(set,v);
//     if(u==v)return;     
//     set[u]=v;
// }
// bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
//     //传入参数n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
//     int *set=malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++)set[i]=i;   //初始化并查集，[0,],[1,],[2,],[3,],[4,]..
//     for(int i=0;i<edgesSize;i++) setJoin(set,edges[i][0],edges[i][1]);      //循环edges，将edges中的两个元素加入并查集中,[0,1],[1,2],[2,0]
//     return isSameSet(set,source,destination);       //判断是否在同一个集合
// }

//----------------------------------------------------
//2103
#include <string.h>
int countPoints(char* rings) {
    int d['Z'];     //这里的'z'是ASCII码表中Z的ASCII码值，为90，目的是设置d的大小以容纳所有可能的颜色
    memset(d, 0, sizeof(d));
    d['R'] = 1;     //这里将R的ASCII码值(82)映射特定的位标志（1, 2, 4）
    d['G'] = 2;
    d['B'] = 4;
// d['R'] = 1; 表示红色环的位标志为 1（二进制 001）。
// d['G'] = 2; 表示绿色环的位标志为 2（二进制 010）。
// d['B'] = 4; 表示蓝色环的位标志为 4（二进制 100）。

    int mask[10];
    memset(mask, 0, sizeof(mask));

    for (int i = 0, n = strlen(rings); i < n; i += 2) {
        int c = rings[i];
        int j = rings[i + 1] - '0';
        mask[j] |= d[c];
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (mask[i] == 7) {
            ans++;
        }
    }

    return ans;
}