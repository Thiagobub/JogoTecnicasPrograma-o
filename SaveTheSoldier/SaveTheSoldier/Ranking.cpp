#include "stdafx.h"
#include "Ranking.h"


Ranking::Ranking()
{
	points = 0;
	games = 0;
	font.loadFromFile("Files\\arial.ttf");
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setCharacterSize(30);

	text.setStyle(sf::Text::Bold);
	auxi = 0;
	para = false;
}


Ranking::~Ranking()
{
}

void Ranking::setPoints(int pontos) { this->points = points; }
int Ranking::getPoints() { return points; }
void Ranking::setgames(const int games) { this->games = games; }
int Ranking::getGames() { return games; }

void Ranking::saveRank()
{
	s_file.open("Files\\rank_new.txt");
	s_file << "games=" << this->getGames() << endl;
	s_file << "pontos=" << this->getPoints() << endl;
	s_file.close();
	return;
}

void Ranking::loadRank(RenderWindow* j, View* camera)
{

	l_file.open("Files\\rankin.txt");
	while (getline(l_file, line))
	{
		istringstream linestream(line);
		if (getline(linestream, key, '='))
		{
			if (getline(linestream, value))
			{
				if (key == "games")
				{
					jogo.push_back(stoi(value));
					games++;
				}
				else if (key == "pontos")
				{
					ponto.push_back(stoi(value));
				}
			}
			else
				cerr << "Erro, nenhum valor encontrado para a chave" << key << endl;
		}
	}
	RenderWindow* janela;
	janela = new RenderWindow(VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Rankings");
	janela->setSize(Vector2u(JANELA_LARGURA, JANELA_ALTURA));
	camera->setSize(JANELA_LARGURA, JANELA_ALTURA);
	camera->setCenter(JANELA_LARGURA / 2, JANELA_ALTURA / 2);
	janela->setView(*camera);
	janela->clear(Color(0, 0, 0, 255));
	janela->clear();
	janela->display();
	janela->clear(Color(0, 0, 0, 255));
	janela->clear();
	text.setPosition(Vector2f(JANELA_LARGURA / 10, JANELA_ALTURA / 4));
	for (int i = 0; i<(int)ponto.size(); i++)
	{
		line = "Jogo" + to_string(jogo[i]) + ":	" + to_string(ponto[i]) + " pontos";
		text.move(0, 45); //o valor eh para teste
		text.setString(line);
		janela->draw(text);
		// janela->display(); 
	}
	text.move(0, 90);
	text.setCharacterSize(15);
	text.setString("Pressione (V) para voltar...");
	janela->draw(text);
	janela->display();
	text.setPosition(0, 0);
	l_file.close();

	while (!Keyboard::isKeyPressed(Keyboard::V))
	{

	}

	janela->close();
	delete janela;

	return;
}

void Ranking::setPontuacaoInicial(int pontuacao_inicial)
{
	this->pontuacao_inicial = pontuacao_inicial;
}
void Ranking::setPontuacaoFinal(int pontuacao_final)
{
	this->pontuacao_final = pontuacao_final;
	pontuacao_total += pontuacao_inicial - pontuacao_final;
}
void Ranking::salvaRanking(int num_P)
{
	//Salva a pontuacao total(intermediaria) em um arquivo e reseta a pontuacao
	s_file.open("Files\\pontos_atuais.txt");
	s_file << "pontos=" << this->pontuacao_total << endl;
	s_file << "jogadores=" << num_P << endl;
	s_file.close();
	pontuacao_total = 0;
	return;
}
int Ranking::loadPontos()
{
	//Carregar pontuacao total do arquivo
	l_file.open("Files\\pontos_atuais.txt");
	while (getline(l_file, line))
	{
		istringstream linestream(line);
		if (getline(linestream, key, '='))
		{
			if (getline(linestream, value))
			{
				if (key == "pontos")
				{
					this->pontuacao_total = stoi(value);
				}
				else if (key == "jogadores")
				{
					return stoi(value);
				}
			}
			else
				cerr << "Erro, nenhum valor encontrado para a chave" << key << endl;
		}
	}


}