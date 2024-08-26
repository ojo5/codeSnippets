#include <ctype.h>
#include <stdio.h>

char *to_jaden_case(char *jaden_case, const char *string) {
    int i;
    int is_start_of_word = 1; // Flag to determine if the current character is the start of a new word

    for (i = 0; string[i] != '\0'; i++) {
        if (is_start_of_word && isalpha((unsigned char)string[i])) {
            jaden_case[i] = toupper((unsigned char)string[i]);
            is_start_of_word = 0; // After capitalizing, we're no longer at the start of a word
        } else {
            jaden_case[i] = string[i]; // Copy the character as is
            if (string[i] == ' ') {
                is_start_of_word = 1; // Next character will be the start of a new word
            }
        }
    }
    
    jaden_case[i] = '\0'; // Null-terminate the resulting string
    return jaden_case;
}