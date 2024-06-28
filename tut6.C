void tut6()
{
	TH1F *hist = new TH1F("hist" , "Histogram", 100, 0, 10 );
	
	TRandom2 *rand = new TRandom2(3);
	
	fstream file; //fstream class to create a file holder object
	file.open("data3.txt", ios::out);
	
	for (int i = 0 ; i < 1000 ; i++ ){
		double_t r = rand->Gaus(5, 1);
		file << r << endl ;
	
	};
	
	file.close();
	
	file.open("data3.txt", ios:: in ); //Read Permissions
	
	double_t value;
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
