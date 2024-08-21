#include "pch.h"

#include "Core/public/Math/Include.h"
#include "Core/Core.h"

namespace PMath = Phanes::Core::Math;
using namespace Phanes::Core::Math::UnitLiterals;

namespace VectorTests
{
    TEST(Vector2, OperatorTests) 
    {
        PMath::Vector2 v0(2.4f, 3.1f);
        PMath::Vector2 v1(5.1f, 2.5f);

        v0 += v1;
        EXPECT_TRUE(v0 == PMath::Vector2(7.5f, 5.6f));
        
        v0 -= v1;
        EXPECT_TRUE(v0 == PMath::Vector2(2.4f, 3.1f));

        v0 *= v1;
        EXPECT_TRUE(v0 == PMath::Vector2(12.24f, 7.75f));

        v0 /= v1;
        EXPECT_TRUE(v0 == PMath::Vector2(2.4f, 3.1f));


        v0 += 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector2(6.4f, 7.1f));

        v0 -= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector2(2.4f, 3.1f));

        v0 *= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector2(9.6f, 12.4f));

        v0 /= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector2(2.4f, 3.1f));
                        
        // ------------------------------------------

        PMath::Vector2 r;

        r = v0 + v1;
        EXPECT_TRUE(r == PMath::Vector2(7.5f, 5.6f));
        
        r = v0 - v1;
        EXPECT_TRUE(r == PMath::Vector2(-2.7f, 0.6f));
        
        r = v0 * v1;
        EXPECT_TRUE(r == PMath::Vector2(12.24f, 7.75f));

        r = v0 / v1;
        EXPECT_TRUE(r == PMath::Vector2(0.470588f, 1.24f));



        r = v0 + 4.0f;
        EXPECT_TRUE(r == PMath::Vector2(6.4f, 7.1f));

        r = v0 - 4.0f;
        EXPECT_TRUE(r == PMath::Vector2(-1.6f, -0.9f));

        r = v0 * 4.0f;
        EXPECT_TRUE(r == PMath::Vector2(9.6f, 12.4f));

        r = v0 / 4.0f;
        EXPECT_TRUE(r == PMath::Vector2(0.6f, 0.775f));

        // --------------------------------------------

        EXPECT_TRUE(r != PMath::Vector2(0.480588f, 3.24f));

        EXPECT_FALSE(r != PMath::Vector2(0.6f, 0.775f));

    }

    TEST(Vector2, FunctionTest)
    {
        PMath::Vector2 v0(2.4f, 3.1f);
        PMath::Vector2 v1(5.1f, 2.5f);
        PMath::Vector2 v2(0.0f, 0.0f);

        EXPECT_FLOAT_EQ(PMath::Magnitude(v0), 3.9204591f);
        EXPECT_FLOAT_EQ(PMath::SqrMagnitude(v0), 15.37f);
        EXPECT_TRUE(PMath::NormalizeV(v0) == PMath::Vector2(0.612173f, 0.790724f));
        EXPECT_TRUE(PMath::NormalizeV(v2) == PMath::Vector2(0.0f, 0.0f));
        EXPECT_TRUE(PMath::IsNormalized(v0));
        EXPECT_TRUE(PMath::Abs(PMath::Angle(v0, v1) - 26.13928198243463_deg) < P_FLT_INAC);
        EXPECT_FLOAT_EQ(PMath::CosineAngle(v0,v1), 0.897725742f);
        EXPECT_TRUE(PMath::SignVectorV(v0) == PMath::Vector2(1, 1));
        EXPECT_TRUE(PMath::BindToSquareV(v1, 2.0f) == PMath::Vector2(2.0f, 0.9803921568f));

        // Re-init vectors.
        v0 = PMath::Vector2(2.4f, 3.1f);
        v1 = PMath::Vector2(5.1f, 2.5f);

        EXPECT_TRUE(PMath::ClampToSquareV(v0, 2.0f) == PMath::Vector2(1.5483870968f, 2.0f));
        EXPECT_FLOAT_EQ(PMath::DotP(v0, v1), 12.89677419368f);

        // Re-init vector
        v0 = PMath::Vector2(2.4f, 3.1f);

        EXPECT_TRUE(PMath::MaxV(v0, v1) == PMath::Vector2(5.1f, 3.1f));
        
        // Re-init vector
        v0 = PMath::Vector2(2.4f, 3.1f);

        EXPECT_TRUE(PMath::MinV(v0, v1) == PMath::Vector2(2.4f, 2.5f));

        EXPECT_TRUE(PMath::GetPerpendicularV(v0) == PMath::Vector2(2.5f, -2.4f));
        EXPECT_TRUE(PMath::GetReversePerpendicularV(v1) == PMath::Vector2(-2.5f, 5.1f));

        EXPECT_TRUE(PMath::ScaleV(v0, v1) == PMath::Vector2(-6.25f, -12.24f));
        EXPECT_TRUE(PMath::CompInverseV(v0) == PMath::Vector2(1.0f/-6.25f, 1.0f/-12.24f));

        // re-init vectors.
        v0 = PMath::Vector2(2.4f, 3.1f);
        v1 = PMath::Vector2(5.1f, 2.5f);

        PMath::Vector2 n(0.8320502943f, 0.554700196f);

        // std::cerr << PMath::ToString(PMath::Reflect(v0, n)) << std::endl;

        EXPECT_TRUE(PMath::ReflectV(v0, n) == PMath::Vector2(3.784616f, 1.023077f));
        
        // Re-init vectors.
        v0 = PMath::Vector2(2.4f, 3.1f);

        EXPECT_TRUE(PMath::RotateV(v0, (float)30.0_deg) == PMath::Vector2(0.528460969082653f, 3.88467875173176f));
        EXPECT_TRUE(PMath::ClockwiseRotateV(v0, (float)30.0_deg) == PMath::Vector2(2.4f, 3.1f));
        EXPECT_TRUE(PMath::NegateV(v0) == PMath::Vector2(-2.4f, -3.1f));
        EXPECT_TRUE(PMath::IsPerpendicular(v0, PMath::GetPerpendicular(v0))); // Tests GetPerpendicular too.
        EXPECT_TRUE(PMath::IsNormalized(n));
        EXPECT_FALSE(PMath::IsNormalized(v0));
        
        // Re-init vectors.
        v0 = PMath::Vector2(2.4f, 3.1f);
        v1 = PMath::Vector2(5.1f, 2.5f);
        
        EXPECT_TRUE(PMath::IsParallel(v0, PMath::Vector2(-7.2f, -9.3f)));
        EXPECT_TRUE(PMath::IsCoincident(v0, PMath::Vector2(7.2f, 9.3f)));
        EXPECT_FALSE(PMath::IsCoincident(v0, PMath::Vector2(-7.2f, -9.3f)));


        EXPECT_TRUE(PMath::Reflect(v0, n) == PMath::Vector2(3.784616f, 1.023077f));
        EXPECT_TRUE(PMath::Scale(v0, v1) == PMath::Vector2(12.24f, 7.75f));
        EXPECT_TRUE(PMath::CompInverse(v0) == PMath::Vector2(1.0f / 2.4f, 1.0f / 3.1f));
        EXPECT_TRUE(PMath::Negate(v0) == PMath::Vector2(-2.4f, -3.1f));
        EXPECT_TRUE(PMath::GetPerpendicular(v0) == PMath::Vector2(3.1f, -2.4f));
        EXPECT_TRUE(PMath::GetReversePerpendicular(v0) == PMath::Vector2(-3.1f, 2.4f));
        EXPECT_TRUE(PMath::Max(v0, v1) == PMath::Vector2(5.1f, 3.1f));
        EXPECT_TRUE(PMath::Min(v0, v1) == PMath::Vector2(2.4f, 2.5f));
        EXPECT_TRUE(PMath::Normalize(v0) == PMath::Vector2(0.612173f, 0.790724f));
        EXPECT_TRUE(PMath::SignVector(v0) == PMath::Vector2(1.0f, 1.0f));
        EXPECT_TRUE(PMath::BindToSquare(v1, 2.0f) == PMath::Vector2(2.0f, 0.9803921568f));
        EXPECT_TRUE(PMath::ClampToSquare(v0, 2.0f) == PMath::Vector2(1.5483870968f, 2.0f));
        EXPECT_TRUE(PMath::Lerp(v0, v1, 0.7f) == PMath::Vector2(4.29f, 2.68f));
        EXPECT_TRUE(PMath::Rotate(v0, (float)30.0_deg) == PMath::Vector2(0.528460969082653f, 3.88467875173176f));
        EXPECT_TRUE(PMath::ClockwiseRotate(v0, (float)30.0_deg) == PMath::Vector2(3.628461f, 1.484679f));
    }

    // --------------

    TEST(Vector3, OperatorTests)
    {
        PMath::Vector3 v0(2.4f, 3.1f, 5.6f);
        PMath::Vector3 v1(5.1f, 2.5f, 7.2f);
        

        v0 += v1;
        EXPECT_TRUE(v0 == PMath::Vector3(7.5f, 5.6f, 12.8f));

        v0 -= v1;
        EXPECT_TRUE(v0 == PMath::Vector3(2.4f, 3.1f, 5.6f));

        v0 *= v1;
        EXPECT_TRUE(v0 == PMath::Vector3(12.24f, 7.75f, 40.32f));

        v0 /= v1;
        EXPECT_TRUE(v0 == PMath::Vector3(2.4f, 3.1f, 5.6f));


        v0 += 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector3(6.4f, 7.1f, 9.6f));

        v0 -= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector3(2.4f, 3.1f, 5.6f));

        v0 *= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector3(9.6f, 12.4f, 22.4f));

        v0 /= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector3(2.4f, 3.1f, 5.6f));

        // ------------------------------------------

        PMath::Vector3 r;

        r = v0 + v1;
        EXPECT_TRUE(r == PMath::Vector3(7.5f, 5.6f, 12.8f));

        r = v0 - v1;
        EXPECT_TRUE(r == PMath::Vector3(-2.7f, 0.6f, -1.6f));

        r = v0 * v1;
        EXPECT_TRUE(r == PMath::Vector3(12.24f, 7.75f, 40.32f));

        r = v0 / v1;
        EXPECT_TRUE(r == PMath::Vector3(0.470588f, 1.24f, 0.777777777777f));



        r = v0 + 4.0f;
        EXPECT_TRUE(r == PMath::Vector3(6.4f, 7.1f, 9.6f));

        r = v0 - 4.0f;
        EXPECT_TRUE(r == PMath::Vector3(-1.6f, -0.9f, 1.6f));

        r = v0 * 4.0f;
        EXPECT_TRUE(r == PMath::Vector3(9.6f, 12.4f, 22.4f));

        r = v0 / 4.0f;
        EXPECT_TRUE(r == PMath::Vector3(0.6f, 0.775f, 1.4f));

        // --------------------------------------------

        EXPECT_TRUE(r != PMath::Vector3(0.480588f, 3.24f, 34.5f));

        EXPECT_FALSE(r != PMath::Vector3(0.6f, 0.775f, 1.4f));
    }

    TEST(Vector3, FunctionTest)
    {
        PMath::Vector3 v0(2.4f, 3.1f, 5.6f);
        PMath::Vector3 v1(5.1f, 2.5f, 7.2f);
        PMath::Vector3 v2(0.0f, 0.0f, 0.0f);
        PMath::Vector3 n(0.70710678f, 0.42426406f, 0.56568542f);

        EXPECT_FLOAT_EQ(PMath::Magnitude(v0), 6.835934464f);
        EXPECT_FLOAT_EQ(PMath::SqrMagnitude(v0), 46.73f);
        EXPECT_TRUE(PMath::NormalizeV(v0) == PMath::Vector3(0.351086f, 0.453486f, 0.8192f));
        EXPECT_TRUE(PMath::NormalizeV(v2) == PMath::Vector3(0.0f, 0.0f, 0.0f));
        EXPECT_TRUE(PMath::IsNormalized(v0));
        EXPECT_TRUE(PMath::Abs(PMath::Angle(v0, v1) - 15.8372675_deg) < P_FLT_INAC);
        EXPECT_FLOAT_EQ(PMath::CosineAngle(v0, v1), 0.962040687624f);
        EXPECT_TRUE(PMath::SignVectorV(v0) == PMath::Vector3(1, 1, 1));

        // Re-init vectors.
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);

        EXPECT_FLOAT_EQ(PMath::DotP(v0, v1), 60.31f);

        EXPECT_TRUE(PMath::MaxV(v0, v1) == PMath::Vector3(5.1f, 3.1f, 7.2f));

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);

        EXPECT_TRUE(PMath::MinV(v0, v1) == PMath::Vector3(2.4f, 2.5f, 5.6f));

        EXPECT_TRUE(PMath::ReflectV(v0, n) == PMath::Vector3(5.979999f, 2.5279994f, 1.1039991f));
        
        PMath::Vector3 up(PVectorUp3(float, false));
        PMath::Vector3 right(PVectorEast3(float, false));
        PMath::Vector3 front(5.4f, 0.0f, 0.0f);

        PMath::Orthogonalize(up, right, front);
        EXPECT_TRUE(PMath::DotP(up, front) == 0.0f);
        EXPECT_TRUE(PMath::DotP(right, front) == 0.0f);

        PMath::OrthoNormalize(up, right, front);
        EXPECT_TRUE(PMath::DotP(up, front) == 0.0f);
        EXPECT_TRUE(PMath::DotP(right, front) == 0.0f);
        EXPECT_FLOAT_EQ(PMath::Magnitude(front), 1.0f);

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);

        EXPECT_TRUE(PMath::PerspectiveDivideV(v0) == PMath::Vector3(0.4285714f, 0.55357142f, 0.0f));

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::CrossPV(v0,v1) == PMath::Vector3(8.32f,11.28f,-9.81f));
        EXPECT_TRUE(PMath::NegateV(v0) == PMath::Vector3(-8.32f, -11.28f, 9.81f));

        EXPECT_TRUE(PMath::ScaleV(v0, v1) == PMath::Vector3(-42.431988f, -28.199997f, 70.631996f));

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::ProjectV(v0, v1) == PMath::Vector3(3.65732461f, 1.7928061f, 5.16328180f));

        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::ClampToMagnitudeV(v0, 5.0f, 6.0f) == PMath::Vector3(2.1065165f, 2.7209172f, 4.91520539f));
        EXPECT_TRUE(PMath::ClampToMagnitudeV(v0, 5.0f, 7.0f) == PMath::Vector3(2.1065165f, 2.7209172f, 4.91520539f));

        EXPECT_TRUE(PMath::CompInverseV(v0) == PMath::Vector3(1.0f / 2.1065165f, 1.0f / 2.7209172f, 1.0f / 4.91520539f));

        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::ClampToCubeV(v0, 3.2f) == PMath::Vector3(2.4f, 3.1f, 3.2f));

        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::RotateAroundAxisV(v0, PMath::Vector3(0.0f, 0.0f, 1.0f), (float)30.0_deg) == PMath::Vector3(3.628461f, 1.484679f, 5.600000f)) << PMath::ToString(PMath::RotateAroundAxisV(v0, PMath::Vector3(0.0f, 0.0f, 1.0f), (float)30.0_deg));
        
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::ScaleToMagnitudeV(v0, 6.0f) == PMath::Vector3(2.1065165f, 2.7209172f, 4.91520539f));

        EXPECT_TRUE(PMath::SignVectorV(v0) == PMath::Vector3(1.0f, 1.0f, 1.0f));

        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::VectorTriple(v0, v1, PMath::Vector3(3.5f, 2.6f, 8.7f)) == CrossP(CrossP(v0, v1), PMath::Vector3(3.5f, 2.6f, 8.7f)));


        EXPECT_TRUE(PMath::IsPerpendicular(PMath::RejectV(v0, v1), v1));

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::IsParallel(v0, PMath::Vector3(-12.0f, -15.5f, -28.0f)));

        EXPECT_TRUE(PMath::IsCoincident(v0, PMath::Vector3(12.0f, 15.5f, 28.0f)));

        EXPECT_TRUE(PMath::IsCoplanar(v0, v1, PMath::Vector3(4.08f, 1.8666666f, 13.44f)));




        EXPECT_FLOAT_EQ(PMath::SqrMagnitude(PMath::Normalize(v0)), 1.0f);
        EXPECT_TRUE(PMath::SignVector(v0) == PMath::Vector3(1, 1, 1));
        EXPECT_TRUE(PMath::Reflect(v0, n) == PMath::Vector3(6.3399987f, 2.1439996f, 1.3919992f));
        EXPECT_TRUE(PMath::PerspectiveDivide(v0) == PMath::Vector3(0.428571428f, 0.553571428571f, 0.0f));
        EXPECT_TRUE(PMath::CrossP(v0, v1) == PMath::Vector3(8.32f, 11.28f, -9.81f));
        EXPECT_TRUE(PMath::Lerp(v0, v1, 0.7f) == PMath::Vector3(4.29f, 2.68f, 6.72f));
        EXPECT_TRUE(PMath::Max(v0,v1) == PMath::Vector3(5.1f, 3.1f, 7.2f));
        EXPECT_TRUE(PMath::Min(v0, v1) == PMath::Vector3(2.4f, 2.5f, 5.6f));
        EXPECT_TRUE(PMath::Negate(v0) == PMath::Vector3(-2.4f, -3.1f, -5.6f));
        EXPECT_TRUE(PMath::Scale(v0, v1) == PMath::Vector3(12.24f, 7.75f, 40.32f));
        EXPECT_TRUE(PMath::ClampToMagnitude(v0, 5.0f, 6.0f) == PMath::Vector3(2.1065165f, 2.7209172f, 4.91520539f));
        EXPECT_TRUE(PMath::ClampToMagnitude(v0, 5.0f, 7.0f) == v0) << PMath::ToString(PMath::ClampToMagnitude(v0, 5.0f, 6.0f));
        EXPECT_TRUE(PMath::ClampToCube(v0, 3.2f) == PMath::Vector3(2.4f, 3.1f, 3.2f));
        EXPECT_TRUE(PMath::ScaleToMagnitude(v0, 6.0f) == PMath::Vector3(2.1065165f, 2.7209172f, 4.91520539f));
        EXPECT_TRUE(PMath::CompInverse(v0) == PMath::Vector3(1.0f / 2.4f, 1.0f / 3.1f, 1.0f / 5.6f));
        EXPECT_TRUE(PMath::RotateAroundAxis(v0, PMath::Vector3(0,0,1), (float)30.0_deg) == PMath::Vector3(3.628461f, 1.484679f, 5.600000f));
        EXPECT_TRUE(PMath::VectorTriple(v0, v1, PMath::Vector3(3.5f,2.6f,8.7f)) == CrossP(CrossP(v0, v1), PMath::Vector3(3.5f, 2.6f, 8.7f)));
        EXPECT_TRUE(PMath::Project(v0, v1) == PMath::Vector3(3.657324613f, 1.792806183f, 5.163281807f));
        EXPECT_TRUE(PMath::Reject(v0, v1) == PMath::Vector3(-1.257324613f, 1.307193817f, 0.436718193f));
    }

    TEST(Vector4, OperatorTests)
    {
        PMath::Vector4 v0(2.4f, 3.1f, 5.6f, -3.7f);
        PMath::Vector4 v1(5.1f, 2.5f, 7.2f, 2.6f);


        v0 += v1;
        EXPECT_TRUE(v0 == PMath::Vector4(7.5f, 5.6f, 12.8f, -1.1f));

        v0 -= v1;
        EXPECT_TRUE(v0 == PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f));

        v0 *= v1;
        EXPECT_TRUE(v0 == PMath::Vector4(12.24f, 7.75f, 40.32f, -9.62f));

        v0 /= v1;
        EXPECT_TRUE(v0 == PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f));


        v0 += 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector4(6.4f, 7.1f, 9.6f, 0.3f));

        v0 -= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f));

        v0 *= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector4(9.6f, 12.4f, 22.4f, -14.8f));

        v0 /= 4.0f;
        EXPECT_TRUE(v0 == PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f));

        // ------------------------------------------

        PMath::Vector4 r;

        r = v0 + v1;
        EXPECT_TRUE(r == PMath::Vector4(7.5f, 5.6f, 12.8f, -1.1f));

        r = v0 - v1;
        EXPECT_TRUE(r == PMath::Vector4(-2.7f, 0.6f, -1.6f, -6.3f));

        r = v0 * v1;
        EXPECT_TRUE(r == PMath::Vector4(12.24f, 7.75f, 40.32f, -9.62f));

        r = v0 / v1;
        EXPECT_TRUE(r == PMath::Vector4(0.470588f, 1.24f, 0.777777777777f, -1.423076923076f));



        r = v0 + 4.0f;
        EXPECT_TRUE(r == PMath::Vector4(6.4f, 7.1f, 9.6f, 0.3f));

        r = v0 - 4.0f;
        EXPECT_TRUE(r == PMath::Vector4(-1.6f, -0.9f, 1.6f, -7.7f));

        r = v0 * 4.0f;
        EXPECT_TRUE(r == PMath::Vector4(9.6f, 12.4f, 22.4f, -14.8f));

        r = v0 / 4.0f;
        EXPECT_TRUE(r == PMath::Vector4(0.6f, 0.775f, 1.4f, -0.925f));

        // --------------------------------------------

        EXPECT_TRUE(r != PMath::Vector4(0.480588f, 3.24f, 34.5f, 73.3f));

        EXPECT_FALSE(r != PMath::Vector4(0.6f, 0.775f, 1.4f, -0.925f));
    }

    TEST(Vector4, FunctionTest)
    {
        PMath::Vector4 v0(2.4f, 3.1f, 5.6f, -3.7f);
        PMath::Vector4 v1(5.1f, 2.5f, 7.2f, 2.6f);
        PMath::Vector4 n(0.535037f, 0.262273f, 0.755346f, 0.272764f);


        EXPECT_FLOAT_EQ(PMath::Magnitude(v0), 7.773030297f);

        EXPECT_FLOAT_EQ(PMath::SqrMagnitude(v0), 60.42f);

        EXPECT_FLOAT_EQ(PMath::Angle(v0, v1), (float)46.83191757_deg);

        EXPECT_FLOAT_EQ(PMath::CosineAngle(v0, v1), 0.68414091f);

        EXPECT_FLOAT_EQ(PMath::Magnitude(PMath::NormalizeV(v0)), 1.0f);

        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_FLOAT_EQ(PMath::DotP(v0, v1), 50.69f);
        
        EXPECT_TRUE(PMath::MaxV(v0, v1) == PMath::Vector4(5.1f, 3.1f, 7.2f, 2.6f)) << PMath::ToString(v0);

        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::MinV(v0, v1) == PMath::Vector4(2.4f, 2.5f, 5.6f, -3.7f)) << PMath::ToString(v0);

        EXPECT_TRUE(PMath::NegateV(v0) == PMath::Vector4(-2.4f, -2.5f, -5.6f, 3.7f)) << PMath::ToString(v0);
        
        EXPECT_TRUE(PMath::CompInverseV(v0) == PMath::Vector4(1.0f / -2.4f, 1.0f / -2.5f, 1.0f / -5.6f, 1.0f / 3.7f)) << PMath::ToString(v0);
        
        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::ClampToMagnitudeV(v0, 6.0f, 7.0f) == PMath::Vector4(2.1613193f, 2.791704135f, 5.043078439f, -3.332034f)) << PMath::ToString(v0);

        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::ScaleToMagnitudeV(v0, 7.0f) == PMath::Vector4(2.1613193f, 2.791704135f, 5.043078439f, -3.332034f)) << PMath::ToString(v0);

        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::ReflectV(v0, n) == PMath::Vector4(3.290488f, -0.310545f, 2.433628f, 6.601034f));
        
        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::ProjectV(v0, v1) == PMath::Vector4(2.845245432533568f, 1.394728153202729f, 4.016817081223861f, 1.450517279330839f));
        
        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::RejectV(v0, v1) == PMath::Vector4(-0.445245432533f, 1.705271846797271f, 1.583182918776139f, -5.150517279330839f));

        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_TRUE(PMath::PerspectiveDivideV(v0) == PMath::Vector4(2.4f / -3.7f, 3.1f / -3.7f, 5.6f / -3.7f, 0.0f));

        EXPECT_TRUE(PMath::IsNormalized(PMath::NormalizeV(v0)));

        EXPECT_TRUE(PMath::IsParallel(v0, v0 * (- 3.0f)));
        
        EXPECT_TRUE(PMath::IsCoincident(v0, v0 * 3.0f));


        v0 = PMath::Vector4(2.4f, 3.1f, 5.6f, -3.7f);
        EXPECT_FLOAT_EQ(PMath::SqrMagnitude(PMath::Normalize(v0)), 1.0f);
        EXPECT_TRUE(PMath::Max(v0, v1) == PMath::Vector4(5.1f, 3.1f, 7.2f, 2.6f));
        EXPECT_TRUE(PMath::Min(v0, v1) == PMath::Vector4(2.4f, 2.5f, 5.6f, -3.7f));
        EXPECT_TRUE(PMath::ClampToMagnitude(v0, 6.0f, 7.0f) == PMath::Vector4(2.1613193f, 2.791704135f, 5.043078439f, -3.332034f)) << PMath::ToString(PMath::Magnitude(v0));
        EXPECT_TRUE(PMath::ScaleToMagnitude(v0, 7.0f) == PMath::Vector4(2.1613193f, 2.791704135f, 5.043078439f, -3.332034f)) << PMath::ToString(v0);
        EXPECT_TRUE(PMath::Reflect(v0, n) == PMath::Vector4(3.290488f, -0.310545f, 2.433628f, 6.601034f));
        EXPECT_TRUE(PMath::Project(v0, v1) == PMath::Vector4(2.845245432533568f, 1.394728153202729f, 4.016817081223861f, 1.450517279330839f));
        EXPECT_FLOAT_EQ(PMath::Angle(PMath::Reject(v0, v1), v1), 1.570796f);
        EXPECT_TRUE(PMath::PerspectiveDivide(v0) == PMath::Vector4(2.4f / -3.7f, 3.1f / -3.7f, 5.6f / -3.7f, 0.0f));
        EXPECT_TRUE(PMath::Negate(v0) == PMath::Vector4(-2.4f, -3.1f, -5.6f, 3.7f));

        EXPECT_TRUE(PMath::CompInverseV(v0) == PMath::Vector4(1.0f / 2.4f, 1.0f / 3.1f, 1.0f / 5.6f, 1.0f / -3.7f));
    }
}

