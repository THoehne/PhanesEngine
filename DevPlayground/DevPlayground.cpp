#define P_USE_NAMESPACE_ALIAS


#include "Phanes.h"

class DevPlayground : public PApp::PhanesProject 
{
    using PhanesProject::PhanesProject;
};


PApp::PhanesProject* PApp::CreatePhanesGame()
{
    return new DevPlayground("DevPlayground");
}