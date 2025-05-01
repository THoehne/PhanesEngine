#include "Core/Include.h"

#if defined(P_LINUX_BUILD)

extern Phanes::Core::Application::PhanesProject* Phanes::Core::Application::CreatePhanesGame();

int main()
{
	Phanes::Core::Logging::Logger::Init();
	PENGINE_LOG_INFO("Logger initialized!");
	PENGINE_LOG_INFO("Welcome to PhanesEngine!");

	auto* phanes_game = Phanes::Core::Application::CreatePhanesGame();

	phanes_game->Run();

	delete phanes_game;

	return 0;
}

#endif
