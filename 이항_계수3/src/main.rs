use std::{io::Read, ops::Range};

fn main() {
	let (n, r, m) = input().expect("Input");
	let ns = std::cmp::max(n - r, r) + 1;
	let ne = n + 1;
	let ds = 1;
	let de = std::cmp::min(n - r, r) + 1;

	let numerator = mul_mod(ns..ne, m);
	let inv_denom = pow_mod(mul_mod(ds..de, m), m - 2, m);

	print!("{}", (numerator * inv_denom) % m);
}

fn mul_mod(rng: Range<usize>, m: usize) -> usize {
	let mut result = 1;

	for i in rng {
		result *= i;
		result %= m;
	}
	result
}

fn pow_mod(base: usize, pow: usize, m: usize) -> usize {
	if pow == 0 {
		return 1;
	}

	let p_div2 = pow_mod(base, pow / 2, m);
	let mut result = 1;

	if pow % 2 == 0 {
		result *= p_div2;
		result *= p_div2;
	} else {
		result *= p_div2;
		result *= p_div2;
		result %= m;
		result *= base;
	};

	result % m
}

fn input() -> Result<(usize, usize, usize), Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf.split_ascii_whitespace();

	if let (Some(n), Some(r), Some(m)) = (
		iter.next().and_then(|x| x.parse::<usize>().ok()),
		iter.next().and_then(|x| x.parse::<usize>().ok()),
		iter.next().and_then(|x| x.parse::<usize>().ok()),
	) {
		Ok((n, r, m))
	} else {
		Err(Box::new(std::fmt::Error))
	}
}
