{
    Info<< "Entering calculateSourceTerm.H file" << endl;
	sigmaMHD = alpha1*sigmaMHD1 + alpha2*sigmaMHD2;
    UBB = sigmaMHD*(U ^ B) ^ B;
    sourceTerm = JB + UBB; 
	//sourceTerm = JB; 
}
