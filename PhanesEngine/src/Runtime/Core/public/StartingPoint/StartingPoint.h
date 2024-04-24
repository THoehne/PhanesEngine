#pragma once

#include "Core/Core.h"

// Entrypoint class for any Phanes game. 

namespace Phanes::Core::Application
{
	class PHANES_CORE_API PhanesGame
	{

	public:

		PhanesGame();
		virtual ~PhanesGame();

		/**
		 * PhanesEngine main loop.
		 */
		void Run();

	};


	/**
	 * Function to be overwriten by client.
	 */

	PhanesGame* CreatePhanesGame();

}