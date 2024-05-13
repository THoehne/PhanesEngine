#pragma once
// Entry point for Phanes game 

#ifdef P_WIN_BUILD

extern Phanes::Core::Application::PhanesGame* Phanes::Core::Application::CreatePhanesGame();

int main(int argc, char** argv)
{
	auto phanes_game = Phanes::Core::Application::CreatePhanesGame();

	phanes_game->Run();

	delete phanes_game;
}

#endif