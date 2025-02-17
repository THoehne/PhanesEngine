#include "Core/Logging/Logging.h"

namespace Phanes::Core::Logging
{
  std::shared_ptr<spdlog::logger> Logger::_PEngineLogger;
  std::shared_ptr<spdlog::logger> Logger::_PAppLogger;
} // namespace Phanes::Core::Logging


void Phanes::Core::Logging::Logger::Init()
{
  spdlog::set_pattern("%^[%n][%T][%l]:%$ %v");

  _PEngineLogger = spdlog::stdout_color_mt("PHANES");
  _PEngineLogger->set_level(spdlog::level::trace);

  _PAppLogger = spdlog::stdout_color_mt("GAME");
  _PAppLogger->set_level(spdlog::level::trace);
}