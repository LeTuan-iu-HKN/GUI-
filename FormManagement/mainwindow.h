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

    //Page Them
    //Tran Quang Huy
    bool isThemDonEmpty();

    //PageSuadon
    //Tran Quang Huy
    bool isSuaDonEmpty();

    //Page Chinh sua don
    //Tran Quang Huy
    void refreshFormTable(QTableWidget*& table);
    //Tran Quang Huy
    void displayFormTable(int row, ShippingForm* Form, QTableWidget*& table);

private slots:

    //PageTimKiem
    //Nguyen Le Tuan
    void on_pushButtonTimDC_clicked();
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageTimDC_clicked();
    //Nguyen Le Tuan
    void on_pushButtonXacNhanDiaChi_clicked();

    // Page Them
    //Nguyen Le Tuan
    void on_pushButtonThem_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanThemDon_clicked();
    //Tran Quang Huy
    void on_pushButtonVeGDCThem_clicked();

    //PageThemThanhCong
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageThemThanhCong_clicked();

    // Page Xoa don
    //Tran Quang Huy
    void on_pushButtonGiaoDienXoaDon_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanXoaDon_clicked();
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageXoa_clicked();

    //Page Chinh sua don
    //Tran Quang Huy
    void on_pushButtonGiaoDienChinhSuaDon_clicked();
    //Tran Quang Huy
    void on_pushButtonXacNhanChonDonChinhSua_clicked();
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageDieuChinh_clicked();
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageDieuChinh_2_clicked();
    //Nguyen Le Tuan
    void on_pushButtonXacNhanThemDon_2_clicked();

    //PageCapNhatGia
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageCapNhatGia_clicked();
    //Tran Quang Huy
    void on_pushButtonCapNhatGia_clicked();
    //Tran Quang Huy
    void on_pushButtonDatVeMacDinh_clicked();
    //Nguyen Le Tuan
    void on_pushButtonCapNhatGia_2_clicked();


    //PageThongKe
    //Tran Quang Huy
    void on_pushButtonXacNhanThongKeTheoThoiGian_clicked();
    //Tran Quang Huy
    void on_pushButtonThongKe_clicked();
    //Nguyen Le Tuan
    void on_pushButtonVeGDCPageThongKe_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H



