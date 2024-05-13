// ========================== //
//   Vector4 implementation   //
// ========================== //


#include "Misc/CommonDefines.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/Vector4.h"

#include "Math/Vector3.h"
#include "Math/Vector2.h"


// ===================== //
//   Vector4 operators   //
// ===================== //

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::createVector(float x, float y, float z, float w)
{
	Vector4 _new{};
	_new.x = x;
	_new.y = y;
	_new.z = z;
	_new.w = w;
	return _new;
}


void phanes::core::math::coretypes::operator+=(Vector4& a, float s)
{
	a.x += s;
	a.y += s;
	a.z += s;
	a.w += s;
}


void phanes::core::math::coretypes::operator+= (phanes::core::math::coretypes::Vector4& a, const phanes::core::math::coretypes::Vector4& b) {
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
}

void phanes::core::math::coretypes::operator-=(Vector4& a, float s)
{
	a.x -= s;
	a.y -= s;
	a.z -= s;
	a.w -= s;
}

void phanes::core::math::coretypes::operator-= (phanes::core::math::coretypes::Vector4& a, const phanes::core::math::coretypes::Vector4& b) {
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
}


void phanes::core::math::coretypes::operator*= (phanes::core::math::coretypes::Vector4& a, float s) {
	a.x *= s;
	a.y *= s;
	a.z *= s;
	a.w *= s;
}


