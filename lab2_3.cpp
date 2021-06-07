#include "lab2_3.h"
#include "functions.h"
#include "lab2_3/lab2_3_func.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab23::lab2_3 form;
	Application::Run(% form);
}

std::string Lab23::lab2_3::getString()
{
	std::string s = "";
	if (keyRadio->Checked) {
		s = getStringFromTextbox(expressionText);
	}
	else if (fileRadio->Checked) {
		s = getStringFromFile(filename);
	}
	if (s[s.length() - 1] == ' ') {
		s.erase(s.length() - 1, 1);
	}
	return s;
}
void Lab23::lab2_3::showArr(std::vector<std::string>& arr, String^& consoleText)
{
	String^ s;
	for (auto& el : arr) {
		consoleText += convert_string_to_String(el, s) + " ";
	}
	consoleText += "\n";
}

bool Lab23::lab2_3::isExValid(std::string s, std::vector<std::string>& arr, String^& consoleText)
{
	int bracket = 0;

	String^ S;
	consoleText = "";
	consoleText += "------ Проверка введённого простого выражения ------\n\n" + convert_string_to_String(s, S);
	
	consoleText += "\n\n1) Проверка, чтобы в выражении были только цифры, указанные переменные (x, y, z), скобки и знаки операций:  \n";
	for (auto& el : arr) {
		if (!isOperand(el) && !isOperator(el) && !isBracket(el)) {
			consoleText += "Неудачно!\n\n";
			return false;
		}
	}
	consoleText += "Удачно!\n\n";
	consoleText += "2) Проверка, чтобы выражение начиналось с числа или открывающей скобки и числа:  \n";
	if (isOperand(arr[0]) || arr[0] == "(" && isOperand(arr[1])) {
		consoleText += "Удачно!\n\n";	
	}
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}

	consoleText += "3) Проверка, чтобы выражение заканчивалось числом или числом и закрывающей скобкой: \n";
	if (isOperand(arr.back()) || isBracket(arr.back()) && isOperand(arr[arr.size() - 2]))
		consoleText += "Удачно!\n\n";
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}
	consoleText += "4) Проверка в цикле всего выражения: \n\n";
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == "(" && isOperand(arr[i + 1])) {
			bracket++;
			consoleText += "  За открывающей скобкой операнд - норм\n";
			continue;
		}
		else if (arr[i] == ")" && isOperator(arr[i + 1])) {
			bracket--;
			consoleText += "  За закрывающей скобкой оператор - норм\n";
			continue;
		}
		else if (isOperator(arr[i]) && isOperand(arr[i + 1]) ||
			isOperator(arr[i]) && arr[i + 1] == "(") {
			consoleText += "  За оператором операнд или открывающая скобка - норм\n";
			continue;		
		}
		else if (isOperand(arr[i]) && isOperator(arr[i + 1]) ||
			isOperand(arr[i]) && arr[i + 1] == ")") {
			consoleText += "  За операндом оператор или закрывающая скобка - норм\n";
			continue;
		}
		else {
			consoleText += "  Ошибка в введённом символе, возможно, потерян пробел. Выход из цикла.\n";
			return false;
		}

	}
	if (bracket != 0 && arr[arr.size() - 1] != ")") {
		consoleText += "\n5) Баланс скобок: не соблюдается\n";
		return false;
	}
	else {
		consoleText += "\n5) Баланс скобок: соблюдается\n";
	}

	return true;
}

