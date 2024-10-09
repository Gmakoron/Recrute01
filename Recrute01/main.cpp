#include <iostream>
#include <string>
#include<random>
#include<vector>
using namespace std;

//��蕶�Ɠ������܂Ƃ߂�\����
struct Question
{
	string s;	//��蕶
	string a;		//����
};

int main()
{
	vector<Question> questions(6);

	random_device rd;
	mt19937 rand(rd());

	//�|���Z
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].s = to_string(x) + "x" + to_string(y)+"�̓����́H";
	questions[0].a = to_string(x * y);

	//����Z
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	questions[1].s = to_string(x*y) + "/" + to_string(y) + "�̓����́H";
	questions[1].a = to_string(x);

	//���G�Ȏ�
	x = uniform_int_distribution<>(1,100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].s = to_string(x) + "-(" + to_string(y*w) + "+" + to_string(z*w) + ")/" + to_string(w) + "�̓����́H";
	questions[2].a = to_string(x - (y + z));

	//�O�p�`�̖ʐ�
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand)*2;
	questions[3].a = "�ʐ�" + to_string(x * y / 2) + "cm^2�A���" + to_string(y) + "cm�̎O�p�`�̍��������߂�B", to_string(x);

	//�~���̖ʐ�
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 3;
	questions[4].a = "��ӂ̔��a" + to_string(x) + "cm�A����" + to_string(y) + "cm�̉~��������\n" +
		"���̉~���̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B", to_string(x * x * y / 3);

	//���̖ʐ�
	x = uniform_int_distribution<>(1, 3)(rand)*3;
	questions[5].a = "���a" + to_string(x) + "cm�̋�������\n" +
		"���̋��̑̐ς�X��cm^3�Ƃ���BX�̒l�����߂�B",
		to_string(x * x * x * 4 / 3);

	std::cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : questions)
	{
		std::cout << e.s << "\n";
		string answer;
		cin >> answer;
		if (answer == e.a)
		{
			std::cout << "����!\n";
		}
		else
		{
			std::cout << "�ԈႢ!������" << e.a << "\n";
		}
	}	//for questions
	return 0;
}