/***************************************************************
 * Name:      EnigmaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-22
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#ifndef ENIGMAMAIN_H
#define ENIGMAMAIN_H

//(*Headers(EnigmaFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

class EnigmaFrame: public wxFrame
{
    public:

        EnigmaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~EnigmaFrame();

    private:

        //(*Handlers(EnigmaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemSettings(wxCommandEvent& event);
        void OnBtnAClick(wxCommandEvent& event);
        void OnBtnBClick(wxCommandEvent& event);
        void OnBtnCClick(wxCommandEvent& event);
        void OnBtnDClick(wxCommandEvent& event);
        void OnBtnEClick(wxCommandEvent& event);
        void OnBtnFClick(wxCommandEvent& event);
        void OnBtnGClick(wxCommandEvent& event);
        void OnBtnHClick(wxCommandEvent& event);
        void OnBtnIClick(wxCommandEvent& event);
        void OnBtnJClick(wxCommandEvent& event);
        void OnBtnKClick(wxCommandEvent& event);
        void OnBtnLClick(wxCommandEvent& event);
        void OnBtnMClick(wxCommandEvent& event);
        void OnBtnNClick(wxCommandEvent& event);
        void OnBtnOClick(wxCommandEvent& event);
        void OnBtnPClick(wxCommandEvent& event);
        void OnBtnQClick(wxCommandEvent& event);
        void OnBtnRClick(wxCommandEvent& event);
        void OnBtnSClick(wxCommandEvent& event);
        void OnBtnTClick(wxCommandEvent& event);
        void OnBtnUClick(wxCommandEvent& event);
        void OnBtnVClick(wxCommandEvent& event);
        void OnBtnWClick(wxCommandEvent& event);
        void OnBtnXClick(wxCommandEvent& event);
        void OnBtnYClick(wxCommandEvent& event);
        void OnBtnZClick(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnMenuItemPlugBoard(wxCommandEvent& event);
        void OnMenuItemReset(wxCommandEvent& event);
        //*)

        //(*Identifiers(EnigmaFrame)
        static const long ID_STATICTEXTROTORC;
        static const long ID_CHOFFSETC;
        static const long ID_STATICTEXTROTORB;
        static const long ID_CHOFFSETB;
        static const long ID_STATICTEXTROTORA;
        static const long ID_CHOFFSETA;
        static const long ID_STATICTEXTQ;
        static const long ID_STATICTEXTW;
        static const long ID_STATICTEXTE;
        static const long ID_STATICTEXTR;
        static const long ID_STATICTEXTT;
        static const long ID_STATICTEXTZ;
        static const long ID_STATICTEXTU;
        static const long ID_STATICTEXTI;
        static const long ID_STATICTEXTO;
        static const long ID_STATICTEXTA;
        static const long ID_STATICTEXTS;
        static const long ID_STATICTEXTD;
        static const long ID_STATICTEXTF;
        static const long ID_STATICTEXTG;
        static const long ID_STATICTEXTH;
        static const long ID_STATICTEXTJ;
        static const long ID_STATICTEXTK;
        static const long ID_STATICTEXTP;
        static const long ID_STATICTEXTY;
        static const long ID_STATICTEXTX;
        static const long ID_STATICTEXTC;
        static const long ID_STATICTEXTV;
        static const long ID_STATICTEXTB;
        static const long ID_STATICTEXTN;
        static const long ID_STATICTEXTM;
        static const long ID_STATICTEXTL;
        static const long ID_BTNQ;
        static const long ID_BTNW;
        static const long ID_BTNE;
        static const long ID_BTNR;
        static const long ID_BTNT;
        static const long ID_BTNZ;
        static const long ID_BTNU;
        static const long ID_BTNI;
        static const long ID_BTNO;
        static const long ID_BTNA;
        static const long ID_BTNS;
        static const long ID_BTND;
        static const long ID_BTNF;
        static const long ID_BTNG;
        static const long ID_BTNH;
        static const long ID_BTNJ;
        static const long ID_BTNK;
        static const long ID_BTNP;
        static const long ID_BTNY;
        static const long ID_BTNX;
        static const long ID_BTNC;
        static const long ID_BTNV;
        static const long ID_BTNB;
        static const long ID_BTNN;
        static const long ID_BTNM;
        static const long ID_BTNL;
        static const long ID_TEXTCTRLCLEAROUT;
        static const long ID_TEXTCTRLENCRYPTEDOUT;
        static const long idMenuSettings;
        static const long idMenuPlug;
        static const long idMenuReset;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(EnigmaFrame)
        wxButton* BtnA;
        wxButton* BtnB;
        wxButton* BtnC;
        wxButton* BtnD;
        wxButton* BtnE;
        wxButton* BtnF;
        wxButton* BtnG;
        wxButton* BtnH;
        wxButton* BtnI;
        wxButton* BtnJ;
        wxButton* BtnK;
        wxButton* BtnL;
        wxButton* BtnM;
        wxButton* BtnN;
        wxButton* BtnO;
        wxButton* BtnP;
        wxButton* BtnQ;
        wxButton* BtnR;
        wxButton* BtnS;
        wxButton* BtnT;
        wxButton* BtnU;
        wxButton* BtnV;
        wxButton* BtnW;
        wxButton* BtnX;
        wxButton* BtnY;
        wxButton* BtnZ;
        wxChoice* ChOffSetA;
        wxChoice* ChOffSetB;
        wxChoice* ChOffSetC;
        wxMenuItem* MenuItemPlugBoard;
        wxMenuItem* MenuItemReset;
        wxMenuItem* MenuItemSettings;
        wxStaticText* StaticTextA;
        wxStaticText* StaticTextB;
        wxStaticText* StaticTextC;
        wxStaticText* StaticTextD;
        wxStaticText* StaticTextE;
        wxStaticText* StaticTextF;
        wxStaticText* StaticTextG;
        wxStaticText* StaticTextH;
        wxStaticText* StaticTextI;
        wxStaticText* StaticTextJ;
        wxStaticText* StaticTextK;
        wxStaticText* StaticTextL;
        wxStaticText* StaticTextM;
        wxStaticText* StaticTextN;
        wxStaticText* StaticTextO;
        wxStaticText* StaticTextP;
        wxStaticText* StaticTextQ;
        wxStaticText* StaticTextR;
        wxStaticText* StaticTextRotorA;
        wxStaticText* StaticTextRotorB;
        wxStaticText* StaticTextRotorC;
        wxStaticText* StaticTextS;
        wxStaticText* StaticTextT;
        wxStaticText* StaticTextU;
        wxStaticText* StaticTextV;
        wxStaticText* StaticTextW;
        wxStaticText* StaticTextX;
        wxStaticText* StaticTextY;
        wxStaticText* StaticTextZ;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlClearout;
        wxTextCtrl* TextCtrlEncryptedOut;
        wxTimer Timer1;
        //*)

        wxArrayString arrRotorSet;
        wxArrayString arrPlugBoard;
        wxArrayString arrETW;
        wxArrayString arrRotorA;
        wxString strRotorNotchA;
        int nRotorA;
        int nOffsetA;
        int nRingsetA;
        wxArrayString arrRotorB;
        wxString strRotorNotchB;
        int nRotorB;
        int nOffsetB;
        int nRingsetB;
        wxArrayString arrRotorC;
        int nRotorC;
        int nOffsetC;
        int nRingsetC;
        wxArrayString arrReflector;
        int nReflector;
        int nCharCount;
        wxString PlugsCount;

        wxString strETW;
        wxString strRotor1;
        wxString strNotchRotor1;
        wxString strRotor2;
        wxString strNotchRotor2;
        wxString strRotor3;
        wxString strNotchRotor3;
        wxString strRotor4;
        wxString strNotchRotor4;
        wxString strRotor5;
        wxString strNotchRotor5;
        wxString strRotor6;
        wxString strRotor7;
        wxString strRotor8;
        wxString strNotchRotor678;
        wxString strReflectorB;
        wxString strReflectorC;
        wxString strPlugs;

        int SetPlugs(wxString strPlugSet, int nPlugIndex);
        wxString GetPlugs(int nPlugSet, int nPlugIndex);
        bool StepRotor(wxString strNotch, int nOffSet);
        int Rotor(wxArrayString arRotor, int nLetter, int nOffSet, int nRingSetting, bool bIn);
        void Encryption(wxString strLetter);
        wxArrayString CreateRotors(wxString strRotor);

        DECLARE_EVENT_TABLE()
};

#endif // ENIGMAMAIN_H
