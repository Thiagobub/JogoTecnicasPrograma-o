#include "stdafx.h"
#include "Inimigo.h"


Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::movimentar(bool colisao, View* cam)	//virtual, pois o chef�o (que tamb�m ter� implementado) ser� diferente
{
	camera = cam;
	//movimenta��o, (Patrulha) do inimigo
}

bool Inimigo::atacar() { return (atirar()) ? true : false; }

bool Inimigo::atirar()
{
	if ((camera->getCenter().x > getPos().x - (1.3 * camera->getSize().x / 3)) && (camera->getCenter().x < getPos().x + (1.3 * camera->getSize().x / 3)))
	{
		if (camera->getCenter().x < getPos().x)
			setOlhandoDireita(false);
		else
			setOlhandoDireita(true);

		if (getTiroPronto())
		{
			setTiroPronto(false);
			setEstado("atirando");
			atualizarAnimacao();
			return true;
		}
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