#include "TaiKhoan.h" 

//string TaiKhoan::getTKID() {
//	return TKID; 
//}
//string TaiKhoan::getTKTen() {
//	return TKTen; 
//}
//int TaiKhoan::getTKSoDu() {
//	return TKSoDu; 
//}
//string TaiKhoan::getTKLoaiTien() {
//	return TKLoaiTien; 
//}
//void TaiKhoan::setTKID(string _TKID) {
//	TKID = _TKID; 
//}
//void TaiKhoan::setTKTen(string _TKTen) {
//	TKTen = _TKTen; 
//}
//void TaiKhoan::setTKSoDu(int _TKSoDu) {
//	TKSoDu = _TKSoDu; 
//}
//void TaiKhoan::setTKLoaiTien(string _TKLoaiTien) {
//	TKLoaiTien = _TKLoaiTien; 
//}
TaiKhoan::TaiKhoan(string _TKID, string _TKTen, int _TKSoDu, string _TKLoaiTien, string _loaiGD, string _ngayGD, int _soTienGD) : TheTu(_TKID, "", _TKTen, _TKSoDu, _TKLoaiTien, _loaiGD, _ngayGD, _soTienGD) {
	/*TKID = _TKID; 
	TKTen = _TKTen; 
	TKSoDu = _TKSoDu; 
	TKLoaiTien = _TKLoaiTien; */
}
TaiKhoan::TaiKhoan(const TaiKhoan& tk) : TheTu(tk) {
	/*TKID = tk.TKID;
	TKTen = tk.TKTen;
	TKSoDu = tk.TKSoDu;
	TKLoaiTien = tk.TKLoaiTien;*/
}
TaiKhoan::~TaiKhoan() {}

