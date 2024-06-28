#include"TProfile.h"
#include"TRandom2.h"
#include"TCanvas.h"
void tut19(){
	TProfile *hprof = new TProfile("hprof","Profile", 100, 0 ,10, "S");
	TRandom2 *rand = new TRandom2();
	for (int i = 0 ; i < 1e8 ; i++){
		hprof->Fill(rand->Rndm()*10, rand->Rndm());
	};
	TCanvas *c = new TCanvas();
	hprof->Draw();

}
