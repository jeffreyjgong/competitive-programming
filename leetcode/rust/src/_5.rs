#![allow(unused_imports)]

use std::collections::{
    VecDeque, LinkedList,
    HashMap, BTreeMap,
    HashSet, BTreeSet,
    BinaryHeap
};

use core::cmp::{
    Eq, PartialEq,
    Ord, PartialOrd,
    Ordering,
    Reverse,
    max, min
};

struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.len() == 1 {
            return s;
        }
        // dynamic programming where 
        // dp[i][j] represents whether or not it is a palindrome

        // base case where dp[i][i] = yes
        // this can get all odd length palindromes
        let n = s.len();
        let dp = vec![vec![false; n]; n];
        for l in 0..n {
            dp[l][l] = true;
        }

        // additional base case where dp[i][i+1] where s[i] == s[i+1] is also a palindrome
        // this can get all even length palindromes
        let l_max = 0;
        let r_max = 0;
        let max = 1;
        for r in 1..n {
            if s[r] == s[r-1] {
                dp[r-1][r] = true;
                l_max = r-1;
                r_max = r;
                max = 2;
            }
        }

        if s.len() == 2 {
            return s[l_max..r_max+1].to_string();
        }

        // odds (largest interval length is largest even number less than)
        // if length 5 then largest interval would be 4
        // if length 6 then largest interval would be 4

        // even (largest interval length is largest odd number less than)
        // if length 5 then largest interval would be 3
        // if length 6 then largest interval would be 5

        let odd_interval_max = if n % 2 == 1 {
            n-1
        } else {
            n-2
        };

        

    }
}