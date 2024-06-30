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
//以2进一个1,2^1(10)=010(2),2^2(10)=100(2),2^3(10)=1000(2)

    int mask[10];
    memset(mask, 0, sizeof(mask));

    for (int i = 0, n = strlen(rings); i < n; i += 2) {
        int c = rings[i];   //获取颜色
        int j = rings[i + 1] - '0';     //获取位置，这里-'0'是获取位置的数字，因为char类型的数字是ASCII码值，所以需要减去'0'来获取数字
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
//----------------------------------------------------
//1377
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b)      //从小到大排序
{
    return *(int*)a - *(int*)b;         //返回负数不换位置
}
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) 
{
    int *ret = malloc(sizeof(int) * k);         //ret数组用于表示
    int *hash = malloc(sizeof(int) * matSize);
    for(int i = 0; i < matSize; i++)
    {
        int count = 0;
        for(int j = 0; j < * matColSize; j++)
        {
            if(mat[i][j] == 1)
            {
                count++;
            }
        }
        hash[i] = count * 100 + i;  //方便找索引
// 第 0 行：2 个军人，hash[0] = 2 * 100 + 0 = 200
// 第 1 行：4 个军人，hash[1] = 4 * 100 + 1 = 401
// 第 2 行：1 个军人，hash[2] = 1 * 100 + 2 = 102
// 第 3 行：2 个军人，hash[3] = 2 * 100 + 3 = 203
// 第 4 行：5 个军人，hash[4] = 5 * 100 + 4 = 504
//妙处在这，hash[i] = count * 100 + i;隐性地将索引和军人数量结合起来，在后面只需将hash[i] % 100 即可获取索引
//局限在当索引足够大时，大于100，hash[i]的结果可能会在含义上上被误解
    }
    qsort(hash, matSize, sizeof(int), comp);
    int j = 0;
    for(int i = 0; i < k; i++)
    {
        ret[j++] = hash[i] % 100;   //转化为索引
    }
    * returnSize = k;
    return ret;
}

//----------------------------------------------------
//1260
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int row, int* gridCol, int k, int* returnSize, int** returnCol)
{
    int col = *gridCol;
    *returnSize = row;
    *returnCol = (int*)malloc(sizeof(int) * row);
    int** ans = (int**)malloc(sizeof(int*) * row);      //用于储存位移k次后的矩阵的二维数组
    k %= (row * col);
    for(int i = 0; i < row; i++)    //行
    {
        (*returnCol)[i] = col;
        ans[i] = (int*)malloc(sizeof(int) * col);
        for(int j = 0; j < col; j++)        //列
        {       
            int id =  (row * col + i * col + j - k ) % (row * col);     //col是列数，
//为了更方便地处理矩阵中的元素，我们将二维矩阵的索引 (i, j) 转换为一维索引 i * col + j。这个索引表示当前元素在一维数组中的位置。
// i * col + j 将二维索引转换为一维索引。
// 减去 k 实现元素左移 k 次。
// 加上 row * col 防止负索引。
// 取模 % (row * col) 确保索引在有效范围内。
            ans[i][j] = grid[id / col][id % col];
            //这里的id/col是行，id%col是列,脑子里想矩阵就懂了
        }
    }
    return ans;
}

/*
*   Y(B)  x(A)
*   *     *
*   *     *

k=1

*   *(B)  Y(A)
x   *     *
*   *     *

你想要A位置的数据正确，那么就得让位置的Y移到A位置，那么这里得到需填充的值grid[id / col][id % col]的id值就得-k
*/

//----------------------------------------------------