
pub struct Scanner {
    words: Vec<&'static str>,
}

impl Scanner {
    pub fn new() -> Self {
        Self {
            words: Vec::new(),
        }
    }
    pub fn push(&mut self, word: &'static str) {
        self.words.push(word)
    }
    pub fn iter(&self) -> ScannerInterator {
        ScannerInterator { 
            index: 0, 
            scanner: self
        }
    }
}

pub struct ScannerInterator<'a> {
    index: usize,
    scanner: &'a Scanner,
}

impl<'a> Iterator for ScannerInterator<'a> {
    type Item = &'a str;
    fn next(&mut self) -> Option<Self::Item> {
        if self.index < self.scanner.words.len() {
            let word = Some(self.scanner.words[self.index]);
            self.index += 1;
            word
        } else {
            None
        }
    }
}

#[cfg(test)]
mod test_iterator {
    use super::*;
    #[test]
    fn test_iterator() {
        let mut scanner = Scanner::new();
        scanner.push("hello");
        scanner.push("world");
        scanner.push("end");
        let iterator = scanner.iter();
        iterator.for_each(|e| println!("{}", e));
    }
}
