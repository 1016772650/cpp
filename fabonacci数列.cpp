#if 0
#include<iostream>
//�ؼ��㣺����쳲��������еķǵݹ��㷨���е���ַ��ĳ���
using namespace std;
int main()
{
	int f = 0;
	int f1 = 0;
	int f2 = 1;
	int l = 0;
	int r = 0;
	int n = 0;
	cin >> n;
	while (1)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		if (f < n)
		{
			l = n - f;
		}
		else
		{
			r = f - n;
			break;
		}
	}
	cout << min(l, r) << endl;
	return 0;
}
#endif