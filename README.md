# Interfaces

This is the repo for all my base interfaces.

`IBaseClass` is an interface for all classes which have to implement `Init` and `Update` methods.<br>
`ISettingsBase` is an interface which helps us to handle groups of settings. For details about this please have a look at my [ESPSystem](https://github.com/xit303/ESPSystem.git) repository.

Using `IBaseClass` will force us to generate the correct structure over and over again for classes which have to `Init` and `Update` things (like Arduinos begin() and loop() functions). If we use this everywhere where we have to initialize and update different parts we can do cool stuff like this.

Create a first class:

```
#include "IBaseClass.h"

class FirstClass : public IBaseClass
{
public:
    virtual bool Init() override {}
    virtual void Update() override {}
};
```

Create a second class:

```
class SecondClass : public IBaseClass
{
public:
    virtual bool Init() override {}
    virtual void Update() override {}
};
```

Create a class that will do the whole work for us:

```
#include <vector>

class Board : public IBaseClass
{
private:
    // storage to hold IBaseClass pointers
    std::vector<IBaseClass*> myClasses;

public:
    virtual bool Init() override
    {
        for (IBaseClass* baseClass : myClasses)
        {
            baseClass->Init();
        }
    }

    virtual void Update() override
    {
        for (IBaseClass* baseClass : myClasses)
        {
            baseClass->Update();
        }
    }

    void Add(IBaseClass* baseClass)
    {
        myClasses.push_back(base_class);
    }
};

```

Finally use it

```
int main(void)
{
    FirstClass firstClass;
    SecondClass secondClass;
    Board board;

    board.Add(&firstClass);
    board.Add(&secondClass);

    // this will init all at once
    board.Init();

    // as long as we tell the truth
    while(true)
    {
        // this will update all at once
        board.Update();
    }

    return 0;
}

```

Got improvements? Let me know :)