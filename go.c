#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------------------
//2389
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

int getDigitSum(int num) {      //获取数字的各位数之和
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
// 加上 row * col 防止负索引。(i,j均为0时)
// 取模 % (row * col) 确保索引在有效范围内。
            ans[i][j] = grid[id / col][id % col];
            //这里的id/col是行，id%col是列,脑子里想矩阵就懂了
        }
    }
    return ans;
}

/*
*   Y(B)  X(A)
*   *     *
*   *     *

k=1

*   *(B)  Y(A)
X   *     *
*   *     *

你想要A位置的数据正确，那么就得让位置的Y移到A位置，那么这里得到需填充的值grid[id / col][id % col]的id值就得-k
*/

//----------------------------------------------------
//1122
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int index = 0;
    int hash[1001] = {0};
    for (int i = 0; i < arr1Size; ++i) {
        hash[arr1[i]]++;        //arr1中元素值作为index，出现个数作为hash[index]的值
    }
    //arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    for (int i = 0; i < arr2Size; ++i) {
        while (hash[arr2[i]] > 0) {     //再从arr2中找到arr2[i](设为X)，X作为hash的index(从0开始)赋值给arr1[index]的值，令再使hash[X]--
            arr1[index++] = arr2[i];
            hash[arr2[i]]--;
        }
    }

    for (int i = 0; i < 1001; ++i) {
        while (hash[i] > 0) {
            //如果arr2中没有的arr1中对应的元素，那么其值设为X。hash[X]值不为0。从0开始for循环，内部while判定若hash[X]>0就继续填充，顺便hash[X]--
            arr1[index++] = i;
            hash[i]--;
        }
    }

    *returnSize = arr1Size;
    //返回排好序的arr1
    return arr1;
}

//----------------------------------------------------
//1313
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    //nums[] = {1, 2, 3, 4};1个2,3个4
    int i, j, k, count;
    int *res;
    k = 0;
    count = 0;
    for (i = 0; i < numsSize; i += 2)
    {
        count += nums[i];
    }
    *returnSize = count;
    res = (int *)malloc(sizeof(int) * count);//为了符合题意(The returned array must be malloced)，需要提前开辟空间
    for (i = 1; i < numsSize; i += 2)       //i=1.3   num[i]就是要打印的值，num[i-1]就是要打印的次数
    {
        for (j = 0; j < nums[i - 1]; j++)       //打印num[i-1]次
        {
            res[k] = nums[i];
            k++;
        }
    }
    return res;
}
//----------------------------------------------------
//1351
int countNegatives(int **grid, int gridSize, int *gridColSize) {
    int ans = 0;
    int Row = gridSize;
    int Col = gridColSize[0];
    for (int i = 0; i < Row; i++) {
        int j = Col - 1;  // 从每行的最后一个元素开始
        while (j >= 0) {
            if(grid[i][j] < 0){ans++;}  //无需严格递减
            j--;
        }
    }
    return ans;
}
/*
//严格递减时
int countNegatives(int **grid, int gridSize, int *gridColSize) {
    int ans = 0;
    int Row = gridSize;
    int Col = gridColSize[0];
    for (int i = 0; i < Row; i++) {
        int j = Col - 1;  // 从每行的最后一个元素开始
        while (j >= 0) {
            if(grid[i][j] < 0){ans++;}
            j--;
        }
    }
    return ans;
}
*/

    //   |  --------------->ROW    行(子数组内元素个数)
    //   |  {4,  3,   2, -1}
    //   |  {3,  2,   1, -1}
    //   |  {1,  1,  -1, -2}
    //   V  {-1, -1, -2, -3}
    //  COL
    //  列(子数组个数)
