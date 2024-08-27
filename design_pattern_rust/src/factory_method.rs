
pub trait ExecutableFile {
    fn execute(&self);
}

pub trait Compiler {
    fn complie(&self) -> Box<dyn ExecutableFile>;
}

pub struct Elf;
pub struct Pe;
pub struct Macho;

pub struct ElfComplier;
pub struct PeCompiler;
pub struct MachoCompiler;

impl ExecutableFile for Elf {
    fn execute(&self) {
        println!("elf running");
    }
}

impl ExecutableFile for Pe {
    fn execute(&self) {
        println!("pe running");
    }
}

impl ExecutableFile for Macho {
    fn execute(&self) {
        println!("macho running");
    }
}

impl Compiler for PeCompiler {
    fn complie(&self) -> Box<dyn ExecutableFile> {
        Box::new(Pe)
    }
}

impl Compiler for ElfComplier {
    fn complie(&self) -> Box<dyn ExecutableFile> {
        Box::new(Elf)
    }
}

impl Compiler for MachoCompiler {
    fn complie(&self) -> Box<dyn ExecutableFile> {
        Box::new(Macho)
    }
}

#[cfg(test)]
mod test_factory_method {
    use super::*;
    #[test]
    fn test_factory_method() {
        let complier: Box<dyn Compiler> = if cfg!(target_os = "windows") {
            Box::new(PeCompiler)
        } else if cfg!(target_os = "linux") {
            Box::new(ElfComplier)
        } else if cfg!(target_os = "macos") {
            Box::new(MachoCompiler)
        } else {
            panic!("unknown system")
        };
        let execute_file = complier.complie();
        execute_file.execute();
    }
}
