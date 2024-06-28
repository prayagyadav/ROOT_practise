/* 
Prayag Yadav
University of Hyderabad
 
 Question 1 : Write a root script to draw 3 histograms and overlap with each other, one with Gaus(-1,1.5), other with Gaus(-0.5,0.5) and then with Landau(1,0.15).Draw with 3 colors .
 
 */
 
 void Q1 () {
 	TFile *file = new TFile("Q1.root", "RECREATE");
 	
 	THStack *hstack = new THStack("hstack", "Different Histograms; x values ; y values");
 	TRandom2 *rand = new TRandom2();
 	double r ;
 	
 	
 	// Histogram 1:
 	
 	TH1F *hist1 = new TH1F("hist1", "GAUS(-1, 1.5 )", 100, -5,5);
 	for (int i =0 ; i < 10000 ; i++){
		r = rand->Gaus(-1.0 ,1.5);
		hist1->Fill(r);  	
 	}
 	hist1->SetLineColor(kRed-2);
 	hist1->SetLineWidth(3);
 	//hist1->SetFillColorAlpha(kRed-9,0.2);
 	
 	//Histogram 2:
 	
 	TH1F *hist2 = new TH1F("hist2", "GAUS(-0.5, 0.5 )", 100, -5,5);
 	for (int i =0 ; i < 10000 ; i++){
		r = rand->Gaus(-0.5 ,0.5);
		hist2->Fill(r);  	
 	}
 	hist2->SetLineColor(kGreen-2);
 	hist2->SetLineWidth(3);
 	//hist2->SetFillColorAlpha(kGreen-9, 0.2);
 	
 	//Histogram 3:
 	
 	TH1F *hist3 = new TH1F("hist3", "LANDAU(1, 0.15 )", 100, -5,5);
 	for (int i =0 ; i < 10000 ; i++){
		r = rand->Landau(1.0 ,0.15);
		hist3->Fill(r);  	
 	}
 	hist3->SetLineColor(kBlue-2);
 	hist3->SetLineWidth(3);
 	//hist3->SetFillColorAlpha(kBlue-9,0.2);
 	
 	//Legend
 	TLegend *leg = new TLegend(0.65,0.6,0.88,0.88);
 	leg->SetBorderSize(0);
 	leg->AddEntry(hist1,"Gaussian(-1,1.5)","l");
 	leg->AddEntry(hist2,"Gaussian(-0.5,0.5)","l");
 	leg->AddEntry(hist3,"Landau(1,0.15)","l");
 	
 	hstack->Add(hist1);
 	hstack->Add(hist2);
	hstack->Add(hist3); 	
	
 	TCanvas *c = new TCanvas();
 	hstack->Draw("nostack");
 	leg->Draw();
 	c->SetTickx();
 	c->SetTicky();
 	
 	c->Print("Q1.pdf");
 	file->Write();
 	//file->Close();
 }
 
 
