#pragma once

#ifdef NOVA_PLATFORM_WINDOWS

	#ifdef NOVA_BUILD_DLL

		#define NOVA_API __declspec(dllexport)

	#else

		#define NOVA_API __declspec(dllimport)

	#endif // NOVA_BUILD_DLL

#endif // NOVA_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#ifdef NOVA_ENABLE_ASSERTS

	#define NOVA_ASSERT(x, ...) { if(!(x)) { NOVA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

	#define NOVA_CORE_ASSERT(x, ...) { if(!(x)) { NOVA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#else

	#define NOVA_ASSERT(x, ...)

	#define NOVA_CORE_ASSERT(x, ...)

#endif // NOVA_ENABLE_ASSERTS

namespace Nova
{

}