//----------------------------------------------------
//1403
int cmp1(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) 
{
    qsort(nums, numsSize, sizeof(int), cmp1);
    int *temp = (int*)malloc(sizeof(int)*numsSize);
    temp[0] = nums[0];
    int sum = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        sum += nums[i];
        temp[i] = temp[i - 1] + nums[i];
        // temp保存前缀和
    }

    int index = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int small = sum - temp[i];
        if(small < temp[i])
        {
            index = i;
            break;
        }
    }
    free(temp);
    *returnSize = index + 1;//index+1是因为要返回的大小是 索引+1
    int* res = (int*)malloc(sizeof(int) * (index + 1));
    for(int i = 0; i <= index; i++)
    {
        res[i] = nums[i];
    }
    return res;
}
//----------------------------------------------------
//中等
//面试题 16.04. 井字游戏
char* tictactoe(char** board, int boardSize){
    //O   X
    //  X O
    //X   O
    //当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
    //统计每一行，每一列，对角线上面，‘O’和‘X’字符的个数
    //横
    int oCnt = 0;
    int xCnt = 0;
    for(int i = 0; i < boardSize;i++){
        oCnt = 0;
        xCnt = 0;
        for(int j = 0; j < boardSize;j++) {
            if(board[i][j] == 'O')
                oCnt++;
            else if(board[i][j] == 'X')
                xCnt++;
        }

        if(oCnt == boardSize || xCnt == boardSize)
            return oCnt == boardSize?"O":"X";
    }
    //竖
    for(int i = 0; i < boardSize;i++){
        oCnt = 0;
        xCnt = 0;
        for(int j = 0; j < boardSize;j++) {
            if(board[j][i] == 'O')
                oCnt++;
            else if(board[j][i] == 'X')
                xCnt++;
        }

        if(oCnt == boardSize || xCnt == boardSize)
            return oCnt == boardSize?"O":"X";
    }


    //对角线
    //正对角线
    oCnt = 0;
    xCnt = 0;
    for(int i = 0; i < boardSize;i++){
        if(board[i][i] == 'O')
            oCnt++;
        else if(board[i][i] == 'X')
            xCnt++;
    }

    if(oCnt == boardSize || xCnt == boardSize)
        return oCnt == boardSize?"O":"X";

    //反对角线
    oCnt = 0;
    xCnt = 0;
    for(int i = 0; i < boardSize;i++){
        if(board[i][boardSize - i - 1] == 'O')
            oCnt++;
        else if(board[i][boardSize - i - 1] == 'X')
            xCnt++;
    }

    if(oCnt == boardSize || xCnt == boardSize)
        return oCnt == boardSize?"O":"X";
    
    oCnt = 0;
    xCnt = 0;
    //判断是否有空位
    //合计O与X的个数
    for(int i = 0; i < boardSize;i++){
        for(int j = 0; j < boardSize;j++) {
            if(board[i][j] == 'O')
                oCnt++;
            else if(board[i][j] == 'X')
                xCnt++;
        }
    }

    printf("%d %d %d\n",oCnt,xCnt,boardSize * boardSize);
    //走到这里，说明还没有玩家获胜
    return oCnt + xCnt == boardSize * boardSize?"Draw":"Pending";

};
//----------------------------------------------------
//面试题 17.09. 第 k 个数
int getKthMagicNumber(int k) {
    if (k <= 0) return 0;

    int* magicNumbers = (int*)malloc(k * sizeof(int));
    magicNumbers[0] = 1;
    int index3 = 0, index5 = 0, index7 = 0;

    for (int i = 1; i < k; ++i) {
        int next3 = magicNumbers[index3] * 3;
        int next5 = magicNumbers[index5] * 5;
        int next7 = magicNumbers[index7] * 7;

        int nextMagicNumber = (next3 < next5) ? ((next3 < next7) ? next3 : next7) : ((next5 < next7) ? next5 : next7);
        magicNumbers[i] = nextMagicNumber;

        if (nextMagicNumber == next3) ++index3;
        if (nextMagicNumber == next5) ++index5;
        if (nextMagicNumber == next7) ++index7;
    }

    int result = magicNumbers[k - 1];
    free(magicNumbers);

    return result;
}
//----------------------------------------------------
//LRC 166. 珠宝的最高价值
int jewelleryValue(int** grid, int gridSize, int* gridColSize){
    int m=gridSize,n=gridColSize[0];
    int f[m][n];
    memset(f,0,sizeof(f));
    //从左上角开始(0,0)
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //i>0说明已经上面有元素
            if(i>0){
                f[i][j]=f[i][j]>f[i-1][j]?f[i][j]:f[i-1][j];
            }
            if(j>0){
            //j>0说明以及左边有元素
                f[i][j]=f[i][j]>f[i][j-1]?f[i][j]:f[i][j-1];
            }
            //f[i][j]的值是上面和左边的的最大的一边
            f[i][j]+=grid[i][j];
        }
    }
    return f[m-1][n-1];
}
//----------------------------------------------------
//81
#include <stdbool.h>
bool search(int* nums, int numsSize, int target) {
    int i;
    for(i = 0; i< numsSize;i++){
        if(nums[i] == target)
        {return true;}
    }
    return false;
}
//----------------------------------------------------
//91
int numDecodings(char* s) {
    int length = strlen(s);
    int i, k, n = length + 1;
    int dp[n], nums[n];
    dp[0] = 1;
    // 字符数组化为整数数组
    for (i = 1; i < n; i++) { 
        dp[i] = 0;
        nums[i] = s[i - 1] - 48;
    }
    if (nums[1] == 0) {
        return 0;
    } else {
        dp[1] = 1;
    }

    for (i = 2; i < n; i++) {

        k = nums[i - 1] * 10 + nums[i];
        if (nums[i] == 0 && (k >= 30 || k == 0)) { 
            // 1.第i位单独解释不了(即等于0)，加上前一位也还是解释不了(此时前一位>=3)，则无解
            return 0; 
        } else if (nums[i] == 0) { 
            // 2.第i位单独解释不了，但是加上前一位可以解释
            dp[i] = dp[i - 2]; //这两个数必放一起解释

        } else if (nums[i] != 0) { 
            // 3.第i位单独可以解释
            if (k > 26 || k < 10) {
                // 3.1加上前一位不行
                dp[i] = dp[i - 1];//这一个数必须单独解释
            } else {
                // 3.2加上前一位可以
                dp[i] = dp[i - 1] + dp[i - 2];//这个i-2是倒数第二位与倒数第一位连体后的解释数
            }
        }
    }
    return dp[n - 1];
}
//----------------------------------------------------
//2065
int map[1002][4][2];
int length[1002];
int *V;
int path[1002];
int max;
void dfs(int pos,int start,int value,int len,int bound){
    // pos: 当前节点的位置。
    // start: 起始节点（在这里是节点 0）。
    // value: 当前路径的价值。
    // len: 当前路径的总时间。
    // bound: 最大允许的时间，即 maxTime。
    int i,FLAG=0;
    if(path[pos]==0){value+=V[pos];path[pos]=1;FLAG=1;}
    if(pos==start){
        max=fmax(max,value);
    }
    for(i=0;i<length[pos];i++){
        if(len+map[pos][i][1]>bound)continue;
        else dfs(map[pos][i][0],start,value,len+map[pos][i][1],bound);
    }
    if(FLAG==1)path[pos]=0;
    return ;
}


