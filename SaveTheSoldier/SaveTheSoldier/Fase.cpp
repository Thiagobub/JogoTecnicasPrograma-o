#include "stdafx.h"
#include "Fase.h"

Fase::Fase()
{

}

Fase::~Fase()
{

	Entidade* aux;

	for (int i = (int)lista_geral.size() - 1; i >= 0; i--)
		lista_geral.pop_back();
	for (int i = (int)lista_obstaculos.size() - 1; i >= 0; i--)
	{
		aux = lista_obstaculos[i];
		lista_obstaculos.pop_back();
		delete aux;
	}
	for (int i = (int)lista_inimigos.size() - 1; i >= 0; i--)
	{
		aux = lista_inimigos[i];
		lista_inimigos.pop_back();
		delete aux;
	}
	for (int i = (int)lista_jogadores.size() - 1; i >= 0; i--)
	{
		aux = lista_jogadores[i];
		lista_jogadores.pop_back();
		delete aux;
	}
	for (int i = (int)lista_tiros_aliados.size() - 1; i >= 0; i--)
	{
		aux = lista_tiros_aliados[i];
		lista_tiros_aliados.pop_back();
		delete aux;
	}
	for (int i = (int)lista_tiros_inimigos.size() - 1; i >= 0; i--)
	{
		aux = lista_tiros_inimigos[i];
		lista_tiros_inimigos.pop_back();
		delete aux;
	}

}

void Fase::setfaseNum(int n) { faseNum = n; }
int Fase::getfaseNum() { return faseNum; }

bool Fase::morte()		//verifica a morte dos dois jogadores
{
	if (lista_jogadores.empty())
		return true;
	else
		return false;
}

void Fase::setBackground(string s) { background.setBackground(s); }
void Fase::setNivelChao(int i) { background.setChao(i); }
void Fase::setCamera(View* c) { camera = c; }
void Fase::setNumeroJogadores(int num) { numero_jogadores = num; }

int Fase::getNumeroJogadores() { return numero_jogadores; }
int Fase::getNivelChao() { return background.getChao(); }
View* Fase::getCamera() { return camera; }

int Fase::getSizeListaObstaculo() { return lista_obstaculos.size(); }
int Fase::getSizeListaInimigos() { return lista_inimigos.size(); }
int Fase::getSizeListaJogadores() { return lista_jogadores.size(); }
int Fase::getSizeListaGeral() { return lista_geral.size(); }

Entidade* Fase::getEntidadeListaObstaculos(int i) { return lista_obstaculos[i]; }
Entidade* Fase::getEntidadeListaInimigos(int i) { return lista_inimigos[i]; }
Entidade* Fase::getEntidadeListaJogadores(int i) { return lista_jogadores[i]; }
Entidade* Fase::getEntidadeListaTirosAliados(int i) { return lista_tiros_aliados[i]; }
Entidade* Fase::getEntidadeListaTirosInimigos(int i) { return lista_tiros_inimigos[i]; }
Entidade* Fase::getEntidadeListaGeral(int i) { return lista_geral[i]; }

Sprite Fase::getFundo() { return background.getSprite(); }
int Fase::getLargB() { return background.getLargura(); }
int Fase::getAltB() { return background.getAltura(); }

void Fase::incluirObstaculo(Entidade* e) { lista_obstaculos.push_back(e); incluirGeral(e); }
void Fase::incluirInimigo(Entidade* e) { lista_inimigos.push_back(e); incluirGeral(e); }
void Fase::incluirJogador(Entidade* e) { lista_jogadores.push_back(e); incluirGeral(e); }
void Fase::incluirTiroAliado(Entidade* e) { lista_tiros_aliados.push_back(e); incluirGeral(e); }
void Fase::incluirTiroInimigo(Entidade* e) { lista_tiros_inimigos.push_back(e); incluirGeral(e); }
void Fase::incluirGeral(Entidade* e) { lista_geral.push_back(e); }

