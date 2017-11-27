#include "stdafx.h"
#include "Cidade.h"


Cidade::Cidade(View* camera, int num = 1)
{
	setBackground("Imagens\\Cidade.png");
	setCamera(camera);
	setNivelChao(181);
	setNumeroJogadores(num);
}


Cidade::~Cidade()
{
}

bool Cidade::fimFase()
{
	for (int i = 0; i < (int)getSizeListaJogadores(); i++)
	{
		if (getEntidadeListaJogadores(i)->getPos().x >= 3500)
		{
			return true;
		}
	}
	return false;
}

void Cidade::spawnEntidades()
{
	Entidade* novo;

	novo = (Entidade*) new Jogador1(125, 125);
	incluirJogador(novo);
	if (getNumeroJogadores() == 2)
	{
		novo = (Entidade*) new Jogador2(175, 125);
		incluirJogador(novo);
	}

	int x;
	int r;
	srand(time(NULL));
	for (x = 600; x <= 3300; x += 150)
	{
		r = rand() % 5;
		if (r == 0)
		{
			novo = (Entidade*) new LixoToxico(x, 125);
			incluirObstaculo(novo);
		}
		else if (r == 1)
		{
			novo = (Entidade*) new Caixa(x, 125);
			incluirObstaculo(novo);
		}
		else if (r == 2)
		{
			novo = (Entidade*) new GranadaInstavel(x, 125);
			incluirObstaculo(novo);
		}
		else if (r == 3)
		{
			novo = (Entidade*) new RifleSoldier(x, 125);
			incluirInimigo(novo);
		}
		else if (r == 4)
		{
			novo = (Entidade*) new BazookaSoldier(x, 125);
			incluirInimigo(novo);
		}
	}
}