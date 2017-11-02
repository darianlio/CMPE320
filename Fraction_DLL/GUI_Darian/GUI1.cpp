#include "GUI1.h"

using namespace GUIDarian;

[System::STAThread]
int main() {
	GUI^ g = gcnew GUI();
	Application::Run(g);
	return 0;
}
