#pragma once
#include"question.h"

//感じの読み取り問題を作成する
QuestionList CreateKanjiExam();

//慣用句の意味をこたえる問題を作成する
QuestionList CreateIdiomExam();

//同じ読みで意味の異なる語の問題を作成する
QuestionList CreateHomophoneExam();

//対疑義の問題を作成する
QuestionList CreateAntonymExam();

//類義語の問題を作成する
QuestionList CreateSynonymExam();
