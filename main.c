#include <stdio.h>
#include <stdlib.h>
#include "go.c"
#include "new.c"

//----------------------------------------------------

// int main(){
//     swit();
// }

//----------------------------------------------------

// 2389
// int main() {
//     int nums[] = {4, 5, 2, 1};
//     int queries[] = {3, 10, 21};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int queriesSize = sizeof(queries) / sizeof(queries[0]);
//     int returnSize;
//     // 调用 answerQueries 函数
//     //int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
//     //返回的类型是 int*，即一个指向整数数组的指针。
//     int* result = answerQueries(nums, numsSize, queries, queriesSize, &returnSize);
//     // 打印结果
//     printf("Result: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     return 0;
// }

//----------------------------------------------------

// 2180
// int main() {
//     int num = 4;
//     int result = countEven(num);
//     printf("The number of integers less than or equal to %d with an even digit sum is: %d\n", num, result);
//     return 0;
// }

//----------------------------------------------------

// 2215
// int main() {
//     int nums1[] = {1, 2, 3};
//     int nums2[] = {2, 4, 6};
//     int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
//     int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
//     int returnSize;     //返回的二维数组元素个数
//     int* returnColumnSizes;         //返回的列大小(每个子数组的大小)

//     // 调用 findDifference 函数
//     int** result = findDifference(nums1, nums1Size, nums2, nums2Size, &returnSize, &returnColumnSizes);

//     // 打印结果
//     printf("Result:[");
//     for (int i = 0; i < returnSize; i++) {
//         printf("[");
//         for (int j = 0; j < returnColumnSizes[i]; j++) {
//             printf("%d", result[i][j]);
//             if (j < returnColumnSizes[i] - 1) {
//                 printf(", ");
//             }
//         }
//         printf("]");
//     }
//     printf("]\n");

//     // 释放内存
//     for (int i = 0; i < returnSize; i++) {
//         free(result[i]);
//     }
//     free(result);
//     free(returnColumnSizes);

//     return 0;
// }

//----------------------------------------------------
// 1971
// int main() {
//     int n = 3;
//     int edgesSize = 3;                  // 二维数组的行数(子数组个数)
//     int edgesColSize[] = {2, 2, 2};    // 二维数组的列数(元素个数)
//     int source = 0;         // 起点
//     int destination = 2;        // 终点

//     // 动态分配二维数组 edges
//     int** edges = (int**)malloc(edgesSize * sizeof(int*));
//     for (int i = 0; i < edgesSize; i++) {
//         edges[i] = (int*)malloc(2 * sizeof(int));
//     }

//     // 初始化 edges 数组
//     edges[0][0] = 0; edges[0][1] = 1;
//     edges[1][0] = 1; edges[1][1] = 2;
//     edges[2][0] = 2; edges[2][1] = 0;

//     // 调用 validPath 函数
//     bool result = validPath(n, edges, edgesSize, edgesColSize, source, destination);

//     // 打印结果
//     printf("Is there a valid path from %d to %d? %s\n", source, destination, result ? "true" : "false");

//     // 释放内存
//     for (int i = 0; i < edgesSize; i++) {
//         free(edges[i]);
//     }
//     free(edges);

//     return 0;
// }

//-----------------------------------------------------
//2103

// int main() {
//     char rings[] = "B0B6G0R6R0R6G9";
//     int result = countPoints(rings);
//     printf("Number of rods with all three colors: %d\n", result);
//     return 0;
// }

//-----------------------------------------------------
//1377
// int main() {
//     // 示例 1 输入
//     int mat[5][5] = {
//         {1, 1, 0, 0, 0},
//         {1, 1, 1, 1, 0},
//         {1, 0, 0, 0, 0},
//         {1, 1, 0, 0, 0},
//         {1, 1, 1, 1, 1}
//     };
//     int matSize = 5;    // 二维数组的行数
//     int matColSize = 5;     // 二维数组的列数
//     int k = 3;          // 要返回的结果的数量
//     int returnSize;         // 返回的结果的数量

//     // 转换为指针数组
//     int* matPtr[5];
//     for (int i = 0; i < 5; i++) {
//         matPtr[i] = mat[i];
//     }

//     // 调用函数
//     int* result = kWeakestRows(matPtr, matSize, &matColSize, k, &returnSize);

//     // 输出结果
//     printf("The indexes of the %d weakest rows are: ", k);
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     // 释放分配的内存
//     free(result);

//     return 0;
// }

//-----------------------------------------------------
//1260
// void printGrid(int** grid, int rows, int cols) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", grid[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int* gridPtr[3];
//     for (int i = 0; i < 3; i++) {
//         gridPtr[i] = grid[i];   //将二维数组的每一行的首地址存储在一维数组中
//     }
//     int gridCol = 3;
//     int k = 1;
//     int returnSize;
//     int* returnCol;
// // int** shiftGrid(int** grid, int row, int* gridCol, int k, int* returnSize, int** returnCol);
//     int** result = shiftGrid(gridPtr, 3, &gridCol, k, &returnSize, &returnCol);

