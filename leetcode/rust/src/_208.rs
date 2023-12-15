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

const SIZE: usize = 26;

#[derive(Debug, Default)]
struct Trie {
    children: [Option<Box<Trie>>; SIZE],
    end_of_word: bool,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {

    fn letter_index(c: char) -> usize {
        (c as usize) - ('a' as usize)
    }

    fn new() -> Self {
        Default::default()
    }
    
    fn insert(&mut self, word: String) {
        let mut node = self;
        for c in word.chars() {
            node = node.children[Self::letter_index(c)].get_or_insert(Box::new(Trie::new()));
        }
        node.end_of_word = true;
    }

    fn search_node(&self, word: &String) -> Option<&Trie> {
        let mut node = self;
        for c in word.chars() {
            match node.children[Self::letter_index(c)] {
                None => return None,
                Some(ref child) => node = child,
            }
        }

        Some(node)
    }
    
    fn search(&self, word: String) -> bool {
        if let Some(dest_node) = self.search_node(&word) {
            return dest_node.end_of_word;
        } 

        false
    }
    
    fn starts_with(&self, prefix: String) -> bool {
        self.search_node(&prefix).is_some()
    }
}
