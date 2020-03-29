#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Big_numbers {
private:
	vector<int> nam_1;                       //число 1
	bool is_it_minus_1 = 0;                 // имеет ли число 1 "-"
	vector<int> nam_2;                      //число 2 
	bool is_it_minus_2 = 0;                // имеет ли число 2 "-"
	vector<int> nam_end;                   //число после арм. действий
	bool is_it_minus_end = 0;             // имеет ли конечное число "-"

	void SumWithMinus_1() {

		for (int i = 0; i < nam_1.size(); i++) {
			nam_end.push_back(nam_1[i]);
		}
		for (int i = 0; i < nam_2.size(); i++) {

			int sum_1 = nam_end[i] - nam_2[i];

			if (sum_1 < 0) { // если сумма заставляет от след числа отнимать 1

				nam_end[i] = sum_1 + 10; // из отриц в полож
				int ii = i + 1; // это будет след числом
				while (true) {
					if (ii == nam_end.size()) { // если выходит за пределы вектора
						break;
					}
					else { // если вектор еще есть
						int sum_2 = nam_end[ii] - 1; // будущее след число
						if (sum_2 < 0) { // не порядочная

							nam_end[ii] = sum_2 + 10;

						}
						else { // порядочная
							nam_end[ii] = sum_2;
							break;
						}

					}
					ii++;
				}

			}
			else { //если ссумма порядочая и можно просто прировнять
				nam_end[i] = sum_1;
			}
			for (int i = nam_end.size() - 1; i >= 0; i--) { // удаление нулей в начале числа
				if (nam_end[i] == 0) {
					nam_end.pop_back();
				}
				else {
					break;
				}
			}
		}

	}
	void SumWithMinus_2() {

		for (int i = 0; i < nam_2.size(); i++) {
			nam_end.push_back(nam_2[i]);
		}
		for (int i = 0; i < nam_1.size(); i++) {

			int sum_1 = nam_end[i] - nam_1[i];

			if (sum_1 < 0) { // если сумма заставляет от след числа отнимать 1

				nam_end[i] = sum_1 + 10; // из отриц в полож
				int ii = i + 1; // это будет след числом
				while (true) {
					if (ii == nam_end.size()) { // если выходит за пределы вектора
						break;
					}
					else { // если вектор еще есть
						int sum_2 = nam_end[ii] - 1; // будущее след число
						if (sum_2 < 0) { // не порядочная

							nam_end[ii] = sum_2 + 10;

						}
						else { // порядочная
							nam_end[ii] = sum_2;
							break;
						}

					}
					ii++;
				}

			}
			else { //если ссумма порядочая и можно просто прировнять
				nam_end[i] = sum_1;
			}
			for (int i = nam_end.size() - 1; i >= 0; i--) { // удаление нулей в начале числа
				if (nam_end[i] == 0) {
					nam_end.pop_back();
				}
				else {
					break;
				}
			}
		}

	}
	void SumWithMinusOrPlus(int i) {
		int val = 1; // на сколько элем нужно уйти чтоб проверить згачение на галичие значений выше чем 9
		while (true) // пока не поймет что след символы не равны 10 или больше
		{
			int rr = i + val; // идет проверка этого элемента в векторе
			if (rr < nam_end.size()) { // если элемент существует
				if (nam_end[rr] > 9) { // если его нужно изменять
					nam_end[rr] = nam_end[rr] % 10;
					if (rr + 1 < nam_end.size()) {// если след символ существует 
						nam_end[rr + 1] = nam_end[rr + 1] + 1; // увелечение след символа на 1
					}
					else { // если след символа в векторе не существует
						nam_end.push_back(1); // добавление 1 в конец вектора
						break;
					}
				}
				else {
					break;
				}
			}
			else { // если элемента не существует
				
				nam_end.push_back(1); // добавляем на послед элем 1
				
				break;
			}
			val++;

		}
	}

