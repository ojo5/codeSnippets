#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Comparison function for `qsort`
int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char *longest(const char *s1, const char *s2) {
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    
    char tmp1[50];
    char tmp2[50];
    
    strcpy(tmp1, s1);
    strcpy(tmp2, s2);
    
    // Use `qsort` to sort the strings
    qsort(tmp1, length1, sizeof(char), compareChars);
    qsort(tmp2, length2, sizeof(char), compareChars);
    
    // Allocate memory for the result string
    char tmpFinalString[100] = "";
    int finalLength = 0;
    
    // Merge the two sorted strings without duplicates
    int i = 0, j = 0;
    while (i < length1 && j < length2) {
        if (tmp1[i] < tmp2[j]) {
            if (finalLength == 0 || tmpFinalString[finalLength - 1] != tmp1[i]) {
                tmpFinalString[finalLength++] = tmp1[i];
            }
            i++;
        } else if (tmp1[i] > tmp2[j]) {
            if (finalLength == 0 || tmpFinalString[finalLength - 1] != tmp2[j]) {
                tmpFinalString[finalLength++] = tmp2[j];
            }
            j++;
        } else {
            if (finalLength == 0 || tmpFinalString[finalLength - 1] != tmp1[i]) {
                tmpFinalString[finalLength++] = tmp1[i];
            }
            i++;
            j++;
        }
    }
    
    // Handle any remaining characters in tmp1
    while (i < length1) {
        if (finalLength == 0 || tmpFinalString[finalLength - 1] != tmp1[i]) {
            tmpFinalString[finalLength++] = tmp1[i];
        }
        i++;
    }
    
    // Handle any remaining characters in tmp2
    while (j < length2) {
        if (finalLength == 0 || tmpFinalString[finalLength - 1] != tmp2[j]) {
            tmpFinalString[finalLength++] = tmp2[j];
        }
        j++;
    }
    
    tmpFinalString[finalLength] = '\0';  // Null-terminate the final string
    
    // Allocate memory on the heap and return the result
    char *result = malloc(finalLength + 1);
    if (result) {
        strcpy(result, tmpFinalString);
    }
    
    printf("tmp1: %s\n", tmp1);
    printf("tmp2: %s\n", tmp2);
    printf("FinalString: %s\n", tmpFinalString);
    
    return result;
}

int main() {
    char *result = longest("hello", "world");
    if (result) {
        printf("Result: %s\n", result);
        free(result);  // Don't forget to free the allocated memory
    }
    return 0;
}