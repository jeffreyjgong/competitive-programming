#![allow(unused_imports)]

use std::{collections::{
    VecDeque, LinkedList,
    HashMap, BTreeMap,
    HashSet, BTreeSet,
    BinaryHeap
}, mem};

use core::cmp::{
    Eq, PartialEq,
    Ord, PartialOrd,
    Ordering,
    Reverse,
    max, min
};

const SIZE: usize = 26;

type OptNode = Option<Box<TrieNode>>;

#[derive(Debug, Default)]
struct TrieNode {
    children: [OptNode; 26],
    end_of_word: bool,
}

#[derive(Debug)]
struct WordDictionary {
    root: TrieNode,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordDictionary {

    fn new() -> Self {
        Self {
            root: Default::default(),
        }
    }

    fn letter_index(c: char) -> usize {
        (c as usize) - ('a' as usize)
    }
    
    fn add_word(&mut self, word: String) {
        let mut node = &mut self.root;
        for c in word.chars() {
            node = node.children[Self::letter_index(c)].get_or_insert(Box::new(Default::default()));
        }

        node.end_of_word = true;
    }

    fn search_word(root: &TrieNode, word: &[u8]) -> bool {
        if let Some(&c) = word.first() {
            if c == b'.' {
                for child in &root.children {
                    if let Some(node) = child {
                        if Self::search_word(&node, &word[1..]) {
                            return true;
                        }
                    }
                }
            } else {
                if let Some(node) = &root.children[Self::letter_index(c as char)] {
                    return Self::search_word(&node, &word[1..]);
                }
            }
            return false;
        }

        root.end_of_word
    }

    fn search(&self, word: String) -> bool {
        Self::search_word(&self.root, word.as_bytes())
    }
}
