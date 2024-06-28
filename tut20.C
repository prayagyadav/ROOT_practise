void write(){
	TFile *Output = new TFile ("Output.root","recreate");
	double x , y ;
	TRandom2 *rand = new TRandom2(2);
	TTree *tree = new TTree("tree","Tree");
	tree->Branch("Energy", &x , "x/D" );
	tree->Branch("Momentum", &y , "y/D" );
	for (int i = 0 ; i < 1e6 ; i++ ) {
		x =  1 + rand->Rndm()*9 ; //creates random numbers between 1 and 9 
		y = x*x ;
		tree->Fill();
	};
	Output->Write();	
	Output->Close();
}

void cuts(){
	TCut cut1 = "x > 5";
	TCut cut2 = "x < 6";
	TFile *Input = new TFile("Output.root", "read");
	TTree *tree = (TTree*)Input->Get("tree");
	TCanvas *c = new TCanvas();
	tree->Draw("x", cut1&&cut2);
	//Input->Close();

}

void tut20 (){
	write();
	cuts();

}
