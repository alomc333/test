#include <iostream>
#include <Windows.h>
using namespace std;

class Vehiele {
protected:
	int dist;
	int speed;
public:
	Vehiele(int dist, int speed) {
		this->dist = dist;
		this->speed = speed;
	}
	virtual double time() = 0;
	virtual double cost() = 0;
};


class Car :public Vehiele {
public:
	Car(int dist, int speed) :Vehiele (dist, speed) {}
	double time() override {
		return (this->dist / this->speed) + 10;
	}
	double cost() override {
		return this->dist * 3;
	}
};


class Bice :public Vehiele {
public:
	Bice(int dist, int speed) :Vehiele(dist, speed) {}
	double time() override {
		return (this->dist / this->speed) + 500;
	}
	double cost() override {
		return this->dist;
	}
};


class Plane :public Vehiele {
public:
	Plane(int dist, int speed) :Vehiele(dist, speed) {}
	double time() override {
		return (this->dist / this->speed) + 2;
	}
	double cost() override {
		return this->dist *10;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vehiele* h[3] = { new Car(1000, 120), new Bice(1000, 30), new Plane(1000, 500) };
	for (int i = 0; i < 3; i++) {
		cout << "Время: " << h[i]->time() << "Стоимость: " << h[i]->cost() << "\n";
	}
}
