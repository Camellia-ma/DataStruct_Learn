#include <stdio.h>

int get_max_number(const int nums[],const int size) {
    int max_num = 0;
    for (int i = 0;i < size;i++) {
        max_num =  nums[i] > max_num ? nums[i] : max_num;
    }
    return max_num;
}

int main() {
    const int nums[9] = {1,2,3,4,5,6,7,8,100};
    printf("max number is: %d\n",get_max_number(nums,sizeof(nums) / sizeof(nums[1])));
    return 0;
}


// Created by 柳贯一 on 2026/3/18.