bool Lab23::lab2_3::isPnValid(std::string s, std::vector<std::string>& arr, String^& consoleText)
{
	String^ S;
	consoleText = "";
	consoleText += "------ Проверка выражения в польской нотации ------\n\n" + convert_string_to_String(s, S);

	consoleText += "\n\n1) Проверка, чтобы в выражении были только цифры, указанные переменные (x, y, z) и знаки операций:  \n";
	for (auto& el : arr) {
		if (!isOperand(el) && !isOperator(el)) {
			consoleText += "Неудачно!\n\n";
			return false;
		}
	}

	consoleText += "Удачно!\n\n";
	consoleText += "2) Проверка, чтобы первый член последовательности были оператором:  \n";
	if (isOperator(arr[0]))
		consoleText += "Удачно!\n\n";
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}

	consoleText += "3) Проверка, чтобы два последних члена последовательности были операндми  \n";
	if (isOperand(arr[arr.size() - 1]) && isOperand(arr[arr.size() - 2]))
		consoleText += "Удачно!\n\n";
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}
	consoleText += "4) Проверка, чтобы в выражении операторов было на один меньше, чем операндов  \n";
	int ops = 0, operands = 0;
	for (auto& el : arr) {
		if (isOperand(el))
			operands++;
		else if (isOperator(el))
			ops++;
		else {
			consoleText += "  Ошибка в введённом символе, возможно, потерян пробел. Выход из цикла.\n";
			return false;
		}
	}
	return true;
}

bool Lab23::lab2_3::isRpnValid(std::string s, std::vector<std::string>& arr, String^& consoleText)
{
	String^ S;
	consoleText = "";
	consoleText += "------ Проверка выражения в обратной польской нотации ------\n\n" + convert_string_to_String(s, S);

	consoleText += "\n\n1) Проверка, чтобы в выражении были только цифры, указанные переменные (x, y, z) и знаки операций:  \n";
	for (auto& el : arr) {
		if (!isOperand(el)&&!isOperator(el)) {
			consoleText += "Неудачно!\n\n";
			return false;
		}
	}
	consoleText += "Удачно!\n\n";
	consoleText += "2) Проверка, чтобы первые два члена последовательности были операндами:  \n";
	if(isOperand(arr[0])&&isOperand(arr[1]))
		consoleText += "Удачно!\n\n";
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}
	consoleText += "3) Проверка, чтобы последний член последовательности был оператором:  \n";
	if (isOperator(arr.back()))
		consoleText += "Удачно!\n\n";
	else {
		consoleText += "Неудачно!\n\n";
		return false;
	}

	consoleText += "4) Проверка, чтобы в выражении операторов было на один меньше, чем операндов  \n";
	int ops = 0, operands = 0;
	for (auto& el : arr) {
		if (isOperand(el))
			operands++;
		else if (isOperator(el))
			ops++;
		else {
			consoleText += "  Ошибка в введённом символе, возможно, потерян пробел. Выход из цикла.\n";
			return false;
		}
	}
	return true;
}
std::vector<std::string> Lab23::lab2_3::convertToPn(std::vector<std::string>& arr, String^& consoleText)
{

	std::vector <std::string> output, input;
	std::reverse(arr.begin(), arr.end());
	for (auto& el:arr)
	{
		if (el == "(") {
			el = ")";
			continue;
		}
		if (el == ")") {
			el = "(";
			continue;
		}
	}
	String^ temp = "";
	consoleText += "\n\nДля преобразования в польскую нотацию сначала развернём исходную строку: \n";

	for (auto& el : arr) {
		consoleText += convert_string_to_String(el, temp) + " ";
	}
	consoleText += "\n\nТеперь воспользуемся алгоритмом преобразования в обратную польскую нотацию:";
	output = convertToRpn(arr, consoleText);

	consoleText += "\nРазвернём выходной массив. Это и будет результат: ";

	std::reverse(output.begin(), output.end());
	for (auto& el : output) {
		consoleText += convert_string_to_String(el, temp) + " ";
	}
	return output;
}


