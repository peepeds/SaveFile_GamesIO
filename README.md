Description

A program to handle a game save file

This program have a function to read a save file and n to save game data to a save file. The save data these parameter (with its data range):

1. Level, integer (between 1 to 99).
2. Skills, string and integer. The skill is not single data, but a maximum of 5 data. Each contain 
   a string  (the skill name) and an integer (skill level, range from 1 to 10).
3. Coins, integer (between 0 to 99.999).
4. Class, string (one of these: "Fighter", "Druid", "Monk", "Rogue", "Wizard", "Paladin", "Ranger", "
                  Cleric", "Warlock").

---


Explanation 

- This Program is build by C++ Programming Language 
- Since the save data consists of multiple parameters with different data types, we need to encapsulate
  it within a data structure, which is a struct.
- The validation function ensures that all parameters are valid according to the specified constraints.
- The write function is responsible for saving data to a data file.
  We use the ios::out flag to specify that the file should be opened for writing. 
  Additionally, the ios::trunc flag indicates that any existing data in the file should be overwritten with the new save data.
- The read function is responsible for reading data from the file named 'Data.naonwae'. 
  The data will be read as a single string line.
- The parsing parameter function will separate the parameters using the '#' delimiter and map each 
  original parameter as described in the Description. The data will then be returned as a single struct unit
- The display procedure will output each parameter contained within the struct

---

Link video : https://youtu.be/YoDI11SkJDI 
