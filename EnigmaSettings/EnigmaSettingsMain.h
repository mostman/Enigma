/***************************************************************
 * Name:      EnigmaSettingsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#ifndef ENIGMASETTINGSMAIN_H
#define ENIGMASETTINGSMAIN_H

//(*Headers(EnigmaSettingsDialog)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

enum {
    ID_ENIGMASETTINGS_DIAG = 1000
};

class EnigmaSettingsDialog: public wxDialog
{
    public:

        EnigmaSettingsDialog(wxWindow* parent,wxWindowID id = ID_ENIGMASETTINGS_DIAG);
        virtual ~EnigmaSettingsDialog();

        // Sets the validators for the dialog controls
        void SetDialogValidators();

        // Data members
        int m_nrotora;
        int m_noffseta;
        int m_nringseta;
        int m_nrotorb;
        int m_noffsetb;
        int m_nringsetb;
        int m_nrotorc;
        int m_noffsetc;
        int m_nringsetc;
        int m_nreflector;

        void SetnRotorA(const int& nrotora) { m_nrotora = nrotora; }
        void SetnOffsetA(const int& noffseta) { m_noffseta = noffseta; }
        void SetnRingsetA(const int& nringseta) { m_nringseta = nringseta; }

        void SetnRotorB(const int& nrotorb) { m_nrotorb = nrotorb; }
        void SetnOffsetB(const int& noffsetb) { m_noffsetb = noffsetb; }
        void SetnRingsetB(const int& nringsetb) { m_nringsetb = nringsetb; }

        void SetnRotorC(const int& nrotorc) { m_nrotorc = nrotorc; }
        void SetnOffsetC(const int& noffsetc) { m_noffsetc = noffsetc; }
        void SetnRingsetC(const int& nringsetc) { m_nringsetc = nringsetc; }

        void SetnReflector(const int& nreflector) { m_nreflector = nreflector; }

        int GetnRotorA() const { return m_nrotora; }
        int GetnOffsetA() const { return m_noffseta; }
        int GetnRingsetA() const { return m_nringseta; }

        int GetnRotorB() const { return m_nrotorb; }
        int GetnOffsetB() const { return m_noffsetb; }
        int GetnRingsetB() const { return m_nringsetb; }

        int GetnRotorC() const { return m_nrotorc; }
        int GetnOffsetC() const { return m_noffsetc; }
        int GetnRingsetC() const { return m_nringsetc; }

        int GetnReflector() const { return m_nreflector; }

    private:

        //(*Handlers(EnigmaSettingsDialog)
        void OnBtnCloseSettings(wxCommandEvent& event);
        //*)

        //(*Identifiers(EnigmaSettingsDialog)
        static const long ID_CHREFLECTOR;
        static const long ID_STATICTEXTRINGSETTING;
        static const long ID_STATICTEXTROTORPOS;
        static const long ID_CHROTORC;
        static const long ID_CHRINGC;
        static const long ID_CHOFFSETC;
        static const long ID_CHROTORB;
        static const long ID_CHRINGB;
        static const long ID_CHOFFSETB;
        static const long ID_CHROTORA;
        static const long ID_CHRINGA;
        static const long ID_CHOFFSETA;
        static const long ID_BTNCLOSESETTINGS;
        //*)

        //(*Declarations(EnigmaSettingsDialog)
        wxButton* BtnCloseSettings;
        wxChoice* ChOffSetA;
        wxChoice* ChOffSetB;
        wxChoice* ChOffSetC;
        wxChoice* ChReflector;
        wxChoice* ChRingA;
        wxChoice* ChRingB;
        wxChoice* ChRingC;
        wxChoice* ChRotorA;
        wxChoice* ChRotorB;
        wxChoice* ChRotorC;
        wxStaticText* StaticTextRingSetting;
        wxStaticText* StaticTextRotorPosition;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ENIGMASETTINGSMAIN_H
