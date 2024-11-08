#include"exam_science.h"
#include"utility.h"
#include<random>
using namespace std;

//物理の問題を作成する
QuestionList CreatePhysicsExam()
{
	QuestionList questions;
	questions.reserve(10);
	random_device rd;

	{//等速直線運動
		constexpr int divisors[] = { 1,2,3,4,5,6,10,12,15,20,30,60 };
		int i = uniform_int_distribution<>(0, size(divisors) - 1)(rd);
		int v = uniform_int_distribution<>(1, 10)(rd) * 60 / divisors[i];	//時速
		int t = uniform_int_distribution<>(0, 10)(rd) * divisors[i];	//時間
		questions.push_back({ "時速" + to_string(v) + "kmで移動する車がある。\nこの車が" +
		to_string(v * t / 60) + "km移動するのにかかる時間を分単位で求めよ",to_string(t) });
	}

	{//等加速度直線運動
	//公式 v = v0 + at　を使って解く問題
		int v0 = uniform_int_distribution<>(1, 10)(rd);	//初速
		int a = uniform_int_distribution<>(1, 5)(rd);	//加速度
		int t = uniform_int_distribution<>(1, 20)(rd);	//移動時間
		questions.push_back({ "秒速" + to_string(v0) + "mで移動していた車が、進行方向に大きさ" + to_string(a) +
		"m/sで等加速度直線運動をはじめた。\n" + to_string(t) + "秒後の速度をm/s単位でもとめよ",to_string(v0 + a * t) });

		//公式 x = v0t + 1/2at^2 を使って解く問題
		v0 = uniform_int_distribution<>(5, 20)(rd);	//初速
		a = uniform_int_distribution<>(1, 5)(rd);	//加速度
		t = uniform_int_distribution<>(1, 10)(rd);	//移動時間
		questions.push_back({ "秒速" + to_string(v0) + "mで移動していた車が、進行方向に大きさ" + to_string(a) +
		"m/sで等加速度直線運動をはじめた。\n加速をはじめてから" + to_string(t) +
		"秒後までに移動した距離をm単位で求めよ",to_string(v0 * t + a * t * t / 2) });

	//公式 v^2 - v0^2 = 2ax　を使って解く問題
		a = -uniform_int_distribution<>(1, 5)(rd)*2;	//加速度
		t = uniform_int_distribution<>(1, 10)(rd);	//移動時間
		v0 = -a * t;	//初速
		questions.push_back({ "秒速" + to_string(v0) + "mで移動していた車がブレーキをかけたところ、" +
			to_string(v0 * t + a * t * t / 2) + "m進んで停止した(v=0)\nブレーキの加速度をm/s^2単位で求めよ",to_string(a) });
	}

	{//重力加速度
		int t = uniform_int_distribution<>(1, 10)(rd);	//移動時間
		int x = 98 * t * t 
			/ 2;		//10倍することで、小数点以下第1位までを整数としてあらわす
		string answer = to_string(x / 10);	//整数部を文字列化
		if (x % 10)
		{
			//少数部がある場合は小数部を文字列化
			answer += '.';
			answer += '0' + x % 10;
		}
		questions.push_back({ "重力加速度を9.8m/s^2とする。\n十分な位高い位置から物体を静かに落とすと、物体は" +
			to_string(t) + "秒間でXm落下する。\nXの値を少数点以下第1位まで求めよ。(空気抵抗は考えないものとする)",
			answer });

		int v0 = uniform_int_distribution<>(1, 10)(rd);	//初速
		t = uniform_int_distribution<>(1, 10)(rd);	//移動時間
		int v = v0 * 10 - 98 * t;	//速度
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
		questions.push_back({ "重力加速度を9.8m/s^2とする。\n初速" + to_string(v0) + "m/sで物体を鉛直に投げたとき," +
			to_string(t) + "秒後の物体の速度はXm/sである。\nXの値を小数点以下第1位まで求めよ。(空気抵抗は考えないものとする)",
			answer });
	}

	return questions;
}