use std::fmt::Write;
use std::io::Read;

fn main() {
	let input = input().expect("Input");
	let mut output = String::new();
	let mut lis = Vec::new();
	let mut nth_min = Vec::new();

	nth_min.push(isize::MAX);

	for n in input {
		if let Some(_) = nth_min.last().filter(|l| **l < n) {
			lis.push((n, nth_min.len()));
			nth_min.push(n);
		} else {
			let ri = nth_min.partition_point(|x| *x < n);
			lis.push((n, ri));
			nth_min[ri] = n;
		}
	}

	let lis = get_lis(lis, nth_min.len());

	let _ = writeln!(output, "{}", lis.len());
	let mut iter = lis.iter();
	if let Some(s) = iter.next() {
		let _ = write!(output, "{}", s);
	}

	for s in iter {
		let _ = write!(output, " {}", s);
	}

	print!("{output}");
}

fn get_lis(lis_temp: Vec<(isize, usize)>, n: usize) -> Vec<isize> {
	let mut v = (0..n).map(|_| isize::MAX).collect::<Vec<isize>>();
	let mut l = v.len() - 1;

	for (n, i) in lis_temp.into_iter().rev() {
		if l == i {
			v[i] = n;

			if let Some(x) = l.checked_sub(1) {
				l = x;
			} else {
				break;
			}
		}
	}

	v
}

fn input() -> Result<Vec<isize>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let v = buf
		.split_ascii_whitespace()
		.flat_map(|x| str::parse::<isize>(x))
		.skip(1)
		.collect::<Vec<isize>>();
	Ok(v)
}
