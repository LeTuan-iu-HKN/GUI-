#include "data_structure.h"

Price default_price;
Price current_price;

ShippingForm::ShippingForm() {
	this->ID = DEFAULT_ID;
	this->sender_name = BLANK_TEXT;
	this->receiver_name = BLANK_TEXT;
	this->from_address = BLANK_TEXT;
	this->to_address = BLANK_TEXT;
	this->sent_date = NULL_DATE;
	this->received_date = NULL_DATE;

	this->isSucceeded = false;
}

ShippingForm::~ShippingForm() {
	delete this;
}

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

/////////////////////////////////////
DocumentShippingForm::~DocumentShippingForm() {
	delete this;
}

int DocumentShippingForm::getType() {
	return DOCUMENT;
}

double DocumentShippingForm::getShippingPrice(Price custom_price) {
	return (distance * custom_price.DOC_distance + custom_price.DOC_service);
}

void DocumentShippingForm::inputDetailInfo(std::ifstream& filein) {
	filein >> distance;
}

/////////////////////////////////////
PackageShippingForm::~PackageShippingForm() {
	delete this;
}

int PackageShippingForm::getType() {
	return PACKAGE;
}

double PackageShippingForm::getShippingPrice(Price custom_price) {
	return (distance * custom_price.PAC_distance + weight * custom_price.PAC_weight);
}

void PackageShippingForm::inputDetailInfo(std::ifstream& filein) {
	filein >> distance;
	filein >> weight;
}

///////////////////////////////////
void ShippingFormList::addForm(ShippingForm*& Form) {
	this->FormList.push_back(Form);
}

void ShippingFormList::removeForm(int index) {
	this->FormList.erase(FormList.begin() + index);
}

void ShippingFormList::replaceForm(ShippingForm*& NewForm, int index) {
	this->FormList.insert(FormList.begin() + index, NewForm);
	this->removeForm(index + 1);
}

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
		this->FormList.push_back(Form);
	}
}

