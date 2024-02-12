fn main() {
	let v = vec![3, 1, -1, 2];
	let mut m = v[0];
	let mut i = 0;

	// loop invariant: m은 v[0..i] 중 최소값이다.
	while i < v.len() {
		if v[i] < m {
			m = v[i];
		}
		i += 1;
		// loop invariant: m은 v[0..i] 중 최소값이다.
	}

	// m은 v[0..n] 중 최소값이다.
	println!("{m}");
}
