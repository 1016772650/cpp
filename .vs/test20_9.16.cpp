#if 0
/* ���������������������A��B���뽫����B�ϲ�������A�У����һ�����������
ע�⣺
���Լ���A�������㹻�Ŀռ���B�����Ԫ�أ� A��B�г�ʼ��Ԫ����Ŀ�ֱ�Ϊm�� n*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m == 0) {
            for (int i = 0;i < n - 1;i++) {
                A[i] = B[i];
            }
        }
        int i = m - 1;
        int j = n - 1;
        int s = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j])
            {
                A[s] = A[i];
                i--;
            }
            else {
                A[s] = B[j];
                j--;
            }
            s--;
        }
        //A��iû�����㣬��B��û��Ԫ����-->ֱ�ӷ���A
        //AûԪ�أ�B�л���
        if (i == -1)
        {
            while (j >= 0) {
                A[s] = B[j];
                s--;
                j--;
            }
        }
    }

#endif