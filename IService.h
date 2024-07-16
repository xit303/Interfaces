#pragma once

//******************************************************
// Includes
//******************************************************

//******************************************************
// Classes
//******************************************************

class IService
{
protected:
    virtual void TaskFunction() = 0;

public:
    virtual bool Start() const = 0;
    virtual bool Stop() const = 0;
};