#include "AdminAccount.h"
GiaoDien gd; 
string AdminAccount::getadminUser() {
	return adminUser; 
}
string AdminAccount::getadminPin() {
	return adminPin; 
}
void AdminAccount::setadminUser(string _adminUser) {
	adminUser = _adminUser; 
}
void AdminAccount::setadminPin(string  _adminPin) {
	adminPin = _adminPin; 
}
AdminAccount::AdminAccount(string _adminUser, string _adminPin) {
	adminUser = _adminUser; 
	adminPin = _adminPin; 
}
AdminAccount::AdminAccount(const AdminAccount& a) {
	adminUser = a.adminUser;
	adminPin = a.adminPin; 
}
AdminAccount::~AdminAccount() {}
istream& operator >> (istream& in, AdminAccount& a) {
	cout << "			User: ";		getline(in, a.adminUser); 
	cout << "			Pin: ";			getline(in, a.adminPin); 
	cout << endl; 
	return in; 
}
ostream& operator << (ostream& out, AdminAccount a) {
	out << a.adminUser << "_"; 
	out << a.adminPin << endl; 
	return out; 
}
void AdminAccount::ReadFileMK(ifstream& file, AdminAccount& a) {
	getline(file, a.adminUser, '_');
	getline(file, a.adminPin); 
}
void AdminAccount::ReadFileDSMK(ifstream& file, LinkedList<AdminAccount>& aList) {
	while (file.eof() == false) {
		AdminAccount a;
		ReadFileMK(file, a);
		aList.addTail(a);
	}
}
void AdminAccount::RegisterAdmin(LinkedList<AdminAccount> aList) {
	cout << "\n\n";
	cout << "		***********************************" << endl;
	cout << "		*            DANG KY ADMIN        *" << endl;
	cout << "		***********************************" << endl << endl; 
	AdminAccount a;
	cin >> a;
	aList.addTail(a);
	ofstream ofile;
	ofile.open("Admin.txt", ios::app);
	ofile << a;
	ofile.close();
}
void AdminAccount::MENU() {
	cout << "\n\n";
	gd.SET_COLOR(3); 
	cout << "                 ---------------------------------------------- " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 |                      MENU                  | " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 |       1. Xem danh sach tai khoan.          | " << endl;
	cout << "                 |       2. Them tai khoan.                   | " << endl;
	cout << "                 |       3. Xoa tai khoan.                    | " << endl;
	cout << "                 |       4. Mo khoa tai khoan.                | " << endl;
	cout << "                 |       5. Chinh sua so du tai khoan         | " << endl;
	cout << "                 |       0. Dang xuat.                        | " << endl;
	cout << "                 |                                            | " << endl;
	cout << "                 ---------------------------------------------- " << endl;
}
int AdminAccount::ChonMenu() {
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
void AdminAccount::XuLyMenu(ifstream& file, LinkedList<AdminAccount> aList, AdminAccount a) {
	TheTu t;
	vector<TheTu> TheTuList;
	LinkedList<UserAccount> uList; 
	UserAccount u; 
	LinkedList<TaiKhoan> DSTK; 
	TaiKhoan tk; 
	while (true) {
		system("cls");
		MENU(); 
		int lcAdmin = ChonMenu(); 
		if (lcAdmin == 0) {
			system("cls");
			cout << "\n Ban da chon Dang xuat khoi tai khoan admin!" << endl; 
			cin.ignore(); 
			NguoiDung(); 
		}
		if (lcAdmin == 1) {
			system("cls");
			cout << "\n Ban da chon chuc nang \"Xem danh sach tai khoan\"!" << endl;
			file.open("TheTu.txt", ios_base::in); 
			t.ReadFileNTheTu(file, TheTuList); 
			t.PrintListTheTu(TheTuList); 
			file.close(); 
			cin.ignore(); 
			break; 
		}
		if (lcAdmin == 2) {
			system("cls");
			cin.ignore(); 
			cout << "\n Ban da chon chuc nang \"Them 1 tai khoan\"!" << endl;
			t.AddTheTu(TheTuList, t); 
			break;
		}
		if (lcAdmin == 3) {
			system("cls");
			cin.ignore(); 
			cout << "\n Ban da chon chuc nang \"Xoa tai khoan\"!" << endl;
			cout << "\n Nhap ID can xoa: "; 
			string id; 
			cin >> id; 
			t.RemoveTheTu(TheTuList, t, id); 
			//t.RemoveID(TheTuList, t, id); 
			break;
		}
		if (lcAdmin == 4) {
			system("cls");
			cout << "\n Ban da chon chuc nang \"Mo khoa tai khoan\"!" << endl;
			cout << "\n Nhap ID can mo khoa: ";
			string id;
			cin >> id;
			u.moKhoa(uList, u, id); 
			cin.ignore();
			break;
		}
		if (lcAdmin == 5) {
			system("cls"); 
			cout << "\n Ban da chon chuc nang \"Chinh sua so du tai khoan\"!" << endl; 
			tk.chinhSuaSoDu(DSTK); 
			break; 
		}
	}
}
void AdminAccount::XuLyAdmin() {
	LinkedList<AdminAccount> aList;
	AdminAccount aa;
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
			XuLyMenu(file, aList, aa); 
		if (a == 27)
			break; 
	}
}
void AdminAccount::DangNhapAdmin(ifstream& file, LinkedList<AdminAccount> aList, AdminAccount a) {
	string aUser;
	char aPin[31], ch; 
	// Mat khau gom 31 ki tu 
	cout << "\n\n";
	gd.SET_COLOR(6); 
	cout << "		***********************************" << endl;
	cout << "		*           DANG NHAP ADMIN       *" << endl;
	cout << "		***********************************" << endl << endl; 
	cout << "			User: ";		getline(cin, aUser);
	cout << "			Pin: ";			
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
	file.open("Admin.txt", ios_base::in);
	ReadFileDSMK(file, aList);
	for (Node<AdminAccount>* pWalker = aList.getHead(); pWalker != NULL; pWalker = pWalker->getpNext()) {
		if (pWalker->getData().adminUser.compare(aUser) == 0 &&
			pWalker->getData().adminPin.compare(aPin) == 0) {
			system("cls");
			XuLyAdmin();
		}
	}
	system("cls");
	cout << "\n User hoac Pin sai, vui long chon lai!" << endl;
	NguoiDung();
	file.close(); 
}
void AdminAccount::NguoiDung() {
	cout << "\n\n";
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
		NguoiDung();
	}
}

