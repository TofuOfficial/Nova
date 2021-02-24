#pragma once

#ifdef NOVA_PLATFORM_WINDOWS

extern Nova::Application* Nova::CreateApplication();

int main(int argc, char** argv)
{
	Nova::Log::Init();

	NOVA_CORE_TRACE("Sandbox Initialized");

	auto app = Nova::CreateApplication();
	app->Run();
	delete app;
}

#endif