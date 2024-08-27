

pub trait Compiler {
    type Output;
    fn fill_header(&mut self, info: &str);
    fn set_bits(&mut self, info: &str);
    fn preprocess(&mut self, info: &str);
    fn compile(&mut self, info: &str);
    fn assemble(&mut self, info: &str);
    fn link(&mut self, info: &str);
    fn attach_debug_info(&mut self, info: &str);
    fn optimize(&mut self, info: &str);
    fn output(&self) -> Self::Output;
}

pub struct Elf {
    info: String,
}
pub struct Pe {
    info: String,
}

impl Elf {
    pub fn extract(&self) {
        println!("{}", self.info)
    } 
}

impl Pe {
    pub fn extract(&self) {
        println!("{}", self.info)
    }
}

pub struct ElfCompiler {
    header: String,
    bits: String,
    preprocess_info: String,
    compile_info: String,
    assemble_info: String,
    link_info: String,
    debug_info: String,
    optimize_info: String,
}

pub struct PeCompiler {
    header: String,
    bits: String,
    preprocess_info: String,
    compile_info: String,
    assemble_info: String,
    link_info: String,
    debug_info: String,
    optimize_info: String,
}

impl Default for ElfCompiler {
    fn default() -> Self {
        Self { 
            header: String::new(), 
            bits: String::new(), 
            preprocess_info: String::new(), 
            compile_info: String::new(), 
            assemble_info: String::new(), 
            link_info: String::new(), 
            debug_info: String::new(), 
            optimize_info: String::new() 
        }
    }
}

impl Default for PeCompiler {
    fn default() -> Self {
        Self { 
            header: String::new(), 
            bits: String::new(), 
            preprocess_info: String::new(), 
            compile_info: String::new(), 
            assemble_info: String::new(), 
            link_info: String::new(), 
            debug_info: String::new(), 
            optimize_info: String::new() 
        }
    }
}

impl Compiler for ElfCompiler {
    type Output = Elf;
    fn fill_header(&mut self, info: &str) {
        self.header = info.to_string();
    }
    fn set_bits(&mut self, info: &str) {
        self.bits = info.to_string();
    }
    fn preprocess(&mut self, info: &str) {
        self.preprocess_info = info.to_string();
    }
    fn compile(&mut self, info: &str) {
        self.compile_info = info.to_string(); 
    }
    fn assemble(&mut self, info: &str) {
        self.assemble_info = info.to_string();
    }
    fn link(&mut self, info: &str) {
        self.link_info = info.to_string();
    }
    fn attach_debug_info(&mut self, info: &str) {
        self.debug_info = info.to_string();
    }
    fn optimize(&mut self, info: &str) {
        self.optimize_info = info.to_string();
    }
    fn output(&self) -> Self::Output {
        Elf {
            info: format!("
                header: {}\n
                bits: {}\n
                preprocess: {}\n
                compile: {}\n
                assemble: {}\n
                link: {}\n
                debug: {}\n
                optimize: {}\n
            ", 
            self.header,
            self.bits,
            self.preprocess_info,
            self.compile_info,
            self.assemble_info,
            self.link_info,
            self.debug_info,
            self.optimize_info
            )
        } 
    }
}

impl Compiler for PeCompiler {
    type Output = Pe;
    fn fill_header(&mut self, info: &str) {
        self.header = info.to_string();
    }
    fn set_bits(&mut self, info: &str) {
        self.bits = info.to_string();
    }
    fn preprocess(&mut self, info: &str) {
        self.preprocess_info = info.to_string();
    }
    fn compile(&mut self, info: &str) {
        self.compile_info = info.to_string(); 
    }
    fn assemble(&mut self, info: &str) {
        self.assemble_info = info.to_string();
    }
    fn link(&mut self, info: &str) {
        self.link_info = info.to_string();
    }
    fn attach_debug_info(&mut self, info: &str) {
        self.debug_info = info.to_string();
    }
    fn optimize(&mut self, info: &str) {
        self.optimize_info = info.to_string();
    }
    fn output(&self) -> Self::Output {
        Pe {
            info: format!("
                header: {}\n,
                bits: {}\n,
                preprocess: {}\n
                compile: {}\n
                assemble: {}\n
                link: {}\n
                debug: {}\n
                optimize: {}\n
            ", 
            self.header,
            self.bits,
            self.preprocess_info,
            self.compile_info,
            self.assemble_info,
            self.link_info,
            self.debug_info,
            self.optimize_info
            )
        } 
    }
}

pub struct Director;
impl Director {
    pub fn compiler_debug_elf_32(compiler: &mut impl Compiler) {
        compiler.fill_header("elf header");
        compiler.set_bits("32");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("attach debug info");
        compiler.optimize("debug version does not optimize");
    }
    pub fn compiler_debug_elf_64(compiler: &mut impl Compiler) {
        compiler.fill_header("elf header");
        compiler.set_bits("64");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("attach debug info");
        compiler.optimize("debug version does not optimize");
    }
    pub fn compiler_release_elf_32(compiler: &mut impl Compiler) {
        compiler.fill_header("elf header");
        compiler.set_bits("32");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("release version does not debug");
        compiler.optimize("optimize finish");
    }
    pub fn compiler_release_elf_64(compiler: &mut impl Compiler) {
        compiler.fill_header("elf header");
        compiler.set_bits("64");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("release version does not debug");
        compiler.optimize("optimize finish");
    }
    pub fn compiler_debug_pe_32(compiler: &mut impl Compiler) {
        compiler.fill_header("pe header");
        compiler.set_bits("32");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("attach debug info");
        compiler.optimize("debug version does not optimize");
    }
    pub fn compiler_debug_pe_64(compiler: &mut impl Compiler) {
        compiler.fill_header("pe header");
        compiler.set_bits("64");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("attach debug info");
        compiler.optimize("debug version does not optimize");
    }
    pub fn compiler_release_pe_32(compiler: &mut impl Compiler) {
        compiler.fill_header("pe header");
        compiler.set_bits("32");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("release version does not debug");
        compiler.optimize("optimize finish");
    }
    pub fn compiler_release_pe_64(compiler: &mut impl Compiler) {
        compiler.fill_header("pe header");
        compiler.set_bits("64");
        compiler.preprocess("preprocess finish");
        compiler.compile("compile finish");
        compiler.assemble("assemble finish");
        compiler.link("link finish");
        compiler.attach_debug_info("release version does not debug");
        compiler.optimize("optimize finish");
    }
}

#[cfg(test)]
mod test_builder {
    use super::*;
    #[test]
    fn test_builder() {
        let mut elf_compiler = ElfCompiler::default();
        let mut pe_compiler = PeCompiler::default();
        Director::compiler_debug_elf_64(&mut elf_compiler);
        let elf_debug_64 = elf_compiler.output();
        elf_debug_64.extract();
        Director::compiler_release_pe_32(&mut pe_compiler);
        let pe_32_release = pe_compiler.output();
        pe_32_release.extract();
    }
}
