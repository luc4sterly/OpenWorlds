// 100193d0 RwGetTextureMipmapState [Global]
// programa: RWL21.DLL

int RwGetTextureMipmapState(void)

{
                    /* 0x193d0  576  RwGetTextureMipmapState */
  return 2 - (uint)((DAT_1005ac04 & 0x40) == 0);
}


