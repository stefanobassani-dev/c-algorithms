#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int score(int* nums, int left, int right) {
    if (left == right)
        return nums[left];

    int diff1 = nums[left] - score(nums, left + 1, right);
    int diff2 = nums[right] - score(nums, left, right - 1);

    return max(diff1, diff2);
}

bool predictTheWinner(int* nums, int numsSize) {
    return score(nums, 0, numsSize - 1) >= 0;
}

int** allocateMatrix(int rows, int column) {
    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(column * sizeof(int));
    }

    return dp;
}

void printMatrix(int** matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int scoreDP(int* nums, int numsSize) {
    int** dp = allocateMatrix(numsSize, numsSize);

    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i; j < numsSize; j++) {
            if (i == j) dp[i][j] = nums[i];
            else  dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }

    int res = dp[0][numsSize - 1] >= 0;

    free(dp);

    return res;
}

int main() {
    int nums[] = {1, 5, 2};

    printf("recursive approach O(2^n): %d\n", predictTheWinner(nums, 3));

    printf("dynamic programming approach O(n^2): %d\n", scoreDP(nums, 3));
}
