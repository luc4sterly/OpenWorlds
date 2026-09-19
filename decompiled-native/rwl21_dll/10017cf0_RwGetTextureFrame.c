// 10017cf0 RwGetTextureFrame [Global]
// programa: RWL21.DLL

undefined4 RwGetTextureFrame(int param_1)

{
                    /* 0x17cf0  256  RwGetTextureFrame */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  FUN_1000cba0(1);
  return 0xffffffff;
}


