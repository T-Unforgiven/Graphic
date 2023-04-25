#pragma once
#include"Func.h"
#include <cmath> 


namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			pbPlot->Image = gcnew Bitmap(pbPlot->Width, pbPlot->Height);
			br = gcnew SolidBrush(Color::White);
			pn_axes = gcnew Pen(Color::Black, 3);
			pn_line = gcnew Pen(Color::Red, 3);
			br1 = gcnew SolidBrush(Color::Black);
			pn_net = gcnew Pen(Color::AliceBlue, 1);
			br2 = gcnew SolidBrush(Color::Green);
			pn_green = gcnew Pen(Color::Green, 3);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnBuild;
	private: System::Windows::Forms::TextBox^ tbYmax;
	private: System::Windows::Forms::TextBox^ tbXmax;
	private: System::Windows::Forms::TextBox^ tbYmin;
	private: System::Windows::Forms::TextBox^ tbXmin;
	private: System::Windows::Forms::PictureBox^ pbPlot;
	private: System::Windows::Forms::Button^ btnUp;
	private: System::Windows::Forms::Button^ btnLeft;
	private: System::Windows::Forms::Button^ btnDown;
	private: System::Windows::Forms::Button^ btnRight;
	private: System::Windows::Forms::Button^ btnIn;
	private: System::Windows::Forms::Button^ btnOut;
	private: System::Windows::Forms::ComboBox^ cbF;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnBuild = (gcnew System::Windows::Forms::Button());
			this->tbYmax = (gcnew System::Windows::Forms::TextBox());
			this->tbXmax = (gcnew System::Windows::Forms::TextBox());
			this->tbYmin = (gcnew System::Windows::Forms::TextBox());
			this->tbXmin = (gcnew System::Windows::Forms::TextBox());
			this->pbPlot = (gcnew System::Windows::Forms::PictureBox());
			this->btnUp = (gcnew System::Windows::Forms::Button());
			this->btnLeft = (gcnew System::Windows::Forms::Button());
			this->btnDown = (gcnew System::Windows::Forms::Button());
			this->btnRight = (gcnew System::Windows::Forms::Button());
			this->btnIn = (gcnew System::Windows::Forms::Button());
			this->btnOut = (gcnew System::Windows::Forms::Button());
			this->cbF = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->BeginInit();
			this->SuspendLayout();
			// 
			// btnBuild
			// 
			this->btnBuild->Location = System::Drawing::Point(248, 565);
			this->btnBuild->Name = L"btnBuild";
			this->btnBuild->Size = System::Drawing::Size(75, 23);
			this->btnBuild->TabIndex = 1;
			this->btnBuild->Text = L"Build";
			this->btnBuild->UseVisualStyleBackColor = true;
			this->btnBuild->Click += gcnew System::EventHandler(this, &MyForm::btnBuild_Click);
			// 
			// tbYmax
			// 
			this->tbYmax->Location = System::Drawing::Point(1247, 53);
			this->tbYmax->Name = L"tbYmax";
			this->tbYmax->Size = System::Drawing::Size(44, 22);
			this->tbYmax->TabIndex = 2;
			this->tbYmax->Text = L"4";
			// 
			// tbXmax
			// 
			this->tbXmax->Location = System::Drawing::Point(1247, 109);
			this->tbXmax->Name = L"tbXmax";
			this->tbXmax->Size = System::Drawing::Size(44, 22);
			this->tbXmax->TabIndex = 3;
			this->tbXmax->Text = L"10";
			// 
			// tbYmin
			// 
			this->tbYmin->Location = System::Drawing::Point(1247, 81);
			this->tbYmin->Name = L"tbYmin";
			this->tbYmin->Size = System::Drawing::Size(45, 22);
			this->tbYmin->TabIndex = 4;
			this->tbYmin->Text = L"-4";
			// 
			// tbXmin
			// 
			this->tbXmin->Location = System::Drawing::Point(1247, 137);
			this->tbXmin->Name = L"tbXmin";
			this->tbXmin->Size = System::Drawing::Size(35, 22);
			this->tbXmin->TabIndex = 5;
			this->tbXmin->Text = L"-10";
			// 
			// pbPlot
			// 
			this->pbPlot->Location = System::Drawing::Point(12, 12);
			this->pbPlot->Name = L"pbPlot";
			this->pbPlot->Size = System::Drawing::Size(1182, 475);
			this->pbPlot->TabIndex = 6;
			this->pbPlot->TabStop = false;
			// 
			// btnUp
			// 
			this->btnUp->Location = System::Drawing::Point(971, 507);
			this->btnUp->Name = L"btnUp";
			this->btnUp->Size = System::Drawing::Size(75, 23);
			this->btnUp->TabIndex = 7;
			this->btnUp->Text = L"up";
			this->btnUp->UseVisualStyleBackColor = true;
			this->btnUp->Click += gcnew System::EventHandler(this, &MyForm::btnUp_Click);
			// 
			// btnLeft
			// 
			this->btnLeft->Location = System::Drawing::Point(897, 536);
			this->btnLeft->Name = L"btnLeft";
			this->btnLeft->Size = System::Drawing::Size(75, 23);
			this->btnLeft->TabIndex = 8;
			this->btnLeft->Text = L"left";
			this->btnLeft->UseVisualStyleBackColor = true;
			this->btnLeft->Click += gcnew System::EventHandler(this, &MyForm::btnLeft_Click);
			// 
			// btnDown
			// 
			this->btnDown->Location = System::Drawing::Point(971, 565);
			this->btnDown->Name = L"btnDown";
			this->btnDown->Size = System::Drawing::Size(75, 23);
			this->btnDown->TabIndex = 9;
			this->btnDown->Text = L"Down";
			this->btnDown->UseVisualStyleBackColor = true;
			this->btnDown->Click += gcnew System::EventHandler(this, &MyForm::btnDown_Click);
			// 
			// btnRight
			// 
			this->btnRight->Location = System::Drawing::Point(1045, 536);
			this->btnRight->Name = L"btnRight";
			this->btnRight->Size = System::Drawing::Size(75, 23);
			this->btnRight->TabIndex = 10;
			this->btnRight->Text = L"Right";
			this->btnRight->UseVisualStyleBackColor = true;
			this->btnRight->Click += gcnew System::EventHandler(this, &MyForm::btnRight_Click);
			// 
			// btnIn
			// 
			this->btnIn->Location = System::Drawing::Point(549, 536);
			this->btnIn->Name = L"btnIn";
			this->btnIn->Size = System::Drawing::Size(114, 23);
			this->btnIn->TabIndex = 11;
			this->btnIn->Text = L"X: Zoom in";
			this->btnIn->UseVisualStyleBackColor = true;
			this->btnIn->Click += gcnew System::EventHandler(this, &MyForm::btnIn_Click);
			// 
			// btnOut
			// 
			this->btnOut->Location = System::Drawing::Point(549, 565);
			this->btnOut->Name = L"btnOut";
			this->btnOut->Size = System::Drawing::Size(114, 23);
			this->btnOut->TabIndex = 12;
			this->btnOut->Text = L"X: Zoom out";
			this->btnOut->UseVisualStyleBackColor = true;
			this->btnOut->Click += gcnew System::EventHandler(this, &MyForm::btnOut_Click);
			// 
			// cbF
			// 
			this->cbF->FormattingEnabled = true;
			this->cbF->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"sinc", L"Gaus", L"polynom", L"sin", L"cos" });
			this->cbF->Location = System::Drawing::Point(222, 535);
			this->cbF->Name = L"cbF";
			this->cbF->Size = System::Drawing::Size(121, 24);
			this->cbF->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(669, 536);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Y: Zoom in";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(669, 565);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Y: Zoom out";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1227, 612);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->cbF);
			this->Controls->Add(this->btnOut);
			this->Controls->Add(this->btnIn);
			this->Controls->Add(this->btnRight);
			this->Controls->Add(this->btnDown);
			this->Controls->Add(this->btnLeft);
			this->Controls->Add(this->btnUp);
			this->Controls->Add(this->pbPlot);
			this->Controls->Add(this->tbXmin);
			this->Controls->Add(this->tbYmin);
			this->Controls->Add(this->tbXmax);
			this->Controls->Add(this->tbYmax);
			this->Controls->Add(this->btnBuild);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		double xmin, xmax, ymin, ymax;
		System::Drawing::Font^ printFont = gcnew System::Drawing::Font("Arial", 10);
		System::Drawing::Font^ netFont = gcnew System::Drawing::Font("Arial", 7);
		System::Drawing::Font^ digitFont = gcnew System::Drawing::Font("Arial", 10);
		Brush^ br, ^br1, ^br2;
		bool changesign = false;
		int lastsign;
		int currentsign;
		Pen^ pn_line, ^ pn_axes, ^pn_net, ^pn_green;
		void clear(Image^ img, Brush^ b) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(b, 0, 0, img->Width, img->Height);
		}

		void plot_axes(Image^ img, Pen^ pn, Point origin) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->DrawLine(pn, 0, origin.Y, img->Width, origin.Y);
			gr->DrawLine(pn, origin.X, 0, origin.X, img->Height);
			gr->DrawString("x", printFont, br1, img->Width - 10, origin.Y-15);
			gr->DrawString("y", printFont, br1, origin.X-10, 0);
		}

		void plot(double(*f)(double),
			double xmin,
			double xmax,
			double ymin,
			double ymax,
			Image^ img) {
			clear(img, br);
			double w = img->Width, h = img->Height;
			double xs = (xmax - xmin) / w;
			double ys = (ymax - ymin) / h;
			Point origin(-xmin / xs, ymax / ys);
			plot_net(img, pn_net, origin);
			plot_axes(img, pn_axes, origin);
			Graphics^ gr = Graphics::FromImage(img);
			int y_pix = (ymax - f(xmin)) / ys;
			for (int x_pix1 = 1; x_pix1 < w; x_pix1++) {
				double x = xmin + x_pix1 * xs,
				y = f(x);
				if (x_pix1 == 1) {
					if (y < 0)
						lastsign = currentsign = -1;
					else
						lastsign = currentsign = 1;
				}
				else {
					if (y < 0)
						currentsign = -1;
					else
						currentsign = 1;
				}
				if (lastsign != currentsign) {
					changesign = true;
					lastsign = currentsign;
				}
				if (changesign) {
					gr->DrawString(Convert::ToString(round(x*10)/10), digitFont, br2, x_pix1, origin.Y - 15);
					changesign = false;
				}
				if (x_pix1 == origin.X) {
					gr->DrawString(Convert::ToString(round(y)), digitFont, br2, origin.X, y_pix - 15);
				}
				int y_pix1 = (ymax - y) / ys;
				gr->DrawLine(pn_line, x_pix1 - 1, y_pix, x_pix1, y_pix1);
				y_pix = y_pix1;
			}
		}

		void plot_net(Image^ img, Pen^ pn, Point origin) {
			Graphics^ gr = Graphics::FromImage(img);
			int aaa = img->Width - origin.X;
			int aa = img->Height - origin.Y;
			for (int i = 0; i < aaa; i += 50) {
				gr->DrawLine(pn, origin.X + i, 0, origin.X + i, img->Height);
				gr->DrawString(Convert::ToString(i), netFont, br1, origin.X + i, origin.Y);
			}
			for (int i = origin.X; i > 0; i -= 50) {
				gr->DrawLine(pn, i, 0, i, img->Height);
				gr->DrawString(Convert::ToString(i - origin.X), netFont, br1, i, origin.Y);
			}
			for (int i = 0; i < aa; i += 50) {
				gr->DrawLine(pn, 0, origin.Y + i, img->Width, origin.Y + i);
				gr->DrawString(Convert::ToString(-i), netFont, br1, origin.X, origin.Y + i);
			}
			for (int i = origin.Y; i > 0; i -= 50) {
				gr->DrawLine(pn, 0, i, img->Width, i);
				gr->DrawString(Convert::ToString(-(i - origin.Y)), netFont, br1, origin.X, i);
			}
		}

	private: System::Void btnBuild_Click(System::Object^ sender, System::EventArgs^ e) {

		xmin = Convert::ToDouble(tbXmin->Text);
		xmax = Convert::ToDouble(tbXmax->Text);
		ymin = Convert::ToDouble(tbYmin->Text);
		ymax = Convert::ToDouble(tbYmax->Text);
		if(cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if(cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if(cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if(cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if(cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnUp_Click(System::Object^ sender, System::EventArgs^ e) {
		ymin += 1;
		ymax += 1;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		xmax -= 1;
		xmin -= 1;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnDown_Click(System::Object^ sender, System::EventArgs^ e) {
		ymin -= 1;
		ymax -= 1;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnRight_Click(System::Object^ sender, System::EventArgs^ e) {
		xmax += 1;
		xmin += 1;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnIn_Click(System::Object^ sender, System::EventArgs^ e) {
		xmax = xmax / 2;
		xmin = xmin / 2;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
	private: System::Void btnOut_Click(System::Object^ sender, System::EventArgs^ e) {
		xmax = xmax * 2;
		xmin = xmin * 2;
		if (cbF->Text == "sinc")
			plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "polynom")
			plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "Gaus")
			plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "sin")
			plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
		if (cbF->Text == "cos")
			plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	ymax = ymax / 2;
	ymin = ymin / 2;
	if (cbF->Text == "sinc")
		plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "polynom")
		plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "Gaus")
		plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "sin")
		plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "cos")
		plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
	pbPlot->Refresh();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	ymax = ymax * 2;
	ymin = ymin * 2;
	if (cbF->Text == "sinc")
		plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "polynom")
		plot(polynom4, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "Gaus")
		plot(Gaus, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "sin")
		plot(prikoltan, xmin, xmax, ymin, ymax, pbPlot->Image);
	if (cbF->Text == "cos")
		plot(multicos, xmin, xmax, ymin, ymax, pbPlot->Image);
	pbPlot->Refresh();

}
};
}
