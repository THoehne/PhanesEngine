#include "Core/StartingPoint/StartingPoint.h"
#include "Core/Logging/Logging.h"

static void IdleMsg()
{
    std::cout << "\nWelcome to PhanesEngine!\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "It's silent...\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << "To silent.\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "I will go now\n";
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    
    std::cout << "Good by!\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}


Phanes::Core::Application::PhanesProject::PhanesProject(std::string _ProjectName)
    : projectName(_ProjectName)
{
    PAPP_LOG_INFO("Loading project: {0}", this->GetName());    
};

Phanes::Core::Application::PhanesProject::~PhanesProject()
{
    PAPP_LOG_INFO("Unloading project: {0}", this->GetName());
};

std::string Phanes::Core::Application::PhanesProject::GetName()
{
    return this->projectName;
}

void Phanes::Core::Application::PhanesProject::Run()
{
    IdleMsg();
}