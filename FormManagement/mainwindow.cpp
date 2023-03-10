#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

//Nguyen Le Tuan + Tran Quang Huy
void MainWindow::displayFormTable(int row, ShippingForm* Form, QTableWidget*& table) {
    table->setRowCount(row + 1);
    QTableWidgetItem* item[8];
    for (int i = 0; i < 8; i++)
    item[i] = new QTableWidgetItem;
    item[0]->setText(QString::fromStdString(Form->sender_name)); table->setItem(row, 0, item[0]);
    item[1]->setText(QString::fromStdString(Form->from_address)); table->setItem(row, 1, item[1]);
    item[2]->setText(QString::fromStdString(Form->receiver_name)); table->setItem(row, 2, item[2]);
    item[3]->setText(QString::fromStdString(Form->to_address)); table->setItem(row, 3, item[3]);
    item[4]->setText(QString::fromStdString(convertDate(Form->sent_date))); table->setItem(row, 4, item[4]);
    Form->received_date == NULL_DATE ? item[5]->setText("Đang giao") : item[5]->setText(QString::fromStdString(convertDate(Form->received_date))); table->setItem(row, 5, item[5]);
    item[6]->setText(QString::fromStdString(Form->getTypeString())); table->setItem(row, 6, item[6]);
    item[7]->setText(QString::number(Form->getRevenue())); table->setItem(row, 7, item[7]);
}

//PageTimKiem
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageTimDC_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonTimDC_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableWidgetDSDiaChi->setRowCount(10);
    ui->tableWidgetDSDiaChi->setColumnCount(8);
}

//Nguyen Le Tuan + Tran Quang Huy
void MainWindow::on_pushButtonXacNhanDiaChi_clicked()
{
    std::vector<int> index = searchIndexFormList(List, ui->textSearch->toPlainText().toStdString());
    for (int i = 0; i < (int)index.size(); i++) {
        displayFormTable(i, List.FormList[index[i]], ui->tableWidgetDSDiaChi);
    }
}

//Page Them
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCThem_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonThem_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//Tran Quang Huy
bool MainWindow::isThemDonEmpty() {
    return (
        ui->textEditTenNguoiGui->toPlainText().isEmpty() ||
        ui->textEditTenNguoiNhan->toPlainText().isEmpty() ||
        ui->textEditDiaChiGui->toPlainText().isEmpty() ||
        ui->textEditDiaChiNhan->toPlainText().isEmpty() ||
        (!(ui->radioButtonTaiLieu->isChecked()) && !(ui->radioButtonBuuKien->isChecked())) ||
        ui->doubleSpinBoxQuangDuong->cleanText().isEmpty() ||
        (ui->radioButtonBuuKien->isChecked() && ui->doubleSpinBoxCanNang->cleanText().isEmpty())
        );
}

void MainWindow::on_pushButtonXacNhanThemDon_clicked() {
    if (isThemDonEmpty()) {
        //Nguyen Le Tuan
        QMessageBox::critical(this, "Thiếu thông tin", "Vui lòng nhập đầy đủ thông tin");
    }
    else {
        //Nguyen Le Tuan + Tran Quang Huy
        ui->stackedWidget->setCurrentIndex(2);
        ShippingForm* Form;
        int type = ui->radioButtonTaiLieu->isChecked(); //1 la tai lieu 0 la buu kien

        if (type == 1) type = DOCUMENT;
        else type = PACKAGE;

        if (type == DOCUMENT) Form = new DocumentShippingForm;
        else Form = new PackageShippingForm;

        Form->sender_name = ui->textEditTenNguoiGui->toPlainText().toStdString();
        Form->receiver_name = ui->textEditTenNguoiNhan->toPlainText().toStdString();
        Form->from_address = ui->textEditDiaChiGui->toPlainText().toStdString();
        Form->to_address = ui->textEditDiaChiNhan->toPlainText().toStdString();
        Form->sent_date = ui->dateEditNgayGui->date().toString("yyyyMMdd").toInt();
        if (ui->checkBoxDenChua->isChecked()) Form->received_date = ui->dateEditNgayNhan->date().toString("yyyyMMdd").toInt();

        if (type == DOCUMENT) {
            ((DocumentShippingForm*)Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong->value());
        }
        else if (type == PACKAGE) {
            ((PackageShippingForm*)Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong->value(), ui->doubleSpinBoxCanNang->value());
        }

        if (List.FormList.size() > 0) {
            std::ofstream fileout;
            fileout.open(INFOR_FILE, std::ios::app);
            fileout << "\n";
            fileout.close();
        }

        List.addForm(Form);

        //Tran Quang Huy
        std::ofstream fileout;
        fileout.open(INFOR_FILE, std::ios::app);
        saveInputInfor(Form, fileout);
        fileout.close();

        ui->labelTenNguoiGui->setText(Form->sender_name.c_str());
        ui->labelTenNguoiNhan->setText(Form->receiver_name.c_str());
        ui->labelDiaChiGui->setText(Form->from_address.c_str());
        ui->labelDiaChiNhan->setText(Form->to_address.c_str());
        ui->labelNgayThangNamGui->setText(QString::fromStdString(convertDate(Form->sent_date)));

        if (Form->getType() == DOCUMENT) {
            ui->labelQuangDuong->setText(QString::number(((DocumentShippingForm*)Form)->distance) + " km");
            ui->labelTaiLieuHayBuuKien->setText(QString::fromStdString(Form->getTypeString()));
        }
        else if (Form->getType() == PACKAGE) {
            ui->labelQuangDuong->setText(QString::number(((PackageShippingForm*)Form)->distance) + " km");
            ui->labelTaiLieuHayBuuKien->setText(QString::fromStdString(Form->getTypeString()) + ": " + QString::number(((PackageShippingForm*)Form)->weight) + " kg");
        }

        if (Form->received_date == NULL_DATE) {
            ui->labelNgayThangNamNhan->setText("Đơn hàng chưa đến nơi");
        }
        else {
            ui->labelNgayThangNamNhan->setText(QString::fromStdString(convertDate(Form->received_date)));
        }
    }
}

