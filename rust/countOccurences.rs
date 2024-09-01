use std::collections::HashMap;

fn count_char_occurrences(s: &str) -> HashMap<char, usize> {
    let mut counts = HashMap::new();
    
    for c in s.chars() {
        // Convert character to lowercase for case-insensitive counting
        let lower_c = c.to_ascii_lowercase();
        *counts.entry(lower_c).or_insert(0) += 1;
    }
    
    counts
}

fn duplicate_encode(word: &str) -> String {
    let counts = count_char_occurrences(word);
    let mut result = String::new(); // Create an empty mutable String
    
    for c in word.chars() {
        // Convert character to lowercase for case-insensitive comparison
        let lower_c = c.to_ascii_lowercase();
        // Retrieve count from the HashMap
        let count = counts.get(&lower_c).unwrap_or(&0); 
        
        if count > &1 { // Compare with 1
            result.push(')'); // Append ')' if character is duplicated
        } else {
            result.push('('); // Append '(' if character is not duplicated
        }
    }
    
    result
}