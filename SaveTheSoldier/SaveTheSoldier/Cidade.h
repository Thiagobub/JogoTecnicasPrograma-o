#pragma once
#include "Fase.h"
#include <stdlib.h>
#include <time.h>

class Cidade :
	public Fase
{
public:
	Cidade(View* camera, int num);
	virtual ~Cidade();

	bool fimFase();

	void spawnEntidades();
};
