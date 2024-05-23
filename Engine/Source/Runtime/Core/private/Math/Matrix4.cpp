// ========================== //
//   Matrix4 implementation   //
// ========================== //

#include "Misc/CommonDefines.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/Matrix4.h"

#include "Math/Vector3.h"


// ================================= //
//   Class Methods for easy access   //
// ================================= //

float& phanes::core::math::coretypes::Matrix4::operator()(int n, int m)
{
	return this->fields[m][n];
}

phanes::core::math::coretypes::Vector4& phanes::core::math::coretypes::Matrix4::operator[](int m)
{
	return (*reinterpret_cast<Vector4*>(this->fields[m]));
}

const float& phanes::core::math::coretypes::Matrix4::operator()(int n, int m) const
{
	return this->fields[m][n];
}

const phanes::core::math::coretypes::Vector4& phanes::core::math::coretypes::Matrix4::operator[](int m) const
{
	return (*reinterpret_cast<const Vector4*>(this->fields[m]));
}


// ================= //
//    Constructors   //
// ================= //

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::createMatrix(float fields[4][4])
{
	Matrix4 a;
	std::copy(&fields[0][0], &fields[4][4], &a.fields[0][0]);
	return a;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::createMatrix(float f00, float f01, float f02, float f03, float f10, float f11, float f12, float f13, float f20, float f21, float f22, float f23, float f30, float f31, float f32, float f33)
{
	Matrix4 a;
	a.fields[0][0] = f00; a.fields[1][0] = f01; a.fields[2][0] = f02; a.fields[3][0] = f03;
	a.fields[0][1] = f10; a.fields[1][1] = f11; a.fields[2][1] = f12; a.fields[3][1] = f13;
	a.fields[0][2] = f20; a.fields[1][2] = f21; a.fields[2][2] = f22; a.fields[3][2] = f23;
	a.fields[0][3] = f30; a.fields[1][3] = f31; a.fields[2][3] = f32; a.fields[3][3] = f33;
	return a;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::createMatrix(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
{
	Matrix4 m;
	m.fields[0][0] = a.x; m.fields[1][0] = b.x; m.fields[2][0] = c.x; m.fields[3][0] = d.x;
	m.fields[0][1] = a.y; m.fields[1][1] = b.y; m.fields[2][1] = c.y; m.fields[3][1] = d.y;
	m.fields[0][2] = a.z; m.fields[1][2] = b.z; m.fields[2][2] = c.z; m.fields[3][2] = d.z;
	m.fields[0][3] = a.w; m.fields[1][3] = b.w; m.fields[2][3] = c.w; m.fields[3][3] = d.w;
	return m;
}


// ============= //
//   Operators   //
// ============= //


void phanes::core::math::coretypes::operator+=(Matrix4& a, float s)
{
	a[0] += s;
	a[1] += s;
	a[2] += s;
	a[3] += s;
}

void phanes::core::math::coretypes::operator+=(Matrix4& a, const Matrix4& b)
{
	a[0] += b[0];
	a[1] += b[1];
	a[2] += b[2];
	a[3] += b[3];
}

void phanes::core::math::coretypes::operator-=(Matrix4& a, float s)
{
	a[0] -= s;
	a[1] -= s;
	a[2] -= s;
	a[3] -= s;
}

void phanes::core::math::coretypes::operator-=(Matrix4& a, const Matrix4& b)
{
	a[0] -= b[0];
	a[1] -= b[1];
	a[2] -= b[2];
	a[3] -= b[3];
}

void phanes::core::math::coretypes::operator*=(Matrix4& a, float s)
{
	a[0] *= s;
	a[1] *= s;
	a[2] *= s;
	a[3] *= s;
}

void phanes::core::math::coretypes::operator*=(Matrix4& a, const Matrix4& b)
{
	Matrix4 c = a;

	a(0, 0) = c(0, 0) * b(0, 0) + c(0, 1) * b(1, 0) + c(0, 2) * b(2, 0) + c(0, 3) * b(3, 0);
	a(0, 1) = c(0, 0) * b(0, 1) + c(0, 1) * b(1, 1) + c(0, 2) * b(2, 1) + c(0, 3) * b(3, 1);
	a(0, 2) = c(0, 0) * b(0, 2) + c(0, 1) * b(1, 2) + c(0, 2) * b(2, 2) + c(0, 3) * b(3, 2);
	a(0, 3) = c(0, 0) * b(0, 3) + c(0, 1) * b(1, 3) + c(0, 2) * b(2, 3) + c(0, 3) * b(3, 3);

	a(1, 0) = c(1, 0) * b(0, 0) + c(1, 1) * b(1, 0) + c(1, 2) * b(2, 0) + c(1, 3) * b(3, 0);
	a(1, 1) = c(1, 0) * b(0, 1) + c(1, 1) * b(1, 1) + c(1, 2) * b(2, 1) + c(1, 3) * b(3, 1);
	a(1, 2) = c(1, 0) * b(0, 2) + c(1, 1) * b(1, 2) + c(1, 2) * b(2, 2) + c(1, 3) * b(3, 2);
	a(1, 3) = c(1, 0) * b(0, 3) + c(1, 1) * b(1, 3) + c(1, 2) * b(2, 3) + c(1, 3) * b(3, 3);

	a(2, 0) = c(2, 0) * b(0, 0) + c(2, 1) * b(1, 0) + c(2, 2) * b(2, 0) + c(2, 3) * b(3, 0);
	a(2, 1) = c(2, 0) * b(0, 1) + c(2, 1) * b(1, 1) + c(2, 2) * b(2, 1) + c(2, 3) * b(3, 1);
	a(2, 2) = c(2, 0) * b(0, 2) + c(2, 1) * b(1, 2) + c(2, 2) * b(2, 2) + c(2, 3) * b(3, 2);
	a(2, 3) = c(2, 0) * b(0, 3) + c(2, 1) * b(1, 3) + c(2, 2) * b(2, 3) + c(2, 3) * b(3, 3);

	a(3, 0) = c(3, 0) * b(0, 0) + c(3, 1) * b(1, 0) + c(3, 2) * b(2, 0) + c(3, 3) * b(3, 0);
	a(3, 1) = c(3, 0) * b(0, 1) + c(3, 1) * b(1, 1) + c(3, 2) * b(2, 1) + c(3, 3) * b(3, 1);
	a(3, 2) = c(3, 0) * b(0, 2) + c(3, 1) * b(1, 2) + c(3, 2) * b(2, 2) + c(3, 3) * b(3, 2);
	a(3, 3) = c(3, 0) * b(0, 3) + c(3, 1) * b(1, 3) + c(3, 2) * b(2, 3) + c(3, 3) * b(3, 3);
}


phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator+(const Matrix4& a, float s)
{
	Matrix4 m;
	m[0] = a[0] + s;
	m[1] = a[1] + s;
	m[2] = a[2] + s;
	m[3] = a[3] + s;
	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator+(const Matrix4& a, const Matrix4& b)
{
	Matrix4 m;
	m[0] = a[0] + b[0];
	m[1] = a[1] + b[1];
	m[2] = a[2] + b[2];
	m[3] = a[3] + b[3];
	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator-(const Matrix4& a, float s)
{
	Matrix4 m;
	m[0] = a[0] - s;
	m[1] = a[1] - s;
	m[2] = a[2] - s;
	m[3] = a[3] - s;
	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator-(const Matrix4& a, const Matrix4& b)
{
	Matrix4 m;
	m[0] = a[0] - b[0];
	m[1] = a[1] - b[1];
	m[2] = a[2] - b[2];
	m[3] = a[3] - b[3];
	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator*(const Matrix4& a, float s)
{
	Matrix4 m;
	m[0] = a[0] * s;
	m[1] = a[1] * s;
	m[2] = a[2] * s;
	m[3] = a[3] * s;
	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::operator*(const Matrix4& a, const Matrix4& b)
{
	Matrix4 m;

	m(0, 0) = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0) + a(0, 3) * b(3, 0);
	m(0, 1) = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1) + a(0, 3) * b(3, 1);
	m(0, 2) = a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2) + a(0, 3) * b(3, 2);
	m(0, 3) = a(0, 0) * b(0, 3) + a(0, 1) * b(1, 3) + a(0, 2) * b(2, 3) + a(0, 3) * b(3, 3);

	m(1, 0) = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0) + a(1, 3) * b(3, 0);
	m(1, 1) = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1) + a(1, 3) * b(3, 1);
	m(1, 2) = a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2) + a(1, 3) * b(3, 2);
	m(1, 3) = a(1, 0) * b(0, 3) + a(1, 1) * b(1, 3) + a(1, 2) * b(2, 3) + a(1, 3) * b(3, 3);

	m(2, 0) = a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0) + a(2, 3) * b(3, 0);
	m(2, 1) = a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1) + a(2, 3) * b(3, 1);
	m(2, 2) = a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2) + a(2, 3) * b(3, 2);
	m(2, 3) = a(2, 0) * b(0, 3) + a(2, 1) * b(1, 3) + a(2, 2) * b(2, 3) + a(2, 3) * b(3, 3);

	m(3, 0) = a(3, 0) * b(0, 0) + a(3, 1) * b(1, 0) + a(3, 2) * b(2, 0) + a(3, 3) * b(3, 0);
	m(3, 1) = a(3, 0) * b(0, 1) + a(3, 1) * b(1, 1) + a(3, 2) * b(2, 1) + a(3, 3) * b(3, 1);
	m(3, 2) = a(3, 0) * b(0, 2) + a(3, 1) * b(1, 2) + a(3, 2) * b(2, 2) + a(3, 3) * b(3, 2);
	m(3, 3) = a(3, 0) * b(0, 3) + a(3, 1) * b(1, 3) + a(3, 2) * b(2, 3) + a(3, 3) * b(3, 3);
	return m;
}

