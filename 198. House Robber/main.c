#include <stdio.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    // if I choose nums[0], I'll skip the following element
    int picked = nums[0] + rob(nums + 2, numsSize - 2);

    // if I do not choose nums[0]
    int notPicked = rob(nums + 1, numsSize - 1);

    return picked > notPicked ? picked : notPicked;
};

int robDP(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return max(nums[0], nums[1]);

    for (int i = numsSize - 2; i >= 0; i--) {
        int twoStepsForward = (i + 2) > numsSize - 1 ? 0 : nums[i + 2];
        nums[i] = max(
            nums[i] + twoStepsForward,
            nums[i + 1]
        );
    }

    return nums[0];
}

int main() {
    int nums[] = {2, 7, 9, 3, 1};

    printf("%d\n", rob(nums, 5));
    printf("%d\n", robDP(nums, 5));
}
