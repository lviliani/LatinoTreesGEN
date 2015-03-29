{
 
 TTree* myTree = (TTree*) _file0 -> Get("Analyzer/myTree");
 myTree->Draw("weightNominalLHE","","");
 
 gPad->SetLogy();
  
}