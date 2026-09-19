// 1001af90 RwRemoveMaterialModeFromMaterial [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1001afc6) */

int RwRemoveMaterialModeFromMaterial(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
                    /* 0x1af90  338  RwRemoveMaterialModeFromMaterial */
  if ((param_2 & 0xffffff3f) != 0) {
    FUN_1000cba0(0x48);
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x30);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  bVar2 = bVar1 & 0x3f;
  *(byte *)(param_1 + 0x30) = bVar2;
  *(byte *)(param_1 + 0x30) = bVar1 & ~(byte)param_2 & 0xc0 | bVar2;
  return param_1;
}


