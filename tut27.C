void tut27(){
	TCanvas *c = new TCanvas("c","Animation",800,800);

	TEllipse *el =new TEllipse(0.2,0.5, 0.1,0.1);
	el->SetFillColor(kBlue-5);
	double frame_rate = 60;
	double time = 1000000/frame_rate; //time in microseconds
	
	gSystem->Unlink("tut27.gif");
	for (int i  = 0 ; i < 600 ; i++ ) {
		el->SetX1(0.5 + i * 0.001 );
		el->Draw();
		c->Update();
		c->Print("tut27.gif+");
		//usleep(time); //takes input in int microseconds

	}

}
