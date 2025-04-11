#pragma once
#include "FF_Test.h"

class Base2
{
private:
    float x;

public:
    friend void FF_Test::FuntionFriend(Base2& b);
};

