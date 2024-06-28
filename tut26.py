from ROOT import *
#c1 = TCanvas("c1","canvas",0,0,800,800)
c1  =  TCanvas()
hist = TH1F("hist","Histogram",100,-5,5)
hist.FillRandom("gaus")

hist.Draw()

c1.Update()

input()
