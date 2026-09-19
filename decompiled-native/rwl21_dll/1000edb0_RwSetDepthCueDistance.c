// 1000edb0 RwSetDepthCueDistance [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 RwSetDepthCueDistance(undefined4 param_1)

{
  undefined4 uVar1;
  
                    /* 0xedb0  568  RwSetDepthCueDistance */
  _DAT_1005a0b8 = param_1;
  if (*(code **)(PTR_DAT_1005b69c + 0x2b8) != (code *)0x0) {
    uVar1 = (**(code **)(PTR_DAT_1005b69c + 0x2b8))(param_1);
    return uVar1;
  }
  return 1;
}


