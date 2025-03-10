#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
// moi tao
int valueChange(int n, int valuedau, int valuecuoi) {
	if (n < valuedau) n = valuedau;
	else if (n > valuecuoi) n = valuecuoi;
	return n;
}
// moi tao

int firstMeet(int& exp1, int& exp2, int e1) {
	// TODO: Complete this function
	if (e1 < 0 || e1>99) return -99;
	exp1 = valueChange(exp1, 0, 600);
	exp2 = valueChange(exp2, 0, 600);

	float pre_exp1 = exp1;
	float pre_exp2 = exp2;

	if (e1 <= 3) {
		if (e1 == 0) exp2 += 29;
		else if (e1 == 1) exp2 += 45;
		else if (e1 == 2) exp2 += 75;
		else if (e1 == 3) exp2 += (29 + 45 + 75);
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0) pre_exp1 = (int)(exp1 + D * 0.005 + 0.999);
		else pre_exp1 = ceil(exp1 - (int)(D * 0.01));
		exp1 = pre_exp1;
	}
	else {
		if (e1 >= 4 && e1 <= 19) pre_exp2 += (int)(e1 * 0.25 + 0.999) + 19; //attention //check new testcase before submitting
		else if (e1 >= 20 && e1 <= 49) pre_exp2 += (int)(e1 * 0.111111 + 0.999) + 21; //attention //check new testcase before submitting
		else if (e1 >= 50 && e1 <= 65) pre_exp2 += (int)(e1 * 0.0625 + 0.999) + 17; //attention //check new testcase before submitting
		else if (e1 >= 66 && e1 <= 79) {
			pre_exp2 += (int)(e1 * 0.25 + 0.999) + 19;
			exp2 = pre_exp2;
			exp2 = valueChange(exp2, 0, 600);
			pre_exp2 = exp2;
			if (pre_exp2 > 200) pre_exp2 += (int)(e1 * 0.111111 + 0.999) + 21;
		}
		else if (e1 >= 80 && e1 <= 99) {
			pre_exp2 += (int)(e1 * 0.25 + 0.999) + 19;
			exp2 = pre_exp2; 
			exp2 = valueChange(exp2, 0, 600);
			pre_exp2 = exp2;
			pre_exp2 += (int)(e1 * 0.111111 + 0.999) + 21;
			exp2 = pre_exp2;
			exp2 = valueChange(exp2, 0, 600);
			pre_exp2 = exp2;
			if (pre_exp2 > 400) {
				pre_exp2 += (int)(e1 * 0.0625 + 0.999) + 17;
				exp2 = pre_exp2;
				exp2 = valueChange(exp2, 0, 600);
				pre_exp2 = exp2;
				pre_exp2 = (int)(pre_exp2 * 1.15 + 0.999);
			}
		}
		exp2 = pre_exp2;
		pre_exp1 -= e1;
		exp1 = pre_exp1;
	}
	exp1 = valueChange(exp1, 0, 600);
	exp2 = valueChange(exp2, 0, 600);
	return exp1 + exp2;
}

