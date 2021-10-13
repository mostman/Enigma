/***************************************************************
 * Name:      EnigmaSettingsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "EnigmaSettingsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(EnigmaSettingsDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "wx/valgen.h"

//(*IdInit(EnigmaSettingsDialog)
const long EnigmaSettingsDialog::ID_CHREFLECTOR = wxNewId();
const long EnigmaSettingsDialog::ID_STATICTEXTRINGSETTING = wxNewId();
const long EnigmaSettingsDialog::ID_STATICTEXTROTORPOS = wxNewId();
const long EnigmaSettingsDialog::ID_CHROTORC = wxNewId();
const long EnigmaSettingsDialog::ID_CHRINGC = wxNewId();
const long EnigmaSettingsDialog::ID_CHOFFSETC = wxNewId();
const long EnigmaSettingsDialog::ID_CHROTORB = wxNewId();
const long EnigmaSettingsDialog::ID_CHRINGB = wxNewId();
const long EnigmaSettingsDialog::ID_CHOFFSETB = wxNewId();
const long EnigmaSettingsDialog::ID_CHROTORA = wxNewId();
const long EnigmaSettingsDialog::ID_CHRINGA = wxNewId();
const long EnigmaSettingsDialog::ID_CHOFFSETA = wxNewId();
const long EnigmaSettingsDialog::ID_BTNCLOSESETTINGS = wxNewId();
//*)

BEGIN_EVENT_TABLE(EnigmaSettingsDialog,wxDialog)
    //(*EventTable(EnigmaSettingsDialog)
    //*)
END_EVENT_TABLE()

// Set the validators for the dialog controls
void EnigmaSettingsDialog::SetDialogValidators()
{
    FindWindow(ID_CHROTORA)->SetValidator(wxGenericValidator(& m_nrotora));
    FindWindow(ID_CHOFFSETA)->SetValidator(wxGenericValidator(& m_noffseta));
    FindWindow(ID_CHRINGA)->SetValidator(wxGenericValidator(& m_nringseta));

    FindWindow(ID_CHROTORB)->SetValidator(wxGenericValidator(& m_nrotorb));
    FindWindow(ID_CHOFFSETB)->SetValidator(wxGenericValidator(& m_noffsetb));
    FindWindow(ID_CHRINGB)->SetValidator(wxGenericValidator(& m_nringsetb));

    FindWindow(ID_CHROTORC)->SetValidator(wxGenericValidator(& m_nrotorc));
    FindWindow(ID_CHOFFSETC)->SetValidator(wxGenericValidator(& m_noffsetc));
    FindWindow(ID_CHRINGC)->SetValidator(wxGenericValidator(& m_nringsetc));

    FindWindow(ID_CHREFLECTOR)->SetValidator(wxGenericValidator(& m_nreflector));
}

EnigmaSettingsDialog::EnigmaSettingsDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(EnigmaSettingsDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizerReflector;

    Create(parent, wxID_ANY, _("Enigma Settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizerReflector = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Reflector"));
    ChReflector = new wxChoice(this, ID_CHREFLECTOR, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHREFLECTOR"));
    ChReflector->SetSelection( ChReflector->Append(_("UKW-B")) );
    ChReflector->Append(_("UKW-C"));
    StaticBoxSizerReflector->Add(ChReflector, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(StaticBoxSizerReflector, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticTextRingSetting = new wxStaticText(this, ID_STATICTEXTRINGSETTING, _("Ring Setting"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTRINGSETTING"));
    BoxSizer4->Add(StaticTextRingSetting, 0, wxALL|wxALIGN_LEFT, 5);
    StaticTextRotorPosition = new wxStaticText(this, ID_STATICTEXTROTORPOS, _("Initial Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTROTORPOS"));
    BoxSizer4->Add(StaticTextRotorPosition, 0, wxALL|wxALIGN_LEFT, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("3rd Rotor"));
    ChRotorC = new wxChoice(this, ID_CHROTORC, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHROTORC"));
    ChRotorC->SetSelection( ChRotorC->Append(_("I")) );
    ChRotorC->Append(_("II"));
    ChRotorC->Append(_("III"));
    ChRotorC->Append(_("IV"));
    ChRotorC->Append(_("V"));
    ChRotorC->Append(_("VI"));
    ChRotorC->Append(_("VII"));
    ChRotorC->Append(_("VIII"));
    StaticBoxSizer1->Add(ChRotorC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChRingC = new wxChoice(this, ID_CHRINGC, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHRINGC"));
    ChRingC->SetSelection( ChRingC->Append(_("A")) );
    ChRingC->Append(_("B"));
    ChRingC->Append(_("C"));
    ChRingC->Append(_("D"));
    ChRingC->Append(_("E"));
    ChRingC->Append(_("F"));
    ChRingC->Append(_("G"));
    ChRingC->Append(_("H"));
    ChRingC->Append(_("I"));
    ChRingC->Append(_("J"));
    ChRingC->Append(_("K"));
    ChRingC->Append(_("L"));
    ChRingC->Append(_("M"));
    ChRingC->Append(_("N"));
    ChRingC->Append(_("O"));
    ChRingC->Append(_("P"));
    ChRingC->Append(_("Q"));
    ChRingC->Append(_("R"));
    ChRingC->Append(_("S"));
    ChRingC->Append(_("T"));
    ChRingC->Append(_("U"));
    ChRingC->Append(_("V"));
    ChRingC->Append(_("W"));
    ChRingC->Append(_("X"));
    ChRingC->Append(_("Y"));
    ChRingC->Append(_("Z"));
    StaticBoxSizer1->Add(ChRingC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    StaticBoxSizer1->Add(ChOffSetC, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("2nd Rotor"));
    ChRotorB = new wxChoice(this, ID_CHROTORB, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHROTORB"));
    ChRotorB->Append(_("I"));
    ChRotorB->SetSelection( ChRotorB->Append(_("II")) );
    ChRotorB->Append(_("III"));
    ChRotorB->Append(_("IV"));
    ChRotorB->Append(_("V"));
    ChRotorB->Append(_("VI"));
    ChRotorB->Append(_("VII"));
    ChRotorB->Append(_("VIII"));
    StaticBoxSizer2->Add(ChRotorB, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChRingB = new wxChoice(this, ID_CHRINGB, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHRINGB"));
    ChRingB->SetSelection( ChRingB->Append(_("A")) );
    ChRingB->Append(_("B"));
    ChRingB->Append(_("C"));
    ChRingB->Append(_("D"));
    ChRingB->Append(_("E"));
    ChRingB->Append(_("F"));
    ChRingB->Append(_("G"));
    ChRingB->Append(_("H"));
    ChRingB->Append(_("I"));
    ChRingB->Append(_("J"));
    ChRingB->Append(_("K"));
    ChRingB->Append(_("L"));
    ChRingB->Append(_("M"));
    ChRingB->Append(_("N"));
    ChRingB->Append(_("O"));
    ChRingB->Append(_("P"));
    ChRingB->Append(_("Q"));
    ChRingB->Append(_("R"));
    ChRingB->Append(_("S"));
    ChRingB->Append(_("T"));
    ChRingB->Append(_("U"));
    ChRingB->Append(_("V"));
    ChRingB->Append(_("W"));
    ChRingB->Append(_("X"));
    ChRingB->Append(_("Y"));
    ChRingB->Append(_("Z"));
    StaticBoxSizer2->Add(ChRingB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    StaticBoxSizer2->Add(ChOffSetB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, this, _("1st Rotor"));
    ChRotorA = new wxChoice(this, ID_CHROTORA, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHROTORA"));
    ChRotorA->Append(_("I"));
    ChRotorA->Append(_("II"));
    ChRotorA->SetSelection( ChRotorA->Append(_("III")) );
    ChRotorA->Append(_("IV"));
    ChRotorA->Append(_("V"));
    ChRotorA->Append(_("VI"));
    ChRotorA->Append(_("VII"));
    ChRotorA->Append(_("VIII"));
    StaticBoxSizer3->Add(ChRotorA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChRingA = new wxChoice(this, ID_CHRINGA, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHRINGA"));
    ChRingA->SetSelection( ChRingA->Append(_("A")) );
    ChRingA->Append(_("B"));
    ChRingA->Append(_("C"));
    ChRingA->Append(_("D"));
    ChRingA->Append(_("E"));
    ChRingA->Append(_("F"));
    ChRingA->Append(_("G"));
    ChRingA->Append(_("H"));
    ChRingA->Append(_("I"));
    ChRingA->Append(_("J"));
    ChRingA->Append(_("K"));
    ChRingA->Append(_("L"));
    ChRingA->Append(_("M"));
    ChRingA->Append(_("N"));
    ChRingA->Append(_("O"));
    ChRingA->Append(_("P"));
    ChRingA->Append(_("Q"));
    ChRingA->Append(_("R"));
    ChRingA->Append(_("S"));
    ChRingA->Append(_("T"));
    ChRingA->Append(_("U"));
    ChRingA->Append(_("V"));
    ChRingA->Append(_("W"));
    ChRingA->Append(_("X"));
    ChRingA->Append(_("Y"));
    ChRingA->Append(_("Z"));
    StaticBoxSizer3->Add(ChRingA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    StaticBoxSizer3->Add(ChOffSetA, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(StaticBoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BtnCloseSettings = new wxButton(this, ID_BTNCLOSESETTINGS, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCLOSESETTINGS"));
    BoxSizer2->Add(BtnCloseSettings, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BTNCLOSESETTINGS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EnigmaSettingsDialog::OnBtnCloseSettings);
    //*)
    SetDialogValidators();
}

EnigmaSettingsDialog::~EnigmaSettingsDialog()
{
    //(*Destroy(EnigmaSettingsDialog)
    //*)
}

void EnigmaSettingsDialog::OnBtnCloseSettings(wxCommandEvent& event)
{
    if (
        (ChRotorA->GetCurrentSelection() == ChRotorB->GetCurrentSelection()) ||
        (ChRotorA->GetCurrentSelection() == ChRotorC->GetCurrentSelection()) ||
        (ChRotorB->GetCurrentSelection() == ChRotorC->GetCurrentSelection())
       )
    {
        wxMessageBox("Its not recomended to have the same rotor stacked like this...", "Rotor Selection", wxICON_EXCLAMATION);
    }
    else
    {
        if ( Validate() && TransferDataFromWindow() )
        {
            if ( IsModal() )
            {
                EndModal(wxID_OK); // If modal
            }
            else
            {
                SetReturnCode(wxID_OK);
                this->Show(false); // If modeless
            }
        }
    }
}
