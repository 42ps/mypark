// INPUT
// 5
// 3 4
// 1 1
// 1 -1
// 2 2
// 3 3

// OUTPUT
// 1 -1
// 1 1
// 2 2
// 3 3
// 3 4

use std::fmt::Write;
use std::io::Read;

fn main() {
	let mut points = input().expect("coordinates");

	points.sort_unstable();

	let mut output = String::new();

	for p in points {
		let _ = writeln!(output, "{} {}", p.0, p.1);
	}

	print!("{output}");
}

fn input() -> Result<Vec<(isize, isize)>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.skip(1)
		.flat_map(|x| x.parse::<isize>());

	let mut v = Vec::new();

	while let [Some(x), Some(y)] = [(); 2].map(|_| iter.next()) {
		v.push((x, y))
	}

	Ok(v)
}
