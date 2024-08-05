#pragma once

//******************************************************
// Includes
//******************************************************

#include "IName.h"

//******************************************************
// Classes
//******************************************************

class ISetting : public IName
{
public:
    ISetting(const char* name) : IName(name) {}
    
    virtual bool HasChanged() = 0;
    virtual bool SetDefault() = 0;
    virtual bool Reload() = 0;
    virtual bool Save(bool forceSave = false) = 0;
};