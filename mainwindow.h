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

    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QString styleSheetContent;




    //LEFT SIDE
    QGroupBox* leftSide;
    QVBoxLayout* leftLayout;

    QLabel* mainHeader;

            //Invoice Information Box
    QGroupBox* invoiceInfoBox;
    QVBoxLayout* invoiceInfoBoxLayout;
    InvoiceInfoModel* invoiceInfoModel;
    QTableView* invoiceInfoView;

            //Agreement Parties Box
    QGroupBox* agreementPartiesBox;
    QVBoxLayout* agreementPartiesBoxLayout;
    QLabel* agreementPartiesHeader;
    AgreementPartiesModel* agreementPartiesModel;
    QTableView* agreementPartiesView;

            //Left Side Buttons
    QPushButton* saveButton;
    QPushButton* generatePdfButton;

    //RIGHT SIDE
    QGroupBox* rightSide;
    QVBoxLayout* rightLayout;
    QLabel* listOfGoodsHeader;
    TableOfGoodsModel* tableOfGoodsModel;
    QTableView* tableOfGoodsView;
    QPushButton* addItemButton;
    QPushButton* removeItemButton;


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
};
#endif // MAINWINDOW_H
