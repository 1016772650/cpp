#if 0
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>result;
		if (pRoot != NULL) {
			stack<TreeNode*>stack1;
			stack<TreeNode*>stack2;
			stack1.push(pRoot);
			while (!stack1.empty() || !stack2.empty())
			{
				vector<int>ret1;
				vector<int>ret2;
				TreeNode* cur = NULL;
				while (!stack1.empty())
				{
					cur = stack1.top();
					//ż��ջ��������,���Դ������ҽ�ջ
					if (cur->left)stack2.push(cur->left);
					if (cur->right)stack2.push(cur->right);
					ret1.push_back(stack1.top()->val);
					stack1.pop();
				}
				if (ret1.size()) result.push_back(ret1);
				while (!stack2.empty())
				{
					cur = stack2.top();
					//����ջ��������,���Դ��������ջ
					if (cur->right)stack1.push(cur->right);
					if (cur->left)stack1.push(cur->left);
					ret2.push_back(stack2.top()->val);
					stack2.pop();
				}
				if (ret2.size()) result.push_back(ret2);
			}
		}
		return result;
	}

};
#endif