int maximalPathQuality(int* values, int valuesSize, int** edges, int edgesSize, int* edgesColSize, int maxTime){
    //memset(map,0,sizeof(map)); 
    memset(length,0,sizeof(length)); 
    V=values;
     int i,j,k,res=0;
    for(i=0;i<edgesSize;i++){
        int left=edges[i][0],right=edges[i][1],len=edges[i][2];
        map[left][length[left]][0]=right;  map[left][length[left]++][1]=len; 
        map[right][length[right]][0]=left;  map[right][length[right]++][1]=len;
    }
        max=0; dfs(0,0,0,0,maxTime);
        res=fmax(res,max);
    return res;
}
//----------------------------------------------------
//3099
int sumOfTheDigitsOfHarshadNumber(int x) {
    int s = 0;
    for (int v = x; v; v /= 10) {   //取最后一位
        s += v % 10;
        // 计算 x 的各位数字之和
    }
    return x % s ? -1 : s;      //x%s==0则返回s，否则返回-1
}
//----------------------------------------------------
//589
struct Node {
    int val;
    int numChildren;        //子节点个数
    struct Node** children;     //指向子节点的指针数组，因为子节点同样需要储存数据，也是Node类型
};


#define MAXN 10000
static int buff[MAXN], next;

int* helper(struct Node *root);

int* preorder(struct Node *root, int *returnSize) {
    next = 0;
    helper(root);
    int *res = (int*)malloc(sizeof(int) * next);
    memcpy(res, buff, sizeof(int) * next);
    *returnSize = next;
    return res;
}

int* helper(struct Node *root) {
    if (!root) return NULL;
    buff[next++] = root->val;
    for (int i = 0; i < root->numChildren; ++i)
        helper(root->children[i]);
    return buff;
}
//----------------------------------------------------
//225
#define TAK_LEN 101
typedef struct {
    int *head;
    int *tail;
} MyStack;