//     printf("Shifted Grid:\n");
//     printGrid(result, returnSize, gridCol);

//     // 释放分配的内存
//     for (int i = 0; i < returnSize; i++) {
//         free(result[i]);
//     }
//     free(result);
//     free(returnCol);

//     return 0;
// }
//-----------------------------------------------------
//1122
// int main() {
//     int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
//     int arr2[] = {2, 1, 4, 3, 9, 6};
//     int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
//     int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
//     int returnSize;

//     int* result = relativeSortArray(arr1, arr1Size, arr2, arr2Size, &returnSize);

//     printf("Sorted array: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     return 0;
// }
//-----------------------------------------------------
//1313
// int main() {
//     int nums[] = {1, 2, 3, 4};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int returnSize;
    
//     int* result = decompressRLElist(nums, numsSize, &returnSize);
    
//     printf("Decompressed list: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");
    
//     free(result);  // 释放动态分配的内存
//     return 0;
// }
//-----------------------------------------------------
//1351
// int main() {
//     int grid[4][4] = {
//         {-4, 3, -2, -1},
//         {3, 2, 1, -1},
//         {1, 1, -1, -2},
//         {-1, -1, -2, -3}
//     };
//     int* gridColSize = (int*)malloc(4 * sizeof(int));
//     for (int i = 0; i < 4; i++) {
//         gridColSize[i] = 4;
//     }
//     int** gridPtr = (int**)malloc(4 * sizeof(int*));
//     for (int i = 0; i < 4; i++) {
//         gridPtr[i] = grid[i];
//     }

//     int gridSize = 4;
//     int result = countNegatives(gridPtr, gridSize, gridColSize);

//     printf("Number of negatives in the grid: %d\n", result);

//     free(gridColSize);
//     free(gridPtr);
//     return 0;
// }
//-----------------------------------------------------
//1403
// int main() {
//     int nums[] = {4, 3, 10, 9, 8};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int returnSize;
    
//     int* result = minSubsequence(nums, numsSize, &returnSize);
    
//     printf("The resulting subsequence is: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");
    
//     free(result);
//     return 0;
// }
//-----------------------------------------------------
//中等
//面试题 16.04 井字游戏
// int main() {
//     char* board[] = {"O X", " XO", "X O"};
//     int boardSize = sizeof(board) / sizeof(board[0]);
    
//     char* result = tictactoe(board, boardSize);
    
//     printf("The result of the game is: %s\n", result);
    
//     return 0;
// }
//-----------------------------------------------------
//面试题 17.09 第 k 个数
// int main() {
//     int k = 10;
//     int result = getKthMagicNumber(k);
//     printf("The %dth magic number is: %d\n", k, result);
//     return 0;
// }
//-----------------------------------------------------
//LRC 166. 珠宝的最高价值
// int main() {
//     int gridSize = 3;
//     int gridColSize[3] = {3, 3, 3};

//     int** grid = (int**)malloc(gridSize * sizeof(int*));
//     grid[0] = (int[]) {1, 3, 1};
//     grid[1] = (int[]) {1, 5, 1};
//     grid[2] = (int[]) {4, 2, 1};

//     int result = jewelleryValue(grid, gridSize, gridColSize);
//     printf("Maximum jewellery value: %d\n", result);

//     // Free allocated memory
//     free(grid);

//     return 0;
// }
//-----------------------------------------------------
//81
// int main() {
//     int nums[] = {2, 5, 6, 0, 0, 1, 2};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int target = 0;

//     if (search(nums, numsSize, target)) {
//         printf("true\n");
//     } else {
//         printf("false\n");
//     }

//     return 0;
// }
//-----------------------------------------------------
//91
// int main() {
//     // 示例1
//     char s1[] = "12";
//     printf("解码方法的总数（%s）：%d\n", s1, numDecodings(s1));

//     // 示例2
//     char s2[] = "226";
//     printf("解码方法的总数（%s）：%d\n", s2, numDecodings(s2));

//     // 示例3
//     char s3[] = "06";
//     printf("解码方法的总数（%s）：%d\n", s3, numDecodings(s3));

//     return 0;
// }
//-----------------------------------------------------
//2065
// #include <math.h>
// int main() {
//     // 示例1的输入
//     int values[] = {0, 32, 10, 43};
//     int valuesSize = sizeof(values) / sizeof(values[0]);

