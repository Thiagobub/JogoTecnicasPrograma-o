#include "stdafx.h"
#include "LixoToxico.h"


LixoToxico::LixoToxico(int x, int y)
{
	string s = "Imagens\\LixoToxico.png";

	setVelX(0);
	setVelY(0);

	incluirAnimacaoParado(s, 0, 11, 50, 48);
	incluirAnimacaoParado(s, 55, 11, 51, 48);
	incluirAnimacaoParado(s, 112, 11, 51, 48);
	incluirAnimacaoParado(s, 170, 11, 52, 48);
	incluirAnimacaoParado(s, 230, 11, 52, 48);
	incluirAnimacaoParado(s, 290, 11, 52, 48);
	incluirAnimacaoParado(s, 349, 11, 52, 48);
	incluirAnimacaoParado(s, 408, 11, 50, 48);
	setTempoAnimacaoParado(5500);

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setTag("LixoToxico");

	atualizarAnimacao();
}


LixoToxico::~LixoToxico()
{
}

bool LixoToxico::atacar() { return false; }