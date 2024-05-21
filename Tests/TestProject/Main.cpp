#include "Core/public/Math/Plane.hpp"


#include <iostream>
#include <chrono>



namespace PMath = Phanes::Core::Math;


int main()
{


    
    for (int i = 0; i < 10; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        
        for (size_t i = 0; i < 999999; i++)
        {

        
        }
        auto end = std::chrono::high_resolution_clock::now();
    
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    }
    

    return 0;

}