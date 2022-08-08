#pragma once
#include "UserInteraction.cpp"
#include <iostream>

#define MAX_TIME 1000

int UserInteraction::GetTemperature() {
	double userTemperature;
	std::cout << "������� ����������� ���������� �����:";
	std::cin >> userTemperature;
	return userTemperature;
}

void UserInteraction::OutputResult(const int time) {
	if (time == MAX_TIME) {
		std::cout << "����������� ���������� ����� ������� ����" << std::endl;
	}
	else {
		std::cout << "����� �� ���������:" << time << std::endl;
	}
}