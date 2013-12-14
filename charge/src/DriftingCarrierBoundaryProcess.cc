#include "DriftingCarrierBoundaryProcess.hh"
#include "DriftingElectron.hh"
#include "DriftingHole.hh"

#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4VParticleChange.hh"
#include "G4TransportationManager.hh"
#include "G4Navigator.hh"
#include "G4GeometryTolerance.hh"

DriftingCarrierBoundaryProcess::DriftingCarrierBoundaryProcess(const G4String& aName):G4VDiscreteProcess(aName){
  
  kCarTolerance = G4GeometryTolerance::GetInstance()->GetSurfaceTolerance();
   
   if (verboseLevel>1) {     
     G4cout << GetProcessName() << " is created "<< G4endl;
    }
  
}

DriftingCarrierBoundaryProcess::~DriftingCarrierBoundaryProcess()
{ ; }

DriftingCarrierBoundaryProcess::DriftingCarrierBoundaryProcess(DriftingCarrierBoundaryProcess& right):G4VDiscreteProcess(right)
{ ; }

G4double DriftingCarrierBoundaryProcess::GetMeanFreePath( 
       const G4Track& aTrack, G4double /*previousStepSize*/, G4ForceCondition* condition  )
{

  *condition = Forced;
  //G4double proposedStep = aTrack.GetStep()->GetPostStepPoint()->GetSafety();
  //G4cout <<  "DriftingCarrierBoundaryProcess: " <<  proposedStep <<  G4endl;
  //if (proposedStep == 0) proposedStep = DBL_MAX;
  //return proposedStep;
  return DBL_MAX;
}

G4VParticleChange* DriftingCarrierBoundaryProcess::PostStepDoIt( const G4Track& aTrack, const G4Step& aStep )
{    

  aParticleChange.Initialize(aTrack);
  G4StepPoint* postStepPoint = aStep.GetPostStepPoint();
  //G4cout << postStepPoint->GetProcessDefinedStep()->GetProcessName() << G4endl;

// do nothing but return if the current step is not limited by a volume boundar
  if(postStepPoint->GetStepStatus()!=fGeomBoundary)
    { 
      return G4VDiscreteProcess::PostStepDoIt(aTrack,aStep);      
    }

  aParticleChange.ProposeNonIonizingEnergyDeposit(aTrack.GetKineticEnergy());
  aParticleChange.ProposeTrackStatus(fStopAndKill);  
  //G4cout <<  "Track Killed" <<  G4endl;
  //std::ofstream file;
  //file.open("epositions.txt",std::ios::app);
  //file << aTrack.GetPosition().getX()/m <<  " " <<  
//aTrack.GetPosition().getY()/m 
 // 	<< G4endl;
  //file.close();

  std::ofstream file;
  file.open("epositions.txt",std::ios::app);
  file << aTrack.GetPosition().getX()/m <<  " " <<  
    aTrack.GetPosition().getY()/m 
       << G4endl;
  file.close();
  return &aParticleChange;
}

G4bool DriftingCarrierBoundaryProcess::IsApplicable(const G4ParticleDefinition& aPD)
{

  return ((&aPD==DriftingElectron::DriftingElectronDefinition())||(&aPD==DriftingHole::Definition()));

}
