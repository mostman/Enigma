/***************************************************************
 * Name:      EnigmaApp.h
 * Purpose:   Defines Application Class
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#ifndef ENIGMAAPP_H
#define ENIGMAAPP_H

#include <wx/app.h>

class EnigmaApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ENIGMAAPP_H
