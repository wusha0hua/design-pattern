
pub trait Component {
    fn chmod(&mut self);
}

pub struct File {
    name: &'static str,
}

pub struct Folder {
    name: &'static str,
    component: Vec<Box<dyn Component>>,
}

impl File {
    pub fn new(name: &'static str) -> Self {
        Self { name, }
    }
}

impl Folder {
    pub fn new(name: &'static str) -> Self {
        Self { 
            name, 
            component: Vec::new()
        }
    }
    pub fn add(&mut self, component: impl Component + 'static) {
        self.component.push(Box::new(component));
    }
}

impl Component for File {
    fn chmod(&mut self) {
        println!("{} chmod", self.name);
    }
}

impl Component for Folder {
    fn chmod(&mut self) {
        println!("{} chmod", self.name);
        for file in &mut self.component {
            file.chmod(); 
        }
    }
}

#[cfg(test)]
mod test_composite {
    use super::*;
    #[test]
    fn test_composite() {
        let mut folder = Folder::new("folder1");
        folder.add(Folder::new("folder2"));
        folder.add(File::new("file1"));
        folder.chmod();
    }
}
