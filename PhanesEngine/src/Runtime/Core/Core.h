#pragma once

#ifdef P_WIN_BUILD

	#ifdef P_DLL_EXPORT

		#define PHANES_CORE_API __declspec(dllexport)

	#else

		#define PHANES_CORE_API __declspec(dllimport)

	#endif // P_DLL_EXPORT

#else

	#error Only Windows is supported at the moment.	

#endif // P_WIN_BUILD