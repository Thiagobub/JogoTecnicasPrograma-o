#pragma once
#include "Obstaculo.h"
class Caixa :
	public Obstaculo
{
public:
	Caixa(int x, int y);
	~Caixa();

	bool atacar();
};

