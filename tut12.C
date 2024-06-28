void tut12 (){
	TCanvas *c1 = new TCanvas();
	
	TF1 *f = new TF1( "f(x)", "[0]/sqrt([1]*x)", 0 , 10  );
	f->SetParameter(0,1);
	f->SetParameter(1,TMath:: Pi());
	f->SetTitle("f(x)");
	f->SetLineColor(kBlue-5);
	c1->SetTickx();
	f->GetXaxis()->SetTitle("x");
	c1->SetTicky();
	f->GetYaxis()->SetTitle("y");
	f->SetLineWidth(3);
	f->Draw();	
	
	TLegend *l = new TLegend(0.6,0.5,0.8,0.8);
	l->AddEntry(f, "X^(-1/2)", "l");
	l->SetBorderSize(0);
	l->Draw();
	
}
