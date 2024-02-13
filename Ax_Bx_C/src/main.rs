use std::io::Read;

fn gcd(a: isize, b: isize) -> isize {
	if b % a == 0 {
		return a;
	}

	gcd(b % a, a)
}

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

fn main() {
	let (a, b, c) = input().expect("INPUT");

	if let Some(s) = check_zero(a, b, c) {
		print!("{s}");
		return;
	}

	let d = gcd(
		std::cmp::min(a.abs(), b.abs()),
		std::cmp::max(a.abs(), b.abs()),
	);

	if c % d != 0 {
		print!("Not Exist");
		return;
	}

	let ap = a.abs() / d;
	let bp = b.abs() / d;
	let cp = c / d;

	let mut x = 0;
	let mut y = 0;

	loop {
		if (ap * x + 1) % bp == 0 {
			y = (ap * x + 1) / bp;
			x *= -1;
			break;
		}

		if (ap * x - 1) % bp == 0 {
			y = (ap * x - 1) / bp;
			y *= -1;
			break;
		}
		x += 1;
	}

	x *= cp;
	y *= cp;
	x = if a.is_negative() { -x } else { x };
	y = if b.is_negative() { -y } else { y };

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
