use std::io::Read;

#[allow(dead_code)]
#[rustfmt::skip]
const CLOCKS_OF_SWITCH: [[Option<usize>; 5]; 10] = [
	[ Some(0), Some(1),   Some(2),   None,     None],
	[ Some(3), Some(7),   Some(9),   Some(11), None],
	[ Some(4), Some(10),  Some(14),  Some(15), None],
	[ Some(0), Some(4),   Some(5),   Some(6),  Some(7)],
	[ Some(6), Some(7),   Some(8),   Some(10), Some(12)],
	[ Some(0), Some(2),   Some(14),  Some(15), None],
	[ Some(3), Some(14),  Some(15),  None,     None],
	[ Some(4), Some(5),   Some(7),   Some(14), Some(15)],
	[ Some(1), Some(2),   Some(3),   Some(4),  Some(5)],
	[ Some(3), Some(4),   Some(5),   Some(9),  Some(13)],
];

fn main() {
	let input = input().expect("INPUT");

	for mut case in input {
		solve(&mut case);
	}
}

fn change_clocks(num: usize, clocks: &mut [isize; 16], add: isize) {
	for clk in CLOCKS_OF_SWITCH[num].iter().filter_map(|x| *x) {
		clocks[clk] += add;
	}
}

fn is_all_12(clocks: &mut [isize; 16]) -> bool {
	clocks.iter().filter(|x| **x % 4 != 0).count() == 0
}

fn find_case(clocks: &mut [isize; 16], press_count: usize, min_count: &mut usize, start: usize) {
	if is_all_12(clocks) {
		(*min_count) = press_count;
		return;
	}

	for i in start..10 {
		for a in 1..=3 {
			change_clocks(i, clocks, a);

			find_case(clocks, press_count + a as usize, min_count, i + 1);

			change_clocks(i, clocks, a * -1);
		}
	}
}

fn solve(clocks: &mut [isize; 16]) {
	let mut output = 31;
	find_case(clocks, 0, &mut output, 0);

	if output == 31 {
		println!("-1");
	} else {
		println!("{output}");
	}
}

fn input() -> Result<Vec<[isize; 16]>, Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<isize>());

	let t = iter.next().ok_or_else(|| std::fmt::Error)? as usize;
	let mut v = vec![[0; 16]; t];

	for i in 0..t {
		for j in 0..16 {
			let x = iter.next().ok_or_else(|| std::fmt::Error)?;
			v[i][j] = x / 3;
		}
	}

	Ok(v)
}
