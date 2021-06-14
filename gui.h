#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
  
class MainFrame : public wxFrame  
{
public:
    MainFrame(const wxString &title);
    void InitMaterials();
private:
    wxPanel *pnl;
    wxButton *btn1;
    wxChoice *cbb1, *cbb2;
    wxStaticText *lbl1, *lbl2, *lbl3;
    wxBoxSizer *mainSizer, *inputSizer, *cbbSizer, *lblSizer, *dimSizer;
    wxTextCtrl *inpL, *inpH, *inpTh;
    wxTextCtrl *log;
    
    void OnPressBTN1(wxCommandEvent& WXUNUSED(event));
    void Calculate();
};
