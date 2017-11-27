#pragma once

#include "stdafx.h"

namespace Entidade1
{
	class Entidade
	{
	private:
		Vector2f posAnt;
		Vector2f pos;
		Vector2f vel;
		Sprite sprite;	//Atual anima��o 
		string estado;	//Parado, andando, etc...
		string estado_antigo;
		string tag;

		float altura_tiro; //em rela��o ao p� (para inimigos e jogadores)

		bool olhando_direita;
		bool no_chao;
		bool pulando;

	public:

		Entidade();	//DEFINIR LOCALIZA��O DE SPAWN E ETC... QUE � PADR�O
		~Entidade();

		bool operator==(string s);
		bool operator!=(string s);

		void setPosAnt(float x, float y);
		void setPosAntX(float x);
		void setPosAntY(float y);

		void setPos(float x, float y);
		void setPosX(float x);
		void setPosY(float y);

		void setVel(float x, float y);
		void setVelX(float x);
		void setVelY(float y);

		void setEstado(string e = "parado");
		void setEstadoAntigo(string e = "parado");
		void setSprite(Texture t);
		void setNoChao(bool b);
		void setPulando(bool b);
		void setAlturaTiro(float h);
		void setOrigem();	//Coloca a origem no "p�" da Entidade (Bottom Center)
		void setTag(string s);

		//Fun��es Informativas
		Vector2f getCentro();
		Vector2f getPosAnt();
		Vector2f getPos();
		Vector2f getVel();
		string getEstado();	//Para Anima�ao
		string getTag();
		Sprite getSprite();	//Para desenhar na tela
		FloatRect getBox();	//Para Colis�o
		float getAltura();
		float getLargura();
		float getAlturaTiro();
		bool colidiu(FloatRect* o);//Para ver se um objeto colidiu com esse
		bool mudouEstado();
		bool estaNoChao();	//Para o pulo
		bool getOlhandoDireita();
		bool getPulando();

		//Pegar "p�" (ponto) (centro da borda inferior) para colis�o com o chao
		Vector2f getPe();

		//Para ele inverter a imagem ao andar para a esquerda
		void setOlhandoDireita(bool flag);
		void atualizaDirecaoSprite();

		//Fun��es para chamar
		void gravidade(bool colisao);

		void retornaPos();
		void atualizarPos(float x, float y);
		void atualizarPos(Vector2f v);
		void atualizarSprite(Texture* t);
		void atualizaPosSprite();

		virtual void atualizarAnimacao() = 0;
		virtual void movimentar(bool colisao, View* camera) = 0;		//Movimenta��o do Player/Inimigos
		virtual bool atacar() = 0;
	};
}