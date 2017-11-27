#pragma once
#include "Obstaculo.h"
class LixoToxico :
	public Obstaculo
{
public:
	LixoToxico(int x, int y);
	~LixoToxico();

	bool atacar();
};

