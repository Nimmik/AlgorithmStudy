#include <iostream>
#include <algorithm>

using namespace std;
int num;
int input[10000];
int index, result;
int arr[10000];

int isLast()
{
	for (int i = 0; i < num; i++)
		if ((i + 1 != num) && (input[i] < input[i + 1]))
			return 0;

	return -1;
}


void sssort(int start, int val, int least)
{
	//start�ε������� num-1�ε�������... val+1���� val�� �ٲٰ� ��Ʈ ����
	for (int i = start; i <= num - 1; i++)
	{
		if (input[i] == least)
			input[i] = val;

		
	}
	//sort
	sort(input + start, input + num);
}

bool isIn(int a, int index)
{
	for (int i = index; i < num; i++)
		if (input[i] == a)
			return true;

	return false;
}

int getLeast(int start, int a)
{
	int min = input[start];
	for (int i = start; i < num; i++)
	{
		if (input[i] < min && input[i] > a)
			min = input[i];
	}
	return min;
}

int main(void)
{
	while (1)
	{
		cin >> num;

		for (int i = 0; i < num; i++)
			cin >> input[i];

		if ((result = isLast()) == -1)
		{
			printf("%d", result);
			return 0;
		}

		else
		{
			for (int i = 0; i < num; i++) {
				if ((i + 1 != num) && (input[i] < input[i + 1]))
					index = i;
			}
		}


		if (index == num - 2)
		{
			int temp = input[index];
			input[index] = input[index + 1];
			input[index + 1] = temp;
		}
		else
		{
			//index + 1�� ��ġ�� ���� �� ������ �߿� ���� ���� ������ �����ϰ�, ���� index+1�� ���� �� ���� ������ ������������ �����Ѵ�
			int temp = input[index];
			//
			if (!isIn(input[index]+1, index+1))
			{
				//input[index]���� ū ���� �߿����� min

				input[index] = getLeast(index + 1, input[index]);
				sssort(index + 1, temp, input[index]);
			}
			
			else
			{
				input[index]++;
				sssort(index + 1, temp, input[index]);
			}
		}


		for (int i = 0; i < num; i++)
		{
			printf("%d", input[i]);
			if (i != num - 1)
				printf(" ");
		}

	}
	return 0;
}


