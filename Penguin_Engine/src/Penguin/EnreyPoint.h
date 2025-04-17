#pragma once

#ifdef PG_PLATFORM_WINDOWS

extern Penguin::Application* Penguin::CreateApplication();

int main(int argc, char** argv)
{ 
	Penguin::Log::Init();
	PG_CORE_WARN("Initialized Log£¡");
	int a = 5;
	PG_CLIENT_INFO("Hello£¡ Var = {}", a);

	auto app = Penguin::CreateApplication();
	app->Run();
	delete app;
	
}

#endif
