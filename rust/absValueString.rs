impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        let mut list: Vec<i32> = Vec::new();  // Creates an empty vector of type i32
        let mut result = 0;
        for c in s.chars(){
            list.push(c as i32);
        }
        for i in 0..list.len() - 1 {
            result += (list[i] - list[i + 1]).abs();
        }
        return result;
    }
}