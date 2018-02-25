#pragma once

#include <Windows.h>
#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"
#include "lib\UART\UART.h"
#include "lib\LED\LED.h"
#include "lib\Razer\Razer.h"
#include "lib\Asus\Asus.h"
#include "lib\QMK\QMK.h"
//
//#include "lib\Measurements\Measurements.h"
//#include "lib\LED\LED.h"
#include "lib\LED\LEDController.h"
#include "lib\LED\WS2812_Definitions.h"
#include "lib\Configuration\Configuration.h"


#undef RGB

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
			this->tempControlInitialised = false;
			this->msi = gcnew MSIAfterBurnerPlugin();
			this->config = gcnew Config();

			InitializeComponent();

			this->debugCheckBox->Checked = this->config->debug;

			this->initComponents();
			this->updateComponents();
			this->initTempControl();
			this->updateTempControl();

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
	private: System::Windows::Forms::TrackBar^  greenBar;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TrackBar^  redBar;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  blueBar;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  colourPanel;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::CheckBox^  razerCheckBox;
	private: System::Windows::Forms::CheckBox^  ledStringsCheckBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  asusCheckBox;

	private: Config ^ config;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::CheckBox^  tempControlCheckBox;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  tempControlList;
	private: System::Windows::Forms::Timer^  updateTimer;
	private: System::Windows::Forms::CheckBox^  manualControlBox;
	private: System::Windows::Forms::CheckBox^  debugCheckBox;
	private: System::Windows::Forms::CheckBox^  qmkCheckBox;

	private: System::ComponentModel::IContainer^  components;



	protected:

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->debugBox = (gcnew System::Windows::Forms::TextBox());
			this->measureButton = (gcnew System::Windows::Forms::Button());
			this->redButton = (gcnew System::Windows::Forms::Button());
			this->greenButton = (gcnew System::Windows::Forms::Button());
			this->blueButton = (gcnew System::Windows::Forms::Button());
			this->greenBar = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->blueBar = (gcnew System::Windows::Forms::TrackBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->redBar = (gcnew System::Windows::Forms::TrackBar());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->colourPanel = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->asusCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->razerCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ledStringsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->tempControlList = (gcnew System::Windows::Forms::ComboBox());
			this->manualControlBox = (gcnew System::Windows::Forms::CheckBox());
			this->tempControlCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->debugCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->qmkCheckBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenBar))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueBar))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redBar))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// debugBox
			// 
			this->debugBox->Location = System::Drawing::Point(32, 222);
			this->debugBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->debugBox->Multiline = true;
			this->debugBox->Name = L"debugBox";
			this->debugBox->Size = System::Drawing::Size(1193, 1208);
			this->debugBox->TabIndex = 0;
			// 
			// measureButton
			// 
			this->measureButton->Location = System::Drawing::Point(32, 29);
			this->measureButton->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->measureButton->Name = L"measureButton";
			this->measureButton->Size = System::Drawing::Size(1200, 179);
			this->measureButton->TabIndex = 1;
			this->measureButton->Text = L"Measure";
			this->measureButton->UseVisualStyleBackColor = true;
			this->measureButton->Click += gcnew System::EventHandler(this, &MyForm::measureButton_Click);
			// 
			// redButton
			// 
			this->redButton->Location = System::Drawing::Point(1667, 222);
			this->redButton->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->redButton->Name = L"redButton";
			this->redButton->Size = System::Drawing::Size(301, 103);
			this->redButton->TabIndex = 2;
			this->redButton->Text = L"Red";
			this->redButton->UseVisualStyleBackColor = true;
			this->redButton->Click += gcnew System::EventHandler(this, &MyForm::redButton_Click);
			// 
			// greenButton
			// 
			this->greenButton->Location = System::Drawing::Point(1667, 339);
			this->greenButton->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->greenButton->Name = L"greenButton";
			this->greenButton->Size = System::Drawing::Size(301, 88);
			this->greenButton->TabIndex = 2;
			this->greenButton->Text = L"Green";
			this->greenButton->UseVisualStyleBackColor = true;
			this->greenButton->Click += gcnew System::EventHandler(this, &MyForm::greenButton_Click);
			// 
			// blueButton
			// 
			this->blueButton->Location = System::Drawing::Point(1667, 441);
			this->blueButton->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->blueButton->Name = L"blueButton";
			this->blueButton->Size = System::Drawing::Size(301, 95);
			this->blueButton->TabIndex = 2;
			this->blueButton->Text = L"Blue";
			this->blueButton->UseVisualStyleBackColor = true;
			this->blueButton->Click += gcnew System::EventHandler(this, &MyForm::blueButton_Click);
			// 
			// greenBar
			// 
			this->greenBar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->greenBar->LargeChange = 25;
			this->greenBar->Location = System::Drawing::Point(0, 55);
			this->greenBar->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->greenBar->Maximum = 255;
			this->greenBar->Name = L"greenBar";
			this->greenBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->greenBar->Size = System::Drawing::Size(115, 761);
			this->greenBar->TabIndex = 3;
			this->greenBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::colourBar_ValueChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Blue;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 48);
			this->label1->TabIndex = 4;
			this->label1->Text = L"B";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Location = System::Drawing::Point(1248, 222);
			this->panel1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(396, 834);
			this->panel1->TabIndex = 5;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->blueBar);
			this->panel4->Location = System::Drawing::Point(269, 7);
			this->panel4->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(115, 816);
			this->panel4->TabIndex = 11;
			// 
			// blueBar
			// 
			this->blueBar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->blueBar->LargeChange = 25;
			this->blueBar->Location = System::Drawing::Point(0, 55);
			this->blueBar->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->blueBar->Maximum = 255;
			this->blueBar->Name = L"blueBar";
			this->blueBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->blueBar->Size = System::Drawing::Size(115, 761);
			this->blueBar->TabIndex = 5;
			this->blueBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::colourBar_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->redBar);
			this->panel2->Location = System::Drawing::Point(8, 7);
			this->panel2->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(115, 816);
			this->panel2->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Red;
			this->label3->Dock = System::Windows::Forms::DockStyle::Top;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 48);
			this->label3->TabIndex = 8;
			this->label3->Text = L"R";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// redBar
			// 
			this->redBar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->redBar->LargeChange = 25;
			this->redBar->Location = System::Drawing::Point(0, 55);
			this->redBar->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->redBar->Maximum = 255;
			this->redBar->Name = L"redBar";
			this->redBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->redBar->Size = System::Drawing::Size(115, 761);
			this->redBar->TabIndex = 7;
			this->redBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::colourBar_ValueChanged);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->greenBar);
			this->panel3->Location = System::Drawing::Point(139, 7);
			this->panel3->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(115, 816);
			this->panel3->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Lime;
			this->label2->Dock = System::Windows::Forms::DockStyle::Top;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 48);
			this->label2->TabIndex = 6;
			this->label2->Text = L"G";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// colourPanel
			// 
			this->colourPanel->BackColor = System::Drawing::Color::Black;
			this->colourPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->colourPanel->Location = System::Drawing::Point(1248, 1075);
			this->colourPanel->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->colourPanel->Name = L"colourPanel";
			this->colourPanel->Size = System::Drawing::Size(399, 357);
			this->colourPanel->TabIndex = 6;
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->qmkCheckBox);
			this->panel5->Controls->Add(this->asusCheckBox);
			this->panel5->Controls->Add(this->razerCheckBox);
			this->panel5->Controls->Add(this->ledStringsCheckBox);
			this->panel5->Location = System::Drawing::Point(1667, 613);
			this->panel5->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(295, 235);
			this->panel5->TabIndex = 7;
			// 
			// asusCheckBox
			// 
			this->asusCheckBox->AutoSize = true;
			this->asusCheckBox->Location = System::Drawing::Point(11, 119);
			this->asusCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->asusCheckBox->Name = L"asusCheckBox";
			this->asusCheckBox->Size = System::Drawing::Size(116, 36);
			this->asusCheckBox->TabIndex = 0;
			this->asusCheckBox->Text = L"Asus";
			this->asusCheckBox->UseVisualStyleBackColor = true;
			this->asusCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::componentCheckBox_CheckedChanged);
			// 
			// razerCheckBox
			// 
			this->razerCheckBox->AutoSize = true;
			this->razerCheckBox->Checked = true;
			this->razerCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->razerCheckBox->Location = System::Drawing::Point(11, 64);
			this->razerCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->razerCheckBox->Name = L"razerCheckBox";
			this->razerCheckBox->Size = System::Drawing::Size(128, 36);
			this->razerCheckBox->TabIndex = 0;
			this->razerCheckBox->Text = L"Razer";
			this->razerCheckBox->UseVisualStyleBackColor = true;
			this->razerCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::componentCheckBox_CheckedChanged);
			// 
			// ledStringsCheckBox
			// 
			this->ledStringsCheckBox->AutoSize = true;
			this->ledStringsCheckBox->Checked = true;
			this->ledStringsCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ledStringsCheckBox->Location = System::Drawing::Point(11, 10);
			this->ledStringsCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->ledStringsCheckBox->Name = L"ledStringsCheckBox";
			this->ledStringsCheckBox->Size = System::Drawing::Size(204, 36);
			this->ledStringsCheckBox->TabIndex = 0;
			this->ledStringsCheckBox->Text = L"LED Strings";
			this->ledStringsCheckBox->UseVisualStyleBackColor = true;
			this->ledStringsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::componentCheckBox_CheckedChanged);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(1669, 568);
			this->label4->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(299, 38);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Components Control";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Controls->Add(this->tempControlList);
			this->panel6->Controls->Add(this->manualControlBox);
			this->panel6->Controls->Add(this->tempControlCheckBox);
			this->panel6->Location = System::Drawing::Point(1667, 901);
			this->panel6->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(295, 214);
			this->panel6->TabIndex = 7;
			// 
			// tempControlList
			// 
			this->tempControlList->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->tempControlList->Enabled = false;
			this->tempControlList->FormattingEnabled = true;
			this->tempControlList->Location = System::Drawing::Point(11, 117);
			this->tempControlList->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->tempControlList->Name = L"tempControlList";
			this->tempControlList->Size = System::Drawing::Size(265, 39);
			this->tempControlList->TabIndex = 1;
			this->tempControlList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tempControlList_SelectedIndexChanged);
			// 
			// manualControlBox
			// 
			this->manualControlBox->AutoSize = true;
			this->manualControlBox->Location = System::Drawing::Point(11, 7);
			this->manualControlBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->manualControlBox->Name = L"manualControlBox";
			this->manualControlBox->Size = System::Drawing::Size(246, 36);
			this->manualControlBox->TabIndex = 0;
			this->manualControlBox->Text = L"Manual Control";
			this->manualControlBox->UseVisualStyleBackColor = true;
			this->manualControlBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::tempControlUpdate);
			// 
			// tempControlCheckBox
			// 
			this->tempControlCheckBox->AutoSize = true;
			this->tempControlCheckBox->Location = System::Drawing::Point(11, 62);
			this->tempControlCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->tempControlCheckBox->Name = L"tempControlCheckBox";
			this->tempControlCheckBox->Size = System::Drawing::Size(224, 36);
			this->tempControlCheckBox->TabIndex = 0;
			this->tempControlCheckBox->Text = L"Temp Control";
			this->tempControlCheckBox->UseVisualStyleBackColor = true;
			this->tempControlCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::tempControlUpdate);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(1669, 855);
			this->label5->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(299, 38);
			this->label5->TabIndex = 8;
			this->label5->Text = L"LEDs Control";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// updateTimer
			// 
			this->updateTimer->Tick += gcnew System::EventHandler(this, &MyForm::updateTimer_Tick);
			// 
			// debugCheckBox
			// 
			this->debugCheckBox->AutoSize = true;
			this->debugCheckBox->Location = System::Drawing::Point(1248, 100);
			this->debugCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->debugCheckBox->Name = L"debugCheckBox";
			this->debugCheckBox->Size = System::Drawing::Size(137, 36);
			this->debugCheckBox->TabIndex = 0;
			this->debugCheckBox->Text = L"Debug";
			this->debugCheckBox->UseVisualStyleBackColor = true;
			this->debugCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::debugCheckBox_CheckedChanged);
			// 
			// qmkCheckBox
			// 
			this->qmkCheckBox->AutoSize = true;
			this->qmkCheckBox->Location = System::Drawing::Point(11, 169);
			this->qmkCheckBox->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->qmkCheckBox->Name = L"qmkCheckBox";
			this->qmkCheckBox->Size = System::Drawing::Size(117, 36);
			this->qmkCheckBox->TabIndex = 0;
			this->qmkCheckBox->Text = L"QMK";
			this->qmkCheckBox->UseVisualStyleBackColor = true;
			this->qmkCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::componentCheckBox_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2000, 1464);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->debugCheckBox);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->colourPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->blueButton);
			this->Controls->Add(this->greenButton);
			this->Controls->Add(this->redButton);
			this->Controls->Add(this->measureButton);
			this->Controls->Add(this->debugBox);
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"MyForm";
			this->Text = L"Comptroller";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenBar))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueBar))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redBar))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void staticColour(Colour ^colour);

	public: void updateColourBars(Colour ^colour);

	public: LEDController ^ledString3, ^ledString1;
	public: Razer ^ razer;
	public: Asus ^ asus;
	public: QMK ^ qmk;

	private: System::Void measureButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		ledString3->staticColour(BLACK);
		ledString1->staticColour(BLACK);
		CloseUart();
	}

	private: void updateComponents();
	private: void initComponents();
	private: bool tempControlInitialised;
	private: void initTempControl();
	private: void updateTempControl();

	private: System::Void redButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void greenButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void blueButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void colourBar_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void componentCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tempControlUpdate(System::Object^  sender, System::EventArgs^  e);

	private: System::Void updateTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void debugCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		this->config->debug = this->debugCheckBox->Checked;
	}
	private: System::Void tempControlList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
		this->updateTempControl();
	}
};
}
