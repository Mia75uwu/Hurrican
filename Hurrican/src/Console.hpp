// Datei : Console.hpp

// --------------------------------------------------------------------------------------
//
// Konsolen-Klasse für Hurrican
//
// (c) 2002 Jörg M. Winterstein
//
// --------------------------------------------------------------------------------------

#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

// --------------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------------

#include "DX8Font.hpp"
#include "DX8Input.hpp"
#include "DX8Sprite.hpp"
#include "Globals.hpp"

#include <bitset>

// --------------------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------------------

// DKS - Compensating for larger line spacing, which was too tight originally and allowed
//      only for small non-block cursor indicator:
//constexpr int MAX_LINES = 20;  // Anzahl der Zeilen in der Konsole
constexpr int MAX_LINES = 16;  // Anzahl der Zeilen in der Konsole
constexpr int MAX_CHARS = 90;  // Anzahl der Zeichen pro Zeile

// --------------------------------------------------------------------------------------
// Consolen-Klasse
// --------------------------------------------------------------------------------------

class ConsoleClass {
  private:
    float its_Alpha;                  // Aktueller Alphawert der Konsole
    float Fade;                       // Ein / Aus faden ?
    DirectGraphicsSprite ConsoleGFX;  // Grafik der Konsole
    bool Activate;                    // Aktivierungstaste gedrückt oder nicht
    char Text[MAX_LINES][MAX_CHARS];  // Text in der Konsole
    char Buffer[MAX_CHARS];
    std::bitset<256> Pressed;         // Für Tasten-lock

    bool CONSOLE_CHEAT(char *cheat);
    int GetIntFromBuffer(int index);
    // DKS - New console joystick support - CursorChar stores the candidate character (space by default)
    char CursorChar[2];

    inline bool CONSOLE_COMMAND(const char* command);
    inline bool CONSOLE_COMMAND_ARG(const char* command, int len);

  public:
    bool Active;        // Gerade aktiv ?
    bool Showing;       // Gerade angezeigt ?
    bool RenderBinary;  // Alles als 0 und 1 rendern (nur fun)

    ConsoleClass();   // Menu initialisieren und Grafiken laden
    ~ConsoleClass();  // Menu freigeben

    // DKS - ConsoleClass is now a static global, instead of dynamically allocated
    //      pointer, so moved the loading of sprites from its constructor to this new
    //      function:
    void LoadSprites();

    void ShowConsole();    // Menu anzeigen
    void Open();           // öffnen
    void Hide();           // verstecken
    void CheckInput();     // Wurde was eingegeben ?
    void CheckCommands();  // Text nach enter drücken checken
    void ScrollUp();       // Eine Zeile hochscrollen
    bool DoConsole();      // Alles machen, was die Console betrifft =)

    void print(const std::string &output);
    void print(const char *output);

    namespace Command {
      void Help();
      void Clear();
      void LevelInfo();
      void Quit();
    };
    namespace Cheat {
      void ExtraWeapons();
      void Time();
      void MaxWeapons();
      void Health();
      void Supershot();
      void Autofire();
      void FlameThrower();
      void GodMode();
      void WhellMode();
    };
};

// --------------------------------------------------------------------------------------
// Externals
// --------------------------------------------------------------------------------------

extern ConsoleClass Console;

#endif
