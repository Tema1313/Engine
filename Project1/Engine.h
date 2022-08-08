#pragma once
#include <vector>

class Engine {
public:
	int I = 10;//момент инерции
	std::vector<int> startM = { 20,75,100,105,75,0 };//крутящий момент
	std::vector<int> startV = { 0,75,150,200,250,300 };//скорость вращения коленвала
	int overheatingTemperature = 110;//температура перегрева
	double M;
	double V;
	double Vh();//скорость нагрева двигателя
	double Vc(double ambientTemperature, double engineTemperature);//скорость охлаждения двигателя
};
