#include "company.h"

//======================================================================
//CONSTRUCTORS==========================================================
//======================================================================

Company::Company()
{

}

//======================================================================
//PUBLIC METHODS========================================================
//======================================================================

QString Company::getPostalCode() const
{
    return postalCode;
}

void Company::setPostalCode(const QString &value)
{
    postalCode = value;
}

QString Company::getState() const
{
    return state;
}

void Company::setState(const QString &value)
{
    state = value;
}

QString Company::getHouseNumber() const
{
    return houseNumber;
}

void Company::setHouseNumber(const QString &value)
{
    houseNumber = value;
}

QString Company::getCity() const
{
    return city;
}

void Company::setCity(const QString &value)
{
    city = value;
}

QString Company::getStreet() const
{
    return street;
}

void Company::setStreet(const QString &value)
{
    street = value;
}

QString Company::getCountry() const
{
    return country;
}

void Company::setCountry(const QString &value)
{
    country = value;
}

QString Company::getFullName() const
{
    return fullName;
}

void Company::setFullName(const QString &value)
{
    fullName = value;
}

QString Company::getVatNumber() const
{
    return vatNumber;
}

void Company::setVatNumber(const QString &value)
{
    vatNumber = value;
}