//     int edgesSize = 3;
//     int edgesColSize[] = {3, 3, 3};
//     int** edges = (int**)malloc(edgesSize * sizeof(int*));
//     for (int i = 0; i < edgesSize; i++) {
//         edges[i] = (int*)malloc(edgesColSize[i] * sizeof(int));
//     }
//     edges[0][0] = 0; edges[0][1] = 1; edges[0][2] = 10;
//     edges[1][0] = 1; edges[1][1] = 2; edges[1][2] = 15;
//     edges[2][0] = 0; edges[2][1] = 3; edges[2][2] = 10;

//     int maxTime = 49;

//     // 调用函数并输出结果
//     int result = maximalPathQuality(values, valuesSize, edges, edgesSize, edgesColSize, maxTime);
//     printf("最大路径价值: %d\n", result);

//     // 释放内存
//     for (int i = 0; i < edgesSize; i++) {
//         free(edges[i]);
//     }
//     free(edges);

//     return 0;
// }
//-----------------------------------------------------
//3099
// int main() {
//     int x = 18; // 示例1
//     int result = sumOfTheDigitsOfHarshadNumber(x);
//     printf("Result for %d: %d\n", x, result);

//     x = 23; // 示例2
//     result = sumOfTheDigitsOfHarshadNumber(x);
//     printf("Result for %d: %d\n", x, result);

//     return 0;
// }
//-----------------------------------------------------
//589
// 创建节点的帮助函数
// struct Node* createNode(int val, int numChildren) {     
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->val = val;    
//     node->numChildren = numChildren;
//     node->children = (struct Node**)malloc(sizeof(struct Node*) * numChildren);
//     return node;
// }

// // 主函数
// int main() {
//     // 构造示例1的树
//     struct Node* root = createNode(1, 3);
//     struct Node* child1 = createNode(3, 2);
//     struct Node* child2 = createNode(2, 0);
//     struct Node* child3 = createNode(4, 0);
//     struct Node* grandchild1 = createNode(5, 0);
//     struct Node* grandchild2 = createNode(6, 0);

//     root->children[0] = child1;
//     root->children[1] = child2;
//     root->children[2] = child3;
//     child1->children[0] = grandchild1;
//     child1->children[1] = grandchild2;

//     int returnSize;
//     int* result = preorder(root, &returnSize);

//     // 打印结果
//     printf("Preorder traversal: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     // 释放内存
//     free(result);
//     free(grandchild2);
//     free(grandchild1);
//     free(child3);
//     free(child2);
//     free(child1);
//     free(root->children);
//     free(root);

//     return 0;
// }

//-----------------------------------------------------
//225
// int main() {
//     // 创建一个栈实例
//     MyStack* myStack = myStackCreate();

//     // 执行操作
//     myStackPush(myStack, 1);
//     myStackPush(myStack, 2);

//     int topElement = myStackTop(myStack); // 获取栈顶元素
//     printf("Top element: %d\n", topElement); // 应输出 2

//     int poppedElement = myStackPop(myStack); // 弹出栈顶元素
//     printf("Popped element: %d\n", poppedElement); // 应输出 2

//     bool isEmpty = myStackEmpty(myStack); // 检查栈是否为空
//     printf("Is stack empty? %s\n", isEmpty ? "true" : "false"); // 应输出 false

//     // 释放栈
//     myStackFree(myStack);

//     return 0;
// }
//-----------------------------------------------------
//232
// int main() {
//     // 创建一个队列实例
//     MyQueue* myQueue = myQueueCreate();

//     // 执行操作
//     myQueuePush(myQueue, 1);
//     myQueuePush(myQueue, 2);

//     int frontElement = myQueuePeek(myQueue); // 获取队列开头元素
//     printf("Front element: %d\n", frontElement); // 应输出 1

//     int poppedElement = myQueuePop(myQueue); // 弹出队列开头元素
//     printf("Popped element: %d\n", poppedElement); // 应输出 1

//     bool isEmpty = myQueueEmpty(myQueue); // 检查队列是否为空
//     printf("Is queue empty? %s\n", isEmpty ? "true" : "false"); // 应输出 false

//     // 释放队列
//     myQueueFree(myQueue);

//     return 0;
// }
//-----------------------------------------------------
//2129
// int main() {
//     char title1[] = "capiTalIze tHe titLe";
//     char title2[] = "First leTTeR of EACH Word";
//     char title3[] = "i lOve leetcode";

//     printf("Original: %s\n", title1);
//     printf("Capitalized: %s\n", capitalizeTitle(title1));

//     printf("Original: %s\n", title2);
//     printf("Capitalized: %s\n", capitalizeTitle(title2));

//     printf("Original: %s\n", title3);
//     printf("Capitalized: %s\n", capitalizeTitle(title3));

//     return 0;
// }
//-----------------------------------------------------
//303
// int main() {
//     int nums[] = {-2, 0, 3, -5, 2, -1};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);

