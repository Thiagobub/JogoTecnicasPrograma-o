#pragma once
#include "Personagem.h"

using namespace Entidade1;

class Inimigo
	: public Personagem
{
private:
	View* camera;

public:
	Inimigo();
	~Inimigo();


	void movimentar(bool colisao, View* cam);

	bool atacar();

	bool atirar();
};
