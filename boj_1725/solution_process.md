### 문제 소개
[boj_1725](https://www.acmicpc.net/problem/1725)

### 입/출력 분석
- 모든 입/출력 경우의 수를 나열하시오.

N
H1
H2
...
Hn

1 ≤ N ≤ 100,000, 0 <= H <= 1,000,000,000

### 풀이
- 풀이 과정 (풀이의 논리가 담긴 글)

1. 영역의 너비와 동일한 너비를 가지는 직사각형의 넓이를 구함. -> 넓이 = 너비 * min(높이) -> 이 중 최대값.

2. 최소 높이를 가지는 막대그래프의 인덱스를 기준으로 영역을 분할. n개라면 n + 1개로 영역을 분할한다.

3. 각 영역에 대해 1번 2번 과정을 적용.

- 풀이의 중심이 되는 알고리즘이 무엇인가?
분할과 정복.

- 왜 이 알고리즘을 선택했는가?
종만북 연습문제.

- 시간복잡도를 계산하시오.
O(N logN)

- 공간복잡도를 계산하시오.
O(N)

- special case가 있는가?

### 슈도 코드 작성
```
index = vec![0]
min_h = usize::Max;
max_a = 0;

for (i, a) in arr.enumerate() {
	if a < min_h {
		min_h = a;
		index.push(i);
	} else if a == min_h {
		index.push(i);
	}
}
area = min_h * arr.len();

for i in (0..index.len() - 1) {
	let s = index[i];
	let e = index[i + 1];

	max_a = max(calc_area(&arr[s..e]), max_a);
}

max(area, max_a);
```

### 소스 코드 작성
제출 파일.

### 테스트 작성