// Task 2
float probability(int nearbyVal) {
	int n = sqrt(nearbyVal);
	float newVal = 1;
	newVal = nearbyVal;
	if ((nearbyVal - n * n) > ((n + 1) * (n + 1) - nearbyVal)) 
		//cout << fixed << setprecision(2);
	return (newVal / ((n + 1) * (n + 1)) + 80) / 123;
	else return 1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
	// TODO: Complete this function
	if (E2 < 0 || E2>99) return -99;
	valueChange(HP1, 0, 666);
	valueChange(EXP1, 0, 600);
	valueChange(M1, 0, 3000);

	float pre_HP1 = HP1;
	float pre_EXP1 = EXP1;
	float pre_M1 = M1;
	float motnua = pre_M1 / 2; // Khai bao bien lam moc cho TH E2 odd

	// con duong so 1 ////////////////////////////////////////

	float P1 = 0;
	P1 = probability(EXP1);

	// con duong so 2 ////////////////////////////////////////

	float balance = 0;
	int k = 0;

	do {
		if (M1 == 0) break;
		// 2.1
		// 2.1
		if (HP1 < 200) {
			HP1 = (int)(pre_HP1 * 1.3 + 0.999);
			HP1 = valueChange(HP1, 0, 666);
			M1 -= 150;
			M1 = valueChange(M1, 0, 3000);
			balance += 150;
			if (balance > motnua && E2 % 2 == 1) break; // Ket thuc vong lap khi loss money > 1/2 * M1 trong TH E2%2==1 (1)
		}
		else {
			HP1 = (int)(pre_HP1 * 1.1 + 0.999);
			HP1 = valueChange(HP1, 0, 666);
			M1 -= 70;
			M1 = valueChange(M1, 0, 3000);
			balance += 70;
			if (balance > motnua && E2 % 2 == 1) break; // Ket thuc vong lap khi loss money > 1/2 * M1 trong TH E2%2==1 (2)
		}

		pre_HP1 = HP1;
		if (M1 == 0) break; //dung thuc hien hanh dong khi M = 0 cua TH E2 % 2 == 0

		// 2.2
		// 2.2
		if (EXP1 < 400) {
			M1 -= 200;
			M1 = valueChange(M1, 0, 3000);
			balance += 200;
		}
		else {
			M1 -= 120;
			M1 = valueChange(M1, 0, 3000);
			balance += 120;
		}
		EXP1 = (int)(pre_EXP1 * 1.13 + 0.999);
		EXP1 = valueChange(EXP1, 0, 600);
		pre_EXP1 = EXP1;
		if (balance > motnua && E2 % 2 == 1) break; // Ket thuc vong lap khi loss money > 1/2 * M1 trong TH E2%2==1 (3)
		if (M1 == 0) break; //dung thuc hien hanh dong khi M = 0 cua TH E2 % 2 == 0

		// 2.3
		// 2.3
		if (EXP1 < 300) {
			M1 -= 100;
			M1 = valueChange(M1, 0, 3000);
			balance += 100;
		}
		else {
			M1 -= 120;
			M1 = valueChange(M1, 0, 3000);
			balance += 120;
		}
		EXP1 = (int)(pre_EXP1 * 0.90 + 0.999);
		EXP1 = valueChange(EXP1, 0, 600);
		pre_EXP1 = EXP1;
		if (balance > motnua && E2 % 2 == 1) break; // Ket thuc vong lap khi loss money > 1/2 * M1 trong TH E2%2==1 (5)
		if (M1 == 0) break;


		if (E2 % 2 == 1)	k++;
	} while (k > 0);

	pre_HP1 = HP1;
	pre_EXP1 = EXP1;
	HP1 = (int)(pre_HP1 * 0.83 + 0.999);
	EXP1 = (int)(pre_EXP1 * 1.17 + 0.999);
	HP1 = valueChange(HP1, 0, 666);
	EXP1 = valueChange(EXP1, 0, 600);
	pre_HP1 = HP1;
	pre_EXP1 = EXP1;

	float P2 = 0;
	P2 = probability(EXP1);


	//con duong so 3 ////////////////////////////////////////
	int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

	int i = 0; //chi so cua day P
	if (E2 >= 0 && E2 <= 9) {
		i = E2;
	}
	else if (E2 >= 10 && E2 <= 99) {
		i = (E2 % 10) + (E2 / 10);
		i = i % 10;
	}

	float P3 = P[i] * 0.01;

	if (P1 == 1 && P2 == 1 && P3 == 1) {
		pre_EXP1 = EXP1;
		EXP1 = (int)(pre_EXP1 * 0.75 + 0.999);
		EXP1 = valueChange(EXP1, 0, 600);
		pre_EXP1 = EXP1;
	}
	else {
		float trbcongP = (P1 + P2 + P3) / 3;
		if (trbcongP < 0.5) {     // lieu co check duoc cac gia tri rat gan 0.5
			pre_HP1 = HP1;
			pre_EXP1 = EXP1;
			HP1 = (int)(pre_HP1 * 0.85 + 0.999);
			HP1 = valueChange(HP1, 0, 666);
			EXP1 = (int)(pre_EXP1 * 1.15 + 0.999);
			EXP1 = valueChange(EXP1, 0, 600);
			pre_HP1 = HP1;
			pre_EXP1 = EXP1;
		}
		else {
			pre_HP1 = HP1;
			pre_EXP1 = EXP1;
			HP1 = (int)(pre_HP1 * 0.90 + 0.999);
			HP1 = valueChange(HP1, 0, 666);
			EXP1 = (int)(pre_EXP1 * 1.20 + 0.999);
			EXP1 = valueChange(EXP1, 0, 600);
			pre_HP1 = HP1;
			pre_EXP1 = EXP1;
		}
	}

	return HP1 + EXP1 + M1;
}

