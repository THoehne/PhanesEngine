#include "PhanesEnginePCH.h"

#include "Core/public/Math/IntPoint.h"



// ----- TIntPoint2 ------------------------------------------

template<IntType T, RealType Rt>
Rt Phanes::Core::Math::Distance(const TIntPoint2<T>& p1, const TIntPoint2<T>& p2)
{
	return Magnitude(p2 - p1);
}

// ----- TIntPoint3 ------------------------------------------


template<IntType T, RealType Rt>
Rt Phanes::Core::Math::Distance(const TIntPoint3<T>& p1, const TIntPoint3<T>& p2)
{
	return Magnitude(p2 - p1);
}