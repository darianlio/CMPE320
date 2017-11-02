#pragma once

#include "Fraction_DLL\Fraction_DLL.h"

namespace GUIDarian {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			fillComboBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  equalButton;
	private: System::Windows::Forms::Label^  titleLabel;
	private: System::Windows::Forms::TextBox^  num1Textbox;
	private: System::Windows::Forms::TextBox^  den1Textbox;
	private: System::Windows::Forms::TextBox^  num2Textbox;
	private: System::Windows::Forms::TextBox^  den2Textbox;
	private: System::Windows::Forms::Label^  underlineLabel1;
	private: System::Windows::Forms::Label^  underlineLabel2;
	private: System::Windows::Forms::Label^  underlineLabel3;
	private: System::Windows::Forms::ComboBox^  operandComboBox;
	private: System::Windows::Forms::Label^  errorLabel;
	private: System::Windows::Forms::Label^  numResultLabel;
	private: System::Windows::Forms::Label^  denResultLabel;
	private: System::Windows::Forms::Label^  noteLabel;
	private: System::Windows::Forms::Button^  closeButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->equalButton = (gcnew System::Windows::Forms::Button());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->num1Textbox = (gcnew System::Windows::Forms::TextBox());
			this->den1Textbox = (gcnew System::Windows::Forms::TextBox());
			this->num2Textbox = (gcnew System::Windows::Forms::TextBox());
			this->den2Textbox = (gcnew System::Windows::Forms::TextBox());
			this->underlineLabel1 = (gcnew System::Windows::Forms::Label());
			this->underlineLabel2 = (gcnew System::Windows::Forms::Label());
			this->underlineLabel3 = (gcnew System::Windows::Forms::Label());
			this->operandComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->errorLabel = (gcnew System::Windows::Forms::Label());
			this->numResultLabel = (gcnew System::Windows::Forms::Label());
			this->denResultLabel = (gcnew System::Windows::Forms::Label());
			this->noteLabel = (gcnew System::Windows::Forms::Label());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// equalButton
			// 
			this->equalButton->Location = System::Drawing::Point(186, 90);
			this->equalButton->Name = L"equalButton";
			this->equalButton->Size = System::Drawing::Size(40, 30);
			this->equalButton->TabIndex = 11;
			this->equalButton->Text = L"=";
			this->equalButton->UseVisualStyleBackColor = true;
			this->equalButton->Click += gcnew System::EventHandler(this, &GUI::equalButton_Click);
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(98, 23);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(161, 20);
			this->titleLabel->TabIndex = 5;
			this->titleLabel->Text = L"Fraction Calculator";
			// 
			// num1Textbox
			// 
			this->num1Textbox->Location = System::Drawing::Point(29, 78);
			this->num1Textbox->Name = L"num1Textbox";
			this->num1Textbox->Size = System::Drawing::Size(40, 20);
			this->num1Textbox->TabIndex = 6;
			this->num1Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// den1Textbox
			// 
			this->den1Textbox->Location = System::Drawing::Point(29, 114);
			this->den1Textbox->Name = L"den1Textbox";
			this->den1Textbox->Size = System::Drawing::Size(40, 20);
			this->den1Textbox->TabIndex = 7;
			this->den1Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// num2Textbox
			// 
			this->num2Textbox->Location = System::Drawing::Point(131, 78);
			this->num2Textbox->Name = L"num2Textbox";
			this->num2Textbox->Size = System::Drawing::Size(40, 20);
			this->num2Textbox->TabIndex = 9;
			this->num2Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// den2Textbox
			// 
			this->den2Textbox->Location = System::Drawing::Point(131, 114);
			this->den2Textbox->Name = L"den2Textbox";
			this->den2Textbox->Size = System::Drawing::Size(40, 20);
			this->den2Textbox->TabIndex = 10;
			this->den2Textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// underlineLabel1
			// 
			this->underlineLabel1->AutoSize = true;
			this->underlineLabel1->Location = System::Drawing::Point(254, 94);
			this->underlineLabel1->Name = L"underlineLabel1";
			this->underlineLabel1->Size = System::Drawing::Size(55, 13);
			this->underlineLabel1->TabIndex = 12;
			this->underlineLabel1->Text = L"________";
			// 
			// underlineLabel2
			// 
			this->underlineLabel2->Location = System::Drawing::Point(131, 95);
			this->underlineLabel2->Name = L"underlineLabel2";
			this->underlineLabel2->Size = System::Drawing::Size(49, 23);
			this->underlineLabel2->TabIndex = 13;
			this->underlineLabel2->Text = L"______";
			// 
			// underlineLabel3
			// 
			this->underlineLabel3->Location = System::Drawing::Point(29, 94);
			this->underlineLabel3->Name = L"underlineLabel3";
			this->underlineLabel3->Size = System::Drawing::Size(100, 23);
			this->underlineLabel3->TabIndex = 14;
			this->underlineLabel3->Text = L"______";
			// 
			// operandComboBox
			// 
			this->operandComboBox->AllowDrop = true;
			this->operandComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->operandComboBox->FormattingEnabled = true;
			this->operandComboBox->Location = System::Drawing::Point(77, 94);
			this->operandComboBox->Name = L"operandComboBox";
			this->operandComboBox->Size = System::Drawing::Size(43, 21);
			this->operandComboBox->TabIndex = 8;
			// 
			// errorLabel
			// 
			this->errorLabel->AutoSize = true;
			this->errorLabel->ForeColor = System::Drawing::Color::Red;
			this->errorLabel->Location = System::Drawing::Point(26, 52);
			this->errorLabel->Name = L"errorLabel";
			this->errorLabel->Size = System::Drawing::Size(93, 13);
			this->errorLabel->TabIndex = 16;
			this->errorLabel->Text = L"Waiting for input...";
			// 
			// numResultLabel
			// 
			this->numResultLabel->AutoSize = true;
			this->numResultLabel->Location = System::Drawing::Point(270, 85);
			this->numResultLabel->Name = L"numResultLabel";
			this->numResultLabel->Size = System::Drawing::Size(23, 13);
			this->numResultLabel->TabIndex = 17;
			this->numResultLabel->Text = L"null";
			// 
			// denResultLabel
			// 
			this->denResultLabel->AutoSize = true;
			this->denResultLabel->Location = System::Drawing::Point(270, 117);
			this->denResultLabel->Name = L"denResultLabel";
			this->denResultLabel->Size = System::Drawing::Size(23, 13);
			this->denResultLabel->TabIndex = 18;
			this->denResultLabel->Text = L"null";
			// 
			// noteLabel
			// 
			this->noteLabel->AutoSize = true;
			this->noteLabel->Location = System::Drawing::Point(29, 156);
			this->noteLabel->Name = L"noteLabel";
			this->noteLabel->Size = System::Drawing::Size(215, 26);
			this->noteLabel->TabIndex = 19;
			this->noteLabel->Text = L"Note: Press \'Enter\' to calculate. \n          Press \'<Alt> + C\' to close the progr"
				L"am.";
			// 
			// closeButton
			// 
			this->closeButton->Location = System::Drawing::Point(251, 194);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(75, 23);
			this->closeButton->TabIndex = 20;
			this->closeButton->Text = L"Exit";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &GUI::closeButton_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(342, 229);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->noteLabel);
			this->Controls->Add(this->denResultLabel);
			this->Controls->Add(this->numResultLabel);
			this->Controls->Add(this->errorLabel);
			this->Controls->Add(this->operandComboBox);
			this->Controls->Add(this->underlineLabel1);
			this->Controls->Add(this->den1Textbox);
			this->Controls->Add(this->num1Textbox);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->equalButton);
			this->Controls->Add(this->underlineLabel3);
			this->Controls->Add(this->num2Textbox);
			this->Controls->Add(this->den2Textbox);
			this->Controls->Add(this->underlineLabel2);
			this->KeyDown += gcnew KeyEventHandler(this, &GUI::altKeyHandler);
			this->KeyDown += gcnew KeyEventHandler(this, &GUI::enterKeyHandler);
			this->KeyPreview = true;
			this->Location = System::Drawing::Point(96, 110);
			this->Name = L"GUI";
			this->Text = L"Fraction Calculator by Darian Lio";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) { }
	private: System::Void equalButton_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			this->denResultLabel->Visible = true;
			this->underlineLabel1->Visible = true;

			int num1 = Int32::Parse(num1Textbox->Text);
			int den1 = Int32::Parse(den1Textbox->Text);
			int num2 = Int32::Parse(num2Textbox->Text);
			int den2 = Int32::Parse(den2Textbox->Text);

			if (den1 == 0 || den2 == 0) {
				this->errorLabel->Text = "Illegal argument: Cannot divide by zero.";
				return;
			}
 
			Fraction result;
			String^ numResult;
			String^ denResult;
			if (this->operandComboBox->SelectedItem == "+") {
				result = Fraction(num1, den1) + Fraction(num2, den2);
			}
			else if (this->operandComboBox->SelectedItem == "-") {
				result = Fraction(num1, den1) - Fraction(num2, den2);
			}
			else if (this->operandComboBox->SelectedItem == "*") {
				result = Fraction(num1, den1) * Fraction(num2, den2);
			}
			else if (this->operandComboBox->SelectedItem == "/") {
				if (num2 == 0) {
					this->errorLabel->Text = "Illegal argument: Cannot divide by zero.";
					return;
				}
				result = Fraction(num1, den1) / Fraction(num2, den2);
			}
			else {
				this->errorLabel->Text = "Error: Please select an operand.";
				return;
			}


			if (result.denominator() == 1 || result.numerator() == 0){
				numResult = Convert::ToString(result.numerator());
				this->denResultLabel->Visible = false;
				this->underlineLabel1->Visible = false;
			}
			else {
				numResult = Convert::ToString(result.numerator());
				denResult = Convert::ToString(result.denominator());
			}

			this->numResultLabel->Text = numResult;
			this->denResultLabel->Text = denResult;
			this->errorLabel->Text = "Sucess: Result has been calculated.";
		}
		catch (System::FormatException^) {
			this->errorLabel->Text = "Error: Please fill in all the inputs correctly.";
		}
		catch (System::OverflowException^) {
			this->errorLabel->Text = "Error: The number exceeds the limit, resulting in overflow.";
		}
	}

	private: System::Void fillComboBox() {
		this->operandComboBox->Items->Add("+");
		this->operandComboBox->Items->Add("-");
		this->operandComboBox->Items->Add("*");
		this->operandComboBox->Items->Add("/");
	}

	private: System::Void altKeyHandler(System::Object^  sender, KeyEventArgs^  e) {
		if (e->Alt && (char)e->KeyCode == (char)67) {
			this->errorLabel->Text = "The program is closing...";
			this->Close();
		}
	}

	private: System::Void enterKeyHandler(System::Object^  sender, KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter) {
			equalButton_Click(this, gcnew EventArgs());
		}
	}
	private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->errorLabel->Text = "The program is closing...";
		this->Close();
	}
};
}
