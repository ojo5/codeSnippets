impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut result: Vec<i32> = Vec::new();
    // Iterate over indices
    for i in 0..nums.len() {
        for j in (i + 1)..nums.len() {
            if nums[i] + nums[j] == target {
                result.push(i as i32);
                result.push(j as i32);
                return result;
            }
        }
    }
    result // Return an empty vector if no pair is found
    }    
}

