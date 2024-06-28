void plot() {
	TFile *file =new TFile("Output.root", "READ");
	TH1F *histo = (TH1F*)file->Get("Legend");
	histo->Draw();
}
