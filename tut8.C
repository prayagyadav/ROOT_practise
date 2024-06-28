void tut8()
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
	
	TF1 *MyFunction = new TF1("FunctionName", "gaus", 1, 9 );
	MyFunction->SetParameter(0,40); //The Constant Value
	MyFunction->SetParameter(1,5); //The Mean Value
	MyFunction->SetParameter(2,1); //The Sigma or Standard Deviation	
	
	
	hist->GetXaxis()->SetTitle("X-Axis");
	hist->GetYaxis()->SetTitle("Y-Axis");
	TCanvas *c1 = new TCanvas();
	hist->Fit("FunctionName","RQ");
	
	double mean = MyFunction->GetParameter(1);
	double sigma = MyFunction->GetParameter(2);
	cout << "Mean/Sigma = "<<mean/sigma<<endl;
	
	hist->SetStats(0); // to remove the statistics box
	hist->Draw();
	
	TLegend *leg = new TLegend(0.6,0.7, 0.85, 0.85);
	leg->AddEntry(hist,"The Random Histogram", "l");
	leg->AddEntry(MyFunction,"Gaussian Fit", "l");
	leg->Draw();
	
	
	
}
