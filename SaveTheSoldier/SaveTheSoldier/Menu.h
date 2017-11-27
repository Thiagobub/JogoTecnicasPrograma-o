#pragma once
#include "stdafx.h"
#include "Background.h"
#include "Ranking.h"

class Menu
{
private:
	Background background;
	Keyboard* keyboard;
	Event evento;
	int numero_jogadores;
	int n_fase;
	Ranking* rank;
	bool bmenu; //voltar pro menu principal
	bool fechar;


public:
	Menu();
	~Menu();

	void setNumerojogadores(int num);
	int getNumeroJogadores();
	void setFaseN(int n);
	int getFaseN();
	void setBmenu(const bool bmenu);
	bool getBmenu();
	void setFechar(bool fechar);
	bool getFechar();

	void setTela(RenderWindow*janela, View* camera, float larg, float alt);

	string tela(RenderWindow* janela, View* camera); //tela do menu inicial do jogo)

	void selectFase(RenderWindow*janela, View* camera);

	void escolhe_jogador(RenderWindow*janela, View* camera);

	string telaPausa(RenderWindow* janela, View* camera);
	string telaMorte(RenderWindow* janela, View* camera);

	string telaTransicao(RenderWindow* janela, View* camera);
	string telaFinal(RenderWindow* janela, View* camera);

	void setPontuacaoInicial(int p);
	void setPontuacaoFinal(int p);
	void salvaRanking();
	void guardarProgresso();
};