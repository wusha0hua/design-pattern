use std::collections::HashMap;


pub trait Server {
    fn handle_request(&mut self, ip: &str) -> String;
}

pub struct Application;

impl Server for Application {
    fn handle_request(&mut self, _: &str) -> String {
        "Ok".into()
    }
}

pub struct NginxServer {
    application: Application,
    max_allowed_requests: usize,
    limiter: HashMap<String, usize>,
}

impl NginxServer {
    pub fn new() -> Self {
        Self { 
            application: Application, 
            max_allowed_requests: 2, 
            limiter: HashMap::new() 
        }
    }
    pub fn check(&mut self, ip: &str) -> bool {
        let request = self.limiter.entry(ip.to_string()).or_insert(1);
        if *request > self.max_allowed_requests {
            return false;
        }
        *request += 1;
        true
    }
}

impl Server for NginxServer {
    fn handle_request(&mut self, ip: &str) -> String {
        if !self.check(ip) {
            "refuse".to_string()
        } else {
            self.application.handle_request(ip)
        }
    }
}

#[cfg(test)]
mod test_proxy {
    use crate::proxy::Server;

    use super::NginxServer;
    #[test]
    fn test_proxy() {
        let mut nginx = NginxServer::new();
        let ip1 = "127.0.0.1";
        let ip2 = "127.0.0.2";
        assert_eq!("Ok", nginx.handle_request(ip1));
        assert_eq!("Ok", nginx.handle_request(ip1));
        assert_eq!("refuse", nginx.handle_request(ip1));
        assert_eq!("Ok", nginx.handle_request(ip2));
    }
}
