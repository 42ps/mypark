use std::io::Read;

fn main() {
	let (k, mut row, mut col) = input().expect("input");

	let mut p = pow(2, k - 1);
	let mut q = pow(4, k - 1);

	let mut sum = 0;

	while p != 0 {
		let x = row / p * 2 + col / p;
		sum += x * q;

		row = row % p;
		col = col % p;

		p /= 2;
		q /= 4;
	}

	println!("{sum}");
}

fn pow(base: usize, k: usize) -> usize {
	if k == 0 {
		return 1;
	}

	let half = pow(base, k / 2);
	(half * half) * if k % 2 == 1 { base } else { 1 }
}

fn input() -> Result<(usize, usize, usize), Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<usize>());

	if let (Some(n), Some(r), Some(c)) = (iter.next(), iter.next(), iter.next()) {
		Ok((n, r, c))
	} else {
		Err(Box::new(std::fmt::Error))
	}
}
