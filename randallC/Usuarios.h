#pragma once
#include <string>
#include "ArbolUsuarios.h"
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "InterfazGrafica.h" 
namespace randallC {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Usuarios
	/// </summary>
	public ref class Usuarios : public System::Windows::Forms::Form
	{
	public:
		Usuarios(void)
		{
			InitializeComponent();
			arbol = new ArbolUsuarios();
			arbol->cargarDesdeArchivo("usuarios.txt");
		}

	protected:
		~Usuarios()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ txtMENU_USUARIOS;
	protected:
	private: System::Windows::Forms::Button^ btnInsertarUsuario;
	private: System::Windows::Forms::Button^ btnEliminarUsuario;
	private: System::Windows::Forms::Button^ btnBUSCAR_USUARIO_ID;
	private: System::Windows::Forms::Button^ btnMostrarUsuariosAlfabeticamente;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::RichTextBox^ mostrarContenido;

	private: System::Windows::Forms::Button^ btnVOLVER;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::TextBox^ txtEdad;
	private: System::Windows::Forms::TextBox^ txtSaldo;
	private: System::Windows::Forms::Button^ Ver_Recorrido;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		ArbolUsuarios* arbol;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtMENU_USUARIOS = (gcnew System::Windows::Forms::Label());
			this->btnInsertarUsuario = (gcnew System::Windows::Forms::Button());
			this->btnEliminarUsuario = (gcnew System::Windows::Forms::Button());
			this->btnBUSCAR_USUARIO_ID = (gcnew System::Windows::Forms::Button());
			this->btnMostrarUsuariosAlfabeticamente = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->mostrarContenido = (gcnew System::Windows::Forms::RichTextBox());
			this->mostrarContenido->ReadOnly = true;
			this->btnVOLVER = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtEdad = (gcnew System::Windows::Forms::TextBox());
			this->txtSaldo = (gcnew System::Windows::Forms::TextBox());
			this->Ver_Recorrido = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			System::Drawing::Color botonColor = System::Drawing::Color::White;
			System::Drawing::Size botonTamano = System::Drawing::Size(175, 36);

			// Eventos
			this->btnInsertarUsuario->Click += gcnew System::EventHandler(this, &Usuarios::btnInsertarUsuario_Click);
			this->btnEliminarUsuario->Click += gcnew System::EventHandler(this, &Usuarios::btnEliminarUsuario_Click);
			this->btnBUSCAR_USUARIO_ID->Click += gcnew System::EventHandler(this, &Usuarios::btnBUSCAR_USUARIO_ID_Click);
			this->btnMostrarUsuariosAlfabeticamente->Click += gcnew System::EventHandler(this, &Usuarios::btnMostrarUsuariosAlfabeticamente_Click);
			this->Ver_Recorrido->Click += gcnew System::EventHandler(this, &Usuarios::Ver_Recorrido_Click);
			this->btnVOLVER->Click += gcnew System::EventHandler(this, &Usuarios::btnVOLVER_Click);

			// txtMENU_USUARIOS
			this->txtMENU_USUARIOS->AutoSize = true;
			this->txtMENU_USUARIOS->BackColor = System::Drawing::Color::White;
			this->txtMENU_USUARIOS->Location = System::Drawing::Point(398, 52);
			this->txtMENU_USUARIOS->Name = L"txtMENU_USUARIOS";
			this->txtMENU_USUARIOS->Size = System::Drawing::Size(142, 16);
			this->txtMENU_USUARIOS->TabIndex = 0;
			this->txtMENU_USUARIOS->Text = L"MENU DE USUARIOS";

			// btnInsertarUsuario
			this->btnInsertarUsuario->Location = System::Drawing::Point(112, 128);
			this->btnInsertarUsuario->Name = L"btnInsertarUsuario";
			this->btnInsertarUsuario->Size = botonTamano;
			this->btnInsertarUsuario->BackColor = botonColor;
			this->btnInsertarUsuario->Text = L"INSERTAR_USUARIO";

			// btnEliminarUsuario
			this->btnEliminarUsuario->Location = System::Drawing::Point(639, 124);
			this->btnEliminarUsuario->Name = L"btnEliminarUsuario";
			this->btnEliminarUsuario->Size = botonTamano;
			this->btnEliminarUsuario->BackColor = botonColor;
			this->btnEliminarUsuario->Text = L"ELIMINAR_USUARIO";

			// btnBUSCAR_USUARIO_ID
			this->btnBUSCAR_USUARIO_ID->Location = System::Drawing::Point(374, 124);
			this->btnBUSCAR_USUARIO_ID->Name = L"btnBUSCAR_USUARIO_ID";
			this->btnBUSCAR_USUARIO_ID->Size = botonTamano;
			this->btnBUSCAR_USUARIO_ID->BackColor = botonColor;
			this->btnBUSCAR_USUARIO_ID->Text = L"BUSCAR_USUARIO_ID";

			// btnMostrarUsuariosAlfabeticamente
			this->btnMostrarUsuariosAlfabeticamente->Location = System::Drawing::Point(72, 455);
			this->btnMostrarUsuariosAlfabeticamente->Name = L"btnMostrarUsuariosAlfabeticamente";
			this->btnMostrarUsuariosAlfabeticamente->Size = botonTamano;
			this->btnMostrarUsuariosAlfabeticamente->BackColor = botonColor;
			this->btnMostrarUsuariosAlfabeticamente->Text = L"MOSTRAR_ALFABETICAMENTE";

			// comboBox1
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^ >(3) { L"inOrden", L"preOrden", L"postOrden" });
			this->comboBox1->Location = System::Drawing::Point(72, 511);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(228, 24);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->Text = L"MOSTRAR_RECORRIDOS";

