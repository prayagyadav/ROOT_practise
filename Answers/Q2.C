/*
Question 2 : Follow the exercise (https://root.cern/doc/master/graph2derrorsfit_8C.html)

Notes : The aim is to create a 2D scatter plot with "error spheres".Fit this scatter plot with a custom function and plot the fit function surface in the same plot.
 */


void Q2()
{
   TCanvas *c1 = new TCanvas("c1"); //Creating a canvas for everything
 
   Double_t rnd, x, y, z, ex, ey, ez;// x,y,z represent cordinates in 3D space; ex ,ey, ez represent the x y and z component of the error sphere
                                     // rnd is a random number variable 
   Double_t e = 0.3;                 // e sets the range of rnd
   Int_t nd = 500;                   // nd presents the number of data points
 
   TRandom r;                       // creation of a random class object r.
   TF2  *f2 = new TF2("f2","1000*(([0]*sin(x)/x)*([1]*sin(y)/y))+200",-6,6,-6,6); //The 2D function Constructor
   f2->SetParameters(1,1);                                                        //setting the parameters 0 as 1 and 1 as 1 . 
   TGraph2DErrors *dte = new TGraph2DErrors(nd);                                  // The constructor of 2D error graphs.
 
   // Fill the 2D graph ; creating the scatter plot data
   Double_t zmax = 0;                   // zmax represents the maximum value of z in our plot
   for (Int_t i=0; i<nd; i++) {         // Looping for nd number of data points
      f2->GetRandom2(x,y);              // Get random (x,y) coordinates from the -6<x<6 and y -6<y<6 square area.****
      rnd = r.Uniform(-e,e);            // Generate a random number in [-e,e] with uniform probability density
      z = f2->Eval(x,y)*(1+rnd);        // Calculate the expected value of z with the f2 function and randomize it by rnd%
      if (z>zmax) zmax = z;             // Iteratively reupdating the maximum value of z
      dte->SetPoint(i,x,y,z);           // Adding the obtained point to the 2D error graph at the ith data point entry
      ex = 0.05*r.Rndm();               // Generate random number between 0.0 to 0.05 for error in x
      ey = 0.05*r.Rndm();               // Generate random number between 0.0 to 0.05 for error in y
      ez = TMath::Abs(z*rnd);           // To produce a lose linear correlation between z and error in z ****
      dte->SetPointError(i,ex,ey,ez);   // Adding the obtained errors to the 2D error graph at the ith data point entry
   }
 
   f2->SetParameters(0.5,1.5); // Initializing the parameters of f2 to arbitrarily chosen value
   dte->Fit(f2);               // Fiting the  parameters of f2 based the initial parameters
   TF2 *fit2 = (TF2*)dte->FindObject("f2"); //Copying the the fitted f2 to a new function fit2 which is used for plotting ****
   fit2->SetTitle("2D data with errors and its Fit Surface");// Title
   fit2->SetMaximum(zmax); //zmax finally used to set the range of z axis, for better viewing
   gStyle->SetHistTopMargin(0); // Effectively sets the height of the graph to full
   fit2->SetLineColor(1); //Changing the color of lines to Blue
   fit2->SetLineWidth(1); //Decreasing the thickness of lines
   fit2->Draw("surf1");   //Plotting the fit with surf1 style
   dte->Draw("same p0");  //Plotting the 2D error graph ****
   //dte->Draw();
}
