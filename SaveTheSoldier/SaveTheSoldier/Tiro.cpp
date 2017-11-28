#include "stdafx.h"
#include "Tiro.h"

using namespace Entidade1;

Tiro::Tiro(float x, float y, bool direita, bool aliado)
{
	setPosX(x);
	setPosY(y);

	if (direita)
	{
		setOlhandoDireita(true);
		setVelX(0.14);
	}
	else
	{
		setOlhandoDireita(false);
		setVelX(-0.14);
	}
	setVelY(0);

	if (aliado)
		incluirAnimacaoParado("Imagens\\TiroAliado.png", 0, 0, 30, 5);
	else
		incluirAnimacaoParado("Imagens\\TiroInimigo.png", 0, 0, 30, 5);
	setTempoAnimacaoParado(10);

	atualizarAnimacao();
}


Tiro::~Tiro()
{
}

void Tiro::incluirAnimacaoParado(string s, int a, int b, int c, int d) { Texture* t = new Texture(); t->loadFromFile(s, IntRect(a, b, c, d)); parado.push_back(t); }
void Tiro::setTempoAnimacaoParado(int i) { tempo_parado = i; }

void Tiro::atualizarAnimacao()
{
	int j = floor(((i % tempo_parado) * parado.size()) / tempo_parado);
	atualizarSprite(parado[j]);
	i++;
}

void Tiro::movimentar(bool colisao, View* camera) { atualizarPos(getVel().x, 0); }
bool Tiro::atacar() { return false; }