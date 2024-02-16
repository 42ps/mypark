use std::io::BufRead;
use std::io::BufWriter;
use std::io::Write;

fn main() {
	let stdin = std::io::stdin();
	let lock = stdin.lock();
	let mut lines = lock.lines();

	let _ = lines.next().unwrap().unwrap().parse::<usize>().expect("N");

	let mut v = vec![0; 10_000];
	for line in lines {
		let x = line.expect("X").trim().parse::<usize>().expect("x");
		v[x - 1] += 1;
	}

	let stdout = std::io::stdout();
	let mut buf = BufWriter::with_capacity(4_096_000, stdout);

	for i in 1..10_001 {
		let e = v[i - 1];
		for _ in 0..e {
			let _ = writeln!(buf, "{i}");
		}
	}
}
