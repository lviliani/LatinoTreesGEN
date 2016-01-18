void DrawRange(std::string var, int nbin, float min, float max)
{
  gStyle->SetOptStat(0);
  TCanvas *myCan=new TCanvas();
  myCan->SetGrid();
  //gPad->SetLogy();
  TTree* myTree = (TTree*) _file0 -> Get("Analyzer/myTree");
  TH1F* h_0 = new TH1F("h_0","",nbin,min,max);
  TString toDraw_0 = Form ("%s >> h_0", var.c_str());
  myTree->Draw(toDraw_0.Data(),"weightNominalLHE","");
  float normalization_0 = h_0 -> Integral(-1,-1);
  h_0->Scale(1./normalization_0);
  h_0->SetFillColor(kBlue);
  //h_0->SetFillColorAlpha(kBlue, 0.35);
  h_0->Draw("hist");

  TString plotName = Form ("%s", var.c_str());
  myCan->SaveAs("Plots/"+plotName +".pdf");
  
  
}
