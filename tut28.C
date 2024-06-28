void tut28() {
	TCanvas *c = new TCanvas();
	
	TF1 *f = new TF1("f","[0]+cos([1]+x)", -5,5);
	f->SetParameters(0,1);
	
	double solution;
	
	ROOT::Math::RootFinder fin;
	fin.Solve(*f, -5, 5);
	solution = fin.Root();
	cout<<"A root is "<<solution<<endl;
	
	TLine *l = new TLine(-5,0,5,0);
	TLine *r = new TLine(solution,-1,solution,1);
	
	f->Draw();
	l->Draw();
	r->Draw();
	
	
	
}
