//
// Created by sebastien on 3-2-16.
//

#ifndef CENTAURENGINE_MODULEINTERFACE_H
#define CENTAURENGINE_MODULEINTERFACE_H

#include <string>
#include <map>
#include "../Include/Context.h"

class DemoInputModule;


class ModuleInterface {

public:

    virtual void getFunctions(std::map<std::string, DemoInputModule> *map)=0;
    virtual float score(std::string functionName, Context context )=0;
    virtual void execute(std::string functionName, Context context )=0;

};


#endif //CENTAURENGINE_MODULEINTERFACE_H
