#ifndef THETU_H
#define THETU_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "LinkedList.h" 
#include "Node.h"
#pragma warning(disable:4996) 
using namespace std;

class TheTu {
private:
    string userID, userPin; 
    string TKTen;
    int TKSoDu;
    string TKLoaiTien;
    string loaiGD; 
    string ngayGD; 
    int soTienGD; 
public:
    string getuserID(); 
    string getuserPin(); 
    void setuserID(string _userID); 
    void setuserPin(string _userPin); 
    string getTKTen();
    int getTKSoDu();
    string getTKLoaiTien();
    void setTKTen(string _TKTen);
    void setTKSoDu(int _TKSoDu);
    void setTKLoaiTien(string _TKLoaiTien);
    string getloaiGD(); 
    void setloaiGD(string _loaiGD); 
    string getngayGD();
    void setngayGD(string _ngayGD);
    int getsoTienGD(); 
    void setsoTienGD(int _soTienGD); 
    TheTu(string _userID = "NoName", string _userPin = "12345", string _TKTen = "NoName", double _TKSoDu = 0, string _TKLoaiTien = "VND", string _loaiGD = "", string _ngayGD = "", int _soTienGD = 0);
    TheTu(const TheTu& t); 
    ~TheTu(); 
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, TheTu& t);
    friend ostream& operator < (ostream& out, TheTu t);
    friend ostream& operator << (ostream& out, TheTu t);
    // Ham bo tro: 
    void ReadFile1TheTu(ifstream& file, TheTu& t);
    void ReadFile1ID(ifstream& file, TheTu& t); 
    void ReadFileNTheTu(ifstream& file, vector<TheTu>& tList);
    void ReadFileNID(ifstream& file, vector<TheTu>& tList);
    void Print1TheTu(TheTu t);
    void PrintListTheTu(vector<TheTu> tList);
    void AddTheTu (vector<TheTu> tList, TheTu t);
    void RemoveTheTu(vector<TheTu> tList, TheTu t, string id);
    void RemoveID(vector<TheTu> tList, TheTu t, string id); 
};

#endif 
