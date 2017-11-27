#pragma once
#include "Entidade.h"

using namespace Entidade1;

class Tiro :
	public Entidade
{
private:
	vector<Texture*> parado;	//FRAMES DA ANIMAÇÃO
	int tempo_parado;			//TEMPO NECESSÁRIO PARA COMPLETAR 1 CICLO

	int i;

public:
	Tiro(float x, float y, bool direita, bool aliado);

	~Tiro();


	void incluirAnimacaoParado(string s, int a, int b, int c, int d);
	void setTempoAnimacaoParado(int i);

	void atualizarAnimacao();

	void movimentar(bool colisao, View* camera);
	bool atacar();
};

