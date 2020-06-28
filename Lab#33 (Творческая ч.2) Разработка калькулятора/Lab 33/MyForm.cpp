#include "MyForm.h"
#include <windows.h>
#include <iostream>

using namespace Lab33;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}