#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
void Screen3View::UpdateGraph(uint16_t value)
{
	dynamicGraph1.addDataPoint(value); //adiciona o valor em um ponto no gráfico
}