// Task 3

int maxcheo(int arr[10][10], int ROWS, int COLS) {
	int start = 0;
	int max = arr[ROWS][COLS];

	if (ROWS > COLS) {
		start = ROWS - COLS;
		for (int i = 0; i < (10 - start); i++) {
			if (arr[start + i][i] > max) {
				max = arr[start + i][i];
			}
		}
		int sum = COLS + ROWS;
		int k = sum - 9;
		for (int j = k; j <= 9; j++) {
			if (arr[j][sum - j] > max) {
				max = arr[j][sum - j];
			}
		}
	}
	else if (COLS > ROWS) {
		start = COLS - ROWS;
		for (int i = 0; i < (10 - start); i++) {
			if (arr[i][start + i] > max) {
				max = arr[i][start + i];
			}
		}
		int sum = COLS + ROWS;
		int k = sum - 9;
		for (int j = k; j <= 9; j++) {
			if (arr[j][sum - j] > max) {
				max = arr[j][sum - j];
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (arr[i][i] > max) {
				max = arr[i][i];
			}
		}
		int sum = COLS + ROWS;
		int k = sum - 9;
		for (int j = k; j <= 9; j++) {
			if (arr[j][sum - j] > max) {
				max = arr[j][sum - j];
			}
		}
	}
	
	return max;
}


int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
	// TODO: Complete this function
	if (E3 < 0 || E3>99) return -99;

	float pre_HP1 = HP1;
	float pre_EXP1 = EXP1;
	float pre_HP2 = HP2;
	float pre_EXP2 = EXP2;

	int arr[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}

	int i = 0;
	int j = 0;

	for (int k = 0; k < 10; k++) {
		for (int d = 0; d < 10; d++) {
			if (arr[k][d] > E3 * 2) {
				i += 1;
			}
			if (arr[k][d] < -E3) {
				j += 1;
			}
		}
	}

	do {
		i = i % 10 + i / 10;
	} while (i >= 10);

	do {
		j = j % 10 + j / 10;
	} while (j >= 10);

	int scoreTaxi = arr[i][j];
	int scoreSaW = maxcheo(arr, i, j);

	if (abs(scoreTaxi) > scoreSaW) {
		
		EXP1 = int(pre_EXP1 * 0.88 + 0.999);
		EXP1 = valueChange(EXP1, 0, 600);
		HP1 = int(pre_HP1 * 0.9 + 0.999);
		HP1 = valueChange(HP1, 0, 666);

		EXP2 = int(pre_EXP2 * 0.88 + 0.999);
		EXP2 = valueChange(EXP2, 0, 600);
		HP2 = int(pre_HP2 * 0.9 + 0.999);
		HP2 = valueChange(HP2, 0, 666);
		
		return scoreTaxi;
	}
	else {
		EXP1 = int(pre_EXP1 * 1.12 + 0.999);
		EXP1 = valueChange(EXP1, 0, 600);
		HP1 = int(pre_HP1 * 1.1 + 0.999);
		HP1 = valueChange(HP1, 0, 666);

		EXP2 = int(pre_EXP2 * 1.12 + 0.999);
		EXP2 = valueChange(EXP2, 0, 600);
		HP2 = int(pre_HP2 * 1.1 + 0.999);
		HP2 = valueChange(HP2, 0, 666);

		return scoreSaW; // co tra gia tri am khong?
	}
}


// Task4
int checkCondition4(const char* s, char se[], int length_s, int size_se) {
	for (int i = 0; i < length_s; i++) {
		if (s[i] == se[0]) {
			if (size_se == 1) return -(300 + (i));
			int k = 0;
			for (int j = 0; j < size_se; j++) {
				if (s[i + j] == se[j]) k++;
			}
			if (k == size_se) {
				return -(300 + (i)); // neu chuoi s co chua chuoi se
			}
		}
	}
	return -1;
}

