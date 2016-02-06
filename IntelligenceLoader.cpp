//
// Created by sebastien on 3-2-16.
//

#include "Include/IntelligenceLoader.h"

IntelligenceLoader::IntelligenceLoader() {

    std::string configFileURL = getConfigurationFileName();

    std::cout << configFileURL << std::endl;

    intelligence = loadConfiguration(configFileURL );

}

std::string IntelligenceLoader::getConfigurationFileName() {

    // Get which config to use from default
    tinyxml2::XMLDocument defaultConfig;
    //TODO change to relative path, or argv or something
    std::string baseURL = "/home/sebastien/ClionProjects/CentaurEngine/Config/";
    defaultConfig.LoadFile((baseURL + "settings.xml").c_str());

    if( defaultConfig.Error()) {
        std::cerr << "XMLERROR: " << defaultConfig.ErrorName() << std::endl;
        std::cerr << "Looked for: " << baseURL << std::endl;

        exit(-1);
    }

    tinyxml2::XMLElement* configName = defaultConfig.FirstChildElement("configuration")->FirstChildElement("config_file");
    if( defaultConfig.Error()) { std::cerr << "XMLERROR: " << defaultConfig.ErrorName() << std::endl; exit(-1); }
    //std::cout << "Using: " << configName->GetText() << std::endl;

    return (baseURL+configName->GetText()).c_str();

}


Intelligence IntelligenceLoader::loadConfiguration(std::string configFileURL) {

    // Load config
    std::cout << "Loading config" << std::endl;
    tinyxml2::XMLDocument config;
    config.LoadFile(configFileURL.c_str());
    if( config.Error()) {std::cout << "XMLERROR: " << config.ErrorName() << std::endl;exit(-1);}
    std::string version = config.FirstChildElement("configuration")->FirstChildElement("version")->GetText();
    std::cout << "Version: " << version << std::endl;

    // Load input and output modules
    std::cout << "Loading modules" << std::endl;
    std::vector<std::string> inModules  = getModules(&config, "in_modules");
    std::vector<std::string> outModules = getModules(&config, "out_modules");
    /*
    // Load functions from modules
    std::cout << "Loading functions" << std::endl;
    std::vector<std::shared_ptr<ModuleInterface>> loadedModules;
    auto inputMap = getScriptMap(inModules, &loadedModules );
    auto outputMap = getScriptMap(outModules, &loadedModules );
     */

    // Let the hacking begin
    DemoInputModule inputModule;
    //auto inputMap = getScriptMap(inModules, &loadedModules );

    // Load decisions
    std::cout << "Loading decisions and considerations" << std::endl;
    auto decisions = loadDecisions(&config, inputModule, inputModule );

    std::cout << "Done" << std::endl;

    return Intelligence(decisions, inputModule);

}

std::vector<std::string> IntelligenceLoader::getModules( tinyxml2::XMLDocument *config, const char *moduleType ) {
    tinyxml2::XMLNode* module = config->FirstChildElement("configuration")->FirstChildElement(moduleType)->FirstChild();
    tinyxml2::XMLNode*lastModule = config->FirstChildElement("configuration")->FirstChildElement(moduleType)->LastChild();
    if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;exit(-1);}
    std::vector<std::string> moduleNames;

    do {
        if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;break;}
        std::string name = module->FirstChild()->Value();
        std::cout << "Found module: " << name << std::endl;
        moduleNames.insert(moduleNames.end(), name);

        if(module->FirstChild()->Value() == lastModule->FirstChild()->Value() ) {
            std::cout << "No More modules" << std::endl;
            break;
        }
        module = module->NextSibling();
    } while( true );

    return moduleNames;
}

