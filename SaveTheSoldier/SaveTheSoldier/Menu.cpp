#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	rank = new Ranking;
}


Menu::~Menu()
{
}


void Menu::setNumerojogadores(int num) { numero_jogadores = num; }
int Menu::getNumeroJogadores() { return numero_jogadores; }
void Menu::setFaseN(int n) { n_fase = n; }
int Menu::getFaseN() { return n_fase; }
void Menu::setBmenu(const bool bmenu) { this->bmenu = bmenu; }
bool Menu::getBmenu() { return bmenu; }
void Menu::setFechar(bool fechar) { this->fechar = fechar; }
bool Menu::getFechar() { return fechar; }

void Menu::setTela(RenderWindow*janela, View* camera, float larg, float alt)
{
	janela->clear();
	janela->draw(background.getSprite());
	camera->setSize(larg, alt);
	camera->setCenter(larg / 2, alt / 2);
	janela->setView(*camera);
	janela->display();
}

string Menu::tela(RenderWindow* janela, View* camera) //tela do menu inicial do jogo)
{
	setTela(janela, camera, 308.0, 167.0);
	background.setBackground("Imagens\\Menu1.png");
	setTela(janela, camera, 308.0, 167.0); //necessario setar novamente
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::N))  //novo jogo
			{
				selectFase(janela, camera);
				escolhe_jogador(janela, camera);
				return "novo_jogo";
			}
			else if (Keyboard::isKeyPressed(Keyboard::C)) //continuar jogo salvo
			{
				setFaseN(2);
				setNumerojogadores(2);
				numero_jogadores = rank->loadPontos();
				remove("Files\\pontos_atuais.txt");
				return "continuar";
			}
			else if (Keyboard::isKeyPressed(Keyboard::R)) //ranking
			{
				rank->loadRank(janela, camera);
				return "ranking";
			}

			else if (Keyboard::isKeyPressed(Keyboard::S)) //sair
				return "sair";
		}
		else if (evento.type == Event::Closed)
			return "sair";
	}
}

void Menu::selectFase(RenderWindow*janela, View* camera)
{
	background.setBackground("Imagens\\MenuFase.png");
	setTela(janela, camera, 308.0, 167.0);
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Num1))  //fase 1
			{
				setFaseN(1);
				return;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num2)) //fase 2
			{
				setFaseN(2);
				return;
			}
		}
		else if (evento.type == Event::Closed)
			janela->close();
	}

}

void Menu::escolhe_jogador(RenderWindow*janela, View* camera)
{
	background.setBackground("Imagens\\Newgame.png");
	setTela(janela, camera, 308.0, 167.0);
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Num1))  //um jogador
			{
				setNumerojogadores(1);
				return;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num2)) //dois jogadores
			{
				setNumerojogadores(2);
				return;
			}
		}
		else if (evento.type == Event::Closed)
			janela->close();
	}
}

string Menu::telaPausa(RenderWindow* janela, View* camera)
{
	setTela(janela, camera, 308.0, 167.0);
	background.setBackground("Imagens\\MenuPause.png");
	setTela(janela, camera, 308.0, 167.0);
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::C)) //continuar jogo
				return "continuar_jogo";
			else if (Keyboard::isKeyPressed(Keyboard::S)) //sair do jogo
				return "sair";
		}
		else if (evento.type == Event::Closed)
			return "sair";
	}

}
string Menu::telaMorte(RenderWindow* janela, View* camera)
{
	setTela(janela, camera, 308.0, 167.0);
	background.setBackground("Imagens\\TelaMorte.png");
	setTela(janela, camera, 308.0, 167.0);
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::M)) //menu principal
			{
				return "menu_principal";
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) //sair do jogo
				return "sair";
		}
		else if (evento.type == Event::Closed)
			return "sair";
	}
}

string Menu::telaTransicao(RenderWindow* janela, View* camera)
{
	setTela(janela, camera, background.getLargura(), background.getAltura());
	background.setBackground("Imagens\\MenuTransicao.png");
	setTela(janela, camera, background.getLargura(), background.getAltura());
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::C)) //continuar jogo
				return "continuar";
			else if (Keyboard::isKeyPressed(Keyboard::G)) //guardar progresso
			{
				return "salvar";
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) //sair do jogo
				return "sair";
		}
		else if (evento.type == Event::Closed)
			return "sair";
	}
}
string Menu::telaFinal(RenderWindow* janela, View* camera)
{
	setTela(janela, camera, background.getLargura(), background.getAltura());
	background.setBackground("Imagens\\MenuFinal.png");
	setTela(janela, camera, background.getLargura(), background.getAltura());
	while (janela->waitEvent(evento))
	{
		if (evento.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::M)) //menu principal
			{
				return "menu_principal";
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) //sair do jogo
				return "sair";
		}
		else if (evento.type == Event::Closed)
			return "sair";
	}
}

void Menu::setPontuacaoInicial(int p)
{
	rank->setPontuacaoInicial(p);
}
void Menu::setPontuacaoFinal(int p)
{
	rank->setPontuacaoFinal(p);
}
void Menu::salvaRanking()
{
	rank->saveRank();
}
void Menu::guardarProgresso()
{
	rank->salvaRanking(numero_jogadores);
}