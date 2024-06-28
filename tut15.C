void tut15() {
	fstream file;
	file.open("data5.txt", ios::in);
	
	double x, y ;
	TFile *output = new TFile("tut15.root","RECREATE");
	TTree *tree = new TTree("tree", "tree");
	tree->Branch("x", &x , "x/D");
	tree->Branch("y", &y , "y/D");
	
	while (1){
		file >> x >> y ;
		if (file.eof()) break ;
		
		tree->Fill();
	};
	output->Write();
	output->Close();
	
	file.close();


}