MyStack* myStackCreate() {
    MyStack *obj = malloc(sizeof(MyStack));
    obj->head = malloc(sizeof(int) * TAK_LEN);
    obj->tail = obj->head;
    return obj;
}
void myStackPush(MyStack* obj, int x) {
    if (obj->tail == obj->head + TAK_LEN - 1)
        return;
    
    obj->tail++;        // 移动 tail 指针
    //tail 向前移动一个位置，arr[1] 存储元素 1：
    *(obj->tail) = x;    // 将新元素存储在新的 tail 位置
}
int myStackPop(MyStack* obj) {
    int tmp;
    if (obj->tail == obj->head)
        return 0;

    tmp = *(obj->tail);
    obj->tail--;
    return tmp;
}
int myStackTop(MyStack* obj) {
    return *(obj->tail);
}
bool myStackEmpty(MyStack* obj) {
    if (obj->head == obj->tail)
        return true;
    
    return false;
}
void myStackFree(MyStack* obj) {
    free(obj->head);
    free(obj);
}
// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false
/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
//-----------------------------------------------------
//232
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
typedef struct {
    int* stk;   // 栈
    int stkSize;    // 栈容量
    int stkCapacity;    // 栈顶
} Stack;
Stack* stackCreate(int cpacity) {         // 初始化栈
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}
void stackPush(Stack* obj, int x) {     // 入栈
    obj->stk[obj->stkSize++] = x;
}
void stackPop(Stack* obj) {         // 出栈
    obj->stkSize--;
}
int stackTop(Stack* obj) {          // 栈顶
    return obj->stk[obj->stkSize - 1];
}
bool stackEmpty(Stack* obj) {        // 判空
    return obj->stkSize == 0;
}
void stackFree(Stack* obj) {         // 释放栈
    free(obj->stk);
}

typedef struct {        // 队列
    Stack* inStack;      // 输入栈
    Stack* outStack;        // 输出栈
} MyQueue;
MyQueue* myQueueCreate() {         // 初始化队列
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}
void in2out(MyQueue* obj) {      // 将输入栈中的元素全部弹出并压入输出栈
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}
void myQueuePush(MyQueue* obj, int x) {      // 元素 x 入队
    stackPush(obj->inStack, x);
}
int myQueuePop(MyQueue* obj) {      // 队首元素出队(out stack)
    if (stackEmpty(obj->outStack)) {    //若输出栈为空，则将输入栈中的元素全部弹出并压入输出栈
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);        // 弹出输出栈的栈顶元素
    return x;
}
int myQueuePeek(MyQueue* obj) {      // 队首元素
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}
bool myQueueEmpty(MyQueue* obj) {        // 判空
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}
void myQueueFree(MyQueue* obj) {         // 释放队列
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}
//----------------------------------------------------
//2129
#include <ctype.h>
char * capitalizeTitle(char * title){
    int len = strlen(title);
    int j = 0;
    for (int i = 0; i <= len; i++) {
        if (title[i] == ' ' || title[i] == '\0') {
            if (i - j > 2) {
                title[j] = toupper(title[j]); /* 转为大写 */
                //在使用 toupper 和 tolower 函数之前，需要包含标准库头文件 <ctype.h>
            }
            j = i + 1; /* 更新起始位置 */
            // 跳过空格或换行符 title[i] == ' ' || title[i] == '\0'
        } else {
            title[i] = tolower(title[i]); /* 其余转为小写 */
        }
    }
    return title;
}
//----------------------------------------------------
//303
typedef struct {
    int* presum;
    int size;
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj=(NumArray*)malloc(sizeof(NumArray));
    obj->presum=(int*)malloc((numsSize+1)*sizeof(int));     //这里的+1是为了防止数组越界
    obj->size=numsSize+1;
    obj->presum[0]=0;
    for(int i=1;i<obj->size;i++)
    {
        obj->presum[i]=obj->presum[i-1]+nums[i-1];
    }
    return obj;
}
int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->presum[right+1]-obj->presum[left];
}
void numArrayFree(NumArray* obj) {
    free(obj->presum);
    free(obj);
}
/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
//----------------------------------------------------
//2908
#include <limits.h>

