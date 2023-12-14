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

use std::rc::Rc;
use std::cell::RefCell;

pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
        val,
        left: None,
        right: None
        }
    }
}

struct Solution;

impl Solution {
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        let mut cur_list: Vec<i32> = Vec::new();

        let mut cur_sum = 0;

        Self::helper(root, target_sum, &mut cur_sum, &mut res, &mut cur_list);

        res
    }

    fn helper(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32, cur_sum: &mut i32, res: &mut Vec<Vec<i32>>, cur_list: &mut Vec<i32>) {
        if let Some(existing_root) = root {
            *cur_sum += existing_root.borrow().val;
            cur_list.push(existing_root.borrow().val);

            if existing_root.borrow().left.is_none() && existing_root.borrow().right.is_none() && *cur_sum == target_sum {
                res.push(cur_list.to_vec());
            } else {
                if existing_root.borrow().left.is_some() {
                    Self::helper(existing_root.borrow().left.clone(), target_sum, cur_sum, res, cur_list);
                }

                if existing_root.borrow().right.is_some() {
                    Self::helper(existing_root.borrow().right.clone(), target_sum, cur_sum, res, cur_list);
                }
            }

            *cur_sum -= existing_root.borrow().val;
            cur_list.pop();
        }
    }

}