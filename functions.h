#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <chrono>


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;



std::string& convert_String_to_string(String^ s, std::string& os); //конверт из String^ в string
std::string& convert_String_to_string(String^ s); //конверт из String^ в string 2
String^ convert_string_to_String(std::string& os, String^ s);//конверт наоборот
String^ convert_string_to_String(std::string& os);//конверт наоборот 2
DateTime convertDate(String^ d);
int getNumOfLines(std::string filename);//получение количества строк в файле
std::string getStringFromFile(std::string filename);//прочитать строку из файла
int getNumOfNumsFromString(std::string& s);//получение количества элементов в строке, разделённых пробелами
int emptyValidate(std::string s);
int onlyTextValidate(std::string s);//валидация текста(без цифр и знаков)
int onlyDigitsValidate(std::string s);//валидация текста(только цифры)
int getRandomNumber(int min, int max);//генерация случайного числа
int getIntFromString(String^ s, int& num);//достать инт из большого стринга
int isTextBoxFill(TextBox^ tb);
std::string getStringFromTextbox(TextBox^ tb);//достать строку из текстбокса

bool getNumFromTextbox(TextBox^ tb, int& num);//достать число из текстбокса

int getFirstNumFromString(std::string& s);//получить первое число в строке
int getLastNumFromString(std::string& s);//получить последнее число в строке
std::string browseFile(OpenFileDialog^ ofd);//получить путь к файлу из диалога
int checkFile(std::string filename);//проверка открытого файла
void showErr(String^ text); //показать мессаджбокс с ошибкой
void parseString(std::string s, std::vector<std::string>& parseSubst, char delimeter = ' ');//распарсить в вектор строку по разделителю (по умолчанию пробел)




class labTimer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	labTimer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(clock_t::now() - m_beg).count();
			
	}
};