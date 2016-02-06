//
// Created by sebastien on 3-2-16.
//

#ifndef CENTAURENGINE_INTELLIGENCELOADER_H
#define CENTAURENGINE_INTELLIGENCELOADER_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Intelligence.h"
#include "../External/tinyxml2.h"


class IntelligenceLoader {


public:
    IntelligenceLoader();


private:
public:
    const Intelligence &getIntelligence() const {
        return intelligence;
    }

private:
    Intelligence intelligence;

    std::vector<std::string> getModules(tinyxml2::XMLDocument *config, const char *moduleType);
    std::string getConfigurationFileName();
    Intelligence loadConfiguration(std::string configFileURL);

    std::vector<Decision> loadDecisions(tinyxml2::XMLDocument *config, DemoInputModule input,
                                        DemoInputModule output);

    std::map<std::string, DemoInputModule> getScriptMap(std::vector<std::string> modules,
                                              std::vector<std::shared_ptr<ModuleInterface>> *loadedModules);
};


#endif //CENTAURENGINE_INTELLIGENCELOADER_H
