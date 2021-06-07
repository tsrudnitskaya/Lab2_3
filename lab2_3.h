#pragma once
#include "lab2_3/lab2_3_data.h"

namespace Lab23 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для lab2_3
	/// </summary>
	public ref class lab2_3 : public System::Windows::Forms::Form
	{
	public:
		lab2_3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~lab2_3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RadioButton^ fileRadio;

	private: System::Windows::Forms::RadioButton^ keyRadio;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RichTextBox^ consoleBox;

	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::RadioButton^ rpnRadio;

	private: System::Windows::Forms::RadioButton^ pnRadio;

	private: System::Windows::Forms::RadioButton^ exRadio;

	private: System::Windows::Forms::Button^ exCheckBtn;
	private: System::Windows::Forms::Button^ exConvertBtn;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::RadioButton^ tpRpnRadio;



	private: System::Windows::Forms::RadioButton^ toPnRadio;

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ expressionText;
	private: System::Windows::Forms::TextBox^ zText;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ yText;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ xText;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ exCalcBtn;
	private: System::Windows::Forms::Button^ browseBtn;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(lab2_3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->expressionText = (gcnew System::Windows::Forms::TextBox());
			this->zText = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->yText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->xText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->exCheckBtn = (gcnew System::Windows::Forms::Button());
			this->rpnRadio = (gcnew System::Windows::Forms::RadioButton());
			this->exCalcBtn = (gcnew System::Windows::Forms::Button());
			this->pnRadio = (gcnew System::Windows::Forms::RadioButton());
			this->exRadio = (gcnew System::Windows::Forms::RadioButton());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->tpRpnRadio = (gcnew System::Windows::Forms::RadioButton());
			this->toPnRadio = (gcnew System::Windows::Forms::RadioButton());
			this->exConvertBtn = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->browseBtn = (gcnew System::Windows::Forms::Button());
			this->fileRadio = (gcnew System::Windows::Forms::RadioButton());
			this->keyRadio = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->consoleBox = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(146)));
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(311, 541);
			this->panel1->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->richTextBox1);
			this->panel5->Controls->Add(this->expressionText);
			this->panel5->Controls->Add(this->zText);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->yText);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Controls->Add(this->xText);
			this->panel5->Controls->Add(this->label1);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 241);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(311, 152);
			this->panel5->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(146)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(12, 18);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(286, 59);
			this->richTextBox1->TabIndex = 9;
			this->richTextBox1->TabStop = false;
			this->richTextBox1->Text = L"Допускается ввод через пробел операторов, операндов, а так же скобок (без вложенн"
				L"ости). Если вы используете в выражении переменные, не забудьте их ввести";
			// 
			// expressionText
			// 
			this->expressionText->Location = System::Drawing::Point(11, 82);
			this->expressionText->Name = L"expressionText";
			this->expressionText->Size = System::Drawing::Size(285, 20);
			this->expressionText->TabIndex = 8;
			this->expressionText->Text = L"/ + 5 7 3";
			// 
			// zText
			// 
			this->zText->Location = System::Drawing::Point(252, 107);
			this->zText->Name = L"zText";
			this->zText->Size = System::Drawing::Size(44, 20);
			this->zText->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(232, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Z";
			// 
			// yText
			// 
			this->yText->Location = System::Drawing::Point(131, 107);
			this->yText->Name = L"yText";
			this->yText->Size = System::Drawing::Size(45, 20);
			this->yText->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(111, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Y";
			// 
			// xText
			// 
			this->xText->Location = System::Drawing::Point(28, 107);
			this->xText->Name = L"xText";
			this->xText->Size = System::Drawing::Size(45, 20);
			this->xText->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(8, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"X";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->exCheckBtn);
			this->panel6->Controls->Add(this->rpnRadio);
			this->panel6->Controls->Add(this->exCalcBtn);
			this->panel6->Controls->Add(this->pnRadio);
			this->panel6->Controls->Add(this->exRadio);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 139);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(311, 102);
			this->panel6->TabIndex = 5;
			// 
			// exCheckBtn
			// 
			this->exCheckBtn->AutoSize = true;
			this->exCheckBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(142)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->exCheckBtn->FlatAppearance->BorderSize = 0;
			this->exCheckBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exCheckBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exCheckBtn->ForeColor = System::Drawing::Color::White;
			this->exCheckBtn->Location = System::Drawing::Point(150, 18);
			this->exCheckBtn->Name = L"exCheckBtn";
			this->exCheckBtn->Size = System::Drawing::Size(146, 35);
			this->exCheckBtn->TabIndex = 107;
			this->exCheckBtn->Text = L"Проверить";
			this->exCheckBtn->UseVisualStyleBackColor = false;
			this->exCheckBtn->Click += gcnew System::EventHandler(this, &lab2_3::exCheckBtn_Click);
			// 
			// rpnRadio
			// 
			this->rpnRadio->AutoSize = true;
			this->rpnRadio->ForeColor = System::Drawing::Color::White;
			this->rpnRadio->Location = System::Drawing::Point(15, 68);
			this->rpnRadio->Name = L"rpnRadio";
			this->rpnRadio->Size = System::Drawing::Size(93, 17);
			this->rpnRadio->TabIndex = 4;
			this->rpnRadio->Text = L"Обратная ПН";
			this->rpnRadio->UseVisualStyleBackColor = true;
			// 
			// exCalcBtn
			// 
			this->exCalcBtn->AutoSize = true;
			this->exCalcBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(142)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->exCalcBtn->FlatAppearance->BorderSize = 0;
			this->exCalcBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exCalcBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exCalcBtn->ForeColor = System::Drawing::Color::White;
			this->exCalcBtn->Location = System::Drawing::Point(150, 59);
			this->exCalcBtn->Name = L"exCalcBtn";
			this->exCalcBtn->Size = System::Drawing::Size(146, 35);
			this->exCalcBtn->TabIndex = 108;
			this->exCalcBtn->Text = L"Вычислить";
			this->exCalcBtn->UseVisualStyleBackColor = false;
			this->exCalcBtn->Click += gcnew System::EventHandler(this, &lab2_3::exCalcBtn_Click);
			// 
			// pnRadio
			// 
			this->pnRadio->AutoSize = true;
			this->pnRadio->Checked = true;
			this->pnRadio->ForeColor = System::Drawing::Color::White;
			this->pnRadio->Location = System::Drawing::Point(15, 45);
			this->pnRadio->Name = L"pnRadio";
			this->pnRadio->Size = System::Drawing::Size(84, 17);
			this->pnRadio->TabIndex = 3;
			this->pnRadio->TabStop = true;
			this->pnRadio->Text = L"Прямая ПН";
			this->pnRadio->UseVisualStyleBackColor = true;
			// 
			// exRadio
			// 
			this->exRadio->AutoSize = true;
			this->exRadio->ForeColor = System::Drawing::Color::White;
			this->exRadio->Location = System::Drawing::Point(15, 22);
			this->exRadio->Name = L"exRadio";
			this->exRadio->Size = System::Drawing::Size(129, 17);
			this->exRadio->TabIndex = 2;
			this->exRadio->Text = L"Простое выражение";
			this->exRadio->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->tpRpnRadio);
			this->panel4->Controls->Add(this->toPnRadio);
			this->panel4->Controls->Add(this->exConvertBtn);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 61);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(311, 78);
			this->panel4->TabIndex = 3;
			// 
			// tpRpnRadio
			// 
			this->tpRpnRadio->AutoSize = true;
			this->tpRpnRadio->Checked = true;
			this->tpRpnRadio->ForeColor = System::Drawing::Color::White;
			this->tpRpnRadio->Location = System::Drawing::Point(15, 36);
			this->tpRpnRadio->Name = L"tpRpnRadio";
			this->tpRpnRadio->Size = System::Drawing::Size(102, 17);
			this->tpRpnRadio->TabIndex = 3;
			this->tpRpnRadio->TabStop = true;
			this->tpRpnRadio->Text = L"В обратную ПН";
			this->tpRpnRadio->UseVisualStyleBackColor = true;
			// 
			// toPnRadio
			// 
			this->toPnRadio->AutoSize = true;
			this->toPnRadio->ForeColor = System::Drawing::Color::White;
			this->toPnRadio->Location = System::Drawing::Point(15, 13);
			this->toPnRadio->Name = L"toPnRadio";
			this->toPnRadio->Size = System::Drawing::Size(93, 17);
			this->toPnRadio->TabIndex = 2;
			this->toPnRadio->Text = L"В прямую ПН";
			this->toPnRadio->UseVisualStyleBackColor = true;
			// 
			// exConvertBtn
			// 
			this->exConvertBtn->AutoSize = true;
			this->exConvertBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(142)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->exConvertBtn->FlatAppearance->BorderSize = 0;
			this->exConvertBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exConvertBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exConvertBtn->ForeColor = System::Drawing::Color::White;
			this->exConvertBtn->Location = System::Drawing::Point(150, 18);
			this->exConvertBtn->Name = L"exConvertBtn";
			this->exConvertBtn->Size = System::Drawing::Size(146, 35);
			this->exConvertBtn->TabIndex = 106;
			this->exConvertBtn->Text = L"Преобразовать";
			this->exConvertBtn->UseVisualStyleBackColor = false;
			this->exConvertBtn->Click += gcnew System::EventHandler(this, &lab2_3::exConvertBtn_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->browseBtn);
			this->panel3->Controls->Add(this->fileRadio);
			this->panel3->Controls->Add(this->keyRadio);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(311, 61);
			this->panel3->TabIndex = 0;
			// 
			// browseBtn
			// 
			this->browseBtn->FlatAppearance->BorderSize = 0;
			this->browseBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->browseBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"browseBtn.Image")));
			this->browseBtn->Location = System::Drawing::Point(268, 12);
			this->browseBtn->Name = L"browseBtn";
			this->browseBtn->Size = System::Drawing::Size(37, 35);
			this->browseBtn->TabIndex = 109;
			this->browseBtn->UseVisualStyleBackColor = true;
			this->browseBtn->Click += gcnew System::EventHandler(this, &lab2_3::browseBtn_Click);
			// 
			// fileRadio
			// 
			this->fileRadio->AutoSize = true;
			this->fileRadio->ForeColor = System::Drawing::Color::White;
			this->fileRadio->Location = System::Drawing::Point(15, 33);
			this->fileRadio->Name = L"fileRadio";
			this->fileRadio->Size = System::Drawing::Size(74, 17);
			this->fileRadio->TabIndex = 1;
			this->fileRadio->Text = L"Из файла";
			this->fileRadio->UseVisualStyleBackColor = true;
			// 
			// keyRadio
			// 
			this->keyRadio->AutoSize = true;
			this->keyRadio->Checked = true;
			this->keyRadio->ForeColor = System::Drawing::Color::White;
			this->keyRadio->Location = System::Drawing::Point(15, 10);
			this->keyRadio->Name = L"keyRadio";
			this->keyRadio->Size = System::Drawing::Size(95, 17);
			this->keyRadio->TabIndex = 0;
			this->keyRadio->TabStop = true;
			this->keyRadio->Text = L"С клавиатуры";
			this->keyRadio->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->richTextBox2);
			this->panel2->Controls->Add(this->consoleBox);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(311, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(15, 35, 15, 15);
			this->panel2->Size = System::Drawing::Size(473, 541);
			this->panel2->TabIndex = 1;
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->ForeColor = System::Drawing::Color::Black;
			this->richTextBox2->Location = System::Drawing::Point(15, 367);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(443, 162);
			this->richTextBox2->TabIndex = 10;
			this->richTextBox2->TabStop = false;
			this->richTextBox2->Text = resources->GetString(L"richTextBox2.Text");
			// 
			// consoleBox
			// 
			this->consoleBox->BackColor = System::Drawing::Color::White;
			this->consoleBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->consoleBox->Location = System::Drawing::Point(15, 35);
			this->consoleBox->Margin = System::Windows::Forms::Padding(0);
			this->consoleBox->Name = L"consoleBox";
			this->consoleBox->ReadOnly = true;
			this->consoleBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->consoleBox->Size = System::Drawing::Size(443, 318);
			this->consoleBox->TabIndex = 0;
			this->consoleBox->TabStop = false;
			this->consoleBox->Text = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// lab2_3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 541);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"lab2_3";
			this->Text = L"lab2_3";
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		std::string getString();//получить строку для работы
		bool isExValid(std::string s, std::vector <std::string>& arr, String^& consoleText);//проверка простого выражения
		bool isPnValid(std::string s, std::vector <std::string>& arr, String^& consoleText);//проверка польской нотации
		bool isRpnValid(std::string s, std::vector <std::string>& arr, String^& consoleText);//проверка обратной польской нотации
		std::vector <std::string> convertToRpn(std::vector <std::string>& arr, String^& consoleText);//конверт в опн
		std::vector <std::string> convertToPn(std::vector <std::string>& arr, String^& consoleText);//конверт в опн
		void showArr(std::vector <std::string>& arr, String^& consoleText); //Демонстрирует в окошке с логом состояние указанного массива
		bool calcEx(std::vector <std::string>& input, String^& consoleText, double& num);//вычисление выражения 
		void recursiveCalc(std::vector<std::string>& stack,String^& consoleText, bool& err); //рекурсивное вычисление в стеке пн
		bool calcPn(std::vector <std::string>& input, String^& consoleText, double& num);//вычисление выражения в пн
		bool calcRpn(std::vector <std::string>& input, String^& consoleText, double& num);//вычисление выражения в опн
		bool substToEx(std::vector <std::string>& arr, String^& consoleText);

private: System::Void exCheckBtn_Click(System::Object^ sender, System::EventArgs^ e);//обработчик нажатия кнопки проверки выражения
private: System::Void browseBtn_Click(System::Object^ sender, System::EventArgs^ e);//обработчик нажатия кнопки выбора файла
private: System::Void exConvertBtn_Click(System::Object^ sender, System::EventArgs^ e);//обработчик нажатия кнопки преобразовать
private: System::Void exCalcBtn_Click(System::Object^ sender, System::EventArgs^ e); //обработчик нажатия кнопки вычислить
};
}
