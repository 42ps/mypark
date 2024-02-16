use std::fmt::Write;

fn main() {
	let mut buf = String::new();
	let mut output = String::new();
	std::io::stdin().read_line(&mut buf).expect("C");
	let c = buf.trim().parse::<usize>().expect("C");

	for _ in 0..c {
		let (mut map, empty_count) = read_map().expect("Map");

		let cnt = match empty_count % 3 {
			0 => find_case(&mut map, 0, empty_count / 3),
			_ => 0,
		};

		let _ = writeln!(output, "{cnt}");
	}

	print!("{output}")
}

fn read_map() -> Result<(Vec<Vec<bool>>, usize), Box<dyn std::error::Error>> {
	let mut empty_count = 0;
	let mut buf = String::new();
	let mut map = Vec::new();

	std::io::stdin().read_line(&mut buf)?;

	let mut iter = buf
		.split_ascii_whitespace()
		.flat_map(|x| x.parse::<usize>());

	let (Some(h), Some(_)) = (iter.next(), iter.next()) else {
		return Err(Box::new(std::fmt::Error));
	};

	for _ in 0..h {
		buf.clear();
		std::io::stdin().read_line(&mut buf)?;

		let v = buf
			.trim()
			.as_bytes()
			.iter()
			.map(|x| *x == b'#')
			.collect::<Vec<bool>>();
		empty_count += v.iter().filter(|x| !**x).count();

		map.push(v);
	}

	Ok((map, empty_count))
}

const BLOCKS: [[(usize, usize); 3]; 4] = [
	[(0, 1), (1, 0), (1, 1)],
	[(0, 0), (1, 0), (1, 1)], // ㄴ
	[(0, 0), (0, 1), (1, 0)],
	[(0, 0), (0, 1), (1, 1)], // ㄱ
];

#[derive(Clone, Copy, Debug)]
struct BlkType(usize);

impl BlkType {
	fn new(x: usize) -> Option<Self> {
		if x >= 4 {
			None
		} else {
			Some(BlkType(x))
		}
	}

	fn id(&self) -> usize {
		self.0
	}
}

fn find_case(map: &mut Vec<Vec<bool>>, index: usize, blk_cnt: usize) -> usize {
	if blk_cnt == 0 {
		return 1;
	}

	let w = map[0].len();
	let h = map.len();
	let mut sum = 0;

	let end = (w - 1) * (h - 1);
	for i in index..end {
		let cp = (i / (w - 1), i % (w - 1));
		let putables = get_putable_blocks(map, cp);

		for blk in putables {
			put_block(map, cp, blk);

			sum += find_case(map, i + 1, blk_cnt - 1);

			remove_block(map, cp, blk)
		}

		if !map[cp.0][cp.1] {
			break;
		}
	}

	sum
}

fn get_putable_blocks(map: &Vec<Vec<bool>>, c: (usize, usize)) -> Vec<BlkType> {
	let mut result = Vec::new();
	let n = if map[c.0][c.1] { 0 } else { 1 };

	for (i, blk) in BLOCKS.iter().enumerate().skip(n) {
		let mut is_possible = true;
		for (x, y) in blk.map(|(x, y)| (c.0 + x, c.1 + y)) {
			if map[x][y] {
				is_possible = false;
				break;
			}
		}

		if let Some(x) = BlkType::new(i).filter(|_| is_possible) {
			result.push(x)
		}
	}
	result
}

fn put_block(map: &mut Vec<Vec<bool>>, point: (usize, usize), blk: BlkType) {
	set_block(map, point, blk, true);
}

fn remove_block(map: &mut Vec<Vec<bool>>, point: (usize, usize), blk: BlkType) {
	set_block(map, point, blk, false);
}

fn set_block(map: &mut Vec<Vec<bool>>, point: (usize, usize), blk: BlkType, v: bool) {
	for (x, y) in BLOCKS[blk.id()].map(|(x, y)| (point.0 + x, point.1 + y)) {
		map[x][y] = v;
	}
}
