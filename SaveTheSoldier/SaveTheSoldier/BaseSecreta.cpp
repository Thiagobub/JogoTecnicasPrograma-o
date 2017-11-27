#include "stdafx.h"
#include "BaseSecreta.h"


BaseSecreta::BaseSecreta(View* camera, int num)
{
	setBackground("Imagens\\BaseSecreta.png");
	setCamera(camera);
	setNivelChao(171);
	setNumeroJogadores(num);
}


BaseSecreta::~BaseSecreta()
{
}


bool BaseSecreta::fimFase()
{
	for (int i = 0; i < (int)getSizeListaJogadores(); i++)
	{
		for (int j = 0; (int)getSizeListaGeral(); j++)
		{
			if (getEntidadeListaGeral(j)->getTag() == "Prisioneiro")
			{
				if (getEntidadeListaJogadores(i)->colidiu(&getEntidadeListaGeral(j)->getBox()))
				{
					return true;
				}
				break;
			}
		}
	}
	return false;
}

void BaseSecreta::spawnEntidades()
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
	for (x = 450; x <= 2850; x += 150)
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

	novo = (Entidade*) new Chefe(3200, 125);
	incluirInimigo(novo);

	novo = (Entidade*) new Prisioneiro(3400, 171);
	incluirGeral(novo);
}