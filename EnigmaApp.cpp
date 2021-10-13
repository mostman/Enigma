/***************************************************************
 * Name:      EnigmaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "EnigmaApp.h"

//(*AppHeaders
#include "EnigmaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(EnigmaApp);

bool EnigmaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	EnigmaFrame* Frame = new EnigmaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
