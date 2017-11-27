#pragma once
#include "stdafx.h"
class Ranking
{
private:
	int points;
	ifstream l_file;
	ofstream s_file;
	string line, key, value;
	int games;		 //numero de pontuacoes salvas
	Font font;
	Text text;
	vector<int>jogo;
	vector<int>ponto;
	int auxi;
	bool para, troca;
	int pontuacao_inicial;
	int pontuacao_final;
	int pontuacao_total;

public:
	Ranking();
	~Ranking();
	void setPoints(int pontos);
	int getPoints();
	void setgames(const int games);
	int getGames();

	void saveRank();

	void loadRank(RenderWindow* j, View* camera);

	void setPontuacaoInicial(int pontuacao_inicial);
	void setPontuacaoFinal(int pontuacao_final);
	void salvaRanking(int num_P);
	int loadPontos();
};