int checkCondition5(const char* s, int length_s) {
	//int count = 0;
	for (int i = 0; i < length_s; i++) {
		if ((i > 0) && (s[i - 1] == s[i]) && s[i + 1] == s[i] && (i < length_s - 1)) {
			//count++;
			//if (count == 2) 
			return -(400 + (i - 1));  //i la index de xac dinh vi tri
		}
		//else count = 0;
	}
	return -1;
}

int checkCondition6(const char* s, int length_s) {
	int spec_symbol = 0;
	for (int i = 0; i < length_s; i++) {
		if (*(s + i) == '@' || *(s + i) == '%' || *(s + i) == '#' || *(s + i) == '$' || *(s + i) == '!') spec_symbol++;
		if (i == length_s - 1 && spec_symbol == 0) return -5;
	}
	return -1;
}

int checkCondition7(const char* s, int length_s) {
	for (int i = 0; i < length_s; i++) {
		if (*(s + i) < '0' || (*(s + i) > '9' && *(s + i) < 'A') || (*(s + i) > 'Z' && *(s + i) < 'a') || *(s + i) > 'z') {
			if (*(s + i) != '@' && *(s + i) != '%' && *(s + i) != '#' && *(s + i) != '$' && *(s + i) != '!') return i;
		} //Xac dinh cac ky tu hop le
	}
	return -1;
}

int checkPassword(const char* s, const char* email) {
	// TODO: Complete this function
	int length_s = strlen(s);
	if (length_s < 8) return -1;
	if (length_s > 20) return -2;

	char se[100];
	int size_se = 0;
	for (int i = 0; i < 100; i++) {
		if (*(email + i) == '@') {
			size_se = i;
			se[i] = '\0';
			break;
		}
		se[i] = *(email + i);
	}
	if (size_se == 0) return -300;
	while (1) {
		int C4 = checkCondition4(s, se, length_s, size_se);
		if (C4 != -1) return C4;
		int C5 = checkCondition5(s, length_s);
		if (C5 != -1) return C5;
		int C6 = checkCondition6(s, length_s);
		if (C6 != -1) return C6;
		int C7 = checkCondition7(s, length_s);
		if (C7 != -1) return C7;
		break;
	}
	return -10;
}

// Task 5
int sameString(const char* dung, const char* chay) {
	int same = strcmp(dung, chay);
	if (same != 0) return 0; //khong giong thi in ra false
	else return 1; //giong thi in ra true
}

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
	// TODO: Complete this function
	const char* dem_pwds[30];
	int dem[30];
	for (int i = 0; i < 30; i++) {
		dem[i] = 0;
	}

	int count = 0;
	// Tim so cac chuoi khac nhau
	for (int i = 0; i < num_pwds; i++) {
		int is_unique = 1;
		for (int j = 0; j < i; j++) {
			if (sameString(arr_pwds[i], arr_pwds[j])) {
				is_unique = 0;
				break;
			}
		}
		if (count == 30) break;
		if (is_unique) {
			count++;
			dem_pwds[count - 1] = arr_pwds[i];
		}
	}//

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < num_pwds; j++) {
			if (sameString(dem_pwds[i], arr_pwds[j])) dem[i] += 1;   //so lan xuat hien cua mot chuoi trong mang //can giong nhau
		}
	}

	int length[30];

	for (int i = 0; i < 30; i++) {
		if (i < count) length[i] = strlen(dem_pwds[i]);    // do dai cua moi chuoi // co can thiet khong?
		else length[i] = -1;
	}

	int max = dem[0];
	int count_dem = 0;
	for (int i = 0; i < count; i++) {
		if (max < dem[i]) max = dem[i]; //so lan xuat hien nhieu nhat cua mot chuoi trong day
	}

	int max_length = 0;

	for (int i = 0; i < count; i++) {
		if (dem[i] == max) {
			if (max_length < length[i]) max_length = length[i];
		}
	}

	int vitri = 0;

	for (int i = 0; i < count; i++) {
		if (max == dem[i] && max_length == length[i]) {
			for (int j = 0; j < num_pwds; j++) {
				if (sameString(arr_pwds[j], dem_pwds[i])) { //can giong nhau
					int vitri = j;
					return vitri;
				}
			}
		}
	}
	return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
