#include <QHeaderView>
#include <QFile>

#include <QDebug>


#include "mainwindow.h"


//======================================================================
//CONSTRUCTORS===========================================================
//======================================================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new QWidget;
    mainWidget->setObjectName("mainWidget");
    mainLayout = new QHBoxLayout;
    readSaveAndSetStyleSheet();
    configureAndShowMainWindowContent();
}

//======================================================================
//DESCRUCTOR============================================================
//======================================================================

MainWindow::~MainWindow()
{
    delete mainWidget;
}

//======================================================================
//PUBLIC SLOTS==========================================================
//======================================================================

//LEFT SIDE BUTTONS

void MainWindow::on_AgreementPartiesResetSupplierButton_clicked()
{
    agreementPartiesModel->resetAgreementParty(AgreementPartiesModel::SupplierColumn);
}

void MainWindow::on_AgreementPartiesResetCustomerButton_clicked()
{
    agreementPartiesModel->resetAgreementParty(AgreementPartiesModel::CustomerColumn);
}

void MainWindow::on_SaveButton_clicked()
{
    currentInvoice = new Invoice;
    currentInvoice->setInvoiceInfoModel(invoiceInfoModel);
    currentInvoice->setAgreementPartiesModel(agreementPartiesModel);
    currentInvoice->setTableOfGoodsModel(tableOfGoodsModel);

}

void MainWindow::on_GeneratePdfButton_clicked()
{

}

void MainWindow::on_ResetAllButton_clicked()
{
    invoiceInfoModel->resetInvoiceInformation();
    agreementPartiesModel->resetAgreementParty(AgreementPartiesModel::SupplierColumn);
    agreementPartiesModel->resetAgreementParty(AgreementPartiesModel::CustomerColumn);
    tableOfGoodsModel->clearListOfGoods();

}

//RIGHT SIDE BUTTONS

void MainWindow::on_addItemButton_clicked()
{
    tableOfGoodsModel->addItem();
}

void MainWindow::on_RemoveItemButton_clicked()
{
    if(tableOfGoodsView->currentIndex().isValid())
        tableOfGoodsModel->removeRows(tableOfGoodsView->currentIndex().row(), 1);
}

void MainWindow::on_ResetListOfGoodsButton_clicked()
{

    tableOfGoodsModel->clearListOfGoods();

}

//======================================================================
//PRIVATE METHODS=======================================================
//======================================================================

void MainWindow::readSaveAndSetStyleSheet(){
    QFile file(":/styleSheet/style.qss");
    file.open(QFile::ReadOnly);
    styleSheetContent = QLatin1String(file.readAll());
    setStyleSheet(styleSheetContent);
    ensurePolished();
}


void MainWindow::configureAndShowMainWindowContent()
{
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    createLeftSide();
    createRightSide();

    mainLayout->addWidget(leftSide);
    mainLayout->addWidget(rightSide);


}


//LEFT SIDE ======================================================================================================================


void MainWindow::createLeftSide()
{
    leftSide = new QGroupBox;
    leftLayout = new QVBoxLayout;
    leftSide->setLayout(leftLayout);

    leftSide->setObjectName("leftSide");
    leftSide->setFixedWidth(600);


    leftLayout->setAlignment(Qt::AlignTop);

    mainHeader = new QLabel("NEW INVOICE");
    mainHeader->setObjectName("mainHeader");
    leftLayout->addWidget(mainHeader);

    addInvoiceInfoView();
    createAgreementPartiesBox();
    createLeftSideButtons();
    leftLayout->addStretch();


}

void MainWindow::addInvoiceInfoView()
{
    invoiceInfoModel = new InvoiceInfoModel;
    invoiceInfoView = new QTableView;
    invoiceInfoView->setModel(invoiceInfoModel);
    setUpInvoiceInfoViewSizes();
    leftLayout->addWidget(invoiceInfoView);
}

void MainWindow::setUpInvoiceInfoViewSizes()
{
    invoiceInfoView->setFixedSize(580,54);
    invoiceInfoView->verticalHeader()->hide();
    invoiceInfoView->horizontalHeader()->setSectionResizeMode(InvoiceInfoModel::InvoiceNumberColumn, QHeaderView::Stretch);
    invoiceInfoView->setColumnWidth(InvoiceInfoModel::DateOfIssueColumn, 100);
    invoiceInfoView->horizontalHeader()->setSectionResizeMode(InvoiceInfoModel::DateOfIssueColumn, QHeaderView::Fixed);
    invoiceInfoView->setColumnWidth(InvoiceInfoModel::DateOfPaymentColumn, 100);
    invoiceInfoView->horizontalHeader()->setSectionResizeMode(InvoiceInfoModel::DateOfPaymentColumn, QHeaderView::Fixed);
}

void MainWindow::createAgreementPartiesBox()
{
    agreementPartiesBox = new QGroupBox;
    setUpAgreementPartiesBoxSizes();

    agreementPartiesBoxLayout = new QVBoxLayout;
    agreementPartiesBoxLayout->setAlignment(Qt::AlignTop);

    agreementPartiesHeader = new QLabel("Agreement Parties");
    setUpAgreementPartiesHeaderSizes();
    agreementPartiesBoxLayout->addWidget(agreementPartiesHeader);

    createAgreementPartiesView();
    agreementPartiesBoxLayout->addWidget(agreementPartiesView);

    agreementPartiesBox->setLayout(agreementPartiesBoxLayout);

    leftLayout->addWidget(agreementPartiesBox);
}

