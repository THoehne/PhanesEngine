#include <iostream>

#include "Core/Math/Include.h"

int main(int argc, char **argv)  {
    Phanes::Core::Math::Vector3 v1(1.0f, 2.0f, 3.0f);
    Phanes::Core::Math::Vector3 v2(1.0f, 2.0f, 3.0f);

    Phanes::Core::Math::Vector3 v3 = v1 + v2;

    std::cout << "v3: " << Phanes::Core::Math::ToString(v3) << std::endl;
}