istream& operator >> (istream& in, TaiKhoan& tk) {
	string TKID;
	string TKTen;
	int TKSoDu;
	string TKLoaiTien;
	cout << "\n Nhap ID: ";			getline(in, TKID); 
	cout << " Nhap ten TK: ";		getline(in, TKTen); 
	cout << " Nhap so du: ";		in >> TKSoDu; 
	in.ignore(); 
	cout << " Nhap loai tien: ";	getline(in, TKLoaiTien); 
	tk = TaiKhoan(TKID, TKTen, TKSoDu, TKLoaiTien, "", "", 0); 
	return in; 
}
ostream& operator << (ostream& out, TaiKhoan tk) {
	out << "\n ------------------------------------ \n\n"; 
	out << "           THONG TIN TAI KHOAN        \n\n"; 
	out << "   - ID        : " << tk.getuserID() << endl; 
	out << "   - Ten TK    : " << tk.getTKTen() << endl; 
	out << "   - So du     : " << tk.getTKSoDu() << endl; 
	out << "   - Loai tien : " << tk.getTKLoaiTien() << endl; 
	out << "\n ------------------------------------ \n\n\n";
	return out;
}
void TaiKhoan::ReadFileTK(ifstream& file, TaiKhoan& a) {
	string TKID;
	string TKTen;
	int TKSoDu;
	string TKLoaiTien;
	getline(file, TKID, '_');
	getline(file, TKTen, '_');
	getline(file, TKLoaiTien, '_'); 
	file >> TKSoDu; 
	string tmp; 
	getline(file, tmp); 
	a = TaiKhoan(TKID, TKTen, TKSoDu, TKLoaiTien, "", "", 0);
}
void TaiKhoan::ReadFileDSTK(ifstream& file, LinkedList<TaiKhoan>& aList) {
	while (file.eof() == false) {
		TaiKhoan a;
		ReadFileTK(file, a);
		aList.addTail(a);
	}
}
//void TaiKhoan::ReadFileGD(ifstream& file, TaiKhoan& a) {
//	string TKID;
//	string loaiGD; 
//	int soTienGD; 
//	string ngayGD; 
//	getline(file, TKID, '_');
//	getline(file, loaiGD, '_');
//	getline(file, ngayGD, '_');
//	file >> soTienGD;
//	a = TaiKhoan(TKID, "", 0, "", loaiGD, ngayGD, soTienGD); 
//}
//void TaiKhoan::ReadFileDSGD(ifstream& file, vector<TaiKhoan>& aList) {
//	while (file.eof() == false) {
//		TaiKhoan a;
//		ReadFileGD(file, a);
//		aList.push_back(a);
//	}
//}
void TaiKhoan::thongTinTK(LinkedList<TaiKhoan> DSTK, string& keyID) {
	TaiKhoan tk; 
	ifstream file;
	file.open("[ID].txt", ios_base::in);
	ReadFileDSTK(file, DSTK); 
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != DSTK.getTail(); pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(keyID) == 0) {
			cout << pWalker->getData(); 
		}
	}
	file.close(); 
}
void TaiKhoan::rutTien(LinkedList<TaiKhoan> DSTK, string& keyID) {
	int soTienCanRut, tmp = 0;
	ifstream file;
	file.open("[ID].txt", ios_base::in);
	ReadFileDSTK(file, DSTK);
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != NULL; pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(keyID) == 0) {
			if (pWalker->getData().getTKSoDu() >= 50000) {
				cout << "\n SO DU HIEN TAI: " << pWalker->getData().getTKSoDu() << " VND" << endl;
				cout << "\n Luu y: So tien rut phai lon hon 50,000 VND va phai la boi so cua 50,000 VND! " << endl; 
				cout << "\n >> Nhap so tien can rut: ";
				cin >> soTienCanRut;
				if ((soTienCanRut >= 50000) && (soTienCanRut <= pWalker->getData().getTKSoDu() - 50000) && (soTienCanRut % 50000 == 0)) {

					tmp = pWalker->getData().getTKSoDu() - soTienCanRut;
					TaiKhoan tmpx;
					tmpx = pWalker->getData();
					tmpx.setTKSoDu(tmp);
					pWalker->setData(tmpx);
					//pWalker->getData().setTKSoDu(tmp);
					//pWalker->setData(pWalker->getData());
					//cin.ignore();

					ofstream ofile;
					//ofile.open("[ID].txt", ios::trunc);
					//for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != NULL; pWalker = pWalker->getpNext())
					//ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getTKTen() << "_" << pWalker->getData().getTKLoaiTien() << "_" << tmp << endl; 
					//ofile.close(); 

					ofile.open("[LichSuID].txt", ios::app);
					time_t curr_time = time(NULL);
					char* tm = ctime(&curr_time);
					//pWalker->getData().setloaiGD("RutTien");
					//pWalker->getData().setngayGD(tm);
					//pWalker->getData().setsoTienGD(soTienCanRut);
					//ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getloaiGD() << "_" << pWalker->getData().getngayGD() << "_" << pWalker->getData().getsoTienGD() << endl;
					ofile << pWalker->getData().getuserID() << "_" << "RutTien" << "_" << tm << "_" << soTienCanRut << endl;
					ofile.close();
					cout << "\n Rut tien thanh cong!" << endl;
				}
				else {
					cout << "\n Giao dich khong thanh cong!" << endl;
				}
			}
			else {
				cout << "\n TAI KHOAN CUA QUY KHACH DUOI 50,000 VND NEN KHONG THE THUC HIEN CHUC NANG!" << endl;
			}
		}
	}
	file.close();
	ofstream ofile;
	ofile.open("[ID].txt", ios::trunc);
	ofile.close();
	ofile.open("[ID].txt", ios::app);
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != DSTK.getTail(); pWalker = pWalker->getpNext()) {
		ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getTKTen() << "_" << pWalker->getData().getTKLoaiTien() << "_" << pWalker->getData().getTKSoDu() << endl;
	}
	ofile.close();
}
void TaiKhoan::chuyenTien(LinkedList<TaiKhoan> DSTK, string& keyID) {
	char* tm;
	int soTienCanChuyen, tmp = 0, tmp1 = 0, tkim = 1;
	string soTK;
	ifstream file;
	file.open("[ID].txt", ios_base::in);
	ReadFileDSTK(file, DSTK);
	file.close();
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != DSTK.getTail(); pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(keyID) == 0) {
			if (pWalker->getData().getTKSoDu() >= 50000) {
				cout << "\n SO DU HIEN TAI: " << pWalker->getData().getTKSoDu() << " VND" << endl;
				cout << "\n Luu y: So tien chuyen phai lon hon 50,000 VND va phai la boi so cua 50,000 VND! " << endl;
				cout << "\n >> Nhap so tai khoan can chuyen den: ";
				cin >> soTK;
				for (Node<TaiKhoan>* pTimKiem = DSTK.getHead(); pTimKiem != DSTK.getTail(); pTimKiem = pTimKiem->getpNext()) {
					if (pTimKiem->getData().getuserID().compare(soTK) == 0) {
						cout << "\n >> Nhap so tien can chuyen: ";
						cin >> soTienCanChuyen;
						if ((soTienCanChuyen >= 50000) && (soTienCanChuyen <= pWalker->getData().getTKSoDu() - 50000) && (soTienCanChuyen % 50000 == 0)) {

							tmp = pWalker->getData().getTKSoDu() - soTienCanChuyen;
							tmp1 = pTimKiem->getData().getTKSoDu() + soTienCanChuyen;

							//cin.ignore();
							TaiKhoan tmm, tmmm;
							tmm = pTimKiem->getData();
							tmm.setTKSoDu(tmp1);
							pTimKiem->setData(tmm);
							tmmm = pWalker->getData();
							tmmm.setTKSoDu(tmp);
							pWalker->setData(tmmm);
							ofstream ofile;
							//ofile.open("[ID].txt", ios::trunc);
							//ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getTKTen() << "_" << pWalker->getData().getTKLoaiTien() << "_" << tmp << endl;
							//ofile << pTimKiem->getData().getuserID() << "_" << pTimKiem->getData().getTKTen() << "_" << pTimKiem->getData().getTKLoaiTien() << "_" << tmp << endl;
							//ofile.close();

							ofile.open("[LichSuID].txt", ios::app);
							time_t curr_time = time(NULL);
							tm = ctime(&curr_time);
							ofile << pWalker->getData().getuserID() << "_" << "ChuyenTien" << "_" << tm << "_" << soTienCanChuyen << endl;
							ofile << pTimKiem->getData().getuserID() << "_" << "NhanTien" << "_" << tm << "_" << soTienCanChuyen << endl;
							ofile.close();
							tkim = 0;
							cout << "\n Giao dich thanh cong! " << endl;

						}
						else {
							cout << "\n Giao dich khong thanh cong!" << endl;
						}
						if (tkim == 1) {
							cout << "\n SO TAI KHOAN CAN CHUYEN DEN KHONG TON TAI!" << endl;
						}
					}

				}
			}
			else {
				cout << "\n TAI KHOAN CUA QUY KHACH DUOI 50,000 VND NEN KHONG THE THUC HIEN CHUC NANG!" << endl;
			}
		}

	}
	ofstream ofile;
	ofile.open("[ID].txt", ios::trunc);
	ofile.close();
	ofile.open("[ID].txt", ios::app);
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != DSTK.getTail(); pWalker = pWalker->getpNext()) {
		ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getTKTen() << "_" << pWalker->getData().getTKLoaiTien() << "_" << pWalker->getData().getTKSoDu() << endl;
	}
	ofile.close();
}
//void TaiKhoan::noiDungGD(vector<TaiKhoan> DSTK, string& keyID) {
//	ifstream file;
//	file.open("[LichSuID].txt", ios_base::in);
//	ReadFileDSGD(file, DSTK);
//	for (int i = 0; i < DSTK.size(); i++) {
//		if (keyID == DSTK[i].getuserID()) {
//			while (DSTK[i].getloaiGD() == "RutTien") {
//				cout << " Ngay giao dich: " << DSTK[i].getngayGD() << endl;
//				cout << " So tien giao dich: -" << DSTK[i].getsoTienGD() << endl << endl;
//				
//			}
//			/*if (DSTK[i].getloaiGD() == "RutTien") {
//				cout << "\n --------------------- RUT TIEN ---------------------- \n\n";
//				cout << " Ngay giao dich: " << DSTK[i].getngayGD() << endl; 
//				cout << " So tien giao dich: -" << DSTK[i].getsoTienGD() << endl << endl; 
//				cout << "\n ----------------------------------------------------- \n\n";
//			}
//			if (DSTK[i].getloaiGD() == "ChuyenTien") {
//				cout << "\n ------------------- CHUYEN TIEN --------------------- \n\n";
//				cout << " Ngay giao dich: " << DSTK[i].getngayGD() << endl;
//				cout << " So tien giao dich: -" << DSTK[i].getsoTienGD() << endl << endl;
//				cout << "\n ----------------------------------------------------- \n\n";
//			}*/
//		}
//	}
//	file.close();
//}

