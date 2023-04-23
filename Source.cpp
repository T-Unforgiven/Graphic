#include "MyForm.h"

using namespace Project7;
[STAThreadAttribute]
void main(cli::array<System::String^>^ args)
{
	Application::Run(gcnew MyForm());

}
//5 функций через комбобох(ченить сложное), подписать оси, сделать сетку и подписать деления, должна быть возможность двигать график, отметить точки пересечения с осями, параллельный перенос