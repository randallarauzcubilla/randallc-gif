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

	public ref class Usuarios : public System::Windows::Forms::Form
	{
	public:
		Usuarios(void)
		{
			InitializeComponent();
			arbol = new ArbolUsuarios();
			arbol->cargarDesdeArchivo("usuarios.txt");
			Usuario* nodo = arbol->getRaiz();
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
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Panel^ panelArbolUsuarios;
		   ArbolUsuarios* arbol;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txtMENU_USUARIOS = (gcnew System::Windows::Forms::Label());
			this->btnInsertarUsuario = (gcnew System::Windows::Forms::Button());
			this->btnEliminarUsuario = (gcnew System::Windows::Forms::Button());
			this->btnBUSCAR_USUARIO_ID = (gcnew System::Windows::Forms::Button());
			this->btnMostrarUsuariosAlfabeticamente = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->mostrarContenido = (gcnew System::Windows::Forms::RichTextBox());
			this->btnVOLVER = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtEdad = (gcnew System::Windows::Forms::TextBox());
			this->txtSaldo = (gcnew System::Windows::Forms::TextBox());
			this->Ver_Recorrido = (gcnew System::Windows::Forms::Button());
			this->panelArbolUsuarios = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// txtMENU_USUARIOS
			// 
			this->txtMENU_USUARIOS->AutoSize = true;
			this->txtMENU_USUARIOS->BackColor = System::Drawing::Color::White;
			this->txtMENU_USUARIOS->Location = System::Drawing::Point(308, 62);
			this->txtMENU_USUARIOS->Name = L"txtMENU_USUARIOS";
			this->txtMENU_USUARIOS->Size = System::Drawing::Size(142, 16);
			this->txtMENU_USUARIOS->TabIndex = 0;
			this->txtMENU_USUARIOS->Text = L"MENU DE USUARIOS";
			// 
			// btnInsertarUsuario
			// 
			this->btnInsertarUsuario->BackColor = System::Drawing::Color::White;
			this->btnInsertarUsuario->Location = System::Drawing::Point(61, 124);
			this->btnInsertarUsuario->Name = L"btnInsertarUsuario";
			this->btnInsertarUsuario->Size = System::Drawing::Size(175, 36);
			this->btnInsertarUsuario->TabIndex = 16;
			this->btnInsertarUsuario->Text = L"INSERTAR_USUARIO";
			this->btnInsertarUsuario->UseVisualStyleBackColor = false;
			this->btnInsertarUsuario->Click += gcnew System::EventHandler(this, &Usuarios::btnInsertarUsuario_Click);
			// 
			// btnEliminarUsuario
			// 
			this->btnEliminarUsuario->BackColor = System::Drawing::Color::White;
			this->btnEliminarUsuario->Location = System::Drawing::Point(532, 124);
			this->btnEliminarUsuario->Name = L"btnEliminarUsuario";
			this->btnEliminarUsuario->Size = System::Drawing::Size(175, 36);
			this->btnEliminarUsuario->TabIndex = 15;
			this->btnEliminarUsuario->Text = L"ELIMINAR_USUARIO";
			this->btnEliminarUsuario->UseVisualStyleBackColor = false;
			this->btnEliminarUsuario->Click += gcnew System::EventHandler(this, &Usuarios::btnEliminarUsuario_Click);
			// 
			// btnBUSCAR_USUARIO_ID
			// 
			this->btnBUSCAR_USUARIO_ID->BackColor = System::Drawing::Color::White;
			this->btnBUSCAR_USUARIO_ID->Location = System::Drawing::Point(291, 124);
			this->btnBUSCAR_USUARIO_ID->Name = L"btnBUSCAR_USUARIO_ID";
			this->btnBUSCAR_USUARIO_ID->Size = System::Drawing::Size(175, 36);
			this->btnBUSCAR_USUARIO_ID->TabIndex = 14;
			this->btnBUSCAR_USUARIO_ID->Text = L"BUSCAR_USUARIO_ID";
			this->btnBUSCAR_USUARIO_ID->UseVisualStyleBackColor = false;
			this->btnBUSCAR_USUARIO_ID->Click += gcnew System::EventHandler(this, &Usuarios::btnBUSCAR_USUARIO_ID_Click);
			// 
			// btnMostrarUsuariosAlfabeticamente
			// 
			this->btnMostrarUsuariosAlfabeticamente->BackColor = System::Drawing::Color::White;
			this->btnMostrarUsuariosAlfabeticamente->Location = System::Drawing::Point(39, 448);
			this->btnMostrarUsuariosAlfabeticamente->Name = L"btnMostrarUsuariosAlfabeticamente";
			this->btnMostrarUsuariosAlfabeticamente->Size = System::Drawing::Size(175, 36);
			this->btnMostrarUsuariosAlfabeticamente->TabIndex = 13;
			this->btnMostrarUsuariosAlfabeticamente->Text = L"MOSTRAR_ALFABETICAMENTE";
			this->btnMostrarUsuariosAlfabeticamente->UseVisualStyleBackColor = false;
			this->btnMostrarUsuariosAlfabeticamente->Click += gcnew System::EventHandler(this, &Usuarios::btnMostrarUsuariosAlfabeticamente_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"inOrden", L"preOrden", L"postOrden" });
			this->comboBox1->Location = System::Drawing::Point(39, 509);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(197, 24);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->Text = L"MOSTRAR_RECORRIDOS";
			// 
			// mostrarContenido
			// 
			this->mostrarContenido->Location = System::Drawing::Point(18, 187);
			this->mostrarContenido->Name = L"mostrarContenido";
			this->mostrarContenido->ReadOnly = true;
			this->mostrarContenido->Size = System::Drawing::Size(721, 255);
			this->mostrarContenido->TabIndex = 6;
			this->mostrarContenido->Text = L"";
			// 
			// btnVOLVER
			// 
			this->btnVOLVER->BackColor = System::Drawing::Color::Red;
			this->btnVOLVER->Location = System::Drawing::Point(39, 626);
			this->btnVOLVER->Name = L"btnVOLVER";
			this->btnVOLVER->Size = System::Drawing::Size(175, 36);
			this->btnVOLVER->TabIndex = 12;
			this->btnVOLVER->Text = L"VOLVER";
			this->btnVOLVER->UseVisualStyleBackColor = false;
			this->btnVOLVER->Click += gcnew System::EventHandler(this, &Usuarios::btnVOLVER_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(273, 455);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(434, 22);
			this->txtNombre->TabIndex = 8;
			this->txtNombre->Text = L"Nombre";
			// 
			// txtID
			// 
			this->txtID->Location = System::Drawing::Point(273, 499);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(327, 22);
			this->txtID->TabIndex = 9;
			this->txtID->Text = L"Indetificación_ID";
			// 
			// txtEdad
			// 
			this->txtEdad->Location = System::Drawing::Point(273, 545);
			this->txtEdad->Name = L"txtEdad";
			this->txtEdad->Size = System::Drawing::Size(100, 22);
			this->txtEdad->TabIndex = 10;
			this->txtEdad->Text = L"Edad";
			// 
			// txtSaldo
			// 
			this->txtSaldo->Location = System::Drawing::Point(273, 586);
			this->txtSaldo->Name = L"txtSaldo";
			this->txtSaldo->Size = System::Drawing::Size(327, 22);
			this->txtSaldo->TabIndex = 11;
			this->txtSaldo->Text = L"SaldoTarjeta";
			// 
			// Ver_Recorrido
			// 
			this->Ver_Recorrido->BackColor = System::Drawing::Color::White;
			this->Ver_Recorrido->Location = System::Drawing::Point(39, 562);
			this->Ver_Recorrido->Name = L"Ver_Recorrido";
			this->Ver_Recorrido->Size = System::Drawing::Size(175, 36);
			this->Ver_Recorrido->TabIndex = 0;
			this->Ver_Recorrido->Text = L"Ver Recorrido";
			this->Ver_Recorrido->UseVisualStyleBackColor = false;
			this->Ver_Recorrido->Click += gcnew System::EventHandler(this, &Usuarios::Ver_Recorrido_Click);
			// 
			// panelArbolUsuarios
			// 
			this->panelArbolUsuarios->BackColor = System::Drawing::SystemColors::Control;
			this->panelArbolUsuarios->Location = System::Drawing::Point(766, 12);
			this->panelArbolUsuarios->Name = L"panelArbolUsuarios";
			this->panelArbolUsuarios->Size = System::Drawing::Size(1033, 870);
			this->panelArbolUsuarios->TabIndex = 17;
			this->panelArbolUsuarios->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Usuarios::panelArbolUsuarios_Paint);
			// 
			// Usuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(1766, 809);
			this->Controls->Add(this->panelArbolUsuarios);
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
			panelArbolUsuarios->Invalidate();
			txtID->Text = "IngreseID";
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
			txtID->Text = "IngreseID";
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

		// Intentar insertar y verificar éxito
		bool exito = arbol->insertarUsuario(id, nombreStr, edad, saldo);

		if (exito) {
			mostrarContenido->AppendText("Usuario insertado correctamente.\n");
			arbol->guardarEnArchivo("usuarios.txt");
			System::String^ reporte = gcnew System::String(arbol->obtenerUsuariosOrdenadosPorNombre().c_str());
			System::IO::File::WriteAllText("reportes.txt", reporte);
			// Actualizar los campos de entrada
			txtID->Text = "IngreseID";
			txtNombre->Text = "IngreseNombre";
			txtEdad->Text = "IngreseEdad";
			txtSaldo->Text = "IngreseSaldo";
			panelArbolUsuarios->Invalidate();
		}
		else {
			mostrarContenido->AppendText("Error al insertar usuario: ID duplicado, edad o saldo inválidos.\n");
		}
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
private: void dibujarNodo(Graphics^ g, Usuario* nodo, int x, int y, int xOffset)
{
	if (nodo == nullptr) return;

	// Dibujar el nodo
	System::Drawing::Rectangle rect(x - 25, y - 15, 50, 30);
	g->DrawRectangle(Pens::Black, rect);

	// Mostrar datos del usuario
	std::stringstream ss;
	ss << nodo->id << "\n" << nodo->nombre;
	String^ texto = gcnew String(ss.str().c_str());
	g->DrawString(
		texto,
		gcnew System::Drawing::Font("Arial", 8),
		System::Drawing::Brushes::Black,
		static_cast<float>(x - 20),
		static_cast<float>(y - 10)
	);

	// Dibujar líneas hacia los hijos y sus nodos recursivamente
	if (nodo->izq != nullptr)
	{
		g->DrawLine(Pens::Black, x, y + 15, x - xOffset, y + 75 - 15);
		dibujarNodo(g, nodo->izq, x - xOffset, y + 75, xOffset / 2);
	}
	if (nodo->der != nullptr)
	{
		g->DrawLine(Pens::Black, x, y + 15, x + xOffset, y + 75 - 15);
		dibujarNodo(g, nodo->der, x + xOffset, y + 75, xOffset / 2);
	}
}
private: System::Void panelArbolUsuarios_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;

	int panelCenter = panelArbolUsuarios->Width / 2;
	dibujarNodo(g, arbol->getRaiz(), panelCenter, 50, panelArbolUsuarios->Width / 4);
}
};
}