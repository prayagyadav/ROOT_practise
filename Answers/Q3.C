/* 
 Create a histogram with 60 bins and set the values with the following values

  Double_t data[nBins] = { 6, 1,10,12, 6,13,23,22,15,21,
                           23,26,36,25,27,35,40,44,66,81,
                           75,57,48,45,46,41,35,36,53,32,
                           40,37,38,31,36,44,42,37,32,32,
                           43,44,35,33,33,39,29,41,32,44,
                           26,39,29,35,32,21,21,15,25,15};
and then fit this histogram with signal and background PDF, where signal model is lorenztian peak and bkg model is quadratic fit.
Follow his exercise for this particular case and thats what u would be using for lee fake rate fit 
https://root.cern.ch/root/html/tutorials/fit/FittingDemo.C.html

*/
// Quadratic background function
	double background(double *x, double *par) {
   		return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
   		};
 
 
	// Lorenzian Peak function
	double lorentzianPeak(double *x, double *par) {
  		return (0.5*par[0]*par[1]/TMath::Pi()) / TMath::Max( 1.e-10,(x[0]-par[2])*(x[0]-par[2]) + 0.25*par[1]*par[1]);
  		};

	// Sum of background and peak function
	double sumsigbag(double *x, double *par) {
  		return background(x,par) + lorentzianPeak(x,&par[3]);
  		};
void Q3(){
	TCanvas *c1 = new TCanvas();
	const Int_t nBins = 60 ;
	Double_t data[nBins] = { 6, 1,10,12, 6,13,23,22,15,21,
                           23,26,36,25,27,35,40,44,66,81,
                           75,57,48,45,46,41,35,36,53,32,
                           40,37,38,31,36,44,42,37,32,32,
                           43,44,35,33,33,39,29,41,32,44,
                           26,39,29,35,32,21,21,15,25,15};
                           
	TH1F *hist = new TH1F("hist","Signal and Background;x axis;No. of Events", nBins , 0 ,3 );
	for (int i = 0 ; i < nBins ; i++ ){
		hist->SetBinContent(i+1, data[i]);
	};
	
	
	
	hist->SetStats(0);
	hist->SetLineColor(kBlack);
	
	
	TF1 *added = new TF1("added", sumsigbag, 0,3, 6 ); //six parameters
	added->SetParameters(1,1,1,0.2,5.0,1);
	added->SetLineColor(kBlue-2);
	
	hist->Fit(added);
	
	TF1 *sgn = new TF1("Signal", lorentzianPeak, 0, 3, 3);
	TF1 *bkg = new TF1("Background",background, 0 ,3 , 3 );
	sgn->SetLineColor(kGreen-2);
	bkg->SetLineColor(kRed-2);
	
	
	TLegend *leg = new TLegend(0.7, 0.7, 0.88, 0.88 );
	leg->SetBorderSize(0);
	leg->AddEntry(hist,"Raw Data", "l");
	leg->AddEntry(sgn,"Signal Fit","l");
	leg->AddEntry(bkg,"Background Fit", "l");
	leg->AddEntry(added,"Signal + Background", "l");
	
	double par[6];
	added->GetParameters(par);
	sgn->SetParameters(par[3],par[4], par[5]);
	bkg->SetParameters(par[0],par[1],par[2]);
	
	
	hist->Draw();
	added->Draw("same");
	sgn->Draw("same");
	bkg->Draw("same");
	leg->Draw("same");
}
