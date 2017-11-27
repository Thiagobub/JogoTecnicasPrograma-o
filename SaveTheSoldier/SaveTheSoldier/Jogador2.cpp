#include "stdafx.h"
#include "Jogador2.h"


Jogador2::Jogador2(int x, int y)
{
	string s = "Imagens\\Player2.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setAlturaTiro(28);
	setTag("Jogador2");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0.045);	//VELOCIDADE DE CORRIDA
	setVelY(0.3);	//VELOCIDADE DO PULO

	//DEFINIR OS CONTROLES DESTE JOGADOR
	setControleDireita(Keyboard::Right);
	setControleEsquerda(Keyboard::Left);
	setControlePular(Keyboard::Up);
	setControleAtirar(Keyboard::Numpad0);

	//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 5, 2, 32, 40);
	incluirAnimacaoParado(s, 42, 2, 33, 40);
	incluirAnimacaoParado(s, 79, 2, 34, 40);
	incluirAnimacaoParado(s, 118, 2, 33, 40);
	incluirAnimacaoParado(s, 157, 2, 32, 40);
	incluirAnimacaoParado(s, 194, 2, 32, 40);
	setTempoAnimacaoParado(6000);

	incluirAnimacaoAndando(s, 445, 50, 35, 43);
	incluirAnimacaoAndando(s, 404, 49, 36, 44);
	incluirAnimacaoAndando(s, 362, 53, 37, 40);
	incluirAnimacaoAndando(s, 326, 50, 32, 43);
	incluirAnimacaoAndando(s, 287, 50, 33, 43);
	incluirAnimacaoAndando(s, 248, 51, 33, 42);
	incluirAnimacaoAndando(s, 206, 50, 35, 43);
	incluirAnimacaoAndando(s, 163, 49, 38, 44);
	incluirAnimacaoAndando(s, 119, 49, 40, 40);
	incluirAnimacaoAndando(s, 80, 50, 35, 43);
	incluirAnimacaoAndando(s, 43, 51, 32, 42);
	incluirAnimacaoAndando(s, 4, 51, 33, 42);
	setTempoAnimacaoAndando(3200);

	//incluirAnimacaoAtirando(s, 4, 99, 34, 41); //1
	//incluirAnimacaoAtirando(s, 42, 98, 50, 41);//2
	incluirAnimacaoAtirando(s, 102, 98, 54, 40); //3
	incluirAnimacaoAtirando(s, 160, 98, 67, 40); //4
	incluirAnimacaoAtirando(s, 232, 98, 69, 40); //5
	incluirAnimacaoAtirando(s, 306, 98, 51, 40); //6
	incluirAnimacaoAtirando(s, 363, 98, 53, 40); //7
	incluirAnimacaoAtirando(s, 423, 97, 53, 40); //8
	incluirAnimacaoAtirando(s, 363, 98, 53, 40); //7
	incluirAnimacaoAtirando(s, 423, 97, 53, 40); //8
	//incluirAnimacaoAtirando(s, 481, 95, 50, 41); //9
	//incluirAnimacaoAtirando(s, 534, 95, 34, 41); //10
	setTempoAnimacaoAtirando(3500);
}


Jogador2::~Jogador2()
{
}
