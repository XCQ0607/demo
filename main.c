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

int main() {
    char rings[] = "B0B6G0R6R0R6G9";
    int result = countPoints(rings);
    printf("Number of rods with all three colors: %d\n", result);
    return 0;
}

