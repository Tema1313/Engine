#pragma once
#include "UserInteraction.cpp"
#include <iostream>

#define MAX_TIME 1000

int UserInteraction::GetTemperature() {
	double userTemperature;
	std::cout << "Введите температуру окружающей среды:";
	std::cin >> userTemperature;
	return userTemperature;
}

void UserInteraction::OutputResult(const int time) {
	if (time == MAX_TIME) {
		std::cout << "Температура окружающей среды слишком мала" << std::endl;
	}
	else {
		std::cout << "Время до перегрева:" << time << std::endl;
	}
}