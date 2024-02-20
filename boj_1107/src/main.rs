use std::{collections::HashSet, io::Read};

fn main() {
	let (target, btns) = input().expect("input");

	let mut min = target.abs_diff(100);

	for btn in btns.iter() {
		goto_channel(&btns, *btn, 1, target, &mut min);
	}

	print!("{min}")
}

fn goto_channel(btns: &Vec<usize>, ch: usize, count: usize, target: usize, min: &mut usize) {
	if count > 6 {
		return;
	}

	*min = std::cmp::min(target.abs_diff(ch) + count, *min);

	if ch == 0 {
		return;
	}

	for btn in btns {
		goto_channel(btns, ch * 10 + btn, count + 1, target, min);
	}
}

fn input() -> Result<(usize, Vec<usize>), Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<usize>());

	let (Some(target), Some(_)) = (iter.next(), iter.next()) else {
		Err(Box::new(std::fmt::Error))?
	};

	let disabled = iter.collect::<HashSet<usize>>();
	let btns = (0..10)
		.filter(|x| !disabled.contains(x))
		.collect::<Vec<usize>>();

	Ok((target, btns))
}
