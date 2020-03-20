
#if 0
class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			str[0] = '0';
		}
		int sum = 0;
		int result = 0;
		for (auto& e : str)
		{
			if (e > '9' || e < '0')
			{
				sum = 0;
				break;
			}
			sum = result * 10 + flag * (e - '0');
			if ((sum > 0 && result < 0) || (sum < 0 && result>0))
				return 0;
			result = sum;
		}
		return sum;
	}
};
#endif
//���������һ���Ӿ���������⣺
//������ȷ�������£�ʮ���ƣ���ʾ��Χ��-2147483648~2147483647
//˼·1��:���ó�long long�������ж�����
/*
���ߣ�����è��

   int StrToInt(string str) {
		int length=str.size();
		int symbol=1,i=0;
		if(str[0]=='-'||str[0]=='+')
		{
			if(str[0]=='-')
				symbol=-1;
			i++;
		}
		long long retData=0;
		while(str[i]!='\0')
		{
			if(str[i]>='0'&&str[i]<='9'&&i<=length-1)
				retData=(retData<<3)+(retData<<1)+str[i++]-'0';
			else return 0;
			if(symbol==1&&retData>0x7FFFFFFF||symbol==-1&&retData>(int)0x80000000)
				return 0;
		}
		return retData*symbol;
	}
*/
//���������ĳ���еķ���˵��һ������
//Ϊʲô���ﻹ�Ǳ಻������
//��Ϊ��ѭ���Ĺ����г������߲�����symbol==-1&&retData<(int)0x80000000������
//�ж�ǰ���������жϹ���������Ϊ2147483647����ʹ������2147483648��Խ�磩������Լ��Ż���int��Χ��2147483647
//ִ�к������2147483647���൱��û�жϣ�


/*
sum = result * 10 + flag * (e - '0');
if ((sum > 0 && result < 0) || (sum < 0 && result>0))
	return 0;
result = sum;
*/
// ������e����flag�������ڲ���if������·������͸���������У����ұ��������
// �����������������str = "-2147483648"ʱ���������������Ȼ����������ϸ��ţ�����2147483640+8�������