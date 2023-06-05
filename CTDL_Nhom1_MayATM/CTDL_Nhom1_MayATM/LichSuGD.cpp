#include "LichSuGD.h"

LichSuGD::LichSuGD(string _TKID, string _loaiGD, string _ngayGD, int _soTienGD) : TheTu(_TKID, "", "", 0, "", _loaiGD, _ngayGD, _soTienGD) {}
LichSuGD::LichSuGD(const LichSuGD& tk) : TheTu(tk) {}
LichSuGD::~LichSuGD() {}

void LichSuGD::ReadFileGD(ifstream& file, LichSuGD& a) {
	string TKID;
	string loaiGD;
	int soTienGD;
	string ngayGD;
	getline(file, TKID, '_');
	getline(file, loaiGD, '_');
	getline(file, ngayGD, '_');
	file >> soTienGD;
	a = LichSuGD(TKID, loaiGD, ngayGD, soTienGD);
}
void LichSuGD::ReadFileDSGD(ifstream& file, LinkedList<LichSuGD>& aList) {
	while (file.eof() == false) {
		LichSuGD a;
		ReadFileGD(file, a);
		aList.addTail(a);
	}
}

bool operator == (LichSuGD data, LichSuGD datas) {
	if (data.getuserID().compare(datas.getuserID()))
		return true; 
	return false; 
}

int LichSuGD::findNodeInLL(LinkedList<LichSuGD> DSGD, LichSuGD datas) {
	int index = 0;
	Node<LichSuGD>* p = DSGD.getHead();
	while (p != NULL) {
		if (p->getData().getuserID() == datas.getuserID()) {
			return index;
		}
		p = p->getpNext();
		index++;
	}
	return -1;
}

Node<LichSuGD>* LichSuGD::getNode(LinkedList<LichSuGD> DSGD, int index) {
	Node<LichSuGD>* pTemp = DSGD.getHead();
	int i = 0;
	while (pTemp != NULL && i != index) {
		pTemp = pTemp->getpNext();
		i++;
	}
	if (i == index && pTemp != NULL)
		return pTemp;
	return NULL;
}

void LichSuGD::noiDungGD(LinkedList<LichSuGD> DSGD, string& keyID) {
	int kt = 0; 
	ifstream file;
	file.open("[LichSuID].txt", ios_base::in);
	ReadFileDSGD(file, DSGD);

	for (Node<LichSuGD>* pWalker = DSGD.getHead(); pWalker != DSGD.getTail(); pWalker = pWalker->getpNext()) {
		long long num1 = stoll(pWalker->getData().getuserID()); 
		long long num2 = stoll(keyID);
		if (num1 == num2) {
			cout << "\n ----------------------------------------------------- \n";
			cout << "\n Loai giao dich: " << pWalker->getData().getloaiGD() << endl;
			cout << "\n Ngay giao dich: " << pWalker->getData().getngayGD() << endl;
			cout << " So tien giao dich: " << pWalker->getData().getsoTienGD() << " dong" << endl;
			cout << "\n ----------------------------------------------------- \n\n";
			kt = 1; 
		}
	}
	if (kt == 0) {
		cout << "\n Tai khoan cua ban chua co giao dich nao!" << endl; 
	}
	file.close();	
}

