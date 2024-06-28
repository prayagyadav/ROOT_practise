void tut16(){

	TCanvas *c = new TCanvas();
	TFile *input = new TFile("tut15.root","read");
	
	TTree *tree = (TTree*)input->Get("tree");
	double a , b ;
	TH1F *hist = new TH1F("hist", "Histogram;x axis; y axis ", 100,0, 20 );
	int entries = tree->GetEntries();
	tree->SetBranchAddress("x", &a);
	tree->SetBranchAddress("y", &b);
	for (int i =0; i < entries ; i++ ){
		tree->GetEntry(i);
		hist->Fill(a);
		cout<< a << " " << b << endl;
	}
	
	
	hist->Draw();
	//input->Close();
}
