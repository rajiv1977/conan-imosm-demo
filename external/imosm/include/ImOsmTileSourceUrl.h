#pragma once
#include "ImOsmTileSourceAsync.h"

static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);

namespace ImOsm {
class TileSourceUrl : public TileSourceAsync {
public:
  TileSourceUrl(int requestLimit, bool preload,
                const std::string &userAgent = "curl");
  virtual ~TileSourceUrl();

protected:
  virtual bool receiveTile(int z, int x, int y, TileData &tileData) override;
  virtual std::string makeUrl(int z, int x, int y) = 0;

private:
  std::string _userAgent{"curl"};
};
} // namespace ImOsm


static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
    std::string& text = *static_cast<std::string*>(param);
    size_t totalsize = size * nmemb;
    auto buff = static_cast<char*>(buffer);
    std::string str(buff);
    return totalsize;
}
