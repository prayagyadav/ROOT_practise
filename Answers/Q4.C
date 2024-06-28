double fitf(double *x, double *par)
{
   double arg = 0;
   if (par[2] != 0) arg = (x[0] - par[1])/par[2];
 
   double fitval = par[0]*std::exp(-0.5*arg*arg);
   return fitval;
};
void Q4(){
	TCanvas *c1 = new TCanvas();
	
	TH1F *hist = new TH1F("hist", "This is a user defined fitting;x axis ;y axis", 100 ,-4, 4);
	
	//Filling with a gaussian
	hist->FillRandom("gaus",0.25e5); 
	hist->SetFillColor(kGreen-9);
	hist->SetStats(0);	
	
	hist->Draw();

	//Creating the function object
	TF1 *func = new TF1("MyFunction", fitf, -4, 4, 3 );
	func->SetParameters(100,0,1);
	func->SetLineWidth(2);
	
	//fitting
	hist->Fit(func,"R");
	
	func->Draw("same");
	
	TLegend *leg = new TLegend(0.6,0.6,0.88,0.88);
	leg->SetBorderSize(0);
	leg->AddEntry(hist, "The data", "f");
	leg->AddEntry(func,"The fitted user defined function", "l");
	leg->Draw();
}