void TaiKhoan::chinhSuaSoDu(LinkedList<TaiKhoan> DSTK) {
	string keyID; 
	cout << "\n >> Nhap so tai khoan: "; 
	cin >> keyID; 
	TaiKhoan tmp; 
	ifstream file;
	file.open("[ID].txt", ios_base::in);
	ReadFileDSTK(file, DSTK);
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != NULL; pWalker = pWalker->getpNext()) {
		if (pWalker->getData().getuserID().compare(keyID) == 0) {
			cout << "\n So du hien tai: " << pWalker->getData().getTKSoDu() << " dong" << endl;
			int soDuNew; 
			cout << "\n >> Nhap so du muon chinh: "; 
			cin >> soDuNew; 
			tmp = pWalker->getData();
			tmp.setTKSoDu(soDuNew);
			pWalker->setData(tmp);
		}
	}
	ofstream ofile;
	ofile.open("[ID].txt", ios::trunc);
	ofile.close();
	ofile.open("[ID].txt", ios::app);
	for (Node<TaiKhoan>* pWalker = DSTK.getHead(); pWalker != DSTK.getTail(); pWalker = pWalker->getpNext()) {
		ofile << pWalker->getData().getuserID() << "_" << pWalker->getData().getTKTen() << "_" << pWalker->getData().getTKLoaiTien() << "_" << pWalker->getData().getTKSoDu() << endl;
	}
	ofile.close();
	file.close();
}

