
------------------------------------------------

PARA PODER EXECUTAR O PROJETO DO VISUAL STUDIO (CÓDIGO E NÃO .EXE) COM O SFML

------------------------------------------------

1. Clicar com o botão direito em cima do projeto "SaveTheSoldier" no gerenciador de soluções

2. Ir em propriedades

3. Setar a Configuração em "Todas as Configurações" no canto superior esquerdo da tela

4. Ir em Diretórios VC++

5. Adicionar uma nova linha em "Diretórios de Inclusão"

6. Abrir a pasta SFML e selecionar a pasta "include" (Caminho: "SFML\include")

7. Em "Diretórios de Biblioteca" adicionar uma nova linha

8. Abrir a pasta SFML e selecionar a pasta "lib" (Caminho: "SFML\lib")

9. Caso necessário, setar Configuração para "Debuger" em "Linker -> Entrada" adiconar as seguintes linhas:
sfml-graphics-d.lib
sfml-system-d.lib
sfm-system-d.lib

10. Agora setar Configuração para "Release" no mesmo local, adicionar as seguintes linhas:
sfml-graphics.lib
sfml-system.lib
sfm-system.lib

11. Aplicar e rodar o jogo

-------------------------------------------------
