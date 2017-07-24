Info<< "Entering createSourceTerm.H file" << endl;

Info<< "Constructing JBTable object..." << endl;
readJBData JBTable(mesh);
Info<< "Constructing UBBTable object..." << endl;
readUBBData UBBTable(mesh);

//const volVectorField& JB = JBTable.assignJBValues(mesh);
//const volVectorField& B = UBBTable.assignUBBValues(mesh);

//calculateUBBTerm UBB_Term(mesh, UBBTable);
//
volVectorField sourceTerm
(
    IOobject
    (
        "sourceTerm",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE //NO_WRITE
    ),
    mesh,
    dimensionedVector("sourceTerm", dimensionSet(1,-2,-2,0,0,0,0),Foam::vector(0,0,0))
); 

volVectorField UBB
(
    IOobject
    (
        "UBB",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE //NO_WRITE
    ),
    mesh,
    dimensionedVector("UBB", dimensionSet(1,-2,-2,0,0,0,0),Foam::vector(0,0,0))
); 
  
volVectorField JB
(
    IOobject
    (
        "JB",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE //NO_WRITE
    ),
    mesh,
    dimensionedVector("JB", dimensionSet(1,-2,-2,0,0,0,0),Foam::vector(0,0,0))
); 

volVectorField B
(
    IOobject
    (
        "B",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE //NO_WRITE
    ),
    mesh,
    dimensionedVector("B", dimensionSet(1,0,-2,0,0,-1,0),Foam::vector(0,0,0))
);

volScalarField sigmaMHD
(
    IOobject
    (
        "sigmaMHD",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
	IOobject::AUTO_WRITE
    ),
	mesh,
	dimensionedScalar("sigmaMHD", dimensionSet(-1,-3,3,0,0,2,0),0)
);

JB = JBTable.assignJBValues(mesh);
B = UBBTable.assignUBBValues(mesh);

#include "calculateSourceTerm.H"
