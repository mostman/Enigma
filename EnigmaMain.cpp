/***************************************************************
 * Name:      EnigmaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "EnigmaMain.h"
#include <wx/msgdlg.h>
// Get Settings Data
#include "EnigmaSettings/EnigmaSettingsMain.h"
// Get Plugboard Data
#include "EnigmaPlugBoard/EnigmaPlugBoardMain.h"

// Application version number
const wxString strVersion = "1.0";

//(*InternalHeaders(EnigmaFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(EnigmaFrame)
const long EnigmaFrame::ID_STATICTEXTROTORC = wxNewId();
const long EnigmaFrame::ID_CHOFFSETC = wxNewId();
const long EnigmaFrame::ID_STATICTEXTROTORB = wxNewId();
const long EnigmaFrame::ID_CHOFFSETB = wxNewId();
const long EnigmaFrame::ID_STATICTEXTROTORA = wxNewId();
const long EnigmaFrame::ID_CHOFFSETA = wxNewId();
const long EnigmaFrame::ID_STATICTEXTQ = wxNewId();
const long EnigmaFrame::ID_STATICTEXTW = wxNewId();
const long EnigmaFrame::ID_STATICTEXTE = wxNewId();
const long EnigmaFrame::ID_STATICTEXTR = wxNewId();
const long EnigmaFrame::ID_STATICTEXTT = wxNewId();
const long EnigmaFrame::ID_STATICTEXTZ = wxNewId();
const long EnigmaFrame::ID_STATICTEXTU = wxNewId();
const long EnigmaFrame::ID_STATICTEXTI = wxNewId();
const long EnigmaFrame::ID_STATICTEXTO = wxNewId();
const long EnigmaFrame::ID_STATICTEXTA = wxNewId();
const long EnigmaFrame::ID_STATICTEXTS = wxNewId();
const long EnigmaFrame::ID_STATICTEXTD = wxNewId();
const long EnigmaFrame::ID_STATICTEXTF = wxNewId();
const long EnigmaFrame::ID_STATICTEXTG = wxNewId();
const long EnigmaFrame::ID_STATICTEXTH = wxNewId();
const long EnigmaFrame::ID_STATICTEXTJ = wxNewId();
const long EnigmaFrame::ID_STATICTEXTK = wxNewId();
const long EnigmaFrame::ID_STATICTEXTP = wxNewId();
const long EnigmaFrame::ID_STATICTEXTY = wxNewId();
const long EnigmaFrame::ID_STATICTEXTX = wxNewId();
const long EnigmaFrame::ID_STATICTEXTC = wxNewId();
const long EnigmaFrame::ID_STATICTEXTV = wxNewId();
const long EnigmaFrame::ID_STATICTEXTB = wxNewId();
const long EnigmaFrame::ID_STATICTEXTN = wxNewId();
const long EnigmaFrame::ID_STATICTEXTM = wxNewId();
const long EnigmaFrame::ID_STATICTEXTL = wxNewId();
const long EnigmaFrame::ID_BTNQ = wxNewId();
const long EnigmaFrame::ID_BTNW = wxNewId();
const long EnigmaFrame::ID_BTNE = wxNewId();
const long EnigmaFrame::ID_BTNR = wxNewId();
const long EnigmaFrame::ID_BTNT = wxNewId();
const long EnigmaFrame::ID_BTNZ = wxNewId();
const long EnigmaFrame::ID_BTNU = wxNewId();
const long EnigmaFrame::ID_BTNI = wxNewId();
const long EnigmaFrame::ID_BTNO = wxNewId();
const long EnigmaFrame::ID_BTNA = wxNewId();
const long EnigmaFrame::ID_BTNS = wxNewId();
const long EnigmaFrame::ID_BTND = wxNewId();
const long EnigmaFrame::ID_BTNF = wxNewId();
const long EnigmaFrame::ID_BTNG = wxNewId();
const long EnigmaFrame::ID_BTNH = wxNewId();
const long EnigmaFrame::ID_BTNJ = wxNewId();
const long EnigmaFrame::ID_BTNK = wxNewId();
const long EnigmaFrame::ID_BTNP = wxNewId();
const long EnigmaFrame::ID_BTNY = wxNewId();
const long EnigmaFrame::ID_BTNX = wxNewId();
const long EnigmaFrame::ID_BTNC = wxNewId();
const long EnigmaFrame::ID_BTNV = wxNewId();
const long EnigmaFrame::ID_BTNB = wxNewId();
const long EnigmaFrame::ID_BTNN = wxNewId();
const long EnigmaFrame::ID_BTNM = wxNewId();
const long EnigmaFrame::ID_BTNL = wxNewId();
const long EnigmaFrame::ID_TEXTCTRLCLEAROUT = wxNewId();
const long EnigmaFrame::ID_TEXTCTRLENCRYPTEDOUT = wxNewId();
const long EnigmaFrame::idMenuSettings = wxNewId();
const long EnigmaFrame::idMenuPlug = wxNewId();
const long EnigmaFrame::idMenuReset = wxNewId();
const long EnigmaFrame::idMenuQuit = wxNewId();
const long EnigmaFrame::idMenuAbout = wxNewId();
const long EnigmaFrame::ID_STATUSBAR1 = wxNewId();
const long EnigmaFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EnigmaFrame,wxFrame)
    //(*EventTable(EnigmaFrame)
    //*)
END_EVENT_TABLE()

int EnigmaFrame::SetPlugs(wxString strPlugSet, int nPlugIndex)
{
    int nPlug;
    if (arrETW.Index(strPlugSet.Mid(nPlugIndex,1)) == nPlugIndex)
    {
        nPlug = -1;
    }
    else
    {
        nPlug = arrETW.Index(strPlugSet.Mid(nPlugIndex,1));
    }
    return nPlug;
}

wxString EnigmaFrame::GetPlugs(int nPlugSet, int nPlugIndex)
{
    wxString strPlugBoard;
    if (nPlugSet == -1)
    {
        strPlugBoard = arrETW.Item(nPlugIndex);
    }
    else
    {
        strPlugBoard = arrETW.Item(nPlugSet);
    }
    return strPlugBoard;
}

bool EnigmaFrame::StepRotor(wxString strNotch, int nOffSet)
{
    bool bStep = false;
    int nNotchCount = strNotch.Length();

    for (int i=0; i < nNotchCount; i++)
    {
        if (arrETW.Index(strNotch.Mid(i,1)) == nOffSet)
        {
            bStep = true;
            break;
        }
    }

    return bStep;
}

int EnigmaFrame::Rotor(wxArrayString arRotor, int nLetter, int nOffSet, int nRingSetting, bool bIn = true)
{
    int nRotorIndex;
    int nPos;
    int nEncryptedLetterIndex;
    int nETWCount = arrETW.Count();

    // Caesar shift (Calculate the OffSet and RingSettings)
    // https://en.wikipedia.org/wiki/Caesar_cipher
    nPos = (nLetter + nOffSet + (nETWCount - nRingSetting))%nETWCount;

    // In to the Rotor from ETW,Rotors and to Reflector
    if (bIn)
    {
        nRotorIndex = arrETW.Index(arRotor.Item(nPos));
    }
    // Back trough the Rotor from Reflector, Rotors and to the ETW
    else
    {
        nRotorIndex = arRotor.Index(arrETW.Item(nPos));
    }
    nEncryptedLetterIndex = (nRotorIndex + (nETWCount - nOffSet) + nRingSetting)%nETWCount;

    return nEncryptedLetterIndex;
}

void EnigmaFrame::Encryption(wxString strLetter)
{
    wxColour fBG = wxColour(234,116,12);
    int nLetIndex;
    int nEncryptedLetterIndex;
    int nETWCount = arrETW.Count();
    wxString strClear;
    wxString strEncrypted;

    // Get Offsets
    nOffsetA = ChOffSetA->GetCurrentSelection();
    nOffsetB = ChOffSetB->GetCurrentSelection();
    nOffsetC = ChOffSetC->GetCurrentSelection();

    // Step Rotor A
    ChOffSetA->SetSelection((ChOffSetA->GetCurrentSelection()+1)% nETWCount);
    // Rotor A Notch check
    if (StepRotor(strRotorNotchA,nOffsetA))
    {
        // Step Rotor B
        ChOffSetB->SetSelection((ChOffSetB->GetCurrentSelection()+1)% nETWCount);
        // Rotor B Notch check
        if (StepRotor(strRotorNotchB,nOffsetB))
        {
            // Step Rotor C
            ChOffSetC->SetSelection((ChOffSetC->GetCurrentSelection()+1)% nETWCount);
        }
    }
    // Check for double step
    else
    {
        // Rotor B Notch check
        if (StepRotor(strRotorNotchB,nOffsetB))
        {
           // Step Rotor B and C
            ChOffSetB->SetSelection((ChOffSetB->GetCurrentSelection()+1)% nETWCount);
            ChOffSetC->SetSelection((ChOffSetC->GetCurrentSelection()+1)% nETWCount);
        }
    }

    nCharCount++;
    // String Clear Text out
    strClear += TextCtrlClearout->GetValue()+strLetter;
    TextCtrlClearout->SetValue(strClear);

    // Get index of letter from ETW
    nLetIndex = arrETW.Index(strLetter);

    // PlugBoard
    nLetIndex = arrETW.Index(arrPlugBoard.Item(nLetIndex));

    // Rotor A
    nOffsetA = ChOffSetA->GetCurrentSelection();
    nEncryptedLetterIndex = Rotor(arrRotorA,nLetIndex,nOffsetA,nRingsetA);

    // Rotor B
    nOffsetB = ChOffSetB->GetCurrentSelection();
    nEncryptedLetterIndex = Rotor(arrRotorB,nEncryptedLetterIndex,nOffsetB,nRingsetB);

    // Rotor C
    nOffsetC = ChOffSetC->GetCurrentSelection();
    nEncryptedLetterIndex = Rotor(arrRotorC,nEncryptedLetterIndex,nOffsetC,nRingsetC);

    // Reflector
    nEncryptedLetterIndex = arrETW.Index(arrReflector.Item(nEncryptedLetterIndex));

    // Back Trought the Rotors again.
    // Rotor C
    nEncryptedLetterIndex = Rotor(arrRotorC,nEncryptedLetterIndex,nOffsetC,nRingsetC,false);

    // Rotor B
    nEncryptedLetterIndex = Rotor(arrRotorB,nEncryptedLetterIndex,nOffsetB,nRingsetB,false);

    // Rotor A
    nEncryptedLetterIndex = Rotor(arrRotorA,nEncryptedLetterIndex,nOffsetA,nRingsetA,false);

    // PlugBoard
    nEncryptedLetterIndex = arrETW.Index(arrPlugBoard.Item(nEncryptedLetterIndex));

    switch( nEncryptedLetterIndex )
    {
        case 0:
            StaticTextA->SetForegroundColour(fBG);
            break;
        case 1:
            StaticTextB->SetForegroundColour(fBG);
            break;
        case 2:
            StaticTextC->SetForegroundColour(fBG);
            break;
        case 3:
            StaticTextD->SetForegroundColour(fBG);
            break;
        case 4:
            StaticTextE->SetForegroundColour(fBG);
            break;
        case 5:
            StaticTextF->SetForegroundColour(fBG);
            break;
        case 6:
            StaticTextG->SetForegroundColour(fBG);
            break;
        case 7:
            StaticTextH->SetForegroundColour(fBG);
            break;
        case 8:
            StaticTextI->SetForegroundColour(fBG);
            break;
        case 9:
            StaticTextJ->SetForegroundColour(fBG);
            break;
        case 10:
            StaticTextK->SetForegroundColour(fBG);
            break;
        case 11:
            StaticTextL->SetForegroundColour(fBG);
            break;
        case 12:
            StaticTextM->SetForegroundColour(fBG);
            break;
        case 13:
            StaticTextN->SetForegroundColour(fBG);
            break;
        case 14:
            StaticTextO->SetForegroundColour(fBG);
            break;
        case 15:
            StaticTextP->SetForegroundColour(fBG);
            break;
        case 16:
            StaticTextQ->SetForegroundColour(fBG);
            break;
        case 17:
            StaticTextR->SetForegroundColour(fBG);
            break;
        case 18:
            StaticTextS->SetForegroundColour(fBG);
            break;
        case 19:
            StaticTextT->SetForegroundColour(fBG);
            break;
        case 20:
            StaticTextU->SetForegroundColour(fBG);
            break;
        case 21:
            StaticTextV->SetForegroundColour(fBG);
            break;
        case 22:
            StaticTextW->SetForegroundColour(fBG);
            break;
        case 23:
            StaticTextX->SetForegroundColour(fBG);
            break;
        case 24:
            StaticTextY->SetForegroundColour(fBG);
            break;
        case 25:
            StaticTextZ->SetForegroundColour(fBG);
            break;
    }
    // String Encrypted Text out
    strEncrypted += TextCtrlEncryptedOut->GetValue()+arrETW.Item(nEncryptedLetterIndex);

    // Fix Encrypted output text format "XXXXX XXXXX XXXXX" ext...
    /*
    if (((strEncrypted.length()%5) == 0) && (strEncrypted.length() == 5))
    {
        strEncrypted += wxT(" ");
    }
    if ( ((strEncrypted.length()%6) == 0) && (strEncrypted.length() >= 5) )
    {
        if ( ((strEncrypted.length()%5) == 1) && (strEncrypted.length() < 6) )
        {
            strEncrypted = strEncrypted.Left(5);
            strEncrypted += wxT(" ");
        }
        else if ( (strEncrypted.length() > 6) )
        {
            strEncrypted = strEncrypted.Left(strEncrypted.length()-1)+wxT(" ")+strEncrypted.Right(1);
        }
    }
    */
    if ((nCharCount%5) == 0)
    {
        strEncrypted += wxT(" ");
    }

    TextCtrlEncryptedOut->SetValue(strEncrypted);
}

