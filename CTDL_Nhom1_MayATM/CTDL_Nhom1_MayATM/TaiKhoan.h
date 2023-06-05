#ifndef TAIKHOAN_H
#define TAIKHOAN_H
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
#include <chrono>
#include "LinkedList.h" 
#include "TheTu.h" 
#include "UserAccount.h" 
using namespace std;

class TaiKhoan : public TheTu {
public:
	TaiKhoan(string _TKID = "NoID", string _TKTen = "NoName", int _TKSoDu = 0, string _TKLoaiTien = "VND", string _loaiGD = "", string _ngayGD = "", int _soTienGD = 0);
	TaiKhoan(const TaiKhoan& tk); 
	~TaiKhoan(); 
	friend istream& operator >> (istream& in, TaiKhoan& tk);
	friend ostream& operator << (ostream& out, TaiKhoan tk);
	void ReadFileTK(ifstream& file, TaiKhoan& a);
	void ReadFileDSTK(ifstream& file, LinkedList<TaiKhoan>& aList);
	bool operator != (TaiKhoan& a);
	void thongTinTK(LinkedList<TaiKhoan> DSTK, string& keyID);
	void rutTien(LinkedList<TaiKhoan> DSTK, string& keyID);
	void chuyenTien(LinkedList<TaiKhoan> tk, string& keyID);
	void chinhSuaSoDu(LinkedList<TaiKhoan> DSTK); 
};

#endif // TAIKHOAN_H