std::vector <std::string> Lab23::lab2_3::convertToRpn(std::vector<std::string>& arr, String^& consoleText)
{
	std::vector <std::string> stack;
	std::vector <std::string> output;
	String^ temp = "";
	consoleText += "\n\n------ Старт преобразования ------\n";
	for(auto& el : arr){
		if (isOperand(el)) {
			output.push_back(el);
			consoleText += "\n" + convert_string_to_String(el, temp) + " - это операнд, помещаем его в выходной массив";
			consoleText += "\nВыходной массив: ";
			showArr(output, consoleText);
			consoleText += "\nСтек: ";
			showArr(stack, consoleText);
			continue;
		}
		if (el == "(") {
			stack.push_back(el);
			consoleText += "\nОткрывающая скобка помещается в стэк";
			consoleText += "\nВыходной массив: ";
			showArr(output, consoleText);
			consoleText += "\nСтек: ";
			showArr(stack, consoleText);
			continue;
		}
		if (el == ")") {
			consoleText += "\nЗакрывающая скобка - выталкиваем из стека все элементы, пока не встретим открывающую скобку";
			for (int i = stack.size() - 1; i >= 0; --i) {
				if (stack[i] != "(") {
					output.push_back(stack[i]);
					consoleText += "\n" + convert_string_to_String(stack[i], temp) + " - выталкиваем в выходной массив";
					stack.pop_back();
					consoleText += "\nВыходной массив: ";
					showArr(output, consoleText);
					consoleText += "\nСтек: ";
					showArr(stack, consoleText);
				}
				else {
					stack.pop_back();
					consoleText += "\n( - просто удаляем из стека";
					consoleText += "\nВыходной массив: ";
					showArr(output, consoleText);
					consoleText += "\nСтек: ";
					showArr(stack, consoleText);
					break;
				}
			}

			continue;
		}
		if (isOperator(el)) {
			consoleText += "\n" + convert_string_to_String(el, temp) + " - это оператор, проверяем вес операторов в стэке";
			if (stack.size() == 0 || getPriority(stack[stack.size() - 1]) < getPriority(el)) {
				if (stack.size() == 0)
					consoleText += "\nСтэк пуст";
				else
					consoleText += "\nПриоритет " + convert_string_to_String(stack[stack.size() - 1], temp) + " ниже, чем у " + convert_string_to_String(el, temp);
				consoleText += ", поэтому просто помещаем элемент в стек";
				stack.push_back(el);
				consoleText += "\nВыходной массив: ";
				showArr(output, consoleText);
				consoleText += "\nСтек: ";
				showArr(stack, consoleText);
			}
			else {
				while (stack.size() > 0 && getPriority(stack[stack.size() - 1]) >= getPriority(el)) {
					consoleText += "\nПриоритет " + convert_string_to_String(stack[stack.size() - 1], temp) + " больше либо равен приоритету " + convert_string_to_String(el, temp) + ", выталкиваем " + convert_string_to_String(stack[stack.size() - 1], temp) + " в выходной массив";
					output.push_back(stack[stack.size() - 1]);
					stack.pop_back();
					consoleText += "\nВыходной массив: ";
					showArr(output, consoleText);
					consoleText += "\nСтек: ";
					showArr(stack, consoleText);
				}
				stack.push_back(el);
				consoleText += "\nОтправляем " + convert_string_to_String(el, temp) + " в стэк";
				consoleText += "\nВыходной массив: ";
				showArr(output, consoleText);
				consoleText += "\nСтек: ";
				showArr(stack, consoleText);
			}
		}
	}
	while (stack.size() != 0) {
		consoleText += "\nВходная строка закончилась. Очищаем стек. Отправляем " + convert_string_to_String(stack[stack.size() - 1], temp) + " в выходной массив";
		output.push_back(stack[stack.size() - 1]);
		stack.pop_back();
		consoleText += "\nВыходной массив: ";
		showArr(output, consoleText);
		consoleText += "\nСтек: ";
		showArr(stack, consoleText);
	}
	consoleText += "\n\nРезультат преобразования: ";

	for (auto& el : output) {
		consoleText += convert_string_to_String(el, temp) + " ";
	}
	return output;
}

bool Lab23::lab2_3::calcEx(std::vector<std::string>& input, String^& consoleText, double& num)
{
	consoleText += "\n\nПреобразуем выражение в ОПН для облегчения процесса вычислений: ";
	std::vector <std::string> inputPN = convertToRpn(input, consoleText);
	consoleText += "\n\nВычислим полученное выражение: ";
	if (!calcRpn(inputPN, consoleText, num))
		return false;
	return true;
}



