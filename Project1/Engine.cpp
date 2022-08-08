#include "Engine.h"
#include <iostream>

double Engine::Vh()
{
	return M * 0.01 + V * V * 0.0001;
}

double Engine::Vc(double ambientTemperature, double engineTemperature)
{
	return 0.1 * (ambientTemperature - engineTemperature);
}
