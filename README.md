# Experimento 03 - SDCard-ADC-UART-LCD
_____________________________________________________________________________________________________________________________________________
**Autores:** Patrick Morás e Fábio Itturriet  
**Data:** 30/07/2021           
**Objetivo:** Esse projeto visa a configuração da plataforma STM32F769NI utilizando alguns dispositivos como cartão de memória MicroSD, FREERTOS e o display LCD da plataforma. O intuito é ler um arquivo do SDcard contendo uma derivação de Eletrocardiograma, os dados então serão plotados em um gráfico e ficará disponivel para visualização na tela da plataforma.                      
**IDE=** STM32CUBE IDE v.1.7.0
**GUI=** TouchGFX v.4.17.0

_____________________________________________________________________________________________________________________________________________

# Esquemático do Experimento

Diagrama geral do projeto


<img src="https://user-images.githubusercontent.com/86391684/139781999-feda3a0a-b3cd-4eda-8291-b645a48a079f.png" width="800" />

Diagrama específico do experimento


<img src="https://user-images.githubusercontent.com/86391684/139778629-7e410274-a83a-47c3-87d7-e035e4c4c57d.png" width="800" />

_____________________________________________________________________________________________________________________________________________

# Abreviações

- GUI: Interface Gráfica de Usuário
- ECG: Eletrocardiograma
- APB: Arquitetura avançada de barramento de microcontrolador
_____________________________________________________________________________________________________________________________________________

# Descrição do Experimento

