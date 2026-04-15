#include "pattern.hpp"

int ACharacter::shoot()
{
    cout << "shoot" << endl;
    unique_ptr<AWeapon> weapon = makeWeapon();
    return weapon->attack();
}

unique_ptr<AWeapon> gunner::makeWeapon()
{
    cout << "set gunner" <<endl;
    unique_ptr<IComponentFactory> factory = make_unique<gunFactory>();
    unique_ptr<AWeapon> ret =  make_unique<gun>(10, move(factory));
    return ret;
}

/**************************************/
int AWeapon::attack()
{
    cout << "weapon shoot" << endl;
    return damage;
}

int AWeapon::getDamage()
{
    return damage;
}

gun::gun(int dmg, unique_ptr<IComponentFactory> f) : AWeapon(dmg), factory(move(f))
{
    sp = factory->makeScope();
}

int gun::attack()
{
    cout << "gun shoot" <<endl;
    if(sp != nullptr) return getDamage() + sp->getDamage();
    return getDamage();
}

/**************************************/
int scope::getDamage()
{
    return damage;
}

/**************************************/
unique_ptr<IComponent> gunFactory::makeScope()
{
    return move(make_unique<scope>(22));
}