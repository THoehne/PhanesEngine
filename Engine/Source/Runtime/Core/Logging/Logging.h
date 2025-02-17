#pragma once


#include "Core/Logging/LoggingPCH.h"
#include "Core/Core.h"

namespace Phanes::Core::Logging
{
	class Logger {

	public:

		static void Init();

		static std::shared_ptr<spdlog::logger>& PEngineLogger() { return _PEngineLogger; }
		static std::shared_ptr<spdlog::logger>& PAppLogger() { return _PAppLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> _PEngineLogger;
		static std::shared_ptr<spdlog::logger> _PAppLogger;
	};
}


namespace PLog = Phanes::Core::Logging; // User Macros 

#ifdef P_DEBUG

// Default logger

#define PENGINE_LOG_TRACE(...)			::Phanes::Core::Logging::Logger::PEngineLogger()->trace(__VA_ARGS__)
#define PENGINE_LOG_INFO(...)			::Phanes::Core::Logging::Logger::PEngineLogger()->info(__VA_ARGS__)
#define PENGINE_LOG_WARN(...)			::Phanes::Core::Logging::Logger::PEngineLogger()->warn(__VA_ARGS__)
#define PENGINE_LOG_ERROR(...)			::Phanes::Core::Logging::Logger::PEngineLogger()->error(__VA_ARGS__)
#define PENGINE_LOG_FATAL(...)			::Phanes::Core::Logging::Logger::PEngineLogger()->critical(__VA_ARGS__)


#define PAPP_LOG_TRACE(...)				::Phanes::Core::Logging::Logger::PAppLogger()->trace(__VA_ARGS__)
#define PAPP_LOG_INFO(...)				::Phanes::Core::Logging::Logger::PAppLogger()->info(__VA_ARGS__)
#define PAPP_LOG_WARN(...)				::Phanes::Core::Logging::Logger::PAppLogger()->warn(__VA_ARGS__)
#define PAPP_LOG_ERROR(...)				::Phanes::Core::Logging::Logger::PAppLogger()->error(__VA_ARGS__)
#define PAPP_LOG_FATAL(...)				::Phanes::Core::Logging::Logger::PAppLogger()->critical(__VA_ARGS__)

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
