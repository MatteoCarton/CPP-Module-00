/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:38 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 12:28:39 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string name) {
    this->firstName = name;
}

std::string Contact::getFirstName(void) {
    return (this->firstName);
}

void Contact::setLastName(std::string name) {
    this->lastName = name;
}

std::string Contact::getLastName(void) {
    return (this->lastName);
}

void Contact::setNickname(std::string name) {
    this->nickname = name;
}

std::string Contact::getNickname(void) {
    return (this->nickname);
}
    
void Contact::setPhoneNumber(std::string name) {
    this->phoneNumber = name;
}

std::string Contact::getPhoneNumber(void) {
    return (this->phoneNumber);
}

void Contact::setDarkestSecret(std::string name) {
    this->darkestSecret = name;
}

std::string Contact::getDarkestSecret(void) {
    return (this->darkestSecret);
}