//Page ThemThanhCong
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageThemThanhCong_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Page Xoa don
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageXoa_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Tran Quang Huy
void MainWindow::refreshFormTable(QTableWidget*& table) {
    for (int i = 0; i < (int)List.FormList.size(); i++)
        displayFormTable(i, List.FormList[i], table);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonGiaoDienXoaDon_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
    ui->tableWidgetDSToanBoDonHang->setRowCount(10);
    ui->tableWidgetDSToanBoDonHang->setColumnCount(8);
    refreshFormTable(ui->tableWidgetDSToanBoDonHang);
}

//Tran Quang Huy
void MainWindow::on_pushButtonXacNhanXoaDon_clicked() {
    int index = ui->spinBoxSTTCanXoa->value() - 1; //index = STT - 1
    List.removeForm(index);
    refreshFormTable(ui->tableWidgetDSToanBoDonHang);
    printAllFormToFile(List);
}

//Page Chinh sua don
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageDieuChinh_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageDieuChinh_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonGiaoDienChinhSuaDon_clicked() {
    ui->stackedWidget->setCurrentIndex(5);
    ui->tableWidgetDSToanBoDonHangGiaoDienChinhSua->setRowCount(10);
    ui->tableWidgetDSToanBoDonHangGiaoDienChinhSua->setColumnCount(8);
    refreshFormTable(ui->tableWidgetDSToanBoDonHangGiaoDienChinhSua);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonXacNhanChonDonChinhSua_clicked() {
    ui->stackedWidget->setCurrentIndex(8);
}

//Tran Quang Huy
bool MainWindow::isSuaDonEmpty() {
    return (
    ui->textEditTenNguoiGui_2->toPlainText().isEmpty() ||
    ui->textEditTenNguoiNhan_2->toPlainText().isEmpty() ||
    ui->textEditDiaChiGui_2->toPlainText().isEmpty() ||
    ui->textEditDiaChiNhan_2->toPlainText().isEmpty() ||
    (!(ui->radioButtonTaiLieu_2->isChecked()) && !(ui->radioButtonBuuKien_2->isChecked())) ||
    ui->doubleSpinBoxQuangDuong_2->cleanText().isEmpty() ||
    (ui->radioButtonBuuKien_2->isChecked() && ui->doubleSpinBoxCanNang_2->cleanText().isEmpty())
    );
}

//Nguyen Le Tuan + Tran Quang Huy
void MainWindow::on_pushButtonXacNhanThemDon_2_clicked() {
    if (isSuaDonEmpty()) {
        QMessageBox::critical(this, "Thiếu thông tin", "Vui lòng nhập đầy đủ thông tin");
    }
    else {
        ShippingForm* Form;
        int type = ui->radioButtonTaiLieu_2->isChecked(); //1 la tai lieu 0 la buu kien

        if (type == 1) type = DOCUMENT;
        else type = PACKAGE;

        if (type == DOCUMENT) Form = new DocumentShippingForm;
        else Form = new PackageShippingForm;

        Form->sender_name = ui->textEditTenNguoiGui_2->toPlainText().toStdString();
        Form->receiver_name = ui->textEditTenNguoiNhan_2->toPlainText().toStdString();
        Form->from_address = ui->textEditDiaChiGui_2->toPlainText().toStdString();
        Form->to_address = ui->textEditDiaChiNhan_2->toPlainText().toStdString();
        Form->sent_date = ui->dateEditNgayGui_2->date().toString("yyyyMMdd").toInt();
        if (ui->checkBoxDenChua_2->isChecked()) Form->received_date = ui->dateEditNgayNhan_2->date().toString("yyyyMMdd").toInt();

        if (type == DOCUMENT) {
            ((DocumentShippingForm*)Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong_2->value());
        }
        else if (type == PACKAGE) {
            ((PackageShippingForm*)Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong_2->value(), ui->doubleSpinBoxCanNang_2->value());
        }

        List.replaceForm(Form, ui->spinBoxSTTCanChinhSua->value() - 1);
        printAllFormToFile(List);

        refreshFormTable(ui->tableWidgetDSToanBoDonHangGiaoDienChinhSua);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

//PageCapNhatGia
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageCapNhatGia_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonCapNhatGia_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->labelGiaNhanDonTaiLieu->setText(QString::number(current_price.DOC_service));
    ui->labelGiaQuangDuongTaiLieu->setText(QString::number(current_price.DOC_distance));
    ui->labelGiaCanNangBuuKien->setText(QString::number(current_price.PAC_weight));
    ui->labelGiaQuangDuongBuuKien->setText(QString::number(current_price.PAC_distance));
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonCapNhatGia_clicked() {
    if (!(ui->checkBoxTaiLieu->isChecked()) && !(ui->checkBoxBuuKien->isChecked())) {
        QMessageBox::critical(this, "Thiếu thông tin", "Vui lòng chọn ít nhất 1 trong 2 ô Tài liệu hoặc Bưu kiện!");
    }
    else {
        if (ui->checkBoxTaiLieu->isChecked()) {
            current_price.DOC_service = ui->textEditGiaNhanDonTaiLieu->toPlainText().toUInt();
            current_price.DOC_distance = ui->textEditGiaQuangDuongTaiLieu->toPlainText().toUInt();
            ui->labelGiaNhanDonTaiLieu->setText(QString::number(current_price.DOC_service));
            ui->labelGiaQuangDuongTaiLieu->setText(QString::number(current_price.DOC_distance));
        }
        if (ui->checkBoxBuuKien->isChecked()) {
            current_price.PAC_weight = ui->textEditGiaCanNangBuuKien->toPlainText().toUInt();
            current_price.PAC_distance = ui->textEditGiaQuangDuongBuuKien->toPlainText().toUInt();
            ui->labelGiaCanNangBuuKien->setText(QString::number(current_price.PAC_weight));
            ui->labelGiaQuangDuongBuuKien->setText(QString::number(current_price.PAC_distance));
        }
        printMoneyToFile(current_price);
    }
}

//Tran Quang Huy
void MainWindow::on_pushButtonDatVeMacDinh_clicked() {
    ui->labelGiaNhanDonTaiLieu->setText(QString::number(default_price.DOC_service));
    ui->labelGiaQuangDuongTaiLieu->setText(QString::number(default_price.DOC_distance));
    ui->labelGiaCanNangBuuKien->setText(QString::number(default_price.PAC_weight));
    ui->labelGiaQuangDuongBuuKien->setText(QString::number(default_price.PAC_distance));
    current_price = default_price;
    printMoneyToFile(current_price);
}

//Page Thong ke
//Nguyen Le Tuan
void MainWindow::on_pushButtonVeGDCPageThongKe_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonXacNhanThongKeTheoThoiGian_clicked() {
    double revenue = 0;
    int start_date = ui->dateEdit->date().toString("yyyyMMdd").toInt();
    int end_date = ui->dateEdit_2->date().toString("yyyyMMdd").toInt();
    std::vector<int> index = searchDateIndexFormList(List, start_date, end_date);

    for (int i = 0; i < (int)index.size(); i++) {
        displayFormTable(i, List.FormList[index[i]], ui->tableWidgetDSDoanhThu);
        revenue += List.FormList[index[i]]->getRevenue();
    }
    ui->label_6->setText(QString::number(revenue));
}

//Nguyen Le Tuan
void MainWindow::on_pushButtonThongKe_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
    ui->tableWidgetDSDoanhThu->setRowCount(5);
    ui->tableWidgetDSDoanhThu->setColumnCount(8);
}




































