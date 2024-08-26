#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool validate_pin(const char *pin) {
    if (pin == NULL) {
        return false; // Handle NULL pointer case
    }

    const char *start = pin; // Save the original pointer for length calculation

    while (*pin) {
        if (!isdigit((unsigned char)*pin)) { // Check if the character is not a digit
            return false; // Return false if any character is not a digit
        }
        pin++; // Move to the next character
    }

    size_t length = pin - start; // Calculate the length of the string

    // Check if length is 4 or 6
    if (length == 4 || length == 6) {
        return true;
    }
    
    return false; // Return false if length is not 4 or 6
}