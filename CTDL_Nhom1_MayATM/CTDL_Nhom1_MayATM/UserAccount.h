#ifndef USERACCOUNT_H
#define USERACCOUNT_H
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
#include "TheTu.h" 
#include "AdminAccount.h" 
#include "TaiKhoan.h" 
#include "LichSuGD.h"
#include "GiaoDien.h"
using namespace std;

class UserAccount {
	string userID;
	string userPin;
public:
	string getuserID();
	string getuserPin();
	void setuserID(string _userID);
	void setuserPin(string _userPin);
	UserAccount(string _userID = "NoID", string _userPin = "123456");
	UserAccount(const UserAccount& a);
	~UserAccount();
	friend istream& operator >> (istream& in, UserAccount& a);
	friend ostream& operator << (ostream& out, UserAccount a);
	void ReadFileMK(ifstream& file, UserAccount& a);
	void ReadFileDSMK(ifstream& file, LinkedList<UserAccount>& aList);
	void RegisterUser(vector<UserAccount> aList);
	void DangNhapUser(LinkedList<UserAccount> aList, UserAccount a);
	void MENU();
	int ChonMenu();
	void XuLyMenu(ifstream& file, LinkedList<UserAccount> aList, UserAccount a, string& keyID);
	void XuLyUser(string& keyID);
	void NguoiDung(); 
	void moKhoa(LinkedList<UserAccount> uList, UserAccount u, string& aUser);
	void doiMaPin(LinkedList<UserAccount> tList, string& keyID);
};

#endif // USERACCOUNT.H
