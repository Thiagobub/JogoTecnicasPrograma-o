#pragma once
#include "stdafx.h"

#include "Background.h"

#include "Jogador1.h"
#include "Jogador2.h"

#include "Caixa.h"
#include "GranadaInstavel.h"
#include "LixoToxico.h"

#include "RifleSoldier.h"
#include "BazookaSoldier.h"
#include "Chefe.h"

#include "Prisioneiro.h"
#include "Tiro.h"

#include "Progressao.h"
#include "Menu.h"

using namespace Entidade1;

class Fase
{
private:
	Background background;
	vector<Entidade*> lista_obstaculos;
	vector<Entidade*> lista_inimigos;
	vector<Entidade*> lista_jogadores;
	vector<Entidade*> lista_tiros_aliados;
	vector<Entidade*> lista_tiros_inimigos;
	vector<Entidade*> lista_geral;
	View* camera;
	Menu* menu;
	int faseNum;
	int numero_jogadores;

public:
	Fase();
	virtual ~Fase();

	void setfaseNum(int n);
	int getfaseNum();

	bool morte();

	void setBackground(string s);
	void setNivelChao(int i);
	void setCamera(View* c);
	void setNumeroJogadores(int num);

	int getNumeroJogadores();
	int getNivelChao();
	View* getCamera();

	int getSizeListaObstaculo();
	int getSizeListaInimigos();
	int getSizeListaJogadores();
	int getSizeListaGeral();

	Entidade* getEntidadeListaObstaculos(int i);
	Entidade* getEntidadeListaInimigos(int i);
	Entidade* getEntidadeListaJogadores(int i);
	Entidade* getEntidadeListaTirosAliados(int i);
	Entidade* getEntidadeListaTirosInimigos(int i);
	Entidade* getEntidadeListaGeral(int i);

	Sprite getFundo();
	int getLargB();
	int getAltB();

	void incluirObstaculo(Entidade* e);
	void incluirInimigo(Entidade* e);
	void incluirJogador(Entidade* e);
	void incluirTiroAliado(Entidade* e);
	void incluirTiroInimigo(Entidade* e);
	void incluirGeral(Entidade* e);

	void deletarObstaculo(Entidade* e);
	void deletarInimigo(Entidade* e);
	void deletarJogador(Entidade* e);
	void deletarTiroAliado(Entidade* e);
	void deletarTiroInimigo(Entidade* e);
	void deletarGeral(Entidade* e);

	void atualizar();

	void chamarGravidade();

	bool checarColisaoGeral(Entidade* e);
	bool checarColisaoObstaculos(Entidade* e);
	bool checarColisaoInimigos(Entidade* e);
	bool checarColisaoJogadores(Entidade* e);
	void checarTiros();

	void checarColisoesFatais();


	void movimentar();

	void atacar();

	void atualizarAnimacao();

	virtual bool fimFase() = 0;
	virtual void spawnEntidades() = 0;
};

