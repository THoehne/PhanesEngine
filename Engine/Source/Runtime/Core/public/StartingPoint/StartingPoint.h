#pragma once

#include "Core/Core.h"

// Entrypoint class for any Phanes game. 

namespace Phanes::Core::Application
{
  class PHANES_CORE PhanesProject
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

    FORCEINLINE std::string GetName();

  };


  /**
   * Function to be overwriten by client.
   */

  PhanesProject* CreatePhanesGame();
}
