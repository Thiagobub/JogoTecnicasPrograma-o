#include "stdafx.h"
#include "GranadaInstavel.h"


GranadaInstavel::GranadaInstavel(int x, int y)
{
	string s = "Imagens\\GranadaInstavel.png";

	setVelX(0);
	setVelY(0);

	incluirAnimacaoParado(s, 7, 5, 18, 11);
	setTempoAnimacaoParado(10);

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setTag("GranadaInstavel");

	atualizarAnimacao();
}

GranadaInstavel::~GranadaInstavel()
{
}
