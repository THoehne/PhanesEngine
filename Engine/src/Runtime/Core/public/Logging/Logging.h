#pragma once

#include "PhanesEnginePCH.h"

#include "Core/Core.h"

#ifndef P_DEBUG
#pragma warning(disable : 4251) // Disable STL dll export warning
#endif

namespace Phanes::Core::Logging
{
	static std::shared_ptr<spdlog::logger> _PEngineLogger;
	static std::shared_ptr<spdlog::logger> _PAppLogger;

	PHANES_CORE void Init();

	PHANES_CORE inline std::shared_ptr<spdlog::logger>& PEngineLogger() { return _PEngineLogger; };
	PHANES_CORE inline std::shared_ptr<spdlog::logger>& PGameLogger() { return _PAppLogger; };
}


namespace PLog = Phanes::Core::Logging; // User Macros 

#ifdef P_DEBUG

// Default logger

#define PENGINE_LOG_TRACE(...)			::Phanes::Core::Logging::PEngineLogger()->trace(__VA_ARGS__)
#define PENGINE_LOG_INFO(...)				::Phanes::Core::Logging::PEngineLogger()->info(__VA_ARGS__)
#define PENGINE_LOG_WARN(...)				::Phanes::Core::Logging::PEngineLogger()->warn(__VA_ARGS__)
#define PENGINE_LOG_ERROR(...)			::Phanes::Core::Logging::PEngineLogger()->error(__VA_ARGS__)
#define PENGINE_LOG_FATAL(...)			::Phanes::Core::Logging::PEngineLogger()->fatal(__VA_ARGS__)


#define PAPP_LOG_TRACE(...)			::Phanes::Core::Logging::PAppLogger()->trace(__VA_ARGS__)
#define PAPP_LOG_INFO(...)			::Phanes::Core::Logging::PAppLogger()->info(__VA_ARGS__)
#define PAPP_LOG_WARN(...)			::Phanes::Core::Logging::PAppLogger()->warn(__VA_ARGS__)
#define PAPP_LOG_ERROR(...)			::Phanes::Core::Logging::PAppLogger()->error(__VA_ARGS__)
#define PAPP_LOG_FATAL(...)			::Phanes::Core::Logging::PAppLogger()->fatal(__VA_ARGS__)

#else 

#define PENGINE_LOG_TRACE(...)
#define PENGINE_LOG_INFO(...)
#define PENGINE_LOG_WARN(...)
#define PENGINE_LOG_ERROR(...)
#define PENGINE_LOG_FATAL(...)


#define PAPP_LOG_TRACE(...)	
#define PAPP_LOG_INFO(...)	
#define PAPP_LOG_WARN(...)	
#define PAPP_LOG_ERROR(...)	
#define PAPP_LOG_FATAL(...)	

#endif
