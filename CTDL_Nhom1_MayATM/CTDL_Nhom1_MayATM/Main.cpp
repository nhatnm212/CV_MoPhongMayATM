#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "LinkedList.h" 
#include "Node.h"
#include "TheTu.h"
#include "AdminAccount.h"
#include "UserAccount.h" 
#include <ctime> 
#include "GiaoDien.h"
#pragma warning(disable:4996) 
using namespace std;
#define MAX_LENGHT  128 
#define ENTER       13 
#define BACKSPACE   8 
#define ESCAPE      27 

int main() {
	
	time_t curr_time = time(NULL); 
	char* tm = ctime(&curr_time); 
	cout << "\n Now: " << tm; 

	cout << "\n\n";
	GiaoDien gd; 
	gd.SET_COLOR(6);
	cout << "		***********************************" << endl;
	cout << "		*            PHAN MEM ATM         *" << endl;
	cout << "		***********************************" << endl << endl;
	cout << "			1. Tai khoan admin. " << endl; 
	cout << "			2. Tai khoan user. " << endl; 
	cout << "\n			>> Nhap lua chon: "; 
	int lc; 
	cin >> lc; 
	cin.ignore(); 

	ifstream file; 
	if (lc == 1) {
		system("cls"); 
		LinkedList<AdminAccount> aList;
		AdminAccount pa, aa;
		pa.DangNhapAdmin(file, aList, aa);
	}
	else if (lc == 2) {
		system("cls"); 
		LinkedList<UserAccount> uList;
		UserAccount pu, uu;
		pu.DangNhapUser(uList, uu);
	}
	else {
		system("cls"); 
		AdminAccount pa; 
		pa.NguoiDung(); 
	}

	return 0;
}

