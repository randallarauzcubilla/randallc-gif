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

	public ref class Rutas : public System::Windows::Forms::Form
	{
	public:
		Rutas(void)
		{
			InitializeComponent();
			grafo = new GrafoRutas();
			grafo->cargarDesdeArchivo("rutas.txt");
		}

	protected:
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
	private: System::Windows::Forms::Button^ btnKRUSKAL;
	private: System::Windows::Forms::Button^ btnVOLVER;
	private: System::Windows::Forms::RichTextBox^ mostrarContedinoRUTAS;
	private: System::Windows::Forms::Button^ btnVerMasCorta;
	private: System::Windows::Forms::Button^ btnVerMatrizAdyacencia;

	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Panel^ panelGrafoRutas;

		   GrafoRutas* grafo;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txtTITULO_RUTAS = (gcnew System::Windows::Forms::Label());
			this->btnDFS = (gcnew System::Windows::Forms::Button());
			this->btnBFS = (gcnew System::Windows::Forms::Button());
			this->btnINFO = (gcnew System::Windows::Forms::Button());
			this->txtESTACION_DESTINO = (gcnew System::Windows::Forms::TextBox());
			this->txtESTACION_ORIGEN = (gcnew System::Windows::Forms::TextBox());
			this->btnKRUSKAL = (gcnew System::Windows::Forms::Button());
			this->btnVOLVER = (gcnew System::Windows::Forms::Button());
			this->mostrarContedinoRUTAS = (gcnew System::Windows::Forms::RichTextBox());
			this->btnVerMasCorta = (gcnew System::Windows::Forms::Button());
			this->btnVerMatrizAdyacencia = (gcnew System::Windows::Forms::Button());
			this->panelGrafoRutas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// txtTITULO_RUTAS
			// 
			this->txtTITULO_RUTAS->AutoSize = true;
			this->txtTITULO_RUTAS->BackColor = System::Drawing::Color::White;
			this->txtTITULO_RUTAS->Location = System::Drawing::Point(300, 30);
			this->txtTITULO_RUTAS->Name = L"txtTITULO_RUTAS";
			this->txtTITULO_RUTAS->Size = System::Drawing::Size(247, 16);
			this->txtTITULO_RUTAS->TabIndex = 33;
			this->txtTITULO_RUTAS->Text = L"MENU DE RUTAS DE TRANSPORTES";
			this->txtTITULO_RUTAS->Click += gcnew System::EventHandler(this, &Rutas::txtTITULO_RUTAS_Click);
			// 
			// btnDFS
			// 
			this->btnDFS->Location = System::Drawing::Point(300, 100);
			this->btnDFS->Name = L"btnDFS";
			this->btnDFS->Size = System::Drawing::Size(220, 40);
			this->btnDFS->TabIndex = 32;
			this->btnDFS->Text = L"CAMINOS DFS";
			this->btnDFS->UseVisualStyleBackColor = true;
			this->btnDFS->Click += gcnew System::EventHandler(this, &Rutas::btnDFS_Click);
			// 
			// btnBFS
			// 
			this->btnBFS->Location = System::Drawing::Point(50, 100);
			this->btnBFS->Name = L"btnBFS";
			this->btnBFS->Size = System::Drawing::Size(220, 40);
			this->btnBFS->TabIndex = 31;
			this->btnBFS->Text = L"DESDE ESTACIÓN BFS";
			this->btnBFS->UseVisualStyleBackColor = true;
			this->btnBFS->Click += gcnew System::EventHandler(this, &Rutas::btnBFS_Click);
			// 
			// btnINFO
			// 
			this->btnINFO->Location = System::Drawing::Point(280, 604);
			this->btnINFO->Name = L"btnINFO";
			this->btnINFO->Size = System::Drawing::Size(220, 40);
			this->btnINFO->TabIndex = 30;
			this->btnINFO->Text = L"USO / RUTAS";
			this->btnINFO->UseVisualStyleBackColor = true;
			this->btnINFO->Click += gcnew System::EventHandler(this, &Rutas::btnINFO_Click);
			// 
			// txtESTACION_DESTINO
			// 
			this->txtESTACION_DESTINO->Location = System::Drawing::Point(565, 544);
			this->txtESTACION_DESTINO->Name = L"txtESTACION_DESTINO";
			this->txtESTACION_DESTINO->Size = System::Drawing::Size(282, 22);
			this->txtESTACION_DESTINO->TabIndex = 29;
			this->txtESTACION_DESTINO->Text = L"DESTINO";
			this->txtESTACION_DESTINO->TextChanged += gcnew System::EventHandler(this, &Rutas::txtESTACION_DESTINO_TextChanged);
			// 
			// txtESTACION_ORIGEN
			// 
			this->txtESTACION_ORIGEN->Location = System::Drawing::Point(282, 544);
			this->txtESTACION_ORIGEN->Name = L"txtESTACION_ORIGEN";
			this->txtESTACION_ORIGEN->Size = System::Drawing::Size(262, 22);
			this->txtESTACION_ORIGEN->TabIndex = 28;
			this->txtESTACION_ORIGEN->Text = L"ORIGEN";
			this->txtESTACION_ORIGEN->TextChanged += gcnew System::EventHandler(this, &Rutas::txtESTACION_ORIGEN_TextChanged);
			// 
			// btnKRUSKAL
			// 
			this->btnKRUSKAL->Location = System::Drawing::Point(32, 604);
			this->btnKRUSKAL->Name = L"btnKRUSKAL";
			this->btnKRUSKAL->Size = System::Drawing::Size(220, 40);
			this->btnKRUSKAL->TabIndex = 27;
			this->btnKRUSKAL->Text = L"RED MÍNIMA (KRUSKAL)";
			this->btnKRUSKAL->UseVisualStyleBackColor = true;
			this->btnKRUSKAL->Click += gcnew System::EventHandler(this, &Rutas::btnKRUSKAL_Click);
			// 
			// btnVOLVER
			// 
			this->btnVOLVER->BackColor = System::Drawing::Color::Red;
			this->btnVOLVER->ForeColor = System::Drawing::Color::White;
			this->btnVOLVER->Location = System::Drawing::Point(540, 604);
			this->btnVOLVER->Name = L"btnVOLVER";
			this->btnVOLVER->Size = System::Drawing::Size(220, 40);
			this->btnVOLVER->TabIndex = 26;
			this->btnVOLVER->Text = L"VOLVER";
			this->btnVOLVER->UseVisualStyleBackColor = false;
			this->btnVOLVER->Click += gcnew System::EventHandler(this, &Rutas::btnVOLVER_Click);
			// 
			// mostrarContedinoRUTAS
			// 
			this->mostrarContedinoRUTAS->Location = System::Drawing::Point(36, 160);
			this->mostrarContedinoRUTAS->Name = L"mostrarContedinoRUTAS";
			this->mostrarContedinoRUTAS->ReadOnly = true;
			this->mostrarContedinoRUTAS->Size = System::Drawing::Size(811, 365);
			this->mostrarContedinoRUTAS->TabIndex = 25;
			this->mostrarContedinoRUTAS->Text = L"";
			this->mostrarContedinoRUTAS->TextChanged += gcnew System::EventHandler(this, &Rutas::mostrarContedinoRUTAS_TextChanged);
			// 
			// btnVerMasCorta
			// 
			this->btnVerMasCorta->Location = System::Drawing::Point(550, 100);
			this->btnVerMasCorta->Name = L"btnVerMasCorta";
			this->btnVerMasCorta->Size = System::Drawing::Size(220, 40);
			this->btnVerMasCorta->TabIndex = 24;
			this->btnVerMasCorta->Text = L"RUTA MÁS CORTA";
			this->btnVerMasCorta->UseVisualStyleBackColor = true;
			this->btnVerMasCorta->Click += gcnew System::EventHandler(this, &Rutas::btnVerMasCorta_Click);
			// 
			// btnVerMatrizAdyacencia
			// 
			this->btnVerMatrizAdyacencia->Location = System::Drawing::Point(36, 544);
			this->btnVerMatrizAdyacencia->Name = L"btnVerMatrizAdyacencia";
			this->btnVerMatrizAdyacencia->Size = System::Drawing::Size(220, 40);
			this->btnVerMatrizAdyacencia->TabIndex = 23;
			this->btnVerMatrizAdyacencia->Text = L"MATRIZ ADYACENCIA";
			this->btnVerMatrizAdyacencia->UseVisualStyleBackColor = true;
			this->btnVerMatrizAdyacencia->Click += gcnew System::EventHandler(this, &Rutas::btnVerMatrizAdyacencia_Click);
			// 
			// panelGrafoRutas
			// 
			this->panelGrafoRutas->BackColor = System::Drawing::SystemColors::Control;
			this->panelGrafoRutas->Location = System::Drawing::Point(874, 49);
			this->panelGrafoRutas->Name = L"panelGrafoRutas";
			this->panelGrafoRutas->Size = System::Drawing::Size(772, 830);
			this->panelGrafoRutas->TabIndex = 34;
			this->panelGrafoRutas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Rutas::panelGrafoRutas_Paint);
			// 
			// Rutas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(1544, 787);
			this->Controls->Add(this->panelGrafoRutas);
			this->Controls->Add(this->txtTITULO_RUTAS);
			this->Controls->Add(this->btnDFS);
			this->Controls->Add(this->btnBFS);
			this->Controls->Add(this->btnINFO);
			this->Controls->Add(this->txtESTACION_DESTINO);
			this->Controls->Add(this->txtESTACION_ORIGEN);
			this->Controls->Add(this->btnKRUSKAL);
			this->Controls->Add(this->btnVOLVER);
			this->Controls->Add(this->mostrarContedinoRUTAS);
			this->Controls->Add(this->btnVerMasCorta);
			this->Controls->Add(this->btnVerMatrizAdyacencia);
			this->Name = L"Rutas";
			this->Text = L"Rutas";
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

