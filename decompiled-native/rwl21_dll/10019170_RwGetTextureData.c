// 10019170 RwGetTextureData [Global]
// programa: RWL21.DLL

undefined4 RwGetTextureData(int param_1)

{
                    /* 0x19170  253  RwGetTextureData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x20);
  }
  FUN_1000cba0(1);
  return 0;
}


