#pragma once
#include "../common_header.hpp"
#include "interface.hpp"

class AWeapon;
class gunFactory;

/**************************************/
class ACharacter
{
private:
    int stamina = 0;
public:
    int shoot();

protected:
    virtual unique_ptr<AWeapon> makeWeapon() = 0;
};

class gunner : public ACharacter
{
protected:
    unique_ptr<AWeapon> makeWeapon() override;
};

/**************************************/
class AWeapon
{
private:
    int damage = 0;
public:
    AWeapon(int dmg) : damage(dmg){};

    virtual int attack();
            int getDamage();
};

class gun : public AWeapon
{
private:
    unique_ptr<IComponent> sp = nullptr;
    unique_ptr<IComponentFactory> factory;
public:
    gun(int dmg, unique_ptr<IComponentFactory> f);
    int attack() override;
};


/**************************************/
class scope : public IComponent
{
private:
    int damage;
public:
    scope(int dmg): damage(dmg){};
    int getDamage() override;
};

/**************************************/
class gunFactory : public IComponentFactory
{
public:
    unique_ptr<IComponent> makeScope() override;
};