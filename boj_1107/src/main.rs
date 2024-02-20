use std::cmp;
use std::io::Read;

fn main() {
	let (target, btns) = input().expect("input");
	let mut min = target.abs_diff(100);

	if let Some(n) = press_number(&btns, (0..target).rev()) {
		min = cmp::min(min, n.to_string().len() + target - n);
	}
	if let Some(n) = press_number(&btns, target..=1_000_000) {
		min = cmp::min(min, n.to_string().len() + n - target);
	}
	print!("{min}")
}

fn press_number(btns: &Vec<bool>, rng: impl Iterator<Item = usize>) -> Option<usize> {
	rng.filter(|x| is_possible(&btns, *x)).next()
}

fn is_possible(btns: &Vec<bool>, mut x: usize) -> bool {
	while x > 9 {
		if !btns[x % 10] {
			return false;
		}
		x /= 10;
	}
	btns[x]
}

fn input() -> Result<(usize, Vec<bool>), Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf.split_ascii_whitespace().flat_map(|x| x.parse::<_>());

	let (Some(target), Some(_)) = (iter.next(), iter.next()) else {
		Err(Box::new(std::fmt::Error))?
	};

	let mut btns = vec![true; 10];
	iter.for_each(|x| btns[x] = false);

	Ok((target, btns))
}
