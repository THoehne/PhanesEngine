#pragma once

#include "StartingPointPCH.h"
#include "Core/Core.h"

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

  };


  /**
   * Function to be overwriten by client.
   */

  PhanesProject* CreatePhanesGame();
}
