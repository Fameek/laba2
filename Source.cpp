#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Big_numbers {
private:
	vector<int> nam_1;                       //����� 1
	bool is_it_minus_1 = 0;                 // ����� �� ����� 1 "-"
	vector<int> nam_2;                      //����� 2 
	bool is_it_minus_2 = 0;                // ����� �� ����� 2 "-"
	vector<int> nam_end;                   //����� ����� ���. ��������
	bool is_it_minus_end = 0;             // ����� �� �������� ����� "-"
	vector<int> answer;
	bool is_it_minus_ansver = 0;
	

	void SumWithMinus_1() {

		for (int i = 0; i < nam_1.size(); i++) {
			nam_end.push_back(nam_1[i]);
		}
		for (int i = 0; i < nam_2.size(); i++) {

			int sum_1 = nam_end[i] - nam_2[i];

			if (sum_1 < 0) { // ���� ����� ���������� �� ���� ����� �������� 1

				nam_end[i] = sum_1 + 10; // �� ����� � �����
				int ii = i + 1; // ��� ����� ���� ������
				while (true) {
					if (ii == nam_end.size()) { // ���� ������� �� ������� �������
						break;
					}
					else { // ���� ������ ��� ����
						int sum_2 = nam_end[ii] - 1; // ������� ���� �����
						if (sum_2 < 0) { // �� ����������

							nam_end[ii] = sum_2 + 10;

						}
						else { // ����������
							nam_end[ii] = sum_2;
							break;
						}

					}
					ii++;
				}

			}
			else { //���� ������ ��������� � ����� ������ ����������
				nam_end[i] = sum_1;
			}
			for (int i = nam_end.size() - 1; i >= 0; i--) { // �������� ����� � ������ �����
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

			if (sum_1 < 0) { // ���� ����� ���������� �� ���� ����� �������� 1

				nam_end[i] = sum_1 + 10; // �� ����� � �����
				int ii = i + 1; // ��� ����� ���� ������
				while (true) {
					if (ii == nam_end.size()) { // ���� ������� �� ������� �������
						break;
					}
					else { // ���� ������ ��� ����
						int sum_2 = nam_end[ii] - 1; // ������� ���� �����
						if (sum_2 < 0) { // �� ����������

							nam_end[ii] = sum_2 + 10;

						}
						else { // ����������
							nam_end[ii] = sum_2;
							break;
						}

					}
					ii++;
				}

			}
			else { //���� ������ ��������� � ����� ������ ����������
				nam_end[i] = sum_1;
			}
			for (int i = nam_end.size() - 1; i >= 0; i--) { // �������� ����� � ������ �����
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
		int val = 1; // �� ������� ���� ����� ���� ���� ��������� �������� �� ������� �������� ���� ��� 9
		while (true) // ���� �� ������ ��� ���� ������� �� ����� 10 ��� ������
		{
			int rr = i + val; // ���� �������� ����� �������� � �������
			if (rr < nam_end.size()) { // ���� ������� ����������
				if (nam_end[rr] > 9) { // ���� ��� ����� ��������
					nam_end[rr] = nam_end[rr] % 10;
					if (rr + 1 < nam_end.size()) {// ���� ���� ������ ���������� 
						nam_end[rr + 1] = nam_end[rr + 1] + 1; // ���������� ���� ������� �� 1
					}
					else { // ���� ���� ������� � ������� �� ����������
						nam_end.push_back(1); // ���������� 1 � ����� �������
						break;
					}
				}
				else {
					break;
				}
			}
			else { // ���� �������� �� ����������
				
				nam_end.push_back(1); // ��������� �� ������ ���� 1
				
				break;
			}
			val++;

		}
	}
	void dell_nam_1_2() {
		if (nam_1.size() != 0) {
			int ii = nam_1.size();
			for (int i = 0; i < ii; i++) {
				nam_1.pop_back();
			}
		}
		if (nam_2.size() != 0) {
			int ii = nam_2.size();
			for (int i = 0; i < ii; i++) {
				nam_2.pop_back();
			}
		}
		is_it_minus_1 = 0;
		is_it_minus_2 = 0;
	}
	void dell_end() {
		if (nam_end.size() != 0) {
			int ii = nam_end.size();
			for (int i = 0; i < ii; i++) {
				nam_end.pop_back();
			}
		}
		is_it_minus_end = 0;
	}
	void dell_answer() {
		if (answer.size() != 0) {
			int ii = answer.size();
			for (int i = 0; i < ii; i++) {
				answer.pop_back();
			}
		}
		is_it_minus_ansver = 0;
	}
	//void zerroes_nam_2() {
	//	int ii = nam_2.size();
	//	for (int i = ii - 1; i >= 0; i++) {
	//		if (nam_2[i] == 0) {
	//			nam_2.pop_back();
	//		}
	//		else
	//			break;
	//	}
	//}
public:
	
	bool creator(string snam_1, string snam_2) { 
	
		dell_data();

		vector<int> nam_1f;                          // ��������� ������ ��� ������ 1 �����
		vector<int> nam_2f;                          // ��������� ������ ��� ������ 2 �����
		bool trriger = 0;                            // ������, ���� �� ����� 1

		if (snam_1[0] == '0' || snam_2[0] == '0') {  //######## ��� ��� ��� ��� �������� �� ����������� ������ �������� ����� 
			trriger = 1;                             // ���� �� ��� ����������� ���� (����� ������) ��� ���� ����� ���������� � ���� �� ��� �������� ������
		}                                            //
		if (snam_1[0] == '-' && snam_1[1] == '0') {   // 
			trriger = 1;                              //
		}                                             //
		if (snam_2[0] == '-' && snam_2[1] == '0') {  //
			trriger = 1;                             // 
		}                                            //########



		for (int i = 0; i < snam_1.size(); i++) {         // ������ ��������� 1 ������
			if (snam_1[i] == 45 && snam_1[0] == 45 ) {    // �������� �� ������� ������ �� ������ �������
				if (i == 0) {                             // ���� �������������� 1 ������
					is_it_minus_1 = 1;                    // ����� ����� ����� �����
				}
				else {                                    // �����
					trriger = 1;                          // ���������� ������� ����� 
				}
			}
			else if (snam_1[i] == 48 || snam_1[i] == 49 || snam_1[i] == 50 || snam_1[i] == 51 || snam_1[i] == 52 || snam_1[i] == 53 || snam_1[i] == 54 || snam_1[i] == 55 || snam_1[i] == 56 || snam_1[i] == 57) {   // ���� ������ ����� ������ ����� �� 0 �� 9
				string cha ;     
				cha = snam_1[i];    // � ����� ������ ���������� 1 �����
				nam_1f.push_back(stoi(cha.c_str()));   // ��������� ����� � ����� �������
			}
			else {         // ����� ����������� �����
				trriger = 1;
			}


			if (trriger == 1) {  // ���� ����� ��� �� ��������� �� ����� �� ����� 
				break;
			}
		}
		if (trriger == 1) {        // ���� ����� �� ���������� �� �������� �� ������ � ���������� �������� ������� 
			cout << "ERROR:incorrect numbers or the first character is 0" << endl;
			dell_nam_1_2();
			return false;
		}
		for (int i = 0; i < snam_2.size(); i++) {             // ������ ��������� 2 ������
			if (snam_2[i] == 45 && snam_2[0] == 45) { // �������� �� ������� ������ �� ������ �������
				if (i == 0) {
					is_it_minus_2 = 1;
				}
				else {
					trriger = 1;
				}
			}
			else if (snam_2[i] == 48 || snam_2[i] == 49 || snam_2[i] == 50 || snam_2[i] == 51 || snam_2[i] == 52 || snam_2[i] == 53 || snam_2[i] == 54 || snam_2[i] == 55 || snam_2[i] == 56 || snam_2[i] == 57) {   // ���� ������ ����� ������ ����� �� 0 �� 9
				string cha;
				cha = snam_2[i];
				nam_2f.push_back(stoi(cha.c_str())); // ����������
			}
			else {
				trriger = 1;
			}


			if (trriger == 1) {
				break;
			}
		}
		if (trriger == 1) { // ���� ����������� ����� �� ������� � �������
			cout << "ERROR:incorrect numbers or the first character is 0" << endl;
			dell_nam_1_2();
			return false;
		}
		else if (trriger == 0) { // ���� ��� ������ ������ �� ���������� ��� ������� � ������� ������� ����� �� �����
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
			return true;
		}
		dell_nam_1_2();
		return false;
	}
	void print_all() { 
		if (nam_1.size() != 0) {
			cout << "nam 1: ";
			if (is_it_minus_1 == 1) {
				cout << "-";
			}
			for (int i = nam_1.size() - 1; i >= 0; i--) {
				cout << nam_1[i];
			}
			cout << endl;
		}
		if (nam_2.size() != 0) {
			cout << "nam 2: ";
			if (is_it_minus_2 == 1) {
				cout << "-";

			}
			for (int i = nam_2.size() - 1; i >= 0; i--) {
				cout << nam_2[i];
			}
			cout << endl;
		}
		if (answer.size() != 0) {
			cout << "answer: ";
			if (is_it_minus_ansver == 1) {
				cout << "-";

			}
			for (int i = answer.size() - 1; i >= 0; i--) {
				cout << answer[i];
			}
			cout << endl;
		}
	}
	void sum() {
		if (nam_1.size() != 0 || nam_2.size() != 0) {          //���� ������� ����������
			dell_answer();
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {    // ���� ���� �� ����� � �������
				
				if (nam_1.size() == nam_2.size()) { // ���� ������� ������� �����
					bool trriger = 0;     // �� ����� ����� 1 ���� 2 ����� ���������
					int target;         // ���������� � ������ ����� � ����� ���������� ���������� �������(�� �����)
					for (int i = nam_1.size() - 1; i >= 0; i--) { // ������ �� ����� �� �������� � ��������
						
						if (nam_1[i] == nam_2[i]) { // ���� ����� ����� 
							if (i == 0) { // ���� ����� ��� ��������� 
								trriger = 1; // ����� ����� 0
								break;
							}
						}
						else if (nam_1[i] > nam_2[i]) { // ���� ����� �� �����
							if (is_it_minus_1 == 1 && is_it_minus_2 == 0) { // ���� ����� ��� � 1��� �����
								is_it_minus_end = 1;
								
							}
							target = i + 1;
							break;
						}
						else if (nam_1[i] < nam_2[i]) {  // ���� ����� �� �����
							if (is_it_minus_1 == 0 && is_it_minus_2 == 1) { // ���� ����� ��� � 2��� �����
								is_it_minus_end = 1;
								
							}
							
							target = i + 1;
							break;
						}
					}
					if (trriger == 1) {
						nam_end.push_back(0); // ������� ��� ������� ����� = 0 ���������
					}
					else {  // ���� ����� �� ����� 0
						if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {  // ���� ����� 1 � �������
							if (is_it_minus_end == 0) { // ��� ����� � ������
								for (int i = 0; i < target; i++) { //  ������������ (�� �����) ����� � 2 ����� �� �������
									nam_end.push_back(nam_2[i]);
								}
							}
							else { // ���� ����� � �������
								for (int i = 0; i < target; i++) {
									nam_end.push_back(nam_1[i]); //   ������������ (�� �����) ����� � 1 ����� �� �������
								}
							}
						}
						else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {// ���� ����� 2 � �������
							if (is_it_minus_end == 0) {    // ��� ����� � ������
								for (int i = 0; i < target; i++) {
									nam_end.push_back(nam_1[i]); // ������������(�� �����) ����� � 1 ����� �� �������
								}
							}
							else {  // ���� ����� � �������
								for (int i = 0; i < target; i++) { 
									nam_end.push_back(nam_2[i]);   //  ������������ (�� �����) ����� � 2 ����� �� �������
								}
							}
						}

						for (int i = 0; i < target; i++) { //����������� �� ������� 
							int sum_1; // ����� 
							if (is_it_minus_1 == 1 && is_it_minus_2 == 0) { // ���� ����� 1 � �������     #�� ����� ��� �� ����� �� ���� ����� �������� ��� ���� �������� �� �������� �������(������� �� �����)
								if (is_it_minus_end == 0) {                 // ���� ����� ��� ������
									sum_1 = nam_end[i] - nam_1[i];    
								}
								else if (is_it_minus_end == 1) {   // ���� ����� � ������
									sum_1 = nam_end[i] - nam_2[i];
								}
							}
							else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {// ���� ����� 2 � �������
								if (is_it_minus_end == 0) {  // ���� ����� ��� ������
									sum_1 = nam_end[i] - nam_2[i];
								}
								else if (is_it_minus_end == 1) {  // ���� ����� � ������
									sum_1 = nam_end[i] - nam_1[i];
								}
							}

							if (sum_1 < 0) { // ���� ����� ���������� �� ���� ����� �������� 1
								
								nam_end[i] = sum_1 + 10; // �� ����� � �����
								int ii = i + 1; // ��� ����� ���� ������
								while (true) {
									if (ii == target) { // ���� ������� �� ������� �������
										break;
									}
									else { // ���� ������ ��� ����
										int sum_2 = nam_end[ii] - 1; // ������� ���� �����
										if (sum_2 < 0) { // �� ����������
											
											nam_end[ii] = sum_2 + 10; 

										}
										else { // ����������
											nam_end[ii] = sum_2;
											break;
										}

									}
									ii++;
								}

							}
							else { //���� ������ ��������� � ����� ������ ����������
								nam_end[i] = sum_1;
							}
						}
						for (int i = target - 1; i >= 0; i--) { // �������� ����� � ������ �����
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
					if (is_it_minus_1 == 1) { // ���� ������� ����� � -
						is_it_minus_end = 1;
						SumWithMinus_1();
					}
					else if (is_it_minus_2 == 1) { //���� ������� ����� � -
						is_it_minus_end = 0;
						SumWithMinus_1();
					}
				}

				if (nam_1.size() < nam_2.size()) {
					if (is_it_minus_1 == 1) { // ���� ������� ����� � -
						is_it_minus_end = 0;
						SumWithMinus_2();
					}
					else if (is_it_minus_2 == 1) { //���� ������� ����� � -
						is_it_minus_end = 1;
						SumWithMinus_2();
					}
				}
			}
			else  { // ���� 2 ����� ��� ������ ��� 2 � �������
				if (is_it_minus_1 == 0 && is_it_minus_2 == 0) { // ���������� �����
				}
				else if (is_it_minus_1 == 1 && is_it_minus_2 == 1) { // ���������� ������

					is_it_minus_end = 1;
				}
				if (nam_1.size() < nam_2.size()) {  // ���� 1 ����� ������ 2

					for (int i = 0; i < nam_2.size(); i++) { // ������ �� ����� ��������� ����� 2 ����� ��� ��� ��� ������ 
						nam_end.push_back(nam_2[i]);
					}
					
					for (int i = 0; i < nam_1.size(); i++) {
						int sum_2_elem = nam_end[i] + nam_1[i];  // �������� 2� ����� (��������� �������) #nam_end ������������ ��� ��� ������� ����� ���� �� 1 ������ ��� nam_1
						
						if (sum_2_elem > 9) {              // ���� ����� ���������� 1 � ���� �����
							int iii = sum_2_elem % 10;  // �������� �������� ������� �� 10 �� ����� ����� 
							nam_end[i] = iii;
						
							nam_end[i + 1] = nam_end[i + 1] + 1; // ���� ���� ��������� �� 1
							SumWithMinusOrPlus(i);
						}
						else if (sum_2_elem < 10) {   // ���� ����� ���������� 1 � ���� �����
							nam_end[i] = sum_2_elem;  // ���������� ����� � ��������
						}
						
					}

				}
				else if (nam_2.size() < nam_1.size()) {  // ���� 2 ����� ������ 1

					for (int i = 0; i < nam_1.size(); i++) { // ������ �� ����� ��������� ����� 2 ����� ��� ��� ��� ������ 
						nam_end.push_back(nam_1[i]);
					}

					for (int i = 0; i < nam_2.size(); i++) {
						int sum_2_elem = nam_end[i] + nam_2[i];  // �������� 2� ����� (��������� �������) #nam_end ������������ ��� ��� ������� ����� ���� �� 1 ������ ��� nam_1

						if (sum_2_elem > 9) {              // ���� ����� ���������� 1 � ���� �����
							int iii = sum_2_elem % 10;  // �������� �������� ������� �� 10 �� ����� ����� 
							nam_end[i] = iii;

							nam_end[i + 1] = nam_end[i + 1] + 1; // ���� ���� ��������� �� 1
							SumWithMinusOrPlus(i);
						}
						else if (sum_2_elem < 10) {   // ���� ����� ���������� 1 � ���� �����
							nam_end[i] = sum_2_elem;  // ���������� ����� � ��������
						}

					}


				}
				else if (nam_1.size() == nam_2.size()) {  // ���� 1 � 2 ����� �����				
						for (int i = 0; i < nam_1.size(); i++) { // ������ �� ����� ��������� ����� ������ ����� 
							nam_end.push_back(nam_1[i]);
						}

						for (int i = 0; i < nam_1.size(); i++) { // ���������� � ������ �� ����� ���������� ��������

							int sum_2_elem = nam_end[i] + nam_2[i];  // �������� 2� ����� (��������� �������) #nam_end ������������ ��� ��� ������� ����� ���� �� 1 ������ ��� nam_1
							if (sum_2_elem > 9) {              // ���� ����� ���������� 1 � ���� �����
								int iii = sum_2_elem % 10;  // �������� �������� ������� �� 10 �� ����� ����� 
								nam_end[i] = iii;
								int ooo = i + 1;              // �������� ���� ��������
								if (ooo < nam_end.size()) {   // ���� ��� �� ������� �� ������� �������

									nam_end[i + 1] = nam_end[i + 1] + 1; // ���� ���� ��������� �� 1
									int val = 1; // �� ������� ���� ����� ���� ���� ��������� �������� �� ������� �������� ���� ��� 9
									while (true) // ���� �� ������ ��� ���� ������� �� ����� 10 ��� ������
									{
										int rr = i + val; // ���� �������� ����� �������� � �������
										if (rr < nam_end.size()) { // ���� ������� ����������
											if (nam_end[rr] > 9) { // ���� ��� ����� ��������
												nam_end[rr] = nam_end[rr] % 10;
												if (rr + 1 < nam_end.size()) {// ���� ���� ������ ���������� 
													nam_end[rr + 1] = nam_end[rr + 1] + 1; // ���������� ���� ������� �� 1
												}
												else { // ���� ���� ������� � ������� �� ����������
													nam_end.push_back(1); // ���������� 1 � ����� �������
													break;
												}
											}
											else {
												break;
											}
										}
										else { // ���� �������� �� ����������
											if (nam_end[rr] > 9) { // ���� ��� ����� ��������
												nam_end[rr] = nam_end[rr] % 10;
												nam_end.push_back(1); // ��������� �� ������ ���� 1
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
							else if (sum_2_elem < 10) {   // ���� ����� ���������� 1 � ���� �����
								nam_end[i] = sum_2_elem;  // ���������� ����� � ��������
							}




						}
					


				}

			}
			for (int i = 0; i < nam_end.size(); i++) {
				answer.push_back(nam_end[i]);
			}
			is_it_minus_ansver = is_it_minus_end;
			dell_end();
			
		}
	}
	void razn() {
		if (nam_1.size() != 0 || nam_2.size() != 0) {          //���� ������� ����������
			dell_answer();
				if (is_it_minus_1 == 0 && is_it_minus_2 == 0) {
					is_it_minus_2 = 1;
					sum();
					is_it_minus_2 = 0;
				}
				else if (is_it_minus_1 == 1 && is_it_minus_2 == 1) {
					is_it_minus_2 = 0;
					sum();
					is_it_minus_2 = 1;
				}
				else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) {
					is_it_minus_2 = 0;
					sum();
					is_it_minus_2 = 1;
				}
				else if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {
					is_it_minus_2 = 1;
					sum();
					is_it_minus_2 = 0;
				}
				

		}
	}
	void ymn(){
		if (nam_1.size() != 0 || nam_2.size() != 0) {
			dell_answer();
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {//������� ������� � �������
				is_it_minus_end = 1;
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 1 || is_it_minus_1 == 0 && is_it_minus_2 == 0) { // ������� ������� � ������� ��� ������
				is_it_minus_end = 0;
			}



			if (nam_1.size() == 1 || nam_2.size() == 1) { // �� ���� �������� = 0
				if (nam_1[0] == 0 || nam_2[0] == 0) {
					nam_end.push_back(0);
				
				}
			}

			if (nam_end.size() != 1) {
				vector <int> nam_1_0 = nam_1;
				vector <int> nam_2_0 = nam_2;

				for (int i = 0; i < nam_1.size(); i++) {     // �������� 1 �����
					for (int ii = 0; ii < nam_2.size(); ii++) { // �� ������
						if (nam_end.size() == ii + i) {    // ���� ������� �� ������� ������� ������
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
						else {   // ���� �������� ��� � ������� �������
							int ymn_1 = nam_1[i] * nam_2[ii];
							if (ymn_1 > 9) { // �� ����������
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
							else if (ymn_1 < 10) { // ������� � (��������) ������� ������
								int sum_1 = nam_end[i + ii] + ymn_1; 
								if (sum_1 > 9) { // ������
									nam_end[i + ii] = sum_1 - 10;
									if (i + ii + 1 < nam_end.size()) {
										nam_end[i + ii + 1] = nam_end[i + ii + 1] + 1;
										SumWithMinusOrPlus(i + ii);
									}
									else {
										nam_end.push_back(1);
									}
								}
								else if (sum_1 < 10) { // �������
									nam_end[i + ii] = sum_1;
								}

							}

						}





					}




					
				}
				dell_nam_1_2();
				for (int i = 0; i < nam_1_0.size(); i++) {
					nam_1.push_back(nam_1_0[i]);
				}
				for (int i = 0; i < nam_2_0.size(); i++) {
					nam_2.push_back(nam_2_0[i]);
				}
			}
			
			for (int i = 0; i < nam_end.size(); i++) {
				answer.push_back(nam_end[i]);
			}
			dell_end();
			is_it_minus_ansver = is_it_minus_end;




		}
	}
	void del(){      
		if (nam_1.size() != 0 || nam_2.size() != 0) {
			dell_answer();
			vector <int> nam_1_0 = nam_1;
			vector <int> nam_2_0 = nam_2;
			bool minus = 0;
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0 || is_it_minus_1 == 0 && is_it_minus_2 == 1) {//������� ������� � �������
				minus = 1;
			}
			else if (is_it_minus_1 == 1 && is_it_minus_2 == 1 || is_it_minus_1 == 0 && is_it_minus_2 == 0) { // ������� ������� � ������� ��� ������
				minus = 0;
			}
			if (nam_2.size() == 1 && nam_2[0] == 1) { // ������� �� 1
				for (int i = 0; i < nam_1.size(); i++) {
					nam_end.push_back(nam_1[i]);
				}
			}
			else {
				if (nam_1.size() == nam_2.size()) {
					string nam_1_str = "000000000"; // �������� 9 ���������(0 �������� ����������) 
					string nam_2_str = "000000000";
					int i = 0;
					while (true) // ������ 9 ��������� � ������ ��� ������
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

					int nam_1_int = stoi(nam_1_str.c_str()); // �������������� ������� � ���
					int nam_2_int = stoi(nam_2_str.c_str());
					nam_end.push_back(nam_1_int / nam_2_int); // ����� ����� ������� ���� �����
				}
				else if (nam_1.size() < nam_2.size()) { // �������
					is_it_minus_end = 0;
					nam_end.push_back(0);
				}
				else if (nam_1.size() > nam_2.size()) { // ���������� 0 ,�������� ������� , �������� �������� ����� , ��������� ���1 � ���2
					int nam_2_size = nam_2.size();
					int nam_1__nam_2 = nam_1.size() - nam_2.size();
					vector<int> nam_2_zer;
					for (int i = nam_2.size() - 1; i >= 0; i--) {
						nam_2_zer.push_back(nam_2[i]);
					}
					for (int i = 0; i < nam_1__nam_2; i++) {
						nam_2_zer.push_back(0);
					}
					for (int i = 0; i < nam_2_size; i++) {
						nam_2.pop_back();
					}
					for (int i = 0; i < nam_2_zer.size(); i++) {
						nam_2.push_back(nam_2_zer[nam_1.size() - 1 - i]);
					}
					/*vector<int> nam_1_save;
					for (int i = 0; i < nam_1.size(); i++) {
						nam_1_save.push_back(nam_1[i]);
					}*/
					int target = 0;
					vector<int> end;
					while (1) {
						is_it_minus_1 = 0;
						is_it_minus_2 = 1;
						sum();
						for (int i = 0; i < answer.size(); i++) {
							nam_end.push_back(answer[i]);
						}
						is_it_minus_end = is_it_minus_ansver;
						dell_answer();
						//zerroes_nam_2();
						int size_2 = nam_2.size();
						
						int size_1 = nam_1.size();
						int size_end = nam_end.size();
						if (is_it_minus_end == 0) {
							target++;

							for (int i = 0; i < size_1; i++) {
								nam_1.pop_back();
							}
							for (int i = 0; i < nam_end.size(); i++) {
								nam_1.push_back(nam_end[i]);
							}
							for (int i = 0; i < size_end; i++) {
								nam_end.pop_back();
							}

						}
						else if (is_it_minus_end == 1) {
							end.push_back(target);
							target = 0;
							for (int i = 0; i < size_end; i++) {
								nam_end.pop_back();
							}
							if (nam_2.size() == nam_2_size) {
								break;
							}
							else {
								for (int i = 0; i < size_2; i++) {
									nam_2.pop_back();
								}
								nam_2_zer.pop_back();
								is_it_minus_end = 0;
								for (int i = 0; i < nam_2_zer.size(); i++) {
									nam_2.push_back(nam_2_zer[nam_2_zer.size() - 1 - i]);
								}
							}
						}
					}
					is_it_minus_end = minus;
					for (int i = end.size() - 1; i >= 0; i--) {
						nam_end.push_back(end[i]);
					}



				}
			}
			dell_nam_1_2();
			for (int i = 0; i < nam_1_0.size(); i++) {
				nam_1.push_back(nam_1_0[i]);
			}
			for (int i = 0; i < nam_2_0.size(); i++) {
				nam_2.push_back(nam_2_0[i]);
			}
			for (int i = 0; i < nam_end.size(); i++) {
				answer.push_back(nam_end[i]);
			}
			is_it_minus_ansver = is_it_minus_end;
			dell_end();
			if (answer.size() > 1) {
				int ii = answer.size();
				for (int i = ii - 1; i >= 0; i--) {
					if (answer[i] == 0) {
						answer.pop_back();
					}
					else
						break;
				}
			}
			
		}	
	}
	void print_answer() {
		
		
		if (answer.size() != 0) {
			cout << "Answer : ";
			if (is_it_minus_ansver == 1) {
				cout << "-";				
			}
			for (int i = answer.size() - 1; i >= 0; i--) {
				cout << answer[i];
			}
			cout << endl;
		}
		else {
			cout << "Answer is not found" << endl;
		}
		
	}
	void computing(string nam_1___nam_2) {
		dell_data();
		string nam_1_f;
		string nam_2_f;
		int ii = 0;
		char rr;
		if (nam_1___nam_2.size() != 0) {
			for (int i = 0; i < nam_1___nam_2.size(); i++) {
				ii++;
				if (nam_1___nam_2[i] == '-' || nam_1___nam_2[i] == '+' || nam_1___nam_2[i] == '*' || nam_1___nam_2[i] == '/') {
					rr = nam_1___nam_2[i];
					break;
				}
			}
			if (ii == nam_1___nam_2.size()) {
				cout << "ERROR:incorrect numbers" << endl;
			}
			else {
				for (int i = 0; i < ii - 1; i++) {
					nam_1_f.push_back(nam_1___nam_2[i]);
				}
				for (int i = ii; i < nam_1___nam_2.size(); i++) {
					nam_2_f.push_back(nam_1___nam_2[i]);
				}
				bool tt = creator(nam_1_f, nam_2_f);
				if (tt == 1) {
					if (rr == '+') {
						sum();
					}
					else if (rr == '-') {
						razn();
					}
					else if(rr == '*') {
						ymn();
					}
					else if (rr == '/') {
						del();
					}
					
				}
			}
		}
	}
	void dell_data() {
		dell_nam_1_2();
		dell_end();
		dell_answer();
		
	}




};









int main() {
	while (1) {
		Big_numbers win;
		string a;
		string b;
		string c;
		cout << "nam_1 : "; cin >> a;
		cout << "nam_2 : "; cin >> b;
		cout << "computing : "; cin >> c;

		win.creator(a, b);

		win.sum();
		win.print_answer();
		cout << endl;

		win.razn();
		win.print_answer();
		cout << endl;

		win.ymn();
		win.print_answer();
		cout << endl;

		win.del();
		win.print_answer();
		cout << endl;

		win.print_all();
		cout << endl;

		win.computing(c);
		win.print_all();
		cout << endl;

		win.dell_data();
		win.print_all();
	}
	return 0;
}
