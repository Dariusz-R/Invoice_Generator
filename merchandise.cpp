#include "merchandise.h"

int Merchandise::numberOfGoods = 0;

Merchandise::Merchandise()
{
     ordinalNumber = ++numberOfGoods;
     quantity = 0;
     serviceOrDescription = "";
     exchangeRate = 0;
     unitNetPrice = 0;
     netAmount = 0;
     vatRate = 0;
     vatAmount = 0;
     grossAmount = 0;
}

int Merchandise::getGrossAmount() const
{
    return grossAmount;
}

void Merchandise::setGrossAmount(int value)
{
    grossAmount = value;
}

int Merchandise::getOrdinalNumber()
{
    return ordinalNumber;
}

void Merchandise::setOrdinalNumber(int value)
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

int Merchandise::getVatAmount() const
{
    return vatAmount;
}

void Merchandise::setVatAmount(int value)
{
    vatAmount = value;
}

int Merchandise::getVatRate() const
{
    return vatRate;
}

void Merchandise::setVatRate(int value)
{
    vatRate = value;
}

int Merchandise::getNetAmount() const
{
    return netAmount;
}

void Merchandise::setNetAmount(int value)
{
    netAmount = value;
}

int Merchandise::getUnitNetPrice() const
{
    return unitNetPrice;
}

void Merchandise::setUnitNetPrice(int value)
{
    unitNetPrice = value;
}

int Merchandise::getExchangeRate() const
{
    return exchangeRate;
}

void Merchandise::setExchangeRate(int value)
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

int Merchandise::getQuantity() const
{
    return quantity;
}

void Merchandise::setQuantity(int value)
{
    quantity = value;
}
