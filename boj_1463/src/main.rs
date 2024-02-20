use std::io::Read;

fn main() {
	let n = input().expect("input");

	if n <= 2 {
		print!("{}", n - 1);
	} else {
		let mut memo = vec![0; n + 1];

		memo[2] = 1;
		memo[3] = 1;
		print!("{}", solve(n, &mut memo));
	}
}

fn solve(n: usize, memo: &mut Vec<usize>) -> usize {
	if memo[n] != 0 {
		return memo[n];
	}

	let mut m = usize::MAX;

	if n % 3 == 0 {
		m = m.min(solve(n / 3, memo));
	}

	if n % 2 == 0 {
		m = m.min(solve(n / 2, memo));
	}

	m = m.min(solve(n - 1, memo));

	memo[n] = m + 1;
	memo[n]
}

fn input() -> Result<usize, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let x = buf.trim().parse::<usize>()?;

	Ok(x)
}
