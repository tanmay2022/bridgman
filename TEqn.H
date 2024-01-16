//  fvScalarMatrix TEqn
//   (
//     Cp*dimt*fvm::ddt(T)- (dimx*dimx/(psi + 1e-6))*fvm::laplacian(psi*K, T) == dimx*(mag(fvc::grad(psi))/(psi + 1e-6))*flux*(T)
//   );
// 
//   TEqn.solve();

volScalarField height = pos(mesh.C().component(1)/dimx-(ybottom + 30*50e-6 + runTime.value()*Vpull));

// volScalarField gradpsi2 = (fvc::grad(psi))&(fvc::grad(psi));

volScalarField K = Ks*phi + Kl*(1-phi);
//volScalarField omega = epsilon*L*L*0.18/(Tm*K);


 fvScalarMatrix TEqn
  (
    Cp*dimt*fvm::ddt(T)- (dimx*dimx/(psi + 1e-6))*fvm::laplacian(psi*K, T) == dimx*(mag(fvc::grad(psi))/(psi + 1e-6))*flux*(T-Tinf)*(1-height) - dimx*dimx*((fvc::grad(psi))&(fvc::grad(psi*T) - Bd*fvc::grad(psi)))*height*(K/((psi+1e-6)*(psi+1e-6)))
  );

  TEqn.solve();
