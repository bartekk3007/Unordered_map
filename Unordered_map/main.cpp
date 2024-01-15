#include <iostream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct Hash
{
	int operator()(char a) const
	{
		return a;
	}
};

struct Equals
{
	bool operator()(char a, char b) const
	{
		if (abs(a - b) < 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	string s1 = "aaaabbb";

	unordered_map<char, int, Hash, Equals> letterUMap;

	for (auto iter = s1.begin(); iter != s1.end(); iter++)
	{
		letterUMap[*iter]++;
	}

	for (auto iter = letterUMap.begin(); iter != letterUMap.end(); iter++)
	{
		cout << iter->first << ' ' << iter->second << '\n';
	}

	return 0;
}