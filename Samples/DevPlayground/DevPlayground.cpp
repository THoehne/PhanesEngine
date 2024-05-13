#include <Phanes.h>

using namespace Phanes::Core::Math;

class DevPlayground : public Phanes::Core::Application::PhanesGame {};


Phanes::Core::Application::PhanesGame* Phanes::Core::Application::CreatePhanesGame()
{
  return new DevPlayground();
}