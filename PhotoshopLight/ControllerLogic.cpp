#include "ControllerLogic.h"

ControllerLogic::ControllerLogic()
{

}

void ControllerLogic::increaseFiltr()
{
    if(currentFiltr == numberOfFiltrs)
    {
        currentFiltr = 1;
    }
    else
    {
        ++currentFiltr;
    }
}

void ControllerLogic::reduceFiltr()
{
    if(currentFiltr == 1)
    {
        currentFiltr = numberOfFiltrs;
    }
    else
    {
        --currentFiltr;
    }
}

void ControllerLogic::increasePicture()
{
    if(currentPicture == numberOfPictures)
    {
        currentPicture = 1;
    }
    else
    {
        ++currentPicture;
    }
}

void ControllerLogic::reducePicture()
{
    if(currentPicture == 1)
    {
        currentPicture = numberOfPictures;
    }
    else
    {
        ++currentPicture;
    }
}

