#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <cstdio>

#define DEFAULT_ID 0
#define BLANK_TEXT ""
#define NULL_DATE 0

#define STRING_NOT_FOUND std::string::npos

//Nguyen Trong Tri Kien
enum ParcelType {
	DOCUMENT = 1, 
	PACKAGE = 2
};

//Nguyen Trong Tri Kien
struct Price {
	unsigned int DOC_service = 12000;
	unsigned int DOC_distance = 2000;
	unsigned int PAC_weight = 10000;
	unsigned int PAC_distance = 2000;
};

extern Price default_price;
extern Price current_price;

//Tran Quang Huy + Nguyen Trong Tri Kien
class ShippingForm {
	public:
		int ID;

		std::string sender_name;
		std::string receiver_name;

		std::string from_address;
		std::string to_address;

		int sent_date;
		int received_date;

		Price price;

		//Tran Quang Huy
		ShippingForm();
		//Tran Quang Huy
        virtual ~ShippingForm();
		//Tran Quang Huy
		bool isSucceeded();
		//Tran Quang Huy
		virtual int getType() = 0;
		//Tran Quang Huy
		virtual std::string getTypeString() = 0;
		//Nguyen Trong Tri Kien
		void inputGeneralInfo(std::ifstream& filein);
		//Nguyen Trong Tri Kien
		virtual void inputDetailInfo(std::ifstream& filein) = 0;
		//Nguyen Trong Tri Kien
		void inputPriceInfo(std::ifstream& filein);

		//Tran Quang Huy
		virtual double getRevenue() = 0;
};

class DocumentShippingForm : public ShippingForm {
	public:
		double distance;

		//Tran Quang Huy
		~DocumentShippingForm();
		//Tran Quang Huy
		int getType();
		//Tran Quang Huy
		std::string getTypeString();
		//Tran Quang Huy
		void setDetailInfo(double distance);
		//Tran Quang Huy
		double getRevenue();
		//Nguyen Trong Tri Kien
		void inputDetailInfo(std::ifstream& filein);
};

class PackageShippingForm : public ShippingForm {
	public:
		double distance;
		double weight;

		//Tran Quang Huy
		~PackageShippingForm();
		//Tran Quang Huy
		int getType();
		//Tran Quang Huy
		std::string getTypeString();
		//Tran Quang Huy
		void setDetailInfo(double distance, double weight);
		//Tran Quang Huy
		double getRevenue(); 
		//Nguyen Trong Tri Kien
		void inputDetailInfo(std::ifstream &filein);
};


//Tran Quang Huy + Nguyen Trong Tri Kien
class ShippingFormList {
	public:
		std::vector<ShippingForm*> FormList;

		//Tran Quang Huy
		void addForm(ShippingForm*& Form);
		//Tran Quang Huy
		void removeForm(int index);
		//Tran Quang Huy
		void replaceForm(ShippingForm*& NewForm, int index);
		//Nguyen Trong Tri Kien
		void inputList(std::ifstream& filein);
};

#endif
