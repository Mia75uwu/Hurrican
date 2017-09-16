#ifndef _TRIGGER_FLOATING_HPP_
#define _TRIGGER_FLOATING_HPP_

#include "GegnerClass.hpp"
#include "Gegner_Stuff.hpp"

class GegnerFloating : public GegnerClass
{
private :
    bool	playeron;

public:

    GegnerFloating	   (int Wert1,	int Wert2,			// Konstruktor
                        bool		  Light);
    void GegnerExplode (void);							// Gegner explodiert
    void DoKI		   (void);							// Gegner individuell mit seiner
    // eigenen kleinen KI bewegen
};

#endif