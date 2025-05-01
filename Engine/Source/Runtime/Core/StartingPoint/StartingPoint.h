#pragma once

#include "Core/Core.h"
#include "StartingPointPCH.h"

// Entrypoint class for any Phanes game.

namespace Phanes::Core::Application
{
	class PhanesProject
	{

	private:
		std::string projectName;

	public:
		PhanesProject(std::string _ProjectName);

		virtual ~PhanesProject();

		/**
         * PhanesEngine main loop.
         */
		void Run();

		/**
         * Getter for project name;
         */

		std::string GetName();

		PhanesProject(const PhanesProject&) = delete;
		PhanesProject& operator=(const PhanesProject&) = delete;
	};

	/**
     * Function to be overwriten by client.
     */
	PhanesProject* CreatePhanesGame();
} // namespace Phanes::Core::Application
