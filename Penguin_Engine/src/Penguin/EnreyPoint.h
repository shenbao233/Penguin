#pragma once

#ifdef PG_PLATFORM_WINDOWS

extern Penguin::Application* Penguin::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome!\n");
	auto app = Penguin::CreateApplication();
	app->Run();
	delete app;
}

#endif
