#include "PhanesEnginePCH.h"

#include "Core/public/Math/Point.h"

#include "Core/public/Math/Vector2.h"
#include "Core/public/Math/Vector3.h"
// #include "Core/public/Math/Vector4.h"


// ----- TPoint2 ------------------------------------------

template<RealType T>
T Phanes::Core::Math::Distance(const TPoint2<T>& p1, const TPoint2<T>& p2)
{
  return Magnitude(p2 - p1);
}


// ----- TPoint3 ------------------------------------------

template<RealType T>
T Phanes::Core::Math::Distance(const TPoint3<T>& p1, const TPoint3<T>& p2)
{
  return Magnitude(p2 - p1);
}


// ----- TPoint4 ------------------------------------------

//template<RealType T>
//T Phanes::Core::Math::Distance(const TPoint4<T>& p1, const TPoint4<T>& p2)
//{
//	return Magnitude(TVector3<T>(p1, p2));
//}
