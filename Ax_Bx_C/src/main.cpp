#include <iostream>

using namespace std;

typedef long int i64;

i64 gcd(i64 a, i64 b) {
	// a < b
	// a != 0
	if (b % a == 0) {
		return a;
	}

	return gcd(b % a, a);
}

int is_zero(i64 a, i64 b, i64 c) {
	if (a != 0 && b != 0 && c != 0) {
		return 0;
	}

	if (c == 0) {
		cout << "0 0";
	} else if (b != 0 && c % b == 0) {
		cout << "0 " << c / b;
	} else if (a != 0 && c % a == 0) {
		cout << c / a << " 0";
	} else {
		cout << "Not Exist";
	}

	return 1;
}

int main() {
	i64 a, b, c;
	cin >> a >> b >> c;

	if (is_zero(a,b,c)) {
		return 0;
	}

	i64 d = gcd(min(abs(a), abs(b)), max(abs(a), abs(b)));

	if (c % d != 0) {
		cout << "Not Exist";
		return 0;
	}

	i64 ap = abs(a) / d;
	i64 bp = abs(b) / d;
	i64 cp = c / d;

	i64 x = 0;
	i64 y = 0;

	while (true) {
		if ((ap * x + 1) % bp == 0) {
			y = (ap * x + 1) / bp;
			x *= -1;
			break;
		}

		if ((ap * x - 1) % bp == 0) {
			y = (ap * x - 1) / bp;
			y *= -1;
			break;
		}
		x++;
	}

	x *= cp;
	y *= cp;

	if (a < 0) {
		x *= -1;
	}

	if (b < 0) {
		y *= -1;
	}

	cout << x << " " << y;

	return 0;
}
