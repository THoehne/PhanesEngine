#include "PhanesEnginePCH.h"

#include "Core/public/Math/MathUnitConversion.h"


template<RealType T>
inline T Phanes::Core::Math::UnitConversion::DegToRad(T deg)
{
    return deg * P_PI_180_FLT;
}

template<RealType T>
inline T Phanes::Core::Math::UnitConversion::RadToDeg(T rad)
{
    return rad * P_180_PI_FLT;
}

template<RealType T>
inline T Phanes::Core::Math::UnitConversion::DegToGradian(T deg)
{
    return deg * 1.111111f;
}

template<RealType T>
inline T Phanes::Core::Math::UnitConversion::GradianToDeg(T g)
{
    return g * 0.9f;
}

template<RealType T>
inline T Phanes::Core::Math::UnitConversion::RadToGradian(T rad)
{
    return rad * 200 / P_PI_FLT;
}

template<RealType T>
inline T Phanes::Core::Math::UnitConversion::GradianToRad(T g)
{
    return g * P_PI_FLT / 200;
}



// Unit Literals

double Phanes::Core::Math::UnitLiterals::operator""_deg(long double _x)
{
  return _x * P_PI_180_FLT;
}

double Phanes::Core::Math::UnitLiterals::operator""_rad(long double _x)
{
  return _x;
}

double Phanes::Core::Math::UnitLiterals::operator""_g(long double _x)
{
  return _x * P_PI_FLT / 200;
}

