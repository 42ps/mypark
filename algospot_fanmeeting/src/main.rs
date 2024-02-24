use std::io::Read;

fn main() {
	let input = input().expect("input: members and fans");

	for case in input.chunks_exact(2) {
		println!("{}", solve(&case[0], &case[1]))
	}
}

fn solve(members: &str, fans: &str) -> usize {
	let mut expect_female = Vec::new();
	let mut jump = Vec::new();
	let mut nearest_x = None;

	for (i, m) in members.as_bytes().iter().enumerate() {
		if *m == b'M' {
			expect_female.push(i);
			jump.push(nearest_x.unwrap_or(i + 1))
		} else if nearest_x.is_none() {
			nearest_x = Some(if i != 0 { i } else { 1 });
		}
	}

	hug_all_fans(members.len(), fans.as_bytes(), &expect_female, &jump)
}

fn hug_all_fans(m: usize, fans: &[u8], exp_fm: &[usize], jump: &[usize]) -> usize {
	let n = fans.len();

	if n == 1 {
		return (exp_fm.is_empty() || fans[0] == b'F') as usize;
	}

	if n < m {
		return 0;
	}

	let half = n / 2;

	let left = hug_all_fans(m, &fans[..half], exp_fm, jump);
	let right = hug_all_fans(m, &fans[half..], exp_fm, jump);

	let s = (half + 1).checked_sub(m).unwrap_or_default();
	let e = (half + m - 1).clamp(0, n);
	let count = hug_partial_fans(m, &fans[s..e], exp_fm, jump);

	left + right + count
}

fn hug_partial_fans(m: usize, fans: &[u8], exp_fm: &[usize], jump: &[usize]) -> usize {
	let mut i = 0;
	let mut count = 0;
	let e = fans.len().checked_sub(m).unwrap_or_default();

	while (0..=e).contains(&i) {
		let fans = &fans[i..];
		if let Some((_, j)) = exp_fm
			.iter()
			.map(|x| fans[*x])
			.zip(jump)
			.filter(|(f, _)| *f != b'F')
			.next()
		{
			i += j;
		} else {
			count += 1;
			i += 1;
		}
	}
	count
}

fn input() -> Result<Vec<String>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	Ok(buf
		.split_ascii_whitespace()
		.skip(1)
		.map(|x| x.to_string())
		.collect::<_>())
}
