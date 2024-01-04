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
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        // LCP of (S) is LCP(LCP (s_1, s_2), s_3) etc.
        // this is a canonical reduction!

        strs.into_iter().reduce(|acc, cur| {
            acc.chars()
                .zip(cur.chars())
                .take_while(|(a,c)| a == c)
                .map(|(c, _)| c)
                .collect()
        }).unwrap().to_string()
    }
}
