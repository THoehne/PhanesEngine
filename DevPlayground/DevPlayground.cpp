
#include <PhanesEngine.h>


class DevPlayground : public Phanes::Core::Application::PhanesGame {};



Phanes::Core::Application::PhanesGame* Phanes::Core::Application::CreatePhanesGame()
{
	return new DevPlayground();
}