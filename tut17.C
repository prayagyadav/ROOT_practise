void tut17() {
	TCanvas *c1 = new TCanvas("histogram","2D Histogram",5);
	gStyle->SetPalette(kRainBow);
	TPad *p = new TPad("pad","",0,0,0.9,1 );
	p->Draw();
	p->cd();
	//gPad->Range(-10,-10,10,10);
	TRandom2 *rand =new TRandom2(10);
	TH2F *hist = new TH2F("hist","Histogram",100, -5 , 5 , 100 , -5 , 5);
	hist->SetStats(0);
	for (int i = 0 ; i < 1e7 ; i++ ){
		hist->Fill(rand->Gaus(), rand->Gaus());
	}
	hist->SetContour(1000);
	hist->GetXaxis()->SetTitle("X axis");
	hist->GetYaxis()->SetTitle("Y axis");
	hist->GetZaxis()->SetTitle("Z axis");
	hist->Draw("colz");
	
}