void MainWindow::setUpAgreementPartiesBoxSizes()
{
    agreementPartiesBox->setFixedHeight(315);
    agreementPartiesBox->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
}

void MainWindow::setUpAgreementPartiesHeaderSizes()
{
    agreementPartiesHeader->setFixedHeight(25);
    agreementPartiesHeader->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
}

void MainWindow::createAgreementPartiesView()
{
    agreementPartiesModel = new AgreementPartiesModel;
    agreementPartiesView = new QTableView;
    agreementPartiesView->setModel(agreementPartiesModel);

    setUpAgreementPartiesViewSizes();

}

void MainWindow::setUpAgreementPartiesViewSizes()
{
    agreementPartiesView->setFixedSize(560,265);
    agreementPartiesView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    agreementPartiesView->verticalHeader()->setMinimumWidth(100);
    agreementPartiesView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    agreementPartiesView->horizontalHeader()->setSectionResizeMode(AgreementPartiesModel::SupplierColumn, QHeaderView::Stretch);
    agreementPartiesView->horizontalHeader()->setSectionResizeMode(AgreementPartiesModel::CustomerColumn, QHeaderView::Stretch);
}

void MainWindow::createLeftSideButtons()
{
    QHBoxLayout *leftSideResetButtonsLayout = new QHBoxLayout;
    resetSupplierFormButton = new QPushButton("Reset Supplier");
    leftSideResetButtonsLayout->addWidget(resetSupplierFormButton);
    connect(resetSupplierFormButton, SIGNAL(clicked()), this, SLOT(on_AgreementPartiesResetSupplierButton_clicked()));

    resetCustomerFormButton = new QPushButton("Reset Customer");
    leftSideResetButtonsLayout->addWidget(resetCustomerFormButton);
    connect(resetCustomerFormButton, SIGNAL(clicked()), this, SLOT(on_AgreementPartiesResetCustomerButton_clicked()));

    leftLayout->addLayout(leftSideResetButtonsLayout);

    saveButton = new QPushButton("Save");
    leftLayout->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(on_SaveButton_clicked()));

    generatePdfButton = new QPushButton("Generate PDF");
    leftLayout->addWidget(generatePdfButton);
    connect(generatePdfButton, SIGNAL(clicked()), this, SLOT(on_GeneratePdfButton_clicked()));

    resetAllButton = new QPushButton("Reset All");
    leftLayout->addWidget(resetAllButton);
    connect(resetAllButton, SIGNAL(clicked()), this, SLOT(on_ResetAllButton_clicked()));
}

//=================================================================================================================================
//RIGHT SIDE ======================================================================================================================
//=================================================================================================================================

void MainWindow::createRightSide()
{
    rightSide = new QGroupBox;
    leftSide->setObjectName("rightSide");
    rightSide->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));


    rightLayout = new QVBoxLayout;

    listOfGoodsHeader = new QLabel("List of Goods");
    rightLayout->addWidget(listOfGoodsHeader);

    tableOfGoodsModel = new TableOfGoodsModel;
    tableOfGoodsView = new QTableView;
    tableOfGoodsView->setModel(tableOfGoodsModel);
    setUpTableOfGoodsViewSizes();

    rightLayout->addWidget(tableOfGoodsView);

    createRightSideButtons();

    rightSide->setLayout(rightLayout);
}

void MainWindow::setUpTableOfGoodsViewSizes()
{
    tableOfGoodsView->setMinimumWidth(540);
    tableOfGoodsView->verticalHeader()->hide();
    tableOfGoodsView->horizontalHeader()->setSectionResizeMode(TableOfGoodsModel::OrdinalNumberColumn, QHeaderView::Fixed);
    tableOfGoodsView->setColumnWidth( TableOfGoodsModel::OrdinalNumberColumn, 20 );
    tableOfGoodsView->horizontalHeader()->setSectionResizeMode(TableOfGoodsModel::ServiceOrDescriptionColumn, QHeaderView::Stretch);
    for(short i = 2; i < tableOfGoodsModel->getNumberOfColumns(); ++i){
        tableOfGoodsView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        tableOfGoodsView->setColumnWidth( i, 60 );
    }
}

void MainWindow::createRightSideButtons()
{
    addItemButton = new QPushButton("Add Item");
    rightLayout->addWidget(addItemButton);
    connect(addItemButton, SIGNAL(clicked()), this, SLOT(on_addItemButton_clicked()));

    removeItemButton = new QPushButton("Remove Item");
    rightLayout->addWidget(removeItemButton);
    connect(removeItemButton, SIGNAL(clicked()), this, SLOT(on_RemoveItemButton_clicked()));

    resetListOfGoodsButton = new QPushButton("Reset List");
    rightLayout->addWidget(resetListOfGoodsButton);
    connect(resetListOfGoodsButton, SIGNAL(clicked()), this, SLOT(on_ResetListOfGoodsButton_clicked()));
}


