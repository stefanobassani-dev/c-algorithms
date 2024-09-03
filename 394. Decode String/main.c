#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toDigitNumber(char c) {
    int asciiNums[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

    int i = 0;

    while (i < 10 && c != asciiNums[i]) i++;

    return i < 10 ? asciiNums[i] - 48 : -1;
}

char* decodeString(char* s) {
    // printf("%s\n", s);
    int i = 0;
    int len = strlen(s);
    while (i < len && toDigitNumber(s[i]) == -1) i++;

    // if it does not contain numbers, I return the string as it is
    if (i == len) return s;

    int open = 0;
    int openIndex = 0;
    int close = 0;
    int closeIndex = 0;

    int index = 0;

    char* result = NULL;
    int resultLen = 0;

    while (index < len) {
        if (toDigitNumber(s[index]) == -1 && s[index] != '[' && s[index] != ']') {
            resultLen++;
            result = (char*) realloc(result, (resultLen + 1) * sizeof(char));
            result[resultLen - 1] = s[index];
        }
        if (s[index] == '[') {
            int multiIndex = index - 1;
            int multiplicator = toDigitNumber(s[multiIndex]);

            open++;
            openIndex = index;

            while (open != close) {
                index++;
                if (s[index] == '[') open++;
                if (s[index] == ']') close++;
            }

            closeIndex = index;

            char* string = decodeString(
                strndup(s + (openIndex + 1), (closeIndex - 1 - openIndex)));

            char* newStr = (char*) malloc((strlen(string) * multiplicator + 1) * sizeof(char));

            for (int j = 0; j < multiplicator; j++) strcat(newStr, string);
            resultLen += strlen(newStr);

            result = (char*) realloc(result, (resultLen + 1) * sizeof(char));
            strcat(result, newStr);

        }


        index++;
    }

    return result;
}

int main() {
    char encoded[] = "3[a2[c]]";
    // char encoded[] = "3[a2[c]]";


    printf("%s\n", decodeString(encoded));
}