O experimento tem como fonte do sinal de eletrocardiograma um banco de dados do PhysioNet, o [*MIT-BIH Arrhythmia Database Directory*](https://physionet.org/physiobank/database/html/mitdbdir/mitdbdir.htm) tem um conjunto de registros de ECG de longa duração (entorno de 30 minutos) com diferentes derivações. Nesse exemplo foi utilizado o registro 100, mais especificamente a derivação MLII que basicamente é uma Derivação II modificada, dessa derivação foi extraida com o auxilio do matlab, os 10 primeiros segundos de dados.

## Abrindo arquivos no formato .dat no Matlab

A programação para abrir o arquivo .dat e visualizar os dados no gráfico é vista em [*Open_ECG: ECG .dat file reader*](https://www.mathworks.com/matlabcentral/fileexchange/49822-open_ecg-ecg-dat-file-reader), as principais alterações que podem ser feitas caso necessário é na função 'fread()' onde pode ser alterado a frequência (nesse caso foi utilizado os 360Hz) e em 'Time=' onde registra a janela de tempo que será plotado os dados e também extraidos na sequência. Por fim foi adicionado a função writematrix(Orig_Sig, "NomedoArquivo.txt") na linha 14 do código, esta função salva os dados plotados em um arquivo no formato .txt para ser inserido no cartão de memória posteriomente.

## Iniciando o projeto

Comece pelo [documento de integração](Integração_CubeIDE_TouchGFX.md), assumindo que foi seguido todos os passos temos um projeto criado no touchGFX e aberto no CubeIDE, no "Project Explorer" é possivel ver o arquivo .touchgfx, começaremos abrindo ele para configurar a Interface Gráfica de Usuário (GUI)

## Configuração da GUI

O principal elemento gráfico desse experimento é o gráfico dinâmico, nele que será plotado os dados de ECG, o restante dos elementos podem ser mudados conforme o desejo do usuário, desse modo a explicação atém-se ao gráfico dinámico.

o gráfico foi dispoto do seguinte modo

<img src="https://user-images.githubusercontent.com/86391684/142873314-55cba5e7-04a2-4603-ac84-d2515ac3c818.png" width="750" />

Nele foi deixado uma margem de 50 pixels a esqueda para a legenda sobrando 750 pixels para atualização de dados no gráfico (largura total da tela - margem = 800 - 50). Por questões de desempenho foi escolhido o grafico no modo de desenhar e sobrescrever. Como os dados tem frequência de 360Hz, foi criado uma escala para transformar a legenda em segundos, 1/360 é uma dizima periódica, logo foi arredondado para 0,0028s e a grade tem uma marcação a cada 360 amostras subtituindo por 1 segundo.

<img src="https://user-images.githubusercontent.com/86391684/142873535-022d5dd0-363f-47ac-960c-42ed0cca7fe4.png" width="200" />


## Configuração da CubeIDE (versão 1.0)

Ao gerar o código no TouchGFX pode-se fechar o programa, no CubeIDE o próximo passo é configurar alguns dispositivos e o sistema operacional FREERTOS, basta então acessar o arquivo .ioc em "Project Explorer". 

No MicroSD será inserido um arquivo no formato .txt, a seguir temos a imagem do esquemático do cartão SD

<img src="https://user-images.githubusercontent.com/86391684/127378718-bc18c094-0e21-479a-a403-b7812d42cfb2.png" width="400" />

na parte superior do esquemático temos, além das alimentações, as linhas de comunicação com o conector, essa interface com o cartão SD é dado pelo periférico SDMMC, na parte de baixo da imagem temos o uSD_Detect, linha responsável pela detecção do MicroSD conectado ao slot, uSD_Detect esta conectado ao pino PI15 do MCU e deve ser configurado como GPIO_Input

<img src="https://user-images.githubusercontent.com/86391684/127379861-4ada9714-4355-4e5c-a973-0a2765a3a742.png" width="650" />

A configuração do Conector SD se dá como

  1. Vá até connectivity > SDMMC2 > Mode e selecione *SD 4 bits Wide bus*
  2. Em *configuration* clique na aba *NVIC Settings* e habilite o *SDMMC2 global interrrupt*

<img src="https://user-images.githubusercontent.com/86391684/127430677-a8ef86ef-1941-403d-9603-80e9344ac993.png" width="400" />

  4. Ainda em *SDMMC2 configuration* clique na aba *DMA Settings* e em *Add* e adicione TX e o RX do SDMMC2 no DMA

<img src="https://user-images.githubusercontent.com/86391684/127431076-b5a8be0a-f04e-4ada-a328-5a3538c9f1e6.png" width="400" />

  5. definimos então o pino PI15, de detecção do cartão SD, como entrada (GPIO_Input)
  6. Subsequentemente vá até Middleware > FATFS > em *Mode* marque *SD card*
  7. Em *configuration* clique na aba *Platform Settings*, em Detect_SDIO, selecione o PI15 na coluna *Found Solutions*

<img src="https://user-images.githubusercontent.com/86391684/127433019-51ce4260-dd97-4f6a-807e-8b25e32cc642.png" width="800" />

  8. Na guia *Advanced Settings*, habilete *Use dma template*

<img src="https://user-images.githubusercontent.com/86391684/127433681-ce2c05b3-d2c0-4770-9015-576ebedb3128.png" width="400" />

Em "middleware" vá em FREERTOS > Advanced settings e habilite "USE_NEWLIB_REENTRANT.

<img src="https://user-images.githubusercontent.com/86391684/142874044-5ad8ce4d-ee4f-4730-9dac-e3511fdd0702.png" width="700" />

Por fim, na aba "Clock Configuration", nela queremos abaixar o clock da interface SDMMC2, para isto foi mudada a divisão "/P" do PLL por 8 obtendo 50MHz no PLLQ, em seguida basta selecionar o  "PLL48CLK" no "SDMMC2 Clock Mux" para receber os 50MHz de frequência para a interface SDMMC2.

<img src="https://user-images.githubusercontent.com/86391684/142877007-63d1765d-c2be-49e1-bef5-dc4cda5bb856.png" width="780" />
<img src="https://user-images.githubusercontent.com/86391684/142879418-d6f8e87d-6a44-4dfe-944f-0eba19a9c510.png" width="230" />

Assim finalizamos a configuração da plataforma. Podemos então salvar o projeto e gerar o código inicial, é possivel salvar o projeto atravéz do ícone de disquete :floppy_disk: ou pelo atalho "Ctrl+S" ou pela guia File > Save.

_____________________________________________________________________________________________________________________________________________

# Programação (versão 1.0)

Inicialmente foi definida as variáveis de arquivo FATFS, senguinte foi criado vetores para gerenciamento dos dados juntamente com variáveis auxiliares, foi criado também uma fila de dados. A programação se dá entorno da tarefa padrão 'StartDefaultTask()' criado pelo sistema operacional FREERTOS, nesta tarefa são colocas as funções de manipulação do cartão SD, tendo como objetivo copiar os dados do arquivo .txt colocado na MicroSD. Logo depois foi criado um *loop* para manipulação desses dados onde foi extraido somente os valores de ECG e colocados no vetor 'valor[]'. No *loop* principal da tarefa 'for(;;){}' cada dado de ECG é enviado para uma fila a cada 2.77777 ms.
OBS.: como o tempo do laço de envio dos dados de ECG é uma dízima periódica e, esse tempo foi colocado no 'osDelay' onde é gerenciado por *ticks* de clock, possivelmente o valor está sendo truncado para 2ms ou arredondado para 3ms, será buscado alternativas para contornar isso e se ter a amostragem mais correta possível, qualquer novidade será atualizado aqui.

Na biblioteca 'Model.ccp'é criada a backend da interface gráfica, nela temos o 'Model::tick()', função essa chamada a cada atualização de imagem, nela é visto quantos dados de ECG estão na fila e em seguida atualiza-os no gráfico dinâmico com a função 'UpdateGraph()', essa função é adicionada nas bibliotecas de visualização e apresentação.  
_____________________________________________________________________________________________________________________________________________

# Atualização (versao 2.0)
**Data:** 30/03/2022 
**IDE=** STM32CUBE IDE v.1.9.0
**GUI=** TouchGFX v.4.19.0

_____________________________________________________________________________________________________________________________________________

## Configuração da CubeIDE (versão 2.0)


_____________________________________________________________________________________________________________________________________________
# Programação (versão 1.0)


_____________________________________________________________________________________________________________________________________________
# Conclusão

Seguindo o processo e rodando o código é possível visualizar o ECG sendo plotados em *loop* na tela do microcontrolador, veja a figura a seguir. Alguns ajustes futuros serão considerados, como o ajuste da frequência comentado anteriormente, a legenda do eixo Y deverá ser alterada para termos de tensão, etc.

<img src="https://user-images.githubusercontent.com/86391684/142877669-b5a4694b-8e84-43b2-ade4-f4cf21cbdcb0.jpg" width="750" />

_____________________________________________________________________________________________________________________________________________


# Materiais explicativos (Display LCD)
- **Introdução e integração do Cube IDE com TouchGFX ->**  https://www.youtube.com/watch?v=9QDWti5RzBU  
- **Animação de componentes mexendo direto no código ->**  https://www.youtube.com/watch?v=q4nxEP5bPIc  
- **Treinamento do Chrome-ART ->**  https://st-onlinetraining.s3.amazonaws.com/STM32F7-System_ChromART_DMA2D/index.html 
- **Guia sobre gráfico dinâmico ->** https://support.touchgfx.com/docs/development/ui-development/ui-components/miscellaneous/dynamic-graph
- **Como abrir arquivo de ECG .dat no Matlab ->** https://www.mathworks.com/matlabcentral/fileexchange/49822-open_ecg-ecg-dat-file-reader
- **Descrição dos dados utilizados do PhysioNet ->** https://physionet.org/physiobank/database/html/mitdbdir/intro.htm
