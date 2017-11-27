#include "stdafx.h"
#include "Principal.h"


Principal::Principal()
{
	iniciar();
	executar();
}


Principal::~Principal()
{
}

void Principal::iniciar()
{
	janela = new RenderWindow(VideoMode(JANELA_LARGURA, JANELA_ALTURA), "Meu Jogo");	//CRIA UMA JANELA
	janela->setPosition(Vector2i(0, 0));	//SETA A POSIÇÃO DA JANELA NA TELA DO USUARIO

	camera = new View();

	menu = new Menu;
	//menu->tela(janela, camera);


	camera->setSize(368, 207);

	exec_menu_principal = true;
	nova_fase = false;
}


void Principal::centralizarCamera()
{
	int centro = 0, i;
	for (i = 0; i < lista_fases.getInfoPrimeiro()->getSizeListaJogadores(); i++)
	{
		centro += lista_fases.getInfoPrimeiro()->getEntidadeListaJogadores(i)->getPos().x;
	}

	if ((centro / i >= 200) && (lista_fases.getInfoPrimeiro()->getLargB() - (centro / i)))
		camera->setCenter(centro / i, camera->getSize().y / 2);
	else if ((centro) / i < 200)
		camera->setCenter(200, camera->getSize().y / 2);
	else
			camera->setCenter(lista_fases.getInfoPrimeiro()->getLargB() - 200, camera->getSize().y / 2);

}


void Principal::atualizarEcra()
{
	janela->clear();	///LIMPA A TELA
	janela->draw(lista_fases.getPrimeiro()->getInfo()->getFundo()); //desenha o fundo

																	//REDESENHA CADA UMA DAS ENTIDADES DA FASE
	for (int i = 0; i < lista_fases.getInfoPrimeiro()->getSizeListaGeral(); i++)
		janela->draw(lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i)->getSprite());

	janela->setView(*camera);
	centralizarCamera();
	janela->display();	///ATUALIZA A TELA
	return;
}

void Principal::executar()
{
	while (janela->isOpen())
	{
		//Se Tiver que executar o menu
		if (exec_menu_principal && janela->isOpen())
		{
			exec_menu_principal = false;
			//Se o menu mandou começar um novo jogo
			return_menu = menu->tela(janela, camera);
			if (return_menu == "novo_jogo")
			{
				if (menu->getFaseN() == 1)
				{
					Fase* fase;
					fase = new Cidade(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);

					fase = new BaseSecreta(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);
				}
				else
				{
					Fase* fase;
					fase = new BaseSecreta(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);
				}
				nova_fase = true;
			}
			else if (return_menu == "ranking")
			{
				exec_menu_principal = true;
			}
			else if (return_menu == "continuar")
			{
				if (menu->getFaseN() == 1)
				{
					Fase* fase;
					fase = new Cidade(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);

					fase = new BaseSecreta(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);
				}
				else
				{
					Fase* fase;
					fase = new BaseSecreta(camera, menu->getNumeroJogadores());
					lista_fases.incluir(fase);
				}

				nova_fase = true;
			}
			else if (return_menu == "sair")
			{
				janela->close();
				break;
			}
		}

		//Se tiver que carregar uma fase
		if (nova_fase && !exec_menu_principal && janela->isOpen())
		{
			lista_fases.getInfoPrimeiro()->spawnEntidades();
			pontuacao = 0;
			for (int i = 0; i < lista_fases.getInfoPrimeiro()->getSizeListaGeral(); i++)
			{
				if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "LixoToxico" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "Caixa" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "GranadaInstavel")
					pontuacao += 15;
				else if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "BazookaSoldier" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "RifleSoldier")
					pontuacao += 30;
				else if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "Chefe")
					pontuacao += 60;
			}
			menu->setPontuacaoInicial(pontuacao);
			nova_fase = false;
		}

		//Loop da fase atual
		if (janela->isOpen() && !exec_menu_principal)
			lista_fases.getInfoPrimeiro()->atualizar();

		while (janela->pollEvent(evento) && janela->isOpen())
		{
			if (evento.type == Event::Closed)
				janela->close();
			if (evento.type == Event::KeyPressed)
				if (keyboard.isKeyPressed(Keyboard::Escape) || keyboard.isKeyPressed(Keyboard::P))
				{
					return_menu = menu->telaPausa(janela, camera);
					if (return_menu == "sair")
					{
						janela->close();
						break;
					}
				}
			camera->setSize(368, 207);
		}

		if (!exec_menu_principal && lista_fases.getInfoPrimeiro()->morte() && janela->isOpen())	//GAME OVER
		{
			while (lista_fases.getPrimeiro() != NULL)
			{
				lista_fases.popFirst();
			}
			return_menu = menu->telaMorte(janela, camera);
			if (return_menu == "menu_principal")
			{
				exec_menu_principal = true;
			}
			else if (return_menu == "sair")
			{
				janela->close();
				break;
			}
		}

		//QUANDO A FASE ATUAL ACABAR
		if (lista_fases.getPrimeiro() != NULL)
		{
			if (lista_fases.getInfoPrimeiro()->fimFase() && janela->isOpen() && !exec_menu_principal)
			{
				pontuacao = 0;
				for (int i = 0; i < lista_fases.getInfoPrimeiro()->getSizeListaGeral(); i++)
				{
					if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "LixoToxico" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "Caixa" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "GranadaInstavel")
						pontuacao += 15;
					else if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "BazookaSoldier" || *lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "RifleSoldier")
						pontuacao += 30;
					else if (*lista_fases.getInfoPrimeiro()->getEntidadeListaGeral(i) == "Chefe")
						pontuacao += 60;
				}
				lista_fases.popFirst();
				if (lista_fases.getPrimeiro() != NULL)	//tem uma próxima fase
				{
					return_menu = menu->telaTransicao(janela, camera);
					if (return_menu == "salvar")
					{
						menu->setPontuacaoFinal(pontuacao);
						menu->guardarProgresso();
						exec_menu_principal = true;
					}
					else if (return_menu == "sair")
					{
						janela->close();
						break;
					}
					else if (return_menu == "continuar")
					{
						menu->setPontuacaoFinal(pontuacao);
						nova_fase = true;	//para carregar a nova fase ali em cima
					}
				}
				else	//caso não tenha uma próxima fase
				{
					return_menu = menu->telaFinal(janela, camera);
					if (return_menu == "menu_principal")
					{
						exec_menu_principal = true;
					}
					else if (return_menu == "sair")
					{
						janela->close();
						break;
					}
					menu->salvaRanking();
				}
			}
		}

		if (janela->isOpen() && !nova_fase && !exec_menu_principal)
			atualizarEcra();
	}
}