#include "Core/public/Math/MathPCH.h"


#include <iostream>
#include <chrono>



namespace PMath = Phanes::Core::Math;


int main()
{

    PMath::TMatrix2<float> m1(7.3f,4.3f,
                              9.4f,2.5f);

    

    
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