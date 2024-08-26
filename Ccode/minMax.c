#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void high_and_low(const char *strnum, char *result) {
    long long max = LLONG_MIN; // Initialize to the smallest possible long long integer
    long long min = LLONG_MAX; // Initialize to the largest possible long long integer

    // Check if input string is empty
    if (strnum == NULL || *strnum == '\0') {
        sprintf(result, "Error: Empty input");
        return;
    }

    // Create a buffer for tokenization
    char buffer[4096]; // Increase buffer size to handle longer inputs
    strncpy(buffer, strnum, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null termination

    // Tokenize the string and process each number
    char *token = strtok(buffer, " ");
    int hasNumbers = 0; // Flag to check if we have valid numbers

    while (token != NULL) {
        char *end;
        long long num = strtoll(token, &end, 10); // Convert to long long integer

        // Check if conversion was successful and token contains a valid number
        if (*end == '\0' && end != token) {
            if (num > max) {
                max = num; // Update max if current number is greater
            }
            if (num < min) {
                min = num; // Update min if current number is smaller
            }
            hasNumbers = 1; // Set flag indicating we have valid numbers
        } else {
            sprintf(result, "Error: Invalid input");
            return;
        }

        token = strtok(NULL, " "); // Get the next token
    }

    if (!hasNumbers) {
        sprintf(result, "Error: No valid numbers found");
        return;
    }

    // Format the result string
    sprintf(result, "%lld %lld", max, min);

    // Optionally print the result (for debugging purposes)
    printf("Result: %s\n", result);
}