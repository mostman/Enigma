/***************************************************************
 * Name:      EnigmaSettingsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "EnigmaSettingsApp.h"

//(*AppHeaders
#include "EnigmaSettingsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(EnigmaSettingsApp);

bool EnigmaSettingsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	EnigmaSettingsDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
