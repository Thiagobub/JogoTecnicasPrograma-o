#include "stdafx.h"
#include "RifleSoldier.h"


RifleSoldier::RifleSoldier(int x, int y)
{
	string s = "Imagens\\RifleSoldier.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setAlturaTiro(28);
	setTag("RifleSoldier");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0.03);	//VELOCIDADE DE CORRIDA
	setVelY(0.3);	//O QUANTO ELE PULA


	//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 17, 7, 40, 38);
	incluirAnimacaoParado(s, 66, 7, 40, 38);
	incluirAnimacaoParado(s, 115, 8, 39, 37);
	incluirAnimacaoParado(s, 163, 7, 43, 38);
	setTempoAnimacaoParado(6000);

	incluirAnimacaoAndando(s, 223, 11, 37, 35);
	incluirAnimacaoAndando(s, 369, 9, 35, 37);
	incluirAnimacaoAndando(s, 313, 9, 34, 37);
	incluirAnimacaoAndando(s, 356, 10, 38, 36);
	incluirAnimacaoAndando(s, 403, 9, 39, 37);
	incluirAnimacaoAndando(s, 451, 8, 40, 38);
	setTempoAnimacaoAndando(3200);

	incluirAnimacaoAtirando(s, 7, 68, 48, 38);
	//incluirAnimacaoAtirando(s, 64, 68, 47, 38);
	//incluirAnimacaoAtirando(s, 120, 66, 42, 40);
	incluirAnimacaoAtirando(s, 171, 59, 41, 47);
	incluirAnimacaoAtirando(s, 221, 62, 43, 44);
	incluirAnimacaoAtirando(s, 273, 68, 47, 38);
	incluirAnimacaoAtirando(s, 329, 68, 47, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);

	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	incluirAnimacaoAtirando(s, 385, 68, 48, 38);
	setTempoAnimacaoAtirando(10000);

	atualizarAnimacao();
}


RifleSoldier::~RifleSoldier()
{
}
