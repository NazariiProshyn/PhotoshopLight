#include "ControllerLogic.h"

namespace NSFiltrs
{
     const size_t numberOfFiltrs   = 3;
     const size_t numberOfPictures = 2;
     const size_t minNumberInMenu  = 1;
};


ControllerLogic::ControllerLogic()
{

}

void ControllerLogic::increaseFiltr()
{
    if (currentFiltr == NSFiltrs::numberOfFiltrs)
    {
        currentFiltr = NSFiltrs::minNumberInMenu;
    }
    else
    {
        ++currentFiltr;
    }
}

void ControllerLogic::reduceFiltr()
{
    if (currentFiltr == NSFiltrs::minNumberInMenu)
    {
        currentFiltr = NSFiltrs::numberOfFiltrs;
    }
    else
    {
        --currentFiltr;
    }
}

void ControllerLogic::increasePicture()
{
    if (currentPicture == NSFiltrs::numberOfPictures)
    {
        currentPicture = NSFiltrs::minNumberInMenu;
    }
    else
    {
        ++currentPicture;
    }
}

void ControllerLogic::reducePicture()
{
    if (currentPicture == NSFiltrs::minNumberInMenu)
    {
        currentPicture = NSFiltrs::numberOfPictures;
    }
    else
    {
        --currentPicture;
    }
}

