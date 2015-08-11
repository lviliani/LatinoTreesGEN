
//---- calculate effective weight for negative weight sample

int count(std::string samples) {
 
 std::cout << " ~~~~~ " << std::endl;
 std::cout << " samples = " << samples << std::endl;
 
 std::vector <std::string> v_nameFile;
 
 std::ifstream indata;
 std::string nameFile;
 indata.open(samples.c_str()); // opens the file
 if (!indata) { // file couldn't be opened
  std::cerr << "Error: file " << argv[1] << " could not be opened" << std::endl;
  return 1;
 }
 
 while ( !indata.eof() ) { // keep reading until end-of-file
  indata >> nameFile;
  v_nameFile.push_back(nameFile);
 }
 indata.close();
 
 
 
 

 TChain* myTree = new TChain ("Analyzer/myTree", "myTree");
 for (int iFile = 0; iFile < v_nameFile.size(); iFile++) {
  myTree->Add(v_nameFile.at(iFile).c_str()); 
 }
 
 std::cout << " entries = " << myTree->GetEntries() << std::endl;
 int Np = myTree->GetEntries("weightSM>0");
 int Nm = myTree->GetEntries("weightSM<0");
 std::cout << " weight = " << 1. * (Np - Nm) / (Np + Nm) ;
 std::cout << " +/- " << 1. * sqrt(Np + Nm) / (Np + Nm) << std::endl; //--- approx error
 std::cout << " ~~~~~ " << std::endl;
 
 return 0;
}