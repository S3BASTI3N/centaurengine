//
// Created by sebastien on 3-2-16.
//

#include <iostream>
#include "DemoOutputModule.h"

/*
void DemoOutputModule::getFunctions(std::map<std::string, DemoInputModule> *map) {

    map->insert(std::make_pair( "Say", this));
    map->insert(std::make_pair( "Walk", this));

}
*/

void DemoOutputModule::execute(std::string functionName, Context context ) {
    if( functionName == "Say" ) {
        return say(context);
    }
    if( functionName == "Walk" ) {
        return walk(context);
    }
}

void DemoOutputModule::say( Context context ) {
    std::cout << "saying something" << std::endl;
}

void DemoOutputModule::walk( Context context ) {
    std::cout << "walking" << std::endl;
}

float DemoOutputModule::score(std::string functionName, Context context ) {
    return 0;
}
