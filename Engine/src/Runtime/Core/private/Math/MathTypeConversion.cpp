#include "PhanesEnginePCH.h"
#include "Core/public/Math/MathTypeConversion.h"

// ============ //
//   ToString   //
// ============ //

template<RealType T>
std::string Phanes::Core::Math::ToString(const Phanes::Core::Math::TVector2<T>& v) {
  return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}

template<IntType T>
std::string Phanes::Core::Math::ToString(const TIntVector2<T>& v)
{
  return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}

template<RealType T>
std::string Phanes::Core::Math::ToString(const Phanes::Core::Math::TVector3<T>& v) {
  return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")";
}

template<IntType T>
std::string Phanes::Core::Math::ToString(const TIntVector3<T>& v)
{
  std::to_string(3);

  return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")";
}

//template<typename T>
//std::string Phanes::Core::Math::ToString(const Vector4& v)
//{
//	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ", " + std::to_string(v.w) + ")";
//}
//
//template<typename T>
//std::string Phanes::Core::Math::ToString(const Matrix2& v)
//{
//	return std::to_string(v(0,0)) + " | " + std::to_string(v(0,1)) + "\n" + std::to_string(v(1,0)) + " | " + std::to_string(v(1,1));
//}
//
//template<typename T>
//std::string Phanes::Core::Math::ToString(const Matrix3& v)
//{
//	return std::to_string(v(0, 0)) + " | " + std::to_string(v(0, 1)) + " | " + std::to_string(v(0, 2)) + "\n" + std::to_string(v(1, 0)) + " | " + std::to_string(v(1, 1)) + " | " + std::to_string(v(1, 2)) + "\n" + std::to_string(v(2, 0)) + " | " + std::to_string(v(2, 1)) + " | " + std::to_string(v(2, 2));
//}
