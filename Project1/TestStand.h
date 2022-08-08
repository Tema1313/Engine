#define MAX_TIME 1000

template <typename T>
class TestStand
{
private:
	int numberV;//номер скорости
	double engineTemperature;//температура перегрева
	double ambientTemperature;//окружающая температура
	T* engine;
public:
	int Start();
	TestStand(T& engine, const double ambientTemperature);
};

template<typename T>
TestStand<T>::TestStand(T& engine, const double ambientTemperature) {
	numberV = 0;
	this->engine = &engine;
	this->engine->V = engine.startV[numberV];//скорость вращения коленвала(исходно =0)
	this->engine->M = engine.startM[numberV];//стартовый крутящий момент(исходно =20 )
	engineTemperature = ambientTemperature;//температура двигателя приравнивается к температуре окружающей среды
	this->ambientTemperature = ambientTemperature;//температура окружающей среды
}

template<typename T>
int TestStand<T>::Start() {
	double a = engine->M / engine->I;
	int time = 0;
	double eps = engine->overheatingTemperature - engineTemperature;
	while (eps >= 0 && time < MAX_TIME) {
		time += 1;
		engine->V += a;
		if (numberV < engine->startM.size() - 2) {
			if (engine->V < engine->startV[numberV + 1]) {
				numberV += 0;
			}
			else {
				numberV += 1;
			}
		}
		double up = engine->V - engine->startV[numberV];
		double down = engine->startV[numberV + 1] - engine->startV[numberV];
		double factor = engine->startM[numberV + 1] - engine->startM[numberV];
		engine->M = up / down * factor + engine->startM[numberV];

		engineTemperature += engine->Vh() + engine->Vc(ambientTemperature, engineTemperature);

		a = engine->M / engine->I;
		eps = engine->overheatingTemperature - engineTemperature;
	}
	return time;

}