void tut24(){
	TVector3 v1(1,2,3);
	v1.Print();
	TVector3 v2;
	v2.SetX(3);
	v2.SetY(2);
	v2.SetZ(1);
	v2.Print();
	double deg = 180.0 / TMath::Pi();
	double rad = TMath::Pi() / 180.0 ;
	//cout<< v1.X() <<" "<< v2[0] << endl;
	double rho1 = v1.Mag() ;
	double theta1 = v1.Theta() * deg ;
	double phi1 = v1.Phi() * deg ;
	cout << rho1 << endl << theta1 << endl << phi1 << endl;
	v1.RotateZ(90*rad); // updates the vector v1
	v1.Print();
	//to create a vector in spherical coordinates
	TVector3 v3;
	v3.SetZ(10);
	v3.SetTheta(10*rad);
	v3.SetPhi(45*rad);
	v3.Print();
	
	//Some Operations
	TVector3 v4 = v1 + v2;//Addition
	double x = v1.Dot(v2);//Dot Product
	if (v1.Dot(v2) == v1*v2 ) cout<<"Yes"<<endl;
	// cross product 
	v4 = v1.Cross(v2);
	//copying
	TVector3 v5(v1);
	//Angle between vectors
	double ang = v1.Angle(v2) * deg;
	cout << "Angle is " << ang << endl;
	//Pseudorapidy
	if (v1.Eta() == v1.PseudoRapidity() ) cout<< "Yes" <<endl;


}
