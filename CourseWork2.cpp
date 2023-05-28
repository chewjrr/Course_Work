#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>

class UI{
private:
	bool i4 = 0;
	bool i5 = 0;
	bool q6 = 0;
	bool q7 = 0;
	bool q8 = 0;
public:
	void SetI4(bool value) {
		i4 = value;
	}
	void SetI5(bool value) {
		i5 = value;
	}
	bool GetI4() {
		return i4;
	}
	bool GetI5() {
		return i5;
	}
	void SetQ6(bool value) {
		q6 = value;
	}
	void SetQ7(bool value) {
		q7 = value;
	}
	void SetQ8(bool value) {
		q8 = value;
	}
	bool GetQ6() {
		return q6;
	}
	bool GetQ7() {
		return q7;
	}
	bool GetQ8() {
		return q8;
	}
};
class Sensor{
private:
	bool i0 = 0;
	bool i1 = 0;
	bool i2 = 0;
	bool i3 = 0;
public:
	void Set_I0(bool value) {
		i0 = value;
	}
	void Set_I1(bool value) {
		i1 = value;
	}
	void Set_I2(bool value) {
		i2 = value;
	}
	void Set_I3(bool value) {
		i3 = value;
	}
	bool Get_I0() {
		return i0;
	}
	bool Get_I1() {
		return i1;
	}
	bool Get_I2() {
		return i2;
	}
	bool Get_I3() {
		return i3;
	}
};
class Drive{
private:
	char q0 = 0;
	char q1 = 0;
	char q2 = 0;
	char q3 = 0;
public:
	void SetQ0(char value) {
		q0 = value;
	}
	void SetQ1(char value) {
		q1 = value;
	}
	void SetQ2(char value) {
		q2 = value;
	}
	void SetQ3(char value) {
		q3 = value;
	}
	char GetQ0() {
		return q0;
	}
	char GetQ1() {
		return q1;
	}
	char GetQ2() {
		return q2;
	}
	char GetQ3() {
		return q3;
	}
};
class Container {
private:
	int n1;
	int n2;
	int n3;
	int n4;
	char num;
	int n3res;
public:
	void Set_N() {
		int v1;
		int v2;
		int v3;
		int v4;
		std::cout << "Введите количество компонентов в первом контейнере: ";
		std::cin >> v1;
		std::cout << std::endl;
		Set_N1(v1);

		std::cout << "Введите количество компонентов во втором контейнере: ";
		std::cin >> v2;
		std::cout << std::endl;
		Set_N2(v2);

		std::cout << "Введите вместимость в контейнере для брака: ";
		std::cin >> v3;
		std::cout << std::endl;
		Set_N3(v3);
		Set_N3Res();

		std::cout << "Введите вместимость в контейнере для компонентов с печать: ";
		std::cin >> v4;
		std::cout << std::endl;
		Set_N4(v4);
	}
	void Set_Num(char v) {
		num = v;
	}
	char Get_Num() {
		return num;
	}
	void Set_N1(int value) {
		n1 = value;
	}
	void Set_N2(int value) {
		n2 = value;
	}
	void Set_N3(int value) {
		n3 = value;
	}
	void Set_N4(int value) {
		n4 = value;
	}
	int Get_N1() {
		return n1;
	}
	int Get_N2() {
		return n2;
	}
	int Get_N3() {
		return n3;
	}
	void Set_N3Res() {
		n3res = n3;
	}
	int Get_N3Res() {
		return n3res;
	}
	int Get_N4() {
		return n4;
	}
};
class Controller {
public:
	UI ui{};
	Drive drive{};
	Container container{};
	Sensor sensor{};
	void Step_1() {
		int a;
		container.Set_N();
		std::cout << "1) Для старта нажмите 1: ";
		std::cin >> a;
		if (a == 1) {
			ui.SetI4(1);
			drive.SetQ0(1);
			Rec("1)");
			Step_2();
		}
	}
	void Step_2() {
		ui.SetI4(0);
		if (container.Get_N1() != 0) {
			container.Set_N1(container.Get_N1() - 1);
			container.Set_Num(1);
			Step_2b();
		}
		else if (container.Get_N2() != 0) {
			container.Set_N2(container.Get_N2() - 1);
			container.Set_Num(2);
			Step_2b();
		}
		else Step_2a();
	}
	void Step_2a() {
		drive.SetQ0(0);
		sensor.Set_I1(0);
		ui.SetQ6(1);
		ui.SetQ7(0);
		ui.SetQ8(1);
		std::cout << "2а) Контейнер с заготовками пустой. Вызов сигнала и остановка ленты." << std::endl;
		std::cout << "Выполнение работы технологического процесса завершено." << std::endl;
		std::cout << "Бракованых деталей: " << container.Get_N3Res() - container.Get_N3() << std::endl << std::endl;
		Rec("2a)");

	}
	void Step_2b() {
		sensor.Set_I1(1);
		drive.SetQ1(1);
		Rec("2b)");
		if (container.Get_Num() == 1) {
			std::cout << "2б) Контейнер с заготовками не пустой. Открывается контейнер номер один в котором " << container.Get_N1() << " деталей." << std::endl;
		}
		else if (container.Get_Num() == 2) {
			std::cout << "2б) Контейнер с заготовками не пустой. Открывается контейнер номер два в котором " << container.Get_N2() << " деталей." << std::endl;
		}
		Step_3();
	}
	void Step_3() {
		sensor.Set_I0(0);
		sensor.Set_I1(0);
		drive.SetQ1(0);
		std::cout << "3) Заготовка едет по ленте, но ещё не достигла датчика печати." << std::endl;
		int rand_num = rand() % 100 + 1;//создаем "шанс" брака детали
		if (rand_num >= 1 && rand_num <= 99) { //деталь не бракована 
			Rec("3)");
			Step_4();
		}
		else {
			if (container.Get_N3() != 0) {
				container.Set_N3(container.Get_N3() - 1);
				container.Set_Num(3);
				Rec("3)");
				Step_6();
			}
			else Step_7a();
		}
	}
	void Step_4() {
		sensor.Set_I3(1);
		drive.SetQ3(1);
		std::cout << "4) Заготовка достигла датчика печати. Печать опускается." << std::endl;
		Rec("4)");
		Step_5();
	}
	void Step_5() {
		sensor.Set_I3(0);
		drive.SetQ3(0);
		std::cout << "5) Деталь продолжает движение по ленте." << std::endl;
		Rec("5)");
		Step_6();
	}
	void Step_6() {

		sensor.Set_I0(1);
		drive.SetQ2(1);
		std::cout << "6) Деталь достигла конца ленты. Открывается крышка контейнера для готовых заготовок." << std::endl;
		Rec("6)");
		Step_7();
	}
	void Step_7() {
		sensor.Set_I0(0);
		drive.SetQ2(0);
		if (container.Get_N4() != 0 && container.Get_Num() != 3) {
			Step_7b();
		}
		else if (container.Get_N4() != 0 && container.Get_Num() == 3) {
			if (container.Get_N3() != 0) {
				std::cout << "Деталь бракована, и попадает в контейнер под номером 3, в котором осталсоть места еще для " << container.Get_N3() << " деталей." << std::endl;
				Step_2();
			}
			else Step_7a();
		}
		else if (container.Get_N4() == 0) {
			Step_7a();
		}
	}
	void Step_7a() {
		std::cout << "7а) Контейнер стал заполнен.Останавливаем процесс." << std::endl;
		std::cout << "Выполнение работы технологического процесса завершено." << std::endl;
		std::cout << "Бракованых деталей: " << container.Get_N3Res() - container.Get_N3() << std::endl << std::endl;
		drive.SetQ0(0);
		sensor.Set_I2(2);
		ui.SetQ6(0);
		ui.SetQ7(1);
		ui.SetQ8(1);
		Rec("7a)");
	}
	void Step_7b() {
		sensor.Set_I0(0);
		container.Set_N4(container.Get_N4() - 1);
		if (container.Get_N4() == 0) {
			Step_7a();
		}
		else {
			std::cout << "7б) Контейнер не заполнен. Продолжаем процесс в шаг 2. В контейнере номер 4 осталось еще " << container.Get_N4() << " мест для заготовок" << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
			Rec("7b)");
			Rec("_________________New Detail______________________");
			Step_2();
		}
	}
	void Step_8() {

	}
	void Step_9() {

	}
	void appendToFile(const std::string& filename, const std::vector<std::string>& values) {
		std::ofstream output(filename, std::ios::app);
		if (output.is_open()) {
			for (const std::string& value : values) {
				output << value << ' ';
			}
			output << std::endl;
			output.close();
		}
	}
	void Rec(const std::string& s) {
		std::string step = s;
		std::string filename = "data.txt";
		bool v1 = sensor.Get_I0();
		bool v2 = sensor.Get_I1();
		bool v3 = sensor.Get_I2();
		bool v4 = sensor.Get_I3();
		bool v5 = ui.GetI4();
		bool v6 = ui.GetI5();
		bool v7 = drive.GetQ0();
		bool v8 = drive.GetQ1();
		bool v9 = drive.GetQ2();
		bool v10 = drive.GetQ3();
		bool v11 = ui.GetQ6();
		bool v12 = ui.GetQ7();
		bool v13 = ui.GetQ8();
		std::vector<std::string> values = { step, std::to_string(v1), std::to_string(v2), std::to_string(v3), std::to_string(v4), std::to_string(v5), std::to_string(v6), std::to_string(v7), std::to_string(v8), std::to_string(v9), std::to_string(v10), std::to_string(v11), std::to_string(v12), std::to_string(v13) };
		appendToFile(filename, values);
	}
};
int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Controller controller;
	int choice; // переменная для выбора пункта меню

	do {
		// выводим меню на экран
		std::cout << "Меню:" << std::endl;
		std::cout << "1. Начало моделирования технологического процесса." << std::endl;
		std::cout << "2. Описание программы." << std::endl;
		std::cout << "3. Выход" << std::endl;
		std::cout << "Выберите пункт меню (1-3): ";

		// считываем выбор пользователя
		std::cin >> choice;

		// обрабатываем выбор пользователя
		switch (choice) {
		case 1:
			std::cout << "Вы выбрали пункт 1." << std::endl;
			controller.Step_1();
			break;
		case 2:
			std::cout << "Вы выбрали пункт 2." << std::endl;
			std::cout << "букавы" << std::endl;
			break;
		case 3:
			std::cout << "Выход из программы." << std::endl;
			break;
		default:
			std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
		}
	} while (choice != 3); // продолжаем показывать меню, пока пользователь не выберет "Выход"

	
	return 0;
}