			// mostrarContenido
			this->mostrarContenido->Location = System::Drawing::Point(39, 179);
			this->mostrarContenido->Name = L"mostrarContenido";
			this->mostrarContenido->Size = System::Drawing::Size(881, 255);
			this->mostrarContenido->TabIndex = 6;
			this->mostrarContenido->Text = L"";

			// btnVOLVER
			this->btnVOLVER->Location = System::Drawing::Point(72, 601);
			this->btnVOLVER->Name = L"btnVOLVER";
			this->btnVOLVER->Size = botonTamano;
			this->btnVOLVER->BackColor = System::Drawing::Color::Red;
			this->btnVOLVER->Text = L"VOLVER";

			// txtNombre
			this->txtNombre->Location = System::Drawing::Point(386, 455);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(534, 22);
			this->txtNombre->TabIndex = 8;
			this->txtNombre->Text = L"Nombre";

			// txtID
			this->txtID->Location = System::Drawing::Point(386, 483);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(327, 22);
			this->txtID->TabIndex = 9;
			this->txtID->Text = L"Indetificación_ID";

			// txtEdad
			this->txtEdad->Location = System::Drawing::Point(386, 511);
			this->txtEdad->Name = L"txtEdad";
			this->txtEdad->Size = System::Drawing::Size(100, 22);
			this->txtEdad->TabIndex = 10;
			this->txtEdad->Text = L"Edad";

			// txtSaldo
			this->txtSaldo->Location = System::Drawing::Point(386, 545);
			this->txtSaldo->Name = L"txtSaldo";
			this->txtSaldo->Size = System::Drawing::Size(327, 22);
			this->txtSaldo->TabIndex = 11;
			this->txtSaldo->Text = L"SaldoTarjeta";

			// Ver_Recorrido
			this->Ver_Recorrido->Location = System::Drawing::Point(72, 558);
			this->Ver_Recorrido->Name = L"Ver_Recorrido";
			this->Ver_Recorrido->Size = botonTamano;
			this->Ver_Recorrido->BackColor = botonColor;
			this->Ver_Recorrido->Text = L"Ver Recorrido";