private: System::Void btnKRUSKAL_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarContedinoRUTAS->Clear();
	std::string resultado = grafo->kruskal();
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
private: System::Void panelGrafoRutas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;
	int n = grafo->getCantidad(); // método que devuelve cantidad de estaciones
	if (n == 0) return;

	// Posiciones circulares
	cli::array<System::Drawing::Point>^ posiciones = gcnew cli::array<System::Drawing::Point>(n);
	int cx = panelGrafoRutas->Width / 2;
	int cy = panelGrafoRutas->Height / 2;
	int radio = 200;

	for (int i = 0; i < n; ++i) {
		double angulo = 2 * Math::PI * i / n;
		int x = cx + (int)(radio * Math::Cos(angulo));
		int y = cy + (int)(radio * Math::Sin(angulo));
		posiciones[i] = System::Drawing::Point(x, y);
	}

	// Dibujar aristas con pesos
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int peso = grafo->getPeso(i, j); // método que devuelve matriz[i][j]
			if (peso != INF) {
				g->DrawLine(Pens::Black, posiciones[i], posiciones[j]);
				int midX = (posiciones[i].X + posiciones[j].X) / 2;
				int midY = (posiciones[i].Y + posiciones[j].Y) / 2;
				g->DrawString(
					peso.ToString(),
					gcnew System::Drawing::Font("Arial", 8),
					System::Drawing::Brushes::Red,
					static_cast<float>(midX),
					static_cast<float>(midY)
				);
			}
		}
	}

	// Dibujar nodos
	for (int i = 0; i < n; ++i) {
		String^ nombre = gcnew String(grafo->getNombreEstacion(i).c_str());
		System::Drawing::Font^ fuente = gcnew System::Drawing::Font("Arial", 8);
		SizeF textoSize = g->MeasureString(nombre, fuente);

		// Aumentar tamaño del nodo según el texto
		int anchoNodo = Math::Max(40, (int)textoSize.Width + 10);
		int altoNodo = Math::Max(40, (int)textoSize.Height + 10);

		// Centrar el nodo en la posición
		System::Drawing::Rectangle nodo(posiciones[i].X - anchoNodo / 2, posiciones[i].Y - altoNodo / 2, anchoNodo, altoNodo);
		g->FillEllipse(System::Drawing::Brushes::LightBlue, nodo);
		g->DrawEllipse(System::Drawing::Pens::Black, nodo);

		// Centrar el texto dentro del nodo
		g->DrawString(nombre, fuente, System::Drawing::Brushes::Black,
			posiciones[i].X - textoSize.Width / 2,
			posiciones[i].Y - textoSize.Height / 2);
	}
}
};
}
