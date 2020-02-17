#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <functional>
#include<map>
#include<queue>
using namespace std;

#if 0
//����һ������vector�е�sort����,����opertor[]
//��Ϊmap�еļ�ֵ�Ե�key������ģ�sort������ģ�sort������vector,deque(���Ƽ�)why,����
bool cmp(pair<string, int>a, pair<string, int>b)
{
	return a.second > b.second;
}
void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	map<string, int>mp;
	for (size_t i = 0; i < fruits.size(); i++)
	{
		// 1.ͳ�Ƴ�ˮ�����ִ���
		mp[fruits[i]]++;
	}
	// 2.�ҳ������ϲ���Ե�ˮ��
	vector < pair<string, int> >a(mp.begin(),mp.end());
	sort(a.begin(),a.end(),cmp);
	for (size_t j = 0; j < k; j++)
	{
		cout << a[j].first <<":"<<a[j].second<< endl;
	}
}

int main()
{
	vector<string> v = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ", "����", "����", "����", "������","������", "������" };
	GetFavoriteFruit(v, 3);
	return 0;
}
#endif

#if 0
//������������map��find�����ԣ����ص��ǵ������м�ֵ�Ե�valueֵ+���ȼ�����
struct Count_compare {
	bool operator()(const pair<string, int>& l, const pair<string, int>& v) {
		return l.second < v.second;
	}
};

void GetFavoriteFruit2(const vector<string>& fruits, size_t k)
{
	map<string, int>mp;
	for (auto& e : fruits)
	{
		//map<string, int>::iterator ret = mp.find(e);
		auto ret = mp.find(e);
		if (ret != mp.end())
		{
			ret->second++;
		}
		else {
			mp.insert(pair<string, int>(e, 1));
		}
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Count_compare>pq;
	size_t i = 0;
	for (auto& e : mp) {
		if (i < k) {
			pq.push(e);
		}
		else {
			if (e.second > pq.top().second) {
				pq.pop();
				pq.push(e);
			}
		}
	}
	
}
int main()
{
	vector<string> v = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ", "����", "����", "����", "������","������", "������" };
	GetFavoriteFruit2(v, 3);
	return 0;
}
#endif

#if 0
//��������operator[]+���������
void GetFavoriteFruit3(const vector<string>& fruits, size_t k) {
	map<string, int>mp;
	for (auto& e : fruits)
	{
		mp[e]++;
	}
	multimap<int, string, greater<int>>sortmap;//������multimap��ԭ���ǵߵ���ֵ�Ժ��valueֵ���ܴ����ظ�
	for(const auto&e:mp)
	{
		sortmap.insert(make_pair(e.second, e.first));
	}
	vector<pair<int, string>>a(sortmap.begin(), sortmap.end());
	for (auto& e : a) {
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	vector<string> v = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ", "����", "����", "����", "������","������", "������" };
	GetFavoriteFruit3(v, 3);
	return 0;
}
#endif
