//������
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkwin(vector<vector<int>> v, int row) {
		int sum = 0;
		//���ÿ��
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				sum += v[i][j];
			}
			if (sum == row) {
				return true;
			}
		}
		//���ÿ��
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				sum += v[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}
		//������Խ���
		for (int i = 0; i < row; i++)
		{
			sum += v[i][i];
		}
		if (sum == row) { return true; }
		//��鸱�Խ���
		for (int i = 0; i < row; i++)
		{
			sum += v[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		return false;
	}
};