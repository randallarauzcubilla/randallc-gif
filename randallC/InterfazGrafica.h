#pragma once

namespace randallC {
	ref class Usuarios;
	ref class Rutas;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InterfazGrafica
	/// </summary>
	public ref class InterfazGrafica : public System::Windows::Forms::Form
	{
	public:
		InterfazGrafica(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~InterfazGrafica()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ txtTitulo;
	protected:
	private: System::Windows::Forms::Button^ btnMenuUsuarios;

	private: System::Windows::Forms::Button^ btnGenerarReporte;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Label^ txtNombreDesarrollador;
	private: System::Windows::Forms::RichTextBox^ mostrarREPORTE;
	private: System::Windows::Forms::Button^ btnMenuRutas;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtTitulo = (gcnew System::Windows::Forms::Label());
			this->btnMenuUsuarios = (gcnew System::Windows::Forms::Button());
			this->btnGenerarReporte = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->txtNombreDesarrollador = (gcnew System::Windows::Forms::Label());
			this->mostrarREPORTE = (gcnew System::Windows::Forms::RichTextBox());
			this->mostrarREPORTE->ReadOnly = true;
			this->btnMenuRutas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtTitulo
			// 
			this->txtTitulo->AutoSize = true;
			this->txtTitulo->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->txtTitulo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->txtTitulo->Location = System::Drawing::Point(35, 48);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->Size = System::Drawing::Size(235, 16);
			this->txtTitulo->TabIndex = 0;
			this->txtTitulo->Text = L"SISTEMA RUTAS DE TRANSPORTE";
			this->txtTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->txtTitulo->Click += gcnew System::EventHandler(this, &InterfazGrafica::txtTitulo_Click);
			// 
			// btnMenuUsuarios
			// 
			this->btnMenuUsuarios->BackColor = System::Drawing::SystemColors::Control;
			this->btnMenuUsuarios->Location = System::Drawing::Point(72, 133);
			this->btnMenuUsuarios->Name = L"btnMenuUsuarios";
			this->btnMenuUsuarios->Size = System::Drawing::Size(167, 58);
			this->btnMenuUsuarios->TabIndex = 1;
			this->btnMenuUsuarios->Text = L"Menu Usuarios";
			this->btnMenuUsuarios->UseVisualStyleBackColor = false;
			this->btnMenuUsuarios->Click += gcnew System::EventHandler(this, &InterfazGrafica::btnMenuUsuarios_Click);
			// 
			// btnGenerarReporte
			// 
			this->btnGenerarReporte->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btnGenerarReporte->Location = System::Drawing::Point(72, 333);
			this->btnGenerarReporte->Name = L"btnGenerarReporte";
			this->btnGenerarReporte->Size = System::Drawing::Size(167, 61);
			this->btnGenerarReporte->TabIndex = 3;
			this->btnGenerarReporte->Text = L"Generar Reporte";
			this->btnGenerarReporte->UseVisualStyleBackColor = false;
			this->btnGenerarReporte->Click += gcnew System::EventHandler(this, &InterfazGrafica::btnGenerarReporte_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Firebrick;
			this->btnSalir->Location = System::Drawing::Point(72, 454);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(167, 46);
			this->btnSalir->TabIndex = 4;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &InterfazGrafica::btnSalir_Click);
			// 
			// txtNombreDesarrollador
			// 
			this->txtNombreDesarrollador->AutoSize = true;
			this->txtNombreDesarrollador->Location = System::Drawing::Point(37, 541);
			this->txtNombreDesarrollador->Name = L"txtNombreDesarrollador";
			this->txtNombreDesarrollador->Size = System::Drawing::Size(75, 16);
			this->txtNombreDesarrollador->TabIndex = 5;
			this->txtNombreDesarrollador->Text = L"Randall AC";
			// 
			// mostrarREPORTE
			// 
			this->mostrarREPORTE->Location = System::Drawing::Point(289, 40);
			this->mostrarREPORTE->Name = L"mostrarREPORTE";
			this->mostrarREPORTE->Size = System::Drawing::Size(510, 517);
			this->mostrarREPORTE->TabIndex = 6;
			this->mostrarREPORTE->Text = L"";
			this->mostrarREPORTE->TextChanged += gcnew System::EventHandler(this, &InterfazGrafica::mostrarREPORTE_TextChanged);
			// 
			// btnMenuRutas
			// 
			this->btnMenuRutas->BackColor = System::Drawing::SystemColors::Control;
			this->btnMenuRutas->Location = System::Drawing::Point(72, 237);
			this->btnMenuRutas->Name = L"btnMenuRutas";
			this->btnMenuRutas->Size = System::Drawing::Size(167, 57);
			this->btnMenuRutas->TabIndex = 7;
			this->btnMenuRutas->Text = L"Menu Rutas";
			this->btnMenuRutas->UseVisualStyleBackColor = false;
			this->btnMenuRutas->Click += gcnew System::EventHandler(this, &InterfazGrafica::btnMenuRutas_Click);
			// 
			// InterfazGrafica
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->ClientSize = System::Drawing::Size(811, 584);
			this->Controls->Add(this->btnMenuRutas);
			this->Controls->Add(this->mostrarREPORTE);
			this->Controls->Add(this->txtNombreDesarrollador);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->txtTitulo);
			this->Controls->Add(this->btnGenerarReporte);
			this->Controls->Add(this->btnMenuUsuarios);
			this->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Name = L"InterfazGrafica";
			this->Text = L"InterfazGrafica";
			this->Load += gcnew System::EventHandler(this, &InterfazGrafica::InterfazGrafica_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void InterfazGrafica_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void btnGenerarReporte_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		System::String^ rutaArchivo = "reportes.txt";
		if (System::IO::File::Exists(rutaArchivo)) {
			System::String^ contenido = System::IO::File::ReadAllText(rutaArchivo);
			mostrarREPORTE->Text = contenido;
		}
		else {
			mostrarREPORTE->Text = "No se encontró el archivo de reporte.";
		}
	}
	catch (System::Exception^ ex) {
		mostrarREPORTE->Text = "Error al cargar el reporte: " + ex->Message;
	}
}
private: System::Void btnMenuUsuarios_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnMenuRutas_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void txtTitulo_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void mostrarREPORTE_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
