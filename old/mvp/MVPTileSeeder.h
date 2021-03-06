/// \file MVPTileSeeder.h
///
/// MVP Tile Seeder
///
/// TODO: Write something here
///

#include <mvp/MVPTypes.h>
#include <mvp/MVPAlgorithmOptions.pb.h>
#include <mvp/MVPUserSettings.pb.h>

#ifndef __MVP_MVPTILESEEDER_H__
#define __MVP_MVPTILESEEDER_H__

namespace mvp {

class MVPAlgorithm;

class MVPTileSeeder {
  protected:
    MVPAlgorithm *m_algorithm;
    MVPTileResult m_result;
    MVPUserSettings m_user_settings; 

  public:
    MVPTileSeeder(MVPAlgorithm *algorithm, vw::cartography::GeoReference georef, int tile_size, MVPUserSettings user_settings) :
      m_algorithm(algorithm), m_result(georef, tile_size), m_user_settings(user_settings) {}

    MVPTileResult const& result() {return m_result;}

    MVPUserSettings const& user_settings() {return m_user_settings;}

    virtual bool init() = 0; 

    virtual MVPAlgorithmVar seed(int col, int row) = 0;

    virtual MVPPixelResult update(int col, int row, MVPAlgorithmVar const& seed) = 0;

    MVPPixelResult update(int col, int row) {return update(col, row, seed(col, row));}
};

class MVPTileSeederDumb : public MVPTileSeeder {
  protected:
    MVPAlgorithmVar m_seed;

  public:
    MVPTileSeederDumb(MVPAlgorithm *algorithm, vw::cartography::GeoReference georef, int tile_size, MVPUserSettings user_settings) :
      MVPTileSeeder(algorithm, georef, tile_size, user_settings) {}

    virtual bool init();

    virtual MVPAlgorithmVar seed(int col, int row);

    virtual MVPPixelResult update(int col, int row, MVPAlgorithmVar const& seed);
};

struct MVPTileSeederSquare : public MVPTileSeederDumb {
  public:
    MVPTileSeederSquare(MVPAlgorithm *algorithm, vw::cartography::GeoReference georef, int tile_size, MVPUserSettings user_settings) :
      MVPTileSeederDumb(algorithm, georef, tile_size, user_settings) {}

    virtual MVPAlgorithmVar seed(int col, int row);
};

} // namespace mvp

#endif
