#pragma once
#include "Fase.h"
#include <stdlib.h>
#include <time.h>


class BaseSecreta :
	public Fase
{
public:
	BaseSecreta(View* camera, int num);
	virtual ~BaseSecreta();

	bool fimFase();
	void spawnEntidades();

};
