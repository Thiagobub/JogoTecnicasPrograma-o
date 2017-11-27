#pragma once

#include "stdafx.h"
#include "Fase.h"

template <class T1>
class Lista_Elementos
{
private:

	template <class T2>
	class Elemento
	{
	private:
		Elemento<T2>* prox;
		T2 info;

	public:
		Elemento() { prox = NULL; info = NULL; }
		~Elemento() {}

		void setPoximo(Elemento<T2>* p) { prox = p; }
		Elemento<T2>* getProximo() { return prox; }

		void setInfo(T2 i) { info = i; }
		T2 getInfo() { return info; }
	};

	Elemento<Fase*>* prim;
	Elemento<Fase*>* ult;
	int tam;

public:
	Lista_Elementos() { prim = NULL; ult = NULL; }
	~Lista_Elementos() {}

	void setPrimeiro(Elemento<Fase*>* p) { prim = p; }
	Elemento<Fase*>* getPrimeiro() { return prim; }

	T1 getInfoPrimeiro() { return prim->getInfo(); }

	void setUltimo(Elemento<Fase*>* u) { ult = u; }
	Elemento<Fase*>* getUltimo() { return ult; }

	void setTamanho(int t) { tam = t; }
	int getTamanho() { return tam; }

	void incluir(T1 i)
	{
		Elemento<Fase*>* novo = new Elemento<T1>;
		novo->setInfo(i);
		if (getPrimeiro() == NULL)
		{
			setPrimeiro(novo);
			getPrimeiro()->setPoximo(NULL);
			setUltimo(novo);
			tam++;
		}
		else
		{
			getUltimo()->setPoximo(novo);
			setUltimo(novo);
			tam++;
		}
	}

	void popFirst()
	{
		if (getPrimeiro() != NULL)
		{
			Elemento<T1>* aux = getPrimeiro();
			setPrimeiro(getPrimeiro()->getProximo());
			delete aux->getInfo();
			delete aux;
			tam--;
		}
	}

};

