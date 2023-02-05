#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDateTimeEdit>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <fstream>
#include <vector>
#include "data_structure.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Price random;


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->label_51->setText(QString::number(random.DOC_service, 'f', 0));
    ui->label_52->setText(QString::number(random.DOC_distance, 'f', 0));
    ui->label_53->setText(QString::number(random.PAC_weight, 'f', 0));
    ui->label_54->setText(QString::number(random.PAC_distance, 'f', 0));
}

//PageTimKiem
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableWidgetDSDiaChi->setRowCount(10);
    ui->tableWidgetDSDiaChi->setColumnCount(8);

}


void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->tableWidgetDSDoanhThu->setRowCount(7);
    ui->tableWidgetDSDoanhThu->setColumnCount(8);

}


void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayFormTable(int row, ShippingForm* Form, QTableWidget*& table) {
    ui->tableWidgetDSDiaChi->setRowCount(row + 1);
    QTableWidgetItem* item[8];
    for(int i = 0; i < 8; i++)
           item[i] = new QTableWidgetItem;

    item[0]->setText(QString::fromStdString(Form->sender_name)); table->setItem(row, 0, item[0]);
    item[1]->setText(QString::fromStdString(Form->from_address)); table->setItem(row, 1, item[1]);
    item[2]->setText(QString::fromStdString(Form->receiver_name)); table->setItem(row, 2, item[2]);
    item[3]->setText(QString::fromStdString(Form->to_address)); table->setItem(row, 3, item[3]);
    item[4]->setText(QString::fromStdString(convertDate(Form->sent_date))); table->setItem(row, 4, item[4]);
    item[5]->setText(QString::fromStdString(convertDate(Form->received_date))); table->setItem(row, 5, item[5]);
    item[6]->setText(QString::fromStdString(Form->getTypeString())); table->setItem(row, 6, item[6]);
    item[7]->setText(QString::number(Form->revenue)); table->setItem(row, 7, item[7]);
}

//PageThem

void MainWindow::on_pushButton_clicked()
{
    if(ui->textEditTenNguoiGui->toPlainText().isEmpty() || ui->textEditTenNguoiNhan->toPlainText().isEmpty() || ui->textEditDiaChiGui->toPlainText().isEmpty() || ui->textEditDiaChiNhan->toPlainText().isEmpty() || ui->textEditDiaChiGui->toPlainText().isEmpty() || (!(ui->radioButtonTaiLieu->isChecked()) && !(ui->radioButton_2->isChecked())) || ui->doubleSpinBoxQuangDuong->cleanText().isEmpty()) {
        QMessageBox::critical(this, "Con gà", "Nhập đủ vào con gà");
    } else {
    ui->stackedWidget->setCurrentIndex(2);
    ShippingForm* Form;
    int type = ui->radioButtonTaiLieu->isChecked();//1 la tai lieu 0 la buu kien

    if(type == 1) type = DOCUMENT;
    else type = PACKAGE;

    if(type == DOCUMENT) Form = new DocumentShippingForm;
    else Form = new PackageShippingForm;

    Form->sender_name = ui->textEditTenNguoiGui->toPlainText().toStdString();
    Form->receiver_name = ui->textEditTenNguoiNhan->toPlainText().toStdString();
    Form->from_address = ui->textEditDiaChiGui->toPlainText().toStdString();
    Form->to_address = ui->textEditDiaChiNhan->toPlainText().toStdString();
    Form->sent_date = ui->dateEditNgayGui->date().toString("yyyyMMdd").toInt();
    Form->isSucceeded = ui->checkBoxDenChua->isTristate();//1 la roi 0 la chua
    Form->received_date = ui->dateEditNgayNhan->date().toString("yyyyMMdd").toInt();

    if(type == DOCUMENT) {
        ((DocumentShippingForm*) Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong->value());
    }
    else if(type == PACKAGE) {
        ((PackageShippingForm*) Form)->setDetailInfo(ui->doubleSpinBoxQuangDuong->value(), ui->doubleSpinBoxCanNang->value());
    }
    
    if (List.FormList.size() > 0) {
        std::ofstream fileout;
        fileout.open(INFOR_FILE, std::ios::app);
        fileout << "\n";
        fileout.close();   
    }

    List.addForm(Form);
    std::ofstream fileout;
    fileout.open(INFOR_FILE, std::ios::app);
    saveInputInfor(Form, fileout);
    fileout.close();

    ui->labelTenNguoiGui->setText(Form->sender_name.c_str());
    ui->labelTenNguoiNhan->setText(Form->receiver_name.c_str());
    ui->labelDiaChiGui->setText(Form->from_address.c_str());
    ui->labelDiaChiNhan->setText(Form->to_address.c_str());

    if(Form->getType() == DOCUMENT) {
        ui->labelQuangDuong->setText(QString::number(((DocumentShippingForm*)Form)->distance));
    }

    // if(test.TaiLieuHayBuuKien)
    //     {
    //         ui->labelTaiLieuHayBuuKien->setText("Tai lieu");
    //     }else
    //     {
    //     ui->labelTaiLieuHayBuuKien->setText("Buu Kien");
    //     }

    // ui->labelNgayThangNamGui->setText(QString::fromStdString(std::to_string(test.NgayThangNamGui)));//

    // if(test.DenChua)
    //     {
    //         ui->labelNgayThangNamNhan->setText(QString::fromStdString(std::to_string(test.NgayThangNamNhan)));//
    //     }else
    //     {
    //     ui->labelNgayThangNamNhan->setText("Chua den");
    //     }
}
}


