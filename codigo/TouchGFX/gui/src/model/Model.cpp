#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32f7xx_hal.h"
#include "FreeRTOS.h"
#include "queue.h"

uint16_t dado;
 int espaco, count;

 extern "C"
 {
 	 xQueueHandle messageQ;//define a fila criada no main.c
 }
Model::Model() : modelListener(0)
{
	messageQ = xQueueCreate(50, sizeof (uint16_t)); //cria uma fila com 50 valores de espaço
}

void Model::tick()
{
	espaco = uxQueueSpacesAvailable(messageQ);//cada atualização da tela pega o valor de espaço livre na fila
	espaco = 50 - espaco; //tespaço usado na fila

	for (count=0; count<espaco; count++){//repete até desocupar a fila

	xQueueReceive(messageQ, &dado, 0);//pega um dado da fila
	modelListener->UpdateGraph(dado-870);//atualiza o grafico com o dado

	}
}
