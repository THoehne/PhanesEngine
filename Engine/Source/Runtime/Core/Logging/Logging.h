#pragma once


#include "Core/Logging/LoggingPCH.h"
#include "Core/Core.h"

namespace Phanes::Core::Logging
{
	static Phanes::Ref<spdlog::logger> _PEngineLogger;
	static Phanes::Ref<spdlog::logger> _PAppLogger;

	void Init();

	inline std::shared_ptr<spdlog::logger>& PEngineLogger() { return _PEngineLogger; };
	inline std::shared_ptr<spdlog::logger>& PAppLogger() { return _PAppLogger; };
}


namespace PLog = Phanes::Core::Logging; // User Macros 

#ifdef P_DEBUG

// Default logger

#define PENGINE_LOG_TRACE(...)			::Phanes::Core::Logging::PEngineLogger()->trace(__VA_ARGS__)
#define PENGINE_LOG_INFO(...)			::Phanes::Core::Logging::PEngineLogger()->info(__VA_ARGS__)
#define PENGINE_LOG_WARN(...)			::Phanes::Core::Logging::PEngineLogger()->warn(__VA_ARGS__)
#define PENGINE_LOG_ERROR(...)			::Phanes::Core::Logging::PEngineLogger()->error(__VA_ARGS__)
#define PENGINE_LOG_FATAL(...)			::Phanes::Core::Logging::PEngineLogger()->critical(__VA_ARGS__)


#define PAPP_LOG_TRACE(...)				::Phanes::Core::Logging::PAppLogger()->trace(__VA_ARGS__)
#define PAPP_LOG_INFO(...)				::Phanes::Core::Logging::PAppLogger()->info(__VA_ARGS__)
#define PAPP_LOG_WARN(...)				::Phanes::Core::Logging::PAppLogger()->warn(__VA_ARGS__)
#define PAPP_LOG_ERROR(...)				::Phanes::Core::Logging::PAppLogger()->error(__VA_ARGS__)
#define PAPP_LOG_FATAL(...)				::Phanes::Core::Logging::PAppLogger()->critical(__VA_ARGS__)

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
