#include"exam_japanese.h"
using namespace std;

//�����̓ǂݎ������쐬����
QuestionList CreateKanjiExam()
{
	static const struct {
		const char* kanji;	//����
		const char* reading;	//�ǂ�
		const char* meaning;	//�Ӗ�
	} data[] = {
		{"�s��","������","�l�������W�܂��ĕ�炷�Ƃ���A��"},
		{"���","�Ȃ���","(�����ƂƂ���)��ӂ���������"},
		{"���E","��������","�����C�̌��ʁA�����Ȃ��Ȃ邱��"},
		{"�}��","�͂�ꂢ","�{��}�\�̂͂��߂ɁA�g������񑩎����ӏ������ɂ�������"},
		{"���","�₭���傤","�񑩂��Č��߂邱�ƁA�_��"},
	};

	constexpr int quizCount = 5;	//expr��expression�Ƃ����Ӗ�
	QuestionList questions;
	questions.reserve(quizCount);
	for (int i = 0; i < quizCount; i++)
	{
		const auto& e = data[i];
		questions.push_back({ "[" + string(e.kanji) + "}�̓ǂ݂��Ђ炪�Ȃœ�����",
			e.reading });
	}
	return questions;
}