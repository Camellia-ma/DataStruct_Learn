#include <stdio.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))   // 定义宏 -- 求数组长度

int get_max_number(const int nums[],const int size) {
    int max_num = 0;
    for (int i = 0;i < size;i++) {
        max_num =  nums[i] > max_num ? nums[i] : max_num;
    }
    return max_num;
}

int main() {
    const int nums[20] = {1,2,3,4,5,6,7,8,100};
    printf("max number is: %d\n",get_max_number(nums,ARRAY_SIZE(nums)));
    return 0;
}


// Created by 柳贯一 on 2026/3/18.