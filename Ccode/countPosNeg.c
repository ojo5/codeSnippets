void count_positives_sum_negatives( int *values, size_t count, int *positivesCount, int *negativesSum) {
    *positivesCount = 0;
    *negativesSum = 0;

    // Iterate through the array
    for (size_t i = 0; i < count; i++) {
        if (values[i] > 0) {
            (*positivesCount)++; // Increment the count of positive numbers
        } else if (values[i] < 0) {
            (*negativesSum) += values[i]; // Add to the sum of negative numbers
        }
    }
}