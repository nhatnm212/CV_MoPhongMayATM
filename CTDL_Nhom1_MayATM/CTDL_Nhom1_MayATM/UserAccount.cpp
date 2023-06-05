#include "UserAccount.h"

GiaoDien gd1; 

string UserAccount::getuserID() {
	return userID;
}
string UserAccount::getuserPin() {
	return userPin;
}
void UserAccount::setuserID(string _userID) {
	userID = _userID;
}
void UserAccount::setuserPin(string  _userPin) {
	userPin = _userPin;
}
UserAccount::UserAccount(string _userID, string _userPin) {
	userID = _userID;
	userPin = _userPin;
}
UserAccount::UserAccount(const UserAccount& a) {
	userID = a.userID;
	userPin = a.userPin;
}
UserAccount::~UserAccount() {}
istream& operator >> (istream& in, UserAccount& a) {
	cout << "			ID: ";			getline(in, a.userID);
	cout << "			Pin: ";			getline(in, a.userPin);
	cout << endl;
	return in;
}
ostream& operator << (ostream& out, UserAccount a) {
	out << a.userID << "_";
	out << a.userPin << endl;
	return out;
}
void UserAccount::ReadFileMK(ifstream& file, UserAccount& a) {
	getline(file, a.userID, '_');
	getline(file, a.userPin);
}
void UserAccount::ReadFileDSMK(ifstream& file, LinkedList<UserAccount>& aList) {
	while (file.eof() == false) {
		UserAccount a;
		ReadFileMK(file, a);
		aList.addTail(a);
	}
}
void UserAccount::MENU() {
	cout << "\n\n";
	gd1.SET_COLOR(4); 
	cout << "                 ---------------------------------------------- " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 |                      MENU                  | " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 |       1. Xem thong tin tai khoan.          | " << endl;
	cout << "                 |       2. Rut tien.                         | " << endl;
	cout << "                 |       3. Chuyen tien.                      | " << endl;
	cout << "                 |       4. Xem noi dung giao dich.           | " << endl;
	cout << "                 |       5. Doi ma Pin.                       | " << endl;
	cout << "                 |       0. Dang xuat.                        | " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 ---------------------------------------------- " << endl;
}
int UserAccount::ChonMenu() {
	int n;
	cout << "\n                       >> Nhap lua chon: ";
	cin >> n;
	if (n > 0 || n < 6) {
		return n;
	}
	else {
		return ChonMenu();
	}
}
void UserAccount::XuLyMenu(ifstream& file, LinkedList<UserAccount> aList, UserAccount a, string& keyID) {
	TaiKhoan t;
	LinkedList<TaiKhoan> TheTuList;
	LichSuGD gd;
	LinkedList<LichSuGD> GiaoDichList;
	//Doi mat khau lan dau 
	file.open("TheTu.txt", ios_base::in);
	ReadFileDSMK(file, aList);
	string newPin; 
	UserAccount tmp; 
	for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(keyID) == 0 && pWalker->getData().getuserPin().compare("123456") == 0) {
			cout << "\n Hay doi mat khau moi: ";
			cin >> newPin; 
			for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
				if (pWalker->getData().getuserID().compare(keyID) == 0) {
					tmp = pWalker->getData();
					tmp.setuserPin(newPin);
					pWalker->setData(tmp);
				}
			}
			ofstream ofile;
			ofile.open("TheTu.txt", ios_base::trunc);
			ofile.close();
			ofile.open("TheTu.txt", ios::app);
			for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
				ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
			}
			ofile.close();
			file.close();

			cout << "\n Doi mat khau thanh cong!";
			system("pause");
			system("cls"); 
			NguoiDung(); 
		}
	}

	while (true) {
		system("cls");
		MENU();
		int lcUser = ChonMenu();
		if (lcUser == 0) {
			system("cls");
			cout << "\n Ban da chon Dang xuat khoi tai khoan user!" << endl;
			cin.ignore();
			NguoiDung();
		}
		if (lcUser == 1) {
			system("cls");
			cout << "\n Ban da chon chuc nang Xem thong tin tai khoan!" << endl;
			t.thongTinTK(TheTuList, keyID);
			cin.ignore();
			break;
		}
		if (lcUser == 2) {
			system("cls");
			cout << "\n Ban da chon chuc nang Rut tien!" << endl;
			t.rutTien(TheTuList, keyID);
			cin.ignore();
			break;
		}
		if (lcUser == 3) {
			system("cls");
			cout << "\n Ban da chon chuc nang Chuyen tien!" << endl;
			t.chuyenTien(TheTuList, keyID);
			cin.ignore();
			break;
		}
		if (lcUser == 4) {
			system("cls");
			cout << "\n Ban da chon chuc nang Xem noi dung giao dich!" << endl;
			gd.noiDungGD(GiaoDichList, keyID);
			cin.ignore();
			break;
		}
		if (lcUser == 5) {
			system("cls");
			cout << "\n Ban da chon chuc nang Doi ma pin!" << endl;
			a.doiMaPin(aList, keyID); 
			cin.ignore();
			break;
		}
	}
}
void UserAccount::XuLyUser(string& keyID) {
	LinkedList<UserAccount> aList;
	UserAccount aa;
	ifstream file;

	while (true) {
		cout << endl;
		cout << " ********************************** " << endl;
		cout << " *                                * " << endl;
		cout << " * Bam ENTER de tiep tuc.         * " << endl;
		cout << " * Bam ESC de thoat ve trang chu. * " << endl;
		cout << " *                                * " << endl;
		cout << " ********************************** " << endl;
		char a;
		a = getch();
		system("cls");
		if (a == 13)
			XuLyMenu(file, aList, aa, keyID);
		if (a == 27)
			break;
	}
}
void UserAccount::DangNhapUser(LinkedList<UserAccount> aList, UserAccount a) {
	int limit = 0;
	string aUser; 
	char aPin[31], ch; 
	cout << "\n\n";
	cout << "		***********************************" << endl;
	cout << "		*           DANG NHAP USER        *" << endl;
	cout << "		***********************************" << endl << endl;
	cout << "			ID: ";			cin >> aUser;
	cout << "			Pin: ";
	while (limit < 3) {
		int i = 0; 
		while (true) {
			ch = getch(); 
			if (i >= 31) {
				cout << '\a'; 
				continue; 
			}
			if (ch == 13) {
				break; 
			}
			else {
				if (ch == 8) {
					cout << "\b \b"; 
					aPin[--i] = '\0'; 
				}
				else {
					cout << "*"; 
					aPin[i++] = ch; 
					aPin[i] = '\0'; 
				}
			}
			if (i <= 0) {
				i = 0; 
			}
		}
		aList.clear();
		ifstream file;
		file.open("TheTu.txt", ios_base::in);
		ReadFileDSMK(file, aList);
		for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
			if (pWalker->getData().userID.compare(aUser) == 0 &&
				pWalker->getData().userPin.compare(aPin) == 0) {
				system("cls");
				/*if (pWalker->getData().userPin == "123456") {
					cout << "\n Nhap mat khau moi: ";
					string newpin;
					cin >> newpin;
					pWalker->getData().setuserPin(newpin);
					cout << "\n Cap nhat mat khau thanh cong!";
					ofstream ofile;
					ofile.open("TheTu.txt", ios::trunc);
					for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != NULL; pWalker = pWalker->getpNext())
						ofile << pWalker->getData();
					ofile.close();
					NguoiDung();
				}*/
				XuLyUser(aUser);
			}
		}
		/*for (int i = 0; i < aList.size(); i++) {
			if ((aList[i].getuserID()).compare(aUser) == 0 &&
				(aList[i].getuserPin()).compare(aPin) == 0) {
				system("cls");
				XuLyUser(aUser);
			}
		}*/
		limit++;
		file.close();
		cout << "\n			>> Nhap lai Pin: ";
	}
	if (limit > 2) {
		system("cls");
		cout << "\n Nhap sai Pin qua 3 lan hoac ten ID khong ton tai! " << endl;
		//ifstream file;
		//file.open("TheTu.txt", ios_base::in);
		//ReadFileDSMK(file, aList);
		//file.close();
		//ifstream file;
		//file.open("TheTu.txt", ios_base::in);
		//ReadFileDSMK(file, aList);
		//for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
		//	if (pWalker->getData().getuserID().compare(aUser) == 0) {
		//		tmp = pWalker->getData();
		//		tmp.setuserPin("Block");
		//		pWalker->setData(tmp);
		//		//ofstream ofile;
		//		//ofile.open("TheTu.txt", ios::app);
		//		//ofile << pWalker->getData().getuserID() << "_" << "Block" << endl;
		//		//ofile.close();
		//	}
		//}
		ifstream file;
		UserAccount tmp;
		////file.open("TheTu.txt", ios_base::in);
		////ReadFileDSMK(file, aList);
		//for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
		//	if (pWalker->getData().getuserID().compare(aUser) == 0) {
		//		tmp = pWalker->getData();
		//		tmp.setuserPin("Block");
		//		pWalker->setData(tmp);
		//	}
		//}
		//ofstream ofile;
		//ofile.open("TheTu.txt", ios::trunc || ios::app);
		//for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
		//	ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
		//}
		//ofile.close();
		//file.close();
		/*for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
			if (pWalker->getData().getuserID().compare(aUser) == 0) {
				aList.removeAfter(pWalker);
				ofstream ofile;
				ofile.open("TheTu.txt", ios::app);
				ofile << pWalker->getData().getuserID() << "_" << "Block" << endl;
				ofile.close();
			}
		}
		/*
		for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
			if (pWalker->getData().getuserID().compare(aUser) != 0) {
				ofstream ofile;
				ofile.open("TheTu.txt", ios::trunc);
				ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
				ofile.close();
			}
			//else {
			//	ofstream ofile;
			//	ofile.open("TheTu.txt", ios::app);
			//	ofile << pWalker->getData().getuserID() << "_" << "Block" << endl;
			//	ofile.close();
			//}
		}
		*/

		for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
			if (pWalker->getData().getuserID().compare(aUser) == 0) {
				tmp = pWalker->getData();
				tmp.setuserPin("Block");
				pWalker->setData(tmp);
			}
		}
		ofstream ofile;
		ofile.open("TheTu.txt", ios_base::trunc);
		ofile.close(); 
		ofile.open("TheTu.txt", ios::app);
		for (Node<UserAccount>* pWalker = aList.getHead(); pWalker != aList.getTail(); pWalker = pWalker->getpNext()) {
			ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
		}
		ofile.close();

		NguoiDung();
	}
}
void UserAccount::NguoiDung() {
	cout << "\n\n";
	gd1.SET_COLOR(6); 
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
		//pa.XuLyAdmin(); 
	}
	else if (lc == 2) {
		system("cls");
		LinkedList<UserAccount> uList;
		UserAccount pu, uu;
		pu.DangNhapUser(uList, uu);
	}
	else {
		system("cls");
		NguoiDung();
	}
}

