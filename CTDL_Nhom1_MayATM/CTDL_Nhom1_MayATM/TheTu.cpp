#include "TheTu.h"

string TheTu::getuserID() {
    return userID;
}
string TheTu::getuserPin() {
    return userPin;
}
void TheTu::setuserID(string _userID) {
    userID = _userID;
}
void TheTu::setuserPin(string _userPin) {
    userPin = _userPin;
}
string TheTu::getTKTen() {
    return TKTen;
}
int TheTu::getTKSoDu() {
    return TKSoDu;
}
string TheTu::getTKLoaiTien() {
    return TKLoaiTien;
}
void TheTu::setTKTen(string _TKTen) {
    TKTen = _TKTen;
}
void TheTu::setTKSoDu(int _TKSoDu) {
    TKSoDu = _TKSoDu;
}
void TheTu::setTKLoaiTien(string _TKLoaiTien) {
    TKLoaiTien = _TKLoaiTien;
}
string TheTu::getloaiGD() {
    return loaiGD;
}
void TheTu::setloaiGD(string _loaiGD) {
    loaiGD = _loaiGD;
}
string TheTu::getngayGD() {
    return ngayGD;
}
void TheTu::setngayGD(string _ngayGD) {
    ngayGD = _ngayGD;
}
int TheTu::getsoTienGD() {
    return soTienGD;
}
void TheTu::setsoTienGD(int _soTienGD) {
    soTienGD = _soTienGD;
}
TheTu::TheTu(string _userID, string _userPin, string _TKTen, double _TKSoDu, string _TKLoaiTien, string _loaiGD, string _ngayGD, int _soTienGD) {
    userID = _userID;
    userPin = _userPin;
    TKTen = _TKTen;
    TKSoDu = _TKSoDu;
    TKLoaiTien = _TKLoaiTien;
    loaiGD = _loaiGD;
    ngayGD = _ngayGD;
    soTienGD = _soTienGD;
}
TheTu::TheTu(const TheTu& t) {
    userID = t.userID;
    userPin = t.userPin;
    TKTen = t.TKTen;
    TKSoDu = t.TKSoDu;
    TKLoaiTien = t.TKLoaiTien;
    loaiGD = t.loaiGD;
    ngayGD = t.ngayGD;
    soTienGD = t.soTienGD;
}
TheTu::~TheTu() {}
istream& operator >> (istream& in, TheTu& t) {
    cout << "\n\n";
    cout << "		***********************************" << endl;
    cout << "		*           THEM TAI KHOAN        *" << endl;
    cout << "		***********************************" << endl << endl;
    cout << "			ID: ";		    getline(in, t.userID);
    cout << "			Ten TK: ";		getline(in, t.TKTen);
    cout << "			Loai tien: ";   getline(in, t.TKLoaiTien);
    t.userPin = "123456";
    t.TKSoDu = 0;
    return in;
}
ostream& operator << (ostream& out, TheTu t) {
    out << t.getuserID() << "_" << t.getTKTen() << "_" << t.getTKLoaiTien() << "_" << t.getTKSoDu(); 
    return out;
}
ostream& operator < (ostream& out, TheTu t) {
    out << t.userID << "_";
    out << t.userPin << endl;
    return out;
}
void TheTu::ReadFile1TheTu(ifstream& file, TheTu& t) {
    getline(file, t.userID, '_');
    getline(file, t.userPin);
}
void TheTu::ReadFile1ID(ifstream& file, TheTu& t) {
    getline(file, t.userID, '_');
    getline(file, t.TKTen, '_');
    getline(file, t.TKLoaiTien, '_');
    file >> t.TKSoDu;
}
void TheTu::ReadFileNTheTu(ifstream& file, vector<TheTu>& tList) {
    while (file.eof() == false) {
        TheTu t;
        ReadFile1TheTu(file, t);
        tList.push_back(t);
    }
}
void TheTu::ReadFileNID(ifstream& file, vector<TheTu>& tList) {
    while (file.eof() == false) {
        TheTu t;
        ReadFile1ID(file, t);
        tList.push_back(t);
    }
}
void TheTu::Print1TheTu(TheTu t) {
    cout << setw(20) << left << t.getuserID();
    cout << setw(15) << left << t.getuserPin();
    cout << endl;
}
void TheTu::PrintListTheTu(vector<TheTu> tList) {
    cout << "____________________________________________" << endl << endl;
    cout << "                DANH SACH USER              " << endl << endl;
    cout << setw(5) << left << " STT";
    cout << setw(20) << left << "ID";
    cout << setw(15) << left << "PIN";
    cout << endl;
    cout << "____________________________________________" << endl << endl;
    for (int i = 0; i < tList.size() - 1; i++) {
        cout << " " << setw(5) << left << i + 1;
        Print1TheTu(tList[i]);
    }
    cout << "____________________________________________" << endl;
}
void TheTu::AddTheTu(vector<TheTu> tList, TheTu t) {
    ifstream file;
    file.open("TheTu.txt", ios_base::in);
    ReadFileNTheTu(file, tList);
    cin >> t;
    int found = 0;
    for (int i = 0; i < tList.size(); i++) {
        if (stricmp(tList[i].userID.c_str(), t.getuserID().c_str()) == 0) {
            system("cls");
            cout << "\n Tai khoan co ID " << t.getuserID() << " da ton tai tren he thong!" << endl;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << "\n Da them tai khoan co ID " << t.getuserID() << " vao he thong!" << endl;
        tList.push_back(t);
        ofstream ofile;
        ofile.open("TheTu.txt", ios::app);
        ofile < t;
        ofile.close();
        ofile.open("[ID].txt", ios::app);
        ofile << t << endl; 
        ofile.close();
    }
    file.close();
}
//void TheTu::RemoveTheTu(vector<TheTu> tList, TheTu t, string id) {
//    ifstream file;
//    file.open("TheTu.txt", ios_base::in);
//    ReadFileNTheTu(file, tList);
//    int found = 0;
//    for (int i = 0; i < tList.size(); i++) {
//        if (stricmp(tList[i].userID.c_str(), id.c_str()) == 0) {
//            int tmp = i;
//            cout << "\n Xoa tai khoan co ID " << tList[i].userID << " thanh cong!" << endl;
//            tList.erase(tList.begin() + i);
//            found = 1;
//            ofstream ofile;
//            ofile.open("TheTu.txt", ios::trunc);
//            for (int i = 0; i < tList.size() - 1; i++)
//                ofile < tList[i];
//            ofile.close();
//        }
//    }
//    if (found == 0) {
//        cout << "\n ID khong ton tai trong he thong!!" << endl;
//    }
//    file.close();
//}
//
//void TheTu::RemoveID(vector<TheTu> tList, TheTu t, string id) {
//    ifstream file;
//    file.open("[ID].txt", ios_base::in);
//    ReadFileNTheTu(file, tList);
//    int found = 0;
//    for (int i = 0; i < tList.size(); i++) {
//        if (stricmp(tList[i].userID.c_str(), id.c_str()) == 0) {
//            int tmp = i;
//            cout << "\n Xoa tai khoan co ID " << tList[i].userID << " thanh cong!" << endl;
//            found = 1;
//            ofstream ofile;
//            ofile.open("[ID].txt", ios::trunc);
//            for (int i = 0; i < tList.size() - 1; i++)
//                ofile << tList[i];
//            ofile.close();
//        }
//    }
//    if (found == 0) {
//        cout << "\n ID khong ton tai trong he thong!!" << endl;
//    }
//    file.close();
//}

void TheTu::RemoveTheTu(vector<TheTu> tList, TheTu t, string id) {
    vector<TheTu> tL;
    ifstream file;
    file.open("[ID].txt");
    ReadFileNID(file, tL);
    file.close();
    file.open("TheTu.txt", ios_base::in);
    ReadFileNTheTu(file, tList);
    int found = 0, tmp = 0;
    for (int i = 0; i < tList.size(); i++) {
        if (stricmp(tList[i].userID.c_str(), id.c_str()) == 0) {
            cout << "\n Xoa tai khoan co ID " << tList[i].userID << " thanh cong!" << endl;
            //
            tList.erase(tList.begin() + i);
            found = 1;
            tmp = i;
            cout << endl;
            ofstream ofile;
            ofile.open("TheTu.txt", ios::trunc);
            for (int i = 0; i < tList.size() - 1; i++)
                ofile < tList[i];
            ofile.close();
            ofile.open("[ID].txt", ios::trunc);
            for (int i = 0; i < tL.size() - 1; i++) {
                if (tmp != i)
                    ofile << tL[i];
            }
            ofile << endl; 
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n ID khong ton tai trong he thong!!" << endl;
    }
    file.close();
}

