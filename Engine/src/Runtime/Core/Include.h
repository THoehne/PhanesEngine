#pragma once

#ifdef P_USE_NAMESPACES

using namespace Phanes::Core::Math::Literals;

// Starting point
namespace PApp				= Phanes::Core::Application;


// Math
namespace PMath				= Phanes::Core::Math;
namespace PMathInternal		= Phanes::Core::Math::Internal;


// OSAL
namespace PTypes			= Phanes::Core::Types

#endif

// --- Starting point ------------------------------

#include "Core/public/StartingPoint/StartingPoint.h"
#include "Core/public/StartingPoint/EntryPoint.h"

// --- Math ----------------------------------------

#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathCommon.h"
#include "Core/public/Math/MathTypeConversion.h"
#include "Core/public/Math/MathUnitConversion.h"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/Vector2.h"
#include "Core/public/Math/Vector3.h"

#include "Core/public/Math/IntVector2.h"
#include "Core/public/Math/IntVector3.h"

// --- OSAL ----------------------------------------

#include "Core/public/OSAL/PlatformTypes.h"
