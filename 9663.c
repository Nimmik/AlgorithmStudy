#include <iostream>

using namespace std;

int n;

//col[i]�� ���� i��° ���� ���° �������� ��Ÿ��
int col[16] = { 0 };
int cnt = 0;


bool satisfy(int index)
{
	bool check = true;

	if (index == 1)
		return true;

	//index�� ���� ��� �����(index = 1���� index = index-1 ����) ���� ���� �ƴ�
	for (int i = 1; i <= index - 1; i++)
		if (col[i] == col[index] //index�� ���� ��� �����(index = 1���� index = index-1 ����) ���� ���ΰ�?
			|| col[index] == col[i] - (index - i) //���� ����� ���� �밢���� ��ġ�� ���ΰ�?
			|| col[index] == col[i] + (index - i)) //���� ����� ���� �밢���� ��ġ�� ���ΰ�?
		{
			check = false;
			break;
		}

	return check;
}



bool finished(int index)
{
	if (index == n && satisfy(index))
		return true;

	return false;
}



void nqueens(int index)
{
	col[index] = 0;

	for (int i = 0; i < n; i++)
	{
		//�� ���� ���� ������Ŵ
		col[index]++;

		if (finished(index))
			cnt++;
		
		else if (satisfy(index))
			nqueens(index + 1);
	}	
}

int main(void)
{
	scanf("%d", &n);
	nqueens(1);
	printf("%d", cnt);

	return 0;
}