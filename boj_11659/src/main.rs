use std::fmt::Write;
use std::io::Read;

fn main() {
	let (arr, sections) = input().expect("input");
	let mut acc = vec![0; arr.len() + 1];
	let mut output = String::new();

	acc[0] = arr[0];

	for (i, a) in arr.iter().enumerate() {
		acc[i + 1] = acc[i] + a
	}

	for s in sections {
		let _ = writeln!(output, "{}", acc[s.1] - acc[s.0 - 1]);
	}

	print!("{output}");
}

fn input() -> Result<(Vec<usize>, Vec<(usize, usize)>), Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf.split_ascii_whitespace().flat_map(|x| x.parse::<_>());

	let (Some(n), Some(m)) = (iter.next(), iter.next()) else {
		Err(Box::new(std::fmt::Error))?
	};

	let arr = (0..n)
		.map(|_| iter.next())
		.filter_map(|x| x)
		.collect::<Vec<_>>();

	let sections = (0..m)
		.map(|_| (iter.next(), iter.next()))
		.filter_map(|(x, y)| x.zip(y))
		.collect::<Vec<_>>();

	Ok((arr, sections))
}
