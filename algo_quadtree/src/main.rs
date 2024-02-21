use std::fmt::Write;
use std::io::Read;

fn main() {
	let quad_trees = input().expect("input: fmt");
	let mut output = String::new();

	for tree in quad_trees {
		let filpped = filp_quadtree(tree.as_bytes());

		let _ = writeln!(
			output,
			"{}",
			String::from_utf8(filpped).expect("input: ascii")
		);
	}

	print!("{output}");
}

fn filp_quadtree(tree: &[u8]) -> Vec<u8> {
	if tree[0] != b'x' {
		return tree[0..1].iter().map(|x| *x).collect();
	}

	let (_, child) = tree.split_at(1);

	let mut filpped = Vec::new();
	let mut index = 0;

	for _ in 0..4 {
		let v = filp_quadtree(&child[index..]);
		index += v.len();
		filpped.push(v);
	}

	filpped.swap(0, 2);
	filpped.swap(1, 3);

	let mut result = vec![b'x'];
	result.reserve(index + 1);
	result.extend(filpped.iter().flatten());

	result
}

fn input() -> Result<Vec<String>, Box<dyn std::error::Error>> {
	let mut buf = String::new();

	std::io::stdin().read_to_string(&mut buf)?;

	let mut iter = buf.split_ascii_whitespace();

	let Some(c) = iter.next().and_then(|x| x.parse::<usize>().ok()) else {
		Err(Box::new(std::fmt::Error))?
	};

	let mut trees = Vec::new();
	for s in iter {
		trees.push(s.to_string());
	}

	assert_eq!(trees.len(), c);

	Ok(trees)
}
