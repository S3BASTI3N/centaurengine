//
// Created by sebastien on 3-2-16.
//

#include <iostream>
#include "DemoInputModule.h"


// Register what functions can be found in this module
void DemoInputModule::getFunctions( std::map<std::string, DemoInputModule> *map) {
    /*
    map->insert(std::make_pair( "SonarLeft", this));
    map->insert(std::make_pair( "SonarRight", this));
    map->insert(std::make_pair( "Say", this));
    map->insert(std::make_pair( "Walk", this));
     */

}


// Call functions by string name that was put in the map in getFunctions()
float DemoInputModule::score(std::string functionName, Context context) {
    //std::cout << "Scoring input function" << std::endl;
    //TODO local map to call functions
    if( functionName == "SonarLeft" ) {
        return sonarLeft(context);
    }
    if( functionName == "SonarRight" ) {
        return sonarRight(context);
    }
    return 0;
}

float DemoInputModule::sonarLeft(Context context) {
    //TODO implement distance of sonar
    return -1;

}

float DemoInputModule::sonarRight(Context context) {
    //TODO implement distance of sonar
    return 1;

}

void DemoInputModule::say( Context context ) {
    std::cout << "saying something" << std::endl;
}

void DemoInputModule::walk( Context context ) {
    std::cout << "walking" << std::endl;
}


void DemoInputModule::execute(std::string functionName, Context context ) {
    //TODO replace with local map

    if( functionName == "Say" ) {
        return say(context);
    }
    if( functionName == "Walk" ) {
        return walk( context );
    }
}
