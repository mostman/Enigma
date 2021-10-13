/***************************************************************
 * Name:      EnigmaPlugBoardMain.h
 * Purpose:   Defines Application Frame
 * Author:    Martin Östman (martin.oestman@gmail.com)
 * Created:   2021-02-24
 * Copyright: Martin Östman ()
 * License:
 **************************************************************/

#ifndef ENIGMAPLUGBOARDMAIN_H
#define ENIGMAPLUGBOARDMAIN_H

//(*Headers(EnigmaPlugBoardDialog)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

enum {
    ID_ENIGMAPLUGBOARD_DIAG = 2000
};


class EnigmaPlugBoardDialog: public wxDialog
{
    public:

        EnigmaPlugBoardDialog(wxWindow* parent,wxWindowID id = ID_ENIGMAPLUGBOARD_DIAG);
        virtual ~EnigmaPlugBoardDialog();

        // Sets the validators for the dialog controls
        void SetDialogValidators();

        // Data members
        int nPBA;
        int nPBB;
        int nPBC;
        int nPBD;
        int nPBE;
        int nPBF;
        int nPBG;
        int nPBH;
        int nPBI;
        int nPBJ;
        int nPBK;
        int nPBL;
        int nPBM;
        int nPBN;
        int nPBO;
        int nPBP;
        int nPBQ;
        int nPBR;
        int nPBS;
        int nPBT;
        int nPBU;
        int nPBV;
        int nPBW;
        int nPBX;
        int nPBY;
        int nPBZ;

        wxString m_plugcount;

        int GetnPlugA() const { return nPBA; }
        int GetnPlugB() const { return nPBB; }
        int GetnPlugC() const { return nPBC; }
        int GetnPlugD() const { return nPBD; }
        int GetnPlugE() const { return nPBE; }
        int GetnPlugF() const { return nPBF; }
        int GetnPlugG() const { return nPBG; }
        int GetnPlugH() const { return nPBH; }
        int GetnPlugI() const { return nPBI; }
        int GetnPlugJ() const { return nPBJ; }
        int GetnPlugK() const { return nPBK; }
        int GetnPlugL() const { return nPBL; }
        int GetnPlugM() const { return nPBM; }
        int GetnPlugN() const { return nPBN; }
        int GetnPlugO() const { return nPBO; }
        int GetnPlugP() const { return nPBP; }
        int GetnPlugQ() const { return nPBQ; }
        int GetnPlugR() const { return nPBR; }
        int GetnPlugS() const { return nPBS; }
        int GetnPlugT() const { return nPBT; }
        int GetnPlugU() const { return nPBU; }
        int GetnPlugV() const { return nPBV; }
        int GetnPlugW() const { return nPBW; }
        int GetnPlugX() const { return nPBX; }
        int GetnPlugY() const { return nPBY; }
        int GetnPlugZ() const { return nPBZ; }

        wxString GetPlugCount() const { return m_plugcount; }

        void SetnPlugA(const int& npluga) { nPBA = npluga; }
        void SetnPlugB(const int& nplugb) { nPBB = nplugb; }
        void SetnPlugC(const int& nplugc) { nPBC = nplugc; }
        void SetnPlugD(const int& nplugd) { nPBD = nplugd; }
        void SetnPlugE(const int& npluge) { nPBE = npluge; }
        void SetnPlugF(const int& nplugf) { nPBF = nplugf; }
        void SetnPlugG(const int& nplugg) { nPBG = nplugg; }
        void SetnPlugH(const int& nplugh) { nPBH = nplugh; }
        void SetnPlugI(const int& nplugi) { nPBI = nplugi; }
        void SetnPlugJ(const int& nplugj) { nPBJ = nplugj; }
        void SetnPlugK(const int& nplugk) { nPBK = nplugk; }
        void SetnPlugL(const int& nplugl) { nPBL = nplugl; }
        void SetnPlugM(const int& nplugm) { nPBM = nplugm; }
        void SetnPlugN(const int& nplugn) { nPBN = nplugn; }
        void SetnPlugO(const int& nplugo) { nPBO = nplugo; }
        void SetnPlugP(const int& nplugp) { nPBP = nplugp; }
        void SetnPlugQ(const int& nplugq) { nPBQ = nplugq; }
        void SetnPlugR(const int& nplugr) { nPBR = nplugr; }
        void SetnPlugS(const int& nplugs) { nPBS = nplugs; }
        void SetnPlugT(const int& nplugt) { nPBT = nplugt; }
        void SetnPlugU(const int& nplugu) { nPBU = nplugu; }
        void SetnPlugV(const int& nplugv) { nPBV = nplugv; }
        void SetnPlugW(const int& nplugw) { nPBW = nplugw; }
        void SetnPlugX(const int& nplugx) { nPBX = nplugx; }
        void SetnPlugY(const int& nplugy) { nPBY = nplugy; }
        void SetnPlugZ(const int& nplugz) { nPBZ = nplugz; }

