// 10017d10 RwGetTextureNumFrames [Global]
// program: RWL21.DLL

undefined4 RwGetTextureNumFrames(int param_1)

{
                    /* 0x17d10  260  RwGetTextureNumFrames */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xc);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


