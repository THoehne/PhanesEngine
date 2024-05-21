#pragma once


#ifdef P_WIN_BUILD

	#ifdef P_BUILD_LIB
		
		#define PHANES_CORE __declspec(dllexport)
	
	#else
		
		#define PHANES_CORE __declspec(dllimport)

	#endif

	#ifdef P_DEBUG
	
		#define P_DEBUGBREAK DebugBreak();

	#else 
	
		#define P_DEBUGBREAK

	#endif // P_DEBUG

	#define FORCEINLINE __forceinline

#elif defined(P_UNIX_BUILD)

	#error Only Windows is supported at the moment.	

#elif defined(P_ARM_BUILD)
	
	#error Only Windows is supported at the moment.

#else

	#error The target system must be defined. (See https://github.com/scorpioblood/PhanesEngine for more information)

#endif // P_WIN_BUILD


namespace Phanes
{

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ...Args>
	constexpr Ref<T> MakeRef(Args&& ...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}


}

int test()
{

}