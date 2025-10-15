/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:41 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 12:28:42 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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