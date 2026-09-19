// 1000c900 RwGetPaletteEntries [Global]
// programa: RWL21.DLL

int RwGetPaletteEntries(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
                    /* 0xc900  212  RwGetPaletteEntries */
  if (param_3 == 0) {
    FUN_1000cba0(1);
  }
  else {
    iVar1 = (**(code **)(PTR_DAT_1005b69c + 0x27c))(param_1,param_2,param_3);
    if (iVar1 != 0) {
      return param_3;
    }
  }
  return 0;
}


