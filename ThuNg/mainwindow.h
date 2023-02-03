#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

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

//Page CapNhatGia
struct Price {
    double DOC_service = 12000;
    double DOC_distance = 2000;
    double PAC_weight = 10000;
    double PAC_distance = 2000;
};

//PageDoanhThu
    //int doanhThu;
    //int NgayThangNamBD;
    //int NgayThangNamKT;

