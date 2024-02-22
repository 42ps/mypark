use std::cmp::Reverse;
use std::fmt::Write;
use std::{collections::binary_heap::BinaryHeap, io::Read};

fn main() {
	let input = input().expect("input: integers");
	let mut output = String::new();

	let mut pq = BinaryHeap::new();

	for e in input {
		if e != 0 {
			pq.push(Reverse((e.abs(), e.is_positive())));
		} else {
			let x = pq
				.pop()
				.map(|e| e.0)
				.map(|(e, sign)| e * if sign { 1 } else { -1 })
				.unwrap_or_default();
			let _ = writeln!(output, "{}", x);
		}
	}

	print!("{output}");
}

fn input() -> Result<Vec<isize>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	Ok(buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<_>())
		.skip(1)
		.collect())
}
