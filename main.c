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
void printGrid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* gridPtr[3];
    for (int i = 0; i < 3; i++) {
        gridPtr[i] = grid[i];   //将二维数组的每一行的首地址存储在一维数组中
    }
    int gridCol = 3;
    int k = 1;
    int returnSize;
    int* returnCol;
// int** shiftGrid(int** grid, int row, int* gridCol, int k, int* returnSize, int** returnCol);
    int** result = shiftGrid(gridPtr, 3, &gridCol, k, &returnSize, &returnCol);

    printf("Shifted Grid:\n");
    printGrid(result, returnSize, gridCol);

    // 释放分配的内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnCol);

    return 0;
}
