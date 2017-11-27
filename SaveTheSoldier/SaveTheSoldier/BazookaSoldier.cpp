#include "stdafx.h"
#include "BazookaSoldier.h"


BazookaSoldier::BazookaSoldier(int x, int y)
{
	string s = "Imagens\\BazookaSoldier.png";

	setPosX(x);
	setPosY(y);
	setEstado("parado");
	setEstadoAntigo("parado");
	setOlhandoDireita(true);
	setNoChao(false);
	setAlturaTiro(28);
	setTag("BazookaSoldier");

	//DEFINIR SUAS VELOCIDADES
	setVelX(0.03);	//VELOCIDADE DE CORRIDA
	setVelY(0.3);	//O QUANTO ELE PULA


	//DEFINIR SEUS QUADROS DE ANIMAÇÃO E O TEMPO ENTRE CADA UM
	incluirAnimacaoParado(s, 2, 2, 36, 45);
	incluirAnimacaoParado(s, 44, 2, 38, 45);
	incluirAnimacaoParado(s, 86, 4, 38, 43);
	incluirAnimacaoParado(s, 128, 5, 36, 42);
	setTempoAnimacaoParado(6000);

	incluirAnimacaoAndando(s, 5, 62, 41, 39);
	incluirAnimacaoAndando(s, 54, 61, 41, 40);
	incluirAnimacaoAndando(s, 106, 61, 40, 40);
	incluirAnimacaoAndando(s, 156, 62, 41, 39);
	incluirAnimacaoAndando(s, 204, 63, 40, 38);
	incluirAnimacaoAndando(s, 250, 61, 41, 40);
	incluirAnimacaoAndando(s, 3, 104, 41, 40);
	incluirAnimacaoAndando(s, 51, 103, 38, 41);
	incluirAnimacaoAndando(s, 101, 103, 37, 41);
	incluirAnimacaoAndando(s, 151, 102, 36, 42);
	incluirAnimacaoAndando(s, 201, 103, 37, 41);
	incluirAnimacaoAndando(s, 251, 104, 38, 40);
	setTempoAnimacaoAndando(3200);
	
	incluirAnimacaoAtirando(s, 209, 258, 43, 37); //5
	incluirAnimacaoAtirando(s, 58, 296, 31, 57);  //8
	incluirAnimacaoAtirando(s, 109, 296, 35, 57); //9
	incluirAnimacaoAtirando(s, 109, 296, 35, 57); //9
	incluirAnimacaoAtirando(s, 58, 296, 31, 57);  //8
	incluirAnimacaoAtirando(s, 5, 301, 32, 52);   //7
	incluirAnimacaoAtirando(s, 260, 251, 39, 44); //6
	incluirAnimacaoAtirando(s, 209, 258, 43, 37); //5
	incluirAnimacaoAtirando(s, 159, 253, 46, 42); //4
	incluirAnimacaoAtirando(s, 159, 253, 46, 42); //4
	incluirAnimacaoAtirando(s, 159, 253, 46, 42); //4
	incluirAnimacaoAtirando(s, 159, 253, 46, 42); //4
	incluirAnimacaoAtirando(s, 159, 253, 46, 42); //4
	setTempoAnimacaoAtirando(10000);

	atualizarAnimacao();
}


BazookaSoldier::~BazookaSoldier()
{
}
