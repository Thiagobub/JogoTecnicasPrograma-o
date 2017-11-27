#include "stdafx.h"
#include "Personagem.h"



Personagem::Personagem()
{
	tiro_pronto = true;
}

Personagem::~Personagem()
{
}

void Personagem::setTiroPronto(bool t) { tiro_pronto = t; }
bool Personagem::getTiroPronto() { return tiro_pronto; }

void Personagem::incluirAnimacaoParado(string s, int a, int b, int c, int d) { Texture* t = new Texture(); t->loadFromFile(s, IntRect(a, b, c, d)); parado.push_back(t); }
void Personagem::setTempoAnimacaoParado(int i) { tempo_parado = i; }

void Personagem::incluirAnimacaoAndando(string s, int a, int b, int c, int d) { Texture* t = new Texture(); t->loadFromFile(s, IntRect(a, b, c, d)); andando.push_back(t); }
void Personagem::setTempoAnimacaoAndando(int i) { tempo_andando = i; }

void Personagem::incluirAnimacaoAtirando(string s, int a, int b, int c, int d) { Texture* t = new Texture(); t->loadFromFile(s, IntRect(a, b, c, d)); atirando.push_back(t); }
void Personagem::setTempoAnimacaoAtirando(int i) { tempo_atirando = i; }

void Personagem::atualizarAnimacao()
{
	string s = getEstado();
	if (mudouEstado())
	{
		setEstadoAntigo(s);
		i = 0;
	}

	if (s == "parado")
	{
		int j = floor(((i % tempo_parado) * parado.size()) / tempo_parado);
		atualizarSprite(parado[j]);
	}
	if (s == "andando_direita")
	{
		setOlhandoDireita(true);
		int j = floor(((i % tempo_andando) * andando.size()) / tempo_andando);
		atualizarSprite(andando[j]);
	}
	if (s == "andando_esquerda")
	{
		setOlhandoDireita(false);
		int j = floor(((i % tempo_andando) * andando.size()) / tempo_andando);
		atualizarSprite(andando[j]);
	}
	if (s == "atirando" && !getTiroPronto())
	{
		int j = floor(((i % tempo_atirando) * atirando.size()) / tempo_atirando);
		atualizarSprite(atirando[j]);

		if (i >= tempo_atirando - (100))
		{
			setTiroPronto(true);
			setEstado("parado");
		}
	}
	i++;
}


void Personagem::andarDireita(bool colisao)
{
	if (colisao)
		atualizarPos(-getVel().x, 0);
	else
		atualizarPos(getVel().x, 0);
}
void Personagem::andarEsquerda(bool colisao)
{
	if (colisao)
		atualizarPos(getVel().x, 0);
	else
		atualizarPos(-getVel().x, 0);
}
void Personagem::pular()
{
	if (estaNoChao())
		setPulando(true);

	if (getPulando())
		atualizarPos(Vector2f(0, -0.116));

	if (getPe().y < 120)
		setPulando(false);
}