/*

Intelligence::functionMap IntelligenceLoader::getScriptMap(std::vector<std::string> modules, std::vector<std::shared_ptr<ModuleInterface>>* loadedModules ) {

    Intelligence::functionMap theFunctionMap;

    //TODO rewrite to actually dynamically load modules
    for( auto moduleName : modules ) {
        if( moduleName == "DemoInputModule" ) {
            auto module = std::make_shared<DemoInputModule>();
            loadedModules->push_back(module);
            module->getFunctions(&theFunctionMap);
            continue;
        }
        if( moduleName == "DemoOutputModule" ) {
            auto module = std::make_shared<DemoInputModule>();
            loadedModules->push_back(module);
            module->getFunctions(&theFunctionMap);
            continue;
        }
    }

    return theFunctionMap;
}

 */

std::vector<Decision> IntelligenceLoader::loadDecisions( tinyxml2::XMLDocument *config,
                                                         DemoInputModule input,
                                                         DemoInputModule output) {

    // Get first decision
    tinyxml2::XMLNode *currentDecision = config->FirstChildElement("configuration")->FirstChildElement("decisions")->FirstChild();

    // Get last decision
    tinyxml2::XMLNode *endDecision = config->FirstChildElement("configuration")->FirstChildElement("decisions")->LastChild();

    // Check for errors
    if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;exit(-1);}

    std::vector<Decision> decisions;

    // Loop over decisions
    do {
        if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;break;}
        std::string name = currentDecision->FirstChildElement("name")->GetText();
        std::string description = currentDecision->FirstChildElement("description")->GetText();
        std::string priority = currentDecision->FirstChildElement("priority")->GetText();

        std::cout << "Decision: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "priority: " << priority << std::endl;

        tinyxml2::XMLNode *currentConsideration = currentDecision->FirstChildElement("considerations")->FirstChild();
        tinyxml2::XMLNode *endConsideration = currentDecision->FirstChildElement("considerations")->LastChild();

        std::vector<Consideration> considerations;

        // Loop over considerations
        do {
            if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;break;}

            std::string curveType = currentConsideration->FirstChildElement("curve")->FirstChildElement("type")->GetText();
            std::cout << "  Curve type: " << curveType << std::endl;

            tinyxml2::XMLNode *currentCurveSetting = currentConsideration->FirstChildElement("curve")->FirstChildElement("curve_params")->FirstChild();
            tinyxml2::XMLNode *endCurveSetting = currentConsideration->FirstChildElement("curve")->FirstChildElement("curve_params")->LastChild();


            std::vector<std::string> curveParams;
            do {
                if( config->Error()) {std::cout << "XMLERROR: " << config->ErrorName() << std::endl;break;}

                std::string curveParam = currentCurveSetting->FirstChild()->ToText()->Value();

                std::cout << "    Param: " << curveParam << std::endl;

                curveParams.push_back( curveParam );

                if( currentCurveSetting == endCurveSetting ) break;
                currentCurveSetting = currentCurveSetting->NextSibling();
            } while( true );



            std::string inputName = currentConsideration->FirstChildElement("input")->FirstChildElement("name")->GetText();
            std::string inputMin = currentConsideration->FirstChildElement("input")->FirstChildElement("min")->GetText();
            std::string inputMax = currentConsideration->FirstChildElement("input")->FirstChildElement("max")->GetText();

            std::cout << "  Input name: " << inputName << std::endl;
            std::cout << "    Input min: " << inputMin << std::endl;
            std::cout << "    Input max: " << inputMax << std::endl;

            //HACK
            /*
            auto modulePair = inputMap.find(inputName);

            if( modulePair == inputMap.end()) {
                std::cout << "INPUT FUNCTION " << inputName << " NOT FOUND" << std::endl;
            }
             */

            Consideration consideration = Consideration( curveType, curveParams, input, inputName, inputMin, inputMax );

            considerations.push_back(consideration);

            if( currentConsideration == endConsideration ) break;
            currentConsideration = currentConsideration->NextSibling();

        } while( true );

        Decision decision = Decision(name, description, considerations);

        decisions.push_back(decision);

        if(currentDecision->FirstChild()->Value() == endDecision->FirstChild()->Value() ) break;
        currentDecision = currentDecision->NextSibling();


    } while( true );

    return decisions;

}


