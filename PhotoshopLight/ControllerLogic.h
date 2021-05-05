#pragma once

#include <vector>

class ControllerLogic final
{
public:
	ControllerLogic();
	~ControllerLogic() = default;

	void increaseFiltr();
	void reduceFiltr();

	void increasePicture();
	void reducePicture();

	size_t  getcurrentFiltr() const {return currentFiltr;};
	size_t  getcurrentPicture() const {return currentPicture;};

private:

    size_t  currentFiltr   = 1;
    size_t  currentPicture = 1;

};
