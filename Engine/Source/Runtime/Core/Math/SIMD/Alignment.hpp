#pragma once

#include <cstdlib>
#include <cstring>
#include <type_traits>

namespace Phanes::Core::Math::SIMD
{
	// Structure to conveniently align arrays.
	template <typename T, size_t L, size_t Align>
	struct alignas(Align) AlignedVec
	{
	public:
		static_assert(std::is_trivially_copyable_v<T>,
					  "Alignment.hpp: AlignedVecSSE must be trivially copyable.");
		static_assert(Align >= alignof(T) && (Align & (Align - 1)) == 0,
					  "Alignment.hpp: Alignment must be a power of two and >= alignof(T).");
		T data[L];

		explicit AlignedVec(const T* n_aligned_data)
		{
			std::memcpy(data, n_aligned_data, sizeof(T) * L);
		}

		const T* Get() const
		{
			return data;
		}
	};

	template <typename T, size_t L>
	using AlignedVecSSE = AlignedVec<T, L, 16>;

	template <typename T, size_t L>
	using AlignedVecAVX = AlignedVec<T, L, 32>;
} // namespace Phanes::Core::Math::SIMD
