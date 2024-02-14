use std::io::Read;

fn check_zero(a: isize, b: isize, c: isize) -> Option<String> {
	if a != 0 && b != 0 && c != 0 {
		return None;
	}

	if c == 0 {
		return Some("0 0".to_string());
	}

	if b != 0 && c % b == 0 {
		return Some(format!("0 {}", c / b));
	}
	if a != 0 && c % a == 0 {
		return Some(format!("{} 0", c / a));
	}

	Some("Not Exist".to_string())
}

fn egcd(a: isize, b: isize) -> (isize, isize, isize) {
	let (mut old_r, mut r) = (a, b);
	let (mut old_x, mut x) = (1, 0);
	let (mut old_y, mut y) = (0, 1);

	while r != 0 {
		let q = old_r / r;
		(old_r, r) = (r, old_r % r);
		(old_x, x) = (x, old_x - x * q);
		(old_y, y) = (y, old_y - y * q);
	}

	(old_r, old_x, old_y)
}

fn main() {
	let (a, b, c) = input().expect("INPUT");

	if let Some(s) = check_zero(a, b, c) {
		print!("{s}");
		return;
	}

	let (gcd, x, y) = egcd(a, b);

	if c % gcd != 0 {
		print!("Not Exist");
		return;
	}

	let q = c / gcd;
	let x = x * q;
	let y = y * q;

	print!("{x} {y}");
}

fn input() -> Result<(isize, isize, isize), Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<isize>());

	if let (Some(a), Some(b), Some(c)) = (iter.next(), iter.next(), iter.next()) {
		Ok((a, b, c))
	} else {
		Err(Box::new(std::fmt::Error))
	}
}
