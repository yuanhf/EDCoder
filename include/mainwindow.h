#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QTabWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QListWidget>
#include "CEDCoder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGridLayout* MainLayout;

    QLabel* DECodeLabel;
    QCheckBox* DECodeCheckBox;

    QLabel* DigitalSignedLabel;
    QCheckBox* DigitalSignedCheckBox;
    QLineEdit* DigitalSignedLineEdit;

    QLabel* EnCodeLevelLabel;
    QComboBox* EnCodeLevelComboBox;

    QTabWidget* FuncTabWidget;
    QTabWidget* ACountTabWidget;
    QTabWidget* FileTabWidget;

    QLabel* EnCodeAlthorimLabel;
    QComboBox* EnCodeAlthorimCombox;

    QGridLayout* ACountGridLayout;
    QGridLayout* FileGridLayout;

    QLabel* ACountNameLabel;
    QLineEdit* ACountNameLineEdit;
    QLabel* ACountPasswordLabel;
    QLineEdit* ACountPasswordLineEdit;
    QPushButton* DECodeBtn;
    QLabel* PasswordModeLabel;
    QComboBox* PasswordModeComboBox;
    QLabel* PasswordLengthLabel;
    QComboBox* PasswordLengthComboBox;

    QGroupBox* ACountGroupBox;
    QVBoxLayout* BoxLayout;
    QListWidget* ACountListWidget;
private:
    WORKMODE m_WorkMode;
    PasswordMode m_PaswdMode;
    PasswordCount m_PaswdCount;
    EDCodeLevel m_CodeLevel;
    SingedFlag m_SingedFlag;

    void CreateSourceInfo(QString&);
    void CreateDestnationInfo(QString&);

public slots:
    void DigitalSignedCheckBoxSlot(int);
    void DECodeCheckBoxSlot(int);
    void DECodeBtnSlot();
    void PasswordLengthComboBoxSlot(int);
public:
    void DisplayOut(QString);
};

#endif // MAINWINDOW_H