void Fase::deletarObstaculo(Entidade* e)
{
	for (int i = 0; i < lista_obstaculos.size(); i++)
		if (lista_obstaculos[i] == e)
		{
			lista_obstaculos.erase(lista_obstaculos.begin() + i);
			deletarGeral(e);
			break;
		}
}
void Fase::deletarInimigo(Entidade* e)
{
	for (int i = 0; i < lista_inimigos.size(); i++)
		if (lista_inimigos[i] == e)
		{
			lista_inimigos.erase(lista_inimigos.begin() + i);
			deletarGeral(e);
			break;
		}
}
void Fase::deletarJogador(Entidade* e)
{
	for (int i = 0; i < lista_jogadores.size(); i++)
		if (lista_jogadores[i] == e)
		{
			lista_jogadores.erase(lista_jogadores.begin() + i);
			deletarGeral(e);
			break;
		}
}
void Fase::deletarTiroAliado(Entidade* e)
{
	for (int i = 0; i < lista_tiros_aliados.size(); i++)
		if (lista_tiros_aliados[i] == e)
		{
			lista_tiros_aliados.erase(lista_tiros_aliados.begin() + i);
			deletarGeral(e);
			break;
		}
}
void Fase::deletarTiroInimigo(Entidade* e)
{
	for (int i = 0; i < lista_tiros_inimigos.size(); i++)
		if (lista_tiros_inimigos[i] == e)
		{
			lista_tiros_inimigos.erase(lista_tiros_inimigos.begin() + i);
			deletarGeral(e);
			break;
		}
}
void Fase::deletarGeral(Entidade* e)
{
	for (int i = 0; i < lista_geral.size(); i++)
		if (lista_geral[i] == e)
		{
			lista_geral.erase(lista_geral.begin() + i);
			delete e;
			break;
		}
}

void Fase::atualizar()
{
	checarTiros();
	checarColisoesFatais();
	chamarGravidade();
	movimentar();
	atacar();
	atualizarAnimacao();
}

void Fase::chamarGravidade()	//Não pode chamar da lista_geral, pq os tiros não serão afetados pela gravidade
{
	int i = 0;
	for (i = 0; i < (int)lista_obstaculos.size(); i++)
	{
		if (lista_obstaculos[i]->getPos().y < getNivelChao())	//Obstaculos não pulam pra sair do chão e precisar checar colisão com outras paradas
			lista_obstaculos[i]->gravidade(false);
	}
	for (i = 0; i < (int)lista_inimigos.size(); i++)
	{
		if (lista_inimigos[i]->getPos().y < getNivelChao())	//Inimigo não pula pra precisar checar colisão pra chamar gravidade
			lista_inimigos[i]->gravidade(false);
	}
	for (i = 0; i < (int)lista_jogadores.size(); i++)
	{
		if (lista_jogadores[i]->getPos().y < getNivelChao())
		{
			lista_jogadores[i]->setNoChao(false);
			lista_jogadores[i]->gravidade(false);
		}
		else
			lista_jogadores[i]->setNoChao(true);
		if (checarColisaoInimigos(lista_jogadores[i]))
		{
			deletarJogador(lista_jogadores[i]);
			lista_jogadores[i]->setNoChao(true);
			lista_jogadores[i]->gravidade(true);
		}

		int j;
		for (j = 0; j < (int)lista_obstaculos.size(); j++)
		{
			if (lista_jogadores[i]->colidiu(&lista_obstaculos[j]->getBox()))
			{
				if (*lista_obstaculos[j] == "LixoToxico" || *lista_obstaculos[j] == "GranadaInstavel")
				{
					deletarJogador(lista_jogadores[i]);
				}
				else
				{
					lista_jogadores[i]->setNoChao(true);
					lista_jogadores[i]->gravidade(true);
				}
			}
		}
	}
}

