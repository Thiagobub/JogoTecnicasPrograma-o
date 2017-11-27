#pragma once
#include "stdafx.h"

#include "Cidade.h"
#include "BaseSecreta.h"

#include "Jogador1.h"
#include "Jogador2.h"
#include "LixoToxico.h"
#include "Menu.h"
#include "Lista_Elementos.h"

class Principal
{
private:
	RenderWindow* janela;
	Event evento;
	Keyboard keyboard;
	Lista_Elementos<Fase*> lista_fases;
	Menu* menu;
	View* camera;
	string return_menu;
	bool nova_fase;
	bool exec_menu_principal;
	int pontuacao;

public:
	virtual ~Principal();
	Principal();

	void iniciar();


	void centralizarCamera();


	void atualizarEcra();

	void executar();
};