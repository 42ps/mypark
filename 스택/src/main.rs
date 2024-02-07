use std::fmt::Write;
use std::io::Read;

fn main() {
	let commands = input().expect("Input");
	let mut output = String::new();
	let mut stack = Vec::new();

	for com in commands {
		let to_print = match com.as_str() {
			"top" => Some(stack.last().map(|x| *x).unwrap_or(-1)),
			"size" => Some(stack.len() as isize),
			"empty" => Some(stack.is_empty() as isize),
			"pop" => Some(stack.pop().unwrap_or(-1)),
			x => {
				if let Some(num) = x.split_once(" ").and_then(|(_, x)| x.parse::<isize>().ok()) {
					stack.push(num);
				}
				None
			}
		};

		if let Some(p) = to_print {
			let _ = writeln!(output, "{p}");
		}
	}

	println!("{output}");
}

fn input() -> Result<Vec<String>, Box<dyn std::error::Error>> {
	let mut buf = String::new();
	std::io::stdin().read_to_string(&mut buf)?;

	Ok(buf
		.split("\n")
		.skip(1)
		.map(|x| x.to_string())
		.collect::<Vec<String>>())
}
