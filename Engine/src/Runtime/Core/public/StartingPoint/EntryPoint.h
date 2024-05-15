#pragma once
// Entry point for Phanes game 

#if defined(P_WIN_BUILD) && defined(P_BUILD_LIB)

extern Phanes::Core::Application::PhanesGame* Phanes::Core::Application::CreatePhanesGame();

int main(int argc, char** argv)
{
  auto phanes_game = Phanes::Core::Application::CreatePhanesGame();

  phanes_game->Run();

  delete phanes_game;
}

#endif