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

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Page Them don
    bool isThemDonEmpty();

    //Page sua don
    bool isSuaDonEmpty();

    //Page Xoa don
    void refreshFormTable(QTableWidget*& table);
    void displayFormTable(int row, ShippingForm* Form, QTableWidget*& table);

private slots:
    // Page Them
    void on_pushButtonXacNhanThemDon_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButtonThongKe_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();



    void on_pushButton_18_clicked();

    void on_pushButtonCapNhatGia_clicked();

    void on_pushButtonDatVeMacDinh_clicked();

    void on_pushButtonXacNhanThongKeTheoThoiGian_clicked();

    void on_pushButton_7_clicked();

    void on_pushButtonGiaoDienXoaDon_clicked();

    void on_pushButtonGiaoDienChinhSuaDon_clicked();

    void on_pushButtonXacNhanXoaDon_clicked();

    void on_pushButtonXacNhanChonDonChinhSua_clicked();

    void on_pushButtonXacNhanThemDon_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

//PageThem
struct themData {
    std::string DiaChiGui;
    std::string DiaChiNhan;
    std::string tenNguoiGui;
    std::string tenNguoiNhan;
    int QuangDuong;
    int NgayThangNamGui;
    bool TaiLieuHayBuuKien;
    bool DenChua;
    int NgayThangNamNhan;
    double quangDuong;
    int ID;
};

//PageDoanhThu
struct DT {
    int NgayThangNamBD;
    int NgayThangNamKT;
};

//PageTimkiem
struct TK {
    std::string diaChiTimKiem;
};



