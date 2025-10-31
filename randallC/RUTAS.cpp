#include "pch.h"
#include "RUTAS.h"
#include "InterfazGrafica.h"

System::Void randallC::Rutas::btnVOLVER_Click(System::Object^ sender, System::EventArgs^ e) {
    randallC::InterfazGrafica^ menu = gcnew randallC::InterfazGrafica();
    this->Close();
    menu->ShowDialog();
}