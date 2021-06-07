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
	consoleText += "------ �������� ��������� �������� ��������� ------\n\n" + convert_string_to_String(s, S);
	
	consoleText += "\n\n1) ��������, ����� � ��������� ���� ������ �����, ��������� ���������� (x, y, z), ������ � ����� ��������:  \n";
	for (auto& el : arr) {
		if (!isOperand(el) && !isOperator(el) && !isBracket(el)) {
			consoleText += "��������!\n\n";
			return false;
		}
	}
	consoleText += "������!\n\n";
	consoleText += "2) ��������, ����� ��������� ���������� � ����� ��� ����������� ������ � �����:  \n";
	if (isOperand(arr[0]) || arr[0] == "(" && isOperand(arr[1])) {
		consoleText += "������!\n\n";	
	}
	else {
		consoleText += "��������!\n\n";
		return false;
	}

	consoleText += "3) ��������, ����� ��������� ������������� ������ ��� ������ � ����������� �������: \n";
	if (isOperand(arr.back()) || isBracket(arr.back()) && isOperand(arr[arr.size() - 2]))
		consoleText += "������!\n\n";
	else {
		consoleText += "��������!\n\n";
		return false;
	}
	consoleText += "4) �������� � ����� ����� ���������: \n\n";
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == "(" && isOperand(arr[i + 1])) {
			bracket++;
			consoleText += "  �� ����������� ������� ������� - ����\n";
			continue;
		}
		else if (arr[i] == ")" && isOperator(arr[i + 1])) {
			bracket--;
			consoleText += "  �� ����������� ������� �������� - ����\n";
			continue;
		}
		else if (isOperator(arr[i]) && isOperand(arr[i + 1]) ||
			isOperator(arr[i]) && arr[i + 1] == "(") {
			consoleText += "  �� ���������� ������� ��� ����������� ������ - ����\n";
			continue;		
		}
		else if (isOperand(arr[i]) && isOperator(arr[i + 1]) ||
			isOperand(arr[i]) && arr[i + 1] == ")") {
			consoleText += "  �� ��������� �������� ��� ����������� ������ - ����\n";
			continue;
		}
		else {
			consoleText += "  ������ � �������� �������, ��������, ������� ������. ����� �� �����.\n";
			return false;
		}

	}
	if (bracket != 0 && arr[arr.size() - 1] != ")") {
		consoleText += "\n5) ������ ������: �� �����������\n";
		return false;
	}
	else {
		consoleText += "\n5) ������ ������: �����������\n";
	}

	return true;
}

bool Lab23::lab2_3::isPnValid(std::string s, std::vector<std::string>& arr, String^& consoleText)
{
	String^ S;
	consoleText = "";
	consoleText += "------ �������� ��������� � �������� ������� ------\n\n" + convert_string_to_String(s, S);

	consoleText += "\n\n1) ��������, ����� � ��������� ���� ������ �����, ��������� ���������� (x, y, z) � ����� ��������:  \n";
	for (auto& el : arr) {
		if (!isOperand(el) && !isOperator(el)) {
			consoleText += "��������!\n\n";
			return false;
		}
	}

	consoleText += "������!\n\n";
	consoleText += "2) ��������, ����� ������ ���� ������������������ ���� ����������:  \n";
	if (isOperator(arr[0]))
		consoleText += "������!\n\n";
	else {
		consoleText += "��������!\n\n";
		return false;
	}

	consoleText += "3) ��������, ����� ��� ��������� ����� ������������������ ���� ���������  \n";
	if (isOperand(arr[arr.size() - 1]) && isOperand(arr[arr.size() - 2]))
		consoleText += "������!\n\n";
	else {
		consoleText += "��������!\n\n";
		return false;
	}
	consoleText += "4) ��������, ����� � ��������� ���������� ���� �� ���� ������, ��� ���������  \n";
	int ops = 0, operands = 0;
	for (auto& el : arr) {
		if (isOperand(el))
			operands++;
		else if (isOperator(el))
			ops++;
		else {
			consoleText += "  ������ � �������� �������, ��������, ������� ������. ����� �� �����.\n";
			return false;
		}
	}
	return true;
}

