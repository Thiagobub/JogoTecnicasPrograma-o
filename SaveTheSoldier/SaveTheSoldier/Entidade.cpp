#include "stdafx.h"
#include "Entidade.h"

using namespace Entidade1;

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

bool Entidade::operator==(string s)
{
	return (this->getTag() == s) ? true : false;
}
bool Entidade::operator!=(string s)
{
	return (this->getTag() == s) ? false : true;
}

void Entidade::setPosAnt(float x, float y) { setPosAntX(x); setPosAntY(y); }
void Entidade::setPosAntX(float x) { posAnt.x = x; }
void Entidade::setPosAntY(float y) { posAnt.y = y; }

void Entidade::setPos(float x, float y) { setPosX(x); setPosY(y); }
void Entidade::setPosX(float x) { setPosAntX(pos.x); pos.x = x; atualizaPosSprite(); }
void Entidade::setPosY(float y) { setPosAntY(pos.y); pos.y = y; atualizaPosSprite(); }

void Entidade::setVel(float x, float y) { setVelX(x); setVelY(y); }
void Entidade::setVelX(float x) { vel.x = x; }
void Entidade::setVelY(float y) { vel.y = y; }

void Entidade::setEstado(string e) { estado = e; }
void Entidade::setEstadoAntigo(string e) { estado_antigo = e; }
void Entidade::setSprite(Texture t) { sprite.setTexture(t); }
void Entidade::setNoChao(bool b) { no_chao = b; }
void Entidade::setPulando(bool b) { pulando = b; }
void Entidade::setAlturaTiro(float h) { altura_tiro = h; }
void Entidade::setOrigem() { sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height); }	//Coloca a origem no "pé" da Entidade (Bottom Center)
void Entidade::setTag(string s) { tag = s; }

//Funções Informativas
Vector2f Entidade::getCentro() { return Vector2f(getPos().x + getLargura() / 2, getPos().y + getAltura() / 2); }
Vector2f Entidade::getPosAnt() { return posAnt; }
Vector2f Entidade::getPos() { return sprite.getPosition(); }
Vector2f Entidade::getVel() { return vel; }
string Entidade::getEstado() { return estado; }	//Para Animaçao
string Entidade::getTag() { return tag; }
Sprite Entidade::getSprite() { return sprite; }	//Para desenhar na tela
FloatRect Entidade::getBox() { return sprite.getGlobalBounds(); }	//Para Colisão
float Entidade::getAltura() { return sprite.getGlobalBounds().height; }
float Entidade::getLargura() { return sprite.getGlobalBounds().width; }
float Entidade::getAlturaTiro() { return altura_tiro; }
bool Entidade::colidiu(FloatRect* o) { return o->intersects(getBox()); }	//Para ver se um objeto colidiu com esse
bool Entidade::mudouEstado() { return (estado_antigo != estado) ? true : false; }
bool Entidade::estaNoChao() { return no_chao; }	//Para o pulo
bool Entidade::getOlhandoDireita() { return olhando_direita; }
bool Entidade::getPulando() { return pulando; }

//Pegar "pé" (ponto) (centro da borda inferior) para colisão com o chao
Vector2f Entidade::getPe() { Vector2f v(getPos().x + (getLargura() / 2), getPos().y + getAltura()); return v; }

//Para ele inverter a imagem ao andar para a esquerda
void Entidade::setOlhandoDireita(bool flag) { olhando_direita = flag; atualizaDirecaoSprite(); }
void Entidade::atualizaDirecaoSprite() { (olhando_direita) ? sprite.setScale(1, 1) : sprite.setScale(-1, 1); }

//Funções para chamar
void Entidade::gravidade(bool colisao)
{
	if (colisao)
		setPosY(getPos().y - GRAVIDADE);
	else
		setPosY(getPos().y + GRAVIDADE);
}

void Entidade::retornaPos() { setPos(getPosAnt().x, getPosAnt().y); }
void Entidade::atualizarPos(float x, float y) { setOrigem(); setPos(pos.x + x, pos.y + y); atualizaPosSprite(); setOrigem(); }
void Entidade::atualizarPos(Vector2f v) { Vector2f p = getPos() + v; setPos(p.x, p.y); atualizaPosSprite(); }
void Entidade::atualizarSprite(Texture* t) { setOrigem(); sprite.setTexture(*t, 1); atualizaDirecaoSprite(); setOrigem(); }
void Entidade::atualizaPosSprite() { setOrigem(); sprite.setPosition(pos); setOrigem(); }