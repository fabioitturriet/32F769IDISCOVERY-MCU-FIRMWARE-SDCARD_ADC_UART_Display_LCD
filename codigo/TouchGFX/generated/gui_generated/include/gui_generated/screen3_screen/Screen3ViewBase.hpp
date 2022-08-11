/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN3VIEWBASE_HPP
#define SCREEN3VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>

class Screen3ViewBase : public touchgfx::View<Screen3Presenter>
{
public:
    Screen3ViewBase();
    virtual ~Screen3ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::GraphWrapAndClear<750> dynamicGraph1;
    touchgfx::GraphElementLine dynamicGraph1Line1;
    touchgfx::PainterRGB565 dynamicGraph1Line1Painter;
    touchgfx::GraphElementGridX dynamicGraph1MinorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph1MinorYAxisGrid;
    touchgfx::GraphElementGridX dynamicGraph1MajorXAxisGrid;
    touchgfx::GraphElementGridY dynamicGraph1MajorYAxisGrid;
    touchgfx::GraphLabelsX dynamicGraph1MajorXAxisLabel;
    touchgfx::GraphLabelsY dynamicGraph1MajorYAxisLabel;
    touchgfx::ButtonWithLabel buttonWithLabel1;
    touchgfx::ScalableImage scalableImage1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen3ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREEN3VIEWBASE_HPP
