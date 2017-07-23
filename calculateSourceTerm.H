{
    Info<< "Entering calculateSourceTerm.H file" << endl;
    UBB = sigmaMHD*(U ^ B) ^ B;
    sourceTerm = JB + UBB; 
}
