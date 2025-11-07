#pragma once
#include "GrafoRutas.h"
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
	/// Resumen de Rutas
	/// </summary>
	public ref class Rutas : public System::Windows::Forms::Form
	{
	public:
		Rutas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			grafo = new GrafoRutas();
			grafo->cargarDesdeArchivo("rutas.txt");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Rutas()
		{
			if (components)
			{
				delete components;
			}
			if (grafo) {
				delete grafo;
				grafo = nullptr;
			}
		}
	private: System::Windows::Forms::Label^ txtTITULO_RUTAS;
	protected:
	private: System::Windows::Forms::Button^ btnDFS;
	private: System::Windows::Forms::Button^ btnBFS;
	private: System::Windows::Forms::Button^ btnINFO;
	private: System::Windows::Forms::TextBox^ txtESTACION_DESTINO;
	private: System::Windows::Forms::TextBox^ txtESTACION_ORIGEN;
	private: System::Windows::Forms::Button^ btnPRIM;
	private: System::Windows::Forms::Button^ btnVOLVER;
	private: System::Windows::Forms::RichTextBox^ mostrarContedinoRUTAS;
	private: System::Windows::Forms::Button^ btnVerMasCorta;
	private: System::Windows::Forms::Button^ btnVerMatrizAdyacencia;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		GrafoRutas* grafo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtTITULO_RUTAS = (gcnew System::Windows::Forms::Label());
			this->btnDFS = (gcnew System::Windows::Forms::Button());
			this->btnBFS = (gcnew System::Windows::Forms::Button());
			this->btnINFO = (gcnew System::Windows::Forms::Button());
			this->txtESTACION_DESTINO = (gcnew System::Windows::Forms::TextBox());
			this->txtESTACION_ORIGEN = (gcnew System::Windows::Forms::TextBox());
			this->btnPRIM = (gcnew System::Windows::Forms::Button());
			this->btnVOLVER = (gcnew System::Windows::Forms::Button());
			this->mostrarContedinoRUTAS = (gcnew System::Windows::Forms::RichTextBox());
			this->mostrarContedinoRUTAS->ReadOnly = true;
			this->btnVerMasCorta = (gcnew System::Windows::Forms::Button());
			this->btnVerMatrizAdyacencia = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// txtTITULO_RUTAS
			this->txtTITULO_RUTAS->AutoSize = true;
			this->txtTITULO_RUTAS->BackColor = System::Drawing::Color::White;
			this->txtTITULO_RUTAS->Location = System::Drawing::Point(300, 30);
			this->txtTITULO_RUTAS->Name = L"txtTITULO_RUTAS";
			this->txtTITULO_RUTAS->Size = System::Drawing::Size(247, 16);
			this->txtTITULO_RUTAS->TabIndex = 33;
			this->txtTITULO_RUTAS->Text = L"MENU DE RUTAS DE TRANSPORTES";
			this->txtTITULO_RUTAS->Click += gcnew System::EventHandler(this, &Rutas::txtTITULO_RUTAS_Click);

			// btnBFS
			this->btnBFS->Location = System::Drawing::Point(50, 100);
			this->btnBFS->Name = L"btnBFS";
			this->btnBFS->Size = System::Drawing::Size(220, 40);
			this->btnBFS->TabIndex = 31;
			this->btnBFS->Text = L"DESDE ESTACIÓN BFS";
			this->btnBFS->UseVisualStyleBackColor = true;
			this->btnBFS->Click += gcnew System::EventHandler(this, &Rutas::btnBFS_Click);

			// btnDFS
			this->btnDFS->Location = System::Drawing::Point(300, 100);
			this->btnDFS->Name = L"btnDFS";
			this->btnDFS->Size = System::Drawing::Size(220, 40);
			this->btnDFS->TabIndex = 32;
			this->btnDFS->Text = L"CAMINOS DFS";
			this->btnDFS->UseVisualStyleBackColor = true;
			this->btnDFS->Click += gcnew System::EventHandler(this, &Rutas::btnDFS_Click);

			// btnVerMasCorta
			this->btnVerMasCorta->Location = System::Drawing::Point(550, 100);
			this->btnVerMasCorta->Name = L"btnVerMasCorta";
			this->btnVerMasCorta->Size = System::Drawing::Size(220, 40);
			this->btnVerMasCorta->TabIndex = 24;
			this->btnVerMasCorta->Text = L"RUTA MÁS CORTA";
			this->btnVerMasCorta->UseVisualStyleBackColor = true;
			this->btnVerMasCorta->Click += gcnew System::EventHandler(this, &Rutas::btnVerMasCorta_Click);

			// mostrarContedinoRUTAS
			this->mostrarContedinoRUTAS->Location = System::Drawing::Point(36, 160);
			this->mostrarContedinoRUTAS->Name = L"mostrarContedinoRUTAS";
			this->mostrarContedinoRUTAS->Size = System::Drawing::Size(811, 257);
			this->mostrarContedinoRUTAS->TabIndex = 25;
			this->mostrarContedinoRUTAS->Text = L"";
			this->mostrarContedinoRUTAS->TextChanged += gcnew System::EventHandler(this, &Rutas::mostrarContedinoRUTAS_TextChanged);

			// btnVerMatrizAdyacencia
			this->btnVerMatrizAdyacencia->Location = System::Drawing::Point(36, 440);
			this->btnVerMatrizAdyacencia->Name = L"btnVerMatrizAdyacencia";
			this->btnVerMatrizAdyacencia->Size = System::Drawing::Size(220, 40);
			this->btnVerMatrizAdyacencia->TabIndex = 23;
			this->btnVerMatrizAdyacencia->Text = L"MATRIZ ADYACENCIA";
			this->btnVerMatrizAdyacencia->UseVisualStyleBackColor = true;
			this->btnVerMatrizAdyacencia->Click += gcnew System::EventHandler(this, &Rutas::btnVerMatrizAdyacencia_Click);

			// txtESTACION_ORIGEN
			this->txtESTACION_ORIGEN->Location = System::Drawing::Point(282, 440);
			this->txtESTACION_ORIGEN->Name = L"txtESTACION_ORIGEN";
			this->txtESTACION_ORIGEN->Size = System::Drawing::Size(262, 22);
			this->txtESTACION_ORIGEN->TabIndex = 28;
			this->txtESTACION_ORIGEN->Text = L"ORIGEN";
			this->txtESTACION_ORIGEN->TextChanged += gcnew System::EventHandler(this, &Rutas::txtESTACION_ORIGEN_TextChanged);

			// txtESTACION_DESTINO
			this->txtESTACION_DESTINO->Location = System::Drawing::Point(565, 440);
			this->txtESTACION_DESTINO->Name = L"txtESTACION_DESTINO";
			this->txtESTACION_DESTINO->Size = System::Drawing::Size(282, 22);
			this->txtESTACION_DESTINO->TabIndex = 29;
			this->txtESTACION_DESTINO->Text = L"DESTINO";
			this->txtESTACION_DESTINO->TextChanged += gcnew System::EventHandler(this, &Rutas::txtESTACION_DESTINO_TextChanged);

			// btnPRIM
			this->btnPRIM->Location = System::Drawing::Point(32, 500);
			this->btnPRIM->Name = L"btnPRIM";
			this->btnPRIM->Size = System::Drawing::Size(220, 40);
			this->btnPRIM->TabIndex = 27;
			this->btnPRIM->Text = L"RED MÍNIMA (PRIM)";
			this->btnPRIM->UseVisualStyleBackColor = true;
			this->btnPRIM->Click += gcnew System::EventHandler(this, &Rutas::btnPRIM_Click);

			// btnINFO
			this->btnINFO->Location = System::Drawing::Point(280, 500);
			this->btnINFO->Name = L"btnINFO";
			this->btnINFO->Size = System::Drawing::Size(220, 40);
			this->btnINFO->TabIndex = 30;
			this->btnINFO->Text = L"USO / RUTAS";
			this->btnINFO->UseVisualStyleBackColor = true;
			this->btnINFO->Click += gcnew System::EventHandler(this, &Rutas::btnINFO_Click);

			// btnVOLVER
			this->btnVOLVER->BackColor = System::Drawing::Color::Red;
			this->btnVOLVER->ForeColor = System::Drawing::Color::White;
			this->btnVOLVER->Location = System::Drawing::Point(540, 500);
			this->btnVOLVER->Name = L"btnVOLVER";
			this->btnVOLVER->Size = System::Drawing::Size(220, 40);
			this->btnVOLVER->TabIndex = 26;
			this->btnVOLVER->Text = L"VOLVER";
			this->btnVOLVER->UseVisualStyleBackColor = false;
			this->btnVOLVER->Click += gcnew System::EventHandler(this, &Rutas::btnVOLVER_Click);

			// Rutas
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 579);
			this->Controls->Add(this->txtTITULO_RUTAS);
			this->Controls->Add(this->btnDFS);
			this->Controls->Add(this->btnBFS);
			this->Controls->Add(this->btnINFO);
			this->Controls->Add(this->txtESTACION_DESTINO);
			this->Controls->Add(this->txtESTACION_ORIGEN);
			this->Controls->Add(this->btnPRIM);
			this->Controls->Add(this->btnVOLVER);
			this->Controls->Add(this->mostrarContedinoRUTAS);
			this->Controls->Add(this->btnVerMasCorta);
			this->Controls->Add(this->btnVerMatrizAdyacencia);
			this->Name = L"Rutas";
			this->Text = L"Rutas";
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ResumeLayout(false);
			this->PerformLayout();
}
#pragma endregion
	private: System::Void txtTITULO_RUTAS_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnBFS_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	String^ origen = txtESTACION_ORIGEN->Text;

	if (origen == "") {
		mostrarContedinoRUTAS->AppendText("Ingrese estación de origen.\n");
		return;
	}
	if (!grafo->existeEstacion(msclr::interop::marshal_as<std::string>(origen))) {
		mostrarContedinoRUTAS->AppendText("Estación no válida.\n");
		return;
	}

	std::string resultado = grafo->bfs(msclr::interop::marshal_as<std::string>(origen));
	mostrarContedinoRUTAS->AppendText(gcnew String(resultado.c_str()));
}
private: System::Void btnDFS_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	String^ origen = txtESTACION_ORIGEN->Text;

	if (origen == "") {
		mostrarContedinoRUTAS->AppendText("Ingrese estación de origen.\n");
		return;
	}
	if (!grafo->existeEstacion(msclr::interop::marshal_as<std::string>(origen))) {
		mostrarContedinoRUTAS->AppendText("Estación no válida.\n");
		return;
	}

	std::string resultado = grafo->dfs(msclr::interop::marshal_as<std::string>(origen));
	mostrarContedinoRUTAS->AppendText(gcnew String(resultado.c_str()));
}
private: System::Void btnVerMasCorta_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	String^ origen = txtESTACION_ORIGEN->Text;
	String^ destino = txtESTACION_DESTINO->Text;

	if (origen == "" || destino == "") {
		mostrarContedinoRUTAS->AppendText("Ingrese origen y destino.\n");
		return;
	}
	std::string o = msclr::interop::marshal_as<std::string>(origen);
	std::string d = msclr::interop::marshal_as<std::string>(destino);

	if (!grafo->existeEstacion(o) || !grafo->existeEstacion(d)) {
		mostrarContedinoRUTAS->AppendText("Estaciones no válidas.\n");
		return;
	}

	std::string resultado = grafo->dijkstra(o, d);
	mostrarContedinoRUTAS->AppendText(gcnew String(resultado.c_str()));
}
private: System::Void mostrarContedinoRUTAS_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnVerMatrizAdyacencia_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	std::string resultado = grafo->mostrarMatriz();
	mostrarContedinoRUTAS->AppendText(gcnew String(resultado.c_str()));
}
private: System::Void btnPRIM_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	std::string resultado = grafo->prim();
	mostrarContedinoRUTAS->AppendText(gcnew String(resultado.c_str()));
}
private: System::Void btnINFO_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	mostrarContedinoRUTAS->AppendText(
		"Cómo usar esta sección de rutas:\n\n" +
		"Ver matriz y Prim: solo presione el botón\n" +
		"Anchura (BFS) y Profundidad (DFS): ingrese estación de origen\n" +
		"Ruta más corta (Dijkstra): ingrese estación de origen y destino\n\n" +
		"El resultado se mostrará aquí mismo.\n" +
		"Asegúrese de que las estaciones existan en el sistema.\n"
	);
	if (grafo != nullptr) {
		System::String^ estacionesTexto = gcnew System::String(grafo->obtenerEstacionesComoLinea().c_str());
		mostrarContedinoRUTAS->AppendText("\nEstaciones disponibles: " + estacionesTexto + "\n");
	}
	else {
		mostrarContedinoRUTAS->AppendText("No hay estaciones cargadas actualmente.\n");
	}
}
private: System::Void btnVOLVER_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void txtESTACION_ORIGEN_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtESTACION_DESTINO_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
