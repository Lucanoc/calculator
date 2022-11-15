#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

auto addMethod(double first, double second) -> double;
auto lesMethod(double first, double second) -> double;
auto mulMethod(double first, double second) -> double;
auto divMethod(double first, double second) -> double;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this->setWindowTitle("坤坤计算器");
    
    method["+"] = addMethod;
    method["-"] = lesMethod;
    method["*"] = mulMethod;
    method["/"] = divMethod;
}

MainWindow::~MainWindow()
{
    delete ui;
}

static
auto addMethod(double first, double second) -> double {
    return first + second;
}

static
auto lesMethod(double first, double second) -> double {
    return first - second;
}

static
auto mulMethod(double first, double second) -> double {
    return first * second;
}

static
auto divMethod(double first, double second) -> double {
    return first / second;
}

void MainWindow::updateExpression() const {
    ui->lineEdit->setText(expression);
}

void MainWindow::on_btn1_clicked()
{
    expression += '1';
    
    updateExpression();
}


void MainWindow::on_btn2_clicked()
{
    expression += '2';
    
    updateExpression();
}


void MainWindow::on_btn3_clicked()
{
    expression += '3';
    
    updateExpression();
}


void MainWindow::on_btn4_clicked()
{
    expression += '4';
    
    updateExpression();
}


void MainWindow::on_btn5_clicked()
{
    expression += '5';
    
    updateExpression();
}


void MainWindow::on_btn6_clicked()
{
    expression += '6';
    
    updateExpression();
}


void MainWindow::on_btn7_clicked()
{
    expression += '7';
    
    updateExpression();
}


void MainWindow::on_btn8_clicked()
{
    expression += '8';
    
    updateExpression();
}


void MainWindow::on_btn9_clicked()
{
    expression += '9';
    
    updateExpression();
}


void MainWindow::on_btn0_clicked()
{
    expression += '0';
    
    updateExpression();
}

void MainWindow::on_btnDot_clicked()
{
    if (expression.isEmpty()) {
        return;
    }
    
    expression += '.';
    
    updateExpression();
}


void MainWindow::on_btnAdd_clicked()
{   
    if (expression.isEmpty()) {
        return;
    }
    
    oldExpression = std::move(expression);
    expression.clear();
    
    mode = "+";
    
    updateExpression();
}


void MainWindow::on_btnLes_clicked()
{
    if (expression.isEmpty()) {
        return;
    }
    
    oldExpression = std::move(expression);
    expression.clear();
    
    mode = "-";
    
    updateExpression();
}


void MainWindow::on_btnMult_clicked()
{
    if (expression.isEmpty()) {
        return;
    }
    
    oldExpression = std::move(expression);
    expression.clear();
    
    mode = "*";

    updateExpression();
}


void MainWindow::on_btnDiv_clicked()
{
    if (expression.isEmpty()) {
        return;
    }
    
    oldExpression = std::move(expression);
    expression.clear();
    
    mode = "/";
    
    updateExpression();
}


void MainWindow::on_btnCalc_clicked()
{
    if (mode.isEmpty()) {
        return;
    }
    
    if (expression.isEmpty()) {
        QMessageBox::information(this, "鸡你太美", "第一个操作数为" + oldExpression + "\n请输入第二个操作数!");
        
        return;
    }
    
    double result = method[mode](oldExpression.toDouble(), expression.toDouble());
    
    expression.setNum(result);
    oldExpression.setNum(result);
    
    mode.clear();
    
    updateExpression();
}


void MainWindow::on_btnCls_clicked()
{
    oldExpression.clear();
    expression.clear();
    mode.clear();
    
    updateExpression();
}

