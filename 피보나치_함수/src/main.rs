use std::fmt::Write;
use std::{io::Read, ops::Add};

/// input
///
/// t
/// X1
/// X2
/// ...
/// Xt

/// output
///
/// f(X1)
/// ...
/// f(Xt)

/// 슈도코드
/// 입력 -> input[]
///
/// m = max(input)
/// dp = [(0, 0); m]
///
/// dp[0] = (1, 0)
/// dp[1] = (0, 1)
///
/// for i in (2..=m) {
/// 	dp[i] = dp[i - 2] + dp[i - 1];
/// }
///
/// for i in input {
/// 	println(dp[i])
/// }

#[derive(Clone, Copy)]
struct Counts(i32, i32);

impl Add for Counts {
	type Output = Counts;
	fn add(self, rhs: Self) -> Self::Output {
		Counts(self.0 + rhs.0, self.1 + rhs.1)
	}
}

fn main() {
	let input = input().expect("Input");
	let max = *input.iter().max().expect("Non-empty input");
	let mut dp = Vec::with_capacity(max + 1);

	dp.push(Counts(1, 0));
	dp.push(Counts(0, 1));

	for x in 2..=max {
		dp.push(dp[x - 1] + dp[x - 2]);
	}

	let mut output = String::new();
	for i in input {
		let _ = writeln!(output, "{} {}", dp[i].0, dp[i].1);
	}

	print!("{output}");
}

fn input() -> Result<Vec<usize>, Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	Ok(buf
		.split_ascii_whitespace()
		.skip(1)
		.flat_map(|x| x.parse::<usize>())
		.collect())
}
