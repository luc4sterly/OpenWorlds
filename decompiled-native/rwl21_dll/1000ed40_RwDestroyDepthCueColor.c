// 1000ed40 RwDestroyDepthCueColor [Global]
// program: RWL21.DLL

undefined4 RwDestroyDepthCueColor(int param_1)

{
  undefined4 uVar1;
  
                    /* 0xed40  570  RwDestroyDepthCueColor */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(code **)(PTR_DAT_1005b69c + 0x2ac) != (code *)0x0) {
    uVar1 = (**(code **)(PTR_DAT_1005b69c + 0x2ac))(param_1);
    return uVar1;
  }
  FUN_1000cba0(0x5f);
  return 0;
}


