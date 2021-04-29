#pragma once


class ControllerLogic final
{
public:
	ControllerLogic();
	~ControllerLogic() = default;

	void increaseFiltr();
	void reduceFiltr();

	void increasePicture();
	void reducePicture();

	int  getcurrentFiltr() const {return currentFiltr;};
	int  getcurrentPicture() const {return currentPicture;};

private:
    static const int numberOfFiltrs   = 3;
    unsigned     int currentFiltr     = 1;

    static const int numberOfPictures = 2;
    unsigned     int currentPicture   = 1;

};
