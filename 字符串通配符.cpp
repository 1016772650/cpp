//��̬�滮��˼·���ص��ж�*���ֵ�λ��
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int isMatch(string checkStr, string srcStr)//�ж��Ƿ�ƥ��
{
	int m = checkStr.length();
	int n = srcStr.length();
	vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));//��ʼ��[m+1][n+1]�ռ�
	dp[0][0] = 1;//�߽����������ǵ�һ���ַ���*�����
	for (int i = 1; i <= m; ++i)
		dp[i][0] = dp[i - 1][0] && (checkStr[i - 1] == '*');//�߽�����
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char ch1 = checkStr[i - 1];
			char ch2 = srcStr[j - 1];
			if (ch1 == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] && (ch1 == ch2 || ch1 == '?');
		}
	return dp[m][n];
}
int main()
{
	string checkStr, srcStr;
	while (cin >> checkStr >> srcStr)
	{
		if (isMatch(checkStr, srcStr))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