int minimumSum(int* nums, int numsSize) {
    if (numsSize < 3) return -1;

    int leftMin[numsSize], rightMin[numsSize];
//INT_MAX 是一个宏定义，表示整型变量可以表示的最大值。在大多数系统中，INT_MAX 的值为 2147483647，即 32 位有符号整数的最大值。
    leftMin[0] = INT_MAX;
    rightMin[numsSize - 1] = INT_MAX;

    // Fill leftMin array
    for (int i = 1; i < numsSize; i++) {
        leftMin[i] = (nums[i - 1] < leftMin[i - 1]) ? nums[i - 1] : leftMin[i - 1];
    }

    // Fill rightMin array
    for (int i = numsSize - 2; i >= 0; i--) {
        rightMin[i] = (nums[i + 1] < rightMin[i + 1]) ? nums[i + 1] : rightMin[i + 1];
    }

    int minSum = INT_MAX;
    int found = 0;

    // Find the minimum sum of mountain triplets
    //这里i=1,numsSize-1是为了循环中间元素
    for (int j = 1; j < numsSize - 1; j++) {
        if (nums[j] > leftMin[j] && nums[j] > rightMin[j]) {
            int currentSum = nums[j] + leftMin[j] + rightMin[j];
            if (currentSum < minSum) {
                minSum = currentSum;
                found = 1;
            }
        }
    }

    return found ? minSum : -1;
}
//----------------------------------------------------
//3086
int f(int i, int *nums, int numsSize) {
    int x = nums[i];
    if (i - 1 >= 0) {
        x += nums[i - 1];
    }
    if (i + 1 < numsSize) {
        x += nums[i + 1];
    }
    return x;
}

long long minimumMoves(int* nums, int numsSize, int k, int maxChanges) {
    int n = numsSize;

    long long *indexSum = (long long *)malloc(sizeof(long long) * (n + 1)), *sum = (long long *)malloc(sizeof(long long) * (n + 1));
    for (int i = 0; i < n; i++) {
        indexSum[i + 1] = indexSum[i] + nums[i] * i;
        sum[i + 1] = sum[i] + nums[i];
    }
    long long res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (f(i, nums, n) + maxChanges >= k) {
            if (k <= f(i, nums, n)) {
                res = fmin(res, (long long)k - nums[i]);
            } else {
                res = fmin(res, (long long)2 * k - f(i, nums, n) - nums[i]);
            }
            continue;
        }
        int left = 0, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i1 = fmax(i - mid, 0), i2 = fmin(i + mid, n - 1);
            if (sum[i2 + 1] - sum[i1] >= k - maxChanges) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int i1 = fmax(i - left, 0), i2 = fmin(i + left, n - 1);
        if (sum[i2 + 1] - sum[i1] > k - maxChanges) {
            i1++;
        }
        long long count1 = sum[i + 1] - sum[i1], count2 = sum[i2 + 1] - sum[i + 1];
        res = fmin(res, indexSum[i2 + 1] - indexSum[i + 1] - i * count2 + i * count1 - (indexSum[i + 1] - indexSum[i1]) + 2 * maxChanges);
    }
    free(indexSum);
    free(sum);
    return res;
}
//----------------------------------------------------
//70
int climbStairs(int n){
    if(n == 0) 
        return 0;
    int i = 0;
    int p = 0;
    int q = 0;  //p,q分别表示n-1,n-2阶台阶的不同走法
    int res = 1;
    while(i < n){
        p = q;      //n-2阶台阶的走法
        q = res;        //n-1阶台阶的走法
        res = p+q;      //n阶台阶的走法

    //     n-1  n-2     n
        //&q = 1,p = 0,*res = 1
        //*q = 1,&p = 1,res = 2
        //q = 2,p = 1,res = 3
        //q = 1,p = 1,res = 2
        //q = 2,p = 1,res = 3
        //q = 3,p = 2,res = 5
        //q = 5,p = 3,res = 8
        //q = 8,p = 5,res = 13
        //q = 13,p = 8,res = 21
        //q = 21,p = 13,res = 34
        i++;
    }
    return res;
}
//----------------------------------------------------
//509
//斐波那契数列
int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    int p = 0, q = 0, r = 1;
    //p是n-2项，q是n-1项，r是n项
    for (int i = 2; i <= n; ++i) {
        p = q;
        q = r;  //前两位已就位，1,1
        r = p + q;
    }
    return r;
}
//----------------------------------------------------
//1137
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    
    int a = 0, b = 1, c = 1, d;
    for (int i = 3; i <= n; ++i) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}
//----------------------------------------------------
//746
int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 0) return 0;
    if (costSize == 1) return cost[0];

    int dp[costSize + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= costSize; ++i) {
        dp[i] = (dp[i-1] + cost[i-1] < dp[i-2] + cost[i-2]) ? dp[i-1] + cost[i-1] : dp[i-2] + cost[i-2];
    }

    return dp[costSize];
}
//----------------------------------------------------
