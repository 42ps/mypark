### 문제 소개
[boj_1918](https://www.acmicpc.net/problem/1918)

### 입/출력 분석
- 모든 입/출력 경우의 수를 나열하시오.

```
E' -> E
E -> T + E
E -> T - E
E -> T
T -> F * T
T -> F / T
T -> F
F -> n
F -> ( E )
```

위의 문법을 가진 문자열.


### 풀이
- 풀이 과정 (풀이의 논리가 담긴 글)

문자 -> append.
ops ->  while stack.top()의 우선순위가 ops보다 낮으면 pop else push ops
여는 괄호 -> reculsive call.
닫는 괄호 -> return.

- 풀이의 중심이 되는 알고리즘이 무엇인가?
stack과 재귀호출.

- 왜 이 알고리즘을 선택했는가?
괄호를 처리하는 데에 재귀호출이 적절하고, 연산 우선순위를 처리할 때 스택이 적절해서.

- 시간복잡도를 계산하시오. O(N)

- 공간복잡도를 계산하시오. O(N)

- special case가 있는가? 흠 ..?

### 슈도 코드 작성

fn to_postfix(infix: &str) {
	let mut result = String::new();

	for (i, c) in infix.iter.enumerate() {
		match c {
			'(' => result.append(to_postfix(infix[i..])),
			')' => {
				while let Some(x) = stack.pop() {
					result.push(x)
				}
				return result
			},
			'+' | '-' | '*' | '/' => {
				while priority(stack.top) > priority() {
					let x = stack.pop();
					result.push(x)
				}

				stack.push(c)
			}
			_ => result.push(c),
		}
	}


	while let Some(x) = stack.pop() {
		result.push(x)
	}
	return result
}


### 소스 코드 작성
제출 파일.

### 테스트 작성
