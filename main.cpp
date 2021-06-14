#include "gui.h"

struct Material {
    const char* name;
    float res300, res1300;
};

wxVector<Material> material;

bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame("Resistance");
    frame->InitMaterials();    
    return true;
}

IMPLEMENT_APP(MyApp) 

void MainFrame::InitMaterials() {     
    material.push_back( {"Wolfram", 5.44e-8, 33e-8} );
    material.push_back( {"Tantal", 13.48e-8, 55e-8} );
    material.push_back( {"Nihrom", 1.1e-6, 1.18e-6} );
    material.push_back( {"Molibden", 5.78e-8, 35.2e-8} );
    material.push_back( {"Titan", 4.2e-7, 17e-7} );
    material.push_back( {"Graphite", 8e-6, 8e-6} );
 
    for (int i = 0; i < material.size(); i++)
        cbb1->Append(material[i].name);       
    
    cbb1->SetSelection(0);
}

void MainFrame::OnPressBTN1(wxCommandEvent& WXUNUSED(event))
{
    MainFrame::Calculate();
}

 void MainFrame::Calculate() {
         
    int pos_cbb1 = cbb1->GetSelection();
    int pos_cbb2 = cbb2->GetSelection();
    
    int L = wxAtoi(inpL->GetValue());
    int H = wxAtoi(inpH->GetValue());
    int Th = wxAtoi(inpTh->GetValue());
    
    if (H ==0 || Th ==0) return;
     
    float p;
    (pos_cbb2 == 0) ? p = material[pos_cbb1].res300 : p = material[pos_cbb1].res1300;
    
    if (H == 0 || Th == 0) {
        *log << "Please enter valid dimensions\n\n";
        return;
    }

    float R =  1e9 * p * L / (H * Th);

    *log << "Object resistance equals: " << R << " mOhm \n\n";
 }