public:
	bool creator(string snam_1, string snam_2) {      
		vector<int> nam_1f;                          // временный вектор для записи 1 числа
		vector<int> nam_2f;                          // временный вектор для записи 2 числа
		bool trriger = 0;                            // тригер, если он равен 1

		if (snam_1[0] == '0' || snam_2[0] == '0') {  //######## все эти ифы это проверка на коректность начала большого числа 
			trriger = 1;                             // есть ли там некоректные нули (после минуса) или если цыфра начинается с нуля то она вызывает тригер
		}                                            //
		if (snam_1[0] == '-' && snam_1[1] == '0') {   // 
			trriger = 1;                              //
		}                                             //
		if (snam_2[0] == '-' && snam_2[1] == '0') {  //
			trriger = 1;                             // 
		}                                            //########



		for (int i = 0; i < snam_1.size(); i++) {         // начало оброботки 1 строки
			if (snam_1[i] == 45 && snam_1[0] == 45 ) {    // проверка на наличие минуса на первом символе
				if (i == 0) {                             // если обрабатывается 1 символ
					is_it_minus_1 = 1;                    // певое число имеет минус
				}
				else {                                    // иначе
					trriger = 1;                          // некоректно введено число 
				}
			}
			else if (snam_1[i] == 48 || snam_1[i] == 49 || snam_1[i] == 50 || snam_1[i] == 51 || snam_1[i] == 52 || snam_1[i] == 53 || snam_1[i] == 54 || snam_1[i] == 55 || snam_1[i] == 56 || snam_1[i] == 57) {   // если символ равен любому числу от 0 до 9
				string cha ;     
				cha = snam_1[i];    // в новый стринг записываем 1 число
				nam_1f.push_back(stoi(cha.c_str()));   // добовляем число в конец вектора
			}
			else {         // иначе некоректное число
				trriger = 1;
			}


			if (trriger == 1) {  // если число уже не коректное то выход из цыкла 
				break;
			}
		}
		if (trriger == 1) {        // если число не корректное то сообщаем об ошибке и возвращаем значение неудачи 
			cout << "ERROR:incorrect numbers or the first character is 0" << endl;
			return false;
		}
		for (int i = 0; i < snam_2.size(); i++) {             // начало оброботки 2 строки
			if (snam_2[i] == 45 && snam_2[0] == 45) { // проверка на наличие минуса на первом символе
				if (i == 0) {
					is_it_minus_2 = 1;
				}
				else {
					trriger = 1;
				}
			}
			else if (snam_2[i] == 48 || snam_2[i] == 49 || snam_2[i] == 50 || snam_2[i] == 51 || snam_2[i] == 52 || snam_2[i] == 53 || snam_2[i] == 54 || snam_2[i] == 55 || snam_2[i] == 56 || snam_2[i] == 57) {   // если символ равен любому числу от 0 до 9
				string cha;
				cha = snam_2[i];
				nam_2f.push_back(stoi(cha.c_str())); // записываем
			}
			else {
				trriger = 1;
			}


			if (trriger == 1) {
				break;
			}
		}
		if (trriger == 1) { // если некоректное число то выходим с ошибкой
			cout << "ERROR:incorrect numbers or the first character is 0" << endl;
			return false;
		}
		else if (trriger == 0) { // если все прошло хорошо то записываем эти вектора в главные вектора задом на перед
			for (int i = 0; i < nam_1f.size(); i++) {
				int ii = nam_1f.size() - i - 1;
				int iii = nam_1f[ii];
				nam_1.push_back(iii);
			}
			for (int i = 0; i < nam_2f.size(); i++) {
				int ii = nam_2f.size() - i - 1;
				int iii = nam_2f[ii];
				nam_2.push_back(iii);
			}
			return 1;
		}
		return false;
	}
	void test_vivod() { // тестовый вывод 3 векторов из привата
		if (is_it_minus_1 == 1) {
			cout << "-";
		}
		for (int i = nam_1.size() - 1; i >= 0; i--) {
			cout << nam_1[i];
		}
		cout << endl;
		if (is_it_minus_2 == 1) {
			cout << "-";

		}
		for (int i = nam_2.size() - 1; i >= 0; i--) {
			cout << nam_2[i];
		}
		cout << endl;
		if (is_it_minus_end == 1) {
			cout << "-";

		}
		for (int i = nam_end.size() - 1; i >= 0; i--) {
			cout << nam_end[i];
		}
		cout << endl;
	}
	void sum() {
		if (nam_1.size() != 0 || nam_2.size() != 0) {          //если вектора существуют
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {    // если одно из чисел с минусом
				
				if (nam_1.size() == nam_2.size()) { // если размеры вектора равны
					bool trriger = 0;     // Он будет равен 1 если 2 числа одинаковы
					int target;         // показывает с какого числа в сайзе начинаются одинаковые символы(до конца)
					for (int i = nam_1.size() - 1; i >= 0; i--) { // пробег по числу от большего к меньшему
						
						if (nam_1[i] == nam_2[i]) { // если число равно 
							if (i == 0) { // если чисто уже последнее 
								trriger = 1; // ответ равен 0
								break;
							}
						}
						else if (nam_1[i] > nam_2[i]) { // если числа не равны
							if (is_it_minus_1 == 1 && is_it_minus_2 == 0) { // если минус еть у 1ого числа
								is_it_minus_end = 1;
								
							}
							target = i + 1;
							break;
						}
						else if (nam_1[i] < nam_2[i]) {  // если числа не равны
							if (is_it_minus_1 == 0 && is_it_minus_2 == 1) { // если минус еть у 2ого числа
								is_it_minus_end = 1;
								
							}
							
							target = i + 1;
							break;
						}
					}
					if (trriger == 1) {
						nam_end.push_back(0); // условия при котором ответ = 0 выполнено
					}
					else {  // если число не равно 0
						if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {  // если число 1 с минусом
							if (is_it_minus_end == 0) { // ели ответ с плюсом
								for (int i = 0; i < target; i++) { //  приравневаем (на время) ответ к 2 числу до таргета
									nam_end.push_back(nam_2[i]);
								}
							}
							else { // если оивет с минусом
								for (int i = 0; i < target; i++) {
									nam_end.push_back(nam_1[i]); //   приравневаем (на время) ответ к 1 числу до таргета
								}
							}
						}
						else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {// если число 2 с минусом
							if (is_it_minus_end == 0) {    // ели ответ с плюсом
								for (int i = 0; i < target; i++) {
									nam_end.push_back(nam_1[i]); // приравневаем(на время) ответ к 1 числу до таргета
								}
							}
							else {  // если оивет с минусом
								for (int i = 0; i < target; i++) { 
									nam_end.push_back(nam_2[i]);   //  приравневаем (на время) ответ к 2 числу до таргета
								}
							}
						}

						for (int i = 0; i < target; i++) { //прогоняемся по таргету 
							int sum_1; // сумма 
							if (is_it_minus_1 == 1 && is_it_minus_2 == 0) { // если число 1 с минусом     #по факту тут мы реаем от чего будем отнимать при идее отнимать от большего меньшее(обьясню на сдаче)
								if (is_it_minus_end == 0) {                 // если ответ без минуса
									sum_1 = nam_end[i] - nam_1[i];    
								}
								else if (is_it_minus_end == 1) {   // если ответ с минуса
									sum_1 = nam_end[i] - nam_2[i];
								}
							}
							else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {// если число 2 с минусом
								if (is_it_minus_end == 0) {  // если ответ без минуса
									sum_1 = nam_end[i] - nam_2[i];
								}
								else if (is_it_minus_end == 1) {  // если ответ с минуса
									sum_1 = nam_end[i] - nam_1[i];
								}
							}

							if (sum_1 < 0) { // если сумма заставляет от след числа отнимать 1
								
								nam_end[i] = sum_1 + 10; // из отриц в полож
								int ii = i + 1; // это будет след числом
								while (true) {
									if (ii == target) { // если выходит за пределы вектора
										break;
									}
									else { // если вектор еще есть
										int sum_2 = nam_end[ii] - 1; // будущее след число
										if (sum_2 < 0) { // не порядочная
											
											nam_end[ii] = sum_2 + 10; 

										}
										else { // порядочная
											nam_end[ii] = sum_2;
											break;
										}

									}
									ii++;
								}

							}
							else { //если ссумма порядочая и можно просто прировнять
								nam_end[i] = sum_1;
							}
						}
						for (int i = target - 1; i >= 0; i--) { // удаление нулей в начале числа
							if (nam_end[i] == 0) {
								nam_end.pop_back();
							}
							else {
								break;
							}
						}
					}
				}

				if (nam_1.size() > nam_2.size()) {
					if (is_it_minus_1 == 1) { // если большее число с -
						is_it_minus_end = 1;
						SumWithMinus_1();
					}
					else if (is_it_minus_2 == 1) { //если меньшее число с -
						is_it_minus_end = 0;
						SumWithMinus_1();
					}
				}

				if (nam_1.size() < nam_2.size()) {
					if (is_it_minus_1 == 1) { // если большее число с -
						is_it_minus_end = 0;
						SumWithMinus_2();
					}
					else if (is_it_minus_2 == 1) { //если меньшее число с -
						is_it_minus_end = 1;
						SumWithMinus_2();
					}
				}
			}
			else  { // если 2 числа без минуса или 2 с минусом
				if (is_it_minus_1 == 0 && is_it_minus_2 == 0) { // присвоение плюса
				}
				else if (is_it_minus_1 == 1 && is_it_minus_2 == 1) { // присвоение минуса

					is_it_minus_end = 1;
				}
				if (nam_1.size() < nam_2.size()) {  // если 1 число больше 2

					for (int i = 0; i < nam_2.size(); i++) { // запись на месло конечного числа 2 число так как оно больше 
						nam_end.push_back(nam_2[i]);
					}
					
					for (int i = 0; i < nam_1.size(); i++) {
						int sum_2_elem = nam_end[i] + nam_1[i];  // сложение 2х чисел (элементов вектора) #nam_end используется так как элемент может быть на 1 больше чем nam_1
						
						if (sum_2_elem > 9) {              // если нужно прибовлять 1 к след числу
							int iii = sum_2_elem % 10;  // присваем значения остатка от 10 от числа суммы 
							nam_end[i] = iii;
						
							nam_end[i + 1] = nam_end[i + 1] + 1; // след элем повысился на 1
							SumWithMinusOrPlus(i);
						}
						else if (sum_2_elem < 10) {   // если нужно прибовлять 1 к след числу
							nam_end[i] = sum_2_elem;  // присвоение суммы к элементу
						}
						
					}

				}
				else if (nam_2.size() < nam_1.size()) {  // если 2 число больше 1

					for (int i = 0; i < nam_1.size(); i++) { // запись на месло конечного числа 2 число так как оно больше 
						nam_end.push_back(nam_1[i]);
					}

					for (int i = 0; i < nam_2.size(); i++) {
						int sum_2_elem = nam_end[i] + nam_2[i];  // сложение 2х чисел (элементов вектора) #nam_end используется так как элемент может быть на 1 больше чем nam_1

						if (sum_2_elem > 9) {              // если нужно прибовлять 1 к след числу
							int iii = sum_2_elem % 10;  // присваем значения остатка от 10 от числа суммы 
							nam_end[i] = iii;

							nam_end[i + 1] = nam_end[i + 1] + 1; // след элем повысился на 1
							SumWithMinusOrPlus(i);
						}
						else if (sum_2_elem < 10) {   // если нужно прибовлять 1 к след числу
							nam_end[i] = sum_2_elem;  // присвоение суммы к элементу
						}

					}


				}
				else if (nam_1.size() == nam_2.size()) {  // если 1 и 2 числа равны				
						for (int i = 0; i < nam_1.size(); i++) { // запись на месло конечного числа первое число 
							nam_end.push_back(nam_1[i]);
						}

						for (int i = 0; i < nam_1.size(); i++) { // приступаем к работе со всеми элементами векторов

							int sum_2_elem = nam_end[i] + nam_2[i];  // сложение 2х чисел (элементов вектора) #nam_end используется так как элемент может быть на 1 больше чем nam_1
							if (sum_2_elem > 9) {              // если нужно прибовлять 1 к след числу
								int iii = sum_2_elem % 10;  // присваем значения остатка от 10 от числа суммы 
								nam_end[i] = iii;
								int ooo = i + 1;              // значение след элемента
								if (ooo < nam_end.size()) {   // если ооо не выходит за пределы вектора

									nam_end[i + 1] = nam_end[i + 1] + 1; // след элем повысился на 1
									int val = 1; // на сколько элем нужно уйти чтоб проверить згачение на галичие значений выше чем 9
									while (true) // пока не поймет что след символы не равны 10 или больше
									{
										int rr = i + val; // идет проверка этого элемента в векторе
										if (rr < nam_end.size()) { // если элемент существует
											if (nam_end[rr] > 9) { // если его нужно изменять
												nam_end[rr] = nam_end[rr] % 10;
												if (rr + 1 < nam_end.size()) {// если след символ существует 
													nam_end[rr + 1] = nam_end[rr + 1] + 1; // увелечение след символа на 1
												}
												else { // если след символа в векторе не существует
													nam_end.push_back(1); // добавление 1 в конец вектора
													break;
												}
											}
											else {
												break;
											}
										}
										else { // если элемента не существует
											if (nam_end[rr] > 9) { // если его нужно изменять
												nam_end[rr] = nam_end[rr] % 10;
												nam_end.push_back(1); // добавляем на послед элем 1
											}
											break;
										}
										val++;

									}
								}
								else {
									nam_end.push_back(1);
								}

							}
							else if (sum_2_elem < 10) {   // если нужно прибовлять 1 к след числу
								nam_end[i] = sum_2_elem;  // присвоение суммы к элементу
							}




						}
					


				}

			}
		}
	}
	void razn() {
		if (nam_1.size() != 0 || nam_2.size() != 0) {          //если вектора существуют
			
			if (is_it_minus_1 == 0 && is_it_minus_2 == 0) {
				is_it_minus_2 = 1;
				sum();
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 1) {
				is_it_minus_2 = 0;
				sum();
			}
			else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {
				is_it_minus_2 = 0;
				sum();
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {
				is_it_minus_2 = 1;
				sum();
			}

		}
	}
	void ymn(){
		if (nam_1.size() != 0 || nam_2.size() != 0) {
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {//решение вопроса с минусом
				is_it_minus_end = 1;
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 1 || is_it_minus_1 == 0 && is_it_minus_2 == 0) { // решение вопроса с минусом или плюсом
				is_it_minus_end = 0;
			}



			if (nam_1.size() == 1 || nam_2.size() == 1) { // на ноль умножать = 0
				if (nam_1[0] == 0 || nam_2[0] == 0) {
					nam_end.push_back(0);
				
				}
			}

			if (nam_end.size() != 1) {
				for (int i = 0; i < nam_1.size(); i++) {     // умножние 1 числа
					for (int ii = 0; ii < nam_2.size(); ii++) { // на второе
						if (nam_end.size() == ii + i) {    // если выходим за пределы вектора ответа
							int ymn_1 = nam_1[i] * nam_2[ii];
							if (ymn_1 > 9) {
								nam_end.push_back(ymn_1 % 10);
								string str = to_string(ymn_1);
								string str_1;
								str_1 = str[0];
								nam_end.push_back(stoi(str_1.c_str()));
							}
							else if (ymn_1 < 10) {
								nam_end.push_back(ymn_1);
							}

						}
						else {   // если работаем уже с данными вектора
							int ymn_1 = nam_1[i] * nam_2[ii];
							if (ymn_1 > 9) { // не порядочная
								int rr = ymn_1 % 10;
								int sum_1 = nam_end[i + ii] + rr;
								if (sum_1 > 9) {
									nam_end[i + ii] = sum_1 - 10;
									if (i + ii + 1 < nam_end.size()) {
										nam_end[i + ii + 1] = nam_end[i + ii + 1] + 1;
										SumWithMinusOrPlus(i + ii);
									}
									else {
										nam_end.push_back(1);
									}
								}
								else if (sum_1 < 10) {
									nam_end[i + ii] = sum_1;
								}
								string str = to_string(ymn_1);
								string str_1;
								str_1 = str[0];
								int ymn_2 = stoi(str_1.c_str());
								if (nam_end.size() != i + ii + 1) {
									int sum_2 = nam_end[i + ii + 1] + ymn_2;
									if (sum_2 > 9) {
										nam_end[i + ii + 1] = sum_2 - 10;

										if (i + ii + 2 < nam_end.size()) {
											nam_end[i + ii + 2] = nam_end[i + ii + 2] + 1;
											SumWithMinusOrPlus(i + ii + 1);
										}
										else {
											nam_end.push_back(1);
										}
									}
									else if (sum_2 < 10) {
										nam_end[i + ii + 1] = sum_2;
									}
								}
								else {
									nam_end.push_back(ymn_2);
								}

							}
							else if (ymn_1 < 10) { // класная с (возможно) плохими детьми
								int sum_1 = nam_end[i + ii] + ymn_1; 
								if (sum_1 > 9) { // плохой
									nam_end[i + ii] = sum_1 - 10;
									if (i + ii + 1 < nam_end.size()) {
										nam_end[i + ii + 1] = nam_end[i + ii + 1] + 1;
										SumWithMinusOrPlus(i + ii);
									}
									else {
										nam_end.push_back(1);
									}
								}
								else if (sum_1 < 10) { // хороший
									nam_end[i + ii] = sum_1;
								}

							}

						}





					}




					
				}



			}
			






		}
	}
	void del(){      
		if (nam_1.size() != 0 || nam_2.size() != 0) {
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {//решение вопроса с минусом
				is_it_minus_end = 1;
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 1 || is_it_minus_1 == 0 && is_it_minus_2 == 0) { // решение вопроса с минусом или плюсом
				is_it_minus_end = 0;
			}

			if (nam_1.size() == nam_2.size()) {
				string nam_1_str = "000000000"; // заполнил 9 элементов(0 всеравно сократятся) 
				string nam_2_str = "000000000";
				int i = 0;
				while (true)
				{
					if (nam_1.size() - i != 0) {
						
						string nam_1_str_1 = to_string(nam_1[nam_1.size() - i - 1]);
						nam_1_str[i] = nam_1_str_1[0];
						string nam_2_str_1 = to_string(nam_2[nam_2.size() - i - 1]);
						nam_2_str[i] = nam_2_str_1[0];

						if (i == 8) {
							break;
						}
						i++;
					}
					else {
						break;
					}
				}

				int nam_1_int = stoi(nam_1_str.c_str());
				int nam_2_int = stoi(nam_2_str.c_str());
				nam_end.push_back(nam_1_int / nam_2_int);
			}
			else if (nam_1.size() < nam_2.size()) {
				is_it_minus_end = 0;
				nam_end.push_back(0);
			}
			else if (nam_1.size() > nam_2.size()) {
















			}
		}	
	}
	void print() {
		
		
		if (nam_end.size() != 0) {
			cout << "Answer : ";
			if (is_it_minus_end == 1) {
				cout << "-";				
			}
			for (int i = nam_end.size() - 1; i >= 0; i--) {
				cout << nam_end[i];
			}
			cout << endl;

		}


	}






};









