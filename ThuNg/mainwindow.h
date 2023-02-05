#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data_structure.h"
#include "program_object.h"
#include "backend.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayFormTable(int row, ShippingForm* Form);

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

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
    int doanhThu;
    int NgayThangNamBD;
    int NgayThangNamKT;
};

//PageTimkiem
struct TK {
    std::string diaChiTimKiem;
};