bool Lab23::lab2_3::calcRpn(std::vector<std::string>& input, String^& consoleText, double& num)
{
	std::string el = "";
	String^ temp;
	std::vector<double> stack;
	double res, op1, op2;
	if (substToEx(input, consoleText)) {
		for (int i = 0; i < input.size(); i++) {
			el = input[i];
			if (!isOperator(el)) {
				stack.push_back(std::stod(el));
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- это число, поэтому добавляем его в стек";
			}
			else {
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- это оператор. Достаём из стека верхние два числа.";
				op2 = stack.back();
				stack.pop_back();
				op1 = stack.back();
				stack.pop_back();
				if (el == "+") {
					res = op1 + op2;
				}
				if (el == "-") {
					res = op1 - op2;
				}
				if (el == "*") {
					res = op1 * op2;
				}
				if (el == "/") {
					if (op2) {
						res = op1 / op2;
					}
					else {
						consoleText += "\n\nДеление на ноль! Прерывание операции!";
						return false;
					}
				}
				consoleText += "\n" + op1.ToString() + convert_string_to_String(el, temp) + op2.ToString() + "=" + res.ToString();
				consoleText += "\nДобавляем результат в стек.";
				stack.push_back(res);
			}
		}
		num = stack.back();

		return true;
	}
	else return false;
}
void Lab23::lab2_3::recursiveCalc(std::vector<std::string>& stack, String^& consoleText, bool& err)
{
	String^ temp;
	double res, op1, op2;
	op1 = std::stod(stack.back());
	stack.pop_back();
	op2 = std::stod(stack.back());
	stack.pop_back();
	std::string op = stack.back();
	stack.pop_back();
	if (op == "+") {
		res = op1 + op2;
	}
	else if (op == "-") {
		res = op2 - op1;
	}
	else if (op == "*") {
		res = op1 * op2;
	}
	else if (op == "/") {
		if (op1) {
			res = op2 / op1;
		}
		else {
			consoleText += "\n\nДеление на ноль! Прерывание операции!";
			err = true;
			return;
		}
	}
	consoleText += "\n" + op2.ToString() + convert_string_to_String(op, temp) + op1.ToString() + "=" + res.ToString();
	stack.push_back(std::to_string(res));
	consoleText += "\nДобавляем результат в стек";
	consoleText += "\nСостояние стека: ";
	showArr(stack, consoleText);
	if (stack.size() > 1) {
		if (isOperand(stack[stack.size() - 2])) {
			consoleText += "\nТак как на верхушке стека операнд, вытаскиваем его и совершаем операцию";
			recursiveCalc(stack, consoleText, err);
		}
	}
}


bool Lab23::lab2_3::calcPn(std::vector<std::string>& input, String^& consoleText, double& num)
{
	std::string el = "";
	String^ temp;
	std::vector<std::string> stack;
	bool err = false;
	if (substToEx(input, consoleText)) {
		consoleText += "\n";
		for (int i = 0; i < input.size(); i++) {
			el = input[i];
			if (isOperator(el)) {
				stack.push_back(el);
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- это оператор, поэтому добавляем его в стек";
				consoleText += "\nСостояние стека: ";
				showArr(stack, consoleText);
			}
			else if (isOperator(stack.back())) {
				stack.push_back(el);
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- это число, а на вершине стека оператор, поэтому добавляем число в стек";
				consoleText += "\nСостояние стека: ";
				showArr(stack, consoleText);

			}
			else {
				stack.push_back(el);
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- это число, и на вершине стека другое число, поэтому достаём из стека предыдущее число и совершаем операцию";
				recursiveCalc(stack, consoleText, err);
				if (err) {
					return false;
				}
			}
		}
		num = std::stod(stack.back());
		return true;
	}
	else return false;
}
bool Lab23::lab2_3::substToEx(std::vector<std::string>& arr, String^& consoleText)
{
	String^ temp = "";
	consoleText += "\n\nПроверим заданное выражение на наличие переменных ------\n";
	int x, y, z;
	bool xf = false, yf = false, zf = false;

	for (auto& el : arr) {
		if (el == "x" || el == "X") {
			if (getNumFromTextbox(xText, x)) {
				el = std::to_string(x);
				xf = true;
			}
			else {
				consoleText += "\n\nПользователь не задал переменную " + convert_string_to_String(el, temp) + ". Завершение работы!";
				return false;
			}
		}
		else if (el == "y" || el == "Y") {
			if (getNumFromTextbox(yText, y)) {
				el = std::to_string(y);
				yf = true;
			}
			else {
				consoleText += "\n\nПользователь не задал переменную " + convert_string_to_String(el, temp) + ". Завершение работы!";
				return false;
			}
		}
		else if (el == "z" || el == "Z") {
			if (getNumFromTextbox(zText, z)) {
				el = std::to_string(z);
				zf = true;
			}
			else {
				consoleText += "\n\nПользователь не задал переменную " + convert_string_to_String(el, temp) + ". Завершение работы!";
				return false;
			}
		}
	}
	if(xf) consoleText += "\nПеременная х = " + x.ToString();
	if(yf) consoleText += "\nПеременная y = " + y.ToString();
	if(zf) consoleText += "\nПеременная z = " + z.ToString();
	
	if (xf || yf || zf) {
		consoleText += "\n\nПодставим значения переменных в строку: ";
		for (auto& el : arr) {
			consoleText += convert_string_to_String(el, temp) + " ";
		}
	}
	else consoleText += "\nПеременные не найдены";
	return true;
}

