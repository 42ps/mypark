#include <iostream>

using namespace std;

typedef long int i64;

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

i64 egcd(i64 a, i64 b, i64 *rx, i64 *ry) {
    i64 old_r = a;
    i64 r = b;

    // old_r = a * old_x + b * old_y
    // r = a * x + b * y

    i64 old_x = 1;
    i64 x = 0;

    i64 old_y = 0;
    i64 y = 1;

    while (r != 0) {
        i64 tr,tx,ty,q;

        q = old_r / r;

        tr = r;
        r = old_r % r;
        old_r = tr;

        tx = x;
        x = old_x - x * q;
        old_x = tx;

        ty = y;
        y = old_y - y * q;
        old_y = ty;
    }

    *rx = old_x;
    *ry = old_y;
    return old_r;
}

int main() {
	i64 a, b, c;
	cin >> a >> b >> c;

	if (is_zero(a,b,c)) {
		return 0;
	}

    i64 x,y;
	i64 d = egcd(a, b, &x, &y);

	if (c % d != 0) {
		cout << "Not Exist";
		return 0;
	}

    x *= c / d;
    y *= c / d;

	cout << x << " " << y;

	return 0;
}
