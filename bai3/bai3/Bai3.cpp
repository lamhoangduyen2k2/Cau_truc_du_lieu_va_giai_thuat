#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <fstream>
using namespace std;
bool cp(string s, string t)
{
	for (char& c : s)
		c = tolower(c);
	for (char& c : t)
		c = tolower(c);
	return s < t;
}
int main()
{
	fstream input, output;
	input.open("data.txt", fstream::in);
	output.open("dictionary.txt", fstream::out);
	string s;
	vector <string> v;
	/*while (getline(input, s))
	{
		while (!s.empty() && s[0] == ' ') {
			s.erase(0, 1);
		}
		while (!s.empty() && s.back() == ' ')
			s.pop_back();
		while (s.find(' ') != -1)
		{
			string t = s.substr(0, s.find(' '));
			s.erase(0, t.length() + 1);
			v.push_back(t);
		}
		if (!s.empty())
			v.push_back(s);
	}
	sort(v.begin(), v.end(), cp);
	for (int i = 0; i < v.size(); i++)
	{
		output << v[i];
		if (i != v.size() - 1)
			output << '\n';
	}*/
	while (input >> s)
	{
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++)
	{
		transform(v.at(i).begin(), v.at(i).end(), v.at(i).begin(), ::tolower);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		output << v.at(i) << "\n";
	}
}