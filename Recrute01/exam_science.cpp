#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;

//�����̖����쐬����
QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{//���������^��
		constexpr int divisors[] = { 1,2,3,4,5,6,10,12,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i];	//����
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];	//����
		questions.push_back({ "����" + to_string(v) + "km�ňړ�����Ԃ�����B\n���̎Ԃ�" +
		to_string(v * t / 60) + "km�ړ�����̂ɂ����鎞�Ԃ𕪒P�ʂŋ��߂�",to_string(t) });
	}

	{//�������x�����^��
	//���� v = v0 + at�@���g���ĉ������
		int v0 = uniform_int_distribution<>(1, 10)(rd);	//����
		int a = uniform_int_distribution<>(1, 5)(rd);	//�����x
		int t = uniform_int_distribution<>(1, 20)(rd);	//�ړ�����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��A�i�s�����ɑ傫��" + to_string(a) +
		"m/s�œ������x�����^�����͂��߂��B\n" + to_string(t) + "�b��̑��x��m/s�P�ʂł��Ƃ߂�",to_string(v0 + a * t) });

		//���� x = v0t + 1/2at^2 ���g���ĉ������
		v0 = uniform_int_distribution<>(5, 20)(rd);	//����
		a = uniform_int_distribution<>(1, 5)(rd);	//�����x
		t = uniform_int_distribution<>(1, 10)(rd);	//�ړ�����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��A�i�s�����ɑ傫��" + to_string(a) +
		"m/s�œ������x�����^�����͂��߂��B\n�������͂��߂Ă���" + to_string(t) +
		"�b��܂łɈړ�����������m�P�ʂŋ��߂�",to_string(v0 * t + a * t * t / 2) });

	//���� v^2 - v0^2 = 2ax�@���g���ĉ������
		a = -uniform_int_distribution<>(1, 5)(rd)*2;	//�����x
		t = uniform_int_distribution<>(1, 10)(rd);	//�ړ�����
		v0 = -a * t;	//����
		questions.push_back({ "�b��" + to_string(v0) + "m�ňړ����Ă����Ԃ��u���[�L���������Ƃ���A" +
			to_string(v0 * t + a * t * t / 2) + "m�i��Œ�~����(v=0)\n�u���[�L�̉����x��m/s^2�P�ʂŋ��߂�",to_string(a) });
	}

	{//�d�͉����x
		int t = uniform_int_distribution<>(1, 10)(rd);	//�ړ�����
		int x = 98 * t * t 
			/ 2;		//10�{���邱�ƂŁA�����_�ȉ���1�ʂ܂ł𐮐��Ƃ��Ă���킷
		string answer = to_string(x / 10);	//�������𕶎���
		if (x % 10)
		{
			//������������ꍇ�͏������𕶎���
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({ "�d�͉����x��9.8m/s^2�Ƃ���B\n�\���Ȉʍ����ʒu���畨�̂�Â��ɗ��Ƃ��ƁA���̂�" +
			to_string(t) + "�b�Ԃ�Xm��������B\nX�̒l�������_�ȉ���1�ʂ܂ŋ��߂�B(��C��R�͍l���Ȃ����̂Ƃ���)",
			answer });

		int v0 = uniform_int_distribution<>(1, 10)(rd);	//����
		t = uniform_int_distribution<>(1, 10)(rd);	//�ړ�����
		int v = v0 * 10 - 98 * t;	//���x
		answer.clear();
		if (v < 0)
		{
			v = -v;
			answer = '-';
		}
		answer += to_string(v / 10);
		if (v % 10)
		{
			answer += '.';
			answer += '0' + v % 10;
		}
		questions.push_back({ "�d�͉����x��9.8m/s^2�Ƃ���B\n����" + to_string(v0) + "m/s�ŕ��̂������ɓ������Ƃ�," +
			to_string(t) + "�b��̕��̂̑��x��Xm/s�ł���B\nX�̒l�������_�ȉ���1�ʂ܂ŋ��߂�B(��C��R�͍l���Ȃ����̂Ƃ���)",
			answer });
	}

	return questions;
}