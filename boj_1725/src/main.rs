use std::cmp;
use std::io::Read;

fn main() {
	let histogram = input().expect("Input: histogram");

	print!("{}", calc_area(&histogram));
}

fn input() -> Result<Vec<usize>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	Ok(buf
		.split_ascii_whitespace()
		.skip(1)
		.flat_map(|x| x.parse())
		.collect())
}

fn calc_area(arr: &[usize]) -> usize {
	if arr.len() == 1 {
		return arr[0];
	}

	let n = arr.len();
	let half = n / 2;

	let left = calc_area(&arr[..half]);
	let right = calc_area(&arr[half..]);

	let mut j = Some(half);
	let mut i = Some(half - 1);
	let mut h = usize::MAX;
	let mut area = 0;
	let mut c = 0;

	// j > i
	while c < n {
		let w = j.unwrap_or_default() - i.unwrap_or_default();
		let lh = i.map(|x| arr[x]).unwrap_or_default();
		let rh = j.and_then(|x| arr.get(x)).map(|x| *x).unwrap_or_default();

		if lh > rh {
			h = cmp::min(h, lh);
			i = i.and_then(|x| x.checked_sub(1));
		} else {
			h = cmp::min(h, rh);
			j = j.and_then(|x| x.checked_add(1));
		}

		area = cmp::max(area, w * h);
		c += 1;
		// j > i
	}

	cmp::max(area, cmp::max(left, right))
}
