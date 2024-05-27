#include <iostream>
#include <chrono>

#include "Core/public/Math/Vector4.hpp"

namespace PMath = Phanes::Core::Math;

int main()
{
    PMath::TVector4<float, true> vec0{ 3.4f, 2.3f, 1.2f, 7.5f };
    PMath::TVector4<float, true> vec1{ 7.5f, 3.4f, 2.7f, 2.6f };

    
    /*for (int i = 0; i < 10; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        
        for (size_t i = 0; i < 999999; i++)
        {
            
        }
        auto end = std::chrono::high_resolution_clock::now();
    
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    }*/
    // vec0 += vec1;

    std::cout << vec0.x << " " << vec0.y << " " << vec0.z << " " << vec0.w << std::endl;

    return 0;

}