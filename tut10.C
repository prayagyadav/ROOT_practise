void tut10 () {
	fstream file;
	file.open("data4.txt", ios :: in );
	
	double x , y, ex, ey;
	int n = 0;
	TGraphErrors *ge = new TGraphErrors();
	
	while(1){
		file >> x >> y >> ex >> ey ;
		cout<< x << y << ex << ey ;
		n = ge->GetN();
		ge->SetPoint(n, x, y);
		ge->SetPointError(n, ex,ey);
		if (file.eof()) break ;
	}
	
	file.close();
	
	TCanvas *c1 = new TCanvas();
	ge->Draw("AL*");

}
