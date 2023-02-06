#include "data_structure.h"

Price default_price;
Price current_price;

//Tran Quang Huy
ShippingForm::ShippingForm() {
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this->received_date = NULL_DATE;
	this->price = current_price;
}
//Tran Quang Huy
ShippingForm::~ShippingForm() {
	delete this;
}
//Tran Quang Huy
bool ShippingForm::isSucceeded() {
	return !(this->received_date == NULL_DATE);
}
//Nguyen Trong Tri Kien
void ShippingForm::inputGeneralInfo(std::ifstream& filein) {
	filein.ignore();
	getline(filein, sender_name);
	getline(filein, from_address); // std::cin.ignore(MAX_STREAMSIZE, '\n');
	filein >> sent_date;

	filein.ignore();
	getline(filein, receiver_name);
	getline(filein, to_address);
	filein >> received_date;
}
//Nguyen Trong Tri Kien
void ShippingForm::inputPriceInfo(std::ifstream& filein) {
	filein >> price.DOC_service;
	filein >> price.DOC_distance;
	filein >> price.PAC_weight;
	filein >> price.PAC_distance;
}

/////////////////////////////////////
DocumentShippingForm::~DocumentShippingForm() {
	delete this;
}
//Tran Quang Huy
int DocumentShippingForm::getType() {
	return DOCUMENT;
}

std::string DocumentShippingForm::getTypeString() {
	return std::string("Tài liệu");
}

void DocumentShippingForm::setDetailInfo(double distance) {
	this->distance = distance;
}
//Tran Quang Huy
double DocumentShippingForm::getRevenue() {
    if(received_date == NULL_DATE) return 0;
	return (distance * price.DOC_distance + price.DOC_service);
}
//Nguyen Trong Tri Kien
void DocumentShippingForm::inputDetailInfo(std::ifstream& filein) {
	filein >> distance;
}

/////////////////////////////////////
//Tran Quang Huy
PackageShippingForm::~PackageShippingForm() {
	delete this;
}
//Tran Quang Huy
int PackageShippingForm::getType() {
	return PACKAGE;
}
//Tran Quang Huy
std::string PackageShippingForm::getTypeString() {
	return std::string("Bưu kiện");
}
//Tran Quang Huy
void PackageShippingForm::setDetailInfo(double distance, double weight) {
	this->distance = distance;
	this->weight = weight;
}
//Tran Quang Huy
double PackageShippingForm::getRevenue() {
    if(received_date == NULL_DATE) return 0;
	return (distance * price.PAC_distance + weight * price.PAC_weight);
}
//Nguyen Trong Tri Kien
void PackageShippingForm::inputDetailInfo(std::ifstream& filein) {
	filein >> distance;
	filein >> weight;
}

///////////////////////////////////
//Tran Quang Huy
void ShippingFormList::addForm(ShippingForm*& Form) {
	this->FormList.push_back(Form);
}

//Tran Quang Huy
void ShippingFormList::removeForm(int index) {
	this->FormList.erase(FormList.begin() + index);
}

//Tran Quang Huy
void ShippingFormList::replaceForm(ShippingForm*& NewForm, int index) {
	this->FormList.insert(FormList.begin() + index, NewForm);
	this->removeForm(index + 1);
}
//Nguyen Trong Tri Kien
void ShippingFormList::inputList(std::ifstream& filein) {
	ShippingForm* Form;

	while (!filein.eof()) {
		int type;
		filein >> type;
		if (type == DOCUMENT)
			Form = new DocumentShippingForm;
		else if (type == PACKAGE)
			Form = new PackageShippingForm;

		Form->inputGeneralInfo(filein);
		Form->inputDetailInfo(filein);
		Form->inputPriceInfo(filein);
		this->FormList.push_back(Form);
	}
}

