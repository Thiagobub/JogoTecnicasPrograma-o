#include "stdafx.h"
#include "Caixa.h"


Caixa::Caixa(int x, int y)
{
	string s = "Imagens\\Caixa.png";

	setVelX(0);
	setVelY(0);

	incluirAnimacaoParado(s, 10, 16, 60, 43);
	setTempoAnimacaoParado(10);


	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setTag("Caixa");

	atualizarAnimacao();
}


Caixa::~Caixa()
{
}

bool Caixa::atacar() { return false; }