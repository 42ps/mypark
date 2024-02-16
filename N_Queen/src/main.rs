use std::io::Read;

fn main() {
	let n = input().expect("N");
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)
}

fn input() -> Result {}
