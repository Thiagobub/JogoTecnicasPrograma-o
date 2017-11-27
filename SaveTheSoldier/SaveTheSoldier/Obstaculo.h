#pragma once
#include "Entidade.h"

using namespace Entidade1;

class Obstaculo
	: public Entidade
{
private:
	vector<Texture*> parado;	//FRAMES DA ANIMAÇÃO
	int tempo_parado;			//TEMPO NECESSÁRIO PARA COMPLETAR 1 CICLO

	int i;

public:
	Obstaculo();
	~Obstaculo();

	void incluirAnimacaoParado(string s, int a, int b, int c, int d);
	void setTempoAnimacaoParado(int i);

	void atualizarAnimacao();

	virtual void movimentar(bool colisao, View* camera) {}
	virtual bool atacar() = 0;
};

