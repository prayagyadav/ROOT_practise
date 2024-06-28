void tut5(){
	TH1F *h = new TH1F("hist","Random Numbers", 100, 0 ,100);
	h->GetYaxis()->SetRangeUser(0,100);
	TRandom2 *rand = new TRandom2(1); //seed = 1
	
	for (int i = 0 ; i < 5000 ; i++){
		double_t r = rand->Rndm()*100;
		h->Fill(r);
	};
	TCanvas *c1 = new TCanvas();
	h->Draw();

}
