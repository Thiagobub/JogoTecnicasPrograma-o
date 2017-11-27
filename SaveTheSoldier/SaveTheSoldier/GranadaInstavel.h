#pragma once
#include "Obstaculo.h"
class GranadaInstavel :
	public Obstaculo
{
public:
	GranadaInstavel(int x, int y);
	~GranadaInstavel();

	bool atacar() { return false; }
};

