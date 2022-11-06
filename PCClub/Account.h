#pragma once
template <typename T>
class Account
{
    private:
        T id;
    public:
        Account(T id) : id(id)
        { }
        Account()
        { }
        T GetId() {
            return id;
        }
};

