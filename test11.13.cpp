//11.6

//����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)

//�ڶ��а���3* n������a_i(1 �� a_i �� 10 ^ 9), ��ʾÿ������ѡ�ֵ�ˮƽֵ
//��Ŀ������������������飨3λһ�飩���м�ֵ֮�ͣ���ʹ�����
//�ѵ㣺���������Ԫ�ص��±���ҹ��ɺ�����ĸ����Ĺ�ϵ���ҵ����ɱȹ���������ķ����õĶ�
//��������������η����ˣ�̫���ڲ��軯̫���壬û���ҹ���
#include<iostream>
#include<vector>
#include<algorithm> 
#include<string>

using namespace std;
#if 0
int main()
{
	long long sum = 0;
	vector<int>a;
	int n;
	while (cin >> n) {
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
#endif



#if 0
class FindSecondMax {
	int Solution(int x, vector<int> v)
	{
		int temp = 0;
		int sz = v.size();
		for (int i = 0; i < x; i++)
		{
			for (int j = 1; j < x - i - 1; j++) {
				if (v[j] < v[i])
				{
					temp = v[j];
					v[j] = v[i];
					v[i] = temp;
				}
			}
		}
		int k = 0;
		int count = 0;
		while (k < x) {
			count += v[(sz - k) / 2];
			k++;
		}
	}
};
#endif


//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
#if 0
string Solution() {
	string str1, str2;
	getline(cin, str1);
	int sz1 = str1.size();
	getline(cin, str2);
	int sz2 = str2.size();
	int hasharray[256];
	for (int i=0; i < sz2; i++) {
		hasharray[str2[i]]++;
	}
	string ret;
	for (int j = 0; j < sz1; j++) {
		if (hasharray[str1[j]] ==0) {
			ret += str1[j];
		}
	}
	return ret;
}
#endif

//11.7
//���һ�����ֵ���С�ǵ�����ǵݼ����е���С����
#include<iostream>
#include<vector>
using namespace std;
int main() {

	//int n = 0;
	//cin >> n;
	int array[9] = { 1,2,1,2,1,2,1,2,1 };
	int n = 9;
	int i = 0;
	int count = 0;
	vector<int>v(array, array + sizeof(array) / sizeof(int));
	v.resize(n + 1);
	int j = 0;
	/*
	for (int j = 0; j < n; j++) {
		cin >> v[j];
	}
	*/
	while (i < n) {
		//�ж��Ƿǵ�������
		if (v[i] > v[i + 1]) {
			while (i < n && v[i] >= v[i + 1]) { i++; }
			count++;
			i++;
		}
		if (v[i] == v[i + 1]) {
			i++;
		}
		else {
			//�ж��Ƿǵݼ�����
			while (i < n && v[i] <= v[i + 1]) { i++; }
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int n = 0;
	cin >> n;
	int i = 0;
	int count = 0;
	 v.resize(n+1);
  //v[n]=0;
	int j=0;
	for(int j=0;j<n;j++){
		cin>>v[j];
	}
	while (i < n) {
		//�ж��Ƿǵ�������
		if (v[i] > v[i + 1]) {
			while (i < n && v[i] >= v[i + 1]) { i++; }
			count++;
			i++;
		}
		else if (v[i] == v[i + 1]) {
			i++;
		}
		else {
			//�ж��Ƿǵݼ�����
			while (i < n && v[i] <= v[i + 1]) { i++; }
			count++;
			i++;
		}
	}
	cout<<count<<endl;
	return 0;
}
*/

//�����ַ���
//���룺I Like Beijing.
//�����Beijing. Like I
int main() {
	string s1, s2;
	cin >> s1;
	while (cin >> s2) {
		s1 = s2 + " " + s1;
	}
	cout << s1 << endl;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int i = 1;
	string s1;
	cin >> s1;
	int len = s1.size();
	int count = s1[0] - 'a';
	int count2 = 0;
	int cflag = 1;
	int flag = 1;
	string s;
	while (cin >> s)
	{
		int len2 = s.size();
		if (len > len2) {
			cflag = 0;
		}
		size_t sz = s1.size() < s.size() ? s1.size() : s.size();
		for (int i = 0; i < sz; i++) {
			count2 = s[i] - 'a';
			count = s1[i] - 'a';
			if (count > count2)
			{
				flag = 0;
				break;
			}
		}
		s1 = s;
		len = s1.size();
	}
	if (flag == 0 && cflag == 0) { cout << "none" << endl; }
	if (flag == 1 && cflag == 1) { cout << "both" << endl; }
	if (flag == 1 && cflag == 0) { cout << "lexicographically" << endl; }
	if (flag == 0 && cflag == 1) { cout << "lengths" << endl; }


}