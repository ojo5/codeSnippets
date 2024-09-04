fn solution(s: &str) -> String {
    let mut result = String::new();

    for c in s.chars() {
        // If the character is uppercase and result is not empty, insert a space before it
        if c.is_uppercase() && !result.is_empty() {
            result.push(' ');
        }
        // Append the current character to the result string
        result.push(c);
    }

    result
}