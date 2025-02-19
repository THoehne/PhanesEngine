#include <iostream>
#include "Core/Math/Include.h"

namespace PMath = Phanes::Core::Math;

int main() 
{
    PMath::Matrix4 m0 = PMath::Matrix4(1.0f, 5.0f, 3.0f, 4.0f,
                                           2.0f, 6.0f, 4.0f, 1.0f,
                                           2.0f, -3.0f, 5.0f, 3.0f,
                                           8.0f, -4.0f, 6.0f, -2.0f);


    PMath::Matrix4 m2;

    std::cout << std::to_string(PMath::InverseV<float, false>(m0)) << std::endl;

    std::cout << PMath::ToString(m0) << std::endl;

    return 0;
}