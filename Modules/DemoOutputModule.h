//
// Created by sebastien on 3-2-16.
//

#pragma once

#include "../Include/ModuleInterface.h"

class DemoOutputModule : public ModuleInterface {

    void getFunctions(std::map<std::string, DemoInputModule> *map);

    void say(Context context);

    void execute(std::string functionName, Context context);

    void walk(Context context);

    float score(std::string functionName, Context context);
};
