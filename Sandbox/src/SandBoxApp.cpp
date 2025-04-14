#include <Penguin.h>

class Sandbox : public Penguin::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Penguin::Application* Penguin::CreateApplication()
{
	return new Sandbox();
}