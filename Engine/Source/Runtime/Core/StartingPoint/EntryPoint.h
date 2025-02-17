#pragma once
// Entry point for Phanes game 

#if defined(P_LINUX_BUILD)

extern Phanes::Core::Application::PhanesProject* Phanes::Core::Application::CreatePhanesGame();

int main(int argc, char** argv)
{
  Phanes::Core::Logging::Init();
  PENGINE_LOG_INFO("Logger initialized!");
  PENGINE_LOG_INFO("Welcome to PhanesEngine!");


  auto phanes_game = Phanes::Core::Application::CreatePhanesGame();
  
  PENGINE_LOG_INFO("Loading project {0}...", phanes_game->GetName());

  phanes_game->Run();

  delete phanes_game;

  return 0;
}

#endif