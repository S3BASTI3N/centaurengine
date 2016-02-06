//
// Created by sebastien on 3-2-16.
//

#ifndef CENTAURENGINE_DEMOINPUTMODULE_H
#define CENTAURENGINE_DEMOINPUTMODULE_H


#include <map>
#include "../Include/Context.h"
#include "../Include/ModuleInterface.h"

class DemoInputModule : public ModuleInterface {

public:
    void getFunctions( std::map<std::string, DemoInputModule> *map);
    float score(std::string functionName, Context context);

private:
    float sonarRight(Context context);
    float sonarLeft(Context context);

    void execute(std::string functionName, Context context);

    void say(Context context);

    void walk(Context context);
};

#endif //CENTAURENGINE_DEMOINPUTMODULE_H