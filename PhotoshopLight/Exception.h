#pragma once

#include <string>
#include <iostream>
#include <stdexcept>


class PhotoshipException final
:public std::exception
{
public:
    PhotoshipException(std::string msg):std::exception()
    {
        path = msg;
    };

    std::string getErrorMsg(){ return err+path; }

private:
    std::string path;
    std::string err = "Unable to open or find file: ";

};
