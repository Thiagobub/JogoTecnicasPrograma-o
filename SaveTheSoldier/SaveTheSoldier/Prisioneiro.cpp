#include "stdafx.h"
#include "Prisioneiro.h"


Prisioneiro::Prisioneiro(int x, int y)
{
	string s = "Imagens\\Prisioneiro.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setTag("Prisioneiro");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0);	//VELOCIDADE DE CORRIDA
	setVelY(0);	//O QUANTO ELE PULA


					//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 0, 0, 32, 45);
	setTempoAnimacaoParado(6000);

	atualizarAnimacao();
}


Prisioneiro::~Prisioneiro()
{
}

void Prisioneiro::movimentar(bool colisao, View* cam) 
{
}
bool Prisioneiro::atacar() { return false; }