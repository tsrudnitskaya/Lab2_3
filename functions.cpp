#include "functions.h"

std::string& convert_String_to_string(String^ s, std::string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

std::string& convert_String_to_string(String^ s)
{
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

String^ convert_string_to_String(std::string& os, String^ s)
{
	return s = gcnew String(os.c_str());
}

String^ convert_string_to_String(std::string& os)
{
	String^ s;
	return s = gcnew String(os.c_str());
}

DateTime convertDate(String^ d)
{

	DateTime recordDate = DateTime::ParseExact(d, "ddd MMM dd HH:mm:ss yyyy", System::Globalization::CultureInfo::InvariantCulture);
	return recordDate;
}

int getNumOfLines(std::string filename)
{
	if (checkFile(filename)) {
		std::ifstream file(filename);
		int num = 0;
		std::string line;
		while (getline(file, line))
		{
			num++;
		}
		file.close();
		return num;
	}
	else return -1;

}

int getNumOfNumsFromString(std::string& s)
{
	char endch = s.back();
	if(endch ==' ') s.pop_back();
	int num = 1;
	for (size_t offset = s.find(" "); 
		offset != std::string::npos; 
		offset = s.find(" ", offset+1))
		++num;
	return num;
}

std::string getStringFromFile(std::string filename)
{
	std::string s = "";
	std::ifstream file(filename);
	getline(file, s);
	file.close();
	return s;
}


int checkFile(std::string filename)
{
	std::ifstream file(filename);
	if (file) {
		file.close();
		return 1;
	}
	else return 0;
}

void showErr(String^ text)
{
	MessageBox::Show(text, "Ошибочка");
}




int emptyValidate(std::string s)
{
	return (s == "") ? 0 : 1;
}
int onlyTextValidate(std::string s)
{
	bool flag = 0;
	for (const unsigned char c : s) {
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||
			(c >= 192 && c <= 255) || c == 32) flag = 0;
		else return 0;
	}
	return 1;
}

int onlyDigitsValidate(std::string s)
{
	for (const char c : s) {
		if (!isdigit(c)) {
			return 0;
		}
	}
	return 1;
}

int getRandomNumber(int min, int max) {
	return (rand() % (max - min + 1) + min);
}
int getIntFromString(String^ s, int& num) {
	if (s == "") return 0;
	Int16 temp;
	if (Int16::TryParse(s, temp)) {
		num = temp;
		return 1;
	}
	else return 0;
}


int isTextBoxFill(TextBox^ tb)
{
	if (tb->Text == "") {
		tb->BackColor = Color::LightPink;
		return 0;
	}
	else return 1;
}
std::string getStringFromTextbox(TextBox^ tb)
{
	if (isTextBoxFill(tb)) {
		std::string s;
		convert_String_to_string(tb->Text, s);
		return s;
	}
	else return "";
}

bool getNumFromTextbox(TextBox^ tb, int& num)
{
	std::string s;
	convert_String_to_string((tb->Text), s);
	try {
		num = std::stoi(s);
		return true;
	}
	catch (const std::invalid_argument& ia) {
		return false;
	}

}
int getFirstNumFromString(std::string& s)
{
	std::size_t pos = 0, endpos = 0;
	std::string substr = "";
	endpos = s.find(" ");
	int el;
	if (endpos) {
		substr = s.substr(pos, endpos);
	}
	else {
		substr = s.substr(pos);
	}
	s.erase(pos, substr.length() + 1);
	try {
		el = std::stoi(substr);
		return el;
	}
	catch (const std::invalid_argument& ia) {
		return -1;
	}
}

int getLastNumFromString(std::string& s)
{
	std::size_t pos;
	std::string substr = "";
	pos = s.find_last_of(" ");
	int el;
	if (pos != std::string::npos) {
		substr = s.substr(pos+1);
		s.erase(pos);
	}
	else {
		substr = s;
		s = "";
	}
	try {
		el = std::stoi(substr);
		return el;
	}
	catch (const std::invalid_argument& ia) {
		return -1;
	}
}

std::string browseFile(OpenFileDialog^ ofd)
{
	std::string filename;
	ofd->InitialDirectory = Application::StartupPath;
	ofd->Filter = "txt files (*.txt)|*.txt";
	ofd->ShowDialog();
	convert_String_to_string(ofd->FileName, filename);
	return filename;
}


void parseString(std::string s, std::vector<std::string>& parseSubst, char delimeter)
{
	std::size_t pos = 0, endPos = 0;
	std::string substr = "";
	for (endPos = s.find(delimeter);
		endPos != std::string::npos;
		endPos = s.find(delimeter, endPos + 1)) {
		substr = s.substr(pos, endPos - pos);
		parseSubst.push_back(substr);
		pos = endPos + 1;
	}
	substr = s.substr(pos);
	parseSubst.push_back(substr);
}