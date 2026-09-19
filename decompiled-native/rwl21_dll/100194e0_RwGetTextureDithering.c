// 100194e0 RwGetTextureDithering [Global]
// programa: RWL21.DLL

byte RwGetTextureDithering(void)

{
                    /* 0x194e0  255  RwGetTextureDithering */
  if ((DAT_1005ac04 & 1) != 0) {
    return -((DAT_1005ac04 & 2) == 0) & 3;
  }
  return ((DAT_1005ac04 & 2) == 0) + 1;
}


