#pragma once

// --- Logging -------------------------------------

#include "Core/public/Logging/Logging.h"

// --- Starting point ------------------------------
#include "Core/public/StartingPoint/StartingPoint.h"
#include "Core/public/StartingPoint/EntryPoint.h"




// --- OSAL ----------------------------------------

#include "Core/public/OSAL/PlatformTypes.h"


#ifdef P_USE_NAMESPACE_ALIAS


// Starting point
namespace PApp                = Phanes::Core::Application;

#endif