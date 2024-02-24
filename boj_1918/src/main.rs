use std::io::Read;

fn main() {
	let expr = input().expect("Input: expression");
	let mut iter = expr.as_bytes().iter();

	let postfix = String::from_utf8(to_postfix(&mut iter)).expect("Input: ascii");
	print!("{postfix}",);
}

fn input() -> Result<String, Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;
	Ok(buf)
}

fn to_postfix<'a>(infix: &mut impl Iterator<Item = &'a u8>) -> Vec<u8> {
	let mut result = Vec::new();
	let mut stack = Vec::new();

	while let Some(c) = infix.next() {
		match c {
			b'(' => result.append(&mut to_postfix(infix)),
			b')' => break,
			b'+' | b'-' | b'*' | b'/' => {
				while let Some(x) = stack.last().filter(|x| is_prior_than(**x, *c)) {
					result.push(*x);
					stack.pop();
				}
				stack.push(*c)
			}
			b' ' | b'\n' => {}
			_ => result.push(*c),
		}
	}

	stack.reverse();
	result.append(&mut stack);

	result
}

fn is_prior_than(x: u8, y: u8) -> bool {
	let p1 = match x {
		b'+' | b'-' => 1,
		b'*' | b'/' => 2,
		_ => unreachable!(),
	};

	let p2 = match y {
		b'+' | b'-' => 1,
		b'*' | b'/' => 2,
		_ => unreachable!(),
	};

	p1 >= p2
}
