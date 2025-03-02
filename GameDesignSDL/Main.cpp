#include "Text.h"

int main(int argc, char** argv)
{
	Text text;

	bool success = text.Initialize();

	if (success)
	{
		text.RunLoop();
	}

	text.Shutdown();
	
	return 0;
}