phanes::core::math::coretypes::Vector4 phanes::core::math::coretypes::operator*(const Matrix4& a, const Vector4& v)
{
	Vector4 b = createVector(
		a(0, 0) * v.x + a(0, 1) * v.y + a(0, 2) * v.z + a(0, 3) * v.w,
		a(1, 0) * v.x + a(1, 1) * v.y + a(1, 2) * v.z + a(1, 3) * v.w,
		a(2, 0) * v.x + a(2, 1) * v.y + a(2, 2) * v.z + a(2, 3) * v.w,
		a(3, 0) * v.x + a(3, 1) * v.y + a(3, 2) * v.z + a(3, 3) * v.w
	);
	return b;
}

bool phanes::core::math::coretypes::operator==(const Matrix4& a, const Matrix4& b)
{
	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
		return true;
	}
	return false;
}

// =============================== //
//   Matrix function definition    //
// =============================== //


float phanes::core::math::coretypes::determinant(const Matrix4& a)
{
	Vector3 v0 = reinterpret_cast<const Vector3&>(a[0]);
	Vector3 v1 = reinterpret_cast<const Vector3&>(a[1]);
	Vector3 v2 = reinterpret_cast<const Vector3&>(a[2]);
	Vector3 v3 = reinterpret_cast<const Vector3&>(a[3]);

	Vector3 s = crossP(v0, v1);
	Vector3 t = crossP(v2, v3);
	Vector3 u = a(3, 1) * v0 + a(3, 0) * v1;
	Vector3 v = a(3, 3) * v2 + a(3, 2) * v3;

	return s * v + t * u;
}

