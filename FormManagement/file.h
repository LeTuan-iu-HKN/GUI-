#ifndef FILE_H
#define FILE_H 

#include "data_structure.h"

#define INFOR_FILE "D:\\infor.txt"
#define MONEY_FILE "D:\\money.txt"

//Nguyen Trong Tri Kien
void loadForm(ShippingForm*& Form, std::ifstream& filein);
//Nguyen Trong Tri Kien
void saveInputInfor(ShippingForm*& Form, std::ofstream& fileout);

//Nguyen Trong Tri Kien
void creatNewFile(std::string file_name);
//Nguyen Trong Tri Kien
bool isFileExist(std::string file_name);
//Nguyen Trong Tri Kien
void renameFile(const char* old_name, const char* new_name);
//Nguyen Trong Tri Kien
void removeFile(const char* file_name);
//Nguyen Trong Tri Kien
void printAllFormToFile(ShippingFormList& List);

//Nguyen Trong Tri Kien
void printMoneyToFile(Price money);
//Nguyen Trong Tri Kien
void loadSavedMoney(Price& money, std::string data_file);

#endif