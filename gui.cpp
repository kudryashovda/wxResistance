#include "gui.h"

MainFrame::MainFrame(const wxString &title):wxFrame(NULL, wxID_ANY, title)
{
    SetMinSize(wxSize(400, 200));
    Centre();
    
    pnl = new wxPanel(this, wxID_ANY);
   
    cbb1 = new wxChoice (pnl, wxID_ANY);
    cbb2 = new wxChoice (pnl, wxID_ANY);
        cbb2->Append("300K");
        cbb2->Append("1300K");   
        cbb2->SetSelection(0);
        
    cbbSizer = new wxBoxSizer(wxHORIZONTAL);
        cbbSizer->Add(cbb1, 1, 0);
        cbbSizer->Add(cbb2, 1, 0);
        
    lbl1 = new wxStaticText(pnl, wxID_ANY, "L, mm");
    lbl2 = new wxStaticText(pnl, wxID_ANY, "H, mm");
    lbl3 = new wxStaticText(pnl, wxID_ANY, "Thickness, mkm");
        lbl1->SetMinSize(wxSize(22,22));
        lbl2->SetMinSize(wxSize(22,22));
        lbl3->SetMinSize(wxSize(22,22));

    lblSizer = new wxBoxSizer(wxHORIZONTAL);    
        lblSizer->Add(lbl1, 1, 0);
        lblSizer->Add(lbl2, 1, 0);
        lblSizer->Add(lbl3, 1, 0);
    
    inpL = new wxTextCtrl(pnl, wxID_ANY, "40");
    inpH = new wxTextCtrl(pnl, wxID_ANY, "50");
    inpTh = new wxTextCtrl(pnl, wxID_ANY, "10");
        inpL->SetMinSize(wxSize(22,22));
        inpH->SetMinSize(wxSize(22,22));
        inpTh->SetMinSize(wxSize(22,22));
    
    dimSizer = new wxBoxSizer(wxHORIZONTAL);    
        dimSizer->Add(inpL, 1, 0);
        dimSizer->Add(inpH, 1, 0);
        dimSizer->Add(inpTh, 1, 0);
    
    log = new wxTextCtrl(pnl, wxID_ANY, _(""),
        wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE | wxTE_RICH,
        wxDefaultValidator, wxTextCtrlNameStr );

    btn1 = new wxButton(pnl, wxID_ANY, "CALCULATE");
    
    btn1->Bind (wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnPressBTN1, this);
    
    inputSizer = new wxBoxSizer(wxVERTICAL);    
        inputSizer->Add(lblSizer, 0, wxEXPAND, 0);
        inputSizer->Add(dimSizer, 0, wxEXPAND, 0);
        inputSizer->Add(cbbSizer, 0, wxEXPAND | wxTOP, 5);
        inputSizer->Add(log, 4, wxEXPAND | wxTOP, 5);
        inputSizer->Add(btn1, 1, wxEXPAND | wxTOP, 5);

    mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(inputSizer, 1, wxEXPAND | wxALL, 5);
        
    pnl->SetSizer(mainSizer);
    
    Show(TRUE);
}
