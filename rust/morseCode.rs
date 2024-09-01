mod preloaded;
use preloaded::MORSE_CODE;
// MORSE_CODE is `HashMap<String, String>`. e.g. ".-" -> "A".
fn normalize_spaces(s: &str) -> String {
    s.split_whitespace()
     .collect::<Vec<&str>>()
     .join(" ")
}
fn decode_morse(encoded: &str) -> String {
    let mut result = String::new();
    let mut morse_char = String::new();
    
    for c in encoded.chars() {
        match c {
            '.' | '-' => morse_char.push(c), // Collect Morse code characters
            ' ' => {
                if morse_char.is_empty() {
                    // Handle space between words
                    result.push(' ');
                } else {
                    // Translate Morse code to character
                    if let Some(decoded_char) = MORSE_CODE.get(&morse_char) {
                        result.push_str(decoded_char); // Append decoded character string
                    } else {
                        result.push('?'); // Unknown Morse code
                    }
                    morse_char.clear(); // Clear the collected Morse code
                }
            }
            '/' => {
                // Handle space between words (if '/' is used as a word separator)
                if !morse_char.is_empty() {
                    if let Some(decoded_char) = MORSE_CODE.get(&morse_char) {
                        result.push_str(decoded_char); // Append decoded character string
                    } else {
                        result.push('?'); // Unknown Morse code
                    }
                    morse_char.clear(); // Clear the collected Morse code
                }
                result.push(' '); // Add a space for word separation
            }
            _ => {
                // Ignore any unexpected characters
            }
        }
    }
    
    // Handle any remaining Morse code at the end
    if !morse_char.is_empty() {
        if let Some(decoded_char) = MORSE_CODE.get(&morse_char) {
            result.push_str(decoded_char); // Append decoded character string
        } else {
            result.push('?'); // Unknown Morse code
        }
    }
    let normalized_result = normalize_spaces(result.as_str());

    return normalized_result
}

