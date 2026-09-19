// 1001ae40 RwAddTextureModeToMaterial [Global]
// programa: RWL21.DLL

int RwAddTextureModeToMaterial(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
                    /* 0x1ae40  12  RwAddTextureModeToMaterial */
  if ((param_2 & 0xffffffe8) != 0) {
    FUN_1000cba0(0x39);
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 0x30);
  if ((param_2 & 0xffffffe8) != 0) {
    FUN_1000cba0(0x39);
    return 0;
  }
  if (param_1 != 0) {
    bVar2 = bVar1 & 0xe8;
    *(byte *)(param_1 + 0x30) = bVar2;
    *(byte *)(param_1 + 0x30) = bVar1 & 0x17 | (byte)param_2 | bVar2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


