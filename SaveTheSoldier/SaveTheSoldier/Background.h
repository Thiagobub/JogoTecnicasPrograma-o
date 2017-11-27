#pragma once
#include "stdafx.h"


class Background
{
private:
	Texture texture;
	Sprite imagem;
	int nivel_chao;

public:
	Background();
	~Background();

	void setBackground(string const s);

	Texture getTextura();
	Sprite getSprite();
	int getAltura();
	int getLargura();

	void setChao(int i);
	int getChao();
};