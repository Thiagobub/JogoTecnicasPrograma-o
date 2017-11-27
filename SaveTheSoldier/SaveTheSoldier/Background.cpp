#include "stdafx.h"
#include "Background.h"


Background::Background()
{

}

Background::~Background()
{

}

void	Background::setBackground(string const s) {
	texture.loadFromFile(s);	//carrega a imagem como textura
	imagem.setTexture(texture);	//salva a textura como imagem (background)
}

Texture	Background::getTextura() { return texture; }
Sprite	Background::getSprite() { return imagem; }
int		Background::getAltura() { return imagem.getGlobalBounds().height; }
int		Background::getLargura() { return imagem.getGlobalBounds().width; }

void	Background::setChao(int i) { nivel_chao = i; }
int		Background::getChao() { return nivel_chao; }