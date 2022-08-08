#define MAX_TIME 1000

template <typename T>
class TestStand
{
private:
	int numberV;//����� ��������
	double engineTemperature;//����������� ���������
	double ambientTemperature;//���������� �����������
	T* engine;
public:
	int Start();
	TestStand(T& engine, const double ambientTemperature);
};

template<typename T>
TestStand<T>::TestStand(T& engine, const double ambientTemperature) {
	numberV = 0;
	this->engine = &engine;
	this->engine->V = engine.startV[numberV];//�������� �������� ���������(������� =0)
	this->engine->M = engine.startM[numberV];//��������� �������� ������(������� =20 )
	engineTemperature = ambientTemperature;//����������� ��������� �������������� � ����������� ���������� �����
	this->ambientTemperature = ambientTemperature;//����������� ���������� �����
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