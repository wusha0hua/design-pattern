
pub trait Compiler {
    fn compile_debug(&self) -> Box<dyn Debug>;
    fn compile_release(&self) -> Box<dyn Release>;
}

pub trait Debug {
    fn gdb(&self);  
}

pub trait Release {
    fn execute(&self);
}

pub struct ElfDebug;
pub struct ElfRelease;
pub struct PeDebug;
pub struct PeRelease;
pub struct MachoDebug;
pub struct MachoRelease;

pub struct ElfCompiler;
pub struct PeCompiler;
pub struct MachoCompiler;

impl Debug for ElfDebug {
    fn gdb(&self) {
        println!("elf debugging")
    }
}

impl Debug for PeDebug {
    fn gdb(&self) {
        println!("pe debugging")
    }
}

impl Debug for MachoDebug {
    fn gdb(&self) {
        println!("macho debugging")
    }
}

impl Release for ElfRelease {
    fn execute(&self) {
        println!("elf running")
    }
}

impl Release for PeRelease {
    fn execute(&self) {
        println!("pe running")
    }
}

impl Release for MachoRelease {
    fn execute(&self) {
        println!("macho running")
    }
}

impl Compiler for ElfCompiler {
    fn compile_debug(&self) -> Box<dyn Debug> {
        Box::new(ElfDebug)
    }
    fn compile_release(&self) -> Box<dyn Release> {
        Box::new(ElfRelease)
    }
}

impl Compiler for PeCompiler {
    fn compile_debug(&self) -> Box<dyn Debug> {
        Box::new(PeDebug)
    }
    fn compile_release(&self) -> Box<dyn Release> {
        Box::new(PeRelease)
    }
}

impl Compiler for MachoCompiler {
    fn compile_debug(&self) -> Box<dyn Debug> {
        Box::new(MachoDebug)
    }
    fn compile_release(&self) -> Box<dyn Release> {
        Box::new(MachoRelease)
    }
}

#[cfg(test)]
mod test_abstract_factory {
    use super::*;
    #[test]
    fn test_abstract_factory() {
        let compiler: Box<dyn Compiler> = if cfg!(target_os = "linux") {
            Box::new(ElfCompiler)
        } else if cfg!(target_os = "windows") {
            Box::new(PeCompiler)
        } else if cfg!(target_os = "macos") {
            Box::new(MachoCompiler)
        } else {
            panic!("unknown system")
        };
        let debug_version = compiler.compile_debug();
        let release_version = compiler.compile_release();
        debug_version.gdb();
        release_version.execute();
    }
}
