#define _CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

//ɾ�����������е��ظ���
/*
class EraseSameWord {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int i = 0;
		int j = 0;
		for (j = 1; j < nums.size(); ++j)
		{
			while (nums[i] != nums[j]) {
				nums[++i] = nums[j];
			}
		}
		return i + 1;
	}
};
*/
//�����������������?
//ʱ�临�Ӷ�Ϊn^3
/*
class Solution1{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int Rmax = -10000000;
		int sz = array.size();
		for (int i = 0; i < sz; ++i)
		{
			for(int j = 0; j < sz; j++)
			{
			int max = 0;
			for (int m = i; m <= j; m++) {
				max += array[m];
			}
			if (max > Rmax) {
				Rmax = max;
			}
			}

		}
		return Rmax;
		}
	};
//��������Ż�n^2
class Solution2 {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int Rmax = -10000000;
		int sz = array.size();
		for (int i = 0; i < sz; ++i)
		{
			int max = 0;
			for (int j = i; j < sz; j++)
			{
				max += array[j];
				if (max > Rmax) {
					Rmax = max;
				}
			}

		}
		return Rmax;
	}
};
*/
//״̬���� �� max( dp[ i ] ) = getMax( max( dp[ i -1 ] ) + arr[ i ] ,arr[ i ] ),��̬�滮��˼��
//����ʱ�临�Ӷ�ֻҪOn
/*
class Solution3 {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sz = array.size();
		int max = array[0];
		int Rmax = array[0];
		for (int i = 1; i < sz; ++i) {
			max = (array[i]) > (array[i] + max) ? (array[i]) : (array[i] + max);
		}
		if (max >= Rmax) {
			Rmax = max;
		}
		return Rmax;
	}
};
*/

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sz = array.size();
		int Sum = array[0];   //��ʱ���ֵ
		int MAX = array[0];   //�Ƚ�֮������ֵ

		for (int i = 1; i < sz; i++)
		{
			Sum = (Sum + array[i]) > array[i] ? (Sum + array[i]) : array[i];   //״̬����

			if (Sum >= MAX) {
				MAX = Sum;
			}
		}
		return MAX;
	}
};
int main()
{
	int array[] = { 2, 3, -6, 4, 6, 2, -2, 5, -9 };
	vector<int>v(array, array + sizeof(array) / sizeof(array[0]));
	return 0;
}
