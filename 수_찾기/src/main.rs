use std::fmt::Write;
use std::io::Read;

fn main() {
	let (mut pool, to_find) = input().expect("Input");
	let mut output = String::new();

	pool.sort_unstable();

	for r in to_find.iter().map(|x| {
		pool.get(b_search(&pool, x) as usize)
			.filter(|y| *x == **y)
			.is_some()
	}) {
		let _ = writeln!(output, "{}", r as isize);
	}

	print!("{output}");
}

fn b_search(v: &Vec<isize>, target: &isize) -> isize {
	let mut lo: isize = -1;
	let mut hi: isize = v.len() as isize;

	while lo + 1 < hi {
		let mid = ((lo + hi) / 2) as usize;
		if v[mid] < *target {
			lo = mid as isize;
		} else {
			hi = mid as isize;
		}
	}
	hi
}

fn input() -> Result<(Vec<isize>, Vec<isize>), Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<isize>());

	let Some(n) = iter.next() else {
		return Err(Box::new(std::fmt::Error));
	};

	let pool = (0..n).flat_map(|_| iter.next()).collect::<Vec<isize>>();

	let Some(m) = iter.next() else {
		return Err(Box::new(std::fmt::Error));
	};

	let to_find = (0..m).flat_map(|_| iter.next()).collect::<Vec<isize>>();

	Ok((pool, to_find))
}
