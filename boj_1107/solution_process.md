### 문제 소개
[boj_1107](link_to_problem)

### 입/출력 분석
- 모든 입/출력 경우의 수를 나열하시오.

0 ≤ N ≤ 500,000
0 ≤ M ≤ 10

N
M
b0 b1 ... bm

### 풀이
- 풀이 과정 (풀이의 논리가 담긴 글)

1) 번호를 누르지 않는 경우. (100번에서 시작)
2) 번호를 눌러 채널을 옮기는 경우.

+-로 채널을 조정한다.

- 풀이의 중심이 되는 알고리즘이 무엇인가?
재귀를 이용한 완전탐색(permutation)

- 왜 이 알고리즘을 선택했는가?
자릿수가 충분히 작아서 완전탐색으로 구할 수 있을 것 같아서.

- 시간복잡도를 계산하시오. N의 자리수를 k(1 <= k <= 6)라 했을 때, O(10 ^ k)

- 공간복잡도를 계산하시오.

- special case가 있는가?

### 슈도 코드 작성

```
min = abs(channel - 100);

// initial condition: count = 1
goto_channel(btns, ch, count, target_ch, min) {
	if count > num_len(target_ch) {
		return;
	}

	min = min(abs(target_ch - ch) + count, min);

	for btn in btns {
		goto_channel(btns, ch * 10 + btn, count + 1, target_ch, min);
	}
}

for btn in btns {
	if btn != 0 {
		goto_channel(btns, btn, 1, target_ch, min);
	}
}

```

### 소스 코드 작성
제출 파일.

### 테스트 작성
