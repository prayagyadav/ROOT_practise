void tut3()
{
	TH1F *hist = new TH1F("hist" , "Histogram", 6, 1, 7 );
	fstream file; //fstream class to create a file holder object
	file.open("data.txt", ios:: in ); //Read Permissions
	
	double value;
	while (1) { //always running loop unless break
		file >> value ;
		if (file.eof()) break ;
		hist->Fill(value);
	
	}
	
	file.close();
	
	hist->GetXaxis()->SetTitle("X-Axis");
	hist->GetYaxis()->SetTitle("Y-Axis");
	TCanvas *c1 = new TCanvas();
	hist->Draw();
}
