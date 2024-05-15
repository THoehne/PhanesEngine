#define P_USE_NAMESPACE_ALIAS
#include <Phanes.h>

class DevPlayground : public PApp::PhanesGame {};


PApp::PhanesGame* PApp::CreatePhanesGame()
{
  return new DevPlayground();
}