        void SetPlugCount(const wxString& plugcount) { m_plugcount = plugcount; }

    private:

        //(*Handlers(EnigmaPlugBoardDialog)
        void OnChPBQSet(wxCommandEvent& event);
        void OnChPBWSet(wxCommandEvent& event);
        void OnChPBESet(wxCommandEvent& event);
        void OnChPBRSet(wxCommandEvent& event);
        void OnChPBTSet(wxCommandEvent& event);
        void OnChPBZSet(wxCommandEvent& event);
        void OnChPBUSet(wxCommandEvent& event);
        void OnChPBISet(wxCommandEvent& event);
        void OnChPBOSet(wxCommandEvent& event);
        void OnChPBASet(wxCommandEvent& event);
        void OnChPBSSet(wxCommandEvent& event);
        void OnChPBDSet(wxCommandEvent& event);
        void OnChPBFSet(wxCommandEvent& event);
        void OnChPBGSet(wxCommandEvent& event);
        void OnChPBHSet(wxCommandEvent& event);
        void OnChPBJSet(wxCommandEvent& event);
        void OnChPBKSet(wxCommandEvent& event);
        void OnChPBPSet(wxCommandEvent& event);
        void OnChPBYSet(wxCommandEvent& event);
        void OnChPBXSet(wxCommandEvent& event);
        void OnChPBCSet(wxCommandEvent& event);
        void OnChPBVSet(wxCommandEvent& event);
        void OnChPBBSet(wxCommandEvent& event);
        void OnChPBNSet(wxCommandEvent& event);
        void OnChPBMSet(wxCommandEvent& event);
        void OnChPBLSet(wxCommandEvent& event);
        void OnBtnPBReset(wxCommandEvent& event);
        void OnBtnClose(wxCommandEvent& event);
        //*)

        //(*Identifiers(EnigmaPlugBoardDialog)
        static const long ID_CHPBQ;
        static const long ID_CHPBW;
        static const long ID_CHPBE;
        static const long ID_CHPBR;
        static const long ID_CHPBT;
        static const long ID_CHPBZ;
        static const long ID_CHPBU;
        static const long ID_CHPBI;
        static const long ID_CHPBO;
        static const long ID_CHPBA;
        static const long ID_CHPBS;
        static const long ID_CHPBD;
        static const long ID_CHPBF;
        static const long ID_CHPBG;
        static const long ID_CHPBH;
        static const long ID_CHPBJ;
        static const long ID_CHPBK;
        static const long ID_CHPBP;
        static const long ID_CHPBY;
        static const long ID_CHPBX;
        static const long ID_CHPBC;
        static const long ID_CHPBV;
        static const long ID_CHPBB;
        static const long ID_CHPBN;
        static const long ID_CHPBM;
        static const long ID_CHPBL;
        static const long ID_BTNPHRESET;
        static const long ID_BTNCLOSE;
        static const long ID_STATICTEXTPLUGSCON;
        static const long ID_STATICTEXTPLUGSCOUNT;
        //*)

        //(*Declarations(EnigmaPlugBoardDialog)
        wxButton* BtnClose;
        wxButton* BtnPBReset;
        wxChoice* ChPBA;
        wxChoice* ChPBB;
        wxChoice* ChPBC;
        wxChoice* ChPBD;
        wxChoice* ChPBE;
        wxChoice* ChPBF;
        wxChoice* ChPBG;
        wxChoice* ChPBH;
        wxChoice* ChPBI;
        wxChoice* ChPBJ;
        wxChoice* ChPBK;
        wxChoice* ChPBL;
        wxChoice* ChPBM;
        wxChoice* ChPBN;
        wxChoice* ChPBO;
        wxChoice* ChPBP;
        wxChoice* ChPBQ;
        wxChoice* ChPBR;
        wxChoice* ChPBS;
        wxChoice* ChPBT;
        wxChoice* ChPBU;
        wxChoice* ChPBV;
        wxChoice* ChPBW;
        wxChoice* ChPBX;
        wxChoice* ChPBY;
        wxChoice* ChPBZ;
        wxStaticText* StaticTextPlugsCon;
        wxStaticText* StaticTextPlugsCount;
        //*)

        int nNumCon;

        void ResetPlug(int nToPlug);
        void ConnectPlug(int nToPlug, int nFromPlug);

        DECLARE_EVENT_TABLE()
};

#endif // ENIGMAPLUGBOARDMAIN_H
