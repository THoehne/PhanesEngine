#include "pch.h"

#include "Core/public/Math/Include.h"

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
        std::cerr << PMath::ToString(PMath::Lerp(v0, v1, 0.7f)) << std::endl;
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
        EXPECT_TRUE(PMath::CrossPV(v0,v1) == PMath::Vector3(8.32f,11.28,-9.81));
        EXPECT_TRUE(PMath::NegateV(v0) == PMath::Vector3(-8.32f, -11.28f, 9.81f));
        EXPECT_TRUE(PMath::ScaleV(v0, v1) == PMath::Vector3(-42.432f, -28.2f, 70.632f));

        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
        EXPECT_TRUE(PMath::ProjectV(v0, v1) == PMath::Vector3(3.65732461f, 1.7928061f, 5.16328180f));

        EXPECT_TRUE(PMath::IsPerpendicular(PMath::Reject(v0, v1), v1));
        // std::cerr << PMath::ToString(PMath::Magnitude(v0)) << std::endl;
        // Re-init vector
        v0 = PMath::Vector3(2.4f, 3.1f, 5.6f);
    }
}