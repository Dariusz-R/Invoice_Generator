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

    //LEFT SIDE BUTTONS
    void on_ResetAgreementPartiesFormButton_clicked();
    void on_SaveButton_clicked();
    void on_GeneratePdfButton_clicked();
    void on_ResetAllButton_clicked();

    //RIGHT SIDE BUTTONS
    void on_addItemButton_clicked();
    void on_RemoveItemButton_clicked();
    void on_ResetListOfGoodsButton_clicked();

private:

    void readSaveAndSetStyleSheet();
    void configureAndShowMainWindowContent();

    //Left Side
    void createLeftSide();
    void addInvoiceInfoView();
    void setUpInvoiceInfoViewSizes();
    void createAgreementPartiesBox();
    void setUpAgreementPartiesBoxSizes();
    void setUpAgreementPartiesHeaderSizes();
    void createAgreementPartiesView();
    void setUpAgreementPartiesViewSizes();
    void createLeftSideButtons();

    //Right Side
    void createRightSide();
    void setUpTableOfGoodsViewSizes();
    void createRightSideButtons();

//MEMBERS

    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QString styleSheetContent;

    //==================================
    //LEFT SIDE
    //==================================
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

    //Buttons
    QPushButton *saveButton;
    QPushButton *generatePdfButton;
    QPushButton *resetAgreementPartiesFormButton;
    QPushButton *resetAllButton;

    //==================================
    //RIGHT SIDE
    //==================================

    QGroupBox *rightSide;
    QVBoxLayout *rightLayout;

    //List of Goods Table
    QLabel *listOfGoodsHeader;
    TableOfGoodsModel *tableOfGoodsModel;
    QTableView *tableOfGoodsView;

    //Buttons
    QPushButton *addItemButton;
    QPushButton *removeItemButton;
    QPushButton *resetListOfGoodsButton;


};
#endif // MAINWINDOW_H
