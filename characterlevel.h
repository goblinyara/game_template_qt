#ifndef CHARACTERLEVEL_H
#define CHARACTERLEVEL_H

#define DIFFICULTY 400
class CharacterLevel {
  public:
    CharacterLevel();
    ~CharacterLevel();
    void level_up(int x);
    void set_experience(int exp);
    void add_experience(int exp);
    void remove_experience(int exp);
    int get_level();
    int get_experience();
    void level_one_level();
    int exp_required(int level);

  private:
    int experience;
    int level;
};

#endif // CHARACTERLEVEL_H
