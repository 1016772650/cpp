//�������a �� = b���������еĽϴ�������2�� ���ѭ��ֱ��a == b
//����ԭ���������������������
#include<iostream>
using namespace std;
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a == b) { return a; }
		else {
			while (a != b)
			{
				if (a > b) { a = a / 2; }
				else { b = b / 2; }

			}
			return b;
		}
	}

};//�ǵݹ�
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a == b) { return b; }
		else {
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			return getLCA(a / 2, b);
		}
	}

};//�ݹ