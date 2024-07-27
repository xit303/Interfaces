#pragma once

//******************************************************
// Classes
//******************************************************

class IName
{
private:
    const char *name;

public:
    IName(const char *name) : name(name) {}
    void Name(const char *value) { name = value; }
    const char *Name() { return name; }
};