// =========================== //
//   Matrix2D implementation   //
// =========================== //


#include "Misc/CommonDefines.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/Matrix2.h"

#pragma warning(disable : 4172)

// ================================= //
//   Class Methods for easy access   //
// ================================= //

float& phanes::core::math::coretypes::Matrix2::operator()(int n, int m)
{
	return this->fields[m][n];
}

const float& phanes::core::math::coretypes::Matrix2::operator()(int n, int m) const
{
	return this->fields[m][n];
}

phanes::core::math::coretypes::Vector2& phanes::core::math::coretypes::Matrix2::operator[](int m)
{
	return (*reinterpret_cast<Vector2*>(this->fields[m]));
}

const phanes::core::math::coretypes::Vector2& phanes::core::math::coretypes::Matrix2::operator[](int m) const
{
	return (*reinterpret_cast<const Vector2*>(this->fields[m]));
}


// ================= //
//    Constructors   //
// ================= //

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::createMatrix(float fields[2][2])
{
	Matrix2 a;
	std::copy(&fields[0][0], &fields[2][2], &a.fields[0][0]);
	return a;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::createMatrix(float f00, float f01, float f10, float f11)
{
	Matrix2 a;
	a.fields[0][0] = f00; a.fields[1][0] = f01;
	a.fields[0][1] = f10; a.fields[1][1] = f11;
	return a;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::createMatrix(const Vector2& a, const Vector2& b)
{
	Matrix2 m;
	m.fields[0][0] = a.x; m.fields[1][0] = b.x;
	m.fields[0][1] = a.y; m.fields[1][1] = b.y;
	return m;
}


// ============= //
//   Operators   //
// ============= //


void phanes::core::math::coretypes::operator+=(Matrix2& a, float s)
{
	a[0] += s;
	a[1] += s;
}

void phanes::core::math::coretypes::operator+=(Matrix2& a, const Matrix2& b)
{
	a[0] += b[0];
	a[1] += b[1];
}

void phanes::core::math::coretypes::operator-=(Matrix2& a, float s)
{
	a[0] -= s;
	a[1] -= s;
}

void phanes::core::math::coretypes::operator-=(Matrix2& a, const Matrix2& b)
{
	a[0] -= b[0];
	a[1] -= b[1];
}

void phanes::core::math::coretypes::operator*=(Matrix2& a, float s)
{
	a[0] *= s;
	a[1] *= s;
}

void phanes::core::math::coretypes::operator*=(Matrix2& a, const Matrix2& b)
{
	Matrix2 c = a;

	a(0, 0) = c(0, 0) * b(0, 0) + c(0, 1) * b(1, 0);
	a(0, 1) = c(0, 0) * b(0, 1) + c(0, 1) * b(1, 1);

	a(1, 0) = c(1, 0) * b(0, 0) + c(1, 1) * b(1, 0);
	a(1, 1) = c(1, 0) * b(0, 1) + c(1, 1) * b(1, 1);
}


phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator+(const Matrix2& a, float s)
{
	Matrix2 m;
	m[0] = a[0] + s;
	m[1] = a[1] + s;
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator+(const Matrix2& a, const Matrix2& b)
{
	Matrix2 m;
	m[0] = a[0] + b[0];
	m[1] = a[1] + b[1];
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator-(const Matrix2& a, float s)
{
	Matrix2 m;
	m[0] = a[0] - s;
	m[1] = a[1] - s;
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator-(const Matrix2& a, const Matrix2& b)
{
	Matrix2 m;
	m[0] = a[0] - b[0];
	m[1] = a[1] - b[1];
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator*(const Matrix2& a, float s)
{
	Matrix2 m;
	m[0] = a[0] * s;
	m[1] = a[1] * s;
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::operator*(const Matrix2& a, const Matrix2& b)
{
	Matrix2 m;

	m(0, 0) = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0);
	m(0, 1) = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1);
	m(1, 0) = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0);
	m(1, 1) = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1);

	return m;
}

phanes::core::math::coretypes::Vector2 phanes::core::math::coretypes::operator*(const Matrix2& a, const Vector2& v)
{
	Vector2 b = createVector(
		a(0, 0) * v.x + a(0, 1) * v.y,
		a(1, 0) * v.x + a(1, 1) * v.y
	);
	return b;
}

bool phanes::core::math::coretypes::operator==(const Matrix2& a, const Matrix2& b)
{
	if (a[0] == b[0] && a[1] == b[1]) {
		return true;
	}
	return false;
}

float phanes::core::math::coretypes::determinant(const Matrix2& a)
{
	return (a(0, 0) * a(1, 1)) - (a(0, 1) * a(1, 0));
}

void phanes::core::math::coretypes::inverseNR(Matrix2& a)
{
	float& ref = a(0, 0);
	float b = ref;
	float _1_det = 1.0f / determinant(a);

	a(0, 0) = a(1, 1);
	a(0, 1) = -a(0, 1);
	a(1, 0) = -a(1, 0);
	a(1, 1) = b;

	a *= _1_det;
}

void phanes::core::math::coretypes::transposeNR(Matrix2& a)
{
	swap(a(0, 1), a(1, 0));
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::inverse(Matrix2& a)
{
	Matrix2 m;
	float _1_det = 1.0f / determinant(a);

	m(0, 0) = a(1, 1);
	m(0, 1) = -a(0, 1);
	m(1, 0) = -a(1, 0);
	m(1, 1) = a(0, 0);

	m *= _1_det;
	return m;
}

phanes::core::math::coretypes::Matrix2 phanes::core::math::coretypes::transpose(const Matrix2& a)
{
	Matrix2 c;
	c(0, 0) = a(0, 0);
	c(1, 0) = a(0, 1);
	c(0, 1) = a(1, 0);
	c(1, 1) = a(1, 1);
	return c;
}

bool phanes::core::math::coretypes::isIndentityMatrix(const Matrix2& a)
{

	if (a == phanes::core::math::coretypes::createMatrix(1, 0, 0, 1)) {
		return true;
	}
	return false;
}