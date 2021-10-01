# Integração do TouchGFX Designer e o STM32CubeIDE
Autores: Fábio Itturriet e Patrick Morás  
Data: 01/10/2021  
Versão: STM32Cube 1.7.0; TouchGFX 4.17.0  

_________________________________________________________________________________________________________________________________________________________________________________

Na atual verção é possivel importar o projeto gerado pelo touchGFX para o STM32Cube e compilar sem problemas, o projeto então fica anexado CubeIDE e continua na pastas de projeto do TouchGFX, dessa maneira é possivel aterar qualquer componente gráfico no touchGFX, e ao gerar o código automaticamente é atualizado no CubeIDE. 
Todavia o TouchGFX cria os aquivos do projeto sempre com nome da platarforma que esta sendo usada, com isso fica dificil de saber em qual projeto se esta tabalhando no CubeIDE, então será apresentado uma maneira de renomear os projeto atravez do Visual Studio Code (VS).

# Começando um novo projeto de integração

Comece criando um projeto simples no TouchGFX designer, pode-se adicionar alguns componentes gráfico, mas sem se preocupar pois isso poderá ser alterado futuramente.

1. Execute o programa > clique em "Create New"
2. Selecione a placa de desenvolvimento, nesse exemplo foi utilizada a STM32F769I-DISCO
3. Na janela direita dê um nome ao projeto, foi escolhido Teste_tela
4. A área de trabalho se dá por uma área retangular representando a tela do plataforma, acima dessa área temos os componentes gráficos, na direita temos a aba de configuração e interações juntamente, logo abaixo, tem os botões de gerar código, rodar no simulador e rodar na plataforma respectivamente. 
5. Nesse primeiro momento temos duas opções, criar a tela desejada gerando o código no final, ou então apenas gerar o código. Como esse exemplo visa apenas a integração, nesse momento não foi adicionado nada a tela, e simplemente gerado o código, lembrando que mais para frente a tela poderá ser alterada, então criar a tela antes ou depois da integração não fará diferença. 

imagem

Gerado o código pelo touchGFX Designer podemos fechar o programa
_________________________________________________________________________________________________________________________________________________________________________________

# Renomeando o projeto 

Para que o projeto no cubeIDE fique com o mesmo nome do projeto criado no Touch GFX é preciso fazer alguns ajustes em alguns arquivos. Vá até a pasta do projeto criado

imagem

como é visto o nome do arquivo .ioc é o nome da plataforma escolhida STM32F769I_DISCO, começamos renomeando este aquivo (esse nome deverá se manter igual nas proximas alterações), foi escolhido mesmo nome colocado no projeto anteriomente "Teste_tela"

imagem

os proximos arquivos serão alterados usando o Visual Studio code. Na pasta TouchGFX selecione o executavel "ApplicationTemplate"  e aperte "abrir com Code" 

imagem

logo nas linhas iniciais no Visual Studio (VS) temos o código "Name" e logo em seguida o nome do projeto (nome da plataforma como ja comentado). Selecione e copie o nome do projeto

imagem

vá na aba "editar" do VS e clique na opção "substituir", sera aberto uma janela com o nome do projeto preenchido na área superior, na área de texto inferior coloque nome que se deseja ter no projeto (mesmo nome colocado no arquivo .ioc anteriormente) e aperte em "substituir tudo"

imagem

o proximos arquivos a serem editados podem ser arrastados diretamente pro VS, da pasta do TouchGFX o proximo arquivo a ser editado é o segundo executável que teve o nome dado dentro do programa

imagem 
clique e arraste o arquivo

Na pasta anterior a essa, entre em STM32CubeIDE e o arquivos ".cproject" e ".project" também devem ser alterados.

imagem
clique e arraste os arquivos

No VS faça o mesmo processo de subtituição, agora clicando direto em substituir tudo em cada um dos códigos. Por fim vá em arquivo e clique em "Salvar tudo"

_________________________________________________________________________________________________________________________________________________________________________________

# Importando o Projeto do TouchGFX no CubeIDE

Execute o STM32CubeIDE para importar o projeto

**Importante**: Ao selecionar o espaço de trabalho do CubeIDE, prefira por caminhos sem espaço pois podem gerar comflitos 
1. No CubeIDE vá atá a aba File > Import...
2. Selecione Existing Projects into Workspace > Next
3. Selecione Select root diretory > clique em browse... e selecione a pasta do projeto criado no touchGFX
4. Na área de "Projects:" será reconhecido o diretório do projeto para o STMCube, marque-o e clique em "Finish" 

imagem

Por ora, a integração esta completa, mas é interessante fazer algumas alterações para facilitar a manipulação do projeto. Para se ter acesso um acesso direto do arquivo do projeto da tela no cubeIDE basta ir até a pasta do TouchGFX dentro da pasta do projeto criado, clicar e segurar no executável do projeto, arrasta-lo para o cubeIDE e soltá-lo no projeto impotado na aba "Project Explorer"

imagem

Selecione "Link to files" e clique em "OK"

imagem

dessa maneira o executável do TouchGFX fica de fácil acesso para fazer alterações.

_________________________________________________________________________________________________________________________________________________________________________________

# Configuração do Debugger

Antes de executar o código na plataforma deve configurar o Debugger. Com a plataforma conectada:

1. Execute o CubeIDE e vá na guia Run > Debugger configuration...
2. clique na aba Debugger e role até o final na janela
3. Marque "External Loader" e clique em scan
4. Por fim ao lado de Scan selecione a plataforma que esta sendo usada, aplique as configurações e feche a janela, ou execute o Debugger como desejado

imagem

Obs.: quando não feito esta configuração, ao executar o código a placa muitas vezes não é reconhecida adequadamente e sugem artefatos na tela assim como a falta de componentes graficos que deveriam estar lá.