namespace MatrixTests
{
    TEST(Matrix2, OperatorTests)
    {

        PMath::Matrix2 m0 = PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f);

        m0 += 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(3.0f, 7.0f, 5.0f, 4.0f));

        m0 -= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));

        m0 *= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(2.0f, 10.0f, 6.0f, 4.0f));

        m0 /= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));


        m0 = m0 + 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(3.0f, 7.0f, 5.0f, 4.0f));

        m0 = m0 - 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));

        m0 = m0 * 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(2.0f, 10.0f, 6.0f, 4.0f));

        m0 = m0 / 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));

        


        PMath::Matrix2 m1 = PMath::Matrix2(2.0f, 4.0f, 1.0f, 3.0f);
        
        m0 += m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(3.0f, 9.0f, 4.0f, 5.0f));
        
        m0 -= m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));
        
        m0 *= m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(7.0f, 19.0f, 8.0f, 18.0f));
        


        m0 = PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f);

        m0 = m0 + m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(3.0f, 9.0f, 4.0f, 5.0f));

        m0 = m0 - m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f));

        m0 = m0 * m1;
        EXPECT_TRUE(m0 == PMath::Matrix2(7.0f, 19.0f, 8.0f, 18.0f));

        PMath::Vector2 v = PMath::Vector2(2.0f, 4.0f);

        v = m0 * v;
        EXPECT_TRUE(v == PMath::Vector2(90.0f, 88.0f)) << PMath::ToString(v);

        EXPECT_TRUE(m0 != m1);
    }

    TEST(Matrix2, FunctionTest)
    {
        PMath::Matrix2 m0 = PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f);

        EXPECT_FLOAT_EQ(PMath::Determinant(m0), -13.0f);

        EXPECT_TRUE(PMath::InverseV(m0) == PMath::Matrix2(-2.0f / 13.0f, 5.0f / 13.0f, 3.0f / 13.0f, -1.0f / 13.0f));

        m0 = PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f);
        EXPECT_TRUE(PMath::TransposeV(m0) == PMath::Matrix2(1.0f, 3.0f, 5.0f, 2.0f));


        m0 = PMath::Matrix2(1.0f, 5.0f, 3.0f, 2.0f);

        EXPECT_TRUE(PMath::Inverse(m0) == PMath::Matrix2(-2.0f / 13.0f, 5.0f / 13.0f, 3.0f / 13.0f, -1.0f / 13.0f)) << PMath::ToString(PMath::Inverse(m0));
        EXPECT_TRUE(PMath::Transpose(m0) == PMath::Matrix2(1.0f, 3.0f, 5.0f, 2.0f));
        EXPECT_FALSE(PMath::IsIdentityMatrix(m0));
        EXPECT_TRUE(PMath::IsIdentityMatrix(PMath::Matrix2(1.0f, 0.0f, 
                                                           0.0f, 1.0f)));
    }


    TEST(Matrix3, OperationTests)
    {
        PMath::Matrix3 m0 = PMath::Matrix3(1.0f, 5.0f, 3.0f, 
                                           2.0f, 6.0f, 4.0f, 
                                           2.0f, -3.0f, 5.0f);

        m0 += 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(3.0f, 7.0f, 5.0f, 4.0f, 8.0f, 6.0f, 4.0f, -1.0f, 7.0f));

        m0 -= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));

        m0 *= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(2.0f, 10.0f, 6.0f, 4.0f, 12.0f, 8.0f, 4.0f, -6.0f, 10.0f));

        m0 /= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));


        m0 = m0 + 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(3.0f, 7.0f, 5.0f, 4.0f, 8.0f, 6.0f, 4.0f, -1.0f, 7.0f));

        m0 = m0 - 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));

        m0 = m0 * 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(2.0f, 10.0f, 6.0f, 4.0f, 12.0f, 8.0f, 4.0f, -6.0f, 10.0f));

        m0 = m0 / 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));




        PMath::Matrix3 m1 = PMath::Matrix3(2.0f, 4.0f, 1.0f,
                                           3.0f, 4.0f, -3.0f,
                                           1.0f, 6.0f, 3.0f);

        m0 += m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(3.0f, 9.0f, 4.0f, 5.0f, 10.0f, 1.0f, 3.0f, 3.0f, 8.0f));

        m0 -= m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));

        m0 *= m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(20.0f, 42.0f, -5.0f, 26.0f, 56.0f, -4.0f, 0.0f, 26.0f, 26.0f)) << PMath::ToString(m0);



        m0 = PMath::Matrix3(1.0f, 5.0f, 3.0f,
                            2.0f, 6.0f, 4.0f,
                            2.0f, -3.0f, 5.0f);

        m0 = m0 + m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(3.0f, 9.0f, 4.0f, 5.0f, 10.0f, 1.0f, 3.0f, 3.0f, 8.0f));

        m0 = m0 - m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(1.0f, 5.0f, 3.0f, 2.0f, 6.0f, 4.0f, 2.0f, -3.0f, 5.0f));

        m0 = m0 * m1;
        EXPECT_TRUE(m0 == PMath::Matrix3(20.0f, 42.0f, -5.0f, 26.0f, 56.0f, -4.0f, 0.0f, 26.0f, 26.0f));

        PMath::Vector3 v = PMath::Vector3(2.0f, 4.0f, 3.0f);

        m0 = PMath::Matrix3(1.0f, 5.0f, 3.0f,
                            2.0f, 6.0f, 4.0f,
                            2.0f, -3.0f, 5.0f);

        v = m0 * v;
        EXPECT_TRUE(v == PMath::Vector3(31.0f, 40.0f, 7.0f)) << PMath::ToString(v);

        EXPECT_TRUE(m0 != m1);
    }

    TEST(Matrix3, FunctionTest)
    {
        PMath::Matrix3 m0 = PMath::Matrix3(1.0f, 5.0f, 3.0f,
                                           2.0f, 6.0f, 4.0f,
                                           2.0f, -3.0f, 5.0f);

        EXPECT_FLOAT_EQ(PMath::Determinant(m0), -22.0f);

        PMath::InverseV(m0);
        EXPECT_TRUE(m0 == PMath::Matrix3(-21.0f/11.0f, 17.0f/11.0f, -1.0f/11.0f,
                                         1.0f/11.0f, 1.0f/22.0f, -1.0f/11.0f,
                                         9.0f/11.0f, -13.0f/22.0f, 2.0f/11.0f));

        PMath::TransposeV(m0);

        EXPECT_TRUE(m0 == PMath::Matrix3(-21.0f/11.0f, 1.0f/11.0f, 9.0f/11.0f,
                                         17.0f/11.0f, 1.0f/22.0f, -13.0f/22.0f,
                                         -1.0f/11.0f, -1.0f/11.0f, 2.0f/11.0f));

        m0 = PMath::Matrix3(1.0f, 5.0f, 3.0f,
                            2.0f, 6.0f, 4.0f,
                            2.0f, -3.0f, 5.0f);


        
        Phanes::Ref<PMath::Matrix3> tmp = Phanes::MakeRef<PMath::Matrix3>();
        PMath::Inverse(m0, tmp);
        EXPECT_TRUE(PMath::IsIdentityMatrix(m0 * (*tmp)));

        EXPECT_TRUE(PMath::Transpose(m0) == PMath::Matrix3(1.0f, 2.0f, 2.0f,
                                                           5.0f, 6.0f, -3.0f,
                                                           3.0f, 4.0f, 5.0f));
    }

    TEST(Matrix4, OperationTests)
    {
        PMath::Matrix4 m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 
                                           2.0f, 6.0f, 4.0f, 1.0f, 
                                           2.0f, -3.0f, 5.0f, 3.0f, 
                                           8.0f, -4.0f, 6.0f, -2.0f);

        m0 += 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(3.0f, 7.0f, 5.0f, 6.0f,
                                         4.0f, 8.0f, 6.0f, 3.0f, 
                                         4.0f, -1.0f, 7.0f, 5.0f, 
                                         10.0f, -2.0f, 8.0f, 0.0f));

        m0 -= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));

        m0 *= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(2.0f, 10.0f, 6.0f, 8.0f, 4.0f, 12.0f, 8.0f, 2.0f, 4.0f, -6.0f, 10.0f, 6.0f, 16.0f, -8.0f, 12.0f, -4.0f));

        m0 /= 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));


        m0 = m0 + 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(3.0f, 7.0f, 5.0f, 6.0f,
                                         4.0f, 8.0f, 6.0f, 3.0f,
                                         4.0f, -1.0f, 7.0f, 5.0f,
                                         10.0f, -2.0f, 8.0f, 0.0f)) << PMath::ToString(m0);

        m0 = m0 - 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));

        m0 = m0 * 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(2.0f, 10.0f, 6.0f, 8.0f, 4.0f, 12.0f, 8.0f, 2.0f, 4.0f, -6.0f, 10.0f, 6.0f, 16.0f, -8.0f, 12.0f, -4.0f));

        m0 = m0 / 2.0f;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));




        PMath::Matrix4 m1 = PMath::Matrix4(2.0f, 4.0f, 1.0f, 9.0f, 
                                           3.0f, 4.0f, -3.0f, 2.0f, 
                                           1.0f, 6.0f, 3.0f, -4.0f, 
                                           6.0f, 4.0f, 7.0f, 3.0f);

        m0 += m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(3.0f, 9.0f, 4.0f, 13.0f, 5.0f, 10.0f, 1.0f, 3.0f, 3.0f, 3.0f, 8.0f, -1.0f, 14.0f, 0.0f, 13.0f, 1.0f));

        m0 -= m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));

        m0 *= m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(44.0f, 58.0f, 23.0f, 19.0f, 32.0f, 60.0f, 3.0f, 17.0f, 18.0f, 38.0f, 47.0f, 1.0f, -2.0f, 44.0f, 24.0f, 34.0f)) << PMath::ToString(m0);



        m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                            2.0f, 6.0f, 4.0f, 1.0f,
                            2.0f, -3.0f, 5.0f, 3.0f,
                            8.0f, -4.0f, 6.0f, -2.0f);


        m0 = m0 + m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(3.0f, 9.0f, 4.0f, 13.0f, 5.0f, 10.0f, 1.0f, 3.0f, 3.0f, 3.0f, 8.0f, -1.0f, 14.0f, 0.0f, 13.0f, 1.0f));

        m0 = m0 - m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f, 2.0f, 6.0f, 4.0f, 1.0f, 2.0f, -3.0f, 5.0f, 3.0f, 8.0f, -4.0f, 6.0f, -2.0f));

        m0 = m0 * m1;
        EXPECT_TRUE(m0 == PMath::Matrix4(44.0f, 58.0f, 23.0f, 19.0f, 32.0f, 60.0f, 3.0f, 17.0f, 18.0f, 38.0f, 47.0f, 1.0f, -2.0f, 44.0f, 24.0f, 34.0f));

        PMath::Vector4 v = PMath::Vector4(2.0f, 4.0f, 3.0f, 5.0f);

        m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                            2.0f, 6.0f, 4.0f, 1.0f,
                            2.0f, -3.0f, 5.0f, 3.0f,
                            8.0f, -4.0f, 6.0f, -2.0f);

        v = m0 * v;
        EXPECT_TRUE(v == PMath::Vector4(51.0f, 45.0f, 22.0f, 8.0f)) << PMath::ToString(v);

        EXPECT_TRUE(m0 != m1);
    }

    TEST(Matrix4, FunctionTest)
    {
        PMath::Matrix4 m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                                           2.0f, 6.0f, 4.0f, 1.0f,
                                           2.0f, -3.0f, 5.0f, 3.0f,
                                           8.0f, -4.0f, 6.0f, -2.0f);

        EXPECT_FLOAT_EQ(PMath::Determinant(m0), -662.0f);

        PMath::InverseV(m0);
        EXPECT_TRUE(m0 == PMath::Matrix4(0.359516f, -0.280966f, -0.244712f, 0.211480f,
                                         0.042296f, 0.084592f, -0.087613f, -0.004531f,
                                         -0.332326f, 0.335347f, 0.259818f, -0.107250f,
                                         0.356495f, -0.287009f, -0.024169f, 0.033232f)) << PMath::ToString(m0);

        m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                            2.0f, 6.0f, 4.0f, 1.0f,
                            2.0f, -3.0f, 5.0f, 3.0f,
                            8.0f, -4.0f, 6.0f, -2.0f);

        PMath::TransposeV(m0);

        EXPECT_TRUE(m0 == PMath::Matrix4(1.0f, 2.0f, 2.0f, 8.0f, 5.0f, 6.0f, -3.0f, -4.0f, 3.0f, 4.0f, 5.0f, 6.0f, 4.0f, 1.0f, 3.0f, -2.0f));
        
        m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                            2.0f, 6.0f, 4.0f, 1.0f,
                            2.0f, -3.0f, 5.0f, 3.0f,
                            8.0f, -4.0f, 6.0f, -2.0f);



        Phanes::Ref<PMath::Matrix4> tmp = Phanes::MakeRef<PMath::Matrix4>();
        PMath::Inverse(m0, tmp);
        EXPECT_TRUE(*tmp == PMath::Matrix4(0.359516f, -0.280966f, -0.244712f, 0.211480f,
                                           0.042296f, 0.084592f, -0.087613f, -0.004531f,
                                           -0.332326f, 0.335347f, 0.259818f, -0.107250f,
                                           0.356495f, -0.287009f, -0.024169f, 0.033232f));

        EXPECT_TRUE(PMath::Transpose(m0) == PMath::Matrix4(1.0f, 2.0f, 2.0f, 8.0f, 5.0f, 6.0f, -3.0f, -4.0f, 3.0f, 4.0f, 5.0f, 6.0f, 4.0f, 1.0f, 3.0f, -2.0f));
    }
}