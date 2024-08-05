#pragma once

//******************************************************
// Includes
//******************************************************

#include <vector>

#include "IBaseClass.h"
#include "ISetting.h"

//******************************************************
// Classes
//******************************************************

class ISettingsGroup : public IBaseClass, public ISetting
{
protected:
    std::vector<ISetting*> settings;

    virtual void OnInit() = 0;
    virtual void OnSetDefault() = 0;
    virtual void OnSave() = 0;
    virtual void Print() {}

public:
    ISettingsGroup(const char* name) : ISetting(name) {}

    virtual bool HasChanged() override
    {
        for(ISetting* setting : settings)
        {
            if (setting->HasChanged())
                return true;
        }
        return false;
    }

    virtual bool SetDefault()
    {
        for(ISetting* setting : settings)
        {
            setting->SetDefault();
        }

        OnSetDefault();

        return true;
    }

    virtual bool Reload()
    {
        for(ISetting* setting : settings)
        {
            setting->Reload();
        }

        return true;
    }

    virtual bool Save()
    {
        for(ISetting* setting : settings)
        {
            setting->Save();
        }

        return true;
    }
};