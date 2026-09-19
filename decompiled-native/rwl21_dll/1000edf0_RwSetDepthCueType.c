// 1000edf0 RwSetDepthCueType [Global]
// programa: RWL21.DLL

undefined4 RwSetDepthCueType(int param_1)

{
  int iVar1;
  
                    /* 0xedf0  572  RwSetDepthCueType */
  if (*(code **)(PTR_DAT_1005b69c + 0x2b4) == (code *)0x0) {
    if (param_1 != 1) {
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(PTR_DAT_1005b69c + 0x2b4))(param_1);
    if (iVar1 != 0) {
      DAT_1005a0bc = param_1;
    }
  }
  return 1;
}