//Page ThemThanhCong

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

//PageCapNhatGia

void MainWindow::on_pushButton_15_clicked()
{
    if(ui->checkBox_5->isChecked()) {
    random.DOC_service = ui->textEdit_40->toPlainText().toDouble();
    random.DOC_distance = ui->textEdit_40->toPlainText().toDouble();
    ui->label_51->setText(QString::number(random.DOC_service, 'f', 0));
    ui->label_52->setText(QString::number(random.DOC_distance, 'f', 0));
}
    if(ui->checkBox_6->isChecked()) {
    random.PAC_weight = ui->textEdit_40->toPlainText().toDouble();
    random.PAC_distance = ui->textEdit_40->toPlainText().toDouble();
    ui->label_53->setText(QString::number(random.PAC_weight, 'f', 0));
    ui->label_54->setText(QString::number(random.PAC_distance, 'f', 0));

}
    if(!(ui->checkBox_6->isChecked()) && !(ui->checkBox_5->isChecked())) {
    QMessageBox::critical(this, "LỖI RỒI ĐÓ NHA", "CLICK chọn 1 trong 2 ô để chúng mình cùng chạy nhé!");
}
}


void MainWindow::on_pushButton_13_clicked()
{
    random.DOC_service = 12000;
    random.DOC_distance = 2000;
    random.PAC_weight = 10000;
    random.PAC_distance = 2000;
    ui->label_51->setText(QString::number(random.DOC_service, 'f', 0));
    ui->label_52->setText(QString::number(random.DOC_distance, 'f', 0));
    ui->label_53->setText(QString::number(random.PAC_weight, 'f', 0));
    ui->label_54->setText(QString::number(random.PAC_distance, 'f', 0));
}

//PageDoanhThu
void MainWindow::on_pushButton_6_clicked()
{
    DT r;
    r.NgayThangNamBD =  ui->dateEdit->date().toString("yyyyMMdd").toInt();
    r.NgayThangNamKT =  ui->dateEdit_2->date().toString("yyyyMMdd").toInt();
    ui->label_6->setText(QString::fromStdString(std::to_string(r.doanhThu)));
}

//PageTimKiem


void MainWindow::on_pushButton_7_clicked()
{
    std::vector<int> index = searchIndexFormList(List, ui->textSearch->toPlainText().toStdString());
    QTableWidgetItem* item[(int) index.size()][8];
    for(int i = 0; i < (int) index.size(); i++)
        for(int j = 0; j < 8; j++)
            item[i][j] = new QTableWidgetItem;

    for(int i = 0; i < (int) index.size(); i++) {
        displayFormTable(i, List.FormList[index[i]], ui->tableWidgetDSDiaChi);
    }
}
