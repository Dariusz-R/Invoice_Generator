#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QLayout>
#include <QTableView>
#include <QLabel>
#include <QPushButton>

#include "invoiceinfomodel.h"
#include "agreementpartiesmodel.h"
#include "tableofgoodsmodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_ResetAgreementPartiesFormButton_clicked();
    void on_SaveButton_clicked();
    void on_GeneratePdfButton_clicked();
    void on_ResetAllButton_clicked();
    void on_RemoveItemButton_clicked();
    void on_addItemButton_clicked();
    void on_ResetListOfGoodsButton_clicked();

private:


    void readSaveAndSetStyleSheet();
    void configureAndShowMainWindowContent();
    void createLeftSide();
    void createRightSide();
    void addInvoiceInfoView();
    void createAgreementPartiesBox();
    void createLeftSideButtons();
    void createAgreementPartiesView();
    void setUpInvoiceInfoViewSizes();
    void setUpAgreementPartiesViewSizes();
    void setUpTableOfGoodsViewSizes();
    void setUpAgreementPartiesBoxSizes();
    void setUpAgreementPartiesHeaderSizes();

    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QString styleSheetContent;

    //LEFT SIDE
    QGroupBox *leftSide;
    QVBoxLayout *leftLayout;

    QLabel *mainHeader;

    //Invoice Information Box
    QGroupBox *invoiceInfoBox;
    QVBoxLayout *invoiceInfoBoxLayout;
    InvoiceInfoModel *invoiceInfoModel;
    QTableView *invoiceInfoView;

    //Agreement Parties Box
    QGroupBox *agreementPartiesBox;
    QVBoxLayout *agreementPartiesBoxLayout;
    QLabel *agreementPartiesHeader;
    AgreementPartiesModel *agreementPartiesModel;
    QTableView *agreementPartiesView;

    //Left Side Buttons
    QPushButton *saveButton;
    QPushButton *generatePdfButton;
    QPushButton *resetAgreementPartiesFormButton;
    QPushButton *resetAllButton;

    //RIGHT SIDE
    QGroupBox *rightSide;
    QVBoxLayout *rightLayout;
    QLabel *listOfGoodsHeader;
    TableOfGoodsModel *tableOfGoodsModel;
    QTableView *tableOfGoodsView;

    //Right Side Buttons
    QPushButton *addItemButton;
    QPushButton *removeItemButton;
    QPushButton *resetListOfGoodsButton;

};
#endif // MAINWINDOW_H
