void tut25(){
	THStack *hstack = new THStack("hstack","Histogram Stack; x axis; frequency");
	
	TH1F *h1 = new TH1F("h1", "Gaussian PDF", 100, -10, 10);
	h1->FillRandom("gaus",1e4 );
	
	TH1F *h2 = new TH1F("h2", "Landau PDF", 100, -10, 10);
	h2->FillRandom("landau",4e4 );
	
	TCanvas *c = new TCanvas();
	
	hstack->Add(h1);
	hstack->Add(h2);
		
	hstack->Draw("nostack");


}
