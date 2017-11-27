#include "stdafx.h"
#include "Obstaculo.h"


Obstaculo::Obstaculo()
{
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::incluirAnimacaoParado(string s, int a, int b, int c, int d) { Texture* t = new Texture(); t->loadFromFile(s, IntRect(a, b, c, d)); parado.push_back(t); }
void Obstaculo::setTempoAnimacaoParado(int i) { tempo_parado = i; }

void Obstaculo::atualizarAnimacao()
{
	int j = floor(((i % tempo_parado) * parado.size()) / tempo_parado);
	atualizarSprite(parado[j]);
	i++;
}
