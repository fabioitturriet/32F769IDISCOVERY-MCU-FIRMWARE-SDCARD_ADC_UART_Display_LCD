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

![Esquemático do experimento](https://user-images.githubusercontent.com/86391684/139781999-feda3a0a-b3cd-4eda-8291-b645a48a079f.png)

Diagrama específico do experimento

![Esquemático do experimento ECG-SDCard-Display](https://user-images.githubusercontent.com/86391684/139778629-7e410274-a83a-47c3-87d7-e035e4c4c57d.png)
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

figura

Nele foi deixado uma margem de 50 pixels a esqueda para a legenda sobrando 750 pixels para atualização de dados no gráfico (largura total da tela - margem = 800 - 50). Por questões de desempenho foi escolhido o grafico no modo de desenhar e sobrescrever. Como os dados tem frequencia de 360Hz, foi criado uma escala para transformar a legenda em segundos, 1/360 é uma dizima periódica, logo foi arredondado para 0,0028s e a grade tem uma marcação a cada 360 amostras subtituindo por 1 segundo.

figura
_____________________________________________________________________________________________________________________________________________

# Materiais explicativos (Display LCD)
- **Introdução e integração do Cube IDE com TouchGFX ->**  https://www.youtube.com/watch?v=9QDWti5RzBU  
- **Animação de componentes mexendo direto no código ->**  https://www.youtube.com/watch?v=q4nxEP5bPIc  
- **Treinamento do Chrome-ART ->**  https://st-onlinetraining.s3.amazonaws.com/STM32F7-System_ChromART_DMA2D/index.html 
- **Guia sobre gráfico dinâmico ->** https://support.touchgfx.com/docs/development/ui-development/ui-components/miscellaneous/dynamic-graph
- **Como abrir arquivo de ECG .dat no Matlab ->** https://www.mathworks.com/matlabcentral/fileexchange/49822-open_ecg-ecg-dat-file-reader
- **Descrição dos dados utilizados do PhysioNet ->** https://physionet.org/physiobank/database/html/mitdbdir/intro.htm
