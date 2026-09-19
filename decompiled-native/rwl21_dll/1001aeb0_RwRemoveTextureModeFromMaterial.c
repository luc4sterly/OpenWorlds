// 1001aeb0 RwRemoveTextureModeFromMaterial [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1001aee3) */

int RwRemoveTextureModeFromMaterial(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
                    /* 0x1aeb0  341  RwRemoveTextureModeFromMaterial */
  if ((param_2 & 0xffffffe8) != 0) {
    FUN_1000cba0(0x39);
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x30);
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  bVar2 = bVar1 & 0xe8;
  *(byte *)(param_1 + 0x30) = bVar2;
  *(byte *)(param_1 + 0x30) = bVar1 & ~(byte)param_2 & 0x17 | bVar2;
  return param_1;
}


