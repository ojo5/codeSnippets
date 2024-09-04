fn solution(s: &str) -> Vec<String> {
    let mut s = s.to_string();

    // If the string length is odd, add an underscore
    if s.len() % 2 != 0 {
        s.push('_');
    }

    let mut pairs = Vec::new();

    // Iterate through the string in steps of 2
    for i in (0..s.len()).step_by(2) {
        let pair = &s[i..i + 2]; // Get a slice of two characters
        pairs.push(pair.to_string());
    }

    pairs
}