System::Void Lab23::lab2_3::browseBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	filename = browseFile(openFileDialog1);
	return System::Void();
}




System::Void Lab23::lab2_3::exCheckBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isValid;
	std::string s = getString();
	String^ consoleText = "";
	consoleBox->Text = "";
	if (s != "") {
		std::vector <std::string> arr;
		parseString(s, arr);

		if (exRadio->Checked) {
			isValid = isExValid(s, arr, consoleText);
		}
		if (pnRadio->Checked) {
			isValid = isPnValid(s, arr, consoleText);
		}
		if (rpnRadio->Checked) {
			isValid = isRpnValid(s, arr, consoleText);
		}
		consoleText += "\n\n";
		if (isValid) {
			consoleText += "\n------ Выражение валидно! ------ ";
		}
		else consoleText += "\n------ Выражение невалидно! ------ ";
		consoleBox->AppendText(consoleText);
		consoleBox->ScrollToCaret();
	}

}

System::Void Lab23::lab2_3::exConvertBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag;
	std::string s = getString();
	String^ consoleText = "";
	consoleBox->Text = "";
	if (s != "") {
		std::vector <std::string> arr;
		parseString(s, arr);
		flag = isExValid(s, arr, consoleText);
		consoleBox->Text += "\n\n";
		if (flag) {
			consoleText += "\n------ Выражение валидно! ------ ";
		}
		else {
			consoleText += "\n------ Выражение невалидно! ------ ";
			return;
		}
		std::vector <std::string> output;
		if (tpRpnRadio->Checked) {
			output = convertToRpn(arr, consoleText);
		}
		else {
			output = convertToPn(arr, consoleText);
		}
		consoleBox->AppendText(consoleText);
		consoleBox->ScrollToCaret();
	}
}


System::Void Lab23::lab2_3::exCalcBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag;
	std::string s = getString();
	consoleBox->Text = "";
	String^ consoleText = "";
	double x, y, z, res;
	if (s != "") {
		std::vector <std::string> arr;
		parseString(s, arr);
		if (exRadio->Checked) {
			flag = isExValid(s, arr, consoleText);
		}
		else if (pnRadio->Checked) {
			flag = isPnValid(s, arr, consoleText);
		}
		else if (rpnRadio->Checked) {
			flag = isRpnValid(s, arr, consoleText);
		}
		consoleBox->Text += "\n\n";
		if (flag) {
			consoleText += "\n------ Выражение валидно! ------ ";
		}
		else {
			consoleText += "\n------ Выражение невалидно! ------ ";
			consoleBox->AppendText(consoleText);
			return;
		}
		if (exRadio->Checked) {
			flag = calcEx(arr, consoleText, res);
		}
		else if (pnRadio->Checked) {
			flag = calcPn(arr, consoleText, res);
		}
		else if (rpnRadio->Checked) {
			flag = calcRpn(arr, consoleText, res);
		}
		if (flag) {
			consoleText += "\n\nРезультат вычисления: " + res.ToString();		
		}
		consoleBox->AppendText(consoleText);
		consoleBox->ScrollToCaret();
	}
}
