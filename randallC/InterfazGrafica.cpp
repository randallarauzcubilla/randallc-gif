#include "pch.h"
#include "InterfazGrafica.h"
#include "Usuarios.h"
#include "RUTAS.h"

using namespace System;
using namespace System::Windows::Forms;

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