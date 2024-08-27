
pub trait Executable {
    fn execute(self) -> String;
}

pub struct Linux;

impl Linux {
    fn execute(file: impl Executable) -> String {
        file.execute() 
    }
}

pub struct Elf {
    pe_header: Option<String>,
    elf_header: Option<String>,
}
pub struct Pe {
    pe_header: Option<String>,
    elf_header: Option<String>,
}

impl Default for Elf {
    fn default() -> Self {
        Self {
            pe_header: None,
            elf_header: Some("elf".to_string()),
        }
    }
}

impl Default for Pe {
    fn default() -> Self {
        Self { 
            pe_header: Some("pe".to_string()), 
            elf_header: None 
        }
    }
}

impl Executable for Elf {
    fn execute(self) -> String{
        match self.elf_header {
            Some(info) => info,
            None => String::from("not a elf file")
        }
    }
}

impl Executable for Pe {
    fn execute(self) -> String{
        match self.elf_header {
            Some(info) => info,
            None => String::from("not a elf file")
        }
    }
}

pub struct PeTransformer {
    pe: Pe,
}

impl PeTransformer {
    pub fn new(mut pe: Pe) -> Self {
        pe.elf_header = Some("pe".to_string());
        Self { pe }
    }
}

impl Executable for PeTransformer {
    fn execute(self) -> String {
         match self.pe.elf_header {
            Some(info) => info,
            None => String::from("not a elf file")
        }       
    }
}

#[cfg(test)]
mod test_adaptor {
    use super::*;
    #[test]
    fn test_adaptor() {
        let elf = Elf::default();
        assert_eq!("elf".to_string(), Linux::execute(elf));
        let pe = Pe::default();
        assert_eq!("not a elf file".to_string(), Linux::execute(pe));
        let pe = Pe::default();
        let transformer = PeTransformer::new(pe);
        assert_eq!("pe".to_string(), Linux::execute(transformer));
    }
}
