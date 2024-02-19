### 문제 소개
[clock_sync](https://www.algospot.com/judge/problem/read/CLOCKSYNC)

### 입/출력 분석
- 모든 입/출력 경우의 수를 나열하시오.

T
c1 c2 c3 ... c16
c1 c2 c3 ... c16
...

### 풀이
- 풀이 과정 (풀이의 논리가 담긴 글)

같은 스위치 누르는 횟수 < 4,

총 10개의 스위치가 있으므로 최대 30회를 누를 수 있음.

스위치의 누른 횟수를 기록하며 모든 경우의 수를 완전탐색하여,

가장 작은 횟수를 찾는다.

- 풀이의 중심이 되는 알고리즘이 무엇인가?
재귀를 이용한 완전탐색.

- 왜 이 알고리즘을 선택했는가?
제한 시간이 충분히 길어서.

- 시간복잡도를 계산하시오. O(10 ^ 30) -> O(2 ^ 18)

- 공간복잡도를 계산하시오. O(1)

- special case가 있는가?

### 슈도 코드 작성
```
press_switch(num, clocks, counts) {
	change_clocks(num, clocks, counts, 1)
}


undo_pressing(num, clocks, counts) {
	change_clocks(num, clocks, counts, -1)
}

change_clocks(num, clocks, counts, add) {
	for clk in clock_of_switch[num] {
		clocks[clk] += add;
	}

	counts[num] += add;
}


find_case (clocks, counts, press_count, min_count, start) {

//	if press_count >= min_count {
//		return;
//	}

	if ( is_all_12(clocks) ) {
		(*min_count) = min(press_count, min_count);
		return;
	}


//	for i in 0..16 { // 각 스위치를 순회
//		if counts[i] != 0 { // 스위치를 누를 수 있는 지?
//			press_switch(i, clocks, counts);
//
//			find_case(clocks, counts, press_count + 1, min_count );
//
//			undo_pressing(i, clocks, counts);
//		}
//	}

	for i in start..10 { // 스위치에 대한 조합
		for a in 1..=3 { // 스위치를 몇 번 누를 것인지
			press_switch(i, clocks, counts);

			find_case(clocks, counts, press_count + a, min_count, i + 1 );

			undo_pressing(i, clocks, counts);

		}
	}
}
```

### 소스 코드 작성
제출 파일.

### 테스트 작성