void UserAccount::moKhoa(LinkedList<UserAccount> uList, UserAccount u, string& aUser) {
	ifstream file;
	UserAccount tmp;
	file.open("TheTu.txt", ios_base::in);
	ReadFileDSMK(file, uList);
	for (Node<UserAccount>* pWalker = uList.getHead(); pWalker != uList.getTail(); pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(aUser) == 0) {
			tmp = pWalker->getData();
			tmp.setuserPin("123456");
			pWalker->setData(tmp);
		}
	}
	ofstream ofile;
	ofile.open("TheTu.txt", ios_base::trunc);
	ofile.close();
	ofile.open("TheTu.txt", ios::app);
	for (Node<UserAccount>* pWalker = uList.getHead(); pWalker != uList.getTail(); pWalker = pWalker->getpNext()) {
		ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
	}
	ofile.close();
	file.close();
	cout << "\n Mo khoa thanh cong!" << endl; 
}


void UserAccount::doiMaPin(LinkedList<UserAccount> tList, string& keyID) {
	ifstream file;
	file.open("TheTu.txt", ios_base::in);
	UserAccount tk, tmp;
	tk.ReadFileDSMK(file, tList);
	for (Node<UserAccount>* pWalker = tList.getHead(); pWalker != tList.getTail(); pWalker = pWalker->getpNext()) {
		if (stricmp(pWalker->getData().getuserID().c_str(), keyID.c_str()) == 0) {
			cout << "\n >> Nhap ma Pin hien tai: ";
			string maPinHT;
			cin >> maPinHT;
			if (maPinHT.compare(pWalker->getData().getuserPin()) == 0) {
				cout << "\n >> Nhap ma Pin moi: ";
				string maPinNew1;
				cin >> maPinNew1;
				cout << "\n >> Nhap lai ma Pin moi: ";
				string maPinNew2;
				cin >> maPinNew2;
				if (maPinNew2 == maPinNew1) {
					tmp = pWalker->getData();
					tmp.setuserPin(maPinNew1);
					pWalker->setData(tmp);
					ofstream ofile;
					ofile.open("TheTu.txt", ios_base::trunc);
					ofile.close();
					ofile.open("TheTu.txt", ios::app);
					for (Node<UserAccount>* pWalker = tList.getHead(); pWalker != tList.getTail(); pWalker = pWalker->getpNext()) {
						ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getuserPin() << endl;
					}
					ofile.close();
				}
				else {
					cout << "\n Nhap sai ma Pin moi!" << endl;
					break;
				}
			}
			else {
				cout << "\n Nhap sai ma Pin hien tai!" << endl;
				break;
			}
		}
	}
	file.close();
}

