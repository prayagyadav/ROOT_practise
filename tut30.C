void tut30(){
	TCanvas *c1 = new TCanvas();
	TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();
	TGeoManager *man = new TGeoManager();
	TGeoVolume *top = gGeoManager->MakeBox("TOP",NULL, 10, 10, 10);
	TGeoVolume *box = gGeoManager->MakeBox("BOX",NULL, 1, 1, 0.2);
	
	man->SetTopVolume(top);
	top->AddNode(box , 0);
	
	man->CloseGeometry();
	top->Draw("ogl");
	
}
