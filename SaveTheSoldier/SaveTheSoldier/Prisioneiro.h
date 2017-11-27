#pragma once
#include "Personagem.h"
class Prisioneiro :
	public Personagem
{
public:
	Prisioneiro(int x, int y);
	~Prisioneiro();

	void movimentar(bool colisao, View* cam);
	bool atacar();
};

