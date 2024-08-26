// Function to compute the middle character(s) and store them in the provided buffer
char *get_middle(char outp[3], const char *inp) {
    int len = strlen(inp);
    int mid = len / 2;

    if (len % 2 == 0) {
        // If the length is even, store the middle 2 characters
        outp[0] = inp[mid - 1];
        outp[1] = inp[mid];
        outp[2] = '\0'; // Null-terminate the result string
    } else {
        // If the length is odd, store the middle character
        outp[0] = inp[mid];
        outp[1] = '\0'; // Null-terminate the result string
    }

    return outp;
}