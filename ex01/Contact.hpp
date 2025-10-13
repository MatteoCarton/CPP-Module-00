#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void setFirstName(std::string name);
        std::string getFirstName(void);
        void setLastName(std::string name);
        std::string getLastName(void);
        void setNickname(std::string name);
        std::string getNickname(void);
        void setPhoneNumber(std::string name);
        std::string getPhoneNumber(void);
        void setDarkestSecret(std::string name);
        std::string getDarkestSecret(void);
};

#endif