bool Lab23::lab2_3::isRpnValid(std::string s, std::vector<std::string>& arr, String^& consoleText)
{
	String^ S;
	consoleText = "";
	consoleText += "------ �������� ��������� � �������� �������� ������� ------\n\n" + convert_string_to_String(s, S);

	consoleText += "\n\n1) ��������, ����� � ��������� ���� ������ �����, ��������� ���������� (x, y, z) � ����� ��������:  \n";
	for (auto& el : arr) {
		if (!isOperand(el)&&!isOperator(el)) {
			consoleText += "��������!\n\n";
			return false;
		}
	}
	consoleText += "������!\n\n";
	consoleText += "2) ��������, ����� ������ ��� ����� ������������������ ���� ����������:  \n";
	if(isOperand(arr[0])&&isOperand(arr[1]))
		consoleText += "������!\n\n";
	else {
		consoleText += "��������!\n\n";
		return false;
	}
	consoleText += "3) ��������, ����� ��������� ���� ������������������ ��� ����������:  \n";
	if (isOperator(arr.back()))
		consoleText += "������!\n\n";
	else {
		consoleText += "��������!\n\n";
		return false;
	}

	consoleText += "4) ��������, ����� � ��������� ���������� ���� �� ���� ������, ��� ���������  \n";
	int ops = 0, operands = 0;
	for (auto& el : arr) {
		if (isOperand(el))
			operands++;
		else if (isOperator(el))
			ops++;
		else {
			consoleText += "  ������ � �������� �������, ��������, ������� ������. ����� �� �����.\n";
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
	consoleText += "\n\n��� �������������� � �������� ������� ������� �������� �������� ������: \n";

	for (auto& el : arr) {
		consoleText += convert_string_to_String(el, temp) + " ";
	}
	consoleText += "\n\n������ ������������� ���������� �������������� � �������� �������� �������:";
	output = convertToRpn(arr, consoleText);

	consoleText += "\n�������� �������� ������. ��� � ����� ���������: ";

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
	consoleText += "\n\n------ ����� �������������� ------\n";
	for(auto& el : arr){
		if (isOperand(el)) {
			output.push_back(el);
			consoleText += "\n" + convert_string_to_String(el, temp) + " - ��� �������, �������� ��� � �������� ������";
			consoleText += "\n�������� ������: ";
			showArr(output, consoleText);
			consoleText += "\n����: ";
			showArr(stack, consoleText);
			continue;
		}
		if (el == "(") {
			stack.push_back(el);
			consoleText += "\n����������� ������ ���������� � ����";
			consoleText += "\n�������� ������: ";
			showArr(output, consoleText);
			consoleText += "\n����: ";
			showArr(stack, consoleText);
			continue;
		}
		if (el == ")") {
			consoleText += "\n����������� ������ - ����������� �� ����� ��� ��������, ���� �� �������� ����������� ������";
			for (int i = stack.size() - 1; i >= 0; --i) {
				if (stack[i] != "(") {
					output.push_back(stack[i]);
					consoleText += "\n" + convert_string_to_String(stack[i], temp) + " - ����������� � �������� ������";
					stack.pop_back();
					consoleText += "\n�������� ������: ";
					showArr(output, consoleText);
					consoleText += "\n����: ";
					showArr(stack, consoleText);
				}
				else {
					stack.pop_back();
					consoleText += "\n( - ������ ������� �� �����";
					consoleText += "\n�������� ������: ";
					showArr(output, consoleText);
					consoleText += "\n����: ";
					showArr(stack, consoleText);
					break;
				}
			}

			continue;
		}
		if (isOperator(el)) {
			consoleText += "\n" + convert_string_to_String(el, temp) + " - ��� ��������, ��������� ��� ���������� � �����";
			if (stack.size() == 0 || getPriority(stack[stack.size() - 1]) < getPriority(el)) {
				if (stack.size() == 0)
					consoleText += "\n���� ����";
				else
					consoleText += "\n��������� " + convert_string_to_String(stack[stack.size() - 1], temp) + " ����, ��� � " + convert_string_to_String(el, temp);
				consoleText += ", ������� ������ �������� ������� � ����";
				stack.push_back(el);
				consoleText += "\n�������� ������: ";
				showArr(output, consoleText);
				consoleText += "\n����: ";
				showArr(stack, consoleText);
			}
			else {
				while (stack.size() > 0 && getPriority(stack[stack.size() - 1]) >= getPriority(el)) {
					consoleText += "\n��������� " + convert_string_to_String(stack[stack.size() - 1], temp) + " ������ ���� ����� ���������� " + convert_string_to_String(el, temp) + ", ����������� " + convert_string_to_String(stack[stack.size() - 1], temp) + " � �������� ������";
					output.push_back(stack[stack.size() - 1]);
					stack.pop_back();
					consoleText += "\n�������� ������: ";
					showArr(output, consoleText);
					consoleText += "\n����: ";
					showArr(stack, consoleText);
				}
				stack.push_back(el);
				consoleText += "\n���������� " + convert_string_to_String(el, temp) + " � ����";
				consoleText += "\n�������� ������: ";
				showArr(output, consoleText);
				consoleText += "\n����: ";
				showArr(stack, consoleText);
			}
		}
	}
	while (stack.size() != 0) {
		consoleText += "\n������� ������ �����������. ������� ����. ���������� " + convert_string_to_String(stack[stack.size() - 1], temp) + " � �������� ������";
		output.push_back(stack[stack.size() - 1]);
		stack.pop_back();
		consoleText += "\n�������� ������: ";
		showArr(output, consoleText);
		consoleText += "\n����: ";
		showArr(stack, consoleText);
	}
	consoleText += "\n\n��������� ��������������: ";

	for (auto& el : output) {
		consoleText += convert_string_to_String(el, temp) + " ";
	}
	return output;
}

bool Lab23::lab2_3::calcEx(std::vector<std::string>& input, String^& consoleText, double& num)
{
	consoleText += "\n\n����������� ��������� � ��� ��� ���������� �������� ����������: ";
	std::vector <std::string> inputPN = convertToRpn(input, consoleText);
	consoleText += "\n\n�������� ���������� ���������: ";
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
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- ��� �����, ������� ��������� ��� � ����";
			}
			else {
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- ��� ��������. ������ �� ����� ������� ��� �����.";
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
						consoleText += "\n\n������� �� ����! ���������� ��������!";
						return false;
					}
				}
				consoleText += "\n" + op1.ToString() + convert_string_to_String(el, temp) + op2.ToString() + "=" + res.ToString();
				consoleText += "\n��������� ��������� � ����.";
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
			consoleText += "\n\n������� �� ����! ���������� ��������!";
			err = true;
			return;
		}
	}
	consoleText += "\n" + op2.ToString() + convert_string_to_String(op, temp) + op1.ToString() + "=" + res.ToString();
	stack.push_back(std::to_string(res));
	consoleText += "\n��������� ��������� � ����";
	consoleText += "\n��������� �����: ";
	showArr(stack, consoleText);
	if (stack.size() > 1) {
		if (isOperand(stack[stack.size() - 2])) {
			consoleText += "\n��� ��� �� �������� ����� �������, ����������� ��� � ��������� ��������";
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
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- ��� ��������, ������� ��������� ��� � ����";
				consoleText += "\n��������� �����: ";
				showArr(stack, consoleText);
			}
			else if (isOperator(stack.back())) {
				stack.push_back(el);
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- ��� �����, � �� ������� ����� ��������, ������� ��������� ����� � ����";
				consoleText += "\n��������� �����: ";
				showArr(stack, consoleText);

			}
			else {
				stack.push_back(el);
				consoleText += "\n" + convert_string_to_String(el, temp) + " -- ��� �����, � �� ������� ����� ������ �����, ������� ������ �� ����� ���������� ����� � ��������� ��������";
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
	consoleText += "\n\n�������� �������� ��������� �� ������� ���������� ------\n";
	int x, y, z;
	bool xf = false, yf = false, zf = false;

	for (auto& el : arr) {
		if (el == "x" || el == "X") {
			if (getNumFromTextbox(xText, x)) {
				el = std::to_string(x);
				xf = true;
			}
			else {
				consoleText += "\n\n������������ �� ����� ���������� " + convert_string_to_String(el, temp) + ". ���������� ������!";
				return false;
			}
		}
		else if (el == "y" || el == "Y") {
			if (getNumFromTextbox(yText, y)) {
				el = std::to_string(y);
				yf = true;
			}
			else {
				consoleText += "\n\n������������ �� ����� ���������� " + convert_string_to_String(el, temp) + ". ���������� ������!";
				return false;
			}
		}
		else if (el == "z" || el == "Z") {
			if (getNumFromTextbox(zText, z)) {
				el = std::to_string(z);
				zf = true;
			}
			else {
				consoleText += "\n\n������������ �� ����� ���������� " + convert_string_to_String(el, temp) + ". ���������� ������!";
				return false;
			}
		}
	}
	if(xf) consoleText += "\n���������� � = " + x.ToString();
	if(yf) consoleText += "\n���������� y = " + y.ToString();
	if(zf) consoleText += "\n���������� z = " + z.ToString();
	
	if (xf || yf || zf) {
		consoleText += "\n\n��������� �������� ���������� � ������: ";
		for (auto& el : arr) {
			consoleText += convert_string_to_String(el, temp) + " ";
		}
	}
	else consoleText += "\n���������� �� �������";
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
			consoleText += "\n------ ��������� �������! ------ ";
		}
		else consoleText += "\n------ ��������� ���������! ------ ";
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
			consoleText += "\n------ ��������� �������! ------ ";
		}
		else {
			consoleText += "\n------ ��������� ���������! ------ ";
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
			consoleText += "\n------ ��������� �������! ------ ";
		}
		else {
			consoleText += "\n------ ��������� ���������! ------ ";
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
			consoleText += "\n\n��������� ����������: " + res.ToString();		
		}
		consoleBox->AppendText(consoleText);
		consoleBox->ScrollToCaret();
	}
}
