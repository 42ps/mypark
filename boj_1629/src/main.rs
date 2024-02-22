use std::io::Read;

fn main() {
	let (a, b, c) = input().expect("input: non-zero integers");

	print!("{}", pow_mod(a, b, c));
}

fn pow_mod(base: usize, pow: usize, m: usize) -> usize {
	if pow == 0 {
		return 1;
	}

	let half = pow_mod(base, pow / 2, m);
	let even = (half * half) % m;
	(even * if pow % 2 != 0 { base % m } else { 1 }) % m
}

fn input() -> Result<(usize, usize, usize), Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf.split_ascii_whitespace().flat_map(|x| x.parse::<_>());

	if let (Some(a), Some(b), Some(c)) = (iter.next(), iter.next(), iter.next()) {
		Ok((a, b, c))
	} else {
		Err(Box::new(std::fmt::Error))
	}
}
