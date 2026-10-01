// 1001af20 RwAddMaterialModeToMaterial [Global]
// program: RWL21.DLL

int RwAddMaterialModeToMaterial(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
                    /* 0x1af20  7  RwAddMaterialModeToMaterial */
  if ((param_2 & 0xffffff3f) != 0) {
    FUN_1000cba0(0x48);
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x30);
  if ((param_2 & 0xffffff3f) != 0) {
    FUN_1000cba0(0x48);
    return 0;
  }
  if (param_1 != 0) {
    bVar2 = bVar1 & 0x3f;
    *(byte *)(param_1 + 0x30) = bVar2;
    *(byte *)(param_1 + 0x30) = bVar2 | bVar1 & 0xc0 | (byte)param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


