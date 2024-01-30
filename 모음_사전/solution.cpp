#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> vowel;

int generate_word(int depth, string &generated, const string &word, int &ans)
{
	// cout << generated << endl;
	if (depth == 5 || generated.size() < depth)
	{
		if (word == generated)
		{
			return 1;
		}
		else
		{
			ans++;
			return 0;
		}
	}

	for (int i = -1; i < (int)vowel.size(); i++)
	{
		if (i == -1)
		{
			if (generate_word(depth + 1, generated, word, ans))
			{
				return 1;
			}
		}
		else
		{
			generated.push_back(vowel[i]);

			if (generate_word(depth + 1, generated, word, ans))
			{
				return 1;
			}

			generated.pop_back();
		}
	}
	return 0;
}

int solution(string word)
{
	int ans = 0;

	vowel.push_back('A');
	vowel.push_back('E');
	vowel.push_back('I');
	vowel.push_back('O');
	vowel.push_back('U');

	for (auto v : vowel)
	{
		string generated;
		generated.push_back(v);

		if (generate_word(1, generated, word, ans))
		{
			break;
		}
	}
	return ans + 1;
}

int main(void)
{
	// cout << solution("A") << endl;
	// cout << solution("AA") << endl;
	// cout << solution("AAA") << endl;
	// cout << solution("AAAA") << endl;
	// cout << solution("AAAAA") << endl;
	// cout << solution("AAAAE") << endl;
	cout << solution("AAAE") << endl;
	return 0;
}
