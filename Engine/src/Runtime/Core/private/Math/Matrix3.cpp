// ========================== //
//   Matrix3 implementation   //
// ========================== //



#include "Misc/CommonDefines.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/Matrix3.h"

// ================================= //
//   Class Methods for easy access   //
// ================================= //

float& phanes::core::math::coretypes::Matrix3::operator()(int n, int m)
{
	return this->fields[m][n];
}

phanes::core::math::coretypes::Vector3& phanes::core::math::coretypes::Matrix3::operator[](int m)
{
	return (*reinterpret_cast<Vector3*>(this->fields[m]));
}

const float& phanes::core::math::coretypes::Matrix3::operator()(int n, int m) const
{
	return this->fields[m][n];
}

const phanes::core::math::coretypes::Vector3& phanes::core::math::coretypes::Matrix3::operator[](int m) const
{
	return (*reinterpret_cast<const Vector3*>(this->fields[m]));
}


// ================= //
//    Constructors   //
// ================= //

phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::createMatrix(float fields[3][3])
{
	Matrix3 a;
	std::copy(&fields[0][0], &fields[3][3], &a.fields[0][0]);
	return a;
}

phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::createMatrix(float f00, float f01, float f02, float f10, float f11, float f12, float f20, float f21, float f22)
{
	Matrix3 a;
	a.fields[0][0] = f00; a.fields[1][0] = f01; a.fields[2][0] = f02;
	a.fields[0][1] = f10; a.fields[1][1] = f11; a.fields[2][1] = f12;
	a.fields[0][2] = f20; a.fields[1][2] = f21; a.fields[2][2] = f22;
	return a;
}

phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::createMatrix(const Vector3& a, const Vector3& b, const Vector3& c)
{
	Matrix3 m;
	m.fields[0][0] = a.x; m.fields[1][0] = b.x; m.fields[2][0] = c.x;
	m.fields[0][1] = a.y; m.fields[1][1] = b.y; m.fields[2][1] = c.y;
	m.fields[0][2] = a.z; m.fields[1][2] = b.z; m.fields[2][2] = c.z;
	return m;
}


// ============= //
//   Operators   //
// ============= //


void phanes::core::math::coretypes::operator+=(Matrix3& a, float s)
{
	a[0] += s;
	a[1] += s;
	a[2] += s;
}


void phanes::core::math::coretypes::operator+=(Matrix3& a, const Matrix3& b)
{
	a[0] += b[0];
	a[1] += b[1];
	a[2] += b[2];
}


void phanes::core::math::coretypes::operator-=(Matrix3& a, float s)
{
	a[0] -= s;
	a[1] -= s;
	a[2] -= s;
}


void phanes::core::math::coretypes::operator-=(Matrix3& a, const Matrix3& b)
{
	a[0] -= b[0];
	a[1] -= b[1];
	a[2] -= b[2];
}


void phanes::core::math::coretypes::operator*=(Matrix3& a, float s)
{
	a[0] *= s;
	a[1] *= s;
	a[2] *= s;
}


void phanes::core::math::coretypes::operator*=(Matrix3& a, const Matrix3& b)
{
	Matrix3 c = a;
	a(0, 0) = c(0, 0) * b(0, 0) + c(0, 1) * b(1, 0) + c(0, 2) * b(2, 0);
	a(0, 1) = c(0, 0) * b(0, 1) + c(0, 1) * b(1, 1) + c(0, 2) * b(2, 1);
	a(0, 2) = c(0, 0) * b(0, 2) + c(0, 1) * b(1, 2) + c(0, 2) * b(2, 2);

	a(1, 0) = c(1, 0) * b(0, 0) + c(1, 1) * b(1, 0) + c(1, 2) * b(2, 0);
	a(1, 1) = c(1, 0) * b(0, 1) + c(1, 1) * b(1, 1) + c(1, 2) * b(2, 1);
	a(1, 2) = c(1, 0) * b(0, 2) + c(1, 1) * b(1, 2) + c(1, 2) * b(2, 2);

	a(2, 0) = c(2, 0) * b(0, 0) + c(2, 1) * b(1, 0) + c(2, 2) * b(2, 0);
	a(2, 1) = c(2, 0) * b(0, 1) + c(2, 1) * b(1, 1) + c(2, 2) * b(2, 1);
	a(2, 2) = c(2, 0) * b(0, 2) + c(2, 1) * b(1, 2) + c(2, 2) * b(2, 2);
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator+(const Matrix3& a, float s)
{
	Matrix3 m;
	m[0] = a[0] + s;
	m[1] = a[1] + s;
	m[2] = a[2] + s;
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator+(const Matrix3& a, const Matrix3& b)
{
	Matrix3 m;
	m[0] = a[0] + b[0];
	m[1] = a[1] + b[1];
	m[2] = a[2] + b[2];
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator-(const Matrix3& a, float s)
{
	Matrix3 m;
	m[0] = a[0] - s;
	m[1] = a[1] - s;
	m[2] = a[2] - s;
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator-(const Matrix3& a, const Matrix3& b)
{
	Matrix3 m;
	m[0] = a[0] - b[0];
	m[1] = a[1] - b[1];
	m[2] = a[2] - b[2];
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator*(const Matrix3& a, float s)
{
	Matrix3 m;
	m[0] = a[0] * s;
	m[1] = a[1] * s;
	m[2] = a[2] * s;
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::operator*(const Matrix3& a, const Matrix3& b)
{
	Matrix3 m;

	m(0, 0) = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0);
	m(0, 1) = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1);
	m(0, 2) = a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2);

	m(1, 0) = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0);
	m(1, 1) = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1);
	m(1, 2) = a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2);

	m(2, 0) = a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0);
	m(2, 1) = a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1);
	m(2, 2) = a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2);

	return m;
}


