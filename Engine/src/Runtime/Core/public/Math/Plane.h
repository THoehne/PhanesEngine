#pragma once

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/Vector3.h"

#include "Core/public/Math/MathFwd.h"

namespace Phanes::Core::Math {

	// Plane in 3D space, defined as:  P: ax + by + cz = d;

	template<RealType T>
	struct TPlane
	{
	public:
		TVector3<T> normal;
		T d;
	};

} // Phanes::Core::Math