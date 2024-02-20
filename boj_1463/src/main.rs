use std::io::Read;

fn main() {
	let n = input().expect("input");

	if n <= 2 {
		print!("{}", n - 1);
		return;
	}

	let p3 = n.ilog(3);
	let p2 = n.ilog2();
	let mut min = usize::MAX;

	for i3 in 0..=p3 {
		let x3 = 3_usize.pow(i3);
		for i2 in 0..=p2 {
			let x2 = 2_usize.pow(i2);
			let x = (x2 * x3) as usize;

			if x > n {
				break;
			}

			let candidate = (n - x) + (i2 + i3) as usize;
			min = std::cmp::min(min, candidate);
		}
	}

	print!("{min}");
}

fn input() -> Result<usize, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let x = buf.trim().parse::<usize>()?;

	Ok(x)
}
