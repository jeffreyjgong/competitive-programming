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
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num_to_id: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

        for (idx, &val) in nums.iter().enumerate() {
            let complement = target - val;

            if let Some(&complement_index) = num_to_id.get(&complement) {
                return vec![complement_index, idx as i32];
            }

            num_to_id.insert(val, idx as i32);
        }

        vec![]
    }
}