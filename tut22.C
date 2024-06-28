void tut22( TString filename){
	cout<<"Opening the file..."<<endl;
	TFile *file = new TFile(filename,"recreate");
	cout<<"File opened at "<< file << endl;
}
