#include "Core/Logging/Logging.h"

void Phanes::Core::Logging::Init()
{
  spdlog::set_pattern("%^[%n][%T][%l]:%$ %v");

  _PEngineLogger = spdlog::stdout_color_mt("PHANES");
  _PEngineLogger->set_level(spdlog::level::trace);

  _PAppLogger = spdlog::stdout_color_mt("GAME");
  _PAppLogger->set_level(spdlog::level::trace);
}