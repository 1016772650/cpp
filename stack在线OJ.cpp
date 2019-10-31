#define CRT_SECURE_NO WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		elem.push(x);
		if (min.empty() || x <= min.top()) {
			min.push(x);
		}
	}

	void pop() {

		if (elem.top() == min.top())
		{
			min.pop();
		}
		elem.pop();
	}

	int top() {
		return elem.top();
	}

	int getMin() {
		return min.top();
	}
private:
	std::stack<int> elem;
	std::stack<int> min;
};

class Solution {
public:    
	bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
	{        //��ջ�ͳ�ջ��Ԫ�ظ���������ͬ        
		if(pushV.size() != popV.size())            
			return false;                
		// ��s��ģ����ջ���ջ�Ĺ���        
		int outIdx = 0;        
		int inIdx = 0;        
		std::stack<int> s;                
		while(outIdx < popV.size())
	{
			// ���s�ǿգ�����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ            
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}
			// ջ��Ԫ�����ջ��Ԫ����ȣ���ջ            
			s.pop();
			outIdx++;
		}
		return true;
	}
};
