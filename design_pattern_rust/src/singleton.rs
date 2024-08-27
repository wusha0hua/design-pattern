use std::sync::Mutex;
use lazy_static::lazy_static;

#[derive(Debug, Clone)]
struct SingletonLazy {
    data: Vec<usize>,    
}

lazy_static! {
    static ref singleton: Mutex<SingletonLazy> = Mutex::new(SingletonLazy::new()); 
}

impl SingletonLazy {
    fn new() -> Self {
        Self {
            data: Vec::new(),
        }
    }
    pub fn get_instance() -> &'static Mutex<Self> {
        &singleton
    }
    pub fn get_data(&self) -> &Vec<usize> {
        &self.data
    }
    pub fn push_data(&mut self, data: usize) {
        self.data.push(data);
    }
}


#[cfg(test)]
mod test_singleton {
    #[test]
    fn test_singleton_lazy() {
        use super::SingletonLazy;
        let singleton1 = SingletonLazy::get_instance();
        let singleton2 = SingletonLazy::get_instance();
        singleton1.lock().unwrap().push_data(6);
        singleton2.lock().unwrap().push_data(5);
        assert_eq!(singleton1.lock().unwrap().get_data(), &vec![6usize, 5]);
        assert_eq!(singleton2.lock().unwrap().get_data(), &vec![6usize, 5]);
    }
}
