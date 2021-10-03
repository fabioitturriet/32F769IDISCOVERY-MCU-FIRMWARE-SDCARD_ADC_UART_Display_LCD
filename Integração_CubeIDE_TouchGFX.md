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

<img src="https://user-images.githubusercontent.com/86391684/135736238-37621922-3e7a-4cc6-bba4-b393aaa52313.png" width="800" />

Gerado o código pelo touchGFX Designer podemos fechar o programa
_________________________________________________________________________________________________________________________________________________________________________________

# Renomeando o projeto 

Para que o projeto no cubeIDE fique com o mesmo nome do projeto criado no Touch GFX é preciso fazer alguns ajustes em alguns arquivos. Vá até a pasta do projeto criado

<img src="https://user-images.githubusercontent.com/86391684/135736248-35a15112-b001-4f8f-beb8-1f976fe59298.png" width="800" />

como é visto o nome do arquivo .ioc é o nome da plataforma escolhida STM32F769I_DISCO, começamos renomeando este aquivo (esse nome deverá se manter igual nas próximas alterações), foi escolhido o mesmo nome colocado no projeto anteriomente "Teste_tela"

<img src="https://user-images.githubusercontent.com/86391684/135736250-b44371e7-70fd-42f5-9647-7eac772b7044.png" width="800" />

os proximos arquivos serão alterados usando o Visual Studio code. Na pasta TouchGFX selecione o executável "ApplicationTemplate"  e aperte "abrir com Code" 

<img src="https://user-images.githubusercontent.com/86391684/135736252-87233dda-ad3a-400f-b5ea-ed31ecefcb94.png" width="600" />

logo nas linhas iniciais no Visual Studio (VS) temos o código "Name" e logo em seguida o nome do projeto (nome da plataforma como ja comentado). Selecione e copie o nome do projeto

<img src="https://user-images.githubusercontent.com/86391684/135736255-cc82e7b2-5d13-41b9-9a5a-4fed8d05d6de.png" width="600" />

vá na aba "editar" do VS e clique na opção "substituir", sera aberto uma janela com o nome do projeto preenchido na área superior, na área de texto inferior coloque nome que se deseja ter no projeto (mesmo nome colocado no arquivo .ioc anteriormente) e aperte em "substituir tudo"

<img src="https://user-images.githubusercontent.com/86391684/135736258-dfc4ddb4-ab9f-4212-b758-66a723d345f8.png" width="600" />

os próximos arquivos a serem editados podem ser arrastados diretamente para o VS da pasta do TouchGFX. O próximo arquivo a ser editado é o segundo executável que teve o nome dado dentro do programa

<img src="https://user-images.githubusercontent.com/86391684/135736261-c3585065-cf6b-4da4-811e-4b7f94473966.png" width="800" />
clique e arraste o arquivo

Na pasta anterior a essa, entre em STM32CubeIDE e oo arquivos ".cproject" e ".project" também devem ser alterados.

<img src="https://user-images.githubusercontent.com/86391684/135736264-03bd77d4-4190-48d4-83cf-aa7ac7556035.png" width="800" />
clique e arraste os arquivos

No VS faça o mesmo processo de subtituição, agora clicando direto em "substituir tudo" em cada um dos códigos. Por fim vá na guia arquivo e clique em "Salvar tudo"

_________________________________________________________________________________________________________________________________________________________________________________

# Importando o Projeto do TouchGFX no CubeIDE

Execute o STM32CubeIDE para importar o projeto

**Importante**: Ao selecionar o espaço de trabalho do CubeIDE, prefira por caminhos sem espaço pois podem gerar comflitos 
1. No CubeIDE vá atá a aba File > Import...
2. Selecione Existing Projects into Workspace > Next
3. Selecione Select root diretory > clique em browse... e selecione a pasta do projeto criado no touchGFX
4. Na área de "Projects:" será reconhecido o diretório do projeto para o STMCube, marque-o e clique em "Finish" 

<img src="https://user-images.githubusercontent.com/86391684/135736267-3fa27dcf-be6a-4530-99ce-b5eca54fbfd7.png" width="500" />

Por ora, a integração esta completa, mas é interessante fazer algumas alterações para facilitar a manipulação do projeto. Para se ter um acesso direto ao arquivo do projeto da tela no cubeIDE, basta ir até a pasta do TouchGFX, dentro da pasta do projeto criado, clicar e segurar no executável do projeto, arrasta-lo para o cubeIDE e soltá-lo no projeto impotado na aba "Project Explorer"

<img src="https://user-images.githubusercontent.com/86391684/135736270-9d54e278-52f9-4b11-80fc-aa89d4a60d7f.png" width="800" />

Selecione "Link to files" e clique em "OK"

<img src="https://user-images.githubusercontent.com/86391684/135736271-27ffa1ef-d55a-49c8-b855-ab476a97129e.png" width="450" />

dessa maneira o executável do TouchGFX fica de fácil acesso para fazer alterações.

_________________________________________________________________________________________________________________________________________________________________________________

# Configuração do Debugger

Antes de executar o código na plataforma deve configurar o Debugger. Com a plataforma conectada:

1. Execute o CubeIDE e vá na guia Run > Debugger configuration...
2. clique na aba Debugger e role até o final na janela
3. Marque "External Loader" e clique em scan
4. Por fim ao lado de Scan selecione a plataforma que esta sendo usada, aplique as configurações e feche a janela, ou execute o Debugger como desejado

<img src="https://user-images.githubusercontent.com/86391684/135736275-207002f9-3ebe-4645-a1b5-71557c78466e.png" width="800" />

Obs.: quando não feito esta configuração, ao executar o código a placa muitas vezes não é reconhecida adequadamente e sugem artefatos na tela assim como a falta de componentes graficos que deveriam estar lá.
