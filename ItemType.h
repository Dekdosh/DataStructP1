#pragma once
#include <string>

using namespace std;

class ItemType
{
public:
	ItemType(string x, string y, ItemType* next = nullptr);
	~ItemType();
	//string getData() const;
	ItemType* getNext() const;
	string getA() { return a; }
	string getB() { return b; }
	string getC() { return c; }
	string getD() { return d; }
	string getX() const { return x; }
	string getY() const { return y; }
	string getAC() const { return ac; }
	string getBD() const { return bd; }
	string getTmp() const{ return tmp; }
	//string getE() const { return e; }
	string getSumAB() const{ return sum_ab; }
	string getSumCD() const { return sum_cd; }
	string getResult() const { return result; }
	int getStage() const { return stage; }

	//void setData(string data);
	void setX(string x) { this->x = x; }
	void setY(string y) { this->y = y; }
	void setA(string a) { this->a = a; }
	void setB(string b) { this->b = b; }
	void setC(string c) { this->c = c; }
	void setD(string d) { this->d = d; }
	void setAC(string ac) { this->ac = ac; }
	void setBD(string bd) { this->bd = bd; }
	void setTmp(string tmp) { this->tmp = tmp; }
	//void setE(string e) { this->e = e; }
	void setSumAB(string sumAB) { this->sum_ab = sumAB; }
	void setSumCD(string sumCD) { this->sum_cd = sumCD; }
	void setResult(string res) { result = res; }
	void setNext(ItemType* next);
	void setStage(int newStage) { this->stage = newStage; }


private:
	string a,b,c,d, x, y, tmp, ac, bd, sum_ab, sum_cd, result;
	ItemType* next;
	int stage = 0; //1-ac, 2-bd, 3-sum, 4-result
};

