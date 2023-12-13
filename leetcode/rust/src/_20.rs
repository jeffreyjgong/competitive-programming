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
    pub fn is_valid(s: String) -> bool {
        let str_len: usize = s.len();
        // odd doesn't work
        if str_len & 1 == 1 {
            return false;
        }

        let mut stack = Vec::with_capacity(str_len);

        for c in s.chars() {
            match c {
                '(' | '[' | '{' => stack.push(c),
                _ => match stack.pop() {
                    // match guards
                    Some('(') if c == ')' => (),
                    Some('[') if c == ']' => (),
                    Some('{') if c == '}' => (),
                    _ => return false,
                }
            }
        }

        stack.is_empty()
    }
}