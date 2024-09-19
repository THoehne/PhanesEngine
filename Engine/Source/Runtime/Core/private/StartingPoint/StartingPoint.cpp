#include "PhanesEnginePCH.h"

#define P_USE_NAMESPACE_ALIAS
#define P_TEST

#include "Core/public/StartingPoint/StartingPoint.h"

static void IdleMsg()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    
    std::cout << "\n\nWelcome to PhanesEngine!" << std::endl << std::endl;
    
    SetConsoleTextAttribute(hConsole, 15);
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "It's silent..." << std::endl << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << "To silent." << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "\nI will go now" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    
    std::cout << "\nGood by!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}




Phanes::Core::Application::PhanesProject::PhanesProject(std::string _ProjectName)
    : projectName(_ProjectName)
{};

Phanes::Core::Application::PhanesProject::~PhanesProject()
{
    this->projectName = "Unnamed Project";
};

std::string Phanes::Core::Application::PhanesProject::GetName()
{
    return this->projectName;
}

void Phanes::Core::Application::PhanesProject::Run()
{
    IdleMsg();
}