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


public:
	bool creator(string snam_1, string snam_2) {      
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
			cout << "ERROR:incorrect numbers" << endl;
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
			cout << "ERROR:incorrect numbers" << endl;
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
			return 1;
		}
	}
	void test_vivod() { // �������� ����� 3 �������� �� �������
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
		if (nam_1.size() != 0 || nam_2.size() != 0) {          //���� ������� ����������
			if (is_it_minus_1 == 1 && is_it_minus_2 == 0) {    // ���� ���� �� ����� � �������
				
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
			else if (is_it_minus_1 == 0 && is_it_minus_2 == 1) { // ���� ���� �� ����� � �������






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