bool Fase::checarColisaoGeral(Entidade* e)
{
	int i;
	for (i = 0; i < (int)lista_geral.size(); i++)
	{
		if (lista_geral[i] != e)
			if (e->colidiu(&lista_geral[i]->getBox()))
				return true;
	}
	return false;
}
bool Fase::checarColisaoObstaculos(Entidade* e)
{
	int i;
	for (i = 0; i < (int)lista_obstaculos.size(); i++)
	{
		if (lista_obstaculos[i] != e)
			if (e->colidiu(&lista_obstaculos[i]->getBox()))
				return true;
	}
	return false;
}
bool Fase::checarColisaoInimigos(Entidade* e)
{
	int i;
	for (i = 0; i < (int)lista_inimigos.size(); i++)
	{
		if (lista_inimigos[i] != e)
			if (e->colidiu(&lista_inimigos[i]->getBox()))
				return true;
	}
	return false;
}
bool Fase::checarColisaoJogadores(Entidade* e)
{
	int i;
	for (i = 0; i < (int)lista_jogadores.size(); i++)
	{
		if (lista_jogadores[i] != e)
			if (e->colidiu(&lista_jogadores[i]->getBox()))
				return true;
	}
	return false;
}
void Fase::checarTiros()
{
	bool tiro_existe; //caso o tiro colidiu, ele não vai mais existir e não devemos comparar com o resto
	int i;
	int j;
	for (i = 0; i < (int)lista_tiros_aliados.size(); i++)
	{
		tiro_existe = true;
		//Se sair para fora da camera, então deleta o tiro
		if ((lista_tiros_aliados[i]->getPos().x < camera->getCenter().x - (camera->getSize().x / 2)) || (lista_tiros_aliados[i]->getPos().x > camera->getCenter().x + (camera->getSize().x / 2)))
		{
			deletarTiroAliado(lista_tiros_aliados[i]);
			tiro_existe = false;
		}
		//Se acertou algum obstaculo, deleta o obstaculo
		if (tiro_existe)
		{
			for (j = 0; j < (int)lista_obstaculos.size(); j++)
			{
				if (lista_tiros_aliados[i]->colidiu(&lista_obstaculos[j]->getBox()))
				{
					deletarTiroAliado(lista_tiros_aliados[i]);
					//--lista_obstaculos[j];
					deletarObstaculo(lista_obstaculos[j]);
					tiro_existe = false;
					break;
				}
			}
		}
		//Se acertou algum inimigo, deleta o inimigo
		if (tiro_existe)
		{
			for (j = 0; j < (int)lista_inimigos.size(); j++)
			{

				if (lista_tiros_aliados[i]->colidiu(&lista_inimigos[j]->getBox()))
				{
					deletarTiroAliado(lista_tiros_aliados[i]);
					//lista_inimigos[j]--;
					deletarInimigo(lista_inimigos[j]);
					tiro_existe = false;
					break;
				}
			}
		}
	}
	for (i = 0; i < (int)lista_tiros_inimigos.size(); i++)
	{
		tiro_existe = true;
		//Se sair para fora da camera, então deleta o tiro
		if ((lista_tiros_inimigos[i]->getPos().x < camera->getCenter().x - (camera->getSize().x / 2)) || (lista_tiros_inimigos[i]->getPos().x > camera->getCenter().x + (camera->getSize().x / 2)))
		{
			deletarTiroInimigo(lista_tiros_inimigos[i]);
			tiro_existe = false;
		}
		if (tiro_existe)
		{
			for (j = 0; j < (int)lista_jogadores.size(); j++)
			{
				if (lista_tiros_inimigos[i]->colidiu(&lista_jogadores[j]->getBox()))
				{
					deletarTiroInimigo(lista_tiros_inimigos[i]);
					//lista_jogadores[j]--;
					deletarJogador(lista_jogadores[j]);
					tiro_existe = false;
					break;
				}
			}
		}		
		if (tiro_existe)
		{
			for (j = 0; j < (int)lista_obstaculos.size(); j++)
			{
				if (lista_tiros_inimigos[i]->colidiu(&lista_obstaculos[j]->getBox()))
				{
					deletarTiroInimigo(lista_tiros_inimigos[i]);
					//lista_jogadores[j]--;
					tiro_existe = false;
					break;
				}
			}
		}
	}
}

