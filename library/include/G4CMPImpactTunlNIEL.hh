/***********************************************************************\
 * This software is licensed under the terms of the GNU General Public *
 * License version 3 or later. See G4CMP/LICENSE for the full license. *
\***********************************************************************/

/// \file library/include/G4CMPImpactTUNLNIEL.hh
/// \brief Non-ionizing energy loss calculation from IMPACT@TUNL 2023.
///
/// Computation of NIEL using the empirical model extracted from the ionization yield measurements according to IMPACT@TUNL 2023.  Link to the paper:https://arxiv.org/abs/2303.02196.
//
// $Id$
//
// 20190711  Michael Kelsey

// potential problem1. This ionization model was obtained from the ionization yield measurements in Silicon ONLY.

// potential problem2. The model is obtained in the range of 100 eV to 10 keV. What about energies>10 keV? My first choice would be Lindhard since it works very well above 10 keV but we could give the option to the user to decide which model to use above 10 keV

#ifndef G4CMPImpactTunlNIEL_hh
#define G4CMPImpactTunlNIEL_hh 1

#include "G4VNIELPartition.hh"
#include "G4LewinSmithNIEL.hh"


class G4CMPImpactTunlNIEL : public G4VNIELPartition {
public:
  G4CMPImpactTunlNIEL() {;}
  virtual ~G4CMPImpactTunlNIEL() {;}
  
  // return the fraction of the specified energy which will be deposited as NIEL
  // if an incoming particle with z1, a1 is stopped in the specified material
  // a1 is in atomic mass units, energy in native G4 energy units.
  //
  virtual G4double 
  PartitionNIEL(G4double energy, const G4Material *material, G4double Zin=0.,
		G4double Ain=0.) const;
};

#endif	/* G4CMPImpactTunlNIEL_hh */
