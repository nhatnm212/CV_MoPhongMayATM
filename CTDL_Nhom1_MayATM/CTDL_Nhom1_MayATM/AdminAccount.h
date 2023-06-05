#ifndef ADMINACCOUNT_H
#define ADMINACCOUNT_H
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
#include "LinkedList.cpp"
#include "Node.h"
#include "Node.cpp" 
#include "TheTu.h" 
#include "UserAccount.h" 
#include <Windows.h>
#include "GiaoDien.h"
using namespace std; 

class AdminAccount {
	string adminUser;
	string adminPin;
public:
	string getadminUser();
	string getadminPin();
	void setadminUser(string _adminUser);
	void setadminPin(string _adminPin);
	AdminAccount(string _adminUser = "Admin", string _adminPin = "123456");
	AdminAccount(const AdminAccount& a);
	~AdminAccount();
	friend istream& operator >> (istream& in, AdminAccount& a);
	friend ostream& operator << (ostream& out, AdminAccount a);
	void ReadFileMK(ifstream& file, AdminAccount& a);
	void ReadFileDSMK(ifstream& file, LinkedList<AdminAccount>& aList);
	void RegisterAdmin(LinkedList<AdminAccount> aList);
	void DangNhapAdmin(ifstream& file, LinkedList<AdminAccount> aList, AdminAccount a);
	void MENU(); 
	int ChonMenu(); 
	void XuLyMenu(ifstream& file, LinkedList<AdminAccount> aList, AdminAccount a);
	void XuLyAdmin(); 
	void NguoiDung(); 
};

#endif // ADMINACCOUNT.H
