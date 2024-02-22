#include <iostream>
#include <vector>

using namespace std;

string flip_quadtree(string::const_iterator &it)
{
	auto head = it;
	it += 1;

	if (*head != 'x')
	{
		return string(1, *head);
	}
	auto upperleft = flip_quadtree(it);
	auto upperright = flip_quadtree(it);
	auto lowerleft = flip_quadtree(it);
	auto lowerright = flip_quadtree(it);

	return 'x' + lowerleft + lowerright + upperleft + upperright;
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		string s;
		cin >> s;

		auto it = s.cbegin();
		string v = flip_quadtree(it);

		cout << v << '\n';
	}
}