#include "merchandise.h"

int Merchandise::numberOfGoods = 0;

Merchandise::Merchandise()
{
    ordinalNumber = QString::number(++numberOfGoods);
    quantity ="";
    serviceOrDescription = "";
    exchangeRate = "";
    unitNetPrice = "";
    netAmount = "";
    vatRate = "";
    vatAmount = "";
    grossAmount = "";
}

Merchandise::~Merchandise()
{
    --numberOfGoods;
}

QString Merchandise::getGrossAmount() const
{
    return grossAmount;
}

void Merchandise::setGrossAmount(QString value)
{
    grossAmount = value;
}

QString Merchandise::getOrdinalNumber()
{
    return ordinalNumber;
}

void Merchandise::setOrdinalNumber(QString value)
{
    ordinalNumber = value;
}

int Merchandise::getNumberOfGoods()
{
    return numberOfGoods;
}

void Merchandise::setNumberOfGoods(int value)
{
    numberOfGoods = value;
}

QString Merchandise::getVatAmount() const
{
    return vatAmount;
}

void Merchandise::setVatAmount(QString value)
{
    vatAmount = value;
}

QString Merchandise::getVatRate() const
{
    return vatRate;
}

void Merchandise::setVatRate(QString value)
{
    vatRate = value;
}

QString Merchandise::getNetAmount() const
{
    return netAmount;
}

void Merchandise::setNetAmount(QString value)
{
    netAmount = value;
}

QString Merchandise::getUnitNetPrice() const
{
    return unitNetPrice;
}

void Merchandise::setUnitNetPrice(QString value)
{
    unitNetPrice = value;
}

QString Merchandise::getExchangeRate() const
{
    return exchangeRate;
}

void Merchandise::setExchangeRate(QString value)
{
    exchangeRate = value;
}

QString Merchandise::getServiceOrDescription() const
{
    return serviceOrDescription;
}

void Merchandise::setServiceOrDescription(const QString &value)
{
    serviceOrDescription = value;
}

QString Merchandise::getQuantity() const
{
    return quantity;
}

void Merchandise::setQuantity(QString value)
{
    quantity = value;
}