void phanes::core::math::coretypes::operator/= (phanes::core::math::coretypes::Vector4& a, float s) {
	s = 1.0f / s;
	a.x *= s;
	a.y *= s;
	a.z *= s;
	a.w *= s;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator*(const Vector4& a, float s)
{
	Vector4 v;
	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	v.w = a.w * s;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator*(float s, const Vector4& a)
{
	Vector4 v;
	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	v.w = a.w * s;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator/(const Vector4& a, float s)
{
	Vector4 v;
	s = 1.0f / s;
	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	v.w = a.w * s;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator/(float s, const Vector4& a)
{
	Vector4 v;
	s = 1.0f / s;
	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	v.w = a.w * s;
	return v;
}


float phanes::core::math::coretypes::operator*(const Vector4& a, const Vector4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator+(const Vector4& a, float s)
{
	Vector4 v;
	v.x = a.x + s;
	v.y = a.y + s;
	v.z = a.z + s;
	v.w = a.w + s;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator+(const Vector4& a, const Vector4& b)
{
	Vector4 v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	v.w = a.w + b.w;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator-(const Vector4& a, float s)
{
	Vector4 v;
	v.x = a.x - s;
	v.y = a.y - s;
	v.z = a.z - s;
	v.w = a.w - s;
	return v;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator-(const Vector4& a, const Vector4& b)
{
	Vector4 v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	v.w = a.w - b.w;
	return v;
}


void phanes::core::math::coretypes::operator-(Vector4& a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	a.w = -a.w;
}


bool phanes::core::math::coretypes::operator==(const Vector4& a, const Vector4& b)
{
	if (abs(a.x - b.x) <= P_FLT_INAC and abs(a.y - b.y) <= P_FLT_INAC and abs(a.z - b.z) <= P_FLT_INAC and abs(a.w - b.w) <= P_FLT_INAC)
	{
		return true;
	}
	return false;
}

// ====================================== //
//    Vector4 function implementation	  //
// ====================================== //


float phanes::core::math::coretypes::magnitude(const Vector4& a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

float phanes::core::math::coretypes::sqrMagnitude(const Vector4& a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z;
}


void phanes::core::math::coretypes::normalizeNR(Vector4& a)
{
	a /= sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}


float phanes::core::math::coretypes::angle(const Vector4& a, const Vector4& b)
{
	return acosf(dotP(a, b) / (magnitude(a) * magnitude(b)));
}


float phanes::core::math::coretypes::dotP(const Vector4& a, const Vector4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}


void phanes::core::math::coretypes::orthogonolize(Vector4& a, Vector4& b, Vector4& c)
{
	Set(b, b - project(b, a));
	Set(c, c - project(c, a) - project(c, b));
}

void phanes::core::math::coretypes::orthoNormalize(Vector4& a, Vector4& b, Vector4& c)
{
	Set(b, b - project(b, a));
	Set(c, c - project(c, a) - project(c, b));

	a /= sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	b /= sqrtf(b.x * b.x + b.y * b.y + b.z * b.z);
	c /= sqrtf(c.x * c.x + c.y * c.y + c.z * c.z);
}

void phanes::core::math::coretypes::scaleToMagnitude(Vector4& a, float size)
{
	a /= sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	a *= size;
}

bool phanes::core::math::coretypes::equals(const Vector4& a, const Vector4& b, float threshold)
{
	if (abs(a.x - b.x) <= threshold and abs(a.y - b.y) <= threshold and abs(a.z - b.z) <= threshold)
	{
		return true;
	}
	return false;
}

void phanes::core::math::coretypes::perpspectiveDivideNR(Vector4& a)
{
	float _z = 1.0f / a.z;
	a.x *= _z;
	a.y *= _z;
	a.z = 0.0f;
}

void phanes::core::math::coretypes::maxNR(Vector4& a, const Vector4& b)
{
	a.x = phanes::core::math::max(a.x, b.x);
	a.y = phanes::core::math::max(a.y, b.y);
}

void phanes::core::math::coretypes::minNR(Vector4& a, const Vector4& b)
{
	a.x = phanes::core::math::min(a.x, b.x);
	a.y = phanes::core::math::min(a.y, b.y);
}

void phanes::core::math::coretypes::scaleNR(Vector4& a, const Vector4& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
}

// projects vector a onto vector b
void phanes::core::math::coretypes::projectNR(Vector4& a, const Vector4& b)
{
	float x = (a * b) / (b * b);
	a.x = x * b.x;
	a.y = x * b.y;
	a.z = x * b.z;
}

// rejects vector a from vector b
void phanes::core::math::coretypes::rejectNR(Vector4& a, const Vector4& b)
{
	float x = ((a * b) / (b * b));
	a.x -= x * b.x;
	a.y -= x * b.y;
	a.z -= x * b.z;
}


void phanes::core::math::coretypes::Set(Vector4& a, const Vector4& b)
{
	a.x = b.x;
	a.y = b.y;
	a.z = b.z;
}


// WITH RETURN: //

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::perpspectiveDivide(const Vector4& a)
{
	float _z = 1.0f / a.z;
	return createVector(a.x * _z, a.y * _z, a.z * _z, 0.0f);
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::lerp(const Vector4& a, const Vector4& b, float t)
{
	t = phanes::core::math::clamp(t, .0f, 1.0f);
	return a * (1 - t) + t * b;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::lerpUnclamped(const Vector4& a, const Vector4& b, float t)
{
	return a * (1 - t) + t * b;
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::slerp(const Vector4& a, const Vector4& b, float t)
{
	t = phanes::core::math::clamp(t, 0.0f, 1.0f);
	Vector4 _a = normalize(a);
	Vector4 _b = normalize(b);
	float _angle = angle(_a, _b);
	return (((sinf(1.0f - t) * _angle) / sinf(_angle)) * _a) + ((sinf(t * _angle) / sinf(_angle)) * _b);
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::slerpUnclamped(const Vector4& a, const Vector4& b, float t)
{
	Vector4 _a = normalize(a);
	Vector4 _b = normalize(b);
	float _angle = angle(_a, _b);
	return (((sinf(1.0f - t) * _angle) / sinf(_angle)) * _a) + ((sinf(t * _angle) / sinf(_angle)) * _b);
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::max(const Vector4& a, const Vector4& b)
{
	Vector4 _new{};
	_new.x = phanes::core::math::max(a.x, b.x);
	_new.y = phanes::core::math::max(a.y, b.y);
	_new.z = phanes::core::math::max(a.z, b.z);
	return _new;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::min(const Vector4& a, const Vector4& b)
{
	Vector4 _new{};
	_new.x = phanes::core::math::min(a.x, b.x);
	_new.y = phanes::core::math::min(a.y, b.y);
	_new.z = phanes::core::math::min(a.z, b.z);
	return _new;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::scale(const Vector4& a, const Vector4& b)
{
	return createVector(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::project(const Vector4& a, const Vector4& b)
{
	return ((a * b) / (b * b)) * b;
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::reject(const Vector4& a, const Vector4& b)
{
	return a - ((a * b) / (b * b)) * b;
}


phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::normalize(const Vector4& a)
{
	return a / sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}