void phanes::core::math::coretypes::inverseNR(Matrix4& a)
{
	Vector3 v0 = reinterpret_cast<const Vector3&>(a[0]);
	Vector3 v1 = reinterpret_cast<const Vector3&>(a[1]);
	Vector3 v2 = reinterpret_cast<const Vector3&>(a[2]);
	Vector3 v3 = reinterpret_cast<const Vector3&>(a[3]);

	Vector3 s = crossP(v0, v1);
	Vector3 t = crossP(v2, v3);
	Vector3 u = a(3, 1) * v0 + a(3, 0) * v1;
	Vector3 v = a(3, 3) * v2 + a(3, 2) * v3;

	float _1_det = 1.0f / determinant(a);

	Vector3 r0 = crossP(v1, v) + t * a(3, 1);
	Vector3 r1 = crossP(v, v0) - t * a(3, 0);
	Vector3 r2 = crossP(v3, u) + s * a(3, 3);
	Vector3 r3 = crossP(u, v2) - s * a(3, 2);

	a = createMatrix(
		r0.x, r0.y, r0.z, -dotP(v1, t),
		r1.x, r1.y, r1.z, -dotP(v0, t),
		r2.x, r2.y, r2.z, -dotP(v3, s),
		r3.x, r3.y, r3.z, -dotP(v2, s)
	);
}

void phanes::core::math::coretypes::transposeNR(Matrix4& a)
{
	swap(a(0, 1), a(1, 0));
	swap(a(0, 2), a(2, 0));
	swap(a(0, 3), a(3, 0));

	swap(a(1, 2), a(2, 1));
	swap(a(1, 3), a(3, 1));

	swap(a(2, 3), a(3, 2));
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::inverse(Matrix4& a)
{
	Vector3 v0 = reinterpret_cast<const Vector3&>(a[0]);
	Vector3 v1 = reinterpret_cast<const Vector3&>(a[1]);
	Vector3 v2 = reinterpret_cast<const Vector3&>(a[2]);
	Vector3 v3 = reinterpret_cast<const Vector3&>(a[3]);

	Vector3 s = crossP(v0, v1);
	Vector3 t = crossP(v2, v3);
	Vector3 u = a(3, 1) * v0 + a(3, 0) * v1;
	Vector3 v = a(3, 3) * v2 + a(3, 2) * v3;

	float _1_det = 1.0f / determinant(a);

	Vector3 r0 = crossP(v1, v) + t * a(3, 1);
	Vector3 r1 = crossP(v, v0) - t * a(3, 0);
	Vector3 r2 = crossP(v3, u) + s * a(3, 3);
	Vector3 r3 = crossP(u, v2) - s * a(3, 2);

	Matrix4 m = createMatrix(
		r0.x, r0.y, r0.z, -dotP(v1, t),
		r1.x, r1.y, r1.z, -dotP(v0, t),
		r2.x, r2.y, r2.z, -dotP(v3, s),
		r3.x, r3.y, r3.z, -dotP(v2, s)
	);

	return m;
}

phanes::core::math::coretypes::Matrix4 phanes::core::math::coretypes::transpose(const Matrix4& a)
{
	Matrix4 m = a;

	swap(m(0, 1), m(1, 0));
	swap(m(0, 2), m(2, 0));
	swap(m(0, 3), m(3, 0));

	swap(m(1, 2), m(2, 1));
	swap(m(1, 3), m(3, 1));

	swap(m(2, 3), m(3, 2));
	
	return m;
}

bool phanes::core::math::coretypes::isIndentityMatrix(const Matrix4& a)
{
	if (a == phanes::core::math::coretypes::createMatrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)) {
		return true;
	}
	return false;
}

