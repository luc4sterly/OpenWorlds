// 1000ed80 RwSetDepthCueColor [Global]
// programa: RWL21.DLL

undefined4 RwSetDepthCueColor(undefined4 param_1)

{
  undefined4 uVar1;
  
                    /* 0xed80  402  RwSetDepthCueColor */
  if (*(code **)(PTR_DAT_1005b69c + 0x2b0) != (code *)0x0) {
    uVar1 = (**(code **)(PTR_DAT_1005b69c + 0x2b0))(param_1);
    return uVar1;
  }
  FUN_1000cba0(0x5f);
  return 0;
}


