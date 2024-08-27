

pub trait Department {
    fn execute(&mut self, patient: &Patient) {
        self.handle(patient);
        if let Some(next) = self.next() {
            next.execute(patient);
        }
    }
    fn handle(&mut self, patient: &Patient);
    fn next(&mut self) -> &mut Option<Box<dyn Department>>;
}

pub struct Doctor {
    next: Option<Box<dyn Department>>,
}

impl Doctor {
    pub fn new(next: impl Department + 'static) -> Self {
        Self { 
            next: Some(Box::new(next)),
        }
    }
}

impl Department for Doctor {
    fn handle(&mut self, _: &Patient) {
        println!("Doctor handle");
    }
    fn next(&mut self) -> &mut Option<Box<dyn Department>> {
        &mut self.next
    }
}

pub struct Medical {
    next: Option<Box<dyn Department>>,
}

impl Medical {
    pub fn new(next: impl Department + 'static) -> Self {
        Self { 
            next: Some(Box::new(next)),
        }
    }
}

impl Department for Medical {
    fn handle(&mut self, _: &Patient) {
        println!("Medical handle");
    }
    fn next(&mut self) -> &mut Option<Box<dyn Department>> {
        &mut self.next
    }
}

pub struct Cashier {
    next: Option<Box<dyn Department>>,
}

impl Cashier {
    pub fn new() -> Self {
        Self { 
            next: None,
        }
    }
}
impl Department for Cashier {
    fn handle(&mut self, _: &Patient) {
        println!("Cashier handle");
    }
    fn next(&mut self) -> &mut Option<Box<dyn Department>> {
        &mut self.next
    }
}

pub struct Reception {
    next: Option<Box<dyn Department>>,
}

impl Reception {
    pub fn new(next: impl Department + 'static) -> Self {
        Self { 
            next: Some(Box::new(next)),
        }
    }
}

impl Department for Reception {
    fn handle(&mut self, _: &Patient) {
        println!("Reception handle");
    }
    fn next(&mut self) -> &mut Option<Box<dyn Department>> {
        &mut self.next
    }
}
pub struct Patient;

#[cfg(test)]
mod test_chain_of_responsibility {
    use super::*;
    #[test]
    fn test_chain_of_responsibility() {
        let cashier = Cashier::new();
        let medical = Medical::new(cashier);
        let doctor = Doctor::new(medical);
        let mut reception = Reception::new(doctor);
        let patient = Patient;
        reception.execute(&patient);
    }
}
