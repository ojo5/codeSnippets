int score(const int dice[5]) {
    int counts[7] = {0};  // Initialize array to count occurrences of each die value (1 to 6)
    int total_score = 0;

    // Count the occurrences of each die value
    for (int i = 0; i < 5; i++) {
        counts[dice[i]]++;
    }

    // Calculate the score based on the rules
    if (counts[1] >= 3) {
        total_score += 1000;
        counts[1] -= 3;
    }
    for (int i = 2; i <= 6; i++) {
        if (counts[i] >= 3) {
            total_score += i * 100;
            counts[i] -= 3;
        }
    }

    // Add the score for remaining 1's and 5's
    total_score += counts[1] * 100;
    total_score += counts[5] * 50;

    return total_score;
}