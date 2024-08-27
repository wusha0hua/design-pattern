use std::rc::Rc;


#[derive(Clone, Debug, PartialEq)]
pub struct Prototype {
    data_pointer: Rc<usize>
}

impl Default for Prototype {
    fn default() -> Self {
        Self {
            data_pointer: Rc::new(usize::default()),
        }
    }
}

#[cfg(test)]
mod test_prototype {
    use std::rc::Rc;
    use super::Prototype;
    #[test]
    fn test_prototype() {
        let prototype1 = Prototype::default();
        let prototype2 = prototype1.clone();
        assert_eq!(prototype1, prototype2);
        assert!(Rc::ptr_eq(&prototype1.data_pointer, &prototype2.data_pointer));
    }
}
