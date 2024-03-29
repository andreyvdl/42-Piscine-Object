#include "Account.hpp"

Account::Account(size_t id, double value): _id(id), _value(value) {};

Account::Account(Account const& that): _id(0), _value(0)
{
	*this = that;
}

Account&	Account::operator=(Account const& that)
{
	if (this != &that) {
		this->_id = that.getId();
		this->_value = that.getValue();
	}
	return *this;
}

Account::~Account() {};

size_t	Account::getId() const
{
	return this->_id;
}

double	Account::getValue() const
{
	return this->_value;
}

ostream&	operator<<(ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return p_os;
}
