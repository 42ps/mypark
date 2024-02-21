#include <iostream>
#include <vector>

using namespace std;

string flip_quadtree(string::const_iterator s, string::const_iterator e)
{
	if (*s != 'x')
	{
		return string(1, *s);
	}

	s += 1;

	auto total_len = 0;
	vector<string> filpped;

	for (int i = 0; i < 4; i++)
	{
		auto child = flip_quadtree(s, e);

		s += child.length();
		total_len += child.length();

		filpped.push_back(child);
	}

	std::swap(filpped[0], filpped[2]);
	std::swap(filpped[1], filpped[3]);

	string result(1, 'x');
	result.reserve(total_len + 1);

	for (auto f : filpped)
	{
		result.append(f);
	}

	return result;
}

int main(void)
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		string s;
		cin >> s;

		string v = flip_quadtree(s.cbegin(), s.cend());

		cout << v << '\n';
	}
}