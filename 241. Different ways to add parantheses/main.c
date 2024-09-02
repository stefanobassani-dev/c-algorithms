#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*';
}

int calculate(int num1, int num2, char operator) {
    if (operator == '+') return num1 + num2;
    if (operator == '-') return num1 - num2;
    if (operator == '*') return num1 * num2;

    return 0;
}

int* diffWaysToCompute(char* expression, int* returnSize) {
    int len = strlen(expression);
    int* results = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;

    int isNum = 1;
    for (int i = 0; i < len; i++) {
        if (isOperator(expression[i])) {
            isNum = 0;
            break;
        }
    }
    if (isNum) {
        results[(*returnSize)++] = atoi(expression);
        return results;
    }

    for (int i = 0; i < len; i++) {
        if (isOperator(expression[i])) {
            int leftSize = 0;
            int* leftResults = diffWaysToCompute(strndup(expression, i), &leftSize);

            int rightSize = 0;
            int* rightResults = diffWaysToCompute(strdup(expression + i + 1), &rightSize);

            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    int result = 0;
                    switch (expression[i]) {
                        case '+':
                            result = leftResults[l] + rightResults[r];
                        break;
                        case '-':
                            result = leftResults[l] - rightResults[r];
                        break;
                        case '*':
                            result = leftResults[l] * rightResults[r];
                        break;
                    }
                    results[(*returnSize)++] = result; // Combina i risultati
                }
            }
            free(leftResults);
            free(rightResults);
        }
    }
    return results;
}

int main(void) {
    char str[] = "2*3-4*5";
    int returnSize = 0;

    int* res = diffWaysToCompute(str, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
