#include <stdio.h>


int swit() {
    int u = 5, v = 3;

    printf("u = %d, v = %d\n", u, v);

    if (u > v) u ^= v ^= u ^= v;

    printf("u = %d, v = %d\n", u, v);  // 输出: u = 3, v = 5
    return 0;
}

// 步骤 1
// 执行 u = u ^ v：
// u = 5 ^ 3  // 0101 ^ 0011 = 0110
// u = 6      // 0110
// 步骤 2
// 执行 v = u ^ v（注意，此时 u 已经是上一步的新值 6）：
// v = 6 ^ 3  // 0110 ^ 0011 = 0101
// v = 5      // 0101
// 步骤 3
// 执行 u = u ^ v（注意，此时 v 已经是上一步的新值 5）：
// u = 6 ^ 5  // 0110 ^ 0101 = 0011
// u = 3      // 0011
// 最终交换后的值：
// u = 3
// v = 5
