#if 0
//������Ǽ�����vector��string��һ���ͨ���ַ������Ⱥ�ASCLL��ֵ�Ĵ�С�Ƚϵ�������Ŀ
//�����������
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)//��Χfor�����üӲ��Ӿ�����ֵ�Ƿ���Խ����������
	{
		cin >> str;
	}
	bool symlen = true, symlex = true;
	//�Ƚϳ���
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			symlen = false;
			break;
		}
	}
	//�Ƚ�ascll��ֵ
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] >= v[i])
		{
			symlex = false;
			break;
		}
	}
	if (symlen && symlex)
	{
		cout << "both" << endl;
	}
	else if (!symlen && symlex)
	{
		cout << "lexicographically" << endl;
	}
	else if (symlen && !symlex)
	{
		cout << "lengths" << endl;
	}
	else if (!symlen && !symlex) {
		cout << "none" << endl;
	}

}
#endif