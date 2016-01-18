void DrawRange(std::string var, int nbin, float min, float max)
{
  if(var != "ZGstarDimu_DelaR"){
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


  // For ZGstarDimu_DelaR =========================
  }else{

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
  h_0->SetFillColor(kGreen);
  //h_0->SetFillColorAlpha(kBlue, 0.35);
  h_0->Draw("hist");

  TString plotName = Form ("%s", var.c_str());
  myCan->SaveAs("Plots/"+plotName +".pdf");

  TH1F* h_DeltaR[11];
  TH1F* h_DeltaRc[11];
  int invDimu;
  for(int i(0);i<11;i++)
  {
    myCan->Clear();
    invDimu = i+4;
    TString hName = Form ("h_DeltaR_%d",i);
    TString hTitle = Form ("DeltaR for %d< invM <%d",invDimu, invDimu+1);
    h_DeltaR[i] = new TH1F(hName,hTitle,nbin,min,max);
    h_DeltaR[i]->SetMinimum(0);
    TString toDraw_DeltaR = Form ("%s >> "+hName, var.c_str());
    TString cut = Form ("weightNominalLHE * (%d< m2MuFromZorGstar && m2MuFromZorGstar <%d)",invDimu, invDimu+1);
    myTree->Draw(toDraw_DeltaR.Data(),cut,"");
    h_DeltaRc[i] = (TH1F*)h_DeltaR[i]->Clone();
    h_DeltaRc[i]->GetXaxis()->SetRangeUser(0,0.4);
    h_DeltaR[i]->SetFillColor(kGreen);
    h_DeltaRc[i]->SetFillColor(kRed);
    h_DeltaR[i]->Draw("hist");
    h_DeltaRc[i]->Draw("histsame");
    myCan->SaveAs("Plots/"+hName +".pdf");

  }

  }
  
}