//     NumArray* numArray = numArrayCreate(nums, numsSize);

//     printf("sumRange(0, 2) = %d\n", numArraySumRange(numArray, 0, 2)); // 应输出 1
//     printf("sumRange(2, 5) = %d\n", numArraySumRange(numArray, 2, 5)); // 应输出 -1
//     printf("sumRange(0, 5) = %d\n", numArraySumRange(numArray, 0, 5)); // 应输出 -3

//     numArrayFree(numArray);

//     return 0;
// }
//-----------------------------------------------------
//2908
// int main() {
//     int nums1[] = {8, 6, 1, 5, 3};
//     int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
//     printf("Minimum sum for nums1: %d\n", minimumSum(nums1, numsSize1)); // 应输出 9

//     int nums2[] = {5, 4, 8, 7, 10, 2};
//     int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
//     printf("Minimum sum for nums2: %d\n", minimumSum(nums2, numsSize2)); // 应输出 13

//     int nums3[] = {6, 5, 4, 3, 4, 5};
//     int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
//     printf("Minimum sum for nums3: %d\n", minimumSum(nums3, numsSize3)); // 应输出 -1

//     return 0;
// }
//-----------------------------------------------------
//3086
// int main() {
//     int nums1[] = {1, 1, 0, 0, 0, 1, 1, 0, 0, 1};
//     int nums2[] = {0, 0, 0, 0};

//     int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
//     int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

//     int k1 = 3;
//     int maxChanges1 = 1;
//     int k2 = 2;
//     int maxChanges2 = 3;

//     printf("Example 1: %lld\n", minimumMoves(nums1, numsSize1, k1, maxChanges1));
//     printf("Example 2: %lld\n", minimumMoves(nums2, numsSize2, k2, maxChanges2));

//     return 0;
// }
//-----------------------------------------------------
//70
// int main() {
//     int n = 3; // Example input, you can change this value to test different inputs
//     int result = climbStairs(n);
//     printf("Number of ways to climb %d stairs: %d\n", n, result);
//     return 0;
// }
//-----------------------------------------------------
//509   1137
// int main() {
//     int n = 6;  // 可以根据需要更改为任何正整数
//     int result = fibonacci(n);
//     int result1 = tribonacci(n);
//     printf("F2(%d) = %d\n", n, result);
//     printf("F3(%d) = %d\n", n, result1);
//     return 0;
// }
//-----------------------------------------------------
//746
// int main() {
//     int cost1[] = {10, 15, 20};
//     int size1 = sizeof(cost1) / sizeof(cost1[0]);
//     printf("Minimum cost for cost1: %d\n", minCostClimbingStairs(cost1, size1));

//     int cost2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//     int size2 = sizeof(cost2) / sizeof(cost2[0]);
//     printf("Minimum cost for cost2: %d\n", minCostClimbingStairs(cost2, size2));

//     return 0;
// }
//-----------------------------------------------------
//3033
// int main() {
//     int matrix[3][3] = {
//         {1, 2, -1},
//         {4, -1, 6},
//         {7, 8, 9}
//     };
//     //最简便的的二维数组赋值方法
//     int* matrixPtr[3];
//     for (int i = 0; i < 3; ++i) {
//         matrixPtr[i] = matrix[i];   //将二维数组的每一行的首地址赋值给一维数组
//     }
//     int matrixColSize = 3;      // 列数
//     int returnSize;
//     int* returnColumnSizes;

//     int** result = modifiedMatrix(matrixPtr, 3, &matrixColSize, &returnSize, &returnColumnSizes);

//     printf("Modified Matrix:\n");
//     for (int i = 0; i < returnSize; ++i) {
//         for (int j = 0; j < returnColumnSizes[i]; ++j) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }

//     // Free allocated memory
//     for (int i = 0; i < returnSize; ++i) {
//         free(result[i]);
//     }
//     free(result);
//     free(returnColumnSizes);

//     return 0;
// }

//-----------------------------------------------------
//70
// int main() {
//     int n = 3;  // 示例 2 的输入
//     int result = climbStairs1(n);
//     printf("Number of ways to climb %d stairs: %d\n", n, result);
//     return 0;
// }
//-----------------------------------------------------
//198
// int main() {
//     int houses[] = {2, 999, 9, 3, 999};  // 示例 2 的输入
//     int n = sizeof(houses) / sizeof(houses[0]);
//     int result = rob(houses, n);
//     printf("Maximum amount that can be robbed: %d\n", result);
//     return 0;
// }
//-----------------------------------------------------
//740
int main() {
    int nums[] = {2, 2, 3, 3, 3, 4};  // 示例 2 的输入
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = deleteAndEarn(nums, n);
    printf("Maximum points that can be earned: %d\n", result);
    return 0;
}
//-----------------------------------------------------








