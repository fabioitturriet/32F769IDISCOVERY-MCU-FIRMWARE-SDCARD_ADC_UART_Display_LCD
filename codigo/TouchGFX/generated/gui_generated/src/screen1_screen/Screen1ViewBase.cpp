/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(20, 48, 89));

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_ECG_ID));
    scalableImage1.setPosition(136, 59, 518, 262);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage2.setBitmap(touchgfx::Bitmap(BITMAP_PNGWING_COM_ID));
    scalableImage2.setPosition(577, 167, 87, 81);
    scalableImage2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    textArea1.setXY(192, 129);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AIU2));

    scalableImage3.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_ID));
    scalableImage3.setPosition(400, 8, 381, 88);
    scalableImage3.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage4.setBitmap(touchgfx::Bitmap(BITMAP_VERSAOHORIZONTAL1_ID));
    scalableImage4.setPosition(13, 14, 359, 82);
    scalableImage4.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    buttonWithLabel1.setXY(315, 355);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_C5EN));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);

    add(__background);
    add(box1);
    add(scalableImage1);
    add(scalableImage2);
    add(textArea1);
    add(scalableImage3);
    add(scalableImage4);
    add(buttonWithLabel1);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenSlideTransitionEast();
    }
}