int main() {

	while (true)
	{
		
		cout << "\t \t \t \t MENU \t \t" << endl;
		cout << "Enter :  \t 1 - Sum(+) \t 2 - difference(-)\t 3 - multiplication(*) \t 4 - division(/)" << endl;
		string rr;
		cin >> rr;  cout << endl;
		if (rr.size() == 1) {
			if (rr[0] == '1' || rr[0] == '2' || rr[0] == '3' || rr[0] == '4') {
				int r = stoi(rr.c_str());
				string snam_1;
				string snam_2;
				Big_numbers win;
				
				if (r == 1) {
					cout << "First number : "; cin >> snam_1; cout << endl;
					cout << "Second number : "; cin >> snam_2; cout << endl;
					bool correct = win.creator(snam_1, snam_2);
					if (correct == 1) {
						win.sum();
						win.print();
					}
				}
				else if (r == 2) {
					cout << "First number : "; cin >> snam_1; cout << endl;
					cout << "Second number : "; cin >> snam_2; cout << endl;
					bool correct = win.creator(snam_1, snam_2);
					if (correct == 1) {
						win.razn();
						win.print();
					}
				}
				else if (r == 3) {
					cout << "First number : "; cin >> snam_1; cout << endl;
					cout << "Second number : "; cin >> snam_2; cout << endl;
					bool correct = win.creator(snam_1, snam_2);
					if (correct == 1) {
						win.ymn();
						win.print();
					}
				}
				else if (r == 4) {
					cout << "First number : "; cin >> snam_1; cout << endl;
					cout << "Second number : "; cin >> snam_2; cout << endl;
					bool correct = win.creator(snam_1, snam_2);
					if (correct == 1) {
						win.del();
						win.print();
					}
				}
			}
		}
		if (cin.fail()) {
			cin.clear();
		}
	}
	return 0;
}
