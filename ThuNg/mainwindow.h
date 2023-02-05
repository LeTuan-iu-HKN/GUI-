#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "data_structure.h"
#include "program_object.h"
#include "backend.h"
#include "file.h"

#include <QDateTimeEdit>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QMainWindow>
#include <fstream>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//Tran Quang Huy + Nguyen Le Tuan
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Page Them don
    //Tran Quang Huy
    bool isThemDonEmpty();

    //Page sua don
    //Tran Quang Huy
    bool isSuaDonEmpty();

    //Page Xoa don
    //Tran Quang Huy
    void refreshFormTable(QTableWidget*& table);
    //Tran Quang Huy
    void displayFormTable(int row, ShippingForm* Form, QTableWidget*& table);

private slots:
    // Page Them
    //Tran Quang Huy
    void on_pushButtonXacNhanThemDon_clicked();
    //Nguyen Le Tuan
    void on_pushButton_2_clicked();
    //Nguyen Le Tuan
    void on_pushButton_23_clicked();
    //Nguyen Le Tuan
    void on_pushButton_3_clicked();
    //Nguyen Le Tuan
    void on_pushButton_4_clicked();
    //Nguyen Le Tuan
    void on_pushButton_20_clicked();
    //Nguyen Le Tuan
    void on_pushButton_22_clicked();
    //Nguyen Le Tuan
    void on_pushButton_21_clicked();
    //Nguyen Le Tuan
    void on_pushButton_24_clicked();
    //Nguyen Le Tuan
    void on_pushButton_25_clicked();

    //Tran Quang Huy
    void on_pushButtonThongKe_clicked();
    //Nguyen Le Tuan
    void on_pushButton_26_clicked();
    //Nguyen Le Tuan
    void on_pushButton_28_clicked();
    //Nguyen Le Tuan
    void on_pushButton_27_clicked();


    //Nguyen Le Tuan
    void on_pushButton_18_clicked();

    //Tran Quang Huy
    void on_pushButtonCapNhatGia_clicked();
    //Tran Quang Huy
    void on_pushButtonDatVeMacDinh_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanThongKeTheoThoiGian_clicked();

    //Nguyen Le Tuan
    void on_pushButton_7_clicked();
    //Tran Quang Huy
    void on_pushButtonGiaoDienXoaDon_clicked();
    //Tran Quang Huy
    void on_pushButtonGiaoDienChinhSuaDon_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanXoaDon_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanChonDonChinhSua_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanThemDon_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H



