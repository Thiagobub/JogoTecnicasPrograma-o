#pragma once

#include "stdafx.h"
#include "Entidade.h"

using namespace Entidade1;

class Personagem
	: public Entidade
{
private:
	vector<Texture*> parado;	//FRAMES DA ANIMAÇÃO
	int tempo_parado;			//TEMPO NECESSÁRIO PARA COMPLETAR 1 CICLO
	vector<Texture*> andando;
	int tempo_andando;
	vector<Texture*> atirando;
	int tempo_atirando;

	bool tiro_pronto;

	int i;


public:
	Personagem();
	~Personagem();

	void setTiroPronto(bool t);
	bool getTiroPronto();

	void incluirAnimacaoParado(string s, int a, int b, int c, int d);
	void setTempoAnimacaoParado(int i);

	void incluirAnimacaoAndando(string s, int a, int b, int c, int d);
	void setTempoAnimacaoAndando(int i);

	void incluirAnimacaoAtirando(string s, int a, int b, int c, int d);
	void setTempoAnimacaoAtirando(int i);

	void atualizarAnimacao();


	void andarDireita(bool colisao);
	void andarEsquerda(bool colisao);
	void pular();
	

	virtual bool atacar() = 0;
	virtual void movimentar(bool colisao, View* camera) = 0;
};

