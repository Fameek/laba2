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
			cout << "ERROR:incorrect numbers" << endl;
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
			cout << "ERROR:incorrect numbers" << endl;
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
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {    // если одно из чисел с минусом
				
				if (nam_1.size() == nam_2.size()) {
					bool trriger = 0;
					int target;
					for (int i = nam_1.size() - 1; i >= 0; i--) {
						if (nam_1[i] == nam_2[i]) {
							if (i == 0) {
								trriger = 1;
								break;
							}
						}
						else if (nam_1[i] > nam_2[i]) {
							is_it_minus_end = 1;
							target = i + 1;
							break;
						}
						else if (nam_1[i] < nam_2[i]) {
							target = i + 1;
							break;
						}
					}
					if (trriger == 1) {
						nam_end.push_back(0);
					}

					else {
						for (int i = 0; i < target; i++) {
							nam_end.push_back(nam_2[i]);
						}
						for (int i = 0; i < target; i++) {
							int sum_1 = nam_end[i] - nam_1[i];
							if (sum_1 < 0) {
								
								nam_end[i] = sum_1 + 10;
								int ii = i + 1;
								while (true) {
									if (ii == target) {
										break;
									}
									else {
										int sum_2 = nam_end[ii] - 1;
										if (sum_2 < 0) {
											
											nam_end[ii] = sum_2 + 10;

										}
										else {
											nam_end[ii] = sum_2;
											break;
										}

									}
									ii++;
								}

							}
							else {
								nam_end[i] = sum_1;
							}









						}












					}
				}

				if (nam_1.size() > nam_2.size()) {



				}

				if (nam_1.size() < nam_2.size()) {



				}




			}
			else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) { // если одно из чисел с минусом






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





};









int main() {

	while (true)
	{
		
		string snam_1;
		string snam_2;
		cout << "enter nam 1 : "; cin >> snam_1; cout << endl;
		cout << "enter nam 2 : "; cin >> snam_2; cout << endl;


		if (cin.fail()) {
			cin.clear();
			

		}



		 
		Big_numbers Win;
		bool correct = Win.creator(snam_1, snam_2);
		Win.sum();
		if (correct == 1) {
			Win.test_vivod();
			cout << endl;
			


		}
	







	

	}
	return 0;
}
