#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_WorkMode(WORKMODE::kDeCode),
    m_PaswdMode(PasswordMode::kNumLetterSimbol),
    m_PaswdCount(PasswordCount::kAutoNum),
    m_CodeLevel(EDCodeLevel::kDLevel),
    m_SingedFlag(SingedFlag::kUnSigned),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("EDCoder"));

    MainLayout = new QGridLayout(this->centralWidget());

    DECodeLabel = new QLabel;
    DECodeLabel->setText(tr("加密"));
    MainLayout->addWidget(DECodeLabel, 0, 0);

    DECodeCheckBox = new QCheckBox;
    MainLayout->addWidget(DECodeCheckBox, 0, 1);
    connect(DECodeCheckBox, SIGNAL(stateChanged(int)), this, SLOT(DECodeCheckBoxSlot(int)));

    DigitalSignedLabel = new QLabel;
    DigitalSignedLabel->setText(tr("数字签名："));
    MainLayout->addWidget(DigitalSignedLabel, 0, 2);
    DigitalSignedCheckBox = new QCheckBox;
    MainLayout->addWidget(DigitalSignedCheckBox, 0 , 3);
    connect(DigitalSignedCheckBox, SIGNAL(stateChanged(int)), this, SLOT(DigitalSignedCheckBoxSlot(int)));
    DigitalSignedLineEdit = new QLineEdit;
    DigitalSignedLineEdit->setEnabled(false);
    MainLayout->addWidget(DigitalSignedLineEdit, 0 , 4);

    EnCodeLevelLabel = new QLabel;
    EnCodeLevelLabel->setText(tr("加密级别："));
    MainLayout->addWidget(EnCodeLevelLabel, 0 , 5);
    EnCodeLevelComboBox = new QComboBox;
    EnCodeLevelComboBox->addItem("D");
    EnCodeLevelComboBox->addItem("C");
    EnCodeLevelComboBox->addItem("B");
    EnCodeLevelComboBox->addItem("A");
    EnCodeLevelComboBox->addItem("S");
    EnCodeLevelComboBox->addItem("SS");
    EnCodeLevelComboBox->addItem("SSS");
    MainLayout->addWidget(EnCodeLevelComboBox, 0 , 6);

    EnCodeAlthorimLabel = new QLabel;
    EnCodeAlthorimLabel->setText(tr("加密算法:"));
    MainLayout->addWidget(EnCodeAlthorimLabel, 0 , 7);
    EnCodeAlthorimCombox = new QComboBox;
    EnCodeAlthorimCombox->addItem("Base64");
    EnCodeAlthorimCombox->addItem("MD5");
    EnCodeAlthorimCombox->addItem("SM2");
    EnCodeAlthorimCombox->addItem("SM3");
    EnCodeAlthorimCombox->addItem("SM4");
    EnCodeAlthorimCombox->setEnabled(true);
    MainLayout->addWidget(EnCodeAlthorimCombox, 0 , 8);

    FuncTabWidget = new QTabWidget;
    ACountTabWidget = new QTabWidget;
    FileTabWidget = new QTabWidget;
    MainLayout->addWidget(FuncTabWidget, 1 , 0, 1, 9);
    FuncTabWidget->addTab(ACountTabWidget, tr("账户加密/解密"));
    FuncTabWidget->addTab(FileTabWidget, tr("文件加密/解密"));

    ACountGridLayout = new QGridLayout(ACountTabWidget);
    ACountNameLabel = new QLabel;
    ACountNameLabel->setText(tr("用户名："));
    ACountNameLineEdit = new QLineEdit;
    ACountGridLayout->addWidget(ACountNameLabel, 0, 0);
    ACountGridLayout->addWidget(ACountNameLineEdit, 0, 1);
    ACountPasswordLabel = new QLabel;
    ACountPasswordLabel->setText(tr("密码："));
    ACountPasswordLineEdit = new QLineEdit;
    ACountPasswordLineEdit->setEnabled(false);
    ACountGridLayout->addWidget(ACountPasswordLabel, 0, 2);
    ACountGridLayout->addWidget(ACountPasswordLineEdit, 0, 3);

    PasswordModeLabel = new QLabel;
    PasswordModeLabel->setText(tr("密码组合："));
    PasswordModeComboBox = new QComboBox;
    PasswordModeComboBox->addItem("数字/字母/特殊字符");
    PasswordModeComboBox->addItem("字母/特殊字符");
    PasswordModeComboBox->addItem("数字/字母");
    PasswordModeComboBox->addItem("数字/特殊字符");
    PasswordModeComboBox->addItem("字母");
    PasswordModeComboBox->addItem("数字");
    ACountGridLayout->addWidget(PasswordModeLabel, 1, 0);
    ACountGridLayout->addWidget(PasswordModeComboBox, 1, 1);

    PasswordLengthLabel = new QLabel;
    PasswordLengthLabel->setText(tr("密码位数："));
    PasswordLengthComboBox = new QComboBox;
    PasswordLengthComboBox->addItem(tr("自由加密"));
    PasswordLengthComboBox->addItem(tr("6位密码"));
    PasswordLengthComboBox->addItem(tr("8位密码"));
    PasswordLengthComboBox->addItem(tr("10位密码"));
    PasswordLengthComboBox->addItem(tr("12位密码"));
    PasswordLengthComboBox->addItem(tr("16位密码"));
    PasswordLengthComboBox->addItem(tr("18位密码"));
    ACountGridLayout->addWidget(PasswordLengthLabel, 1, 2);
    ACountGridLayout->addWidget(PasswordLengthComboBox, 1, 3);
    connect(PasswordLengthComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(PasswordLengthComboBoxSlot(int)));

    DECodeBtn = new QPushButton;
    DECodeBtn->setText(tr("加密/解密"));
    ACountGridLayout->addWidget(DECodeBtn, 2, 3);
    connect(DECodeBtn, SIGNAL(clicked()), this, SLOT(DECodeBtnSlot()));

    ACountGroupBox = new QGroupBox;
    ACountGroupBox->setTitle(tr("输出加/解密消息"));
    ACountListWidget = new QListWidget;
    BoxLayout = new QVBoxLayout;
    ACountGroupBox->setLayout(BoxLayout);
    BoxLayout->addWidget(ACountListWidget);
    ACountGridLayout->addWidget(ACountGroupBox, 3, 0, 1, 4);

    FileGridLayout = new QGridLayout(FileTabWidget);

}

