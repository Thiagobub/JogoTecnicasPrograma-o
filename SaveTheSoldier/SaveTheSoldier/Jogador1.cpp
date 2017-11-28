#include "stdafx.h"
#include "Jogador1.h"


Jogador1::Jogador1(int x, int y)
{
	string s = "Imagens\\Player1.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setAlturaTiro(18);
	setTag("Jogador1");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0.1);	//VELOCIDADE DE CORRIDA
	setVelY(8);	//VELOCIDADE DO PULO

	//DEFINIR OS CONTROLES DESTE JOGADOR
	setControleDireita(Keyboard::D);
	setControleEsquerda(Keyboard::A);
	setControlePular(Keyboard::W);
	setControleAtirar(Keyboard::F);

	//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 5, 2, 37, 38);
	incluirAnimacaoParado(s, 50, 2, 38, 38);
	incluirAnimacaoParado(s, 95, 2, 38, 38);
	incluirAnimacaoParado(s, 140, 2, 38, 38);
	incluirAnimacaoParado(s, 184, 2, 38, 38);
	incluirAnimacaoParado(s, 228, 2, 38, 38);
	setTempoAnimacaoParado(6000);

	incluirAnimacaoAndando(s, 5, 44, 42, 40);
	incluirAnimacaoAndando(s, 54, 44, 41, 41);
	incluirAnimacaoAndando(s, 102, 45, 42, 41);
	incluirAnimacaoAndando(s, 152, 44, 39, 40);
	incluirAnimacaoAndando(s, 197, 44, 41, 40);
	incluirAnimacaoAndando(s, 245, 44, 42, 40);
	incluirAnimacaoAndando(s, 294, 42, 42, 40);
	incluirAnimacaoAndando(s, 341, 41, 46, 41);
	incluirAnimacaoAndando(s, 393, 46, 48, 37);
	incluirAnimacaoAndando(s, 448, 43, 42, 40);
	incluirAnimacaoAndando(s, 497, 43, 43, 40);
	incluirAnimacaoAndando(s, 547, 43, 43, 40);
	setTempoAnimacaoAndando(3200);

	incluirAnimacaoAtirando(s, 2, 89, 60, 38);
	incluirAnimacaoAtirando(s, 69, 88, 60, 37);
	setTempoAnimacaoAtirando(2000);
}


Jogador1::~Jogador1()
{
}