wxArrayString EnigmaFrame::CreateRotors(wxString strRotor)
{
    wxArrayString arrRotor;
    int nRotorCount = strRotor.Length();
    for (int i=0; i < nRotorCount; i++)
    {
        arrRotor.Add(strRotor.Mid(i,1));
        //wxLogMessage(wxString::Format(wxT("Array Added: %s"), arrRotor.Item(i)));
    }
    return arrRotor;
}

EnigmaFrame::EnigmaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(EnigmaFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxGridBagSizer* GridBagSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizerRotorA;
    wxStaticBoxSizer* StaticBoxSizerRotorB;
    wxStaticBoxSizer* StaticBoxSizerRotorC;

    Create(parent, wxID_ANY, _("Enigma M3 simulator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("icon/enigma.xpm"))));
    	SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(1, 3, 0, 0);
    StaticBoxSizerRotorC = new wxStaticBoxSizer(wxVERTICAL, this, _("3rd Rotor"));
    StaticTextRotorC = new wxStaticText(this, ID_STATICTEXTROTORC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTROTORC"));
    StaticBoxSizerRotorC->Add(StaticTextRotorC, 0, wxALL|wxALIGN_LEFT, 5);
    ChOffSetC = new wxChoice(this, ID_CHOFFSETC, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOFFSETC"));
    ChOffSetC->SetSelection( ChOffSetC->Append(_("A")) );
    ChOffSetC->Append(_("B"));
    ChOffSetC->Append(_("C"));
    ChOffSetC->Append(_("D"));
    ChOffSetC->Append(_("E"));
    ChOffSetC->Append(_("F"));
    ChOffSetC->Append(_("G"));
    ChOffSetC->Append(_("H"));
    ChOffSetC->Append(_("I"));
    ChOffSetC->Append(_("J"));
    ChOffSetC->Append(_("K"));
    ChOffSetC->Append(_("L"));
    ChOffSetC->Append(_("M"));
    ChOffSetC->Append(_("N"));
    ChOffSetC->Append(_("O"));
    ChOffSetC->Append(_("P"));
    ChOffSetC->Append(_("Q"));
    ChOffSetC->Append(_("R"));
    ChOffSetC->Append(_("S"));
    ChOffSetC->Append(_("T"));
    ChOffSetC->Append(_("U"));
    ChOffSetC->Append(_("V"));
    ChOffSetC->Append(_("W"));
    ChOffSetC->Append(_("X"));
    ChOffSetC->Append(_("Y"));
    ChOffSetC->Append(_("Z"));
    StaticBoxSizerRotorC->Add(ChOffSetC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(StaticBoxSizerRotorC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizerRotorB = new wxStaticBoxSizer(wxVERTICAL, this, _("2nd Rotor"));
    StaticTextRotorB = new wxStaticText(this, ID_STATICTEXTROTORB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTROTORB"));
    StaticBoxSizerRotorB->Add(StaticTextRotorB, 0, wxALL|wxALIGN_LEFT, 5);
    ChOffSetB = new wxChoice(this, ID_CHOFFSETB, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOFFSETB"));
    ChOffSetB->SetSelection( ChOffSetB->Append(_("A")) );
    ChOffSetB->Append(_("B"));
    ChOffSetB->Append(_("C"));
    ChOffSetB->Append(_("D"));
    ChOffSetB->Append(_("E"));
    ChOffSetB->Append(_("F"));
    ChOffSetB->Append(_("G"));
    ChOffSetB->Append(_("H"));
    ChOffSetB->Append(_("I"));
    ChOffSetB->Append(_("J"));
    ChOffSetB->Append(_("K"));
    ChOffSetB->Append(_("L"));
    ChOffSetB->Append(_("M"));
    ChOffSetB->Append(_("N"));
    ChOffSetB->Append(_("O"));
    ChOffSetB->Append(_("P"));
    ChOffSetB->Append(_("Q"));
    ChOffSetB->Append(_("R"));
    ChOffSetB->Append(_("S"));
    ChOffSetB->Append(_("T"));
    ChOffSetB->Append(_("U"));
    ChOffSetB->Append(_("V"));
    ChOffSetB->Append(_("W"));
    ChOffSetB->Append(_("X"));
    ChOffSetB->Append(_("Y"));
    ChOffSetB->Append(_("Z"));
    StaticBoxSizerRotorB->Add(ChOffSetB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(StaticBoxSizerRotorB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizerRotorA = new wxStaticBoxSizer(wxVERTICAL, this, _("1st Rotor"));
    StaticTextRotorA = new wxStaticText(this, ID_STATICTEXTROTORA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTROTORA"));
    StaticBoxSizerRotorA->Add(StaticTextRotorA, 0, wxALL|wxALIGN_LEFT, 5);
    ChOffSetA = new wxChoice(this, ID_CHOFFSETA, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOFFSETA"));
    ChOffSetA->SetSelection( ChOffSetA->Append(_("A")) );
    ChOffSetA->Append(_("B"));
    ChOffSetA->Append(_("C"));
    ChOffSetA->Append(_("D"));
    ChOffSetA->Append(_("E"));
    ChOffSetA->Append(_("F"));
    ChOffSetA->Append(_("G"));
    ChOffSetA->Append(_("H"));
    ChOffSetA->Append(_("I"));
    ChOffSetA->Append(_("J"));
    ChOffSetA->Append(_("K"));
    ChOffSetA->Append(_("L"));
    ChOffSetA->Append(_("M"));
    ChOffSetA->Append(_("N"));
    ChOffSetA->Append(_("O"));
    ChOffSetA->Append(_("P"));
    ChOffSetA->Append(_("Q"));
    ChOffSetA->Append(_("R"));
    ChOffSetA->Append(_("S"));
    ChOffSetA->Append(_("T"));
    ChOffSetA->Append(_("U"));
    ChOffSetA->Append(_("V"));
    ChOffSetA->Append(_("W"));
    ChOffSetA->Append(_("X"));
    ChOffSetA->Append(_("Y"));
    ChOffSetA->Append(_("Z"));
    StaticBoxSizerRotorA->Add(ChOffSetA, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(StaticBoxSizerRotorA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(3, 1, 0, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticTextQ = new wxStaticText(this, ID_STATICTEXTQ, _("Q"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTQ"));
    wxFont StaticTextQFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextQ->SetFont(StaticTextQFont);
    BoxSizer2->Add(StaticTextQ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextW = new wxStaticText(this, ID_STATICTEXTW, _("W"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTW"));
    wxFont StaticTextWFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextW->SetFont(StaticTextWFont);
    BoxSizer2->Add(StaticTextW, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextE = new wxStaticText(this, ID_STATICTEXTE, _("E"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTE"));
    wxFont StaticTextEFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextE->SetFont(StaticTextEFont);
    BoxSizer2->Add(StaticTextE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextR = new wxStaticText(this, ID_STATICTEXTR, _("R"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTR"));
    wxFont StaticTextRFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextR->SetFont(StaticTextRFont);
    BoxSizer2->Add(StaticTextR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextT = new wxStaticText(this, ID_STATICTEXTT, _("T"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTT"));
    wxFont StaticTextTFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextT->SetFont(StaticTextTFont);
    BoxSizer2->Add(StaticTextT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextZ = new wxStaticText(this, ID_STATICTEXTZ, _("Z"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTZ"));
    wxFont StaticTextZFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextZ->SetFont(StaticTextZFont);
    BoxSizer2->Add(StaticTextZ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextU = new wxStaticText(this, ID_STATICTEXTU, _("U"), wxDefaultPosition, wxDefaultSize, wxBORDER_DOUBLE, _T("ID_STATICTEXTU"));
    wxFont StaticTextUFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextU->SetFont(StaticTextUFont);
    BoxSizer2->Add(StaticTextU, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextI = new wxStaticText(this, ID_STATICTEXTI, _("I"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTI"));
    wxFont StaticTextIFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextI->SetFont(StaticTextIFont);
    BoxSizer2->Add(StaticTextI, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextO = new wxStaticText(this, ID_STATICTEXTO, _("O"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTO"));
    wxFont StaticTextOFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextO->SetFont(StaticTextOFont);
    BoxSizer2->Add(StaticTextO, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticTextA = new wxStaticText(this, ID_STATICTEXTA, _("A"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTA"));
    wxFont StaticTextAFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextA->SetFont(StaticTextAFont);
    BoxSizer3->Add(StaticTextA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextS = new wxStaticText(this, ID_STATICTEXTS, _("S"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTS"));
    wxFont StaticTextSFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextS->SetFont(StaticTextSFont);
    BoxSizer3->Add(StaticTextS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextD = new wxStaticText(this, ID_STATICTEXTD, _("D"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTD"));
    wxFont StaticTextDFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextD->SetFont(StaticTextDFont);
    BoxSizer3->Add(StaticTextD, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextF = new wxStaticText(this, ID_STATICTEXTF, _("F"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTF"));
    wxFont StaticTextFFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextF->SetFont(StaticTextFFont);
    BoxSizer3->Add(StaticTextF, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextG = new wxStaticText(this, ID_STATICTEXTG, _("G"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTG"));
    wxFont StaticTextGFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextG->SetFont(StaticTextGFont);
    BoxSizer3->Add(StaticTextG, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextH = new wxStaticText(this, ID_STATICTEXTH, _("H"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTH"));
    wxFont StaticTextHFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextH->SetFont(StaticTextHFont);
    BoxSizer3->Add(StaticTextH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextJ = new wxStaticText(this, ID_STATICTEXTJ, _("J"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTJ"));
    wxFont StaticTextJFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextJ->SetFont(StaticTextJFont);
    BoxSizer3->Add(StaticTextJ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextK = new wxStaticText(this, ID_STATICTEXTK, _("K"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTK"));
    wxFont StaticTextKFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextK->SetFont(StaticTextKFont);
    BoxSizer3->Add(StaticTextK, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticTextP = new wxStaticText(this, ID_STATICTEXTP, _("P"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTP"));
    wxFont StaticTextPFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextP->SetFont(StaticTextPFont);
    BoxSizer4->Add(StaticTextP, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextY = new wxStaticText(this, ID_STATICTEXTY, _("Y"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTY"));
    wxFont StaticTextYFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextY->SetFont(StaticTextYFont);
    BoxSizer4->Add(StaticTextY, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextX = new wxStaticText(this, ID_STATICTEXTX, _("X"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTX"));
    wxFont StaticTextXFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextX->SetFont(StaticTextXFont);
    BoxSizer4->Add(StaticTextX, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextC = new wxStaticText(this, ID_STATICTEXTC, _("C"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTC"));
    wxFont StaticTextCFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextC->SetFont(StaticTextCFont);
    BoxSizer4->Add(StaticTextC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextV = new wxStaticText(this, ID_STATICTEXTV, _("V"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTV"));
    wxFont StaticTextVFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextV->SetFont(StaticTextVFont);
    BoxSizer4->Add(StaticTextV, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextB = new wxStaticText(this, ID_STATICTEXTB, _("B"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTB"));
    wxFont StaticTextBFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextB->SetFont(StaticTextBFont);
    BoxSizer4->Add(StaticTextB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextN = new wxStaticText(this, ID_STATICTEXTN, _("N"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTN"));
    wxFont StaticTextNFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextN->SetFont(StaticTextNFont);
    BoxSizer4->Add(StaticTextN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextM = new wxStaticText(this, ID_STATICTEXTM, _("M"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTM"));
    wxFont StaticTextMFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextM->SetFont(StaticTextMFont);
    BoxSizer4->Add(StaticTextM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextL = new wxStaticText(this, ID_STATICTEXTL, _("L"), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN, _T("ID_STATICTEXTL"));
    wxFont StaticTextLFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTextL->SetFont(StaticTextLFont);
    BoxSizer4->Add(StaticTextL, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 1, 0, 0);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BtnQ = new wxButton(this, ID_BTNQ, _("Q"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNQ"));
    BoxSizer5->Add(BtnQ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnW = new wxButton(this, ID_BTNW, _("W"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNW"));
    BoxSizer5->Add(BtnW, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnE = new wxButton(this, ID_BTNE, _("E"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNE"));
    BoxSizer5->Add(BtnE, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnR = new wxButton(this, ID_BTNR, _("R"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNR"));
    BoxSizer5->Add(BtnR, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnT = new wxButton(this, ID_BTNT, _("T"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNT"));
    BoxSizer5->Add(BtnT, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnZ = new wxButton(this, ID_BTNZ, _("Z"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNZ"));
    BoxSizer5->Add(BtnZ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnU = new wxButton(this, ID_BTNU, _("U"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNU"));
    BoxSizer5->Add(BtnU, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnI = new wxButton(this, ID_BTNI, _("I"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNI"));
    BoxSizer5->Add(BtnI, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnO = new wxButton(this, ID_BTNO, _("O"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNO"));
    BoxSizer5->Add(BtnO, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    FlexGridSizer3->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BtnA = new wxButton(this, ID_BTNA, _("A"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNA"));
    BoxSizer6->Add(BtnA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnS = new wxButton(this, ID_BTNS, _("S"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNS"));
    BoxSizer6->Add(BtnS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnD = new wxButton(this, ID_BTND, _("D"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTND"));
    BoxSizer6->Add(BtnD, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnF = new wxButton(this, ID_BTNF, _("F"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNF"));
    BoxSizer6->Add(BtnF, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnG = new wxButton(this, ID_BTNG, _("G"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNG"));
    BoxSizer6->Add(BtnG, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnH = new wxButton(this, ID_BTNH, _("H"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNH"));
    BoxSizer6->Add(BtnH, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnJ = new wxButton(this, ID_BTNJ, _("J"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNJ"));
    BoxSizer6->Add(BtnJ, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnK = new wxButton(this, ID_BTNK, _("K"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNK"));
    BoxSizer6->Add(BtnK, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    FlexGridSizer3->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BtnP = new wxButton(this, ID_BTNP, _("P"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNP"));
    BoxSizer7->Add(BtnP, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnY = new wxButton(this, ID_BTNY, _("Y"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNY"));
    BoxSizer7->Add(BtnY, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnX = new wxButton(this, ID_BTNX, _("X"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNX"));
    BoxSizer7->Add(BtnX, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnC = new wxButton(this, ID_BTNC, _("C"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNC"));
    BoxSizer7->Add(BtnC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnV = new wxButton(this, ID_BTNV, _("V"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNV"));
    BoxSizer7->Add(BtnV, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnB = new wxButton(this, ID_BTNB, _("B"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNB"));
    BoxSizer7->Add(BtnB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnN = new wxButton(this, ID_BTNN, _("N"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNN"));
    BoxSizer7->Add(BtnN, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnM = new wxButton(this, ID_BTNM, _("M"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNM"));
    BoxSizer7->Add(BtnM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BtnL = new wxButton(this, ID_BTNL, _("L"), wxDefaultPosition, wxSize(25,25), 0, wxDefaultValidator, _T("ID_BTNL"));
    BoxSizer7->Add(BtnL, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    FlexGridSizer3->Add(BoxSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    TextCtrlClearout = new wxTextCtrl(this, ID_TEXTCTRLCLEAROUT, wxEmptyString, wxDefaultPosition, wxSize(270,25), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRLCLEAROUT"));
    BoxSizer1->Add(TextCtrlClearout, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEncryptedOut = new wxTextCtrl(this, ID_TEXTCTRLENCRYPTEDOUT, wxEmptyString, wxDefaultPosition, wxSize(270,25), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRLENCRYPTEDOUT"));
    BoxSizer1->Add(TextCtrlEncryptedOut, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(BoxSizer1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    FlexGridSizer1->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemSettings = new wxMenuItem(Menu1, idMenuSettings, _("Settings\tAlt+S"), _("Change rotors, Reflctor, Ringsettings and Position"), wxITEM_NORMAL);
    Menu1->Append(MenuItemSettings);
    MenuItemPlugBoard = new wxMenuItem(Menu1, idMenuPlug, _("Plugboard\tAlt+P"), _("Set plugboard plugs"), wxITEM_NORMAL);
    Menu1->Append(MenuItemPlugBoard);
    MenuItemReset = new wxMenuItem(Menu1, idMenuReset, _("Reset\tAlt+R"), _("Reset everything"), wxITEM_NORMAL);
    Menu1->Append(MenuItemReset);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(500, true);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BTNQ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnQClick);
    Connect(ID_BTNW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnWClick);
    Connect(ID_BTNE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnEClick);
    Connect(ID_BTNR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnRClick);
    Connect(ID_BTNT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnTClick);
    Connect(ID_BTNZ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnZClick);
    Connect(ID_BTNU,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnUClick);
    Connect(ID_BTNI,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnIClick);
    Connect(ID_BTNO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnOClick);
    Connect(ID_BTNA,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnAClick);
    Connect(ID_BTNS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnSClick);
    Connect(ID_BTND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnDClick);
    Connect(ID_BTNF,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnFClick);
    Connect(ID_BTNG,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnGClick);
    Connect(ID_BTNH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnHClick);
    Connect(ID_BTNJ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnJClick);
    Connect(ID_BTNK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnKClick);
    Connect(ID_BTNP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnPClick);
    Connect(ID_BTNY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnYClick);
    Connect(ID_BTNX,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnXClick);
    Connect(ID_BTNC,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnCClick);
    Connect(ID_BTNV,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnVClick);
    Connect(ID_BTNB,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnBClick);
    Connect(ID_BTNN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnNClick);
    Connect(ID_BTNM,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnMClick);
    Connect(ID_BTNL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaFrame::OnBtnLClick);
    Connect(idMenuSettings,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EnigmaFrame::OnMenuItemSettings);
    Connect(idMenuPlug,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EnigmaFrame::OnMenuItemPlugBoard);
    Connect(idMenuReset,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EnigmaFrame::OnMenuItemReset);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EnigmaFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EnigmaFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&EnigmaFrame::OnTimer1Trigger);
    //*)

    // Rotor Name List
    arrRotorSet.Add("I");
    arrRotorSet.Add("II");
    arrRotorSet.Add("III");
    arrRotorSet.Add("IV");
    arrRotorSet.Add("V");
    arrRotorSet.Add("VI");
    arrRotorSet.Add("VII");
    arrRotorSet.Add("VIII");

    // Default Rotors & Reflector
    nRotorA=2;    // Rotor III
    nOffsetA=0;
    nRingsetA=0;  // RingSetting

    nRotorB=1;    // Rotor II
    nOffsetB=0;
    nRingsetB=0;  // RingSetting

    nRotorC=0;    // Rotor I
    nOffsetC=0;
    nRingsetC=0;  // RingSetting

    nReflector=0; // Reflector UKW-B

    StaticTextRotorA->SetLabel(arrRotorSet.Item(nRotorA));
    StaticTextRotorB->SetLabel(arrRotorSet.Item(nRotorB));
    StaticTextRotorC->SetLabel(arrRotorSet.Item(nRotorC));

    // Initialize ETW, Rotor and Reflector maps.
    // ETW
    strETW = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // PlugBoard
    //strPlugs = wxT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strPlugs = strETW; // No plugs Connected

    // No Plugs Connected default
    PlugsCount = wxT("0");

    // Rotor I
    strRotor1 = wxT("EKMFLGDQVZNTOWYHXUSPAIBRCJ");

    // Rotor II
    strRotor2 = wxT("AJDKSIRUXBLHWTMCQGZNPYFVOE");

    // Rotor III
    strRotor3 = wxT("BDFHJLCPRTXVZNYEIWGAKMUSQO");

    // Rotor IV
    strRotor4 = wxT("ESOVPZJAYQUIRHXLNFTGKDCMWB");

    // Rotor V
    strRotor5 = wxT("VZBRGITYUPSDNHLXAWMJQOFECK");

    // Rotor VI
    strRotor6 = wxT("JPGVOUMFYQBENHZRDKASXLICTW");

    // Rotor VII
    strRotor7 = wxT("NZJHGRCXMYSWBOUFAIVLPEKQDT");

    // Rotor VIII
    strRotor8 = wxT("FKQHTLXOCBJSPDZRAMEWNIUYGV");

    // Rotors Notch Positions
    strNotchRotor1 = wxT("Q");   // Rotor 1 Notch Position (Q)
    strNotchRotor2 = wxT("E");   // Rotor 2 Notch Position (E)
    strNotchRotor3 = wxT("V");   // Rotor 3 Notch Position (V)
    strNotchRotor4 = wxT("J");   // Rotor 4 Notch Position (J)
    strNotchRotor5 = wxT("Z");   // Rotor 5 Notch Position (Z)
    strNotchRotor678 = wxT("ZM"); // Rotor 6, 7 & 8 Notch Position (ZM)

    // ReflectorB (UKW-B)
    strReflectorB = wxT("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // ReflectorC (UKW-C)
    strReflectorC = wxT("FVPJIAOYEDRZXWGCTKUQSBNMHL");

    // Build the arrays
    arrPlugBoard = CreateRotors(strPlugs);
    arrETW = CreateRotors(strETW);
    arrRotorC = CreateRotors(strRotor1);
    arrRotorB = CreateRotors(strRotor2);
    strRotorNotchB = strNotchRotor2;
    arrRotorA = CreateRotors(strRotor3);
    strRotorNotchA = strNotchRotor3;
    arrReflector = CreateRotors(strReflectorB);
}

EnigmaFrame::~EnigmaFrame()
{
    //(*Destroy(EnigmaFrame)
    //*)
}

void EnigmaFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void EnigmaFrame::OnAbout(wxCommandEvent& event)
{
    wxString strAuthor = wxString::FromUTF8("Martin Östman");
    wxString msg = wxbuildinfo(long_f);

    wxString title = "About Enigma M3 simulator";
    wxString message =
        "Enigma M3 simulator Version "+strVersion+"\n"
        +"The Enigma M3 was commonly used by the German Navy (Kriegsmarine) during WWII\n\n"
        +msg+"\n\n"
        "Created by (C) 2021 "+strAuthor+"\n";

    wxMessageBox(message, title, wxICON_INFORMATION|wxOK);
}

void EnigmaFrame::OnMenuItemSettings(wxCommandEvent& event)
{
    EnigmaSettingsDialog SettingsDialog(NULL, ID_ENIGMASETTINGS_DIAG);


    // Send Data to SettingsDialog
    nOffsetA = ChOffSetA->GetSelection();
    SettingsDialog.SetnRotorA(nRotorA);
    SettingsDialog.SetnOffsetA(nOffsetA);
    SettingsDialog.SetnRingsetA(nRingsetA);

    nOffsetB = ChOffSetB->GetSelection();
    SettingsDialog.SetnRotorB(nRotorB);
    SettingsDialog.SetnOffsetB(nOffsetB);
    SettingsDialog.SetnRingsetB(nRingsetB);

    nOffsetC = ChOffSetC->GetSelection();
    SettingsDialog.SetnRotorC(nRotorC);
    SettingsDialog.SetnOffsetC(nOffsetC);
    SettingsDialog.SetnRingsetC(nRingsetC);

    SettingsDialog.SetnReflector(nReflector);

    // Get Data from SettingsDialog
    if (SettingsDialog.ShowModal() == wxID_OK)
    {
        nRotorA = SettingsDialog.GetnRotorA();
        nOffsetA = SettingsDialog.GetnOffsetA();
        ChOffSetA->SetSelection(nOffsetA);
        nRingsetA = SettingsDialog.GetnRingsetA();

        nRotorB = SettingsDialog.GetnRotorB();
        nOffsetB = SettingsDialog.GetnOffsetB();
        ChOffSetB->SetSelection(nOffsetB);
        nRingsetB = SettingsDialog.GetnRingsetB();

        nRotorC = SettingsDialog.GetnRotorC();
        nOffsetC = SettingsDialog.GetnOffsetC();
        ChOffSetC->SetSelection(nOffsetC);
        nRingsetC = SettingsDialog.GetnRingsetC();

        nReflector = SettingsDialog.GetnReflector();

        // Set Current Rotors in RotorLabels
        StaticTextRotorA->SetLabel(arrRotorSet.Item(nRotorA));
        StaticTextRotorB->SetLabel(arrRotorSet.Item(nRotorB));
        StaticTextRotorC->SetLabel(arrRotorSet.Item(nRotorC));
    }

    // Set Current Rotor A
    switch(nRotorA)
    {
        case 0:
            arrRotorA = CreateRotors(strRotor1);
            strRotorNotchA = strNotchRotor1;
            break;
        case 1:
            arrRotorA = CreateRotors(strRotor2);
            strRotorNotchA = strNotchRotor2;
            break;
        case 2:
            arrRotorA = CreateRotors(strRotor3);
            strRotorNotchA = strNotchRotor3;
            break;
        case 3:
            arrRotorA = CreateRotors(strRotor4);
            strRotorNotchA = strNotchRotor4;
           break;
        case 4:
            arrRotorA = CreateRotors(strRotor5);
            strRotorNotchA = strNotchRotor5;
            break;
        case 5:
            arrRotorA = CreateRotors(strRotor6);
            strRotorNotchA = strNotchRotor678;
            break;
        case 6:
            arrRotorA = CreateRotors(strRotor7);
            strRotorNotchA = strNotchRotor678;
            break;
        case 7:
            arrRotorA = CreateRotors(strRotor8);
            strRotorNotchA = strNotchRotor678;
            break;
        default:
            arrRotorA = CreateRotors(strRotor3);
            strRotorNotchA = strNotchRotor3;
    }

    // Set Current Rotor B
    switch(nRotorB)
    {
        case 0:
            arrRotorB = CreateRotors(strRotor1);
            strRotorNotchB = strNotchRotor1;
            break;
        case 1:
            arrRotorB = CreateRotors(strRotor2);
            strRotorNotchB = strNotchRotor2;
            break;
        case 2:
            arrRotorB = CreateRotors(strRotor3);
            strRotorNotchB = strNotchRotor3;
            break;
        case 3:
            arrRotorB = CreateRotors(strRotor4);
            strRotorNotchB = strNotchRotor4;
            break;
        case 4:
            arrRotorB = CreateRotors(strRotor5);
            strRotorNotchB = strNotchRotor5;
            break;
        case 5:
            arrRotorB = CreateRotors(strRotor6);
            strRotorNotchB = strNotchRotor678;
            break;
        case 6:
            arrRotorB = CreateRotors(strRotor7);
            strRotorNotchB = strNotchRotor678;
            break;
        case 7:
            arrRotorB = CreateRotors(strRotor8);
            strRotorNotchB = strNotchRotor678;
            break;
        default:
            arrRotorB = CreateRotors(strRotor2);
            strRotorNotchB = strNotchRotor2;
    }

    // Set Current Rotor C
    switch(nRotorC)
    {
        case 0:
            arrRotorC = CreateRotors(strRotor1);
            break;
        case 1:
            arrRotorC = CreateRotors(strRotor2);
            break;
        case 2:
            arrRotorC = CreateRotors(strRotor3);
            break;
        case 3:
            arrRotorC = CreateRotors(strRotor4);
            break;
        case 4:
            arrRotorC = CreateRotors(strRotor5);
            break;
        case 5:
            arrRotorC = CreateRotors(strRotor6);
            break;
        case 6:
            arrRotorC = CreateRotors(strRotor7);
            break;
        case 7:
            arrRotorC = CreateRotors(strRotor8);
            break;
        default:
            arrRotorC = CreateRotors(strRotor1);
    }

    // Set Current Reflector
    switch(nReflector)
    {
        case 0:
            arrReflector = CreateRotors(strReflectorB);
            break;
        case 1:
            arrReflector = CreateRotors(strReflectorC);
            break;
        default:
            arrReflector = CreateRotors(strReflectorB);
    }
}

void EnigmaFrame::OnBtnAClick(wxCommandEvent& event)
{
    Encryption("A");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnBClick(wxCommandEvent& event)
{
    Encryption("B");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnCClick(wxCommandEvent& event)
{
    Encryption("C");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnDClick(wxCommandEvent& event)
{
    Encryption("D");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnEClick(wxCommandEvent& event)
{
    Encryption("E");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnFClick(wxCommandEvent& event)
{
    Encryption("F");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnGClick(wxCommandEvent& event)
{
    Encryption("G");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnHClick(wxCommandEvent& event)
{
    Encryption("H");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnIClick(wxCommandEvent& event)
{
    Encryption("I");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnJClick(wxCommandEvent& event)
{
    Encryption("J");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnKClick(wxCommandEvent& event)
{
    Encryption("K");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnLClick(wxCommandEvent& event)
{
    Encryption("L");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnMClick(wxCommandEvent& event)
{
    Encryption("M");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnNClick(wxCommandEvent& event)
{
    Encryption("N");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnOClick(wxCommandEvent& event)
{
    Encryption("O");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnPClick(wxCommandEvent& event)
{
    Encryption("P");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnQClick(wxCommandEvent& event)
{
    Encryption("Q");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnRClick(wxCommandEvent& event)
{
    Encryption("R");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnSClick(wxCommandEvent& event)
{
    Encryption("S");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnTClick(wxCommandEvent& event)
{
    Encryption("T");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnUClick(wxCommandEvent& event)
{
    Encryption("U");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnVClick(wxCommandEvent& event)
{
    Encryption("V");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnWClick(wxCommandEvent& event)
{
    Encryption("W");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnXClick(wxCommandEvent& event)
{
    Encryption("X");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnYClick(wxCommandEvent& event)
{
    Encryption("Y");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnBtnZClick(wxCommandEvent& event)
{
    Encryption("Z");
    Timer1.Start(500,true);
}

void EnigmaFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    wxColour fBG = wxColour(0,0,0);
    StaticTextQ->SetForegroundColour(fBG );
    StaticTextW->SetForegroundColour(fBG );
    StaticTextE->SetForegroundColour(fBG );
    StaticTextR->SetForegroundColour(fBG );
    StaticTextT->SetForegroundColour(fBG );
    StaticTextZ->SetForegroundColour(fBG );
    StaticTextU->SetForegroundColour(fBG );
    StaticTextI->SetForegroundColour(fBG );
    StaticTextO->SetForegroundColour(fBG );
    StaticTextA->SetForegroundColour(fBG );
    StaticTextS->SetForegroundColour(fBG );
    StaticTextD->SetForegroundColour(fBG );
    StaticTextF->SetForegroundColour(fBG );
    StaticTextG->SetForegroundColour(fBG );
    StaticTextH->SetForegroundColour(fBG );
    StaticTextJ->SetForegroundColour(fBG );
    StaticTextK->SetForegroundColour(fBG );
    StaticTextP->SetForegroundColour(fBG );
    StaticTextY->SetForegroundColour(fBG );
    StaticTextX->SetForegroundColour(fBG );
    StaticTextC->SetForegroundColour(fBG );
    StaticTextV->SetForegroundColour(fBG );
    StaticTextB->SetForegroundColour(fBG );
    StaticTextN->SetForegroundColour(fBG );
    StaticTextM->SetForegroundColour(fBG );
    StaticTextL->SetForegroundColour(fBG );
}

void EnigmaFrame::OnMenuItemPlugBoard(wxCommandEvent& event)
{
    EnigmaPlugBoardDialog PlugBoardDialog(NULL, ID_ENIGMASETTINGS_DIAG);

    // Send Data to PlugBoardDialog
    PlugBoardDialog.SetnPlugA(SetPlugs(strPlugs,0));
    PlugBoardDialog.SetnPlugB(SetPlugs(strPlugs,1));
    PlugBoardDialog.SetnPlugC(SetPlugs(strPlugs,2));
    PlugBoardDialog.SetnPlugD(SetPlugs(strPlugs,3));
    PlugBoardDialog.SetnPlugE(SetPlugs(strPlugs,4));
    PlugBoardDialog.SetnPlugF(SetPlugs(strPlugs,5));
    PlugBoardDialog.SetnPlugG(SetPlugs(strPlugs,6));
    PlugBoardDialog.SetnPlugH(SetPlugs(strPlugs,7));
    PlugBoardDialog.SetnPlugI(SetPlugs(strPlugs,8));
    PlugBoardDialog.SetnPlugJ(SetPlugs(strPlugs,9));
    PlugBoardDialog.SetnPlugK(SetPlugs(strPlugs,10));
    PlugBoardDialog.SetnPlugL(SetPlugs(strPlugs,11));
    PlugBoardDialog.SetnPlugM(SetPlugs(strPlugs,12));
    PlugBoardDialog.SetnPlugN(SetPlugs(strPlugs,13));
    PlugBoardDialog.SetnPlugO(SetPlugs(strPlugs,14));
    PlugBoardDialog.SetnPlugP(SetPlugs(strPlugs,15));
    PlugBoardDialog.SetnPlugQ(SetPlugs(strPlugs,16));
    PlugBoardDialog.SetnPlugR(SetPlugs(strPlugs,17));
    PlugBoardDialog.SetnPlugS(SetPlugs(strPlugs,18));
    PlugBoardDialog.SetnPlugT(SetPlugs(strPlugs,19));
    PlugBoardDialog.SetnPlugU(SetPlugs(strPlugs,20));
    PlugBoardDialog.SetnPlugV(SetPlugs(strPlugs,21));
    PlugBoardDialog.SetnPlugW(SetPlugs(strPlugs,22));
    PlugBoardDialog.SetnPlugX(SetPlugs(strPlugs,23));
    PlugBoardDialog.SetnPlugY(SetPlugs(strPlugs,24));
    PlugBoardDialog.SetnPlugZ(SetPlugs(strPlugs,25));
    PlugBoardDialog.SetPlugCount(PlugsCount);

    // Get Data from PlugBoardDialog
    if (PlugBoardDialog.ShowModal() == wxID_OK)
    {
        strPlugs = GetPlugs(PlugBoardDialog.GetnPlugA(),0);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugB(),1);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugC(),2);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugD(),3);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugE(),4);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugF(),5);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugG(),6);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugH(),7);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugI(),8);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugJ(),9);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugK(),10);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugL(),11);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugM(),12);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugN(),13);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugO(),14);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugP(),15);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugQ(),16);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugR(),17);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugS(),18);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugT(),19);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugU(),20);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugV(),21);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugW(),22);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugX(),23);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugY(),24);
        strPlugs += GetPlugs(PlugBoardDialog.GetnPlugZ(),25);
        PlugsCount = PlugBoardDialog.GetPlugCount();
    }

    // Create New PlugBoard Array
    arrPlugBoard = CreateRotors(strPlugs);
}

void EnigmaFrame::OnMenuItemReset(wxCommandEvent& event)
{
    // Reset PlugBoard
    strPlugs = strETW; // No plugs Connected

    PlugsCount = wxT("0");

    // Reset RingSettings
    nRingsetA=0;
    nRingsetB=0;
    nRingsetC=0;

    // Reset OffSet
    nOffsetA=0;
    nOffsetB=0;
    nOffsetC=0;

    // Default Rotors
    nRotorA=2; // Rotor III
    nRotorB=1; // Rotor II
    nRotorC=0; // Rotor I

    // Default Reflector
    nReflector=0; // Reflector UKW-B

    // Set Default Rotors
    StaticTextRotorA->SetLabel(arrRotorSet.Item(nRotorA));
    StaticTextRotorB->SetLabel(arrRotorSet.Item(nRotorB));
    StaticTextRotorC->SetLabel(arrRotorSet.Item(nRotorC));

    // Reset OffSet Counters
    ChOffSetA->SetSelection(nOffsetA);
    ChOffSetB->SetSelection(nOffsetB);
    ChOffSetC->SetSelection(nOffsetC);

    // Set Default Plugboard, Rotors, Reflector and rebuild the arrays
    arrPlugBoard = CreateRotors(strPlugs);
    arrRotorC = CreateRotors(strRotor1);
    arrRotorB = CreateRotors(strRotor2);
    strRotorNotchB = strNotchRotor2;
    arrRotorA = CreateRotors(strRotor3);
    strRotorNotchA = strNotchRotor3;
    arrReflector = CreateRotors(strReflectorB);

    // OutPut
    TextCtrlClearout->SetValue("");
    TextCtrlEncryptedOut->SetValue("");
}
