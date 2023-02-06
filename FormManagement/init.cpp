#include "init.h"
//Nguyen Trong Tri Kien
FormManagementSystemInit::FormManagementSystemInit() {
    this->form_info_file = INFOR_FILE;
    this->price_info_file = MONEY_FILE;
    this->cur_price = &current_price;
}
//Nguyen Trong Tri Kien
FormManagementSystemInit::FormManagementSystemInit(ShippingFormList& pList, std::string form_info_file, std::string price_info_file, Price* cur_price) {
    this->pList = &pList;
    this->form_info_file = form_info_file;
    this->price_info_file = price_info_file;
    this->cur_price = cur_price;
}
//Nguyen Trong Tri Kien
void FormManagementSystemInit::init() {
    if (!isFileExist(price_info_file)) {
        creatNewFile(price_info_file);
        *(this->cur_price) = default_price;
    }

    if (!isFileExist(form_info_file)) {
        creatNewFile(form_info_file);
    }

    std::ifstream filein;
    filein.open(form_info_file, std::ios_base::in);
    filein.peek();
    pList->inputList(filein);
    filein.close();

    loadSavedMoney(*(this->cur_price), price_info_file);
}
