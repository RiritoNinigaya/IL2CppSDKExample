#pragma once
#include <il2cpp-api.h>
#include <il2cpp-config.h>
#include <il2cpp-metadata.h>
#include <il2cpp-api-types.h>
#include <Windows.h>
typedef void (*il2cpp_shutdown_t)();

namespace IL2CPPSDK {
	il2cpp_shutdown_t il2cpp_shutdown = nullptr;
	auto modulehandle_gameasm = GetModuleHandle((LPCWSTR)"GameAssembly.dll");
	void Initialize() {
		il2cpp_shutdown = reinterpret_cast<il2cpp_shutdown_t>(GetProcAddress(modulehandle_gameasm, "il2cpp_shutdown"));
		il2cpp_shutdown();
	}
}