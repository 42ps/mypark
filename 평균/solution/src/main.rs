use std::error::Error as StdErr;
use std::io::{self, Read};

fn main() {
	let arr = input().unwrap(); //.expect("Input Error");
	let m = arr.iter().max().unwrap(); //.expect("Empty Input");
	let sum = arr
		.iter()
		.fold(0.0, |sum, a| sum + (*a as f64 / (*m as f64) * 100.0));

	println!("{:.3}", sum / arr.len() as f64);
}

fn input() -> Result<Vec<usize>, Box<dyn StdErr>> {
	let mut buf = String::new();
	let mut v = Vec::new();

	io::stdin().read_to_string(&mut buf)?;
	let mut sp = buf.split_ascii_whitespace();

	sp.next();
	while let Some(snum) = sp.next() {
		let num = snum.parse()?;
		v.push(num);
	}

	Ok(v)
}
