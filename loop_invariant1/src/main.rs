fn main() {
	let v = vec![3, 1, -1, 2];
	let mut m = isize::MAX;

	// // loop invariant: m은 v[0..i] 중 최소값이다. -> 공집합이므로 참.
	// let mut i = 0;
	// while i < v.len() {
	// 	if v[i] < m {
	// 		m = v[i];
	// 	}
	// 	i += 1;
	// 	// loop invariant: m은 v[0..i] 중 최소값이다.
	// }

	// loop invariant: m은 v[0..i] 중 최소값이다. -> 공집합이므로 참.
	for vi in v {
		if vi < m {
			m = vi;
		}
		// loop invariant: m은 v[0..i] 중 최소값이다.
	}

	// m은 v[0..i] 중 최소값이다. -> i == n이므로 m은 모든 원소의 최소값이다.
	println!("{m}");
}
