#ifndef INVOICE_H
#define INVOICE_H

#include "invoiceinfomodel.h"
#include "agreementpartiesmodel.h"
#include "tableofgoodsmodel.h"


class Invoice
{
public:
    Invoice();
    ~Invoice();

    InvoiceInfoModel *getInvoiceInfoModel() const;
    void setInvoiceInfoModel(InvoiceInfoModel *value);

    AgreementPartiesModel *getAgreementPartiesModel() const;
    void setAgreementPartiesModel(AgreementPartiesModel *value);

    TableOfGoodsModel *getTableOfGoodsModel() const;
    void setTableOfGoodsModel(TableOfGoodsModel *value);

private:

    InvoiceInfoModel *invoiceInfoModel;
    AgreementPartiesModel *agreementPartiesModel;
    TableOfGoodsModel *tableOfGoodsModel;

    QString pathToPdf;

};

#endif // INVOICE_H
