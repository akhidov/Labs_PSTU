#pragma once

namespace Lab33 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			listBox1->SelectedIndex = 0;
			listBox2->SelectedIndex = 1;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Из";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"RUB", L"USD", L"EUR" });
			this->listBox1->Location = System::Drawing::Point(43, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(42, 52);
			this->listBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(100, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"в";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"RUB", L"USD", L"EUR" });
			this->listBox2->Location = System::Drawing::Point(121, 12);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(42, 52);
			this->listBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Курс(RUB/USD)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 157);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(111, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Курс(RUB/EUR)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"69,78";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyChar);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(129, 152);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"78,28";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyChar);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(208, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(205, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Введите сумму для перевода:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(419, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 9;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyChar);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 211);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 66);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Перевести";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(306, 211);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 66);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Сброс";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(303, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Результат:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(419, 90);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 13;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox4_KeyChar);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(566, 289);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBox1_KeyChar(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8 && number != 44)
	{
		e->Handled = true;
	}
}

private: System::Void textBox2_KeyChar(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8 && number != 44)
	{
		e->Handled = true;
	}
}


private: System::Void textBox3_KeyChar(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char number = e->KeyChar;
	if ((e->KeyChar <= 47 || e->KeyChar >= 58) && number != 8 && number != 44)
	{
		e->Handled = true;
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ from;
	String^ to;

	from = listBox1->SelectedItem->ToString();
	to = listBox2->SelectedItem->ToString();

	if (from == to)
	{
		MessageBox::Show("Это одна и та же валюта", "Ошибка.");
	}
	else
	{
		if ((textBox1->Text == "") || (textBox2->Text == ""))
		{
			MessageBox::Show("Не указан один из курсов", "Ошибка.");
		}
		else if (textBox3->Text == "")
		{
			MessageBox::Show("Вы не ввели количество валюты", "Ошибка.");
		}
		else
		{
			double usd, eur, sum, res;
			usd = Convert::ToDouble(textBox1->Text);
			eur = Convert::ToDouble(textBox2->Text);
			sum = Convert::ToDouble(textBox3->Text);

			if ((listBox1->SelectedIndex == 0) && (listBox2->SelectedIndex == 1))
			{
				res = sum * (1 / usd);
				textBox4->Text = Convert::ToString(res);
			}
			if ((listBox1->SelectedIndex == 0) && (listBox2->SelectedIndex == 2))
			{
				res = sum * (1 / eur);
				textBox4->Text = Convert::ToString(res);
			}
			if ((listBox1->SelectedIndex == 1) && (listBox2->SelectedIndex == 0))
			{
				res = sum * usd;
				textBox4->Text = Convert::ToString(res);
			}
			if ((listBox1->SelectedIndex == 1) && (listBox2->SelectedIndex == 2))
			{
				res = sum * (usd / eur);
				textBox4->Text = Convert::ToString(res);
			}
			if ((listBox1->SelectedIndex == 2) && (listBox2->SelectedIndex == 0))
			{
				res = sum * eur;
				textBox4->Text = Convert::ToString(res);
			}
			if ((listBox1->SelectedIndex == 2) && (listBox2->SelectedIndex == 1))
			{
				res = sum * (eur / usd);
				textBox4->Text = Convert::ToString(res);
			}
		}
	}
}
	  
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	listBox1->SelectedIndex = 0;
	listBox2->SelectedIndex = 1;
	textBox1->Text = "69,78";
	textBox2->Text = "78,28";
	textBox3->Text = "";
	textBox4->Text = "";
}

private: System::Void textBox4_KeyChar(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	char number = e->KeyChar;
	e->Handled = true;
}

};
}
