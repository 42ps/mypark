use std::{error::Error as StdErr, io::Read};

fn main() {
	let numbers = input().expect("Input Error");
	let mut nth_min = Vec::new();

	nth_min.push(isize::MAX);

	for n in numbers {
		let index = bsearch(&nth_min, n, 0, nth_min.len()).unwrap_or_default();
		if let Err(_) = try_replace(&mut nth_min, index, n) {
			nth_min.push(n);
		}
	}

	println!("{}", nth_min.len());

	// let mut iter = seq.iter();

	// if let Some(n) = iter.next() {
	// 	print!("{}", n);
	// }

	// for n in iter {
	// 	print!(" {}", n);
	// }
}

fn bsearch(numbers: &Vec<isize>, n: isize, low: usize, high: usize) -> Option<usize> {
	if low > high {
		return None;
	}

	let m = (low + high) / 2;

	if n < numbers[m] {
		m.checked_sub(1).and_then(|x| bsearch(numbers, n, low, x))
	} else if n == numbers[m] {
		Some(m)
	} else if m + 1 == numbers.len() || n <= numbers[m + 1] {
		Some(m + 1)
	} else {
		m.checked_add(1).and_then(|x| bsearch(numbers, n, x, high))
	}
}

fn try_replace(nums: &mut Vec<isize>, index: usize, n: isize) -> Result<(), ()> {
	if nums.len() <= index {
		return Err(());
	}

	if nums[index] > n {
		nums[index] = n;
	}

	Ok(())
}

fn input() -> Result<Vec<isize>, Box<dyn StdErr>> {
	let mut v = Vec::new();
	let mut s = String::new();

	std::io::stdin().read_to_string(&mut s)?;

	let mut sp = s.split_ascii_whitespace();
	sp.next();

	for e in sp {
		let n = e.parse::<isize>()?;
		v.push(n);
	}

	Ok(v)
}
