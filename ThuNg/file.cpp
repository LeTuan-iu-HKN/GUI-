#include "file.h"

void loadForm(ShippingForm*& Form, std::ifstream& filein) {
	int type;
	filein >> type;
	if (type == DOCUMENT)
		Form = new DocumentShippingForm;
	else if (type == PACKAGE)
		Form = new PackageShippingForm;

	Form->inputGeneralInfo(filein);
	Form->inputDetailInfo(filein);
}

void saveInputInfor(ShippingForm*& Form, std::ofstream& fileout) {
	fileout << Form->getType() << "\n";
	fileout << Form->sender_name << "\n";
	fileout << Form->from_address << "\n";
	fileout << Form->sent_date << "\n";
	fileout << Form->receiver_name << "\n";
	fileout << Form->to_address << "\n";
	fileout << Form->received_date << "\n";

	if (Form->getType() == DOCUMENT) {
		fileout << ((DocumentShippingForm*)Form)->distance;
	}
	else if (Form->getType() == PACKAGE) {
		fileout << ((PackageShippingForm*)Form)->distance << "\n";
		fileout << ((PackageShippingForm*)Form)->weight;
	}
}

void creatNewFile(std::string file_name) {
	std::ofstream file(file_name);
	file.close();
}

bool isFileExist(std::string file_name) {
	std::ifstream file;
	file.open(file_name);

	bool isExit = (bool)file;
	file.close();

	return isExit;
}

void renameFile(const char* old_name, const char* new_name) {
	rename(old_name, new_name);
}

void removeFile(const char* file_name) {
	remove(file_name);
}

void printAllFormToFile(ShippingFormList& List) {
	creatNewFile(INFOR_FILE);
	std::ofstream fileout;
	fileout.open(INFOR_FILE, std::ios::app);

	if (List.FormList.size() > 0)
		saveInputInfor(List.FormList[0], fileout);

	for (int i = 1;i < List.FormList.size();i++) {
		fileout << "\n";
		saveInputInfor(List.FormList[i], fileout);
	}

	fileout.close();
}

void printMoneyToFile(Price money) {
	creatNewFile(MONEY_FILE);
	std::ofstream fileout;
	fileout.open(MONEY_FILE, std::ios::app);
	fileout << money.DOC_service << "\n";
	fileout << money.DOC_distance << "\n";
	fileout << money.PAC_weight << "\n";
	fileout << money.PAC_distance;
	fileout.close();
}

void loadInputMoney(Price& money, std::string data_file) {
	std::ifstream filein;
	filein.open(data_file, std::ios_base::in);
	filein >> money.DOC_service;
	filein >> money.DOC_distance;
	filein >> money.PAC_weight;
	filein >> money.PAC_distance;
	filein.close();
}