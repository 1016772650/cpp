//1.ʹ��bitset������ת��Ϊ8λ������
//2.��bitsetת��Ϊ�ַ�����ʹ�á�0�����ַ����ָ�ҵ�
//�ҵ���������Ӵ�����
#include<iostream>
#include<string>
#include<bitset>   //bitset
#include<sstream>  //stringstream
#include<algorithm>//max
using namespace std;
int main()

{
	int n;
	while (cin >> n)
	{
		bitset<8> B(n);//תΪ������
		string s = B.to_string();//ת�ַ���
		stringstream ss(s);
		string tmp;
		int m = 0;
		while (getline(ss, tmp, '0'))//�ַ����ָ�
			m = max(m, (int)tmp.size());//������ַ���
		cout << m << endl;
	}
	return 0;
}