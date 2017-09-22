/***********************************************************************\
 * This software is licensed under the terms of the GNU General Public *
 * License version 3 or later. See G4CMP/LICENSE for the full license. *
\***********************************************************************/

/// \file library/include/G4CMPTrackUtils.hh
/// \brief Free standing functions that perform operations on G4Tracks
///
//
// $Id$
//
// 20161111 Initial commit - R. Agnese
// 20170621 M. Kelsey -- Add non-templated utility functions, support both
//		pointer and reference arguments

#include "globals.hh"
#include "G4ThreeVector.hh"

class G4CMPDriftTrackInfo;
class G4CMPPhononTrackInfo;
class G4CMPVTrackInfo;
class G4LatticePhysical;
class G4Track;


namespace G4CMP {
  // Create and initialize kinematics container based on track particle type
  void AttachTrackInfo(const G4Track* track);
  void AttachTrackInfo(const G4Track& track);

  // Create and initialize kinematics container with specified input
  void AttachTrackInfo(const G4Track* track, G4int valley);
  void AttachTrackInfo(const G4Track& track, G4int valley);

  void AttachTrackInfo(const G4Track* track, const G4ThreeVector& kdir);
  void AttachTrackInfo(const G4Track& track, const G4ThreeVector& kdir);

  // Attach pre-created kinematics container to track (no type matching)
  void AttachTrackInfo(const G4Track* track, G4CMPVTrackInfo* trackInfo);
  void AttachTrackInfo(const G4Track& track, G4CMPVTrackInfo* trackInfo);

  // Return template-specified container subtype attached to track
  template<class T> T* GetTrackInfo(const G4Track* track);
  template<class T> T* GetTrackInfo(const G4Track& track);

  // Test whether track has kinematics container attached
  G4bool HasTrackInfo(const G4Track* track);
  G4bool HasTrackInfo(const G4Track& track);

  // Get physical lattice associated with track
  G4LatticePhysical* GetLattice(const G4Track& track);
}

#include "G4CMPTrackUtils.icc"