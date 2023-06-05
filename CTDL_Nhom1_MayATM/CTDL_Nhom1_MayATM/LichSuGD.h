#ifndef LICHSUGD_H
#define LICHSUGD_H
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
#include <cstdlib>
#include "LinkedList.h" 
#include "TheTu.h" 
#include "UserAccount.h" 
#include "TaiKhoan.h"
using namespace std;

class LichSuGD : public TheTu {

public:
	LichSuGD(string _TKID = "NoID", string _loaiGD = "", string _ngayGD = "", int _soTienGD = 0); 
	LichSuGD(const LichSuGD& tk);
	~LichSuGD();
	void ReadFileGD(ifstream& file, LichSuGD& a);
	void ReadFileDSGD(ifstream& file, LinkedList<LichSuGD>& aList);
	int findNodeInLL(LinkedList<LichSuGD> DSGD, LichSuGD datas); 
	Node<LichSuGD>* getNode(LinkedList<LichSuGD> DSGD, int index);
	void noiDungGD(LinkedList<LichSuGD> DSTK, string& keyID);
};

#endif // LICHSUGD_H
