#include "pch.h"
#include "InterfazGrafica.h"
#include "Usuarios.h"
#include "RUTAS.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew randallC::InterfazGrafica());
    return 0;
}

System::Void randallC::InterfazGrafica::btnMenuUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	randallC::Usuarios^ usuarios = gcnew randallC::Usuarios();
	usuarios->ShowDialog();
	this->Show();
}

System::Void randallC::InterfazGrafica::btnMenuRutas_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	randallC::Rutas^ rutas = gcnew randallC::Rutas();
	rutas->ShowDialog();
	this->Show();
}