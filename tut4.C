void tut4(){
	TGraph *g = new TGraph();
	g->SetMarkerStyle(kFullCircle);
	g->SetLineWidth(2);
	g->SetLineColor(kRed);
	g->SetTitle("The Graph");
	g->GetXaxis()->SetTitle("X axis");
	g->GetYaxis()->SetTitle("Y axis");
	fstream file;
	file.open("data2.txt", ios::in );
	 while(1){
	 	double_t x, y;
	 	if(file.eof()) break ;
	 	file>> x >> y ;
	 	g->SetPoint(g->GetN(),x,y);
		
			 
	 };
	TCanvas *c1 = new TCanvas();
	
	g->Draw("ACP");
}
