#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}
void Screen3Presenter::UpdateGraph(uint16_t value)
{
	view.UpdateGraph(value); //atualiza o gráfico com o valor
}
