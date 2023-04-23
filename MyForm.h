#pragma once
#include"Func.h"


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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->BeginInit();
			this->SuspendLayout();
			// 
			// btnBuild
			// 
			this->btnBuild->Location = System::Drawing::Point(162, 242);
			this->btnBuild->Name = L"btnBuild";
			this->btnBuild->Size = System::Drawing::Size(75, 23);
			this->btnBuild->TabIndex = 1;
			this->btnBuild->Text = L"Build";
			this->btnBuild->UseVisualStyleBackColor = true;
			this->btnBuild->Click += gcnew System::EventHandler(this, &MyForm::btnBuild_Click);
			// 
			// tbYmax
			// 
			this->tbYmax->Location = System::Drawing::Point(447, 41);
			this->tbYmax->Name = L"tbYmax";
			this->tbYmax->Size = System::Drawing::Size(44, 22);
			this->tbYmax->TabIndex = 2;
			// 
			// tbXmax
			// 
			this->tbXmax->Location = System::Drawing::Point(397, 242);
			this->tbXmax->Name = L"tbXmax";
			this->tbXmax->Size = System::Drawing::Size(44, 22);
			this->tbXmax->TabIndex = 3;
			// 
			// tbYmin
			// 
			this->tbYmin->Location = System::Drawing::Point(447, 199);
			this->tbYmin->Name = L"tbYmin";
			this->tbYmin->Size = System::Drawing::Size(45, 22);
			this->tbYmin->TabIndex = 4;
			// 
			// tbXmin
			// 
			this->tbXmin->Location = System::Drawing::Point(12, 227);
			this->tbXmin->Name = L"tbXmin";
			this->tbXmin->Size = System::Drawing::Size(35, 22);
			this->tbXmin->TabIndex = 5;
			// 
			// pbPlot
			// 
			this->pbPlot->Location = System::Drawing::Point(18, 16);
			this->pbPlot->Name = L"pbPlot";
			this->pbPlot->Size = System::Drawing::Size(423, 205);
			this->pbPlot->TabIndex = 6;
			this->pbPlot->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 373);
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

		Brush^ br;
		Pen^ pn_line, ^ pn_axes;
		void clear(Image^ img, Brush^ b) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(b, 0, 0, img->Width, img->Height);
		}

		void plot_axes(Image^ img, Pen^ pn, Point origin) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->DrawLine(pn, 0, origin.Y, img->Width, origin.Y);
			gr->DrawLine(pn, origin.X, 0, origin.X, img->Height);
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
			plot_axes(img, pn_axes, origin);
			Graphics^ gr = Graphics::FromImage(img);
			int y_pix = (ymax - f(xmin)) / ys;
			for (int x_pix1 = 1; x_pix1 < w; x_pix1++) {
				double x = xmin + x_pix1 * xs,
				y = f(x);
				int y_pix1 = (ymax - y) / ys;
				gr->DrawLine(pn_line, x_pix1 - 1, y_pix, x_pix1, y_pix1);
				y_pix = y_pix1;
			}
		}

	private: System::Void btnBuild_Click(System::Object^ sender, System::EventArgs^ e) {

		double xmin = Convert::ToDouble(tbXmin->Text), xmax = Convert::ToDouble(tbXmax->Text),
			ymin = Convert::ToDouble(tbYmin->Text), ymax = Convert::ToDouble(tbYmax->Text);
		plot(sinc, xmin, xmax, ymin, ymax, pbPlot->Image);
		pbPlot->Refresh();
	}
};
}
