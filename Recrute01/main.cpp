#include <iostream>
using namespace std;

int mian()
{
	cout << "[���N���[�g�����΍�N�C�Y]\n";
	cout << "13*(-5)�̓�����?\n";

	int answer;
	cin >> answer;

	if (answer == 13 * -5)
	{
		cout << "����!\n";
	}
	else
	{
		cout << "�ԈႢ!������" << 13 * -5 << "\n";
	}
}