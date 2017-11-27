#include "stdafx.h"
#include "Chefe.h"


Chefe::Chefe(int x, int y)
{
	string s = "Imagens\\Chefe.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setAlturaTiro(23);
	setTag("Chefe");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0.06);	//VELOCIDADE DE CORRIDA
	setVelY(0.3);	//O QUANTO ELE PULA


					//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 5, 4, 80, 45);
	incluirAnimacaoParado(s, 87, 4, 81, 45);
	incluirAnimacaoParado(s, 170, 4, 78, 45);
	setTempoAnimacaoParado(6000);

	incluirAnimacaoAndando(s, 5, 53, 83, 50);
	incluirAnimacaoAndando(s, 90, 56, 83, 47);
	incluirAnimacaoAndando(s, 175, 55, 82, 48);
	incluirAnimacaoAndando(s, 259, 53, 81, 50);
	incluirAnimacaoAndando(s, 342, 55, 81, 48);
	incluirAnimacaoAndando(s, 425, 55, 82, 48);
	setTempoAnimacaoAndando(3200);

	incluirAnimacaoAtirando(s, 10, 109, 80, 44);
	incluirAnimacaoAtirando(s, 92, 109, 82, 44);
	incluirAnimacaoAtirando(s, 176, 109, 81, 44);
	incluirAnimacaoAtirando(s, 259, 109, 80, 44);
	setTempoAnimacaoAtirando(7500);

	atualizarAnimacao();
}


Chefe::~Chefe()
{
}
