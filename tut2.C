void tut2()
{
	
	//double x[10] = {1, 2 ,3, 4, 5, 6, 7, 8, 9, 10};
	//double y[10] = {1, 2 ,3, 4, 5, 5, 5, 5, 5 , 5};
	double x[100];
	double y[100];
	
	for (int i = 0 ; i < 100 ; i++ ) {
	x[i] = -5 + (0.1*i);
	}
	
	for (int i = 0 ; i < 100 ; i++) {
	y[i] = sin(x[i]);
	//std:: cout<<y[i]<<std::endl;
	}
	
	TGraph *g = new TGraph(100, x, y);
	
	g->GetXaxis()->SetTitle("x");
	g->GetYaxis()->SetTitle("f(x)");
	g->SetTitle("Nice Plot");
	//g->SetMarkerStyle(6);
	g->SetMarkerStyle(kFullCircle);
	g->SetMarkerSize(0.5);
	
	TCanvas *c1 = new TCanvas();
	g->Draw("ACP");
}
