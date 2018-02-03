#pragma once

#include <Windows.h>
#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"
#include "lib\UART\UART.h"

#include "lib\Razer\Razer.h"
//
//#include "lib\Measurements\Measurements.h"
//#include "lib\LED\LED.h"
#include "lib\LED\LEDController.h"
#include "lib\LED\WS2812_Definitions.h"

namespace Comptroller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			ledString3 = gcnew LEDController(2, 2);

			razer = gcnew Razer();

			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//

		}

		void debug();

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  debugBox;
	private: System::Windows::Forms::Button^  measureButton;

	private: MSIAfterBurnerPlugin ^ msi;
	private: System::Windows::Forms::Button^  redButton;
	private: System::Windows::Forms::Button^  greenButton;
	private: System::Windows::Forms::Button^  blueButton;



	protected:

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->debugBox = (gcnew System::Windows::Forms::TextBox());
			this->measureButton = (gcnew System::Windows::Forms::Button());
			this->redButton = (gcnew System::Windows::Forms::Button());
			this->greenButton = (gcnew System::Windows::Forms::Button());
			this->blueButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// debugBox
			// 
			this->debugBox->Location = System::Drawing::Point(12, 93);
			this->debugBox->Multiline = true;
			this->debugBox->Name = L"debugBox";
			this->debugBox->Size = System::Drawing::Size(726, 509);
			this->debugBox->TabIndex = 0;
			// 
			// measureButton
			// 
			this->measureButton->Location = System::Drawing::Point(12, 12);
			this->measureButton->Name = L"measureButton";
			this->measureButton->Size = System::Drawing::Size(312, 75);
			this->measureButton->TabIndex = 1;
			this->measureButton->Text = L"Measure";
			this->measureButton->UseVisualStyleBackColor = true;
			this->measureButton->Click += gcnew System::EventHandler(this, &MyForm::measureButton_Click);
			// 
			// redButton
			// 
			this->redButton->Location = System::Drawing::Point(330, 12);
			this->redButton->Name = L"redButton";
			this->redButton->Size = System::Drawing::Size(132, 75);
			this->redButton->TabIndex = 2;
			this->redButton->Text = L"Red";
			this->redButton->UseVisualStyleBackColor = true;
			this->redButton->Click += gcnew System::EventHandler(this, &MyForm::redButton_Click);
			// 
			// greenButton
			// 
			this->greenButton->Location = System::Drawing::Point(468, 12);
			this->greenButton->Name = L"greenButton";
			this->greenButton->Size = System::Drawing::Size(132, 75);
			this->greenButton->TabIndex = 2;
			this->greenButton->Text = L"Green";
			this->greenButton->UseVisualStyleBackColor = true;
			this->greenButton->Click += gcnew System::EventHandler(this, &MyForm::greenButton_Click);
			// 
			// blueButton
			// 
			this->blueButton->Location = System::Drawing::Point(606, 12);
			this->blueButton->Name = L"blueButton";
			this->blueButton->Size = System::Drawing::Size(132, 75);
			this->blueButton->TabIndex = 2;
			this->blueButton->Text = L"Blue";
			this->blueButton->UseVisualStyleBackColor = true;
			this->blueButton->Click += gcnew System::EventHandler(this, &MyForm::blueButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 614);
			this->Controls->Add(this->blueButton);
			this->Controls->Add(this->greenButton);
			this->Controls->Add(this->redButton);
			this->Controls->Add(this->measureButton);
			this->Controls->Add(this->debugBox);
			this->Name = L"MyForm";
			this->Text = L"Comptroller";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void staticColour(unsigned long colour);

	public: LEDController ^ ledString3;
	public: Razer ^ razer;

	private: System::Void measureButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		ledString3->staticColour(BLACK);
		CloseUart();
	}
	private: System::Void redButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void greenButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void blueButton_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
