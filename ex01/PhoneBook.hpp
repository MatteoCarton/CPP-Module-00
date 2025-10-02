#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits.h>

class PhoneBook {
    private:
        Contact contact[8];
        int numberOfContact;
        int index;
    public:
        PhoneBook(void);
        void add(void);
        void search(void);
};

#endif 