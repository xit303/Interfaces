#pragma once

//******************************************************
// Includes
//******************************************************

#include "IBaseClass.h"

//******************************************************
// Classes
//******************************************************

class ISettingsBase : public IBaseClass
{
protected:
    const char* name;

    virtual void OnInit() = 0;
    virtual void OnSetDefault() = 0;
    virtual void OnReload() = 0;
    virtual void OnSave() = 0;
    virtual void Print() {};

public:
    ISettingsBase(const char* name) : name(name) {}

    virtual bool HasChanged() = 0;
    virtual bool SetDefault() = 0;
    virtual bool Reload() = 0;
    virtual bool Save() = 0;
};