//
// Created by michael on 09.01.19.
//

#ifndef CP_TASKS_USER_H
#define CP_TASKS_USER_H

#include <iostream>

//!  A User class.
/*!
  Class with id and name of user.
*/
class User {
    unsigned int id;
    std::string name, lastName;

public:
    //! An explicit constructor.
    /*!
      Creates a User named John Doe.
    */
    explicit User(unsigned int id);

    //! A constructor.
    /*!
      Creates a new known User.
    */
    User(unsigned int id, std::string name, std::string lastName);

    //! A bool equal_to const operator.
    /*!
      \param user an User argument.
      \return if users are equal or not.
    */
    bool operator==(const User &user) const;

    //! A getter.
    /*!
      \return user Id.
    */
    unsigned int getId() const;

    //! A getter.
    /*!
      \return user name.
    */
    std::string getName() const;

    //! A getter.
    /*!
      \return user last name.
    */
    std::string getLastName() const;
};

namespace std {

    //!  A std hash class.
    /*!
      Hash class for User.
    */
    template <>
    class hash<User> {
    public:
        //! An operator().
        /*!
          \param user an User argument.
          \return hash of user.
        */
        size_t operator()(const User &user) const;
    };
}

template <class T>
class BinarySize;

template <>
class BinarySize<User> {
public:
    static size_t size(const User &u);
};

#endif //CP_TASKS_USER_H
