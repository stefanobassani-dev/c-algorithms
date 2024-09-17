#include <limits.h>
#include <stdio.h>

int max(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    return c;
}

int calculate(int* nums, int left, int right, int* sum) {
    if (left == right) {
        *sum = nums[left];
        return nums[left];
    }

    int leftSum = 0;
    int leftRes = calculate(nums, left + 1, right, &leftSum);
    int rightSum = 0;
    int rightRes = calculate(nums, left, right - 1, &rightSum);

    (*sum) = leftSum + nums[left];

    return max(leftRes, rightRes, *sum);
}

// int maxSubArray(int* nums, int numsSize) {
//     int sum = 0;
//     return calculate(nums, 0, numsSize - 1, &sum);
// }

int maxSubArray(int* nums, int numsSize) {
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        currSum += nums[i];
        maxSum = currSum > maxSum ? currSum : maxSum;

        if(currSum < 0) currSum = 0;

    }

    return maxSum;
}

int main() {
    int nums[] = {5,4,-1,7,8};

    printf("%d\n", maxSubArray(nums, 5));
}