#pragma once
#include <vector>

class Engine {
public:
	int I = 10;//������ �������
	std::vector<int> startM = { 20,75,100,105,75,0 };//�������� ������
	std::vector<int> startV = { 0,75,150,200,250,300 };//�������� �������� ���������
	int overheatingTemperature = 110;//����������� ���������
	double M;
	double V;
	double Vh();//�������� ������� ���������
	double Vc(double ambientTemperature, double engineTemperature);//�������� ���������� ���������
};
