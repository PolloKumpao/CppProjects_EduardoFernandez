#include <iostream>
#include <string>
#include <ctime>


enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX }; //Fuertemente tipado (enum class)

class Zombie;
class Player
{
public:
	Weapon weapon;
	float precision;
	int life;
	Player();

private:

	void attack(Zombie&Z) {
		int damage;
		switch (weapon) {
			case ::Weapon::FISTS:
				damage = 0;
				break;
			case ::Weapon::GUN:
				damage = 1;
				break;
			case :: Weapon::SHOTGUN:
				damage = 2;
				break;
			case:: Weapon::REVOLVER:
				damage = 3;
				break;
			case ::Weapon::SNIPER:
				damage = 4;
				break;
			case::Weapon::MACHINE_GUN:
				damage = 5;
				break;


		}
		damage = damage * precision;
		Z.life = Z.life - damage;
	}
	bool isAlive() {
		return life > 0;
	}
};

Player::Player():weapon(static_cast<Weapon>(rand()%6)),precision(rand()%20 / 10),life(rand()%101)
{
	
}


class Zombie
{
public:

	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	Zombie();


private:
	void attack(Player&P) {
		if (distanceToPlayer == 0) {
			P.life = P.life - damage;
		}
	}
	bool isAlive() {
		return life > 0;
	}

};

Zombie::Zombie() :distanceToPlayer(20 + rand() % 180), speed(rand() % 210 / 10),damage(rand()%210/10),life(rand()%101)
{
}
void main() {
	srand(time(nullptr));
	Player player;
	Zombie zombies[10];
	bool zombiesAreAlive(Zombie zombies){
		int i = 0;
		int aux = 0;
		while (i < 10){
			if (zombies[i].life > 0) {
				aux++;
			}
			i++;
		}
		return aux == 0;
	}
}