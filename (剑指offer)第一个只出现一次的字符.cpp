class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		map<char, int>mp;
		for (int i = 0; i < str.length(); i++)
		{
			mp[str[i]]++;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (mp[str[i]] == 1) {
				return i;
				break;
			}
		}
		return -1;
	}
};