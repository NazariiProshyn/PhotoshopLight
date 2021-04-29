#pragma once


class ControllerLogic final
{
public:
	ControllerLogic();
	~ControllerLogic() = default;

private:
    static const int numberOfFiltrs   = 3;
    unsigned     int currentFiltr     = 1;

    static const int numberOfPictures = 2;
    unsigned     int currentPicture   = 1;

};
