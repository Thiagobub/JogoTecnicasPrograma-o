#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setControleDireita(Keyboard::Key k) { direita = k; }
void Player::setControleEsquerda(Keyboard::Key k) { esquerda = k; }
void Player::setControlePular(Keyboard::Key k) { pula = k; }
void Player::setControleAtirar(Keyboard::Key k) { atira = k; }

void Player::movimentar(bool colisao, View* camera)
{
	setEstado("parado");

	if (keyboard->isKeyPressed(direita))	//Andando para a Direita
	{
		if (getPos().x < camera->getCenter().x + (camera->getSize().x / 3))
		{
			setEstado("andando_direita");
			andarDireita(colisao);
		}
		else
			andarEsquerda(false);
	}

	if (keyboard->isKeyPressed(esquerda))	//Andando para a Esquerda
	{
		if (camera->getCenter().x - (camera->getSize().x / 3) < getPos().x)
		{
			setEstado("andando_esquerda");
			andarEsquerda(colisao);
		}
		else
			andarDireita(false);
	}

	if (keyboard->isKeyPressed(pula))		//Pulando
		pular();
	else
		setPulando(false);
}

bool Player::atacar() { return (atirar() ? true : false); }

bool Player::atirar()
{

	if (keyboard->isKeyPressed(atira) && getTiroPronto())
	{
		setTiroPronto(false);
		setEstado("atirando");
		atualizarAnimacao();
		return true;
	}
	if (!getTiroPronto())
	{
		setEstado("atirando");
		atualizarAnimacao();
		return false;
	}
	else
		return false;
}