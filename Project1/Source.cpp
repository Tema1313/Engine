#include <iostream>
#include "UserInteraction.h"
#include "Engine.h"
#include "TestStand.h"

int main() {
	setlocale(LC_ALL, "Rus");
	double ambientTemperature = UserInteraction::GetTemperature();
	Engine engine;
	TestStand<Engine> testStand(engine, ambientTemperature);
	UserInteraction::OutputResult(testStand.Start());
}