			// Usuarios
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(977, 646);
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->Controls->Add(this->Ver_Recorrido);
			this->Controls->Add(this->txtSaldo);
			this->Controls->Add(this->txtEdad);
			this->Controls->Add(this->txtID);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->btnVOLVER);
			this->Controls->Add(this->mostrarContenido);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->btnMostrarUsuariosAlfabeticamente);
			this->Controls->Add(this->btnBUSCAR_USUARIO_ID);
			this->Controls->Add(this->btnEliminarUsuario);
			this->Controls->Add(this->btnInsertarUsuario);
			this->Controls->Add(this->txtMENU_USUARIOS);
			this->Name = L"Usuarios";
			this->Text = L"Usuarios";
			this->Load += gcnew System::EventHandler(this, &Usuarios::Usuarios_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnEliminarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContenido->Clear();

	try {
		int id = Convert::ToInt32(txtID->Text);
		Usuario* u = arbol->buscarUsuario(id);

		if (u) {
			arbol->eliminarUsuario(id);
			mostrarContenido->AppendText("Usuario eliminado correctamente.\n");
			arbol->guardarEnArchivo("usuarios.txt");
			System::String^ reporte = gcnew System::String(arbol->obtenerUsuariosOrdenadosPorNombre().c_str());
			System::IO::File::WriteAllText("reportes.txt", reporte);
		}
		else {
			mostrarContenido->AppendText("No se encontró ningún usuario con ese ID.\n");
		}
	}
	catch (...) {
		mostrarContenido->AppendText("Error: ID inválido.\n");
	}
}
private: System::Void btnBUSCAR_USUARIO_ID_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContenido->Clear();

	try {
		int id = Convert::ToInt32(txtID->Text);
		Usuario* u = arbol->buscarUsuario(id);

		if (u) {
			std::stringstream ss;
			ss << u->id << " - " << u->nombre << " - " << u->edad << " años - " << u->saldo << " colones.\n";
			mostrarContenido->AppendText(gcnew System::String(ss.str().c_str()));
		}
		else {
			mostrarContenido->AppendText("Usuario no encontrado.\n");
		}
	}
	catch (...) {
		mostrarContenido->AppendText("Error: ID inválido.\n");
	}
}
private: System::Void btnInsertarUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContenido->Clear();

	try {
		int id = Convert::ToInt32(txtID->Text);
		System::String^ nombre = txtNombre->Text;
		int edad = Convert::ToInt32(txtEdad->Text);
		float saldo = Convert::ToSingle(txtSaldo->Text);

		std::string nombreStr = msclr::interop::marshal_as<std::string>(nombre);
		arbol->insertarUsuario(id, nombreStr, edad, saldo);

		mostrarContenido->AppendText("Usuario insertado correctamente.\n");
		arbol->guardarEnArchivo("usuarios.txt");
		System::String^ reporte = gcnew System::String(arbol->obtenerUsuariosOrdenadosPorNombre().c_str());
		System::IO::File::WriteAllText("reportes.txt", reporte);
	}
	catch (...) {
		mostrarContenido->AppendText("Error: verifique que los campos sean válidos.\n");
	}
}
private: System::Void btnMostrarUsuariosAlfabeticamente_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContenido->Clear();
	System::String^ texto = gcnew System::String(arbol->obtenerUsuariosOrdenadosPorNombre().c_str());
	mostrarContenido->AppendText(texto);
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Ver_Recorrido_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContenido->Clear();

	if (comboBox1->SelectedItem == nullptr) {
		mostrarContenido->AppendText("Seleccione un tipo de recorrido.\n");
		return;
	}

	System::String^ tipo = comboBox1->SelectedItem->ToString();
	std::string resultado;

	if (tipo == "inOrden") {
		resultado = arbol->obtenerRecorridoInOrden();
	}
	else if (tipo == "preOrden") {
		resultado = arbol->obtenerRecorridoPreOrden();
	}
	else if (tipo == "postOrden") {
		resultado = arbol->obtenerRecorridoPostOrden();
	}
	else {
		resultado = "Tipo de recorrido inválido.";
	}
	mostrarContenido->AppendText(gcnew System::String(resultado.c_str()));
}
private: System::Void btnVOLVER_Click(System::Object^ sender, System::EventArgs^ e) {
	/*this->Hide();
	randallC::InterfazGrafica^ menu = gcnew randallC::InterfazGrafica();
	menu->ShowDialog();
	this->Show();*/
	this->Close();
}
private: System::Void txtNombre_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtEdad_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtSaldo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Usuarios_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}