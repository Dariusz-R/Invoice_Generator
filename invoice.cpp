#include "invoice.h"

Invoice::Invoice()
{

}

Invoice::~Invoice()
{
    delete invoiceInfoModel;
    delete agreementPartiesModel;
    delete tableOfGoodsModel;
}

InvoiceInfoModel *Invoice::getInvoiceInfoModel() const
{
    return invoiceInfoModel;
}

void Invoice::setInvoiceInfoModel(InvoiceInfoModel *value)
{
    invoiceInfoModel = value;
}

AgreementPartiesModel *Invoice::getAgreementPartiesModel() const
{
    return agreementPartiesModel;
}

void Invoice::setAgreementPartiesModel(AgreementPartiesModel *value)
{
    agreementPartiesModel = value;
}

TableOfGoodsModel *Invoice::getTableOfGoodsModel() const
{
    return tableOfGoodsModel;
}

void Invoice::setTableOfGoodsModel(TableOfGoodsModel *value)
{
    tableOfGoodsModel = value;
}
