/*
//��������һ�����ֳ��ִ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1��2��3,2,2��2��5,4,2}2�������г�����5�Σ�������2

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int sz = numbers.size();
		int array[9] = { 0 };
		for (int i = 0; i < sz; i++) {
			array[numbers[i]] = 1;
			for (int j = 0; j < sz; j++) {
				if (numbers[j] == numbers[i])
				{
					array[numbers[i]]++;
				}

			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (array[i] >= sz / 2) {
				return i;
			}
		}
		return 0;
	}
};

//��һ�������str����������ִ�
//���룺abcd12345ed125ss123456789
//�����123456789
#include<iostream>
using namespace std;
int continumax(char* outputstr, char* inputstr)
{
	char* in = inputstr, * out = outputstr, * temp, * final;
	int count = 0, maxlen = 0;
	while (*in != '\0')
	{
		if (*in >= '0' && *in <= '9')
		{
			for (temp = in; *in >= '0' && *in <= '9'; in++)
				count++;
		}
		else
			in++;
		//�ҵ����������ˣ���Ϊcout<maxlenʱ��countû�л���õ����㡣
		if (maxlen < count)
		{
			maxlen = count;
			count = 0; //count ������ ��ʱ����
			final = temp; // temp����������ִ�����ʵ��ַ
		}
		count = 0;//������һ�䣬��count>maxlenʱ ��ֵ�ɹ�������count������
		//��count��maxlenСʱ����û�б����ֵ��ֱ������
	}
	for (int i = 0; i < maxlen; i++)
	{
		*out = *final;
		out++;
		final++;
	}
	*out = '\0';
	return maxlen;
}
int main()
{
	//char* a = "abcd12345ed125ss123456789";
	char c[20];
	int n = continumax(c, a);
	cout << "c=" << c << endl;
	cout << "n=" << n;
}

int continumax(char* outputstr, char* inputstr)
{
	char* in = inputstr, * out = outputstr, * temp, * final;
	int count = 0, maxlen = 0;
	while (*in != '\0')
	{
		if (*in >= '0' && *in <= '9')
		{
			for (temp = in; *in >= '0' && *in <= '9'; in++)
				count++;
		}
		else
			in++;
		//�ҵ����������ˣ���Ϊcout<maxlenʱ��countû�л���õ����㡣
		if (maxlen < count)
		{
			maxlen = count;
			count = 0; //count ������ ��ʱ����
			final = temp; // temp����������ִ�����ʵ��ַ
		}
		count = 0;//������һ�䣬��count>maxlenʱ ��ֵ�ɹ�������count������
		//��count��maxlenСʱ����û�б����ֵ��ֱ������
	}
	for (int i = 0; i < maxlen; i++)
	{
		*out = *final;
		out++;
		final++;
	}
	*out = '\0';
	return maxlen;
}
int main()
{
	char* a = "abcd12345ed125ss123456789";
	char c[20];
	int n = continumax(c, a);
	cout << "c=" << c << endl;
	cout << "n=" << n;
}
*/
