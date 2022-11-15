#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    void updateExpression() const;
    
private slots:
    
    void on_btn1_clicked();
    
    void on_btn2_clicked();
    
    void on_btn3_clicked();
    
    void on_btn4_clicked();
    
    void on_btn5_clicked();
    
    void on_btn6_clicked();
    
    void on_btn7_clicked();
    
    void on_btn8_clicked();
    
    void on_btn9_clicked();
    
    void on_btn0_clicked();
    
    void on_btnAdd_clicked();
    
    void on_btnLes_clicked();
    
    void on_btnMult_clicked();
    
    void on_btnDiv_clicked();
    
    void on_btnCalc_clicked();
    
    void on_btnDot_clicked();
    
    void on_btnCls_clicked();
    
private:
    Ui::MainWindow *ui;
    
    QString oldExpression;
    QString expression;
    QString mode;
    
    std::map<QString, std::function<double(double, double)>> method;
};
#endif // MAINWINDOW_H
