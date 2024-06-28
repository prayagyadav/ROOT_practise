void tut14(){
	TFile *file = new TFile("Output.root", "RECREATE");
	
	TH1F *hist = new TH1F("Legend", "Histogram", 100, 0, 100);
	hist->Fill(80);
	hist->Draw();
	
	file->Write();
	file->Close();
}
