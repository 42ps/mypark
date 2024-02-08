use std::collections::VecDeque;
use std::fmt::Write;
use std::io::Read;

fn main() {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf).expect("input");

	let mut output = String::new();
	let mut input = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<usize>());

	let case_count = input.next().expect("T");
	for _ in 0..case_count {
		let one_case = parse_one_case(&mut input).expect("One case");
		let _ = writeln!(output, "{}", solve(one_case));
	}

	print!("{output}");
}

fn solve((m, n, cabbages): (usize, usize, Vec<(usize, usize)>)) -> usize {
	let mut map: Vec<Vec<usize>> = vec![vec![0; n]; m];

	for c in cabbages {
		map[c.0][c.1] = 1;
	}

	let mut count = 0;
	for row in 0..m {
		for col in 0..n {
			if map[row][col] == 1 {
				put_worm(&mut map, row, col);
				count += 1;
			}
		}
	}

	count
}

fn put_worm(map: &mut Vec<Vec<usize>>, row: usize, col: usize) {
	let mut q = VecDeque::new();

	let m = map.len() as isize;
	let n = map[0].len() as isize;
	let direction: [(isize, isize); 4] = [(-1, 0), (0, 1), (1, 0), (0, -1)];

	q.push_back((row, col));

	while let Some((x, y)) = q.pop_front() {
		for (dx, dy) in direction {
			let a = dx + x as isize;
			let b = dy + y as isize;
			let ua = a as usize;
			let ub = b as usize;

			if 0 <= a && a < m && 0 <= b && b < n && map[ua][ub] == 1 {
				map[ua][ub] = 2;
				q.push_back((ua, ub));
			}
		}
	}
}

fn parse_one_case<T: Iterator<Item = usize>>(
	iter: &mut T,
) -> Result<(usize, usize, Vec<(usize, usize)>), Box<dyn std::error::Error>> {
	let (Some(m), Some(n), Some(k)) = (iter.next(), iter.next(), iter.next()) else {
		return Err(Box::new(std::fmt::Error));
	};

	let mut v = Vec::new();

	for _ in 0..k {
		let (Some(x), Some(y)) = (iter.next(), iter.next()) else {
			return Err(Box::new(std::fmt::Error));
		};

		v.push((x, y));
	}

	Ok((m, n, v))
}
