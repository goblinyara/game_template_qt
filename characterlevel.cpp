#include "characterlevel.h"

CharacterLevel::CharacterLevel() {
   this->experience = 0;
   this->level = 1;
}
void CharacterLevel::level_up(int x) {
  this->level = this->level + x;
}

void CharacterLevel::set_experience(int exp) {
 this->experience = exp;
 level_one_level();
}

void CharacterLevel::add_experience(int exp) {
  this->experience = this->experience + exp;
  level_one_level();
}

void CharacterLevel::remove_experience(int exp) {
  this->experience = this->experience - exp;
}

int CharacterLevel::get_level() {
  return this->level;
}

int CharacterLevel::get_experience() {
  return this->experience;
}

void CharacterLevel::level_one_level() {
  this->level = this->experience / (this->level * (this->level - 0.5) * DIFFICULTY);
}

int CharacterLevel::exp_required(int level) {
  return level * (level - 0.5) * DIFFICULTY;
}

CharacterLevel::~CharacterLevel() {

}