void Fase::checarColisoesFatais()
{
	int i, j;
	for (i = 0; i < (int)lista_jogadores.size(); i++)
	{
		for (j = 0; j < (int)lista_inimigos.size(); j++)
		{
			if (lista_jogadores[i]->colidiu(&lista_inimigos[j]->getBox()))
			{
				deletarJogador(lista_jogadores[i]);
				break;
			}

		}
		for (j = 0; j < (int)lista_obstaculos.size(); j++)
		{
			if (*lista_obstaculos[j] == "GranadaInstavel")
			{
				if (lista_jogadores[i]->colidiu(&lista_obstaculos[j]->getBox()))
				{
					deletarObstaculo(lista_obstaculos[j]);
					deletarJogador(lista_jogadores[i]);
					break;
				}
			}
			if (*lista_obstaculos[j] == "LixoToxico")
			{
				if (lista_jogadores[i]->colidiu(&lista_obstaculos[j]->getBox()))
				{
					deletarJogador(lista_jogadores[i]);
					break;
				}
			}
		}
	}
}


void Fase::movimentar()
{
	int i = 0;
	for (i = 0; i < (int)lista_inimigos.size(); i++)	//Não vai ter colisão entre inimigos
	{
		lista_inimigos[i]->movimentar(false, camera);
		if (checarColisaoObstaculos(lista_inimigos[i]))	//Colisão com Obstaculos
			lista_inimigos[i]->movimentar(true, camera);
		if (checarColisaoJogadores(lista_inimigos[i]))	//Colisão com Players
			lista_inimigos[i]->movimentar(true, camera);
	}
	for (i = 0; i < (int)lista_jogadores.size(); i++)	//Não vai ter colisão entre players
	{
		lista_jogadores[i]->movimentar(false, camera);
		if (checarColisaoObstaculos(lista_jogadores[i]))	//Colisão com obstaculos
			lista_jogadores[i]->movimentar(true, camera);
		if (checarColisaoInimigos(lista_jogadores[i]))		//colisão com Inimigos
			lista_jogadores[i]->movimentar(true, camera);
	}
	for (i = 0; i < (int)lista_tiros_aliados.size(); i++)	 //Só basta movimentar os tiros, eles serão verificados se colidiram em outro lugar
	{
		lista_tiros_aliados[i]->movimentar(false, camera);
	}
	for (i = 0; i < (int)lista_tiros_inimigos.size(); i++)	 //Só basta movimentar os tiros, eles serão verificados se colidiram em outro lugar
	{
		lista_tiros_inimigos[i]->movimentar(false, camera);
	}
	for (i = 0; i < (int)lista_obstaculos.size(); i++)	//Eles não colidem, apenas precisam atualizar a animação
		lista_obstaculos[i]->movimentar(false, camera);
}

void Fase::atacar()
{
	int i;
	for (i = 0; i < (int)lista_jogadores.size(); i++)
	{
		if (lista_jogadores[i]->atacar())
		{
			Tiro* t;
			t = new Tiro(lista_jogadores[i]->getPos().x, (lista_jogadores[i]->getPos().y - lista_jogadores[i]->getAlturaTiro()), lista_jogadores[i]->getOlhandoDireita(), true);
			incluirTiroAliado(t);
		}
	}
	for (i = 0; i < (int)lista_inimigos.size(); i++)
	{
		if (lista_inimigos[i]->atacar())
		{
			Tiro* t;
			if (camera->getCenter().x < lista_inimigos[i]->getPos().x)
				t = new Tiro(lista_inimigos[i]->getPos().x, lista_inimigos[i]->getPos().y - lista_inimigos[i]->getAlturaTiro(), false, false);
			else
				t = new Tiro(lista_inimigos[i]->getPos().x, lista_inimigos[i]->getPos().y - lista_inimigos[i]->getAlturaTiro(), true, false);

			incluirTiroInimigo(t);
		}
	}
}

void Fase::atualizarAnimacao()
{
	int i;
	for (i = 0; i < (int)lista_geral.size(); i++)
	{
		if (camera->getCenter().x - ((2 * camera->getSize().x) / 3) < lista_geral[i]->getPos().x && lista_geral[i]->getPos().x < camera->getCenter().x + ((2 * camera->getSize().x) / 3))
			lista_geral[i]->atualizarAnimacao();
	}
}