#ifndef EXTRASTUFF_H
#define EXTRASTUFF_H

#include <fstream>

///
/// Хедър за добавяне на константи и функции, които нямат връзка с никой клас
///

/// Icons----------------------------------
const char CHARACTER_ICON = '@';
const char TROLL_ICON = '&';
const char ORC_ICON = '(';
const char HIGH_ELF_ICON = '+';
const char ILLIDARI_ICON = '=';
const char QUEST_ICON = '?';
const char FOUNTAIN_ICON = '*';
const char EMPTY_ICON = ' ';
const char WALL_ICON = '#';
const char WALL_GUI_CHAR = 219;
const char EXIT_ICON = '!';
const char TREASURE_ICON = '[';
const char GOLD_ICON = '$';
/// ----------------------------------------
/// Constants ------------------------------
const int WEAPON_ID = 1;
const int SHIELD_ID = 2;
const int ARMOR_ID = 3;
const int BUFFER_SIZE = 1024;
const int DEFAULT_NAME_SIZE = 64;
/// ----------------------------------------
/// Strings for exceptions -----------------
const char FILE_ERROR[] = "couldn't open file";
const char FATAL_ERROR[] = "FATAL ERROR";
const char MAP_COUNT_ERROR[] = "Invalid Map Count";
/// ----------------------------------------
/// UI Keys --------------------------------
const char MOVE_FORWARD = 'w';
const char MOVE_BACKWARDS = 's';
const char MOVE_LEFT = 'a';
const char MOVE_RIGHT = 'd';
const char EQUIP_KEY = 'e';
const char UNEQUIP_KEY = 'u';
const char SAVE_KEY = '0';
const char HELP_KEY = 'h';
const char BACKPACK_KEY = 'b';
const char EXIT_MENU = 'r';
/// ---------------------------------------
/// Functions -----------------------------
void clearScreen();
void popUpMenu(const char*);
void pressAnyKey();
///----------------------------------------

#endif // EXTRASTUFF_H INCLUDED