phanes::core::math::coretypes::Vector3 phanes::core::math::coretypes::operator*(const Matrix3& a, const Vector3& v)
{
	Vector3 b = createVector(
		a(0, 0) * v.x + a(0, 1) * v.y + a(0, 2) * v.z,
		a(1, 0) * v.x + a(1, 1) * v.y + a(1, 2) * v.z,
		a(2, 0) * v.x + a(2, 1) * v.y + a(2, 2) * v.z
	);
	return b;
}


bool phanes::core::math::coretypes::operator==(const Matrix3& a, const Matrix3& b)
{
	if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
		return true;
	}
	return false;
}


// =============================== //
//   Matrix function definition    //
// =============================== //


float phanes::core::math::coretypes::determinant(const Matrix3& a)
{
	return  (a(0, 0) * (a(1, 1) * a(2, 2) - a(1, 2) * a(2, 1))
			-a(0, 1) * (a(1, 0) * a(2, 2) - a(1, 2) * a(2, 0))
			+a(0, 2) * (a(1, 0) * a(2, 1) - a(1, 1) * a(2, 0)));
}


void phanes::core::math::coretypes::inverseNR(Matrix3& a)
{
	const Vector3& v0 = a[0];
	const Vector3& v1 = a[1];
	const Vector3& v2 = a[2];

	Vector3 r0 = crossP(v1, v2);
	Vector3 r1 = crossP(v2, v0);
	Vector3 r2 = crossP(v0, v1);
	
	float _1_det = 1.0f / determinant(a);

	a = createMatrix(
		r0.x, r0.y, r0.z,
		r1.x, r1.y, r1.z,
		r2.x, r2.y, r2.z
	);

	a *= _1_det;
}


void phanes::core::math::coretypes::transposeNR(Matrix3& a)
{
	swap(a(0, 1), a(1, 0));
	swap(a(0, 2), a(2, 0));
	swap(a(1, 2), a(2, 1));
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::inverse(Matrix3& a)
{
	const Vector3& v0 = a[0];
	const Vector3& v1 = a[1];
	const Vector3& v2 = a[2];

	Vector3 r0 = crossP(v1, v2);
	Vector3 r1 = crossP(v2, v0);
	Vector3 r2 = crossP(v0, v1);

	float _1_det = 1.0f / determinant(a);

	Matrix3 m = createMatrix(
		r0.x, r0.y, r0.z,
		r1.x, r1.y, r1.z,
		r2.x, r2.y, r2.z
	);

	m *= _1_det;
	return m;
}


phanes::core::math::coretypes::Matrix3 phanes::core::math::coretypes::transpose(const Matrix3& a)
{
	Matrix3 m = createMatrix(
		a(0, 0), a(1, 0), a(2, 0),
		a(0, 1), a(1, 1), a(2, 1),
		a(0, 2), a(1, 2), a(2, 2)
	);

	return m;
}


bool phanes::core::math::coretypes::isIndentityMatrix(const Matrix3& a)
{
	if (a == phanes::core::math::coretypes::createMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1)) {
		return true;
	}
	return false;
}