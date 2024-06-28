void tut29() {
	TCanvas *c1 = new TCanvas();
	
	TH1F *hist1 = new TH1F("hist1","Histogram 1",  100 , -5 , 5);
	TH1F *hist2 = new TH1F("hist2","Histogram 2",  100 , -5 , 5);
	TH1F *hist3 = new TH1F("hist3","Histogram 3",  100 , -5 , 5);
	hist1->SetStats(0);
	
	hist1->FillRandom("gaus",4e2);
	hist2->FillRandom("gaus",2e2);
	
	*hist3 = (*hist1)*(*hist2);
	
	hist1->SetLineColor(kRed-2);
	hist2->SetLineColor(kBlue-2);
	hist3->SetLineColor(kGreen-2);
	
	hist1->SetMaximum(hist3->GetMaximum());
	
	hist1->Draw();
	hist2->Draw("same");
	hist3->Draw("same");
}
