### 문제 소개
[algo_quadtree](https://www.algospot.com/judge/problem/read/QUADTREE)

### 입/출력 분석
- 모든 입/출력 경우의 수를 나열하시오.

C≤50, s.len() <= 1000 

C
s1
s2
...
sC

### 풀이
- 풀이 과정 (풀이의 논리가 담긴 글)

그림을 상하로 뒤집는다.
```
0 1 -> 2 3
2 3    0 1
```

아래의 쿼드트리를 뒤집으면 다음과 같이 바뀐다.
```
x        -> x
0 1 2 3     2 3 0 1
```

따라서, 트리의 자식노드들을 분할한 후 합치면서 순서를 바꾸어주면 된다.

- 풀이의 중심이 되는 알고리즘이 무엇인가?
재귀를 이용한 분할과 정복

- 왜 이 알고리즘을 선택했는가?
책 내용 학습

- 시간복잡도를 계산하시오.
문자열 길이를 N이라 했을 때, O(N logN)

- 공간복잡도를 계산하시오. O(2N)

- special case가 있는가?

### 슈도 코드 작성

```
fn filp_quadtree(tree: &[char]) -> Vec<char> {

	if tree[0] != 'x' {
		return tree[0..1].iter().collect<_>();
	}

	let (_, child) = tree.split(1);

	let filpped = Vec::new();
	let mut index = 0;

	for _ in 0..4 {
		let v = filp_quadtree(child[index..]);
		index += v.len();
		filpped.push_back(v);
	}

	swap(filpped[0], filpped[2]);
	swap(filpped[1], filpped[3]);

	let result = Vec::new();
	result.reserve(index);

	for (src, dst) in filpped.iter().flat().zip(reuslt) {
		*dst = src
	}

	result
}
```

### 소스 코드 작성
제출 파일.

### 테스트 작성
