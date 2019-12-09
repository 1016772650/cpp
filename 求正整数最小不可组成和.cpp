#if 0
class Solution {
public:
	/**
	 * ���������е���С������ɺ�
	 * ���룺��������arr
	 * ���أ����������е���С������ɺ�
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int min = arr[0];
		int max = 0;
		for (int i = 0; i < len; i++)
		{
			if (min > arr[i])
				min = arr[i];
			max += arr[i];
		}
		vector<int>dp(max + 1, 0);
		for (int i = 0; i < len; i++)
		{
			for (int j = max; j >= arr[i]; j--)
			{
				if (dp[j - arr[i]] + arr[i] > dp[j])
					dp[j] = dp[j - arr[i]] + arr[i];
			}
		}
		for (int i = min; i <= max; i++)
		{
			if (i != dp[i])
				return i;
		}
		return max + 1;
	}
};
#endif