void MainWindow::PasswordLengthComboBoxSlot(int CurrentItem)
{
    switch(CurrentItem)
    {
    case 0: m_PaswdCount = PasswordCount::kAutoNum;break;
    case 1: m_PaswdCount = PasswordCount::k6Num;break;
    case 2: m_PaswdCount = PasswordCount::k8Num;break;
    case 3: m_PaswdCount = PasswordCount::k10Num;break;
    case 4: m_PaswdCount = PasswordCount::k12Num;break;
    case 5: m_PaswdCount = PasswordCount::k16Num;break;
    case 6: m_PaswdCount = PasswordCount::k18Num;break;
    }
}

void MainWindow::DigitalSignedCheckBoxSlot(int state)
{
    if (0 == state)
    {
        DigitalSignedLineEdit->setEnabled(false);
        m_SingedFlag = SingedFlag::kUnSigned;
    }
    else
    {
        DigitalSignedLineEdit->setEnabled(true);
        m_SingedFlag = SingedFlag::kSigned;
    }
}

void MainWindow::DECodeCheckBoxSlot(int state)
{
    if (0 == state)
    {
        ACountNameLineEdit->setEnabled(true);
        ACountPasswordLineEdit->setEnabled(false);
        DECodeLabel->setText(tr("加密"));
        m_WorkMode = WORKMODE::kDeCode;

    }
    else
    {
        ACountNameLineEdit->setEnabled(false);
        ACountPasswordLineEdit->setEnabled(true);
        DECodeLabel->setText(tr("解密"));
        m_WorkMode = WORKMODE::kEnCode;
    }
}

void MainWindow::DECodeBtnSlot()
{
    QString strDInfo, strSInfo;
    strSInfo = ACountNameLineEdit->text();
    strDInfo = ACountPasswordLineEdit->text();
    if (!(strDInfo.isEmpty() && strSInfo.isEmpty()))
    {
    CEDCoder* Coder = new CEDCoder();
    CreateSourceInfo(strSInfo);
    Coder->DEnCodeAPI(m_WorkMode, m_CodeLevel, strSInfo, strDInfo);
    CreateDestnationInfo(strDInfo);
    }
    else
    {
        DisplayOut(tr("请输入加密账户或解密密码！"));
    }
}

void MainWindow::CreateSourceInfo(QString &strSInfo)
{
    ACountListWidget->addItem(tr("加密账号为：") + strSInfo);
    if (m_SingedFlag == SingedFlag::kSigned)
    {
        ACountListWidget->addItem(tr("数字签名为：") + DigitalSignedLineEdit->text());
        strSInfo +=  (tr("_") + DigitalSignedLineEdit->text());
    }
}

void MainWindow::CreateDestnationInfo(QString &strDInfo)
{
    ACountListWidget->addItem(tr("加密密码为：") + strDInfo.mid(0, (int)m_PaswdCount));
}

void MainWindow::DisplayOut(QString Message)
{
    ACountListWidget->addItem(Message);
}

MainWindow::~MainWindow()
{
    delete ui;
}
