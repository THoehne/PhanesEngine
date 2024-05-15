#include "Core/public/Math/Vector2.h"

namespace PMath = Phanes::Core::Math;

int main()
{
  float t = 2;
  PMath::Clamp(t, 2.0f, 4.0f);
    

  return 0;
}