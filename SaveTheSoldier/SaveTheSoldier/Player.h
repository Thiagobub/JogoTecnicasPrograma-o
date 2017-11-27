#pragma once
#include "Personagem.h"

class Player :
	public Personagem
{
private:

	Keyboard::Key direita;
	Keyboard::Key esquerda;
	Keyboard::Key pula;
	Keyboard::Key atira;

	Keyboard* keyboard;

public:
	Player();
	~Player();

protected:
	//Devem se chamados pela construtora de cada player

	void setControleDireita(Keyboard::Key k);
	void setControleEsquerda(Keyboard::Key k);
	void setControlePular(Keyboard::Key k);
	void setControleAtirar(Keyboard::Key k);

public:

	void movimentar(bool colisao, View* camera);

	bool atacar();

	bool atirar();
};
