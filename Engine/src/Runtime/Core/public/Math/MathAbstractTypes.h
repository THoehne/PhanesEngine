#pragma once

#ifndef ABSTRACT_TYPES_H
#define ABSTRACT_TYPES_H

namespace Phanes::Core::Math::Internal {

  template <typename T, unsigned int D = 3>
  struct AVector {
  public:

    /**
     * List of n components of the vector
     */

    T comp[D];

  };

  template <typename T, unsigned int n = 3, unsigned int m = 3>
  struct AMatrix {
  public:
    T fields[n][m];

  };

}; // Phanes::Core::Math::abstract::coretypes

#endif // !ABSTRACT_TYPES_H